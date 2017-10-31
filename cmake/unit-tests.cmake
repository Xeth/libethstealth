file(GLOB TEST_SOURCES 
    "test/*.cpp"
)

add_executable(ethstealth-tests EXCLUDE_FROM_ALL ${TEST_SOURCES})
add_dependencies(ethstealth-tests ethstealth)
target_include_directories(ethstealth-tests PUBLIC ${Boost_INCLUDE_DIRS} ${JSONCPP_INCLUDE_DIR} ${ETHCRYPTO_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(ethstealth-tests ethstealth ${ETHCRYPTO_LIBRARIES} ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${Boost_RANDOM_LIBRARY} ${JSONCPP_LIBRARY})

if(GMP_LIBRARIES)
    target_link_libraries(ethstealth-tests ${GMP_LIBRARIES})
endif()

