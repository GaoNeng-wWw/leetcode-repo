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

  # 改进点：使用 $<TARGET_FILE:${test_name}> 
  # 这会让 CMake 自动填充可执行文件的绝对路径（包括 .exe 后缀）
  add_test(NAME ${test_name} COMMAND $<TARGET_FILE:${test_name}>)
endforeach()