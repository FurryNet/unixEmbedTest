find_package(OpenSSL REQUIRED)

add_executable(unixEmbedTest main.cpp ProgressManager.cpp)

target_link_libraries(unixEmbedTest OpenSSL::Crypto)

include_directories(.)