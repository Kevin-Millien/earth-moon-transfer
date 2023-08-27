file(GLOB Sources
     "*.cpp"
)

add_library(src ${Sources})

add_subdirectory(Planets)
add_subdirectory(Visuals)


target_link_libraries(src PRIVATE Planets Visuals)
target_include_directories(src PUBLIC "../include/" "../include/Planets" "../include/Visuals")
