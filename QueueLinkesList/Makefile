all: main

main: main.o queue.o LinkedList.o Node.o
	clang++ -std=c++14 -o $@ $^

main.o: main.cpp queue.h
	clang++ -std=c++14 -c $<

queue.o: queue.cpp queue.h
	clang++ -std=c++14 -c $<

LinkedList.o: LinkedList.cpp LinkedList.h
	clang++ -std=c++14 -c $<

Node.o: Node.cpp Node.h
	clang++ -std=c++14 -c $<

clean:
	rm -f main main.o queue.o LinkedList.o Node.o
