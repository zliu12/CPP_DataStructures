all: main

main: main.o Queue.o Stack.o linked_list.o
	clang++ -std=c++14 -o $@ $^

main.o: main.cpp Queue.cpp Stack.cpp
	clang++ -std=c++14 -c $<

Queue.o: Queue.cpp Queue.h
	clang++ -std=c++14 -c $<

Stack.o: Stack.cpp Stack.h
	clang++ -std=c++14 -c $<

linked_list.o: ../linked_list/linked_list.cpp ../linked_list/linked_list.h
	clang++ -std=c++14 -c $<

clean:
	rm -f main main.o Queue.o Stack.o linked_list.o