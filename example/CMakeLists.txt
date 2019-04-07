set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../bin)

link_directories(${PROJECT_SOURCE_DIR}/../bin)

set_option(BUILD_SHARED_LIBS TRUE BOOL "TRUE to build runtime as shared libraries, FALSE to build static libraries")

include_directories(${PROJECT_SOURCE_DIR}/inc)
link_libraries(IDCP)

set(SRC ${PROJECT_SOURCE_DIR}/example)

set(PROJECT_FILES
	${SRC}/main.cpp
)

add_executable(example ${PROJECT_FILES})

set_property(TARGET example PROPERTY CXX_STANDARD 14)
set_property(TARGET example PROPERTY CXX_STANDARD_REQUIRED ON)