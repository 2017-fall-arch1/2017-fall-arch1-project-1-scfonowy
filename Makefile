all: main

CFLAGS=-g -O3

main: main.o
	cc -o $@ $^

main.o: main.c Graph.o
	cc -c $(CFLAGS) main.c

Graph.o: Graph.c Graph.h Stack.o Queue.o
	cc -c $(CFLAGS) Graph.c

Stack.o: Stack.c Stack.h DataNode.o
	cc -c $(CFLAGS) Stack.c

Queue.o: Queue.c Queue.h DataNode.o
	cc -c $(CFLAGS) Queue.c

DataNode.o: DataNode.c DataNode.h
	cc -c $(CFLAGS) DataNode.c

clean:
	rm -f *.o main


