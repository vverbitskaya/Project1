cmake_minimum_required(VERSION 2.6)

if (CMAKE_VERSION VERSION_LESS "3.1")
	if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14")
	endif ()
else ()
	set (CMAKE_CXX_STANDARD 14)
endif ()

project(proj)

find_package(OpenCV REQUIRED)

add_executable(proj main.cpp ContentAnalyser.cpp ContentTxtAnalyser.cpp)
    
target_link_libraries(proj ${OpenCV_LIBS})

