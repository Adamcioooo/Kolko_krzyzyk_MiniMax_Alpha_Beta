#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

TRGDIR=/tmp/kolko_2

__start__: ./kolko_2
	./kolko_2

./kolko_2: obj obj/main.o  obj/kolko_krzyzyk.o 
                        
	g++ -Wall -pedantic -std=c++11 -o ./kolko_2 obj/main.o  obj/kolko_krzyzyk.o 

obj:
	mkdir -p obj

obj/main.o: src/main.cpp inc/kolko_krzyzyk.hh 
        
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/kolko_krzyzyk.o: inc/kolko_krzyzyk.hh src/kolko_krzyzyk.cpp
	g++ -c ${CXXFLAGS} -o obj/kolko_krzyzyk.o src/kolko_krzyzyk.cpp

clean:
	rm -f obj/*.o ./kolko_2