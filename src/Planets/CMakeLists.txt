file(GLOB Sources
     "*.cpp"
)

add_library(Planets ${Sources})
target_link_libraries(Planets PUBLIC src)

