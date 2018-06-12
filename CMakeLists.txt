cmake_minimum_required(VERSION 3.11)
project(SFRAT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)




include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)



set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/GO/GO.cxx
    
)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/models/GO/GO.h
)

add_executable(sfrat ${SOURCE} ${HEADERS})

if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang|GNU" )
    target_compile_options( sfrat PRIVATE -Wall -Wextra -Wunreachable-code -Wpedantic)
endif()
if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang" )
    target_compile_options( sfrat PRIVATE -Wweak-vtables -Wexit-time-destructors -Wglobal-constructors -Wmissing-noreturn )
endif()
if ( CMAKE_CXX_COMPILER_ID MATCHES "MSVC" )
    target_compile_options( sfrat PRIVATE /W4 /w44265 /w44061 /w44062 )
endif()
