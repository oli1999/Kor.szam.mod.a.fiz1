cmake_minimum_required(VERSION 3.0.0)
project(kor_szam_hoz_egy_alap_main VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(kor_szam_hoz_egy_alap_main main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
