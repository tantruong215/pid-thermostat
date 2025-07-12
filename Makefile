# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -I./src

# Directories
BUILD_DIR := build
SRC_DIR   := src
TEST_DIR  := tests

# Source and object files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS := $(TEST_SRCS:$(TEST_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Default target
all: $(BUILD_DIR)/main $(BUILD_DIR)/test_pid $(BUILD_DIR)/test_plant

# Link main executable
$(BUILD_DIR)/main: $(OBJS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile source .cpp → .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link PID test
$(BUILD_DIR)/test_pid: $(BUILD_DIR)/test_pid.o $(BUILD_DIR)/pid.o | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Link Plant test
$(BUILD_DIR)/test_plant: $(BUILD_DIR)/test_plant.o $(BUILD_DIR)/plant_sim.o | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile test .cpp → .o
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory if missing
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up artifacts
clean:
	rm -rf $(BUILD_DIR) response.csv response.png

.PHONY: all clean
