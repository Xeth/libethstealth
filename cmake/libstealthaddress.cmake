find_package(Boost COMPONENTS system REQUIRED)


include(${CMAKE_SOURCE_DIR}/cmake/libbitcrypto.cmake)

IF(BITCRYPTO_FOUND)
    MESSAGE(STATUS "BitCrypto - found")
ELSE(BITCRYPTO_FOUND)
    MESSAGE(FATAL_ERROR "BitCrypto - not found")
ENDIF(BITCRYPTO_FOUND)

#add_definitions(-D__DEBUG__)

include_directories(${BITCRYPTO_INCLUDE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/src)


file(GLOB SOURCES 
    "src/*.cpp"
)

file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_SOURCE_DIR}/src
    "src/*.hpp"
    "src/*.ipp"
    "src/detail/*.ipp"
    "src/detail/*.hpp"
)




add_library(stealthaddress STATIC ${SOURCES})


install(FILES ${HEADERS} DESTINATION include/stealthaddress)
install(FILES config.hpp DESTINATION include/stealthaddress)
install (TARGETS stealthaddress ARCHIVE DESTINATION lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin)
