CFLAGS = -std=c++17


all: svasm

svasm: svasm.o lexer.o
	$(CXX) $(CFLAGS) svasm.o lexer.o -o $@

lexer.o: lexer.h lexer.cpp
	$(CXX) $(CFLAGS) -c lexer.cpp

svasm.o: lexer.h svasm.cpp
	$(CXX) $(CFLAGS) -c svasm.cpp

clean:
	rm -f *.o *.bin svasm
