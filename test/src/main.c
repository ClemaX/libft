#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include <unit.h>
#include <ansi.h>

#define UNIT(symbol) \
extern const unit symbol;
#include <units.h>
#undef UNIT

int	unit_tests_run(const unit *unit)
{
	int	fw = 0;
	int err = 0;
	int	total_err = 0;

	fprintf(stdout,  COLOR_BLUE_BOLD "%s" COLOR_RESET ":\n", unit->name);

	for (size_t test_i = 0; unit->tests[test_i].test != NULL; ++test_i)
	{
		const int name_len = (int)strlen(unit->tests[test_i].name);

		if (name_len > fw)
			fw = name_len;
	}

	for (size_t test_i = 0; unit->tests[test_i].test != NULL; ++test_i)
	{
		fprintf(stdout,  BULLET " %*s ", -fw, unit->tests[test_i].name);

		err = unit->tests[test_i].test(unit->tests[test_i].args);

		if (!err)
			fprintf(stdout, MARKER_PASS "\n");
		else
			++total_err;
	}

	return total_err;
}

int	main(void)
{
	int err = 0;

	const unit units[] = {
		#define UNIT(symbol) \
		symbol,
		#include <units.h>
		#undef UNIT
	};

	for (size_t unit_i = 0; unit_i < sizeof(units) / sizeof(*units); ++unit_i)
	{
		if (unit_i != 0) {
			fprintf(stdout, "\n");
		}

		err |= unit_tests_run(&units[unit_i]);
	}

	return err;
}
