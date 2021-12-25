SRCDIR=src
OBJDIR=build
CC=g++
CPPFLAGS=-Wall

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<	

circlist_main: $(SRCDIR)/CircularListMain.o
	g++ -o circlist_main $(SRCDIR)/CircularListMain.o
	mkdir -p $(OBJDIR)
	mv circlist_main $(OBJDIR)
    
tests: circlist_main test01.txt test02.txt test03.txt test04.txt test05.txt
	$(OBJDIR)/circlist_main < test01.txt > test01.out.txt || true
	$(OBJDIR)/circlist_main < test02.txt > test02.out.txt || true
	$(OBJDIR)/circlist_main < test03.txt > test03.out.txt || true
	$(OBJDIR)/circlist_main < test04.txt > test04.out.txt || true
	$(OBJDIR)/circlist_main < test05.txt > test05.out.txt || true
	
compare: tests
	diff -i -w -B test01.out.txt expected01.txt || true
	diff -i -w -B test02.out.txt expected02.txt || true
	diff -i -w -B test03.out.txt expected03.txt || true
	diff -i -w -B test04.out.txt expected04.txt || true
	diff -i -w -B test05.out.txt expected05.txt || true


all: circlist_main
	
clean:
	rm -f $(OBJDIR)/circlist_main
	rm -f $(SRCDIR)/*.o
	rm -f *.out.txt

