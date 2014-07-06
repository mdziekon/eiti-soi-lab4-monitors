CXX=g++
CXXFLAGS=-c -std=c++11 -Wall -pthread -Wl,--no-as-needed
LDFLAGS=-pthread -Wl,--no-as-needed
LDLIBS=

SOURCEDIR=src
BUILDDIR=build

SOURCES=sync.cpp main.cpp
EXECUTABLE=run

REAL_SOURCES=$(addprefix $(SOURCEDIR)/, $(SOURCES))
OBJECTS=$(addprefix $(BUILDDIR)/$(SOURCEDIR)/, $(SOURCES:.cpp=.o))
REAL_EXECUTABLE=$(addprefix $(BUILDDIR)/, $(EXECUTABLE))

all: $(REAL_SOURCES) $(REAL_EXECUTABLE)

$(REAL_EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(LDLIBS) $(OBJECTS) -o $@

$(BUILDDIR)/$(SOURCEDIR)/%.o: $(SOURCEDIR)/%.cpp
	-$(foreach d,$(subst /, ,${@D}),mkdir $d; cd $d; ):
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -rf $(BUILDDIR)
