cmake_minimum_required(VERSION 3.15)
project(CodeForceList LANGUAGES CXX)

# 모든 .cpp 파일 재귀 탐색
file(GLOB_RECURSE
        SRC_FILES
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/cpp/*/*.cpp"
)

foreach(_src IN LISTS SRC_FILES)
    # 파일 이름(확장자 제외) 추출
    get_filename_component(_name "${_src}" NAME_WE)
    # 비알파벳/숫자는 언더스코어로 치환
    string(REGEX REPLACE "[^A-Za-z0-9]" "_" _target "${_name}")

    # _src(현재 파일)만으로 실행 파일 생성
    add_executable(${_target} "${_src}")
endforeach()
