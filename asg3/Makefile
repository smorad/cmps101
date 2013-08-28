CC = gcc
CFLAGS = -c -Wall -DDEBUG -g -std=c99
LDFLAGS =
SOURCES = $(COMMON_SOURCES) $(MAIN_SOURCES) $(LDRIVER_SOURCES) $(HDRIVER_SOURCES)
COMMON_SOURCES = bookCountList.c bookCountList.h hashTable.c hashTable.h
MAIN_SOURCES = recommend.c
LDRIVER_SOURCES = listdr.c
HDRIVER_SOURCES = hashDriver.c
COMMON_OBJECTS = $(COMMON_SOURCES:.c=.o)
MAIN_OBJECTS = $(MAIN_SOURCES:.c=.o)
LDRIVER_OBJECTS = $(LDRIVER_SOURCES:.c=.o)
HDRIVER_OBJECTS = $(HDRIVER_SOURCES:.c=.o)
MAIN_EXECUTABLE = recommend
LDRIVER_EXECUTABLE = listDriver
HDRIVER_EXECUTABLE = hashDriver

.PHONY: all main ldriver hdriver ci

all: main ldriver hdriver ci

main: $(MAIN_EXECUTABLE)

ldriver: $(LDRIVER_EXECUTABLE)

hdriver: $(HDRIVER_EXECUTABLE)

$(MAIN_EXECUTABLE): $(COMMON_OBJECTS) $(MAIN_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(LDRIVER_EXECUTABLE): $(COMMON_OBJECTS) $(LDRIVER_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(HDRIVER_EXECUTABLE): $(COMMON_OBJECTS) $(HDRIVER_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@


ci : ${SOURCES}
	cid + ${SOURCES}

clean : 
	-rm *.o *.gch
