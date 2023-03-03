cmake_minimum_required(VERSION 2.9)

project(app)
set(APP_VERSION_MAJOR 1)
set(APP_VERSION_MINOR 0)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
option(ENABLE_CPPLEETC "Enable cpp leet code" OFF)

configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_SOURCE_DIR}/config.h"
    )

find_package(Boost 1.45.0)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    set(EXTRA_LIBS ${EXTRA_LIBS} ${Boost_LIBRARIES})
endif()

if (ENABLE_CPPLEETC)
    message("enable cpp leet code")
    include_directories(sub/cppleetc)
    add_subdirectory(sub/cppleetc)
    set(EXTRA_LIBS ${EXTRA_LIBS} CPPLEETC)
endif()

aux_source_directory(. SRC_DIR)
add_executable(app ${SRC_DIR})

target_link_libraries(app ${EXTRA_LIBS})