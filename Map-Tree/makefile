CXXFLAGS=  -Wall -std=c++11 -g

SOURCES=main.cpp 
TARGET=run

$(TARGET): $(SOURCES:.cpp=.o)
	$(CXX) $(CXXFLAGS)   $^ -o $@

clean:
	rm -f *.o run