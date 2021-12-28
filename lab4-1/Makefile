SRCDIR := src
OBJDIR := obj
BUILDDIR := build
SRC_FILES := $(wildcard $(SRCDIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRC_FILES))
CC := g++
CPPFLAGS := -Wall

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CC) $(CPPFLAGS) -c -o $@ $<	

aliens_main: $(OBJ_FILES)
	g++ -o $@ $^
	mkdir -p $(SRCDIR)
	mkdir -p $(BUILDDIR)
	mv aliens_main $(BUILDDIR)
    
tests: aliens_main test01.txt test02.txt test03.txt test04.txt test05.txt
	$(BUILDDIR)/aliens_main < test01.txt > test01.out.txt || true
	$(BUILDDIR)/aliens_main < test02.txt > test02.out.txt || true
	$(BUILDDIR)/aliens_main < test03.txt > test03.out.txt || true
	$(BUILDDIR)/aliens_main < test04.txt > test04.out.txt || true
	$(BUILDDIR)/aliens_main < test05.txt > test05.out.txt || true
	
compare: tests
	diff -i -w -B test01.out.txt expected01.txt || true
	diff -i -w -B test02.out.txt expected02.txt || true
	diff -i -w -B test03.out.txt expected03.txt || true
	diff -i -w -B test04.out.txt expected04.txt || true
	diff -i -w -B test05.out.txt expected05.txt || true


all: aliens_main
	
clean:
	rm -f $(BUILDDIR)/aliens_main
	rm -f $(OBJDIR)/*.o
	rm -f *.out.txt

