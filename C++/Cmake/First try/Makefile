# Makefile for building, cleaning, and running a C++ program
#Flags needed for the run(Bassim issue)..warring LvL
CXXFLAGS = -Wall -Wextra -pedantic -v
# Compiler
CXX = g++

# Target executable (named main)
TARGET = main

# Source file (named main.cpp)
SRC = main.cpp

# Build target
build: $(SRC)
	$(CXX) -o $(TARGET) $(SRC)

# Clean target
clean:
	rm -f $(TARGET)

# Run target
run: build
	./$(TARGET)
