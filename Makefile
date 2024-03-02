CXX = g++
CXXFLAGS = -Wall -Wpedantic -Werror

SRCS = $(wildcard ./src/*.cpp)
OBJS = $(addsuffix .o, $(basename $(SRCS)))

labirynth: $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@

clean:
	rm labirynth
	rm $(OBJS)