cmake_minimum_required(VERSION 3.8)
add_compile_options(-std=c++11)

project( main  )
include_directories(./)
file(GLOB SOURCES "main.cpp")
file(GLOB APP_COPA21 "dynsocc/application/tournaments/CopaAmerica2021/copa_america_2k21.cpp")

file(GLOB STATICLIBS "dynsocc/cvplayer/impl/player/*.cpp"
					"dynsocc/fundamental/impl/number/*.cpp"
					"dynsocc/fundamental/impl/prob/*.cpp"
					"dynsocc/fundamental/impl/statemachine/*.cpp"
					"dynsocc/fundamental/impl/soccer/*.cpp"
					"dynsocc/fundamental/impl/test/*.cpp"
					"dynsocc/fundamental/stdex/*.cpp"
					"dynsocc/fundamental/stdex/*.ipp"
					"dynsocc/util/*.cpp"
					"dynsocc/test/state_machine/switcher/*.cpp"
					"dynsocc/test/state_machine/*.cpp"
					"dynsocc/application/*.cpp" )					

add_executable( main ${SOURCES} )
add_executable( copa_america_2k21 ${APP_COPA21} )

add_library(libdynsocc STATIC ${STATICLIBS})

TARGET_LINK_LIBRARIES(main libdynsocc)
TARGET_LINK_LIBRARIES(copa_america_2k21 libdynsocc)