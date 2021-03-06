CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

SET(MBED_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEVICE_FLASH")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DDEVICE_FLASH -std=gnu99")

add_definitions(-DDEVICE_FLASH)

SET(FLASH_IMPL_SRCS
        ${MBED_SOURCE_DIR}/flash_api.c
        ${MBED_SOURCE_DIR}/ExternalBlockDevice.cpp
        ${MBED_SOURCE_DIR}/lpc546xx_spifi_storage.c
        ${MBED_SOURCE_DIR}/FlashIAP_LPCXpresso54628.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(kvstore_flash_impl STATIC ${FLASH_IMPL_SRCS})
add_dependencies(kvstore_flash_impl board)
target_link_libraries(kvstore_flash_impl board)
