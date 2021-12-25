cmake_minimum_required(VERSION 3.12)
project(Hello LANGUAGES CXX)

# Add local project module path so CMake includes custom CMake modules.
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules")

include(CTest)
enable_testing()

add_library(hairstudio
  src/HairStudio.h
  src/HairStudio.cpp
)
target_include_directories(hairstudio
	PUBLIC
		src
)
target_compile_options(hairstudio
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra>
		$<$<CXX_COMPILER_ID:MSVC>:
			/W4>
)


#
# Create executable that uses the hairstudio lib to process customers from the standard input.
#
add_executable(hairdressers_main
  src/HairdressersMain.cpp
)
target_link_libraries(hairdressers_main
	PRIVATE
		hairstudio
)
target_compile_options(hairdressers_main
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
add_executable(hairdressers_test
	test/main.cpp
  test/TestHairStudio.cpp
)
target_include_directories(hairdressers_test
	PUBLIC
		test/
)
target_link_libraries(hairdressers_test
	Catch
	hairstudio
)
target_compile_options(hairdressers_test
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra>
		$<$<CXX_COMPILER_ID:MSVC>:
			/W4>
)

# Load and use the .cmake file provided by Catch so all the test cases
# are made available to CTest.
include(ParseAndAddCatchTests)
ParseAndAddCatchTests(hairdressers_test)

install(
	TARGETS hairdressers_test
	RUNTIME DESTINATION bin
)

