#include <iostream>
#include "House.hpp"
#include "Virus.hpp"
#include "Human.hpp"
#include "Watersource.hpp"
#include "Foodsource.hpp"
#include "/home/borna/C++/Glad/include/glad/glad.h"
#include <GLFW/glfw3.h>
#include "/home/borna/C++/imgui-1.89.5/imgui.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"

bool simulation_started = false;
bool fullscreen = false;
int windowedWidth = 800;
int windowedHeight = 600;
int windowedPosX = 100;
int windowedPosY = 100;

void toggleFullscreen(GLFWwindow* window) {
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);

    if (!fullscreen) {
        // Switch to fullscreen
        glfwGetWindowPos(window, &windowedPosX, &windowedPosY);
        glfwGetWindowSize(window, &windowedWidth, &windowedHeight);
        glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
    } else {
        // Switch back to windowed mode
        glfwSetWindowMonitor(window, nullptr, windowedPosX, windowedPosY, windowedWidth, windowedHeight, 0);
    }

    fullscreen = !fullscreen;
}

int main() {
    if (!glfwInit()) {
        // Initialization failed
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(windowedWidth, windowedHeight, "InfectionSim", NULL, NULL);
    if (!window) {
        // Window creation failed
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        // Failed to initialize OpenGL loader
        return -1;
    }

    // Initialize ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;

    // ImGui configuration
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui::StyleColorsDark();

    // Initialize ImGui backends
    const char *glsl_version = "#version 130";
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);




    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Poll and handle events
        glfwPollEvents();

        // ImGui new frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

            // Get a reference to the current ImGui style
        ImGuiStyle& style = ImGui::GetStyle();

        // Modify the colors
        style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1f, 0.1f, 1.0f);
        style.Colors[ImGuiCol_TitleBg] = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
        style.Colors[ImGuiCol_Button] = ImVec4(0.4f, 0.4f, 0.4f, 1.0f);
        style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.6f, 0.6f, 0.6f, 1.0f);
        style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.8f, 0.8f, 0.8f, 1.0f);
        style.Colors[ImGuiCol_Text] = ImVec4(0.9f, 0.9f, 0.9f, 1.0f);
        // Add more colors as needed

        // ImGui commands
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(3, 3));
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(3, 3));
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(25, 10));
        ImGui::PushStyleVar(ImGuiStyleVar_ItemInnerSpacing, ImVec2(10, 10));

        ImVec4 window_bg_color = ImVec4(0.1f, 0.1f, 0.1f, 1.0f);
        ImVec4 title_bg_color = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
        ImVec4 button_color = ImVec4(0.4f, 0.4f, 0.4f, 1.0f);
        ImVec4 button_hovered_color = ImVec4(0.6f, 0.6f, 0.6f, 1.0f);
        ImVec4 button_active_color = ImVec4(0.8f, 0.8f, 0.8f, 1.0f);
        ImVec4 text_color = ImVec4(0.9f, 0.9f, 0.9f, 1.0f);

        ImGui::PushStyleColor(ImGuiCol_WindowBg, window_bg_color);
        ImGui::PushStyleColor(ImGuiCol_TitleBg, title_bg_color);
        ImGui::PushStyleColor(ImGuiCol_Button, button_color);
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, button_hovered_color);
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, button_active_color);
        ImGui::PushStyleColor(ImGuiCol_Text, text_color);
        // Set corner rounding radius for the window
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 5.0f);

        // Set corner rounding radius for the frame
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 5.0f);

        ImGui::Begin("Test");
        ImGui::Text("Testing V 1.0.1");
        if (ImGui::Button("Toggle Fullscreen")) {
            toggleFullscreen(window);
        }
        if (ImGui::Button("Close")) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
        if (ImGui::Button("Start Simulation")){
            simulation_started = true;
            std::cout<<"Started simulation\n";

        }
        if (ImGui::Button("Stop Simulation")){
            simulation_started = false;
            std::cout<<"Stopped simulation\n";
        }
        ImGui::Text("Test");
        ImGui::End();
        ImGui::PopStyleColor(6);
        ImGui::PopStyleVar(6);

        // Render ImGui
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
