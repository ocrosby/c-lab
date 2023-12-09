hello: hello.o
	cc hello.o -o hello # Runs third

hello.o: hello.c
	cc -c hello.c -o hello.o # Runs second

clean: hello
	rm -f hello hello.o
