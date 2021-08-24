cmake_minimum_required(VERSION 3.16)

set( CMAKE_CXX_FLAGS "-O0 -g" )

project(Tutorial)

link_directories(/home/gklpvi/Downloads/dpdk-stable-19.11.9/x86_64-native-linuxapp-gcc/lib)

add_executable(Tutorial ./main.cpp)

target_include_directories(Tutorial PUBLIC /home/gklpvi/Downloads/dpdk-stable-19.11.9/x86_64-native-linuxapp-gcc/include)

target_link_libraries(Tutorial -Wl,--whole-archive /home/gklpvi/Downloads/dpdk-stable-19.11.9/x86_64-native-linuxapp-gcc/lib/libdpdk.a -Wl,--no-whole-archive)
target_link_libraries(Tutorial pthread dl numa)
