# Sources
SRCDIR = src

SRCS = $(addprefix $(SRCDIR)/,\
	$(addprefix gnl/,\
		get_next_line.c\
		get_next_line_utils.c\
	)\
	$(addprefix hashmap/,\
		hmap_i.c\
		hmap_i_pair.c\
		hmap_s.c\
		hmap_s_pair.c\
	)\
	$(addprefix images/,\
		write_bmp.c\
	)\
	$(addprefix io/,\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
	)\
	$(addprefix lists/,\
		ft_lstadd_back.c\
		ft_lstadd_front.c\
		ft_lstclear.c\
		ft_lstdelone.c\
		ft_lstinsert.c\
		ft_lstiter.c\
		ft_lstlast.c\
		ft_lstmap.c\
		ft_lstnew.c\
		ft_lstsize.c\
		ft_lstsort.c\
	)\
	$(addprefix map/,\
		map.c\
		map_sort.c\
		map_utils.c\
	)\
	$(addprefix memory/,\
		ft_bzero.c\
		ft_calloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
	)\
	$(addprefix numbers/,\
		ft_atoi.c\
		ft_itoa.c\
		ft_numlen.c\
		ft_pow.c\
	)\
	$(addprefix paths/,\
		ft_basename.c\
		path_cat.c\
	)\
	$(addprefix printf/,\
		ft_printf.c\
		pf_convert.c\
		pf_format.c\
		pf_line.c\
		pf_numbers.c\
		pf_parse.c\
		pf_specs.c\
	)\
	$(addprefix scanf/,\
		ft_sscanf.c\
		sf_convert.c\
		sf_specs.c\
	)\
	$(addprefix strings/,\
		ft_split.c\
		ft_strchr.c\
		ft_strcmp.c\
		ft_strdup.c\
		ft_strings.c\
		ft_striter.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strnstr.c\
		ft_strpos.c\
		ft_strrchr.c\
		ft_strrem.c\
		ft_strtrim.c\
		ft_substr.c\
	)\
	$(addprefix types/,\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_iscntrl.c\
		ft_isdigit.c\
		ft_islower.c\
		ft_isprint.c\
		ft_issign.c\
		ft_isspace.c\
		ft_isupper.c\
		ft_tolower.c\
		ft_toupper.c\
	)\
)
