set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../lib)

set_option(BUILD_SHARED_LIBS TRUE BOOL "TRUE to build runtime as shared libraries, FALSE to build static libraries")

include_directories(${PROJECT_SOURCE_DIR}/inc)

set(INC ${PROJECT_SOURCE_DIR}/inc)
set(SRC ${PROJECT_SOURCE_DIR}/src)

set(PROJECT_FILES
	${SRC}/Note.cpp
	${SRC}/Bpm.cpp
	${SRC}/Sud.cpp
	${SRC}/Song.cpp
)

add_library(IDCP ${PROJECT_FILES})

set_property(TARGET IDCP PROPERTY CXX_STANDARD 11)
set_property(TARGET IDCP PROPERTY CXX_STANDARD_REQUIRED ON)