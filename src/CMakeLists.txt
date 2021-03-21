include_directories(
    ${CMAKE_SOURCE_DIR}/lib
)

add_executable(${PROJECT_NAME} main.cc t01.cc t02.cc t03.cc)
target_link_libraries(${PROJECT_NAME} myutils)
