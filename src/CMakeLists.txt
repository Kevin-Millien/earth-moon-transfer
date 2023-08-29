include(FetchContent)

FetchContent_Declare(matplotplusplus
        GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus
        GIT_TAG origin/master) # or whatever tag you want

FetchContent_GetProperties(matplotplusplus)
if(NOT matplotplusplus_POPULATED)
    FetchContent_Populate(matplotplusplus)
    add_subdirectory(${matplotplusplus_SOURCE_DIR} ${matplotplusplus_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
file(GLOB Sources
     "*.cpp"
)

add_library(src ${Sources})

add_subdirectory(Planets)
add_subdirectory(Visuals)

find_package(Python3 COMPONENTS Development NumPy)
target_link_libraries(src PUBLIC Planets Visuals Python3::Python Python3::NumPy matplot)
target_include_directories(src PUBLIC "." "../include/" "../include/Planets" "../include/Visuals"  ${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS} ${matplotplusplus_SOURCE_DIR} ${matplotplusplus_BINARY_DIR})
