add_subdirectory(ImagifyGUI)
add_subdirectory(Libraries)
add_subdirectory(Plugins)
add_subdirectory(Tests)
add_subdirectory(ThirdParty)

set_target_properties(Core PROPERTIES FOLDER Libraries)

set_target_properties(TestCore PROPERTIES FOLDER Tests)

set_target_properties(gmock PROPERTIES FOLDER Thirdparty/googletest)
set_target_properties(gmock_main PROPERTIES FOLDER Thirdparty/googletest)
set_target_properties(gtest PROPERTIES FOLDER Thirdparty/googletest)
set_target_properties(gtest_main PROPERTIES FOLDER Thirdparty/googletest)