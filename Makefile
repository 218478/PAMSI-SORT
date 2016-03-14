__start__: Program
	./Program 

Program: obj obj/Main.o obj/Array.o obj/TimeCounter.o 
	g++ -o Program obj/Main.o obj/Array.o\
			obj/TimeCounter.o

obj:
	mkdir obj

obj/Main.o: Main.cpp 
	g++ -c -o obj/Main.o Main.cpp

obj/Array.o: Array.cpp Array.hh
	g++ -c -o obj/Array.o Array.cpp

obj/TimeCounter.o: TimeCounter.cpp TimeCounter.hh
	g++ -c -o obj/TimeCounter.o TimeCounter.cpp

clean:
	rm -f obj/*.o Program
