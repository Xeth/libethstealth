find_package(Boost COMPONENTS system REQUIRED)
find_package(EthKey REQUIRED)
find_package(CryptoPP REQUIRED)
find_package(JsonCPP REQUIRED)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/CopyHeaders.cmake)

CopyHeaders()

#add_definitions(-D__DEBUG__)

include_directories(${CRYPTOPP_INCLUDE_DIR} ${JSONCPP_INCLUDE_DIR} ${ETHKEY_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/src)


file(GLOB SOURCES 
    "src/*.cpp"
)




add_library(ethstealth STATIC ${SOURCES})


install(FILES ${HEADERS} DESTINATION include/ethstealth)
install(FILES config.hpp DESTINATION include/ethstealth)
install (TARGETS ethstealth ARCHIVE DESTINATION lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin)
