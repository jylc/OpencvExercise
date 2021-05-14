# CMakeList.txt: RobustImageStitching 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("RobustImageStitching")

find_package(OpenCV REQUIRED)


if(OpenCV_FOUND)
	message(STATUS "Find the opencv")
	include_directories(${OpenCV_INCLUDE_DIRS})
endif(OpenCV_FOUND)

add_executable (RobustImageStitching "RobustImageStitching.cpp" "RobustImageStitching.h")
if(OpenCV_FOUND)
	link_directories(${OpenCV_LIBRARY_DIRS})
	target_link_libraries(RobustImageStitching ${OpenCV_LIBS})
endif(OpenCV_FOUND)

if(MSVC)
	message(STATUS "Find the opencv")
	file(GLOB RESOURCES "./datas")
	add_custom_command(TARGET RobustImageStitching
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${RESOURCES}
	"$<TARGET_FILE_DIR:RobustImageStitching>"
	)
endif(MSVC)
