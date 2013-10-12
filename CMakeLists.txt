cmake_minimum_required(VERSION 2.8)

find_package(OpenCV REQUIRED)
find_package(Threads REQUIRED)

add_executable(EdgeDetector 
		main 
		core
		acs
		ant
		memory
		random
        guicontroller
        guiview)
        
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -std=c++11 -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O3 -march=native -std=c++11")

target_link_libraries(EdgeDetector ${OpenCV_LIBS})
target_link_libraries(EdgeDetector ${CMAKE_THREAD_LIBS_INIT})
