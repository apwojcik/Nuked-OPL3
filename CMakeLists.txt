cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

project(OPL3 VERSION 1.8 LANGUAGES C)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
add_library(opl3 opl3.c opl3.h)

include(GNUInstallDirs)
include(GenerateExportHeader)

GENERATE_EXPORT_HEADER(opl3 BASE_NAME OPL EXPORT_FILE_NAME export.h)
target_include_directories(opl3 PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
        INTERFACE $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/opl3>)

install(TARGETS opl3 EXPORT OPL3-config COMPONENT OPL3 LIBRARY)

install(FILES ${CMAKE_BINARY_DIR}/export.h opl3.h
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/opl3)

set(OPL3_INSTALL_CMAKEDIR ${CMAKE_INSTALL_LIBDIR}/cmake/OPL3)

install(EXPORT OPL3-config FILE OPL3-targets.cmake DESTINATION ${OPL3_INSTALL_CMAKEDIR} NAMESPACE OPL3::)

include(CMakePackageConfigHelpers)

configure_package_config_file(
        opl3-config.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/OPL3-config.cmake
        INSTALL_DESTINATION ${OPL3_INSTALL_CMAKEDIR})

write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/OPL3-config-version.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion)

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/OPL3-config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/OPL3-config-version.cmake
        DESTINATION ${OPL3_INSTALL_CMAKEDIR})

export(EXPORT OPL3-config FILE ${CMAKE_CURRENT_BINARY_DIR}/OPL3-targets.cmake)
