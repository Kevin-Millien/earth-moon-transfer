file(GLOB Sources
     "*.cpp"
)

add_library(Planets ${Sources})
target_link_libraries(Planets PRIVATE src)

target_include_directories(Planets PUBLIC "../" "../../include" "../../include/Planets" )