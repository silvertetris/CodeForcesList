# top of CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(CodeForceList LANGUAGES CXX)

# grab all your .cpp files
file(GLOB_RECURSE
        SRC_FILES
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/cpp/*/*.cpp"
)

foreach(_src IN LISTS SRC_FILES)
    # get the bare filename (no path, no extension)
    get_filename_component(_name "${_src}" NAME_WE)

    # replace spaces (and, if you like, other non-alphanumerics) with underscores
    string(REGEX REPLACE "[^A-Za-z0-9]" "_" _target "${_name}")

    # now add an executable called e.g. Row_GCD or Gerald_and_Giant_Chess
    add_executable(${_target} "${_src}"
            cpp/264/C/264C.cpp)
endforeach()
