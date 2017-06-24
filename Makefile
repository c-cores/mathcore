CXXFLAGS	 =  -g -O2 -Wall -fmessage-length=0 -I. -I../stdcore
# -g -fprofile-arcs -ftest-coverage
SOURCES		 := $(wildcard math/*.cpp)
TESTS        := $(wildcard test/*.cpp)
OBJECTS		 := $(SOURCES:%.cpp=%.o)
TEST_OBJECTS := $(TESTS:.cpp=.o)
DEPS         := $(OBJECTS:.o=.d)
TEST_DEPS    := $(TEST_OBJECTS:.o=.d)
GTEST_I      := -I$(GOOGLE_TEST_PATH)/include -I. -I../stdcore
GTEST_L      := -L$(GOOGLE_TEST_PATH)/make -L. -L../stdcore
TARGET		 = libmathcore.a
TEST_TARGET  = test_mathcore

-include $(DEPS)
-include $(TEST_DEPS)

all: lib

lib: $(TARGET)

test: lib $(TEST_TARGET)

check: test
	./$(TEST_TARGET)

$(TARGET): $(OBJECTS)
	ar rvs $(TARGET) $(OBJECTS)

math/%.o: math/%.cpp 
	$(CXX) $(CXXFLAGS) -MM -MF $(patsubst %.o,%.d,$@) -MT $@ -c $<
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(TEST_TARGET): $(TEST_OBJECTS) $(GOOGLE_TEST_PATH)/make/gtest_main.o
	$(CXX) $(CXXFLAGS) $(GTEST_L) $^ -pthread -lmathcore -lstdcore -l:gtest.a -o $(TEST_TARGET)

test/%.o: test/%.cpp
	$(CXX) $(CXXFLAGS) $(GTEST_I) -MM -MF $(patsubst %.o,%.d,$@) -MT $@ -c $<
	$(CXX) $(CXXFLAGS) $(GTEST_I) $< -c -o $@
	
clean:
	rm -f math/*.o test/*.o
	rm -f math/*.d test/*.d
	rm -f math/*.gcda test/*.gcda
	rm -f math/*.gcno test/*.gcno
	rm -f $(TARGET) $(TEST_TARGET)
