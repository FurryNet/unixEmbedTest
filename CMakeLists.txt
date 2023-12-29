cmake_minimum_required(VERSION 3.5)
project(unixEmbedTest)

# set(BUILDROOT_DIR ../arm-tmohs1-linux-gnueabi_sdk-buildroot)

# # Setup the embedded libs
# include_directories(${BUILDROOT_DIR}/arm-tmohs1-linux-gnueabi/include)
# link_directories(${BUILDROOT_DIR}/arm-tmohs1-linux-gnueabi/lib)
# # Setup other libs
# include_directories(${BUILDROOT_DIR}/include)
# link_directories(${BUILDROOT_DIR}/lib)

# # Setup the gcc and g++ compilers
# set(CMAKE_C_COMPILER ${BUILDROOT_DIR}/bin/arm-tmohs1-linux-gnueabi-gcc-10.4.0.br_real)
# set(CMAKE_CXX_COMPILER ${BUILDROOT_DIR}/bin/arm-tmohs1-linux-gnueabi-g++.br_real)

# Setup the build output
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


add_subdirectory(src)