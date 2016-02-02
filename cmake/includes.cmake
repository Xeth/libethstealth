
file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/src
    "src/*.hpp"
    "src/*.ipp"
    "src/detail/*.ipp"
    "src/detail/*.hpp"
)

foreach(HEADER ${HEADERS})
    set(HEADER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src/${HEADER})
    configure_file(${HEADER_PATH} ${CMAKE_CURRENT_BINARY_DIR}/include/ethstealth/${HEADER} @ONLY)
endforeach(HEADER)
