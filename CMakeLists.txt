cmake_minimum_required(VERSION 3.5)

project(OOP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(OOP main.cpp container_list.h Exceptionlist.h Iterator.h)


install(TARGETS OOP
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
