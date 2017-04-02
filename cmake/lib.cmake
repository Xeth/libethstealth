find_package(Boost COMPONENTS system REQUIRED)
find_package(EthCrypto REQUIRED)
find_package(CryptoPP REQUIRED)
find_package(JsonCPP REQUIRED)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/CopyHeaders.cmake)

CopyHeaders()

if(${ENABLE_DEBUG})
    add_definitions(-D__DEBUG__)
endif()

file(GLOB SOURCES 
    "src/*.cpp"
)

add_library(ethstealth STATIC ${SOURCES})

target_include_directories(ethstealth PUBLIC ${Boost_INCLUDE_DIRS} ${CRYPTOPP_INCLUDE_DIR} ${JSONCPP_INCLUDE_DIR} ${ETHCRYPTO_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/src)

if(NOT SKIP_LIBRARY_INSTALL)
    install(FILES ${HEADERS} DESTINATION include/ethstealth OPTIONAL)
    install(FILES config.hpp DESTINATION include/ethstealth OPTIONAL)
    install(TARGETS ethstealth ARCHIVE DESTINATION lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin OPTIONAL)
endif()
