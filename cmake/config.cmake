
set (Eth_Stealth_VERSION_MAJOR 1)
set (Eth_Stealth_VERSION_MINOR 0)
set (Eth_Stealth_VERSION_PATCH 0)

configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/src/config.hpp.in"
  "${CMAKE_CURRENT_BINARY_DIR}/config.hpp"
)

#add_definitions(-D__DEBUG__)
