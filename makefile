## Shell-Todo Main Makefile ## ~ eylon

#---# SETTINGS #---#

export ROOT_DIR  := $(shell pwd)
export CONFIG_MK := auto/config.mk

include $(CONFIG_MK)

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
	${EXECUTABLE} ${ARGS} ${shell cat auto/command-line-arguments}

#---# UTILS #---#

clean:
	rm -rf ${BIN_DIR}

.PHONY: all run clean
