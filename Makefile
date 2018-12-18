HEADERS = list_class.h
 
default: bracket_sequencer
 
list_class.o: list_class.cpp $(HEADERS)
	g++ -std=gnu++98 -pedantic -c list_class.cpp -o list_class.o

main.o: Main.cpp $(HEADERS)
	g++ -std=gnu++98 -pedantic -c Main.cpp -o main.o
 
bracket_sequencer: list_class.o main.o 
	g++ -std=gnu++98 -pedantic main.o list_class.o -o bracket_sequencer
 
run: bracket_sequencer
	./bracket_sequencer ./correct.txt
	./bracket_sequencer ./wrong.txt
clean:
	-rm -f *.o bracket_sequencer
