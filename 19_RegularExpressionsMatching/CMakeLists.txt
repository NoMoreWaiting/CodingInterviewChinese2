
include_directories(${PROJECT_SOURCE_DIR}/Utilities)

#4.source directory, 源文件目录
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/Utilities SRC)

STRING( REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR} )

set(CUR_PATH ${PROJECT_SOURCE_DIR}/${CURRENT_FOLDER})

file(GLOB_RECURSE CUR_SRC "${CUR_PATH}/*.h" "${CUR_PATH}/*.cpp")

MESSAGE("${CURRENT_FOLDER}")
MESSAGE("${CUR_PATH}")
MESSAGE("${CUR_SRC}")
MESSAGE("${SRC}")
add_executable(${CURRENT_FOLDER}
        ${CUR_SRC}
        ${SRC}
        )