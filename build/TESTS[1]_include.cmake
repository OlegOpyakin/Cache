if(EXISTS "/Users/oleg/Desktop/Новая папка/build/TESTS[1]_tests.cmake")
  include("/Users/oleg/Desktop/Новая папка/build/TESTS[1]_tests.cmake")
else()
  add_test(TESTS_NOT_BUILT TESTS_NOT_BUILT)
endif()
