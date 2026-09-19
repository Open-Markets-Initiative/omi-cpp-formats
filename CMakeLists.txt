cmake_minimum_required(VERSION 3.20)
project(omi_cpp_formats CXX)

# The parsers and writers use C++23; a C++23 compiler (GCC 14+) is required.
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# What the formats write through. A library's own headers are included as a system directory, so
# its warnings are not reported against these sources.
find_package(RapidJSON REQUIRED)
find_package(Arrow REQUIRED)
find_package(Parquet REQUIRED)

# The captures are zstd compressed, so the reader is built with zstd to open one.
find_library(ZSTD_LIBRARY NAMES zstd REQUIRED)
find_path(ZSTD_INCLUDE_DIR NAMES zstd.h REQUIRED)
add_compile_definitions(HAS_ZSTD)

# Each translation unit under checks/ includes a protocol's writers in one format, so compiling it
# compiles the writers and the Advanced layout assertions they include. A clean build is the gate,
# and it covers a protocol the corpus has no capture of.
add_library(formats_check OBJECT
  checks/iex_iexequities_deep_iextp_v1.06_json_native.cpp
  checks/iex_iexequities_deep_iextp_v1.06_json_rapid.cpp
  checks/iex_iexequities_deep_iextp_v1.06_parquet_wide.cpp
  checks/iex_iexequities_deep_iextp_v1.08_json_native.cpp
  checks/iex_iexequities_deep_iextp_v1.08_json_rapid.cpp
  checks/iex_iexequities_deep_iextp_v1.08_parquet_wide.cpp
  checks/iex_iexequities_deepplus_iextp_v1.01_json_native.cpp
  checks/iex_iexequities_deepplus_iextp_v1.01_json_rapid.cpp
  checks/iex_iexequities_deepplus_iextp_v1.01_parquet_wide.cpp
  checks/iex_iexequities_deepplus_iextp_v1.04_json_native.cpp
  checks/iex_iexequities_deepplus_iextp_v1.04_json_rapid.cpp
  checks/iex_iexequities_deepplus_iextp_v1.04_parquet_wide.cpp
  checks/iex_iexequities_tops_iextp_v1.56_json_native.cpp
  checks/iex_iexequities_tops_iextp_v1.56_json_rapid.cpp
  checks/iex_iexequities_tops_iextp_v1.56_parquet_wide.cpp
  checks/iex_iexequities_tops_iextp_v1.64_json_native.cpp
  checks/iex_iexequities_tops_iextp_v1.64_json_rapid.cpp
  checks/iex_iexequities_tops_iextp_v1.64_parquet_wide.cpp
  checks/iex_iexequities_tops_iextp_v1.66_json_native.cpp
  checks/iex_iexequities_tops_iextp_v1.66_json_rapid.cpp
  checks/iex_iexequities_tops_iextp_v1.66_parquet_wide.cpp
  checks/nasdaq_nsmequities_aggregated_itch_v2.0_json_native.cpp
  checks/nasdaq_nsmequities_aggregated_itch_v2.0_json_rapid.cpp
  checks/nasdaq_nsmequities_aggregated_itch_v2.0_parquet_wide.cpp
  checks/nasdaq_nsmequities_level2_itch_v2.0_json_native.cpp
  checks/nasdaq_nsmequities_level2_itch_v2.0_json_rapid.cpp
  checks/nasdaq_nsmequities_level2_itch_v2.0_parquet_wide.cpp
  checks/nasdaq_nsmequities_nlsplus_itch_v4.0_json_native.cpp
  checks/nasdaq_nsmequities_nlsplus_itch_v4.0_json_rapid.cpp
  checks/nasdaq_nsmequities_nlsplus_itch_v4.0_parquet_wide.cpp
  checks/nasdaq_nsmequities_noiview_itch_v3.0.2017_json_native.cpp
  checks/nasdaq_nsmequities_noiview_itch_v3.0.2017_json_rapid.cpp
  checks/nasdaq_nsmequities_noiview_itch_v3.0.2017_parquet_wide.cpp
  checks/nasdaq_nsmequities_noiview_itch_v3.0.2026_json_native.cpp
  checks/nasdaq_nsmequities_noiview_itch_v3.0.2026_json_rapid.cpp
  checks/nasdaq_nsmequities_noiview_itch_v3.0.2026_parquet_wide.cpp
  checks/nasdaq_nsmequities_qbbo_itch_v2.1_json_native.cpp
  checks/nasdaq_nsmequities_qbbo_itch_v2.1_json_rapid.cpp
  checks/nasdaq_nsmequities_qbbo_itch_v2.1_parquet_wide.cpp
  checks/nasdaq_nsmequities_totalview_itch_v4.1_json_native.cpp
  checks/nasdaq_nsmequities_totalview_itch_v4.1_json_rapid.cpp
  checks/nasdaq_nsmequities_totalview_itch_v4.1_parquet_wide.cpp
  checks/nasdaq_nsmequities_totalview_itch_v5.0.2017_json_native.cpp
  checks/nasdaq_nsmequities_totalview_itch_v5.0.2017_json_rapid.cpp
  checks/nasdaq_nsmequities_totalview_itch_v5.0.2017_parquet_wide.cpp
  checks/nasdaq_nsmequities_totalview_itch_v5.0.2018_json_native.cpp
  checks/nasdaq_nsmequities_totalview_itch_v5.0.2018_json_rapid.cpp
  checks/nasdaq_nsmequities_totalview_itch_v5.0.2018_parquet_wide.cpp
  checks/nasdaq_nsmequities_totalview_itch_v5.0.2022_json_native.cpp
  checks/nasdaq_nsmequities_totalview_itch_v5.0.2022_json_rapid.cpp
  checks/nasdaq_nsmequities_totalview_itch_v5.0.2022_parquet_wide.cpp
  checks/nasdaq_nsmequities_totalview_itch_v5.0.2023_json_native.cpp
  checks/nasdaq_nsmequities_totalview_itch_v5.0.2023_json_rapid.cpp
  checks/nasdaq_nsmequities_totalview_itch_v5.0.2023_parquet_wide.cpp
  checks/nasdaq_nsmequities_totalview_itch_v5.0.2026_json_native.cpp
  checks/nasdaq_nsmequities_totalview_itch_v5.0.2026_json_rapid.cpp
  checks/nasdaq_nsmequities_totalview_itch_v5.0.2026_parquet_wide.cpp
)
target_include_directories(formats_check PRIVATE ${CMAKE_SOURCE_DIR})
target_include_directories(formats_check SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
target_link_libraries(formats_check PRIVATE Arrow::arrow_shared Parquet::parquet_shared)

# One program per protocol and format, reading a capture and writing what it holds.
add_executable(json_native_iex_iexequities_deep_iextp_v1.06 executables/json/native/iex/iexequities/deep/iextp/v1.06/main.cpp)
target_include_directories(json_native_iex_iexequities_deep_iextp_v1.06 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_iex_iexequities_deep_iextp_v1.06 PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_iex_iexequities_deep_iextp_v1.06 executables/json/rapid/iex/iexequities/deep/iextp/v1.06/main.cpp)
target_include_directories(json_rapid_iex_iexequities_deep_iextp_v1.06 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_iex_iexequities_deep_iextp_v1.06 PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_iex_iexequities_deep_iextp_v1.06 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_iex_iexequities_deep_iextp_v1.06 executables/parquet/wide/iex/iexequities/deep/iextp/v1.06/main.cpp)
target_include_directories(parquet_wide_iex_iexequities_deep_iextp_v1.06 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_iex_iexequities_deep_iextp_v1.06 PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_iex_iexequities_deep_iextp_v1.06 PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_iex_iexequities_deep_iextp_v1.08 executables/json/native/iex/iexequities/deep/iextp/v1.08/main.cpp)
target_include_directories(json_native_iex_iexequities_deep_iextp_v1.08 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_iex_iexequities_deep_iextp_v1.08 PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_iex_iexequities_deep_iextp_v1.08 executables/json/rapid/iex/iexequities/deep/iextp/v1.08/main.cpp)
target_include_directories(json_rapid_iex_iexequities_deep_iextp_v1.08 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_iex_iexequities_deep_iextp_v1.08 PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_iex_iexequities_deep_iextp_v1.08 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_iex_iexequities_deep_iextp_v1.08 executables/parquet/wide/iex/iexequities/deep/iextp/v1.08/main.cpp)
target_include_directories(parquet_wide_iex_iexequities_deep_iextp_v1.08 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_iex_iexequities_deep_iextp_v1.08 PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_iex_iexequities_deep_iextp_v1.08 PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_iex_iexequities_deepplus_iextp_v1.01 executables/json/native/iex/iexequities/deepplus/iextp/v1.01/main.cpp)
target_include_directories(json_native_iex_iexequities_deepplus_iextp_v1.01 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_iex_iexequities_deepplus_iextp_v1.01 PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_iex_iexequities_deepplus_iextp_v1.01 executables/json/rapid/iex/iexequities/deepplus/iextp/v1.01/main.cpp)
target_include_directories(json_rapid_iex_iexequities_deepplus_iextp_v1.01 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_iex_iexequities_deepplus_iextp_v1.01 PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_iex_iexequities_deepplus_iextp_v1.01 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_iex_iexequities_deepplus_iextp_v1.01 executables/parquet/wide/iex/iexequities/deepplus/iextp/v1.01/main.cpp)
target_include_directories(parquet_wide_iex_iexequities_deepplus_iextp_v1.01 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_iex_iexequities_deepplus_iextp_v1.01 PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_iex_iexequities_deepplus_iextp_v1.01 PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_iex_iexequities_deepplus_iextp_v1.04 executables/json/native/iex/iexequities/deepplus/iextp/v1.04/main.cpp)
target_include_directories(json_native_iex_iexequities_deepplus_iextp_v1.04 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_iex_iexequities_deepplus_iextp_v1.04 PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_iex_iexequities_deepplus_iextp_v1.04 executables/json/rapid/iex/iexequities/deepplus/iextp/v1.04/main.cpp)
target_include_directories(json_rapid_iex_iexequities_deepplus_iextp_v1.04 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_iex_iexequities_deepplus_iextp_v1.04 PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_iex_iexequities_deepplus_iextp_v1.04 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_iex_iexequities_deepplus_iextp_v1.04 executables/parquet/wide/iex/iexequities/deepplus/iextp/v1.04/main.cpp)
target_include_directories(parquet_wide_iex_iexequities_deepplus_iextp_v1.04 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_iex_iexequities_deepplus_iextp_v1.04 PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_iex_iexequities_deepplus_iextp_v1.04 PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_iex_iexequities_tops_iextp_v1.56 executables/json/native/iex/iexequities/tops/iextp/v1.56/main.cpp)
target_include_directories(json_native_iex_iexequities_tops_iextp_v1.56 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_iex_iexequities_tops_iextp_v1.56 PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_iex_iexequities_tops_iextp_v1.56 executables/json/rapid/iex/iexequities/tops/iextp/v1.56/main.cpp)
target_include_directories(json_rapid_iex_iexequities_tops_iextp_v1.56 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_iex_iexequities_tops_iextp_v1.56 PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_iex_iexequities_tops_iextp_v1.56 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_iex_iexequities_tops_iextp_v1.56 executables/parquet/wide/iex/iexequities/tops/iextp/v1.56/main.cpp)
target_include_directories(parquet_wide_iex_iexequities_tops_iextp_v1.56 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_iex_iexequities_tops_iextp_v1.56 PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_iex_iexequities_tops_iextp_v1.56 PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_iex_iexequities_tops_iextp_v1.64 executables/json/native/iex/iexequities/tops/iextp/v1.64/main.cpp)
target_include_directories(json_native_iex_iexequities_tops_iextp_v1.64 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_iex_iexequities_tops_iextp_v1.64 PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_iex_iexequities_tops_iextp_v1.64 executables/json/rapid/iex/iexequities/tops/iextp/v1.64/main.cpp)
target_include_directories(json_rapid_iex_iexequities_tops_iextp_v1.64 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_iex_iexequities_tops_iextp_v1.64 PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_iex_iexequities_tops_iextp_v1.64 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_iex_iexequities_tops_iextp_v1.64 executables/parquet/wide/iex/iexequities/tops/iextp/v1.64/main.cpp)
target_include_directories(parquet_wide_iex_iexequities_tops_iextp_v1.64 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_iex_iexequities_tops_iextp_v1.64 PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_iex_iexequities_tops_iextp_v1.64 PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_iex_iexequities_tops_iextp_v1.66 executables/json/native/iex/iexequities/tops/iextp/v1.66/main.cpp)
target_include_directories(json_native_iex_iexequities_tops_iextp_v1.66 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_iex_iexequities_tops_iextp_v1.66 PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_iex_iexequities_tops_iextp_v1.66 executables/json/rapid/iex/iexequities/tops/iextp/v1.66/main.cpp)
target_include_directories(json_rapid_iex_iexequities_tops_iextp_v1.66 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_iex_iexequities_tops_iextp_v1.66 PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_iex_iexequities_tops_iextp_v1.66 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_iex_iexequities_tops_iextp_v1.66 executables/parquet/wide/iex/iexequities/tops/iextp/v1.66/main.cpp)
target_include_directories(parquet_wide_iex_iexequities_tops_iextp_v1.66 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_iex_iexequities_tops_iextp_v1.66 PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_iex_iexequities_tops_iextp_v1.66 PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_nasdaq_nsmequities_aggregated_itch_v2.0 executables/json/native/nasdaq/nsmequities/aggregated/itch/v2.0/main.cpp)
target_include_directories(json_native_nasdaq_nsmequities_aggregated_itch_v2.0 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_nasdaq_nsmequities_aggregated_itch_v2.0 PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_nasdaq_nsmequities_aggregated_itch_v2.0 executables/json/rapid/nasdaq/nsmequities/aggregated/itch/v2.0/main.cpp)
target_include_directories(json_rapid_nasdaq_nsmequities_aggregated_itch_v2.0 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_nasdaq_nsmequities_aggregated_itch_v2.0 PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_nasdaq_nsmequities_aggregated_itch_v2.0 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_nasdaq_nsmequities_aggregated_itch_v2.0 executables/parquet/wide/nasdaq/nsmequities/aggregated/itch/v2.0/main.cpp)
target_include_directories(parquet_wide_nasdaq_nsmequities_aggregated_itch_v2.0 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_nasdaq_nsmequities_aggregated_itch_v2.0 PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_nasdaq_nsmequities_aggregated_itch_v2.0 PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_nasdaq_nsmequities_level2_itch_v2.0 executables/json/native/nasdaq/nsmequities/level2/itch/v2.0/main.cpp)
target_include_directories(json_native_nasdaq_nsmequities_level2_itch_v2.0 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_nasdaq_nsmequities_level2_itch_v2.0 PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_nasdaq_nsmequities_level2_itch_v2.0 executables/json/rapid/nasdaq/nsmequities/level2/itch/v2.0/main.cpp)
target_include_directories(json_rapid_nasdaq_nsmequities_level2_itch_v2.0 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_nasdaq_nsmequities_level2_itch_v2.0 PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_nasdaq_nsmequities_level2_itch_v2.0 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_nasdaq_nsmequities_level2_itch_v2.0 executables/parquet/wide/nasdaq/nsmequities/level2/itch/v2.0/main.cpp)
target_include_directories(parquet_wide_nasdaq_nsmequities_level2_itch_v2.0 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_nasdaq_nsmequities_level2_itch_v2.0 PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_nasdaq_nsmequities_level2_itch_v2.0 PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_nasdaq_nsmequities_nlsplus_itch_v4.0 executables/json/native/nasdaq/nsmequities/nlsplus/itch/v4.0/main.cpp)
target_include_directories(json_native_nasdaq_nsmequities_nlsplus_itch_v4.0 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_nasdaq_nsmequities_nlsplus_itch_v4.0 PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_nasdaq_nsmequities_nlsplus_itch_v4.0 executables/json/rapid/nasdaq/nsmequities/nlsplus/itch/v4.0/main.cpp)
target_include_directories(json_rapid_nasdaq_nsmequities_nlsplus_itch_v4.0 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_nasdaq_nsmequities_nlsplus_itch_v4.0 PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_nasdaq_nsmequities_nlsplus_itch_v4.0 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_nasdaq_nsmequities_nlsplus_itch_v4.0 executables/parquet/wide/nasdaq/nsmequities/nlsplus/itch/v4.0/main.cpp)
target_include_directories(parquet_wide_nasdaq_nsmequities_nlsplus_itch_v4.0 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_nasdaq_nsmequities_nlsplus_itch_v4.0 PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_nasdaq_nsmequities_nlsplus_itch_v4.0 PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_nasdaq_nsmequities_noiview_itch_v3.0.2017 executables/json/native/nasdaq/nsmequities/noiview/itch/v3.0.2017/main.cpp)
target_include_directories(json_native_nasdaq_nsmequities_noiview_itch_v3.0.2017 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_nasdaq_nsmequities_noiview_itch_v3.0.2017 PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_nasdaq_nsmequities_noiview_itch_v3.0.2017 executables/json/rapid/nasdaq/nsmequities/noiview/itch/v3.0.2017/main.cpp)
target_include_directories(json_rapid_nasdaq_nsmequities_noiview_itch_v3.0.2017 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_nasdaq_nsmequities_noiview_itch_v3.0.2017 PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_nasdaq_nsmequities_noiview_itch_v3.0.2017 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_nasdaq_nsmequities_noiview_itch_v3.0.2017 executables/parquet/wide/nasdaq/nsmequities/noiview/itch/v3.0.2017/main.cpp)
target_include_directories(parquet_wide_nasdaq_nsmequities_noiview_itch_v3.0.2017 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_nasdaq_nsmequities_noiview_itch_v3.0.2017 PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_nasdaq_nsmequities_noiview_itch_v3.0.2017 PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_nasdaq_nsmequities_noiview_itch_v3.0.2026 executables/json/native/nasdaq/nsmequities/noiview/itch/v3.0.2026/main.cpp)
target_include_directories(json_native_nasdaq_nsmequities_noiview_itch_v3.0.2026 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_nasdaq_nsmequities_noiview_itch_v3.0.2026 PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_nasdaq_nsmequities_noiview_itch_v3.0.2026 executables/json/rapid/nasdaq/nsmequities/noiview/itch/v3.0.2026/main.cpp)
target_include_directories(json_rapid_nasdaq_nsmequities_noiview_itch_v3.0.2026 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_nasdaq_nsmequities_noiview_itch_v3.0.2026 PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_nasdaq_nsmequities_noiview_itch_v3.0.2026 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_nasdaq_nsmequities_noiview_itch_v3.0.2026 executables/parquet/wide/nasdaq/nsmequities/noiview/itch/v3.0.2026/main.cpp)
target_include_directories(parquet_wide_nasdaq_nsmequities_noiview_itch_v3.0.2026 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_nasdaq_nsmequities_noiview_itch_v3.0.2026 PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_nasdaq_nsmequities_noiview_itch_v3.0.2026 PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_nasdaq_nsmequities_qbbo_itch_v2.1 executables/json/native/nasdaq/nsmequities/qbbo/itch/v2.1/main.cpp)
target_include_directories(json_native_nasdaq_nsmequities_qbbo_itch_v2.1 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_nasdaq_nsmequities_qbbo_itch_v2.1 PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_nasdaq_nsmequities_qbbo_itch_v2.1 executables/json/rapid/nasdaq/nsmequities/qbbo/itch/v2.1/main.cpp)
target_include_directories(json_rapid_nasdaq_nsmequities_qbbo_itch_v2.1 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_nasdaq_nsmequities_qbbo_itch_v2.1 PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_nasdaq_nsmequities_qbbo_itch_v2.1 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_nasdaq_nsmequities_qbbo_itch_v2.1 executables/parquet/wide/nasdaq/nsmequities/qbbo/itch/v2.1/main.cpp)
target_include_directories(parquet_wide_nasdaq_nsmequities_qbbo_itch_v2.1 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_nasdaq_nsmequities_qbbo_itch_v2.1 PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_nasdaq_nsmequities_qbbo_itch_v2.1 PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_nasdaq_nsmequities_totalview_itch_v4.1 executables/json/native/nasdaq/nsmequities/totalview/itch/v4.1/main.cpp)
target_include_directories(json_native_nasdaq_nsmequities_totalview_itch_v4.1 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_nasdaq_nsmequities_totalview_itch_v4.1 PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_nasdaq_nsmequities_totalview_itch_v4.1 executables/json/rapid/nasdaq/nsmequities/totalview/itch/v4.1/main.cpp)
target_include_directories(json_rapid_nasdaq_nsmequities_totalview_itch_v4.1 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_nasdaq_nsmequities_totalview_itch_v4.1 PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_nasdaq_nsmequities_totalview_itch_v4.1 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_nasdaq_nsmequities_totalview_itch_v4.1 executables/parquet/wide/nasdaq/nsmequities/totalview/itch/v4.1/main.cpp)
target_include_directories(parquet_wide_nasdaq_nsmequities_totalview_itch_v4.1 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_nasdaq_nsmequities_totalview_itch_v4.1 PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_nasdaq_nsmequities_totalview_itch_v4.1 PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2017 executables/json/native/nasdaq/nsmequities/totalview/itch/v5.0.2017/main.cpp)
target_include_directories(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2017 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2017 PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2017 executables/json/rapid/nasdaq/nsmequities/totalview/itch/v5.0.2017/main.cpp)
target_include_directories(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2017 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2017 PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2017 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2017 executables/parquet/wide/nasdaq/nsmequities/totalview/itch/v5.0.2017/main.cpp)
target_include_directories(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2017 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2017 PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2017 PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2018 executables/json/native/nasdaq/nsmequities/totalview/itch/v5.0.2018/main.cpp)
target_include_directories(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2018 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2018 PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2018 executables/json/rapid/nasdaq/nsmequities/totalview/itch/v5.0.2018/main.cpp)
target_include_directories(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2018 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2018 PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2018 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2018 executables/parquet/wide/nasdaq/nsmequities/totalview/itch/v5.0.2018/main.cpp)
target_include_directories(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2018 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2018 PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2018 PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2022 executables/json/native/nasdaq/nsmequities/totalview/itch/v5.0.2022/main.cpp)
target_include_directories(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2022 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2022 PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2022 executables/json/rapid/nasdaq/nsmequities/totalview/itch/v5.0.2022/main.cpp)
target_include_directories(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2022 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2022 PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2022 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2022 executables/parquet/wide/nasdaq/nsmequities/totalview/itch/v5.0.2022/main.cpp)
target_include_directories(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2022 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2022 PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2022 PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2023 executables/json/native/nasdaq/nsmequities/totalview/itch/v5.0.2023/main.cpp)
target_include_directories(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2023 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2023 PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2023 executables/json/rapid/nasdaq/nsmequities/totalview/itch/v5.0.2023/main.cpp)
target_include_directories(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2023 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2023 PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2023 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2023 executables/parquet/wide/nasdaq/nsmequities/totalview/itch/v5.0.2023/main.cpp)
target_include_directories(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2023 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2023 PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2023 PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2026 executables/json/native/nasdaq/nsmequities/totalview/itch/v5.0.2026/main.cpp)
target_include_directories(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2026 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2026 PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2026 executables/json/rapid/nasdaq/nsmequities/totalview/itch/v5.0.2026/main.cpp)
target_include_directories(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2026 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2026 PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2026 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2026 executables/parquet/wide/nasdaq/nsmequities/totalview/itch/v5.0.2026/main.cpp)
target_include_directories(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2026 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2026 PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2026 PRIVATE Arrow::arrow_shared Parquet::parquet_shared)

# Corpus-driven tests, built by every build so a test that does not compile fails the build.
add_executable(json_native_iex_iexequities_deep_iextp_v1.06_test tests/json/native/iex_iexequities_deep_iextp_v1.06.cpp)
target_include_directories(json_native_iex_iexequities_deep_iextp_v1.06_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_iex_iexequities_deep_iextp_v1.06_test PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_iex_iexequities_deep_iextp_v1.06_test tests/json/rapid/iex_iexequities_deep_iextp_v1.06.cpp)
target_include_directories(json_rapid_iex_iexequities_deep_iextp_v1.06_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_iex_iexequities_deep_iextp_v1.06_test PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_iex_iexequities_deep_iextp_v1.06_test SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_iex_iexequities_deep_iextp_v1.06_test tests/parquet/wide/iex_iexequities_deep_iextp_v1.06.cpp)
target_include_directories(parquet_wide_iex_iexequities_deep_iextp_v1.06_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_iex_iexequities_deep_iextp_v1.06_test PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_iex_iexequities_deep_iextp_v1.06_test PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_iex_iexequities_deep_iextp_v1.08_test tests/json/native/iex_iexequities_deep_iextp_v1.08.cpp)
target_include_directories(json_native_iex_iexequities_deep_iextp_v1.08_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_iex_iexequities_deep_iextp_v1.08_test PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_iex_iexequities_deep_iextp_v1.08_test tests/json/rapid/iex_iexequities_deep_iextp_v1.08.cpp)
target_include_directories(json_rapid_iex_iexequities_deep_iextp_v1.08_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_iex_iexequities_deep_iextp_v1.08_test PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_iex_iexequities_deep_iextp_v1.08_test SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_iex_iexequities_deep_iextp_v1.08_test tests/parquet/wide/iex_iexequities_deep_iextp_v1.08.cpp)
target_include_directories(parquet_wide_iex_iexequities_deep_iextp_v1.08_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_iex_iexequities_deep_iextp_v1.08_test PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_iex_iexequities_deep_iextp_v1.08_test PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_iex_iexequities_deepplus_iextp_v1.01_test tests/json/native/iex_iexequities_deepplus_iextp_v1.01.cpp)
target_include_directories(json_native_iex_iexequities_deepplus_iextp_v1.01_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_iex_iexequities_deepplus_iextp_v1.01_test PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_iex_iexequities_deepplus_iextp_v1.01_test tests/json/rapid/iex_iexequities_deepplus_iextp_v1.01.cpp)
target_include_directories(json_rapid_iex_iexequities_deepplus_iextp_v1.01_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_iex_iexequities_deepplus_iextp_v1.01_test PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_iex_iexequities_deepplus_iextp_v1.01_test SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_iex_iexequities_deepplus_iextp_v1.01_test tests/parquet/wide/iex_iexequities_deepplus_iextp_v1.01.cpp)
target_include_directories(parquet_wide_iex_iexequities_deepplus_iextp_v1.01_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_iex_iexequities_deepplus_iextp_v1.01_test PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_iex_iexequities_deepplus_iextp_v1.01_test PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_iex_iexequities_deepplus_iextp_v1.04_test tests/json/native/iex_iexequities_deepplus_iextp_v1.04.cpp)
target_include_directories(json_native_iex_iexequities_deepplus_iextp_v1.04_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_iex_iexequities_deepplus_iextp_v1.04_test PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_iex_iexequities_deepplus_iextp_v1.04_test tests/json/rapid/iex_iexequities_deepplus_iextp_v1.04.cpp)
target_include_directories(json_rapid_iex_iexequities_deepplus_iextp_v1.04_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_iex_iexequities_deepplus_iextp_v1.04_test PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_iex_iexequities_deepplus_iextp_v1.04_test SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_iex_iexequities_deepplus_iextp_v1.04_test tests/parquet/wide/iex_iexequities_deepplus_iextp_v1.04.cpp)
target_include_directories(parquet_wide_iex_iexequities_deepplus_iextp_v1.04_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_iex_iexequities_deepplus_iextp_v1.04_test PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_iex_iexequities_deepplus_iextp_v1.04_test PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_iex_iexequities_tops_iextp_v1.64_test tests/json/native/iex_iexequities_tops_iextp_v1.64.cpp)
target_include_directories(json_native_iex_iexequities_tops_iextp_v1.64_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_iex_iexequities_tops_iextp_v1.64_test PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_iex_iexequities_tops_iextp_v1.64_test tests/json/rapid/iex_iexequities_tops_iextp_v1.64.cpp)
target_include_directories(json_rapid_iex_iexequities_tops_iextp_v1.64_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_iex_iexequities_tops_iextp_v1.64_test PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_iex_iexequities_tops_iextp_v1.64_test SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_iex_iexequities_tops_iextp_v1.64_test tests/parquet/wide/iex_iexequities_tops_iextp_v1.64.cpp)
target_include_directories(parquet_wide_iex_iexequities_tops_iextp_v1.64_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_iex_iexequities_tops_iextp_v1.64_test PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_iex_iexequities_tops_iextp_v1.64_test PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_iex_iexequities_tops_iextp_v1.66_test tests/json/native/iex_iexequities_tops_iextp_v1.66.cpp)
target_include_directories(json_native_iex_iexequities_tops_iextp_v1.66_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_iex_iexequities_tops_iextp_v1.66_test PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_iex_iexequities_tops_iextp_v1.66_test tests/json/rapid/iex_iexequities_tops_iextp_v1.66.cpp)
target_include_directories(json_rapid_iex_iexequities_tops_iextp_v1.66_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_iex_iexequities_tops_iextp_v1.66_test PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_iex_iexequities_tops_iextp_v1.66_test SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_iex_iexequities_tops_iextp_v1.66_test tests/parquet/wide/iex_iexequities_tops_iextp_v1.66.cpp)
target_include_directories(parquet_wide_iex_iexequities_tops_iextp_v1.66_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_iex_iexequities_tops_iextp_v1.66_test PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_iex_iexequities_tops_iextp_v1.66_test PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2017_test tests/json/native/nasdaq_nsmequities_totalview_itch_v5.0.2017.cpp)
target_include_directories(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2017_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2017_test PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2017_test tests/json/rapid/nasdaq_nsmequities_totalview_itch_v5.0.2017.cpp)
target_include_directories(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2017_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2017_test PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2017_test SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2017_test tests/parquet/wide/nasdaq_nsmequities_totalview_itch_v5.0.2017.cpp)
target_include_directories(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2017_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2017_test PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2017_test PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2018_test tests/json/native/nasdaq_nsmequities_totalview_itch_v5.0.2018.cpp)
target_include_directories(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2018_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2018_test PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2018_test tests/json/rapid/nasdaq_nsmequities_totalview_itch_v5.0.2018.cpp)
target_include_directories(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2018_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2018_test PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2018_test SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2018_test tests/parquet/wide/nasdaq_nsmequities_totalview_itch_v5.0.2018.cpp)
target_include_directories(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2018_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2018_test PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2018_test PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2022_test tests/json/native/nasdaq_nsmequities_totalview_itch_v5.0.2022.cpp)
target_include_directories(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2022_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2022_test PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2022_test tests/json/rapid/nasdaq_nsmequities_totalview_itch_v5.0.2022.cpp)
target_include_directories(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2022_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2022_test PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2022_test SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2022_test tests/parquet/wide/nasdaq_nsmequities_totalview_itch_v5.0.2022.cpp)
target_include_directories(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2022_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2022_test PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2022_test PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2023_test tests/json/native/nasdaq_nsmequities_totalview_itch_v5.0.2023.cpp)
target_include_directories(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2023_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2023_test PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2023_test tests/json/rapid/nasdaq_nsmequities_totalview_itch_v5.0.2023.cpp)
target_include_directories(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2023_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2023_test PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2023_test SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2023_test tests/parquet/wide/nasdaq_nsmequities_totalview_itch_v5.0.2023.cpp)
target_include_directories(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2023_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2023_test PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2023_test PRIVATE Arrow::arrow_shared Parquet::parquet_shared)
add_executable(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2026_test tests/json/native/nasdaq_nsmequities_totalview_itch_v5.0.2026.cpp)
target_include_directories(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2026_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2026_test PRIVATE ${ZSTD_LIBRARY})
add_executable(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2026_test tests/json/rapid/nasdaq_nsmequities_totalview_itch_v5.0.2026.cpp)
target_include_directories(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2026_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2026_test PRIVATE ${ZSTD_LIBRARY})
target_include_directories(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2026_test SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2026_test tests/parquet/wide/nasdaq_nsmequities_totalview_itch_v5.0.2026.cpp)
target_include_directories(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2026_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap ${ZSTD_INCLUDE_DIR})
target_link_libraries(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2026_test PRIVATE ${ZSTD_LIBRARY})
target_link_libraries(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2026_test PRIVATE Arrow::arrow_shared Parquet::parquet_shared)

# Running them reads the captures each protocol declares, from an omi-data-pcaps checkout:
#
#   git clone --depth=1 https://github.com/Open-Markets-Initiative/omi-data-pcaps.git
#   cmake -S . -B build -DOMI_PACKETS_DIR=omi-data-pcaps
#   cmake --build build --parallel $(nproc) && ctest --test-dir build
set(OMI_PACKETS_DIR "" CACHE PATH "omi-data-pcaps checkout holding the captures")

if(OMI_PACKETS_DIR)
  enable_testing()

  add_test(NAME json_native_iex_iexequities_deep_iextp_v1.06 COMMAND json_native_iex_iexequities_deep_iextp_v1.06_test)
  set_tests_properties(json_native_iex_iexequities_deep_iextp_v1.06 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_rapid_iex_iexequities_deep_iextp_v1.06 COMMAND json_rapid_iex_iexequities_deep_iextp_v1.06_test)
  set_tests_properties(json_rapid_iex_iexequities_deep_iextp_v1.06 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME parquet_wide_iex_iexequities_deep_iextp_v1.06 COMMAND parquet_wide_iex_iexequities_deep_iextp_v1.06_test)
  set_tests_properties(parquet_wide_iex_iexequities_deep_iextp_v1.06 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_native_iex_iexequities_deep_iextp_v1.08 COMMAND json_native_iex_iexequities_deep_iextp_v1.08_test)
  set_tests_properties(json_native_iex_iexequities_deep_iextp_v1.08 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_rapid_iex_iexequities_deep_iextp_v1.08 COMMAND json_rapid_iex_iexequities_deep_iextp_v1.08_test)
  set_tests_properties(json_rapid_iex_iexequities_deep_iextp_v1.08 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME parquet_wide_iex_iexequities_deep_iextp_v1.08 COMMAND parquet_wide_iex_iexequities_deep_iextp_v1.08_test)
  set_tests_properties(parquet_wide_iex_iexequities_deep_iextp_v1.08 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_native_iex_iexequities_deepplus_iextp_v1.01 COMMAND json_native_iex_iexequities_deepplus_iextp_v1.01_test)
  set_tests_properties(json_native_iex_iexequities_deepplus_iextp_v1.01 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_rapid_iex_iexequities_deepplus_iextp_v1.01 COMMAND json_rapid_iex_iexequities_deepplus_iextp_v1.01_test)
  set_tests_properties(json_rapid_iex_iexequities_deepplus_iextp_v1.01 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME parquet_wide_iex_iexequities_deepplus_iextp_v1.01 COMMAND parquet_wide_iex_iexequities_deepplus_iextp_v1.01_test)
  set_tests_properties(parquet_wide_iex_iexequities_deepplus_iextp_v1.01 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_native_iex_iexequities_deepplus_iextp_v1.04 COMMAND json_native_iex_iexequities_deepplus_iextp_v1.04_test)
  set_tests_properties(json_native_iex_iexequities_deepplus_iextp_v1.04 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_rapid_iex_iexequities_deepplus_iextp_v1.04 COMMAND json_rapid_iex_iexequities_deepplus_iextp_v1.04_test)
  set_tests_properties(json_rapid_iex_iexequities_deepplus_iextp_v1.04 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME parquet_wide_iex_iexequities_deepplus_iextp_v1.04 COMMAND parquet_wide_iex_iexequities_deepplus_iextp_v1.04_test)
  set_tests_properties(parquet_wide_iex_iexequities_deepplus_iextp_v1.04 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_native_iex_iexequities_tops_iextp_v1.64 COMMAND json_native_iex_iexequities_tops_iextp_v1.64_test)
  set_tests_properties(json_native_iex_iexequities_tops_iextp_v1.64 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_rapid_iex_iexequities_tops_iextp_v1.64 COMMAND json_rapid_iex_iexequities_tops_iextp_v1.64_test)
  set_tests_properties(json_rapid_iex_iexequities_tops_iextp_v1.64 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME parquet_wide_iex_iexequities_tops_iextp_v1.64 COMMAND parquet_wide_iex_iexequities_tops_iextp_v1.64_test)
  set_tests_properties(parquet_wide_iex_iexequities_tops_iextp_v1.64 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_native_iex_iexequities_tops_iextp_v1.66 COMMAND json_native_iex_iexequities_tops_iextp_v1.66_test)
  set_tests_properties(json_native_iex_iexequities_tops_iextp_v1.66 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_rapid_iex_iexequities_tops_iextp_v1.66 COMMAND json_rapid_iex_iexequities_tops_iextp_v1.66_test)
  set_tests_properties(json_rapid_iex_iexequities_tops_iextp_v1.66 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME parquet_wide_iex_iexequities_tops_iextp_v1.66 COMMAND parquet_wide_iex_iexequities_tops_iextp_v1.66_test)
  set_tests_properties(parquet_wide_iex_iexequities_tops_iextp_v1.66 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_native_nasdaq_nsmequities_totalview_itch_v5.0.2017 COMMAND json_native_nasdaq_nsmequities_totalview_itch_v5.0.2017_test)
  set_tests_properties(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2017 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2017 COMMAND json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2017_test)
  set_tests_properties(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2017 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2017 COMMAND parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2017_test)
  set_tests_properties(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2017 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_native_nasdaq_nsmequities_totalview_itch_v5.0.2018 COMMAND json_native_nasdaq_nsmequities_totalview_itch_v5.0.2018_test)
  set_tests_properties(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2018 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2018 COMMAND json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2018_test)
  set_tests_properties(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2018 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2018 COMMAND parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2018_test)
  set_tests_properties(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2018 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_native_nasdaq_nsmequities_totalview_itch_v5.0.2022 COMMAND json_native_nasdaq_nsmequities_totalview_itch_v5.0.2022_test)
  set_tests_properties(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2022 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2022 COMMAND json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2022_test)
  set_tests_properties(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2022 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2022 COMMAND parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2022_test)
  set_tests_properties(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2022 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_native_nasdaq_nsmequities_totalview_itch_v5.0.2023 COMMAND json_native_nasdaq_nsmequities_totalview_itch_v5.0.2023_test)
  set_tests_properties(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2023 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2023 COMMAND json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2023_test)
  set_tests_properties(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2023 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2023 COMMAND parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2023_test)
  set_tests_properties(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2023 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_native_nasdaq_nsmequities_totalview_itch_v5.0.2026 COMMAND json_native_nasdaq_nsmequities_totalview_itch_v5.0.2026_test)
  set_tests_properties(json_native_nasdaq_nsmequities_totalview_itch_v5.0.2026 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2026 COMMAND json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2026_test)
  set_tests_properties(json_rapid_nasdaq_nsmequities_totalview_itch_v5.0.2026 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2026 COMMAND parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2026_test)
  set_tests_properties(parquet_wide_nasdaq_nsmequities_totalview_itch_v5.0.2026 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")
endif()
