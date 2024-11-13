CC = gcc
CFLAGS = -Wall -g
DEPS = functions.h
OBJ = main.o login.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

programa: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o programa
