# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Source files
SRC = main.cpp String.cpp StringFriend.cpp

# Output executable
OUT = app

# Default target to build the project
all: $(OUT)

# Rule to build the executable
$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)
	rm -f $(SRC:.cpp=.o)  # Remove object files after linking

# Clean up generated files
clean:
	rm -f $(OUT)


