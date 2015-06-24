all:
	g++ rebus.cpp -std=c++11 -O2 -o rebus

clean:
	rm -rf *.o rebus