file(GLOB Sources
     "*.cpp"
)

add_library(Visuals ${Sources})
target_link_libraries(Visuals PUBLIC src matplot)