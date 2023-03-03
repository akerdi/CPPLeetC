cmake_minimum_required(VERSION 2.9)

project(app)
set(APP_VERSION_MAJOR 1)
set(APP_VERSION_MINOR 0)
option(ENABLE_CPPLEETC "Enable cpp leet code" OFF)

configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_SOURCE_DIR}/config.h"
    )

if (ENABLE_CPPLEETC)
    message("enable cpp leet code")
    include_directories(sub/cppleetc)
    add_subdirectory(sub/cppleetc)
    set(EXTRA_LIBS ${EXTRA_LIBS} CPPLEETC)
endif()

aux_source_directory(. SRC_DIR)
add_executable(app ${SRC_DIR})

target_link_libraries(app ${EXTRA_LIBS})