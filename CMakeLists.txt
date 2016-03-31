cmake_minimum_required(VERSION 2.6)

project(PFract)

list( APPEND CMAKE_MODULE_PATH
        ${PROJECT_SOURCE_DIR}/extern
        )

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SOURCE_FILES
        View.cpp View.h
        Compositor.cpp Compositor.h
        CLCompositor.cpp CLCompositor.h
        Window.cpp Window.h
        types.h
        CPPCompositor.cpp CPPCompositor.h
        main.cpp)

add_executable(PFract ${SOURCE_FILES})

# Maybe use this as a backend for drawing stuff?
find_package(CImg REQUIRED)
include_directories(${CImg_INCLUDE_DIRS})
target_link_libraries(PFract ${CImg_SYSTEM_LIBS})
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CIMG_CFLAGS}")


# We use OpenGL as a backend for drawing stuff
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
target_link_libraries(PFract ${OPENGL_LIBRARIES})


# We'll load these with PkgConfig
find_package(PkgConfig REQUIRED)


# This is for a window and some key events
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(PFract ${GLFW_LIBRARIES})
target_link_libraries(PFract ${GLFW_STATIC_LIBRARIES})


# And this is to compute everything
pkg_search_module(OPENCL required OpenCL)
include_directories(${OPENCL_INCLUDE_DIRS})
target_link_libraries(PFract ${OPENCL_LIBRARIES})




