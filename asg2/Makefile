C = gcc
CFLAGS = -c -Wall -DDEBUG -g -std=c99
LDFLAGS =
SOURCES = $(COMMON_SOURCES) $(COMP_SOURCES) $(PRINT_SOURCES) $(TEST_SOURCES)
COMMON_SOURCES = insertionSort.c insertionSort.h heapSort.c heapSort.h heap.c heap.h
COMP_SOURCES = sortComp.c
PRINT_SOURCES = sortPrint.c
TEST_SOURCES = heapDriver.c
COMMON_OBJECTS = $(COMMON_SOURCES:.c=.o)
COMP_OBJECTS = $(COMP_SOURCES:.c=.o)
PRINT_OBJECTS = $(PRINT_SOURCES:.c=.o)
TEST_OBJECTS = $(TEST_SOURCES:.c=.o)
COMP_EXECUTABLE = sortComp
PRINT_EXECUTABLE = sortPrint
TEST_EXECUTABLE = heapDriver

.PHONY: all comp print tests ci

all: comp print tests ci

comp: $(COMP_EXECUTABLE)

print: $(PRINT_EXECUTABLE)

tests: $(TEST_EXECUTABLE)

$(COMP_EXECUTABLE): $(COMMON_OBJECTS) $(COMP_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(PRINT_EXECUTABLE): $(COMMON_OBJECTS) $(PRINT_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(TEST_EXECUTABLE): $(COMMON_OBJECTS) $(TEST_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@


ci : ${SOURCES}
	cid + ${SOURCES}
