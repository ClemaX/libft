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
HEADER	=		libft.h
SRCS	=		$(addprefix $(SRCDIR)/,											\
				$(addprefix	io/ft_,												\
				putchar_fd.c putendl_fd.c putnbr_fd.c putstr_fd.c)				\
				$(addprefix lists/ft_,											\
				lstadd_back.c lstadd_front.c lstclear.c lstdelone.c lstiter.c	\
				lstlast.c lstmap.c lstnew.c lstsize.c)							\
				$(addprefix memory/ft_,											\
				bzero.c calloc.c memccpy.c memchr.c memcmp.c memcpy.c			\
				memmove.c memset.c)												\
				$(addprefix numbers/ft_,										\
				atoi.c itoa.c numlen.c pow.c)									\
				$(addprefix strings/ft_,										\
				split.c strchr.c strdup.c strjoin.c strlcat.c strlcpy.c			\
				strlen.c strmapi.c strncmp.c strnstr.c strpos.c strrchr.c		\
				strrem.c strtrim.c substr.c)									\
				$(addprefix types/ft_,											\
				isalnum.c isalpha.c isascii.c isdigit.c							\
				islower.c isprint.c issign.c isspace.c isupper.c tolower.c		\
				toupper.c)														\
				$(addprefix gnl/,												\
				get_next_line.c get_next_line_utils.c)							\
				$(addprefix printf/, ft_printf.c pf_convert.c pf_format.c		\
				pf_line.c pf_numbers.c pf_specs.c)								\
				$(addprefix scanf/,												\
				ft_sscanf.c sf_convert.c sf_specs.c))
OBJDS	=		$(addprefix $(OBJDIR)/,											\
				io lists memory numbers strings types gnl printf scanf)
OBJS	=		$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

all:			$(NAME)

$(NAME):		$(OBJDS) $(OBJS)
	$(AR) $(AFLAGS) $@ $(OBJS)

$(OBJDS):
		mkdir -p $@

$(OBJDIR)/%.o:	$(SRCDIR)/%.c $(INCDIR)/$(HEADER) Makefile
	$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

clean:
	$(RM) -rf $(OBJDIR)

fclean:			clean
	$(RM) -f $(NAME)

re:				fclean all

.PHONY	=		all clean fclean re bonus
