file(GLOB CoreSource
    "*.h"
    "*.cpp"
)

include_directories(${OpenCV_INCLUDE_DIRS})

add_library(Core ${CoreSource})

target_link_libraries(Core PUBLIC ${OpenCV_LIBS})

set_target_properties(Core PROPERTIES FOLDER Libraries)

enable_testing()