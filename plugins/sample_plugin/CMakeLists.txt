# cmake_minimum_required(VERSION 3.10)
# project(TaskManager)

# set(CMAKE_CXX_STANDARD 17)

# include_directories(include)

# add_executable(TaskManager
#     src/main.cpp
#     src/TaskManager.cpp
#     src/PlatformUtils.cpp
# )

# # Plugin build
# add_library(sample_plugin SHARED plugins/sample_plugin/SamplePlugin.cpp)
# target_include_directories(sample_plugin PRIVATE ${CMAKE_SOURCE_DIR}/include)
# set_target_properties(sample_plugin PROPERTIES OUTPUT_NAME "sample_plugin")
