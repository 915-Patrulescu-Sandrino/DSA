cmake_minimum_required(VERSION 3.17)
project(LAB2_FixedCapBiMap)

set(CMAKE_CXX_STANDARD 14)

add_executable(LAB2_FixedCapBiMap App.cpp
        LAB2_FixedCapBiMap FixedCapBiMap.h
        LAB2_FixedCapBiMap FixedCapBiMap.cpp
        LAB2_FixedCapBiMap ExtendedTest.cpp
        LAB2_FixedCapBiMap ExtendedTest.h
        LAB2_FixedCapBiMap ShortTest.h
        LAB2_FixedCapBiMap ShortTest.cpp
        LAB2_FixedCapBiMap FixedCapBiMapIterator.h
        LAB2_FixedCapBiMap FixedCapBiMapIterator.cpp)