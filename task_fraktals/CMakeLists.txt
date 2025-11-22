cmake_minimum_required(VERSION 3.20)

project(taks_fraktals2 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-pedantic -Wall -Wextra")

# --- Пути к исходникам ---
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${SRC_DIR})


# --- Список исходных файлов проекта ---
set(SOURCES
    ${SRC_DIR}/levi.cpp
    ${SRC_DIR}/poly.cpp
    ${SRC_DIR}/vec2d.cpp
    ${SRC_DIR}/Graph.cpp
    ${SRC_DIR}/GUI.cpp
    ${SRC_DIR}/Window.cpp
    
)

# --- Создаём исполняемый файл ---
add_executable(${PROJECT_NAME} ${SOURCES})

# --- Линкуем FLTK ---
target_link_libraries(${PROJECT_NAME} PRIVATE
    fltk
    fltk_images
)


find_package(FLTK)
target_include_directories(${PROJECT_NAME} PRIVATE
        ${fltk_SOURCE_DIR}
)
