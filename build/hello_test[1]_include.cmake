if(EXISTS "/Users/oleg/Desktop/Новая папка/build/hello_test[1]_tests.cmake")
  include("/Users/oleg/Desktop/Новая папка/build/hello_test[1]_tests.cmake")
else()
  add_test(hello_test_NOT_BUILT hello_test_NOT_BUILT)
endif()
