file(GLOB Sources
     "*.cpp"
)

add_library(Visuals ${Sources})



set(Python3_INCLUDE_DIRS "C:/Users/kmillien/AppData/Local/Programs/Python/Python311/include")
set(Python3_NumPy_INCLUDE_DIRS " C:/Users/kmillien/AppData/Local/Programs/Python/Python311/Lib/site-packages/numpy/core/include")
find_package(Python3 COMPONENTS Development NumPy)

target_include_directories(Visuals PUBLIC "../../include" "../../include/Visuals" ${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS} )
target_link_libraries(Visuals PRIVATE src Python3::Python Python3::NumPy) 