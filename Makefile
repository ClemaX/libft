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
SRCS	=		$(addprefix $(SRCDIR)/,					\
				ft_memset.c ft_bzero.c ft_calloc.c		\
				ft_memcpy.c ft_memmove.c ft_memccpy.c	\
				ft_memchr.c ft_memcmp.c					\
				ft_strlen.c ft_strmapi.c				\
				ft_strdup.c ft_strlcpy.c ft_strlcat.c	\
				ft_strchr.c ft_strrchr.c ft_strpos.c	\
				ft_strncmp.c ft_strnstr.c ft_substr.c	\
				ft_strrem.c ft_strtrim.c				\
				ft_isascii.c ft_isprint.c ft_isspace.c	\
				ft_islower.c ft_isupper.c ft_isalpha.c	\
				ft_isdigit.c ft_isalnum.c ft_issign.c	\
				ft_tolower.c ft_toupper.c				\
				ft_atoi.c ft_itoa.c						\
				ft_pow.c ft_numlen.c					\
				ft_putchar_fd.c ft_putendl_fd.c			\
				ft_putnbr_fd.c ft_putstr_fd.c			\
				ft_split.c ft_strjoin.c					\
				ft_lstnew.c								\
				ft_lstsize.c							\
				ft_lstlast.c							\
				ft_lstadd_back.c ft_lstadd_front.c		\
				ft_lstclear.c ft_lstdelone.c			\
				ft_lstiter.c ft_lstmap.c				)
OBJS	=		$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o, $(SRCS))

all:			$(NAME)

$(NAME):		$(OBJDIR) $(OBJS)
	$(AR) $(AFLAGS) $@ $(OBJS)

$(OBJDIR):
		mkdir -p $@

$(OBJDIR)/%.o:	$(SRCDIR)/%.c $(INCDIR)/$(HEADER) Makefile
	$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

clean:
	$(RM) -rf $(OBJDIR)

fclean:			clean
	$(RM) -f $(NAME)

re:				fclean all

.PHONY	=		all clean fclean re bonus
