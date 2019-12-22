#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "vulkan-utils.hpp"

int main() {
    const char* appName = "Triangle";
    const unsigned int width = 800;
    const unsigned int height = 600;
    const bool enableValidationLayers = true;

    auto window = createWindow(width, height, appName);
    auto instance = createInstance(appName, enableValidationLayers);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    vkDestroyInstance(instance, nullptr);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
