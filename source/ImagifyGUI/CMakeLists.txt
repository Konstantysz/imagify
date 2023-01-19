file(GLOB ImagifyGUISource 
"*.h" 
"*.cpp"
"bindings/imgui_impl_glfw.cpp"
"bindings/imgui_impl_opengl2.cpp"
"bindings/imgui_impl_glfw.h"
"bindings/imgui_impl_opengl2.h"
)

add_executable(ImagifyGUI ${ImagifyGUISource})
target_link_libraries(ImagifyGUI imgui)
target_link_libraries(ImagifyGUI OpenCV)