add_executable(detect main.cpp DataLoader.cpp TrainSVM.cpp VisionInput.cpp DetectHuman.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}	
)
target_link_libraries (detect ${OpenCV_LIBS})

