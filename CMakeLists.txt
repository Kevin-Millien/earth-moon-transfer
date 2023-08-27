cmake_minimum_required(VERSION 3.27.4)
project(EMT VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(src)
target_link_libraries(${PROJECT_NAME} PRIVATE src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(Python3_INCLUDE_DIRS "C:\\Users\\kmillien\\AppData\\Local\\Programs\\Python\\Python311\\include")
set(Python3_NumPy_INCLUDE_DIRS " C:\\Users\\kmillien\\AppData\\Local\\Programs\\Python\\Python311\\Lib\\site-packages\\numpy\\core\\include")
find_package(Python3 COMPONENTS Development NumPy)
target_include_directories(${PROJECT_NAME} PRIVATE ${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE src Python3::Python Python3::NumPy) 