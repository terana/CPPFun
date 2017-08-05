CXXFLAGS=  -Wall -std=c++11

SOURCES=draw.cpp rectangle.cpp screen.cpp
TARGET=run

$(TARGET): $(SOURCES:.cpp=.o)
	$(CXX) $(CXXFLAGS)   $^ -o $@

clean:
	rm -f *.o run