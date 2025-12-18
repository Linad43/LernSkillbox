cmake_minimum_required(VERSION 3.17)
project("modul25" VERSION 1.0)

set(CMAKE_CXX_STANDART 14)

add_executable(modul25 src/modul25.cpp include/header_modul25.h src/Ex/mod25ex1.cpp src/Ex/mod25ex2.cpp src/Ex/structPoint.cpp src/Ex/cpu.cpp src/Ex/disk.cpp src/Ex/gpu.cpp src/Ex/kbd.cpp src/Ex/ram.cpp include/header_cpu.h include/header_disk.h include/header_gpu.h include/header_kbd.h include/header_ram.h)
target_include_directores(modul25 PUBLIC include)
