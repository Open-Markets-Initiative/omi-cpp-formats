cmake_minimum_required(VERSION 3.20)
project(omi_cpp_formats CXX)

# The parsers and writers use C++23; a C++23 compiler (GCC 14+) is required.
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# RapidJSON is header only; its package (rapidjson-dev on Ubuntu) provides the include directory.
# It is included as a system directory, so its own warnings are not reported against these sources.
find_package(RapidJSON REQUIRED)

# Each translation unit under checks/ includes a protocol's writers in one format, so compiling it
# compiles the writers and the Advanced layout assertions they include. A clean build is the gate.
add_library(formats_check OBJECT
  checks/iex_iexequities_deep_iextp_v1.06_json_native.cpp
  checks/iex_iexequities_deep_iextp_v1.06_json_rapid.cpp
  checks/iex_iexequities_deep_iextp_v1.08_json_native.cpp
  checks/iex_iexequities_deep_iextp_v1.08_json_rapid.cpp
  checks/iex_iexequities_deepplus_iextp_v1.01_json_native.cpp
  checks/iex_iexequities_deepplus_iextp_v1.01_json_rapid.cpp
  checks/iex_iexequities_deepplus_iextp_v1.04_json_native.cpp
  checks/iex_iexequities_deepplus_iextp_v1.04_json_rapid.cpp
  checks/iex_iexequities_tops_iextp_v1.56_json_native.cpp
  checks/iex_iexequities_tops_iextp_v1.56_json_rapid.cpp
  checks/iex_iexequities_tops_iextp_v1.64_json_native.cpp
  checks/iex_iexequities_tops_iextp_v1.64_json_rapid.cpp
  checks/iex_iexequities_tops_iextp_v1.66_json_native.cpp
  checks/iex_iexequities_tops_iextp_v1.66_json_rapid.cpp
)
target_include_directories(formats_check PRIVATE ${CMAKE_SOURCE_DIR})
target_include_directories(formats_check SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})

