cmake_minimum_required(VERSION 3.20)

set(NAME_PROJECT LernSkillbox)

project(${NAME_PROJECT})

set(CMAKE_CXX_STANDARD 17)


#find_package(fmt CONFIG REQUIRED)

set(DEFAULT_BUILD_TYPE "Release")
if (EXISTS "${CMAKE_SOURCE_DIR}/.git")
    set(DEFAULT_BUILD_TYPE "Debug")
endif ()
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif ()

#add_subdirectory(MainProgram/MainProgram/CoopFun)
#add_subdirectory(MainProgram/MainProgram)

include_directories(MainProgram/MainProgram)
include_directories(MainProgram/MainProgram/CoopFun/include)
#target_include_directories(LernSkillbox PUBLIC "MainProgram/MainProgram/CoopFun/include")
#include_directories(MainProgram/MainProgram/CoopFun)
include_directories(MainProgram/MainProgram/Modul10)
include_directories(MainProgram/MainProgram/Modul11)
include_directories(MainProgram/MainProgram/Modul12)
include_directories(MainProgram/MainProgram/Modul13)
include_directories(MainProgram/MainProgram/Modul14)
include_directories(MainProgram/MainProgram/Modul15)
include_directories(MainProgram/MainProgram/Modul16)
include_directories(MainProgram/MainProgram/Modul17)
include_directories(MainProgram/MainProgram/Modul18)
include_directories(MainProgram/MainProgram/Modul19)
include_directories(MainProgram/MainProgram/Modul2)
include_directories(MainProgram/MainProgram/Modul20)
include_directories(MainProgram/MainProgram/Modul21)
include_directories(MainProgram/MainProgram/Modul22)
include_directories(MainProgram/MainProgram/Modul23)
include_directories(MainProgram/MainProgram/Modul24)
include_directories(MainProgram/MainProgram/Modul26)
include_directories(MainProgram/MainProgram/Modul27)
include_directories(MainProgram/MainProgram/Modul28)
include_directories(MainProgram/MainProgram/Modul3)
include_directories(MainProgram/MainProgram/Modul4)
include_directories(MainProgram/MainProgram/Modul5)
include_directories(MainProgram/MainProgram/Modul6)
include_directories(MainProgram/MainProgram/Modul7)
include_directories(MainProgram/MainProgram/Modul8)
include_directories(MainProgram/MainProgram/Modul9)

