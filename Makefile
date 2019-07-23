
ASSIGNED_MODULE_NAME = exhaustive_subsequence

ASSIGNED_HEADER_FILE = ${ASSIGNED_MODULE_NAME}.hpp
ASSIGNED_SOURCE_FILE = ${ASSIGNED_MODULE_NAME}.cpp

RUBRIC_FILE = rubric.json
TEST_XML_FILE = test.xml
UNIT_TEST_SOURCE_FILE = unittest.cpp
UNIT_TEST_EXECUTABLE = unittest
EXPERIMENT_SOURCE_FILE = experiment.cpp
EXPERIMENT_EXECUTABLE = experiment

CLANG_FLAGS = -std=c++17 -Wall -O -g
GTEST_FLAGS = -lpthread -lgtest_main -lgtest

default_target: print_score

print_score: rubricscore ${RUBRIC_FILE} ${TEST_XML_FILE}
	./rubricscore ${RUBRIC_FILE} ${TEST_XML_FILE}

runexperiment: ${EXPERIMENT_EXECUTABLE}
	./${EXPERIMENT_EXECUTABLE}

rubricscore: rubricscore.cpp
		clang++ ${CLANG_FLAGS} rubricscore.cpp -o rubricscore

${TEST_XML_FILE}: ${UNIT_TEST_EXECUTABLE}
	# delete stale test results, otherwise they could be printed if unit
	# tests crash
	rm -f ${TEST_XML_FILE}
	# || true allows make to continue the build even if some tests fail
	./${UNIT_TEST_EXECUTABLE} --gtest_output=xml:./${TEST_XML_FILE} || true

${UNIT_TEST_EXECUTABLE}: gtest_lib ${ASSIGNED_HEADER_FILE} ${UNIT_TEST_SOURCE_FILE}
	clang++ ${CLANG_FLAGS} ${GTEST_FLAGS} ${UNIT_TEST_SOURCE_FILE} -o ${UNIT_TEST_EXECUTABLE}

${EXPERIMENT_EXECUTABLE}: timer.hpp ${ASSIGNED_HEADER_FILE} ${EXPERIMENT_SOURCE_FILE}
	clang++ ${CLANG_FLAGS} ${EXPERIMENT_SOURCE_FILE} -o ${EXPERIMENT_EXECUTABLE}

gtest_lib: /usr/lib/libgtest.a

/usr/lib/libgtest.a:
	@echo -e "google test library not installed\n"
	@echo -e "Installing libgtest-dev. Please provide the password when asked\n"
	@sudo apt-get -y install libgtest-dev cmake
	@sudo apt-get install cmake # install cmake
	@echo -e "\nConfiguring libgtest-dev\n"
	@cd /usr/src/gtest; sudo cmake CMakeLists.txt; sudo make; sudo cp *.a /usr/lib
	@echo -e "Finished installing google test library\n"

clean:
		rm -f rubricscore ${UNIT_TEST_EXECUTABLE} ${TEST_XML_FILE} ${EXPERIMENT_EXECUTABLE}
