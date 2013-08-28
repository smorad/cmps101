C = gcc
CFLAGS = -c -Wall -DDEBUG -g -std=c99
LDFLAGS =
SOURCES = $(COMMON_SOURCES) $(MAIN_SOURCES) $(TEST_SOURCES) $(TEST2_SOURCES)
COMMON_SOURCES = list.c list.h graph.c graph.h
MAIN_SOURCES = google.c
TEST_SOURCES = graphDriver.c
TEST2_SOURCES = listdr.c
COMMON_OBJECTS = $(COMMON_SOURCES:.c=.o)
MAIN_OBJECTS = $(MAIN_SOURCES:.c=.o)
TEST_OBJECTS = $(TEST_SOURCES:.c=.o)
TEST2_OBJECTS = $(TEST2_SOURCES:.c=.o)
MAIN_EXECUTABLE = googleMaps
TEST_EXECUTABLE = graphDriver
TEST2_EXECUTABLE = listDriver

.PHONY: all main tests tests2 ci

all:  main tests tests2 ci

main: $(MAIN_EXECUTABLE)

tests: $(TEST_EXECUTABLE)

tests2: $(TEST2_EXECUTABLE)

$(MAIN_EXECUTABLE): $(COMMON_OBJECTS) $(MAIN_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(TEST_EXECUTABLE): $(COMMON_OBJECTS) $(TEST_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(TEST2_EXECUTABLE): $(COMMON_OBJECTS) $(TEST2_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@ 

.c.o:
	$(CC) $(CFLAGS) $< -o $@


ci : ${SOURCES}
	cid + ${SOURCES}
clean : 
	-rm *.gch *.o
