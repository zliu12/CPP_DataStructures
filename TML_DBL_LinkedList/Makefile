all: main

main: main.o Tml_Dbl_LinkedList.o
	clang++ -std=c++14 -o $@ $^

main.o: main.cpp Tml_Dbl_LinkedList.h
	clang++ -std=c++14 -c $<

Tml_Dbl_LinkedList.o: Tml_Dbl_LinkedList.cpp Tml_Dbl_LinkedList.h
	clang++ -std=c++14 -c $<

clean:
	rm -f main
	rm -f Tml_Dbl_LinkedList? *.o