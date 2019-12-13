###############################################################################
# Project name: Final Project - Makefile
# Name: Nicole Reynoldson
# Date: 8/13/19
# #############################################################################

CXX = g++
CXXFLAGS = -g -std=c++0x -Wall -pedantic-errors
OBJS = $(SRCS:.cpp=.o)
SRCS = Beach.cpp Space.cpp Cave.cpp getInput.cpp Inventory.cpp Player.cpp Option.cpp SparseForest.cpp DenseForest.cpp menu.cpp Island.cpp main.cpp utilityFunctions.cpp Hut.cpp
HEADERS = Beach.hpp Space.hpp Cave.hpp getInput.hpp Inventory.hpp Player.hpp Option.hpp SparseForest.hpp DenseForest.hpp menu.hpp Island.hpp constants.hpp utilityFunctions.hpp Hut.hpp
TARGET = final

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	rm $(OBJS) $(TARGET)

