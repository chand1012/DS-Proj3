cmake_minimum_required(VERSION 3.10)

# project info
project(DS-Proj3)

set(CMAKE_CXX_STANDARD 14)

if (MSVC)
    add_compile_options(/W4)
    add_compile_options(/Ot)
else()
    add_compile_options(-Wall)
    add_compile_options(-O3)
endif()

# executable definition
add_executable(main main.cpp)
add_executable(hashtabletest HashTableTest.cpp)

# library definition
add_library(HashTable HashTable.cpp HashTable.hpp)
add_library(helpers helpers.cpp helpers.hpp)
if(EXISTS Hopscotch.h)
    add_library(Hopscotch Hopscotch.h Hopscotch.cpp)
endif()

# link libraries to executable 
target_link_libraries(main HashTable)
target_link_libraries(main helpers)
if (EXISTS Hopscotch.h)
    target_link_libraries(main Hopscotch)
endif()
target_link_libraries(hashtabletest HashTable)
target_link_libraries(hashtabletest helpers)


# run target
add_custom_target(run $<TARGET_FILE:main>)
# runtest
add_custom_target(runtest $<TARGET_FILE:hashtabletest>)