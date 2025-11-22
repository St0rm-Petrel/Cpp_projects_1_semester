cmake_minimum_required(VERSION 3.10)

# Название проекта и язык
project(task_radians_and_degrees CXX)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Включение каталога с исходными кодами для заголовочных файлов
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Список исходных файлов
set(SOURCES
    main.cpp
    radians.cpp
    degrees.cpp
)

# Создание исполняемого файла
add_executable(task_radians_and_degrees ${SOURCES})

# Установка свойств компиляции
target_compile_features(task_radians_and_degrees PRIVATE cxx_std_17)

# Включение дополнительных предупреждений компилятора
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(task_radians_and_degrees PRIVATE -Wall -Wextra -pedantic)
endif()

# Для Windows: установка подсистемы
if(WIN32)
    target_link_options(task_radians_and_degrees PRIVATE -Wl,--subsystem,console)
endif()
