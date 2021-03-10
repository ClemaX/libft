NAME	=		libft.a
SRCDIR	=		src
INCDIR	=		include
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
				$(addprefix lists/ft_lst,										\
					add_back.c add_front.c clear.c delone.c						\
					iter.c last.c map.c new.c size.c sort.c insert.c)			\
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
					strlen.c strmapi.c strcmp.c strnstr.c strpos.c strrchr.c	\
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
				)

OBJDS	=		$(addprefix $(OBJDIR)/,											\
					io lists map images memory numbers strings types gnl printf	\
					scanf)

OBJS	=		$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

HDRS	=		$(addprefix $(INCDIR)/, gnl/get_next_line.h						\
				$(addprefix printf/, format.h line.h numbers.h parse.h specs.h)	\
				$(addprefix scanf/, convert.h specs.h)							\
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