add_executable(${NAME_PROJECT}
        MainProgram/MainProgram/CoopFun/src/combinatorics.cpp
        MainProgram/MainProgram/CoopFun/src/CreateVar.cpp
        MainProgram/MainProgram/CoopFun/src/fibonacci.cpp
        MainProgram/MainProgram/CoopFun/src/forStatement.cpp
        MainProgram/MainProgram/CoopFun/include/header_coop_fun.h
        MainProgram/MainProgram/CoopFun/src/nok&nod.cpp
        MainProgram/MainProgram/CoopFun/src/Point.cpp
        MainProgram/MainProgram/CoopFun/src/Random.cpp
        MainProgram/MainProgram/CoopFun/src/RusText.cpp
        MainProgram/MainProgram/CoopFun/src/split.cpp
        MainProgram/MainProgram/CoopFun/src/stringOperation.cpp
        MainProgram/MainProgram/CoopFun/src/swap.cpp
        MainProgram/MainProgram/CoopFun/src/vectorOperation.cpp
        MainProgram/MainProgram/Modul10/header_modul10.h
        MainProgram/MainProgram/Modul10/modul10.cpp
        MainProgram/MainProgram/Modul11/Ex/mod11ex1.cpp
        MainProgram/MainProgram/Modul11/Ex/mod11ex2.cpp
        MainProgram/MainProgram/Modul11/Ex/mod11ex3.cpp
        MainProgram/MainProgram/Modul11/header_modul11.h
        MainProgram/MainProgram/Modul11/modul11.cpp
        MainProgram/MainProgram/Modul12/Ex/mod12ex1.cpp
        MainProgram/MainProgram/Modul12/Ex/mod12ex2.cpp
        MainProgram/MainProgram/Modul12/Ex/mod12ex3.cpp
        MainProgram/MainProgram/Modul12/Ex/mod12ex4.cpp
        MainProgram/MainProgram/Modul12/header_modul12.h
        MainProgram/MainProgram/Modul12/modul12.cpp
        MainProgram/MainProgram/Modul13/Ex/mod13ex1.cpp
        MainProgram/MainProgram/Modul13/Ex/mod13ex2.cpp
        MainProgram/MainProgram/Modul13/Ex/mod13ex3.cpp
        MainProgram/MainProgram/Modul13/header_modul13.h
        MainProgram/MainProgram/Modul13/modul13.cpp
        MainProgram/MainProgram/Modul14/Ex/mod14ex1.cpp
        MainProgram/MainProgram/Modul14/Ex/mod14ex2.cpp
        MainProgram/MainProgram/Modul14/Ex/mod14ex3.cpp
        MainProgram/MainProgram/Modul14/Ex/mod14ex4.cpp
        MainProgram/MainProgram/Modul14/Ex/mod14ex5.cpp
        MainProgram/MainProgram/Modul14/Ex/mod14ex6.cpp
        MainProgram/MainProgram/Modul14/Ex/mod14ex7.cpp
        MainProgram/MainProgram/Modul14/Ex/mod14ex8.cpp
        MainProgram/MainProgram/Modul14/header_modul14.h
        MainProgram/MainProgram/Modul14/modul14.cpp
        MainProgram/MainProgram/Modul15/Ex/mod15ex1.cpp
        MainProgram/MainProgram/Modul15/Ex/mod15ex2.cpp
        MainProgram/MainProgram/Modul15/Ex/mod15ex3.cpp
        MainProgram/MainProgram/Modul15/Ex/mod15ex4.cpp
        MainProgram/MainProgram/Modul15/header_modul15.h
        MainProgram/MainProgram/Modul15/modul15.cpp
        MainProgram/MainProgram/Modul16/Ex/mod16ex1.cpp
        MainProgram/MainProgram/Modul16/Ex/mod16ex2.cpp
        MainProgram/MainProgram/Modul16/Ex/mod16ex3.cpp
        MainProgram/MainProgram/Modul16/Ex/mod16ex4.cpp
        MainProgram/MainProgram/Modul16/Ex/mod16ex5.cpp
        MainProgram/MainProgram/Modul16/header_modul16.h
        MainProgram/MainProgram/Modul16/modul16.cpp
        MainProgram/MainProgram/Modul17/Ex/mod17ex1.cpp
        MainProgram/MainProgram/Modul17/Ex/mod17ex2.cpp
        MainProgram/MainProgram/Modul17/Ex/mod17ex3.cpp
        MainProgram/MainProgram/Modul17/header_modul17.h
        MainProgram/MainProgram/Modul17/modul17.cpp
        MainProgram/MainProgram/Modul18/Ex/mod18ex1.cpp
        MainProgram/MainProgram/Modul18/Ex/mod18ex2.cpp
        MainProgram/MainProgram/Modul18/Ex/mod18ex3.cpp
        MainProgram/MainProgram/Modul18/header_modul18.h
        MainProgram/MainProgram/Modul18/modul18.cpp
        MainProgram/MainProgram/Modul19/Ex/mod19ex1.cpp
        MainProgram/MainProgram/Modul19/Ex/mod19ex2.cpp
        MainProgram/MainProgram/Modul19/Ex/mod19ex3.cpp
        MainProgram/MainProgram/Modul19/Ex/mod19ex4.cpp
        MainProgram/MainProgram/Modul19/Ex/mod19ex5.cpp
        MainProgram/MainProgram/Modul19/header_modul19.h
        MainProgram/MainProgram/Modul19/modul19.cpp
        MainProgram/MainProgram/Modul2/Ex/mod2ex1.cpp
        MainProgram/MainProgram/Modul2/Ex/mod2ex2.cpp
        MainProgram/MainProgram/Modul2/Ex/mod2ex3.cpp
        MainProgram/MainProgram/Modul2/Ex/mod2ex4.cpp
        MainProgram/MainProgram/Modul2/header_modul2.h
        MainProgram/MainProgram/Modul2/Modul2.cpp
        MainProgram/MainProgram/Modul20/Ex/mod20ex1.cpp
        MainProgram/MainProgram/Modul20/Ex/mod20ex2.cpp
        MainProgram/MainProgram/Modul20/Ex/mod20ex3.cpp
        MainProgram/MainProgram/Modul20/Ex/mod20ex4.cpp
        MainProgram/MainProgram/Modul20/header_modul20.h
        MainProgram/MainProgram/Modul20/modul20.cpp
        MainProgram/MainProgram/Modul21/Ex/mod21ex1.cpp
        MainProgram/MainProgram/Modul21/Ex/mod21ex2.cpp
        MainProgram/MainProgram/Modul21/Ex/mod21ex3.cpp
        MainProgram/MainProgram/Modul21/Ex/mod21ex4.cpp
        MainProgram/MainProgram/Modul21/header_modul21.h
        MainProgram/MainProgram/Modul21/modul21.cpp
        MainProgram/MainProgram/Modul22/Ex/mod22ex1.cpp
        MainProgram/MainProgram/Modul22/Ex/mod22ex2.cpp
        MainProgram/MainProgram/Modul22/Ex/mod22ex3.cpp
        MainProgram/MainProgram/Modul22/header_modul22.h
        MainProgram/MainProgram/Modul22/modul22.cpp
        MainProgram/MainProgram/Modul23/Ex/mod23ex1.cpp
        MainProgram/MainProgram/Modul23/Ex/mod23ex2.cpp
        MainProgram/MainProgram/Modul23/Ex/mod23ex3.cpp
        MainProgram/MainProgram/Modul23/header_modul23.h
        MainProgram/MainProgram/Modul23/modul23.cpp
        MainProgram/MainProgram/Modul24/Ex/mod24ex1.cpp
        MainProgram/MainProgram/Modul24/Ex/mod24ex2.cpp
        MainProgram/MainProgram/Modul24/Ex/mod24ex3.cpp
        MainProgram/MainProgram/Modul24/header_modul24.h
        MainProgram/MainProgram/Modul24/modul24.cpp
        MainProgram/MainProgram/Modul26/Ex/mod26ex1.cpp
        MainProgram/MainProgram/Modul26/Ex/mod26ex2.cpp
        MainProgram/MainProgram/Modul26/Ex/mod26ex3.cpp
        MainProgram/MainProgram/Modul26/header_modul26.h
        MainProgram/MainProgram/Modul26/modul26.cpp
        MainProgram/MainProgram/Modul27/Ex/mod27ex1.cpp
        MainProgram/MainProgram/Modul27/Ex/mod27ex2.cpp
        MainProgram/MainProgram/Modul27/Ex/mod27ex3.cpp
        MainProgram/MainProgram/Modul27/header_modul27.h
        MainProgram/MainProgram/Modul27/modul27.cpp
        MainProgram/MainProgram/Modul28/Ex/mod28ex1.cpp
        MainProgram/MainProgram/Modul28/Ex/mod28ex2.cpp
        MainProgram/MainProgram/Modul28/Ex/mod28ex3.cpp
        MainProgram/MainProgram/Modul28/header_modul28.h
        MainProgram/MainProgram/Modul28/modul28.cpp
        MainProgram/MainProgram/Modul3/Ex/mod3ex1.cpp
        MainProgram/MainProgram/Modul3/Ex/mod3ex2.cpp
        MainProgram/MainProgram/Modul3/Ex/mod3ex3.cpp
        MainProgram/MainProgram/Modul3/Ex/mod3ex4.cpp
        MainProgram/MainProgram/Modul3/header_modul3.h
        MainProgram/MainProgram/Modul3/Modul3.cpp
        MainProgram/MainProgram/Modul4/Ex/mod4ex1.cpp
        MainProgram/MainProgram/Modul4/Ex/mod4ex2.cpp
        MainProgram/MainProgram/Modul4/Ex/mod4ex3.cpp
        MainProgram/MainProgram/Modul4/Ex/mod4ex4.cpp
        MainProgram/MainProgram/Modul4/Ex/mod4ex5.cpp
        MainProgram/MainProgram/Modul4/Ex/mod4ex6.cpp
        MainProgram/MainProgram/Modul4/Ex/mod4ex7.cpp
        MainProgram/MainProgram/Modul4/Ex/mod4ex8.cpp
        MainProgram/MainProgram/Modul4/Ex/mod4ex9.cpp
        MainProgram/MainProgram/Modul4/header_modul4.h
        MainProgram/MainProgram/Modul4/Modul4.cpp
        MainProgram/MainProgram/Modul5/Ex/mod5ex1.cpp
        MainProgram/MainProgram/Modul5/Ex/mod5ex2.cpp
        MainProgram/MainProgram/Modul5/Ex/mod5ex3.cpp
        MainProgram/MainProgram/Modul5/Ex/mod5ex4.cpp
        MainProgram/MainProgram/Modul5/Ex/mod5ex5.cpp
        MainProgram/MainProgram/Modul5/Ex/mod5ex6.cpp
        MainProgram/MainProgram/Modul5/header_modul5.h
        MainProgram/MainProgram/Modul5/Modul5.cpp
        MainProgram/MainProgram/Modul6/Ex/mod6ex1.cpp
        MainProgram/MainProgram/Modul6/Ex/mod6ex2.cpp
        MainProgram/MainProgram/Modul6/Ex/mod6ex3.cpp
        MainProgram/MainProgram/Modul6/Ex/mod6ex4.cpp
        MainProgram/MainProgram/Modul6/Ex/mod6ex5.cpp
        MainProgram/MainProgram/Modul6/Ex/mod6ex6.cpp
        MainProgram/MainProgram/Modul6/Ex/mod6ex7.cpp
        MainProgram/MainProgram/Modul6/Ex/mod6ex8.cpp
        MainProgram/MainProgram/Modul6/Ex/mod6ex9.cpp
        MainProgram/MainProgram/Modul6/header_modul6.h
        MainProgram/MainProgram/Modul6/modul6.cpp
        MainProgram/MainProgram/Modul7/Ex/mod7ex1.cpp
        MainProgram/MainProgram/Modul7/Ex/mod7ex2.cpp
        MainProgram/MainProgram/Modul7/Ex/mod7ex3.cpp
        MainProgram/MainProgram/Modul7/Ex/mod7ex4.cpp
        MainProgram/MainProgram/Modul7/Ex/mod7ex5.cpp
        MainProgram/MainProgram/Modul7/Ex/mod7ex6.cpp
        MainProgram/MainProgram/Modul7/Ex/mod7ex7.cpp
        MainProgram/MainProgram/Modul7/Ex/mod7ex8.cpp
        MainProgram/MainProgram/Modul7/header_modul7.h
        MainProgram/MainProgram/Modul7/modul7.cpp
        MainProgram/MainProgram/Modul8/Ex/mod8ex1.cpp
        MainProgram/MainProgram/Modul8/Ex/mod8ex2.cpp
        MainProgram/MainProgram/Modul8/Ex/mod8ex3.cpp
        MainProgram/MainProgram/Modul8/Ex/mod8ex4.cpp
        MainProgram/MainProgram/Modul8/Ex/mod8ex5.cpp
        MainProgram/MainProgram/Modul8/Ex/mod8ex6.cpp
        MainProgram/MainProgram/Modul8/header_modul8.h
        MainProgram/MainProgram/Modul8/modul8.cpp
        MainProgram/MainProgram/Modul9/Ex/mod9ex1.cpp
        MainProgram/MainProgram/Modul9/Ex/mod9ex2.cpp
        MainProgram/MainProgram/Modul9/Ex/mod9ex3.cpp
        MainProgram/MainProgram/Modul9/Ex/mod9ex4.cpp
        MainProgram/MainProgram/Modul9/Ex/mod9ex5.cpp
        MainProgram/MainProgram/Modul9/header_modul9.h
        MainProgram/MainProgram/Modul9/modul9.cpp
        MainProgram/MainProgram/header_main.h
        MainProgram/MainProgram/Main.cpp
        MainProgram/MainProgram/Modul29/header_modul29.h
        MainProgram/MainProgram/Modul29/modul29.cpp
        MainProgram/MainProgram/Modul29/Ex/mod29ex1.cpp
        MainProgram/MainProgram/Modul29/Ex/mod29ex2.cpp
        MainProgram/MainProgram/Modul30/Ex/mod30ex3.cpp
        MainProgram/MainProgram/Modul30/Ex/mod30ex2.cpp
        MainProgram/MainProgram/Modul30/Ex/mod30ex1.cpp
        MainProgram/MainProgram/Modul30/header_modul30.h
        MainProgram/MainProgram/Modul30/modul30.cpp
)

if (WIN32) # Install dlls in the same directory as the executable on Windows
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif ()

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 1.11.0) # The commit hash for 1.11.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

#target_link_libraries(${NAME_PROJECT} PRIVATE fmt::fmt)
target_link_libraries(${NAME_PROJECT} PRIVATE cpr::cpr)