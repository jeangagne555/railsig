#include <iostream>
#include "topology/types.h"

int main() {
    const railsig::topology::Length track_len{150.0};
    std::cout << "RailSig topology check: " << track_len.meters() << " m\n";
    return 0;
}