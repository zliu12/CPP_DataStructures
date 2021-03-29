all: main

main: main.o linked_list.o node.o Node_Iterator.o
	clang++ -std=c++14 -o $@ $^

main.o: main.cpp linked_list.h
	clang++ -std=c++14 -c $<

linked_list.o: linked_list.cpp linked_list.h
	clang++ -std=c++14 -c $<

node.o: node.cpp node.h
	clang++ -std=c++14 -c $<

Node_Iterator.o: Node_Iterator.cpp Node_Iterator.h
	clang++ -std=c++14 -c $<

clean:
	rm -f main linked_list? *.o Node_Iterator? *.o