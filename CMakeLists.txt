cmake_minimum_required(VERSION 3.10)

# Nama project
project(Terminal_Custom_Database_Engine VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# Opsi untuk enable/disable testing
option(BUILD_TESTING "Build tests" OFF)

# Compiler flags
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
elseif(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
endif()

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Kumpulkan semua source files
set(SOURCES
    main.cpp
    src/command.cpp
    src/DATABASE_ENGINE.cpp
    src/record.cpp
    src/table.cpp
)

# Buat executable utama
add_executable(${PROJECT_NAME} ${SOURCES})

# Set output directory untuk executable
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
    DEBUG_POSTFIX "_debug"
)

# Link libraries jika diperlukan (contoh)
# target_link_libraries(${PROJECT_NAME} PRIVATE some_library)

# Tambahkan testing jika diaktifkan
if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()

# Custom target untuk menjalankan program
add_custom_target(run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

# Tampilkan informasi build
message(STATUS "================================================")
message(STATUS "Project Name: ${PROJECT_NAME}")
message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "C++ Standard: C++${CMAKE_CXX_STANDARD}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Output Directory: ${CMAKE_SOURCE_DIR}/bin")
message(STATUS "================================================")