include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/MakeIncludesLink.cmake)

MakeIncludesLink()


include_directories(${Boost_INCLUDE_DIRS} ${JSONCPP_INCLUDE_DIR} ${ETHCRYPTO_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/src)


file(GLOB SOURCES 
    "src/*.cpp"
)


add_library(ethstealth STATIC ${SOURCES})
add_dependencies(ethstealth ethcrypto)

if(NOT SKIP_LIBRARY_INSTALL)
    install(FILES ${HEADERS} DESTINATION include/ethstealth OPTIONAL)
    install(FILES config.hpp DESTINATION include/ethstealth OPTIONAL)
    install(TARGETS ethstealth ARCHIVE DESTINATION lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin OPTIONAL)
endif()


set(ETHSTEALTH_INCLUDE_DIRS ${CMAKE_CURRENT_BINARY_DIR}/include PARENT_SCOPE)
set(ETHSTEALTH_LIBRARY ethcrypto)
set(ETHSTEALTH_LIBRARIES ${ETHSTEALTH_LIBRARY})
