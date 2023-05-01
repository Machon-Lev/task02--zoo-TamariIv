
cmake_minimum_required (VERSION 3.15)

project ("cpp_ex2")

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
	add_compile_options (/W4 /permissive- /Zc:externConstexpr /Zc:inline)
endif ()

# Add source to this project's executable.
add_executable(cpp_ex2)

# TODO: Add tests and install targets if needed.
add_subdirectory (include)
add_subdirectory (src)