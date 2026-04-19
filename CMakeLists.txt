cmake_minimum_required(VERSION 3.10)

add_library(yabool INTERFACE)


target_include_directories(yabool INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/ya-ecosystem/bool>
)

install(
    FILES ${CMAKE_CURRENT_SOURCE_DIR}/yabool.h
    DESTINATION include/ya-ecosystem/bool
)

install(
    TARGETS yabool
    EXPORT yaboolTargets
)
