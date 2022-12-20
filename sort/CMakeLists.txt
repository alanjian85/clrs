project(insertion_sort)
add_executable(insertion_sort sort.cpp)
target_include_directories(insertion_sort PRIVATE insertion)

project(merge_sort)
add_executable(merge_sort sort.cpp)
target_include_directories(merge_sort PRIVATE merge)
