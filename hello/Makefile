CC = gcc
CFLAGS = -Wall -g

.PHONY: clean all

all: a.out

# Rule for preprocessing any .c file
%.i: %.c
	$(CC) $(CFLAGS) -E $< -o $@

# Generic rule for compiling any .c file to an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compiles a main.c source file into an executable file
a.out: main.c
	$(CC) main.c

# Cleans by removing the default a.out executable file
clean:
	@rm -f a.out
	@rm -f *.s
	@rm -f *.o
	@rm -f *.i

# Compiles and runs the default executable a.out file.
run: a.out
	./a.out

