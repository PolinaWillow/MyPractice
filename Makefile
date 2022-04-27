MYPROG = main.cpp binarySearch.cpp

test: $(MYPROG)
	g++ $(MYPROG) -o program