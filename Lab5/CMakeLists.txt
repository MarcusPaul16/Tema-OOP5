cmake_minimum_required(VERSION 3.21)
project(Lab5)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab5 cmake-build-debug/main.cpp cmake-build-debug/Entity.cpp cmake-build-debug/Entity.h cmake-build-debug/Repo.cpp cmake-build-debug/Repo.h cmake-build-debug/Test.cpp cmake-build-debug/Test.h cmake-build-debug/Console.cpp cmake-build-debug/Console.h cmake-build-debug/Service.cpp cmake-build-debug/Service.h)
