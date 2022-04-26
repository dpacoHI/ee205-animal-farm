project(ee205_lab_10d_animal_farm)

cmake_minimum_required(VERSION 3.22)


set(CMAKE_CXX_STANDARD 14)

add_executable(ee205_lab_10d_animal_farm main.cpp config.h Cat.cpp Cat.h Mammal.h Animal.h Color.h Gender.h Node.h List.h Weight.h SinglyLinkedList.h Weight.cpp List.cpp SinglyLinkedList.cpp Animal.cpp Mammal.cpp)
