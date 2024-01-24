#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include <unit.h>
#include <ansi.h>

#define UNIT(symbol) \
extern const unit symbol;
#include <units.h>
#undef UNIT

static inline int	test_run(const test *test, const int name_fw)
{
	int	err;

	fprintf(stdout,  BULLET " %*s ", -name_fw, test->name);

	err = test->test(test->args);

	if (!err)
		fprintf(stdout, MARKER_PASS "\n");

	return err;
}

static inline int	unit_tests_name_fw(const test *tests)
{
	int	name_fw = 0;

	for (size_t test_i = 0; tests[test_i].test != NULL; ++test_i)
	{
		const int name_len = (int)strlen(tests[test_i].name);

		if (name_len > name_fw)
			name_fw = name_len;
	}

	return name_fw;
}

static inline int	unit_tests_run(const unit *unit)
{
	const int	name_fw = unit_tests_name_fw(unit->tests);
	int			err_count = 0;

	fprintf(stdout, COLOR_SFG(S_BOLD, FG_BLUE, "%s") ":\n", unit->name);

	for (size_t test_i = 0; unit->tests[test_i].test != NULL; ++test_i)
		err_count += test_run(&unit->tests[test_i], name_fw) != 0;

	return err_count;
}

int					main(void)
{
	int			err_count = 0;

	const unit	units[] = {
		#define UNIT(symbol) \
		symbol,
		#include <units.h>
		#undef UNIT
	};

	for (size_t unit_i = 0; unit_i < sizeof(units) / sizeof(*units); ++unit_i)
	{
		if (unit_i != 0)
			fprintf(stdout, "\n");

		err_count += unit_tests_run(&units[unit_i]);
	}

	return err_count != 0;
}
