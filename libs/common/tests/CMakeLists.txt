add_executable(railsig_common_tests
        test_types.cpp
)

target_link_libraries(railsig_common_tests
        PRIVATE
        railsig::topology
        Catch2::Catch2WithMain
)

include(Catch)
catch_discover_tests(railsig_common_tests)
