

add_library(stealthaddress STATIC ${CMAKE_SOURCE_DIR}/src/main.cpp) 
add_dependencies(stealthaddress libsecp256k1)
add_dependencies(stealthaddress stealthaddress-core)



if (WIN32)
    set_property (TARGET stealthaddress APPEND PROPERTY STATIC_LIBRARY_FLAGS ${CMAKE_BINARY_DIR}/secp256k1/lib/libsecp256k1.a ${CMAKE_BINARY_DIR}/libstealthaddress-core.a)
elseif (APPLE AND ${CMAKE_GENERATOR} STREQUAL "Xcode")
    set_property (TARGET stealthaddress APPEND PROPERTY STATIC_LIBRARY_FLAGS ${CMAKE_BINARY_DIR}/secp256k1/lib/libsecp256k1.a ${CMAKE_BINARY_DIR}/libstealthaddress-core.a)
elseif (UNIX)
    set(LIB_OBJ_DIR ${CMAKE_BINARY_DIR}/lib.obj)
    make_directory (${LIB_OBJ_DIR})

    ADD_CUSTOM_COMMAND(TARGET stealthaddress
          POST_BUILD
          COMMAND echo "packing libstealthaddress.a"
          COMMAND ${CMAKE_AR} x ${CMAKE_BINARY_DIR}/secp256k1/lib/libsecp256k1.a WORKING_DIRECTORY ${LIB_OBJ_DIR}
          COMMAND ${CMAKE_AR} x ${CMAKE_BINARY_DIR}/libstealthaddress-core.a WORKING_DIRECTORY ${LIB_OBJ_DIR}
          COMMAND ${CMAKE_AR} rcs ${CMAKE_BINARY_DIR}/libstealthaddress.a ${LIB_OBJ_DIR}/*.o
          COMMAND rm -fr ${LIB_OBJ_DIR}
    )
endif (WIN32)


file(GLOB SECP256K1_HEADERS 
    "${PROJECT_BINARY_DIR}/secp256k1/include/*"
)


install(FILES ${HEADERS} DESTINATION include/stealthaddress)
install(FILES ${SECP256K1_HEADERS} DESTINATION include/stealthaddress)
install(FILES config.hpp DESTINATION include/stealthaddress)
install (TARGETS stealthaddress ARCHIVE DESTINATION lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin)

