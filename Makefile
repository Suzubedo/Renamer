GXX=g++
CXXFLAGS= -std=c++11 -pedantic -Werror -Wall
SRC=src/renamer.cc src/main.cc
OBJ=${SRC:.cc=.o}
OUT=renamer

all: $(OBJ)
	$(GXX) -o $(OUT) $(CXXFLAGS) $(SRC) 

check: 
	$(GXX) -o $(OUT) $(CXXFLAGS) $(SRC) 
	./$(OUT) tests/test_dir mp4 srt

clean: 
	rm $(OBJ) $(OUT)	
