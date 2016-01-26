find_package(Boost COMPONENTS system REQUIRED)


include(${CMAKE_SOURCE_DIR}/cmake/libethkey.cmake)

IF(ETHKEY_FOUND)
    MESSAGE(STATUS "EthKey - found")
ELSE(ETHKEY_FOUND)
    MESSAGE(FATAL_ERROR "EthKey - not found")
ENDIF(ETHKEY_FOUND)

#add_definitions(-D__DEBUG__)

include_directories(${ETHKEY_INCLUDE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/src)


file(GLOB SOURCES 
    "src/*.cpp"
)

file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_SOURCE_DIR}/src
    "src/*.hpp"
    "src/*.ipp"
    "src/detail/*.ipp"
    "src/detail/*.hpp"
)




add_library(ethstealth STATIC ${SOURCES})


install(FILES ${HEADERS} DESTINATION include/ethstealth)
install(FILES config.hpp DESTINATION include/ethstealth)
install (TARGETS ethstealth ARCHIVE DESTINATION lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin)
