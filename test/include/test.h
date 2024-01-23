#pragma once

struct	args;

typedef int (*test_function)(const struct args *args);

typedef struct	test
{
	const char			*name;
	test_function		test;
	const struct args	*args;
}				test;
