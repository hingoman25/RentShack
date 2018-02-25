CXX = g++
CXXFLAGS = -std=c++0x -Wall

OBJECTS = main.o Most_frequent.o Highest_rate.o Info_type.o Post.o User.o Sorting_client.o

main: $(OBJECTS)
		$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJECTS): Postsort.h Most_frequent.h Highest_rate.h Info_type.h Post.h User.h Sorting_client.h

clean:
	rm -f *.o main