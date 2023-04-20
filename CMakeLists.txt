cmake_minimum_required(VERSION 3.23)
project(data_structure)

set(CMAKE_CXX_STANDARD 14)

add_executable(data_structure main.cpp sequentialList.h sequentialList.cpp linkedList.h linkedList.cpp sequentialStack.h sequentialStack.cpp linkedStack.h linkedStack.cpp sequentialQueue.h sequentialQueue.cpp linkedQueue.h linkedQueue.cpp sequentialString.h sequentialString.cpp linkedString.h linkedString.cpp matchString.h linkedBinaryTree.h huffmanTree.h adjacencyList.h adjacencyMatrix.h search.h hashtable.h sort.h)
