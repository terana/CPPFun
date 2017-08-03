CXXFLAGS=  -Wall -std=c++11

SOURCES=main.cpp AST.cpp error.cpp AST_builder.cpp
TARGET=run

$(TARGET): $(SOURCES:.cpp=.o)
	$(CXX) $(CXXFLAGS)   $^ -o $@

clean:
	rm -f *.o run