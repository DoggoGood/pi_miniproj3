CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = main
OBJS = 343333.o adjacency_matrix.o incidence_matrix.o adjacency_list.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

343333.o: 343333.c adjacency_matrix.h incidence_matrix.h adjacency_list.h
	$(CC) $(CFLAGS) -c 343333.c

adjacency_matrix.o: adjacency_matrix.c adjacency_matrix.h
	$(CC) $(CFLAGS) -c adjacency_matrix.c

incidence_matrix.o: incidence_matrix.c incidence_matrix.h
	$(CC) $(CFLAGS) -c incidence_matrix.c

adjacency_list.o: adjacency_list.c adjacency_list.h
	$(CC) $(CFLAGS) -c adjacency_list.c

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
