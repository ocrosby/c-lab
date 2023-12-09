# Define the compiler
CC=gcc

# Define any compile-time flags
CFLAGS=-Wall -g

# Define any directories containing header files other than /usr/include
INCLUDES=

# Define library paths in addition to /usr/lib
LFLAGS=

# Define any libraries to link to executable:
LIBS=

# Define the C source files
SRCS=f2c.c conversion.c

# Define the C object files
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#   For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS=$(SRCS:.c=.o)

# Define the executable file
MAIN=f2c

#
# The following part of the makefile is generic; it can be used to
# build any executable just by changing the above definitions and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean

all:    $(MAIN)
	@echo  Simple compiler named $(MAIN) has been compiled

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

# This is a suffix replacement rule for building .o's from .c's
# It uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file)
# (see the gnu make manual for more information)
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
