CC	=g++
CFLAGS	=-c -Wall -O4 -ffast-math -ffinite-math-only -I ./../header/
LDFLAGS	=
SOURCES	= ./../tests/test_get_SVD.cpp ./../src/get_SVD.cpp
OBJECTS	=$(SOURCES:.cpp=.o)
EXECUTABLE	=./../exec/get_SVD

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.out ./../tests/*.o ./../exec/* ./../src/*.o