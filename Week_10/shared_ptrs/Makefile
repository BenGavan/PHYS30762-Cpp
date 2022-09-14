
main.o: main.cpp
	g++ -std=c++11 -o main main.cpp

#g++ -std=c++11 -o main main.cpp -lgmsh

run: main.cpp
	#g++ -std=c++11 -o main main.cpp
	g++-11 -std=c++11 *.cpp -o main
	./main

clean:
	rm *.o output