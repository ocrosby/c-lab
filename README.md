# C Programming Notes


## Makefiles


## Compiling

In this section we will discuss how to compile C code.

## Linking

In this section we will discuss how to link C code.

Source Code:
: the code we write

Object Code:
: sequence of statements in machine language

Compilation:
: the translation of source code into object code by a compiler

The compilation process has four different steps:

* preprocessing
* compiling
* assembling
* linking

GCC:
: GNU Compiler Collection


## The Preprocessor

The roles of the preprocessor are to:

* remove comments in the source files(s)
* includes the code of the header file(s), which is a file with extension .h that contains C function declarations and macro definitions
* replace all the macros (fragments of code which have been given a name) by their values

The output of this step will be stored in a file with a ".i" extension

In order to stop the compilation process after the preprocessing step, we can use the -E option:

```shell
gcc -E hello.c -o hello.i
```

This tells the compiler to compile a file named hello.c and to output the result to a file named hello.i.
The $-E$ option tells the compiler to stop after the preprocessing step.

## The Compiler

The compiler will take the preprocessed file and generate IR code, and will produce a.s file.

IR Code:
: Intermediate Representation Code

We can stop after this step with the $-S$ option:

```shell
gcc -S hello.i -o hello.s
```

## The Assembler

The assembler takes the IR code and transforms it into object code, that is
code in machine language (i.e. binary).  This will produce a file ending
in ".o".

We can stop after this step with the $-c$ option:

```shell
gcc -c hello.s -o hello.o
```

## The Linker

The linker creates the final executable, in binary, and can play two roles:

* linking all the source files together, that is all the other object codes in the project.  For example, if I want to compile main.c with another file called secondary.c and make them into one single program, this is the step where the object code of secondary.c (that is secondary.o) will be linked into the main.c object code (main.o).
* linking function calls with their definitions. The linker knows where to look for the function definitions in the static libraries or dynamic libraries. Static libraries are "the result of the linker making a copy of all used library functions to the executable file" while dynamic libraries "don't require the code to be copied, it is done by just placing the name of the library in the binary file".

## Libraries

In C, there are two types of libraries:

* static libraries
* dynamic libraries

When would you use one over the other?

Static libraries are linked at compile time, while dynamic libraries are linked at runtime.

This means that static libraries are included in the executable, while dynamic libraries are not.

### Static Libraries

To create a static library, we use the ar command:

Step 1: Compile your source files into object files:

```shell
gcc -c file1.c file2.c ... filen.c
```

Step 2: Use the 'ar' command to bundle the object files into a static library:

```shell
ar rcs libmylib.a file1.o file2.o ... filen.o
```

To link a static library into your program, you need to include the
library during the linking phase of your build process. You can do this
by adding the library to your gcc command with the -l option followed
by the library name (without the lib prefix and .a extension), and -L
option followed by the directory where your library is located.

Assuming your static library is named libmylib.a and it's in the same
directory as your source files, you can modify your Makefile to include
this library in the linking process:

```make
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -L. -lmylib

.PHONY: clean all

all: a.out

# Rule for preprocessing any .c file
%.i: %.c
	$(CC) $(CFLAGS) -E $< -o $@

# Generic rule for compiling any .c file to an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compiles a main.c source file into an executable file
a.out: main.o
	$(CC) $(LDFLAGS) main.o -o a.out

# Cleans by removing the default a.out executable file
clean:
	@rm -f a.out
	@rm -f *.s
	@rm -f *.o
	@rm -f *.i

# Compiles and runs the default executable a.out file.
run: a.out
	./a.out
```


### Dynamic Libraries

To create a dynamic library, we use the gcc command:

```shell
gcc -shared -o libhello.so hello.o
```

To link a dynamic library into your program, you need to include the library during the linking phase of your build process. You can do this by adding the library to your gcc command with the -l option followed by the library name (without the lib prefix and .so extension), and -L option followed by the directory where your library is located.  Assuming your dynamic library is named libmylib.so and it's in the same directory as your source files, you can modify your Makefile to include this library in the linking process. Here's how you can do it:

```make
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -L. -lmylib

.PHONY: clean all

all: a.out

# Rule for preprocessing any .c file
%.i: %.c
 $(CC) $(CFLAGS) -E $< -o $@

# Generic rule for compiling any .c file to an object file
%.o: %.c
 $(CC) $(CFLAGS) -c $< -o $@

# Compiles a main.c source file into an executable file
a.out: main.o
 $(CC) $(LDFLAGS) main.o -o a.out

# Cleans by removing the default a.out executable file
clean:
 @rm -f a.out
 @rm -f *.s
 @rm -f *.o
 @rm -f *.i

# Compiles and runs the default executable a.out file.
run: a.out
 ./a.out
```