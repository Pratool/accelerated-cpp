CFLAGS=-O3

grader: grader.cpp median.o Student_info.o grade.o
	g++ $(CFLAGS) grader.cpp median.o Student_info.o grade.o -o grader

grade.o: grade.cpp grade.h Student_info.h
	g++ $(CFLAGS) -c grade.cpp -o grade.o

Student_info.o: Student_info.cpp Student_info.h
	g++ $(CFLAGS) -c Student_info.cpp -o Student_info.o

median.o: median.cpp median.h
	g++ $(CFLAGS) -c median.cpp -o median.o

make all: grader
