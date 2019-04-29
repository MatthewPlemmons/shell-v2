all: shell.c builtins.c execute.c parser.c
	gcc -g -o hsh *.c
