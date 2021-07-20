# CMakeList.txt: RobustImageStitching 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required(VERSION 3.8)

project("OpencvExercise")

find_package(OpenCV REQUIRED)


if (OpenCV_FOUND)
    message(STATUS "Find the opencv")
    include_directories(${OpenCV_INCLUDE_DIRS})
endif (OpenCV_FOUND)

set(DIR_LIST "utils")
foreach (SUB_DIR ${DIR_LIST})
    INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/${SUB_DIR})
    AUX_SOURCE_DIRECTORY(${SUB_DIR} SRC_LIST)
endforeach (SUB_DIR)


add_executable(OpencvExercise "OpencvExercise.cpp" "OpencvExercise.h" ${SRC_LIST})
if (OpenCV_FOUND)
    link_directories(${OpenCV_LIBRARY_DIRS})
    target_link_libraries(OpencvExercise ${OpenCV_LIBS})
endif (OpenCV_FOUND)

if (MSVC)
    message(STATUS "Find the opencv")
    file(GLOB RESOURCES "./datas")
    add_custom_command(TARGET OpencvExercise
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${RESOURCES}
            "$<TARGET_FILE_DIR:OpencvExercise>"
            )
endif (MSVC)
