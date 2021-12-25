SRCDIR=src
OBJDIR=build
CC=g++
CPPFLAGS=-Wall

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<	

hairdressers_main: $(SRCDIR)/HairdressersMain.o $(SRCDIR)/HairStudio.o 
	g++ -o hairdressers_main $(SRCDIR)/HairdressersMain.o $(SRCDIR)/HairStudio.o
	mkdir -p $(OBJDIR)
	mv hairdressers_main $(OBJDIR)
    
tests: hairdressers_main test01.txt test02.txt test03.txt test04.txt test05.txt
	$(OBJDIR)/hairdressers_main < test01.txt > test01.out.txt || true
	$(OBJDIR)/hairdressers_main < test02.txt > test02.out.txt || true
	$(OBJDIR)/hairdressers_main < test03.txt > test03.out.txt || true
	$(OBJDIR)/hairdressers_main < test04.txt > test04.out.txt || true
	$(OBJDIR)/hairdressers_main < test05.txt > test05.out.txt || true
	
compare: tests
	diff -i -w -B test01.out.txt expected01.txt || true
	diff -i -w -B test02.out.txt expected02.txt || true
	diff -i -w -B test03.out.txt expected03.txt || true
	diff -i -w -B test04.out.txt expected04.txt || true
	diff -i -w -B test05.out.txt expected05.txt || true


all: hairdressers_main
	
clean:
	rm -f $(OBJDIR)/hairdressers_main
	rm -f $(SRCDIR)/*.o
	rm -f *.out.txt

