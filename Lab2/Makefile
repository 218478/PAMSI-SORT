__start__: Program
	./Program 

Program: obj obj/Main.o obj/Array.o obj/TimeCounter.o obj/IRunnable.o\
	obj/IStoper.o
	g++ -o Program obj/Main.o obj/Array.o\
			obj/TimeCounter.o obj/IRunnable.o\
			obj/IStoper.o

obj:
	mkdir obj

obj/Main.o: Main.cpp 
	g++ -c -o obj/Main.o Main.cpp

obj/Array.o: Array.cpp Array.hh
	g++ -c -o obj/Array.o Array.cpp

obj/TimeCounter.o: TimeCounter.cpp TimeCounter.hh
	g++ -c -o obj/TimeCounter.o TimeCounter.cpp

obj/IRunnable.o: IRunnable.cpp IRunnable.hh
	g++ -c -o obj/IRunnable.o IRunnable.cpp

obj/IStoper.o: IStoper.cpp IStoper.hh
	g++ -c -o obj/IStoper.o IStoper.cpp

clean:
	rm -f obj/*.o Program
