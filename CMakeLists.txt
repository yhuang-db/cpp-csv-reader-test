cmake_minimum_required(VERSION 3.19)
project(cpp-csv-readers)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        src/main.cpp
        src/include/driver.h src/driver.cpp src/include/csvmonkey.h src/include/csv.h )

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
        PRIVATE ${PROJECT_SOURCE_DIR}/src/include
        )

target_compile_options(${PROJECT_NAME}
        PRIVATE  -msse4.2 -O3
        )