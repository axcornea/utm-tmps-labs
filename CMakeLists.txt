cmake_minimum_required(VERSION 3.20)
project(acornea)

set(CMAKE_CXX_STANDARD 17)

add_executable(acornea main.cpp include/Box.h include/BoxFacility.h include/BoxFactory.h include/BoxBuilder.h include/ShoeBox.h include/PresentBox.h include/FoodBox.h include/CustomBox.h src/Box.cpp include/BoxCompositor.h include/CompositeBox.h)
