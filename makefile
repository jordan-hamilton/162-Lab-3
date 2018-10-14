# Source: http://web.engr.oregonstate.edu/~rookert/cs162/03.mp4

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o Die.o Game.o LoadedDie.o Menu.o
SRCS = main.cpp Die.cpp Game.cpp LoadedDie.cpp Menu.cpp
HEADERS = Die.hpp Game.hpp LoadedDie.hpp Menu.hpp

lab3: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o lab3

$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	rm *.o lab3
