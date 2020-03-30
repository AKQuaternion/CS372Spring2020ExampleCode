cmake_minimum_required(VERSION 3.15)
project(CS372Spring2020ExampleCode)

set(CMAKE_CXX_STANDARD 20)

add_executable(CS372Spring2020ExampleCode main.cpp moderncppexamples.cpp moderncppexamples.hpp Expression.cpp Expression.hpp StoreByReference.hpp StoreByPointer.hpp Observer.cpp Observer.hpp Subject.cpp Subject.hpp)