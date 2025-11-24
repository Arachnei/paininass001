cmake_minimum_required(VERSION 3.10.0)
project(main VERSION 0.1.0 LANGUAGES C CXX)

# Find OpenCL manually in MSYS2
set(OpenCL_INCLUDE_DIR "C:/msys64/mingw64/include")
set(OpenCL_LIBRARY "C:/msys64/mingw64/lib/libOpenCL.dll.a")

# Use relative paths that work from any workspace folder name
add_executable(main WIN32 "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/MyString.cpp")

# Set output directory to project root instead of build folder
set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}"
)

# Link OpenCL and Windows multimedia libraries
target_include_directories(main PRIVATE ${OpenCL_INCLUDE_DIR})
target_link_libraries(main PRIVATE ${OpenCL_LIBRARY} winmm)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
