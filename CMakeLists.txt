cmake_minimum_required(VERSION 3.15)
project(CS372Spring2020ExampleCode)

add_executable(CS372Spring2020ExampleCode main.cpp moderncppexamples.cpp
        moderncppexamples.hpp Expression.cpp Expression.hpp StoreByReference.hpp
        StoreByPointer.hpp Observer.cpp Observer.hpp Subject.cpp Subject.hpp
        Armor.cpp Armor.hpp HomeAutomationComponent.cpp Command.cpp Command.hpp
        Door.cpp Door.hpp Composite.hpp Composite.cpp MP3Player.cpp MP3Player.hpp MP3PlayerState.cpp MP3PlayerState.hpp)

target_compile_features(CS372Spring2020ExampleCode PRIVATE cxx_std_20)

target_compile_options(CS372Spring2020ExampleCode PRIVATE
        -Wall -Wextra -Wpedantic -Weverything
        -Wno-c++98-compat -Wno-padded -Wno-weak-vtables -Wno-missing-prototypes)


