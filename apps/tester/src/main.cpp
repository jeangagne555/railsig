#include <string>
#include "imgui.h"
#include "topology/types.h"
#include "ui_core/gui_app.h"

int main() {
    railsig::ui_core::GuiApp app({
        .title = "RailSig Interactive Tester",
        .width = 1100,
        .height = 720,
    });

    if (!app.is_valid()) {
        return 1;
    }

    double length_input{250.0};
    std::string status_message{"Ready"};

    app.run([&]() {
        ImGui::Begin("Topology Manual Check");

        ImGui::InputDouble("Track Length (m)", &length_input, 10.0, 100.0, "%.2f");
        if (ImGui::Button("Construct Length")) {
            try {
                const railsig::topology::Length len{length_input};
                status_message = "Valid Length: " + std::to_string(len.meters()) + " m";
            } catch (const std::exception& ex) {
                status_message = std::string{"Error: "} + ex.what();
            }
        }

        ImGui::Separator();
        ImGui::TextUnformatted(status_message.c_str());

        ImGui::End();
    });

    return 0;
}