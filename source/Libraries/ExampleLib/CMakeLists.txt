find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

file(GLOB ExampleLibSource
    "*.h"
    "*.cpp"
)

add_library(ExampleLib ${ExampleLibSource})

target_link_libraries(ExampleLib PRIVATE ${OpenCV_LIBS})

set_target_properties(ExampleLib PROPERTIES FOLDER Libraries)

enable_testing()