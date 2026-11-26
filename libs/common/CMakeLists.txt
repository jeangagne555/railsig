add_library(railsig_common STATIC
        src/types.cpp
)
add_library(railsig::common ALIAS railsig_common)

target_include_directories(railsig_common
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(railsig_common PUBLIC cxx_std_23)

if(RAILSIG_BUILD_TESTS)
    add_subdirectory(tests)
endif()