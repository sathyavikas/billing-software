output: maincode.o functions.o
	g++ maincode.o functions.o -o output
maincode.o: maincode.c
	g++ -c maincode.c
functions.o: functions.c functions.h
	g++ -c functions.c
.PHONY: clean
clean:
	rm *.o output


