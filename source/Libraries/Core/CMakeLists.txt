find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

file(GLOB CoreSource
    "*.h"
    "*.cpp"
)

add_library(Core ${CoreSource})

target_link_libraries(Core PRIVATE ${OpenCV_LIBS})

enable_testing()
