cmake_minimum_required(VERSION 3.12)
project(Hello LANGUAGES CXX)

# Add local project module path so CMake includes custom CMake modules.
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules")

include(CTest)
enable_testing()

# lib - alienTreeList
add_library(alienTreeList
  src/AlienTreeList.h
  src/AlienTreeList.cpp
)
target_include_directories(alienTreeList
	PUBLIC
		src
)
target_compile_options(alienTreeList
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra>
		$<$<CXX_COMPILER_ID:MSVC>:
			/W4>
)

# lib - debug
# add_library(libdebug
#   src/Debug.h
#   src/Debug.cpp
# )
# target_include_directories(libdebug
# 	PUBLIC
# 		src
# )
# target_compile_options(libdebug
# 	PRIVATE
# 		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
# 			-Werror -Wall -Wextra>
# 		$<$<CXX_COMPILER_ID:MSVC>:
# 			/W4>
# )

#
# Create executable that uses the hairstudio lib to process customers from the standard input.
#
add_executable(aliens_main
  src/AliensMain.cpp
)
target_link_libraries(aliens_main
	PRIVATE
		alienTreeList
		# libdebug
)
target_compile_options(aliens_main
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
add_executable(aliens_test
	test/main.cpp
  test/TestAliens.cpp
)
target_include_directories(aliens_test
	PUBLIC
		test/
)
target_link_libraries(aliens_test
	Catch
	alienTreeList
)
target_compile_options(aliens_test
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra>
		$<$<CXX_COMPILER_ID:MSVC>:
			/W4>
)

# Load and use the .cmake file provided by Catch so all the test cases
# are made available to CTest.
include(ParseAndAddCatchTests)
ParseAndAddCatchTests(aliens_test)

install(
	TARGETS aliens_test
	RUNTIME DESTINATION bin
)

