cmake_minimum_required(VERSION 3.12)
project(Hello LANGUAGES CXX)

# Add local project module path so CMake includes custom CMake modules.
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules")

include(CTest)
enable_testing()

# lib - stringMatcher
add_library(stringMatcher
  src/StringMatcher.h
  src/StringMatcher.cpp
)
target_include_directories(stringMatcher
	PUBLIC
		src
)
target_compile_options(stringMatcher
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra>
		$<$<CXX_COMPILER_ID:MSVC>:
			/W4>
)

# lib - rollingHash
add_library(rollingHash
  src/RollingHash.h
  src/RollingHash.cpp
)
target_include_directories(rollingHash
	PUBLIC
		src
)
target_compile_options(rollingHash
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra>
		$<$<CXX_COMPILER_ID:MSVC>:
			/W4>
)


#
# create main executable
#
add_executable(text_analysis_main
  src/TextAnalysisMain.cpp
)
target_link_libraries(text_analysis_main
	PRIVATE
		stringMatcher
		rollingHash
		# libdebug
)
target_compile_options(text_analysis_main
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra>
		$<$<CXX_COMPILER_ID:MSVC>:
			/W4>
)



#
# Create a library target for the Catch header-only test framework.
#
add_library(Catch INTERFACE)
target_include_directories(Catch
	INTERFACE
		test/
)

#
# Create a target for executing the Catch unit tests.
#
add_executable(string_matcher_test
	test/main.cpp
  test/TestStringMatcher.cpp
)
target_include_directories(string_matcher_test
	PUBLIC
		test/
)
target_link_libraries(string_matcher_test
	Catch
	stringMatcher
)
target_compile_options(string_matcher_test
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra>
		$<$<CXX_COMPILER_ID:MSVC>:
			/W4>
)

# Load and use the .cmake file provided by Catch so all the test cases
# are made available to CTest.
include(ParseAndAddCatchTests)
ParseAndAddCatchTests(string_matcher_test)

install(
	TARGETS string_matcher_test
	RUNTIME DESTINATION bin
)

