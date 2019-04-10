INC = inc/KMP.h inc/Justify.h
SRC = src/KMP.cpp src/justify.cpp
MAIN = src/main.cpp

compile:
	g++ $(INC) $(SRC) $(MAIN) -std=c++11

