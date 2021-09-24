CPPFLAGS = 
SRC_DIR := .
OBJ_DIR := .

all: sample1 sample2 sample3 sample4 sample5

sample1: sample1.o
	g++ -o sample1 sample1.o

sample2: sample2.o
	g++ -o sample2 sample2.o

sample3: sample3.o
	g++ -o sample3 sample3.o

sample4: sample4.o
	g++ -o sample4 sample4.o

sample5: sample5.o
	g++ -o sample5 sample5.o

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CPPFLAGS) -c -o $@ $<

clean:
	rm -f sample1 sample2 sample3 sample4 sample5
	rm -f *.o
	rm -f *.out.txt
	
