cmake_minimum_required(VERSION 4.0)

# Название библиотеки
project(CoopFun)
set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/MainProgram/MainProgram/CoopFun/include)
#add_subdirectory(src)

add_library(CoopFun STATIC
#        include/header_coop_fun.h
        src/combinatorics.cpp
        src/CreateVar.cpp
        src/fibonacci.cpp
        src/forStatement.cpp
        src/nok&nod.cpp
        src/Point.cpp
        src/Random.cpp
        src/RusText.cpp
        src/split.cpp
        src/stringOperation.cpp
        src/swap.cpp
        src/vectorOperation.cpp
)
target_include_directories(CoopFun INTERFACE "$<BUILD_INTERFACE:${MY_INCLUDE}>")
#target_include_directories(CoopFun INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>")

install(TARGETS CoopFun DESTINATION lib)
install(DIRECTORY "${MY_INCLUDE}" DESTINATION include/CoopFun)
#target_include_directories(CoopFun PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")