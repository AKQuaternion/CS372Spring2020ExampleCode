cmake_minimum_required(VERSION 3.15)
project(CS372Spring2020ExampleCode)

add_compile_options(-Wall -Wextra -Wpedantic -Weverything
        -Wno-c++98-compat -Wno-padded -Wno-weak-vtables -Wno-missing-prototypes)

add_executable(CS372Spring2020ExampleCode main.cpp moderncppexamples.cpp
        moderncppexamples.hpp Expression.cpp Expression.hpp StoreByReference.hpp
        StoreByPointer.hpp Observer.cpp Observer.hpp Subject.cpp Subject.hpp)

target_compile_features(CS372Spring2020ExampleCode PRIVATE cxx_std_20)

