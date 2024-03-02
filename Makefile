iXX = g++
CXXFLAGS = -Wall -Wpedantic -Werror -g

SRCS = $(wildcard ./src/*.cpp)
OBJS = $(addsuffix .o, $(basename $(SRCS)))

labyrinth: $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@

clean:
	rm labyrinth
	rm $(OBJS)
