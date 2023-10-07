## Config Makefile ## ~ eylon

SRC_DIR  := $(ROOT_DIR)/src
BIN_DIR  := $(ROOT_DIR)/bin
INCLUDE_DIR := $(SRC_DIR)/include

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRCS))

EXECUTABLE := $(BIN_DIR)/shell-todo.bin

CC     := gcc
CFLAGS := -I$(INCLUDE_DIR) -g -Wall -Wextra