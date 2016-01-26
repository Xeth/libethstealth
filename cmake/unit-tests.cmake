find_package(Boost COMPONENTS system filesystem unit_test_framework random REQUIRED)

file(GLOB TEST_SOURCES 
    "test/*.cpp"
)


include_directories(${ETHKEY_INCLUDE_PATH})
include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(unit-tests ${TEST_SOURCES})
add_dependencies(unit-tests ethstealth)

target_link_libraries(unit-tests ethstealth ${ETHKEY_LIBRARY} ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${Boost_RANDOM_LIBRARY} gmp)
