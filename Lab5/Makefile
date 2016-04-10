# Makefile jest zle zrobiony, tj. powinienes dodac kazdy plik naglowkowy tam gdzie jakis obiekt
# go potrzebuje. W przeciwnym wypadku Makefile nie widzi, ze zmieniles jakis plik i nie zkompiluje go na nowo
__start__: Program
	./Program 

Program: obj obj/Main.o obj/Array.o obj/TimeCounter.o obj/ArrayRunner.o\
	 obj/Stack.o obj/Queue.o obj/List.o obj/ListTest.o obj/QuickSortArray.o\
	obj/MergeSortArray.o
	g++ -g -o Program obj/Main.o obj/TimeCounter.o\
			obj/ArrayRunner.o obj/Array.o obj/Stack.o\
			obj/Queue.o obj/List.o obj/ListTest.o\
			obj/QuickSortArray.o obj/MergeSortArray.o

obj:
	mkdir obj

obj/Main.o: Main.cpp 
	g++ -c -g -o obj/Main.o Main.cpp

obj/TimeCounter.o: TimeCounter.cpp TimeCounter.hh
	g++ -c -g -o obj/TimeCounter.o TimeCounter.cpp

obj/ArrayRunner.o: ArrayRunner.cpp ArrayRunner.hh
	g++ -c -g -o obj/ArrayRunner.o ArrayRunner.cpp

obj/Array.o: Array.cpp Array.hh
	g++ -c -g -o obj/Array.o Array.cpp

obj/Stack.o: Stack.cpp Stack.hh
	g++ -c -g -o obj/Stack.o Stack.cpp

obj/Queue.o: Queue.cpp Queue.hh
	g++ -c -g -o obj/Queue.o Queue.cpp

obj/List.o: List.cpp List.hh
	g++ -c -g -o obj/List.o List.cpp

obj/ListTest.o: ListTest.cpp ListTest.hh
	g++ -c -g -o obj/ListTest.o ListTest.cpp

obj/QuickSortArray.o: QuickSortArray.cpp QuickSortArray.hh
	g++ -c -g -o obj/QuickSortArray.o QuickSortArray.cpp

obj/MergeSortArray.o: MergeSortArray.cpp MergeSortArray.hh
	g++ -c -g -o obj/MergeSortArray.o MergeSortArray.cpp

clean:
	rm -f obj/*.o Program
