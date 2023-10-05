## Shell-Todo Main Makefile ## ~ eylon

#---# SETTINGS #---#

ROOT_DIR := $(shell pwd) 
SRC_DIR  := src
BIN_DIR  := bin
INCLUDE_DIR := $(SRC_DIR)/include

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRCS))

EXECUTABLE := $(BIN_DIR)/shell-todo.bin

CC     := gcc
CFLAGS := -I$(INCLUDE_DIR) -g -Wall -Wextra


#---# COMPILE #---#

all: $(EXECUTABLE)

# Link
$(EXECUTABLE): $(OBJS)
	@mkdir -p ${BIN_DIR}
	gcc ${CFLAGS} -o $@ $^

# Compile
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(shell dirname $@)
	${CC} ${CFLAGS} -c -o $@ $<
	

#---# EXECUTE #---#

run: $(EXECUTABLE)
	./${EXECUTABLE} ${ARGS}

#---# UTILS #---#

clean:
	rm -rf ${BIN_DIR}

.PHONY: all run clean
