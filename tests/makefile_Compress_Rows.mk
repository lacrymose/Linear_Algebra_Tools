CC	=g++
CFLAGS	=-c -Wall -O4 -ffast-math -ffinite-math-only -I ./../header/
LDFLAGS	=
SOURCES	= ./../tests/test_Compress_Rows.cpp
OBJECTS	=$(SOURCES:.cpp=.o)
EXECUTABLE	=./../exec/get_Compress_Rows

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.out ./../tests/*.o ./../exec/* ./../src/*.o