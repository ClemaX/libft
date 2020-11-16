NAME	=		libft.a
SRCDIR	=		srcs
INCDIR	=		includes
OBJDIR	=		objs
CC		=		/usr/bin/clang
AR		=		/usr/bin/ar
RM		=		/bin/rm
AFLAGS	=		rcus
CFLAGS	=		-Wall -Wextra -Werror
IFLAGS	=		-I$(INCDIR)

SRCS	=		$(addprefix $(SRCDIR)/,											\
				$(addprefix	io/ft_,												\
					putchar_fd.c putendl_fd.c putnbr_fd.c putstr_fd.c)			\
				$(addprefix lists/ft_,											\
					lstadd_back.c lstadd_front.c lstclear.c lstdelone.c			\
					lstiter.c lstlast.c lstmap.c lstnew.c lstsize.c lstsort.c)	\
				$(addprefix map/,												\
					map.c map_utils.c map_sort.c)								\
				$(addprefix images/,											\
					write_bmp.c)												\
				$(addprefix memory/ft_,											\
					bzero.c calloc.c memccpy.c memchr.c memcmp.c memcpy.c		\
					memmove.c memset.c)											\
				$(addprefix numbers/ft_,										\
					atoi.c itoa.c numlen.c pow.c)								\
				$(addprefix strings/ft_,										\
					split.c strchr.c strdup.c strjoin.c strlcat.c strlcpy.c		\
					strlen.c strmapi.c strncmp.c strnstr.c strpos.c strrchr.c	\
					strrem.c strtrim.c substr.c striter.c basename.c strings.c)	\
				$(addprefix types/ft_,											\
					isalnum.c isalpha.c isascii.c isdigit.c						\
					islower.c isprint.c issign.c isspace.c isupper.c iscntrl.c	\
					tolower.c toupper.c)										\
				$(addprefix gnl/,												\
					get_next_line.c get_next_line_utils.c)						\
				$(addprefix printf/, ft_printf.c pf_parse.c pf_convert.c		\
					pf_format.c pf_line.c pf_numbers.c pf_specs.c)				\
				$(addprefix scanf/,												\
					ft_sscanf.c sf_convert.c sf_specs.c)						\
				$(addprefix term/,												\
					$(addprefix env/env,										\
						_get.c _set.c .c)										\
					$(addprefix lexer/,											\
						$(addprefix lexers/lex_,								\
							cmd.c ifs.c inline.c param_quoted.c param.c			\
							subshell.c tokens.c)								\
							lexer.c token_utils.c token.c)						\
					clip.c controls.c hist_cursor.c hist.c init.c				\
					cursor.c line_edit.c line.c read_special.c read.c select.c	\
					term.c write.c))

OBJDS	=		$(addprefix $(OBJDIR)/,											\
					io lists map images memory numbers strings types gnl printf	\
					scanf term term/env term/lexer term/lexer/lexers)

OBJS	=		$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

HDRS	=		$(addprefix $(INCDIR)/, gnl/get_next_line.h						\
				$(addprefix printf/, format.h line.h numbers.h parse.h specs.h)	\
				$(addprefix scanf/, convert.h specs.h)							\
				$(addprefix term/, caps.h cursor.h env.h hist.h lexer.h			\
					line.h term.h token.h)										\
				libft.h)

all:			$(NAME)

$(NAME):		$(OBJDS) $(OBJS)
	@echo AR $(NAME)
	@$(AR) $(AFLAGS) $@ $(OBJS)

$(OBJDS):
	mkdir -p $@

$(OBJDIR)/%.o:	$(SRCDIR)/%.c $(HDRS) Makefile
	@echo CC $<
	@$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

clean:
	@echo RM $(OBJDIR)
	@$(RM) -rf $(OBJDIR)

fclean:			clean
	@echo RM $(NAME)
	@$(RM) -f $(NAME)

re:				fclean all

.PHONY	=		all clean fclean re
