cmake_minimum_required(VERSION 2.6)

project(LIBMC)

set(LIBMC_MAJOR_VERSION 2)
set(LIBMC_MINOR_VERSION 1)
set(LIBMC_PATCH_VERSION 4)
set(LIBMC_VERSION 
    ${LIBMC_MAJOR_VERSION}.${LIBMC_MINOR_VERSION}.${LIBMC_PATCH_VERSION})

include_directories($ENV{CHHOME}/extern/include)
link_directories($ENV{CHHOME}/extern/lib)

add_subdirectory(src)
add_subdirectory(demos)
