
BINDIR=./bin
OBJDIR=./obj
SRCDIR=./src
COMPILE_FLAGS=-std=c++11 -Wall -Werror
LINK_FLAGS=-lgtest -lpthread

all: dirs pizza

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/%.hpp
	g++ $(COMPILE_FLAGS) -c $< -o $@

pizza: $(OBJDIR)/unittest.o $(OBJDIR)/Sups.o $(OBJDIR)/SupBuilders.o $(OBJDIR)/SupDirectors.o
	g++ $? $(LINK_FLAGS) -o $(BINDIR)/$@

dirs:
	@if [ ! -d $(BINDIR) ]; then mkdir $(BINDIR); fi
	@if [ ! -d $(OBJDIR) ]; then mkdir $(OBJDIR); fi
