NAME = libft.a

# Compiler and linker
CC = cc
LD = cc
AR = ar

# Paths
include srcs.mk
INCDIR = include
LIBDIR = lib

OBJDIR = obj
BINDIR = .
TESTDIR=test

# Library dependencies
LIBS = $(addprefix $(LIBDIR)/, )

LIBDIRS = $(dir $(LIBS))
LIBINCS = $(addsuffix $(INCDIR), $(LIBDIRS))
LIBARS = $(notdir $(LIBS))

# Sources
INCS = $(LIBINCS) $(INCDIR)
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
DEPS = $(OBJS:.o=.d)

# Flags
DBGFLAGS := -g3 -fsanitize=address
CFLAGS = -Wall -Wextra $(INCS:%=-I%)# $(DBGFLAGS)
DFLAGS = -MT $@ -MMD -MP -MF $(OBJDIR)/$*.d
LDFLAGS = $(LIBDIRS:%=-L%)# $(DBGFLAGS)
ARFLAGS = -rcs
LDLIBS = $(LIBARS:lib%.a=-l%)

# Compiling commands
COMPILE.c = $(CC) $(DFLAGS) $(CFLAGS) -c
COMPILE.o = $(LD) $(LDFLAGS)
ARCHIVE.o = $(AR) $(ARFLAGS)

all: $(BINDIR)/$(NAME)

# Directories
$(OBJDIR) $(BINDIR):
	@echo "MK $@"
	mkdir -p "$@"

# Libraries
$(LIBS): %.a: FORCE
	make -C $(dir $@) NAME=$(@F)

# Objects
$(OBJS): $(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@mkdir -p '$(@D)'
	@echo "CC $<"
	$(COMPILE.c) $< -o $@

# Dependencies
$(DEPS): $(OBJDIR)/%.d:
include $(wildcard $(DEPS))

# Binaries
$(BINDIR)/$(NAME): $(OBJS) $(LIBS) | $(BINDIR)
	@echo "AR $@"

	$(ARCHIVE.o) $@ $^

# Tests
test: all
	@echo "TEST $@"
	make -C $(TESTDIR) NAME=test
	./$(TESTDIR)/test

debug: CFLAGS += -DDEBUG -g3 -fsanitize=address
debug: LDFLAGS += -g3 -fsanitize=address
debug: re

clean:
	$(foreach dir, $(LIBDIRS),\
		@echo "MK -C $(dir) $@" && make -C $(dir) $@ && ):

	@echo "MK -C $(TESTDIR) $@"
	make -C $(TESTDIR) $@

	@echo "RM $(OBJDIR)"
	rm -rf "$(OBJDIR)"

fclean: clean
	$(foreach dir, $(LIBDIRS),\
		@echo "MK -C $(dir) $@" && make -C $(dir) $@ && ):

	@echo "MK -C $(TESTDIR) $@"
	make -C $(TESTDIR) $@

	@echo "RM $(BINDIR)/$(NAME)"
	rm -f "$(BINDIR)/$(NAME)"

	@rmdir "$(BINDIR)" 2>/dev/null && echo "RM $(BINDIR)" || :

re: fclean all

FORCE: ;

.PHONY: all clean fclean re FORCE

# Assign a value to VERBOSE to enable verbose output
$(VERBOSE).SILENT:
