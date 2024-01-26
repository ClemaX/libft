NAME:=test

SRC_DIR:=src
INC_DIR:=include

LIB_DIR:=..

OBJ_DIR:=obj
GEN_DIR:=gen

UNIT_DIR:=units
UNIT_SUFFIX:=.unit.c

OBJS:=$(addprefix $(OBJ_DIR)/, main.o expect/expect_fds.o)

UNIT_DIRS:=$(shell find "./$(SRC_DIR)/$(UNIT_DIR)" -type d)
UNIT_SRCS:=$(shell find "./$(SRC_DIR)/$(UNIT_DIR)" -type f -name '*$(UNIT_SUFFIX)')
UNIT_OBJS:=$(patsubst ./$(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(UNIT_SRCS))

DEPS:=$(OBJS:.o=.d) $(UNIT_OBJS:.o=.d)

CFLAGS=\
	-I$(INC_DIR) -I$(GEN_DIR) \
	-I$(LIB_DIR)/include \
	-Wall -Wextra -Werror \
	-MT $@ -MMD -MP -MF $(OBJ_DIR)/$*.d \
	-fsanitize=address -g3

LDFLAGS:=\
	-Wall -Wextra -Werror \
	-fsanitize=address -g3

LDLIBS:=-L$(LIB_DIR) -lft

all: $(NAME)

# Directories
$(OBJ_DIR) $(GEN_DIR):
	mkdir -p "$@"

# Generated sources
$(GEN_DIR)/units.h: gen-units.sh $(UNIT_DIRS) | $(GEN_DIR)
	./gen-units.sh $(SRC_DIR)/$(UNIT_DIR) $(UNIT_SUFFIX) > $@

# Objects
$(OBJ_DIR)/main.o: $(GEN_DIR)/units.h | $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	mkdir -p $(@D)
	$(COMPILE.c) $(OUTPUT_OPTION) $<

# Dependencies
$(DEPS): $(OBJ_DIR)/%.d:
include $(wildcard $(DEPS))

# Executables
$(NAME): $(OBJS) $(UNIT_OBJS) $(LIB_DIR)/libft.a
	$(CC) $(LDFLAGS) -o $(NAME) $^ $(LDLIBS)

clean:
	rm -rf $(OBJ_DIR) $(GEN_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
