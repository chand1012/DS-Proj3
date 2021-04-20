cmake_minimum_required(VERSION 3.10)

# project info
project(DS-Proj3)

set(CMAKE_CXX_STANDARD 17)

if (MSVC)
    add_compile_options(/W4)
    add_compile_options(/Ot)
else()
    add_compile_options(-Wall)
    add_compile_options(-O3)
endif()


add_executable(main main.cpp)

add_custom_target(run $<TARGET_FILE:main>)