CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -I./src
BUILD_DIR := build
SRC_DIR := src
TEST_DIR := tests

SRCS := \
OBJS := \

TEST_SRCS := \
TEST_OBJS := \

all: \/main \/test_pid \/test_plant

\/main: \
\t\ \ \$makefile -o \$@

\/%.o: \/%.cpp | \
\t\ \ -c \$< -o \$@

\/test_pid: \/test_pid.o \/pid.o
\t\ \ \$makefile -o \$@

\/test_plant: \/test_plant.o \/plant_sim.o
\t\ \ \$makefile -o \$@

\/%.o: \/%.cpp | \
\t\ \ -c \$< -o \$@

\:
\tmkdir -p \

clean:
\trm -rf \ response.csv response.png

.PHONY: all clean
