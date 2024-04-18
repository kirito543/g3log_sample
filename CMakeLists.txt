cmake_minimum_required(VERSION 3.2)

project(g3log_test)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(THIRD_PARTY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src/third_party)

# glog库
add_library(glog INTERFACE)
set(GLOG_PATH ${THIRD_PARTY_PATH})
target_include_directories(glog INTERFACE ${GLOG_PATH}/include)
link_directories(${GLOG_PATH}/lib)
target_link_libraries(glog INTERFACE libg3log.a)

macro(glob_sources sources_var sources_path)
    file(GLOB_RECURSE ${sources_var} ${sources_path}/*.h ${sources_path}/*.c
        ${sources_path}/*.cc ${sources_path}/*.cpp ${sources_path}/*.cxx)
endmacro()

glob_sources(TEST_SOURCES ${SOURCE_DIR})
add_executable(g3log_test ${TEST_SOURCES})
target_include_directories(g3log_test PUBLIC ${SOURCE_DIR} )
target_link_libraries(g3log_test glog)
set_target_properties(g3log_test PROPERTIES LINK_FLAGS "-Wl,--as-needed")
