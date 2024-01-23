#pragma once

typedef int (*test_function)(void);

typedef struct	test
{
	const char		*name;
	test_function	test;
}				test;
