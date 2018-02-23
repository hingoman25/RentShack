
PROG=prog1
CC=g++
CPPFLAGS=-g -Wall -std=c++11

.PHONY: all

all:
	$(CC) $(CPPFLAGS) main.cpp Info_Type.h Info_Type.cpp Post.h Post.cpp User.h User.cpp Postsort.h Most_frequent.h Most_frequent.cpp Highest_rate.h Highest_rate.cpp Sorting_client.h Sorting_client.cpp -o $(PROG)

clean:
	rm -f *.o $(PROG) core