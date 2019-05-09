CC=gcc
CFLAGS=-g
DEPS = shell.h
OBJ = strings.o strings2.o shell.o env.o builtins.o execute.o parser.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hsh: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
