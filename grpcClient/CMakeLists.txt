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


add_executable(grpcClient "Source/Main.cpp" )
target_include_directories(grpcClient PUBLIC ${PKG_PACKAGES_LOCATION}/grpc_x64-windows/include)
target_include_directories(grpcClient PUBLIC ${PKG_PACKAGES_LOCATION}/abseil_x64-windows/include)
target_include_directories(grpcClient PUBLIC ${PKG_PACKAGES_LOCATION}/protobuf_x64-windows/include)
target_link_libraries(grpcClient protolib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET grpcClient PROPERTY CXX_STANDARD 20)
endif()
