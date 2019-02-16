#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "window.hpp"
#include "statusbar.hpp"
#include "menubar.hpp"
#include "toolbar.hpp"
#include "logger.hpp"

#define LOGGING

using namespace st::ui;
using namespace st::utility;

static Window window("MainWindow");


void onCut(){
    std::cout << "onCut" << std::endl;
}

void onCopy(){
    std::cout << "onCopy" << std::endl;
}

void create_menu_bar(){
    auto menuBar = std::make_unique<MenuBar>("##menubar",&window);
    menuBar->setColor(ImGuiCol_MenuBarBg,ImVec4{1.0f,0.0f,0.0f,1.0f});
    menuBar->setColor(ImGuiCol_PopupBg,ImVec4{0.0f,0.0f,1.0f,1.0f});
    
    Menu menu("File");
    MenuItem file("New");
    menu.addMenuItem(std::move(file));
    
    Menu edit("Edit");
    MenuItem redo("Redo");
    MenuItem cut("Cut");
    cut.bindClicked(onCut);
    MenuItem copy("Copy");
    copy.bindClicked(onCopy);
    
    edit.addMenuItem(redo);
    edit.addMenuItem(cut);
    edit.addMenuItem(copy);
    
    
    menuBar->addMenu(std::move(menu));
    menuBar->addMenu(std::move(edit));
    
    window.setMenuBar(std::move(menuBar));
}

void create_tool_bar(){
    auto toolbar = std::make_unique<ToolBar>("##toolbar",&window);
    toolbar->setViewStyle(ViewStyle::ICON);
    
    toolbar->addButton("Press Me","../resources/press.png");
    toolbar->addButton("Up me","../resources/up.png");
    toolbar->addButton("Tick Me","../resources/yes.png");
    
    window.setToolBar(std::move(toolbar));
}

void create_status_bar(){
    auto statusBar = std::make_unique<StatusBar>("##statusbar",&window);
    window.setStatusBar(std::move(statusBar));
}

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

static void glfw_resize_callback(GLFWwindow*,int w,int h){
    glViewport(0, 0, w, h);
}


int main(int, char**)
{
#ifdef LOGGING
    spdlog::stdout_logger_st("imlog");
#endif
    
    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;
    
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    
    // Create window with graphics context
    GLFWwindow* glfwWindow = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 example", NULL, NULL);
    if (glfwWindow == NULL)
        return 1;
    
    glfwSetFramebufferSizeCallback(glfwWindow,glfw_resize_callback);
    glfwMakeContextCurrent(glfwWindow);
    
    bool err = glewInit() != GLEW_OK;
    if (err)
    {
        fprintf(stderr, "Failed to initialize OpenGL loader!\n");
        return 1;
    }
    
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    
    ImGui::CreateContext();
    
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
    
    ImGui::StyleColorsDark();
    
    ImGui_ImplGlfw_InitForOpenGL(glfwWindow, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
    
    glfwMakeContextCurrent(glfwWindow);
    
    create_menu_bar();
    create_tool_bar();
    create_status_bar();
    
    window.setColor(ImGuiCol_WindowBg,ImVec4(0.4f,0.4f,0.4f,1.0f));

    while (!glfwWindowShouldClose(glfwWindow))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwPollEvents();
        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        
        window.draw();
        
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        
        glfwSwapBuffers(glfwWindow);
    }
    
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    
    glfwDestroyWindow(glfwWindow);
    glfwTerminate();
    
    return 0;
}
