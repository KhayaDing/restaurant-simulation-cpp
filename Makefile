# Makefile for Restaurant Simulation Program
# Algorithm Analysis and Program Design - Data Structures

# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET = restaurant_simulation
SOURCE = restaurant_simulation.cpp

# Default target
all: $(TARGET)

# Compile the program
$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build files
clean:
	rm -f $(TARGET)

# Help target
help:
	@echo "Available targets:"
	@echo "  all     - Build the program (default)"
	@echo "  run     - Build and run the program"
	@echo "  clean   - Remove build files"
	@echo "  help    - Show this help message"

.PHONY: all run clean help 