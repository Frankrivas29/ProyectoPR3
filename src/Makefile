# Makefile for a C++ program
# Define the compiler and flags
CXX = clang++ -std=c++17
CXXFLAGS = -Wall -Wextra -I../include
# List of source files
SRCS = Main.cpp Personaje.cpp Enemigos.cpp Cartas.cpp
# List of object files (automatically generated from source files)
OBJS = $(SRCS:.cpp=.o)
# Target rule: Main
Main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
# Rule to compile each source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<