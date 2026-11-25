#include "ui_core/gui_app.h"

#include <SDL3/SDL.h>
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"

namespace railsig::ui_core {

GuiApp::GuiApp(GuiConfig config) {
    if (!init(config)) {
        shutdown();
    }
}

GuiApp::~GuiApp() {
    shutdown();
}

bool GuiApp::is_valid() const noexcept {
    return window_ != nullptr && renderer_ != nullptr && imgui_initialized_;
}

bool GuiApp::init(const GuiConfig& config) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return false;
    }

    window_ = SDL_CreateWindow(
        config.title.c_str(),
        config.width,
        config.height,
        SDL_WINDOW_RESIZABLE
    );
    if (window_ == nullptr) {
        SDL_Log("SDL_CreateWindow failed: %s", SDL_GetError());
        return false;
    }

    renderer_ = SDL_CreateRenderer(window_, nullptr);
    if (renderer_ == nullptr) {
        SDL_Log("SDL_CreateRenderer failed: %s", SDL_GetError());
        return false;
    }

    SDL_SetRenderVSync(renderer_, 1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui::StyleColorsDark();

    if (!ImGui_ImplSDL3_InitForSDLRenderer(window_, renderer_)) {
        SDL_Log("ImGui_ImplSDL3_InitForSDLRenderer failed");
        return false;
    }

    if (!ImGui_ImplSDLRenderer3_Init(renderer_)) {
        SDL_Log("ImGui_ImplSDLRenderer3_Init failed");
        return false;
    }

    imgui_initialized_ = true;
    return true;
}

void GuiApp::run(const std::function<void()>& draw_ui) {
    if (!is_valid()) {
        return;
    }

    bool running = true;
    while (running) {
        SDL_Event event{};
        while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL3_ProcessEvent(&event);
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
            if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED &&
                event.window.windowID == SDL_GetWindowID(window_)) {
                running = false;
            }
        }

        ImGui_ImplSDLRenderer3_NewFrame();
        ImGui_ImplSDL3_NewFrame();
        ImGui::NewFrame();

        if (draw_ui) {
            draw_ui();
        }

        ImGui::Render();
        SDL_SetRenderDrawColor(renderer_, 24, 26, 30, 255);
        SDL_RenderClear(renderer_);
        ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer_);
        SDL_RenderPresent(renderer_);
    }
}

void GuiApp::shutdown() noexcept {
    if (imgui_initialized_) {
        ImGui_ImplSDLRenderer3_Shutdown();
        ImGui_ImplSDL3_Shutdown();
        ImGui::DestroyContext();
        imgui_initialized_ = false;
    }
    if (renderer_ != nullptr) {
        SDL_DestroyRenderer(renderer_);
        renderer_ = nullptr;
    }
    if (window_ != nullptr) {
        SDL_DestroyWindow(window_);
        window_ = nullptr;
    }
    SDL_Quit();
}

} // namespace railsig::ui_core