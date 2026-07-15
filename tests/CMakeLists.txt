file(GLOB TEST_FILES "*.cc" "*.cpp")

foreach(test_file ${TEST_FILES})
  get_filename_component(test_name ${test_file} NAME_WE)
  
  add_executable(${test_name} ${test_file})
  
  target_link_libraries(${test_name} 
      PRIVATE 
          lc
          gtest 
          gtest_main
  )
  add_test(NAME ${test_name} COMMAND $<TARGET_FILE:${test_name}>)
endforeach()