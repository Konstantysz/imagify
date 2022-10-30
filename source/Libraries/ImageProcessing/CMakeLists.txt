find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

file(GLOB ImageProcessingSource
    "*.h"
    "*.cpp"
)

add_library(ImageProcessing ${ImageProcessingSource})

target_link_libraries(ImageProcessing PRIVATE ${OpenCV_LIBS})