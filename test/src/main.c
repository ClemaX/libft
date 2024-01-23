#include <stddef.h>
#include <stdio.h>

#include <unit.h>

#define UNIT(symbol) \
extern const unit symbol;
#include <units.h>
#undef UNIT

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
			fprintf(stderr, "\n");
		}
		fprintf(stderr, "%s:\n", units[unit_i].name);

		for (size_t test_i = 0; units[unit_i].tests[test_i].test != NULL; ++test_i)
		{
			fprintf(stderr, "- %s\n", units[unit_i].tests[test_i].name);
			err |= units[unit_i].tests[test_i].test();
		}
	}

	return err;
}
