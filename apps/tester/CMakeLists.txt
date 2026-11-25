add_executable(railsig_tester
        src/main.cpp
)

target_link_libraries(railsig_tester
        PRIVATE
        railsig::ui_core
        railsig::topology
)