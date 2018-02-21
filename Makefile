
BINDIR=./bin
OBJDIR=./obj
COMPILE_FLAGS=-std=c++11 -Wall -Werror
LINK_FLAGS=-lgtest -lpthread

all: dirs pizza

%.o: %.cpp %.hpp
	g++ $(COMPILE_FLAGS) -c $< -o $@

pizza: $(OBJDIR)/unittest.o 
	g++ $? $(LINK_FLAGS) -o $(BINDIR)/$@

dirs:
	@if [ ! -d $(BINDIR) ]; then mkdir $(BINDIR); fi
	@if [ ! -d $(OBJDIR) ]; then mkdir $(OBJDIR); fi
