CC	=g++
CFLAGS	=-c -Wall -O4 -ffast-math -ffinite-math-only -I ./../header/
LDFLAGS	=
SOURCES	= ./../tests/test_get_Log_Determinant.cpp
OBJECTS	=$(SOURCES:.cpp=.o)
EXECUTABLE	=./../exec/get_Log_Determinant

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.out ./../tests/*.o ./../exec/* ./../src/*.o