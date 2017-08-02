CXXFLAGS=  -Wall -std=c++11

SOURCES=main.cpp table.cpp error.cpp lex.cpp syn.cpp
TARGET=run

$(TARGET): $(SOURCES:.cpp=.o)
	$(CXX) $(CXXFLAGS)   $^ -o $@

clean:
	rm -f *.o run