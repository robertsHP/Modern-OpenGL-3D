# Compiler
CXX = g++

# Directories
SRC_DIR = src
INC_DIR = include

# Flags
CXXFLAGS = -std=c++17 -I./$(INC_DIR) `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -ldl -lGL

# Find all .cpp files in the src directory
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJS = $(SRCS:.cpp=.o)

# Output
TARGET = your_project

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
