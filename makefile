OBJS	= Student.o SortedList.o SortedListDr.o
SOURCE	= Student.cpp SortedList.cpp SortedListDr.cpp
HEADER	= Student.h SortedList.h
OUT	= SortedListDr
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Student.o: Student.cpp
	$(CC) $(FLAGS) Student.cpp 

SortedList.o: SortedList.cpp
	$(CC) $(FLAGS) SortedList.cpp 

SortedListDr.o: SortedListDr.cpp
	$(CC) $(FLAGS) SortedListDr.cpp 


clean:
	rm -f $(OBJS) $(OUT)
