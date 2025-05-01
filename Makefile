# Makefile for Banker's Algorithm

CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = bankers
SRC = bankers.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET) input.txt

safe: $(TARGET)
	@echo "===== SAFE TEST ====="
	cp test_safe.txt input.txt
	./$(TARGET) input.txt

unsafe: $(TARGET)
	@echo "===== UNSAFE TEST ====="
	cp test_unsafe.txt input.txt
	./$(TARGET) input.txt

test: safe unsafe

clean:
	rm -f $(TARGET)