#pragma once

#include <functional>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

namespace railsig::ui_core {

    struct GuiConfig {
        std::string title{"RailSig"};
        int width{1280};
        int height{800};
    };

    class GuiApp {
    public:
        explicit GuiApp(GuiConfig config);
        ~GuiApp();

        GuiApp(const GuiApp&) = delete;
        GuiApp& operator=(const GuiApp&) = delete;

        [[nodiscard]] bool is_valid() const noexcept;
        void run(const std::function<void()>& draw_ui);

    private:
        bool init(const GuiConfig& config);
        void shutdown() noexcept;

        SDL_Window* window_{nullptr};
        SDL_Renderer* renderer_{nullptr};
        bool imgui_initialized_{false};
    };

} // namespace railsig::ui_core