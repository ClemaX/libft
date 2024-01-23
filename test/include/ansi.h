#pragma once

#ifndef UNCOLORED
# define COLOR_RESET		"\033[0m"
# define COLOR_RED			"\033[0;31m"
# define COLOR_GREEN		"\033[0;32m"
# define COLOR_CYAN			"\033[0;36m"
# define COLOR_BLUE_BOLD	"\033[1;34m"
#else
# define COLOR_RESET		""
# define COLOR_RED			""
# define COLOR_GREEN		""
# define COLOR_CYAN			""
# define COLOR_BLUE_BOLD	""
#endif

#define MARKER_PASS	COLOR_GREEN	"✔"	COLOR_RESET
#define MARKER_FAIL	COLOR_RED	"✗"	COLOR_RESET
#define BULLET		COLOR_CYAN	"▶"	COLOR_RESET
