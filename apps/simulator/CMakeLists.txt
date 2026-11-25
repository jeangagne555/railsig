add_executable(railsig_sim
        src/main.cpp
)

target_link_libraries(railsig_sim
        PRIVATE
        railsig::topology
)
