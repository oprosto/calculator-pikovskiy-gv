GTEST_DIR ?= googletest/googletest
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h $(GTEST_DIR)/include/gtest/internal/*.h
VENV_DIR = myenv
PYTEST = $(VENV_DIR)/bin/pytest

$(shell mkdir -p build/gtest)

all: build/app.exe build/unit-tests.exe

clean:
	@rm -rf build
	@rm -rf $(VENV_DIR)

# Run the normal C application
run-int: build/app.exe
	@build/app.exe

# Run the normal C application with floating point numbers
run-float: build/app.exe
	@build/app.exe --float

# Run all tests
run-unit-test: build/unit-tests.exe
	@build/unit-tests.exe

build/app.exe:
	@gcc src/main.c -o build/app.exe

build/app-test.o:
	@gcc -DGTEST -c src/main.c -o build/app-test.o

build/unit-tests.exe: build/gtest/gtest_main.a build/app-test.o
	@g++ -isystem $(GTEST_DIR)/include -pthread \
		tests/unit/test.cpp \
		build/gtest/gtest_main.a build/app-test.o \
		-o build/unit-tests.exe
venv:
	@python3 -m venv $(VENV_DIR)
	@. $(VENV_DIR)/bin/activate && pip install pytest

run-integration-tests: build/app.exe venv tests/integration/test.py
	@. $(VENV_DIR)/bin/activate && $(PYTEST) tests/integration/test.py

format:
	@find . -name '*.c' -o -name '*.h' -o -name '*.cpp' -o -name '*.hpp' | xargs clang-format -i

####################################
# BUILD GOOGLE TEST STATIC LIBRARY #
####################################

# Google Test object files
build/gtest/gtest-all.o: $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)
	@g++ -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) -c $(GTEST_DIR)/src/gtest-all.cc -o $@

build/gtest/gtest_main.o: $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)
	@g++ -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) -c $(GTEST_DIR)/src/gtest_main.cc -o $@

# Google Test static libraries
build/gtest/gtest_main.a: build/gtest/gtest-all.o build/gtest/gtest_main.o
	@ar rv $@ $^ -o $@