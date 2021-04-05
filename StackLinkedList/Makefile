all: main

main: main.o stack.o LinkedList.o Node.o
	clang++ -std=c++14 -o $@ $^

main.o: main.cpp stack.h
	clang++ -std=c++14 -c $<

stack.o: stack.cpp stack.h
	clang++ -std=c++14 -c $<

LinkedList.o: LinkedList.cpp LinkedList.h
	clang++ -std=c++14 -c $<

Node.o: Node.cpp Node.h
	clang++ -std=c++14 -c $<

clean:
	rm -f main main.o stack.o LinkedList.o Node.o
