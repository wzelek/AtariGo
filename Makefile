TARGET := AtariGo.exe

dir_guard=@mkdir -p $(@D)

BINDIR := bin
INCDIR := inc
SRCDIR := src
BUILDDIR := build
TESTDIR := test

INCDIRS := -I$(INCDIR)/

CXX := clang++
CXXFLAGS := $(INCDIRS) \
			-march=native -Os  \
			-fdata-sections -ffunction-sections  \
			-fno-exceptions -fno-rtti -std=c++17 \
			-Wall -Wextra -pedantic

# $^ - evaluates to the list of dependencies
# $@ - name of the product
# $< - represents the first prerequisite required to create the output file (usually the source file).
# 	$@ evaluates to all
# 	$< evaluates to library.cpp
#   $^ evaluates to library.cpp main.cpp

all: gtest bin

SRCFILES := $(wildcard $(SRCDIR)/*.cpp) 
OBJFILES := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCFILES)) 

bin: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJFILES)
	$(dir_guard)
	$(CXX) $^ -o $@ $(CXXFLAGS) 

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(dir_guard)
	$(CXX) $(CXXFLAGS) $(INCDIRS) -c $< -o $@

$(BUILDDIR)/%.d: $(SRCDIR)/%.cpp
	$(dir_guard)
	$(CXX) $(INCDIRS) -MM $< > $@

GTEST_SRCFILES := $(wildcard $(TESTDIR)/*.cc) 
GTEST_OBJFILES := $(patsubst $(TESTDIR)/%.cc,$(BUILDDIR)/%.o,$(GTEST_SRCFILES)) 

gtest: $(BINDIR)/.gtest

$(BINDIR)/.gtest: $(GTEST_OBJFILES) 
	$(dir_guard)
	$(CXX) $^ -o $@ $(CXXFLAGS) -lgtest -lpthread 

$(BUILDDIR)/%.o: $(TESTDIR)/%.cc
	$(dir_guard)
	$(CXX) $(CXXFLAGS) $(INCDIRS) -c $< -o $@ 

$(BUILDDIR)/%.d: $(TESTDIR)/%.cc
	$(dir_guard)
	$(CXX) $(INCDIRS) -MM $< > $@

clean:
	$(RM) -r $(BINDIR) $(BUILDDIR)
