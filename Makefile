PROGRAM = main.exe
CXXFLAGS = -Wall -g

$(PROGRAM): main.o Node.o student.o
	g++ -o $@ $^

clean:
	rm -f $(PROGRAM) *.o

run: $(PROGRAM)
	./$(PROGRAM)

main.o: main.cpp Node.h student.h
student.o: student.cpp Node.h student.h

