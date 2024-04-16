CC = gcc
CFLAGS = -Wall -g
AR = ar
ARFLAGS = rcs
LIB = libadtlib.a
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.PHONY: all clean

all: $(LIB)

$(LIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

test_linked_list: $(LIB)
	$(CC) $(CFLAGS) -I./include -o tests/test_linked_list tests/test_linked_list.c -L. -l../$(basename $(LIB) .a)

test_double_linked_list: $(LIB)
	$(CC) $(CFLAGS) -I. -o tests/test_double_linked_list tests/test_double_linked_list.c -L. -l$(basename $(LIB) .a)

test_stack: $(LIB)
	$(CC) $(CFLAGS) -I. -o tests/test_stack tests/test_stack.c -L. -l$(basename $(LIB) .a)

test_queue: $(LIB)
	$(CC) $(CFLAGS) -I. -o tests/test_queue tests/test_queue.c -L. -l$(basename $(LIB) .a)

test_map: $(LIB)
	$(CC) $(CFLAGS) -I. -o tests/test_map tests/test_map.c -L. -l$(basename $(LIB) .a)

unit-tests: test_linked_list test_double_linked_list test_stack test_queue test_map
	./tests/test_linked_list
	./tests/test_double_linked_list
	./tests/test_stack
	./tests/test_queue
	./tests/test_map

clean:
	rm -f $(LIB) $(OBJS)
	rmdir $(OBJ_DIR)