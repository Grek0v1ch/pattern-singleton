cmake_minimum_required(VERSION 3.23)
project(pattern_singleton)

set(CMAKE_CXX_STANDARD 14)

add_executable(pattern_singleton
        src/main.cpp
        src/Singleton_Meyers.cpp)

# указываем куда будем класть исполняемый файл
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# копируем папку res к исполняемому файлу
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/res)
