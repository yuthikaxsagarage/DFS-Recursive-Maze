cmake_minimum_required(VERSION 3.15)
project(maze)
find_package(OpenGL REQUIRED)
find_package(GLUT)

set(CMAKE_CXX_STANDARD 17)

set(source_files
        utils.cpp recursive_back_tracker.cpp)
set(header_files
        utils.h recursive_back_tracker.h)





add_executable(maze main.cpp ${source_files} ${header_files})
target_link_libraries( ${PROJECT_NAME} ${OPENGL_gl_LIBRARY} ${GLUT_LIBRARIES} GL)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${OPENGL_gl_LIBRARY})