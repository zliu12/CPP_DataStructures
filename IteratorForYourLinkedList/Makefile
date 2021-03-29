all: main

main: main.o Tml_Dbl_LinkedList.o Node_Iterator.o
	clang++ -std=c++14 -o $@ $^

main.o: main.cpp Tml_Dbl_LinkedList.h
	clang++ -std=c++14 -c $<

Tml_Dbl_LinkedList.o: Tml_Dbl_LinkedList.cpp Tml_Dbl_LinkedList.h
	clang++ -std=c++14 -c $<

Node_Iterator.o: Node_Iterator.cpp Node_Iterator.h
	clang++ -std=c++14 -c $<

clean:
	rm -f main Tml_Dbl_LinkedList? *.o Node_Iterator? *.o