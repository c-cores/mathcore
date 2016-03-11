CXXFLAGS	:= -O2 -g -Wall -fmessage-length=0
INCLUDES	:= -I../stdcore
SOURCES		:= $(shell find mathcore -name '*.cpp')
OBJECTS		:= $(SOURCES:%.cpp=%.o)
TARGET		:= libmathcore.a

all: $(TARGET)

$(TARGET): $(OBJECTS)
	ar rvs $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c -o $@ $<
	
clean:
	rm -f $(OBJECTS) $(TARGET)
