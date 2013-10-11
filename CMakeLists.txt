cmake_minimum_required(VERSION 2.8)

find_package(OpenCV REQUIRED)
find_package(Threads REQUIRED)

add_executable(EdgeDetector 
		main 
		core
		acs
        guicontroller
        guiview)
        
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_FLAGS_DEBUG 
    "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -std=c++11 -g -pg")
set(CMAKE_CXX_FLAGS_RELEASE 
    "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra -std=c++11")

target_link_libraries(EdgeDetector ${OpenCV_LIBS})
target_link_libraries(EdgeDetector ${QT_LIBRARIES})
target_link_libraries(EdgeDetector ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(EdgeDetector rt)
