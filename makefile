transcript.o: transcript.cpp transcript.h
	g++ -c -pedantic-errors -std=c++11 transcript.cpp

print_tasks.o: print_tasks.cpp print_tasks.h
	g++ -c -pedantic-errors -std=c++11 print_tasks.cpp

main.o: main.cpp transcript.h print_tasks.h
	g++ -c -pedantic-errors -std=c++11 main.cpp

game: transcript.o print_tasks.o main.o
	g++ -pedantic-errors -std=c++11 transcript.o print_tasks.o main.o -o game
