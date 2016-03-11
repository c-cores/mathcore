CXXFLAGS	=  -O2 -g -Wall -fmessage-length=0
SOURCES		:=  $(shell find mathcore -name '*.cpp')
OBJECTS		:=  $(SOURCES:%.cpp=%.o)
INC_PATHS	= ../stdcore/stdcore
LDFLAGS		=  
TARGET		=  libmathcore.a

all: $(TARGET)

$(TARGET): $(OBJECTS)
	ar rvs $(TARGET) $(OBJECTS)

%.o: mathcore/%.cpp 
	$(CXX) ${INC_PATHS} $(CXXFLAGS) $(LDFLAGS) -c -o $@ $<
	
clean:
	rm -f $(OBJECTS) $(TARGET)
