NAME	=	libft.a
CC		=	/usr/bin/clang
AR		=	/usr/bin/ar
RM		=	/bin/rm
AFLAGS	=	rcus
CFLAGS	=	-Wall -Wextra -Werror
HEADER	=	libft.h
SRCS	=	ft_memset.c ft_bzero.c ft_calloc.c \
			ft_memcpy.c ft_memmove.c ft_memccpy.c \
			ft_memchr.c ft_memcmp.c \
			ft_strlen.c ft_strmapi.c \
			ft_strdup.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c \
			ft_strncmp.c ft_strnstr.c ft_substr.c \
			ft_strrem.c ft_strtrim.c \
			ft_isascii.c ft_isprint.c ft_isspace.c ft_issign.c \
			ft_islower.c ft_isupper.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			ft_tolower.c ft_toupper.c\
			ft_atoi.c ft_itoa.c \
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
			ft_split.c ft_strjoin.c
BNSS	=	ft_lstnew_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
			ft_lstclear_bonus.c ft_lstdelone_bonus.c \
			ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJS	=	$(patsubst %.c,%.o,$(SRCS))
BNSO	=	$(patsubst %.c,%.o,$(BNSS))

all:		$(NAME)

$(NAME):	$(OBJS)
	$(AR) $(AFLAGS) $(NAME) $(OBJS)

%.o:		%.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) -f $(OBJS) $(BNSO)

fclean:		clean
	$(RM) -f $(NAME)

re:			fclean all

bonus: 		$(OBJS) $(BNSO)
	$(AR) $(AFLAGS) $(NAME) $(OBJS) $(BNSO)

.PHONY	=	all clean fclean re bonus
