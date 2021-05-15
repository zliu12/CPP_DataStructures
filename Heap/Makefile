all: main

main: main.o Heap.o
	clang++ -std=c++14 -o $@ $^

main.o: main.cpp Heap.h
	clang++ -std=c++14 -c $<

Heap.o: Heap.cpp Heap.h
	clang++ -std=c++14 -c $<

clean:
	rm -f main main.o Heap.o