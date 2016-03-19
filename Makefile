__start__: Program
	./Program 

Program: obj obj/Main.o obj/Array.o obj/TimeCounter.o obj/ArrayRunner.o\
	 obj/Stack.o obj/Queue.o  
	g++ -o Program obj/Main.o obj/TimeCounter.o\
			obj/ArrayRunner.o obj/Array.o obj/Stack.o\
			obj/Queue.o

obj:
	mkdir obj

obj/Main.o: Main.cpp 
	g++ -c -o obj/Main.o Main.cpp

obj/TimeCounter.o: TimeCounter.cpp TimeCounter.hh
	g++ -c -o obj/TimeCounter.o TimeCounter.cpp

obj/ArrayRunner.o: ArrayRunner.cpp ArrayRunner.hh
	g++ -c -o obj/ArrayRunner.o ArrayRunner.cpp

obj/Array.o: Array.cpp Array.hh
	g++ -c -o obj/Array.o Array.cpp

obj/Stack.o: Stack.cpp Stack.hh
	g++ -c -o obj/Stack.o Stack.cpp

obj/Queue.o: Queue.cpp Queue.hh
	g++ -c -o obj/Queue.o Queue.cpp

clean:
	rm -f obj/*.o Program
