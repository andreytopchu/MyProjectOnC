cmake_minimum_required(VERSION 3.23)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c Structures/DoublyLinkedList.c Interfaces/DoublyLinkedList.h Interfaces/Stack.h Structures/Stack.c Interfaces/Queue.h Structures/Queue.c Structures/Coins.c Interfaces/Coins.h)
