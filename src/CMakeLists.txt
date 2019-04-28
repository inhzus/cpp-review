file(GLOB SOURCE_FILES algorithm/*.cc search/*.cc sort/*.cc thread/*.cc)
add_library(lib ${SOURCE_FILES})
target_link_libraries(lib pthread)
