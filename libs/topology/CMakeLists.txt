add_library(railsig_topology STATIC
        src/types.cpp
)
add_library(railsig::topology ALIAS railsig_topology)

target_include_directories(railsig_topology
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(railsig_topology PUBLIC cxx_std_23)

if(RAILSIG_BUILD_TESTS)
    add_subdirectory(tests)
endif()

target_link_libraries(railsig_topology
    PUBLIC
        railsig::common
)
