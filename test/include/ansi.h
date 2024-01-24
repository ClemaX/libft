#pragma once

#define S_NORMAL		"0"
#define S_BOLD			"1"
#define S_UNDERLINE		"4"
#define S_BLINKING		"5"
#define S_REVERSED		"7"
#define S_CONCEALED		"8"

#define FG_BLACK		"30"
#define FG_RED			"31"
#define FG_GREEN		"32"
#define FG_ORANGE		"33"
#define FG_BLUE			"34"
#define FG_PURPLE		"35"
#define FG_CYAN			"36"
#define FG_GREY			"37"
#define FG_GRAY			"37"
#define FG_DARKGREY		"90"
#define FG_DARKGRAY		"90"
#define FG_LIGHTRED		"91"
#define FG_LIGHTGREEN	"92"
#define FG_YELLOW		"93"
#define FG_LIGHTBLUE	"94"
#define FG_LIGHTPURPLE	"95"
#define FG_TURQUOISE	"96"

#define BG_BLACK		"40"
#define BG_RED			"41"
#define BG_GREEN		"42"
#define BG_ORANGE		"43"
#define BG_BLUE			"44"
#define BG_PURPLE		"45"
#define BG_CYAN			"46"
#define BG_GREY			"47"
#define BG_GRAY			"47"
#define BG_DARKGREY		"100"
#define BG_DARKGRAY		"100"
#define BG_LIGHTRED		"101"
#define BG_LIGHTGREEN	"102"
#define BG_YELLOW		"103"
#define BG_LIGHTBLUE	"104"
#define BG_LIGHTPURPLE	"105"
#define BG_TURQUOISE	"106"

#ifndef UNCOLORED
# define ANSI_SFGBG(style, fg, bg) \
	"\033[" style ";" fg ";" bg "m"

# define ANSI_SFG(style, fg) \
	"\033[" style ";" fg "m"

# define ANSI_FG(fg) \
	ANSI_SFG(S_NORMAL, fg)

# define ANSI_RESET	"\033[0m"


# define COLOR_SFG(s, fg, text) \
	ANSI_SFG(s, fg) text ANSI_RESET

# define COLOR_FG(fg, text) \
	COLOR_SFG(S_NORMAL, fg, text)
#else
# define ANSI_SFGBG(style, fg, bg) ""
# define ANSI_SFG(style, fg) ""
# define ANSI_FG(fg) ""
# define ANSI_RESET	""
#endif

#define MARKER_PASS	COLOR_FG(FG_GREEN, "✔")
#define MARKER_FAIL	COLOR_FG(FG_RED, "✗")
#define BULLET		COLOR_FG(FG_CYAN,	"▶")
