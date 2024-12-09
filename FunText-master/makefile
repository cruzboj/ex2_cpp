# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -O2 -std=c++11

# Targets
TARGET = runMe
OBJS = FunText.o main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

FunText.o: FunText.cpp FunText.h
	$(CXX) $(CXXFLAGS) -c FunText.cpp

main.o: main.cpp FunText.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f $(TARGET) *.o
