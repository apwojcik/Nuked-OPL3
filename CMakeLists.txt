cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

project(Nuked-OPL3 VERSION 1.8 LANGUAGES C)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
add_library(opl3 opl3.c opl3.h)

include(GenerateExportHeader)

GENERATE_EXPORT_HEADER(opl3 BASE_NAME OPL EXPORT_FILE_NAME export.h)
target_include_directories(opl3 PUBLIC ${CMAKE_BINARY_DIR})

install(TARGETS opl3)
install(FILES ${CMAKE_BINARY_DIR}/export.h opl3.h DESTINATION include/opl3)
