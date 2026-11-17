CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -Werror -g
TARGET = midnight_mischief
OBJECTS = main.o Cat.o Adventure.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	g++ $(CXXFLAGS) -o $@ $^

main.o: main.cpp Adventure.h Cat.h
Cat.o: Cat.cpp Cat.h
Adventure.o: Adventure.cpp Adventure.h Cat.h

%.o: %.cpp
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
