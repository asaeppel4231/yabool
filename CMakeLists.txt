cmake_minimum_required(VERSION 3.10)

project(yabool VERSION 0.1 LANGUAGES C)

include(GNUInstallDirs)

# Header-only library
add_library(yabool INTERFACE)


target_include_directories(yabool INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/ya-ecosystem/bool>
)

# Install headers
install(FILES
    bool.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ya-ecosystem/bool
)

# Install the CMake package config
install(
    TARGETS yabool
    EXPORT yaboolTargets
)

install(EXPORT yaboolTargets
    FILE yaboolTargets.cmake
    NAMESPACE ya::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/yabool
)

include(CMakePackageConfigHelpers)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/yaboolConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/yaboolConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/yabool
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/yaboolConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/yaboolConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/yaboolConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/yabool
)

# pkg-config file
configure_file(
    yabool.pc.in
    yabool.pc
    @ONLY
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/yabool.pc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)
