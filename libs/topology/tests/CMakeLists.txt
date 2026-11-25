add_executable(railsig_topology_tests
        test_types.cpp
)

target_link_libraries(railsig_topology_tests
        PRIVATE
        railsig::topology
        Catch2::Catch2WithMain
)

include(Catch)
catch_discover_tests(railsig_topology_tests)
