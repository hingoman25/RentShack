CXX = g++
CXXFLAGS = -std=c++0x -Wall

OBJECTS = main.o Most_frequent.o Highest_rate.o

main: $(OBJECTS)
		$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJECTS): Postsort.h Most_frequent.h Highest_rate.h

clean:
	rm -f *.o main
