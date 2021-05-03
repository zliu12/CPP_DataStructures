all: main

main: main.o BinaryTree.o
	clang++ -std=c++14 -o $@ $^

main.o: main.cpp BinaryTree.h
	clang++ -std=c++14 -c $<

BinaryTree.o: BinaryTree.cpp BinaryTree.h Node.h
	clang++ -std=c++14 -c $<


clean:
	rm -f main main.o BinaryTree.o