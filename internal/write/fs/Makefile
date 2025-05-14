srcdir = .

CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS =

SRCS = $(wildcard $(srcdir)/src/**/*.c)
HEADERS = $(wildcard $(srcdir)/src/**/*.h)
OBJS = $(addprefix obj/,$(patsubst $(srcdir)/src/%,obj/%,$(patsubst %.c,%.o,$(notdir $(SRCS)))))

BIN=bin/main

-include config.mak

ifeq ($(wildcard config.mak),)
all:
	@echo "File config.mak not found, run configure"
	@exit 1
else

all: clean bin obj $(BIN)

obj:
	mkdir -p $@
bin:
	mkdir -p $@

obj/%.o: $(srcdir)/src/**/%.c
	$(CC) $(CFLAGS) -c $< -o $@

endif

install:
	@echo "NOT IMPL"
	exit 1

uninstall:
	@echo "NOT IMPL"
	exit 1

clean:
	rm -rf obj bin

dist-clean: clean
	rm config.mak

.PHONY: all clean dist-clean install uninstall
