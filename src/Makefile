P=hello_instrumented
OBJECTS=hello.o trace.o
CFLAGS = -Wall -Wextra -pedantic -O0
LDLIBS=
CC=c99

all: main

main: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(P)

hello.o: hello.c
	$(CC) $(CFLAGS) -finstrument-functions -c -o $@ $<

trace.o: trace.c
	$(CC) $(CFLAGS) -c -o $@ $<

