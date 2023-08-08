include_directories(/include ${TempConv_SOURCE_DIR}/src)

set(CUKE_CORE_BOOST_LIBS thread system regex date_time program_options filesystem)
find_package(Boost ${BOOST_MIN_VERSION} COMPONENTS ${CUKE_CORE_BOOST_LIBS} REQUIRED)

add_executable(
  tempconv-steps
  step_definitions/tempconv_steps.cc
)

target_link_libraries(
  tempconv-steps
  TempConv
  cucumber-cpp
  Boost::boost
  Boost::thread
  Boost::system
  Boost::regex
  Boost::date_time
  Boost::program_options
  Boost::filesystem
  GTest::gtest_main
  GTest::gmock_main
)