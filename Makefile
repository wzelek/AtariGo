TARGET := AtariGo

CXX := clang++
CXXFLAGS := -march=native -Os -fdata-sections -ffunction-sections -fno-exceptions -fno-rtti -std=c++17 -Wall -Wextra -pedantic

dir_guard=@mkdir -p $(@D)

BINDIR := bin
INCDIR := inc
SRCDIR := src
BUILDDIR := build

INCDIRS := -I$(INCDIR)

SRCFILES := $(wildcard $(SRCDIR)/*.cpp) 
OBJFILES := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCFILES)) 
DEPFILES := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.d,$(SRCFILES)) 

# $^ - evaluates to the list of dependencies
# $@ - name of the product
$(BINDIR)/$(TARGET): $(OBJFILES)
	$(dir_guard)
	$(CXX) $(CXXFLAGS) $^ -o $@ 

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(dir_guard)
	$(CXX) $(CXXFLAGS) $(INCDIRS) -c $< -o $@

$(BUILDDIR)/%.d: $(SRCDIR)/%.cpp
	$(dir_guard)
	$(CXX) $(INCDIRS) -MM $< > $@

clean:
	$(RM) -r $(BINDIR) $(BUILDDIR)

-include $(DEPFILES)
