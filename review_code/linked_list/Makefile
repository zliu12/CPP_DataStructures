all: main

main: main.o linked_list.o node.o
	clang++ -std=c++14 -o $@ $^

main.o: main.cpp linked_list.h
	clang++ -std=c++14 -c $<

linked_list.o: linked_list.cpp linked_list.h
	clang++ -std=c++14 -c $<

node.o: node.cpp
	clang++ -std=c++14 -c $<

clean:
	rm -f main
	rm -f linked_list? *.o