# JSON programs under executables/json/<format>/ — one per protocol and format, reading a capture and
# writing each message as one line of JSON.
add_executable(json_native_iex_iexequities_deep_iextp_v1.06 executables/json/native/iex/iexequities/deep/iextp/v1.06/main.cpp)
target_include_directories(json_native_iex_iexequities_deep_iextp_v1.06 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
add_executable(json_rapid_iex_iexequities_deep_iextp_v1.06 executables/json/rapid/iex/iexequities/deep/iextp/v1.06/main.cpp)
target_include_directories(json_rapid_iex_iexequities_deep_iextp_v1.06 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
target_include_directories(json_rapid_iex_iexequities_deep_iextp_v1.06 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(json_native_iex_iexequities_deep_iextp_v1.08 executables/json/native/iex/iexequities/deep/iextp/v1.08/main.cpp)
target_include_directories(json_native_iex_iexequities_deep_iextp_v1.08 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
add_executable(json_rapid_iex_iexequities_deep_iextp_v1.08 executables/json/rapid/iex/iexequities/deep/iextp/v1.08/main.cpp)
target_include_directories(json_rapid_iex_iexequities_deep_iextp_v1.08 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
target_include_directories(json_rapid_iex_iexequities_deep_iextp_v1.08 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(json_native_iex_iexequities_deepplus_iextp_v1.01 executables/json/native/iex/iexequities/deepplus/iextp/v1.01/main.cpp)
target_include_directories(json_native_iex_iexequities_deepplus_iextp_v1.01 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
add_executable(json_rapid_iex_iexequities_deepplus_iextp_v1.01 executables/json/rapid/iex/iexequities/deepplus/iextp/v1.01/main.cpp)
target_include_directories(json_rapid_iex_iexequities_deepplus_iextp_v1.01 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
target_include_directories(json_rapid_iex_iexequities_deepplus_iextp_v1.01 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(json_native_iex_iexequities_deepplus_iextp_v1.04 executables/json/native/iex/iexequities/deepplus/iextp/v1.04/main.cpp)
target_include_directories(json_native_iex_iexequities_deepplus_iextp_v1.04 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
add_executable(json_rapid_iex_iexequities_deepplus_iextp_v1.04 executables/json/rapid/iex/iexequities/deepplus/iextp/v1.04/main.cpp)
target_include_directories(json_rapid_iex_iexequities_deepplus_iextp_v1.04 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
target_include_directories(json_rapid_iex_iexequities_deepplus_iextp_v1.04 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(json_native_iex_iexequities_tops_iextp_v1.56 executables/json/native/iex/iexequities/tops/iextp/v1.56/main.cpp)
target_include_directories(json_native_iex_iexequities_tops_iextp_v1.56 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
add_executable(json_rapid_iex_iexequities_tops_iextp_v1.56 executables/json/rapid/iex/iexequities/tops/iextp/v1.56/main.cpp)
target_include_directories(json_rapid_iex_iexequities_tops_iextp_v1.56 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
target_include_directories(json_rapid_iex_iexequities_tops_iextp_v1.56 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(json_native_iex_iexequities_tops_iextp_v1.64 executables/json/native/iex/iexequities/tops/iextp/v1.64/main.cpp)
target_include_directories(json_native_iex_iexequities_tops_iextp_v1.64 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
add_executable(json_rapid_iex_iexequities_tops_iextp_v1.64 executables/json/rapid/iex/iexequities/tops/iextp/v1.64/main.cpp)
target_include_directories(json_rapid_iex_iexequities_tops_iextp_v1.64 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
target_include_directories(json_rapid_iex_iexequities_tops_iextp_v1.64 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(json_native_iex_iexequities_tops_iextp_v1.66 executables/json/native/iex/iexequities/tops/iextp/v1.66/main.cpp)
target_include_directories(json_native_iex_iexequities_tops_iextp_v1.66 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
add_executable(json_rapid_iex_iexequities_tops_iextp_v1.66 executables/json/rapid/iex/iexequities/tops/iextp/v1.66/main.cpp)
target_include_directories(json_rapid_iex_iexequities_tops_iextp_v1.66 PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
target_include_directories(json_rapid_iex_iexequities_tops_iextp_v1.66 SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})

# Corpus-driven tests, built by every build so a test that does not compile fails the build.
add_executable(json_native_iex_iexequities_deep_iextp_v1.06_test tests/json/native/iex_iexequities_deep_iextp_v1.06.cpp)
target_include_directories(json_native_iex_iexequities_deep_iextp_v1.06_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
add_executable(json_rapid_iex_iexequities_deep_iextp_v1.06_test tests/json/rapid/iex_iexequities_deep_iextp_v1.06.cpp)
target_include_directories(json_rapid_iex_iexequities_deep_iextp_v1.06_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
target_include_directories(json_rapid_iex_iexequities_deep_iextp_v1.06_test SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(json_native_iex_iexequities_deep_iextp_v1.08_test tests/json/native/iex_iexequities_deep_iextp_v1.08.cpp)
target_include_directories(json_native_iex_iexequities_deep_iextp_v1.08_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
add_executable(json_rapid_iex_iexequities_deep_iextp_v1.08_test tests/json/rapid/iex_iexequities_deep_iextp_v1.08.cpp)
target_include_directories(json_rapid_iex_iexequities_deep_iextp_v1.08_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
target_include_directories(json_rapid_iex_iexequities_deep_iextp_v1.08_test SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(json_native_iex_iexequities_deepplus_iextp_v1.01_test tests/json/native/iex_iexequities_deepplus_iextp_v1.01.cpp)
target_include_directories(json_native_iex_iexequities_deepplus_iextp_v1.01_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
add_executable(json_rapid_iex_iexequities_deepplus_iextp_v1.01_test tests/json/rapid/iex_iexequities_deepplus_iextp_v1.01.cpp)
target_include_directories(json_rapid_iex_iexequities_deepplus_iextp_v1.01_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
target_include_directories(json_rapid_iex_iexequities_deepplus_iextp_v1.01_test SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(json_native_iex_iexequities_deepplus_iextp_v1.04_test tests/json/native/iex_iexequities_deepplus_iextp_v1.04.cpp)
target_include_directories(json_native_iex_iexequities_deepplus_iextp_v1.04_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
add_executable(json_rapid_iex_iexequities_deepplus_iextp_v1.04_test tests/json/rapid/iex_iexequities_deepplus_iextp_v1.04.cpp)
target_include_directories(json_rapid_iex_iexequities_deepplus_iextp_v1.04_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
target_include_directories(json_rapid_iex_iexequities_deepplus_iextp_v1.04_test SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(json_native_iex_iexequities_tops_iextp_v1.56_test tests/json/native/iex_iexequities_tops_iextp_v1.56.cpp)
target_include_directories(json_native_iex_iexequities_tops_iextp_v1.56_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
add_executable(json_rapid_iex_iexequities_tops_iextp_v1.56_test tests/json/rapid/iex_iexequities_tops_iextp_v1.56.cpp)
target_include_directories(json_rapid_iex_iexequities_tops_iextp_v1.56_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
target_include_directories(json_rapid_iex_iexequities_tops_iextp_v1.56_test SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(json_native_iex_iexequities_tops_iextp_v1.64_test tests/json/native/iex_iexequities_tops_iextp_v1.64.cpp)
target_include_directories(json_native_iex_iexequities_tops_iextp_v1.64_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
add_executable(json_rapid_iex_iexequities_tops_iextp_v1.64_test tests/json/rapid/iex_iexequities_tops_iextp_v1.64.cpp)
target_include_directories(json_rapid_iex_iexequities_tops_iextp_v1.64_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
target_include_directories(json_rapid_iex_iexequities_tops_iextp_v1.64_test SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
add_executable(json_native_iex_iexequities_tops_iextp_v1.66_test tests/json/native/iex_iexequities_tops_iextp_v1.66.cpp)
target_include_directories(json_native_iex_iexequities_tops_iextp_v1.66_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
add_executable(json_rapid_iex_iexequities_tops_iextp_v1.66_test tests/json/rapid/iex_iexequities_tops_iextp_v1.66.cpp)
target_include_directories(json_rapid_iex_iexequities_tops_iextp_v1.66_test PRIVATE ${CMAKE_SOURCE_DIR} executables/pcap)
target_include_directories(json_rapid_iex_iexequities_tops_iextp_v1.66_test SYSTEM PRIVATE ${RAPIDJSON_INCLUDE_DIRS})

# Running them reads the captures each protocol declares. Point OMI_PACKETS_DIR at the corpus checkout:
#
#   cmake -S . -B build -DOMI_PACKETS_DIR=/path/to/packets
#   cmake --build build --parallel $(nproc) && ctest --test-dir build
set(OMI_PACKETS_DIR "" CACHE PATH "Packet corpus checkout holding the capture samples")

if(OMI_PACKETS_DIR)
  enable_testing()

  add_test(NAME json_native_iex_iexequities_deep_iextp_v1.06 COMMAND json_native_iex_iexequities_deep_iextp_v1.06_test)
  set_tests_properties(json_native_iex_iexequities_deep_iextp_v1.06 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_rapid_iex_iexequities_deep_iextp_v1.06 COMMAND json_rapid_iex_iexequities_deep_iextp_v1.06_test)
  set_tests_properties(json_rapid_iex_iexequities_deep_iextp_v1.06 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_native_iex_iexequities_deep_iextp_v1.08 COMMAND json_native_iex_iexequities_deep_iextp_v1.08_test)
  set_tests_properties(json_native_iex_iexequities_deep_iextp_v1.08 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_rapid_iex_iexequities_deep_iextp_v1.08 COMMAND json_rapid_iex_iexequities_deep_iextp_v1.08_test)
  set_tests_properties(json_rapid_iex_iexequities_deep_iextp_v1.08 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_native_iex_iexequities_deepplus_iextp_v1.01 COMMAND json_native_iex_iexequities_deepplus_iextp_v1.01_test)
  set_tests_properties(json_native_iex_iexequities_deepplus_iextp_v1.01 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_rapid_iex_iexequities_deepplus_iextp_v1.01 COMMAND json_rapid_iex_iexequities_deepplus_iextp_v1.01_test)
  set_tests_properties(json_rapid_iex_iexequities_deepplus_iextp_v1.01 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_native_iex_iexequities_deepplus_iextp_v1.04 COMMAND json_native_iex_iexequities_deepplus_iextp_v1.04_test)
  set_tests_properties(json_native_iex_iexequities_deepplus_iextp_v1.04 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_rapid_iex_iexequities_deepplus_iextp_v1.04 COMMAND json_rapid_iex_iexequities_deepplus_iextp_v1.04_test)
  set_tests_properties(json_rapid_iex_iexequities_deepplus_iextp_v1.04 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_native_iex_iexequities_tops_iextp_v1.56 COMMAND json_native_iex_iexequities_tops_iextp_v1.56_test)
  set_tests_properties(json_native_iex_iexequities_tops_iextp_v1.56 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_rapid_iex_iexequities_tops_iextp_v1.56 COMMAND json_rapid_iex_iexequities_tops_iextp_v1.56_test)
  set_tests_properties(json_rapid_iex_iexequities_tops_iextp_v1.56 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_native_iex_iexequities_tops_iextp_v1.64 COMMAND json_native_iex_iexequities_tops_iextp_v1.64_test)
  set_tests_properties(json_native_iex_iexequities_tops_iextp_v1.64 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_rapid_iex_iexequities_tops_iextp_v1.64 COMMAND json_rapid_iex_iexequities_tops_iextp_v1.64_test)
  set_tests_properties(json_rapid_iex_iexequities_tops_iextp_v1.64 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_native_iex_iexequities_tops_iextp_v1.66 COMMAND json_native_iex_iexequities_tops_iextp_v1.66_test)
  set_tests_properties(json_native_iex_iexequities_tops_iextp_v1.66 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_rapid_iex_iexequities_tops_iextp_v1.66 COMMAND json_rapid_iex_iexequities_tops_iextp_v1.66_test)
  set_tests_properties(json_rapid_iex_iexequities_tops_iextp_v1.66 PROPERTIES ENVIRONMENT "OMI_PACKETS_DIR=${OMI_PACKETS_DIR}")

  add_test(NAME json_native_iex_iexequities_deep_iextp_v1.06_run COMMAND json_native_iex_iexequities_deep_iextp_v1.06 ${OMI_PACKETS_DIR}/Iex/IexEquities.Deep.IexTp.v1.06/AuctionInformationMessage.pcap)
  set_tests_properties(json_native_iex_iexequities_deep_iextp_v1.06_run PROPERTIES PASS_REGULAR_EXPRESSION "\"message\":\"AuctionInformationMessage\"")

  add_test(NAME json_rapid_iex_iexequities_deep_iextp_v1.06_run COMMAND json_rapid_iex_iexequities_deep_iextp_v1.06 ${OMI_PACKETS_DIR}/Iex/IexEquities.Deep.IexTp.v1.06/AuctionInformationMessage.pcap)
  set_tests_properties(json_rapid_iex_iexequities_deep_iextp_v1.06_run PROPERTIES PASS_REGULAR_EXPRESSION "\"message\":\"AuctionInformationMessage\"")

  add_test(NAME json_native_iex_iexequities_deep_iextp_v1.08_run COMMAND json_native_iex_iexequities_deep_iextp_v1.08 ${OMI_PACKETS_DIR}/Iex/IexEquities.Deep.IexTp.v1.08/AuctionInformationMessage.pcap)
  set_tests_properties(json_native_iex_iexequities_deep_iextp_v1.08_run PROPERTIES PASS_REGULAR_EXPRESSION "\"message\":\"AuctionInformationMessage\"")

  add_test(NAME json_rapid_iex_iexequities_deep_iextp_v1.08_run COMMAND json_rapid_iex_iexequities_deep_iextp_v1.08 ${OMI_PACKETS_DIR}/Iex/IexEquities.Deep.IexTp.v1.08/AuctionInformationMessage.pcap)
  set_tests_properties(json_rapid_iex_iexequities_deep_iextp_v1.08_run PROPERTIES PASS_REGULAR_EXPRESSION "\"message\":\"AuctionInformationMessage\"")

  add_test(NAME json_native_iex_iexequities_deepplus_iextp_v1.01_run COMMAND json_native_iex_iexequities_deepplus_iextp_v1.01 ${OMI_PACKETS_DIR}/Iex/IexEquities.DeepPlus.IexTp.v1.01/B_TradeBreak.pcap)
  set_tests_properties(json_native_iex_iexequities_deepplus_iextp_v1.01_run PROPERTIES PASS_REGULAR_EXPRESSION "\"message\":\"TradeBreakMessage\"")

  add_test(NAME json_rapid_iex_iexequities_deepplus_iextp_v1.01_run COMMAND json_rapid_iex_iexequities_deepplus_iextp_v1.01 ${OMI_PACKETS_DIR}/Iex/IexEquities.DeepPlus.IexTp.v1.01/B_TradeBreak.pcap)
  set_tests_properties(json_rapid_iex_iexequities_deepplus_iextp_v1.01_run PROPERTIES PASS_REGULAR_EXPRESSION "\"message\":\"TradeBreakMessage\"")

  add_test(NAME json_native_iex_iexequities_deepplus_iextp_v1.04_run COMMAND json_native_iex_iexequities_deepplus_iextp_v1.04 ${OMI_PACKETS_DIR}/Iex/IexEquities.DeepPlus.IexTp.v1.04/AddOrderMessage.pcap)
  set_tests_properties(json_native_iex_iexequities_deepplus_iextp_v1.04_run PROPERTIES PASS_REGULAR_EXPRESSION "\"message\":\"AddOrderMessage\"")

  add_test(NAME json_rapid_iex_iexequities_deepplus_iextp_v1.04_run COMMAND json_rapid_iex_iexequities_deepplus_iextp_v1.04 ${OMI_PACKETS_DIR}/Iex/IexEquities.DeepPlus.IexTp.v1.04/AddOrderMessage.pcap)
  set_tests_properties(json_rapid_iex_iexequities_deepplus_iextp_v1.04_run PROPERTIES PASS_REGULAR_EXPRESSION "\"message\":\"AddOrderMessage\"")

  add_test(NAME json_native_iex_iexequities_tops_iextp_v1.56_run COMMAND json_native_iex_iexequities_tops_iextp_v1.56 ${OMI_PACKETS_DIR}/Iex/IexEquities.Tops.IexTp.v1.56/QuoteUpdateMessage.pcap)
  set_tests_properties(json_native_iex_iexequities_tops_iextp_v1.56_run PROPERTIES PASS_REGULAR_EXPRESSION "\"message\":\"QuoteUpdateMessage\"")

  add_test(NAME json_rapid_iex_iexequities_tops_iextp_v1.56_run COMMAND json_rapid_iex_iexequities_tops_iextp_v1.56 ${OMI_PACKETS_DIR}/Iex/IexEquities.Tops.IexTp.v1.56/QuoteUpdateMessage.pcap)
  set_tests_properties(json_rapid_iex_iexequities_tops_iextp_v1.56_run PROPERTIES PASS_REGULAR_EXPRESSION "\"message\":\"QuoteUpdateMessage\"")

  add_test(NAME json_native_iex_iexequities_tops_iextp_v1.64_run COMMAND json_native_iex_iexequities_tops_iextp_v1.64 ${OMI_PACKETS_DIR}/Iex/IexEquities.Tops.IexTp.v1.64/AuctionInformationMessage.pcap)
  set_tests_properties(json_native_iex_iexequities_tops_iextp_v1.64_run PROPERTIES PASS_REGULAR_EXPRESSION "\"message\":\"AuctionInformationMessage\"")

  add_test(NAME json_rapid_iex_iexequities_tops_iextp_v1.64_run COMMAND json_rapid_iex_iexequities_tops_iextp_v1.64 ${OMI_PACKETS_DIR}/Iex/IexEquities.Tops.IexTp.v1.64/AuctionInformationMessage.pcap)
  set_tests_properties(json_rapid_iex_iexequities_tops_iextp_v1.64_run PROPERTIES PASS_REGULAR_EXPRESSION "\"message\":\"AuctionInformationMessage\"")

  add_test(NAME json_native_iex_iexequities_tops_iextp_v1.66_run COMMAND json_native_iex_iexequities_tops_iextp_v1.66 ${OMI_PACKETS_DIR}/Iex/IexEquities.Tops.IexTp.v1.66/AuctionInformationMessage.pcap)
  set_tests_properties(json_native_iex_iexequities_tops_iextp_v1.66_run PROPERTIES PASS_REGULAR_EXPRESSION "\"message\":\"AuctionInformationMessage\"")

  add_test(NAME json_rapid_iex_iexequities_tops_iextp_v1.66_run COMMAND json_rapid_iex_iexequities_tops_iextp_v1.66 ${OMI_PACKETS_DIR}/Iex/IexEquities.Tops.IexTp.v1.66/AuctionInformationMessage.pcap)
  set_tests_properties(json_rapid_iex_iexequities_tops_iextp_v1.66_run PROPERTIES PASS_REGULAR_EXPRESSION "\"message\":\"AuctionInformationMessage\"")
endif()
