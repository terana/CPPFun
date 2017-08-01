CXXFLAGS=  -Wall -std=c++11
CFLAGS= -Wall

SOURCES=main.cpp bit_array.cpp num_gen.c
TARGET=run

$(TARGET):
	$(CC) -c num_gen.c
		$(CXX) -c main.cpp bit_array.cpp
			$(CXX) $(CXXFLAGS) main.o bit_array.o num_gen.o -o run

clean:
	rm -f *.o run *txt