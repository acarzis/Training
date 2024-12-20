
# enable utf-8 encoding
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")


# define our vcpkg folder location
SET(PKG_CONFIG_EXECUTABLE D:/DEVELOPMENT/vcpkg/vcpkg)
SET(PKG_PACKAGES_LOCATION D:/DEVELOPMENT/vcpkg/packages)


# protobuf dependencies/requirements
SET(CMAKE_MODULE_PATH ${PKG_PACKAGES_LOCATION}/protobuf_x64-windows;D:/DEVELOPMENT/vcpkg/packages/grpc_x64-windows)
SET(Protobuf_DIR ${PKG_PACKAGES_LOCATION}/protobuf_x64-windows/share/protobuf)
SET(Protobuf_LIBRARIES ${PKG_PACKAGES_LOCATION}/protobuf_x64-windows/lib)
SET(Protobuf_INCLUDE_DIR ${PKG_PACKAGES_LOCATION}/protobuf_x64-windows/include)

SET(OPENSSL_ROOT_DIR ${PKG_PACKAGES_LOCATION}/openssl_x64-windows) 
SET(absl_DIR ${PKG_PACKAGES_LOCATION}/abseil_x64-windows/share/absl)
SET(c-ares_DIR ${PKG_PACKAGES_LOCATION}/c-ares_x64-windows/share/c-ares)
SET(c-ares_INCLUDE_DIR ${PKG_PACKAGES_LOCATION}/c-ares_x64-windows/include)
SET(c-ares_LIBRARY ${PKG_PACKAGES_LOCATION}/c-ares_x64-windows/lib)
SET(ZLIB_LIBRARY ${PKG_PACKAGES_LOCATION}/zlib_x64-windows/lib/zlib.lib)
SET(ZLIB_INCLUDE_DIR ${PKG_PACKAGES_LOCATION}/zlib_x64-windows/include)
SET(utf8_range_DIR ${PKG_PACKAGES_LOCATION}/utf8-range_x64-windows/share/utf8_range)
SET(upb_DIR ${PKG_PACKAGES_LOCATION}/upb_x64-windows/share/upb)
SET(re2_DIR ${PKG_PACKAGES_LOCATION}/re2_x64-windows/share/re2)

# gRPC dependencies/requirements
SET(gRPC_DIR ${PKG_PACKAGES_LOCATION}/grpc_x64-windows/share/grpc)

SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

# generate the protobuf & grpc c++ code
add_library(protolib proto/service.proto "Source/animal.cpp" "Source/aquatic_animal.cpp" "Source/land_animal.cpp" "Source/amphibian.cpp" "Include/amphibian.h" "Include/animal.h" "Include/land_animal.h" "Include/aquatic_animal.h" "Source/cpp20.cpp" "Source/Globals.cpp" "Source/basic_concepts.cpp" "Source/inheritance.cpp")
target_link_libraries(protolib gRPC::grpc++)
target_include_directories(protolib PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
protobuf_generate(TARGET protolib LANGUAGE cpp)
protobuf_generate(TARGET protolib LANGUAGE grpc
GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc
PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}")

# target C++ 20
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++20")

# set project requirements & build project
add_executable (Training "Source/Main.cpp" "Include/Main.h" "Include/Person.h" "Source/Person.cpp" "Include/DynamicArray.h" "proto/service.pb.h" "gRPC/service.grpc.pb.h" "Source/animal.cpp" "Source/aquatic_animal.cpp" "Source/land_animal.cpp" "Source/amphibian.cpp" "Include/amphibian.h" "Include/animal.h" "Include/land_animal.h" "Include/aquatic_animal.h" "Source/cpp20.cpp" "Source/Globals.cpp" "Source/basic_concepts.cpp" "Source/inheritance.cpp")
target_include_directories(Training PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include/)
target_include_directories(Training PUBLIC ${PKG_PACKAGES_LOCATION}/grpc_x64-windows/include)
target_include_directories(Training PUBLIC ${PKG_PACKAGES_LOCATION}/abseil_x64-windows/include)
target_include_directories(Training PUBLIC ${PKG_PACKAGES_LOCATION}/protobuf_x64-windows/include)
target_link_libraries(Training protolib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Training PROPERTY CXX_STANDARD 20)
endif()
