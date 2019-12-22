#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "vulkan-utils.hpp"

int main() {
    const char* appName = "Triangle";
    const int width = 800;
    const int height = 600;
    const bool enableValidationLayers = true;

    auto window = createWindow(width, height, appName);
    auto instance = createInstance(appName, enableValidationLayers);
    auto surface = createSurface(window, instance);
    auto physicalDevice = pickPhysicalDevice(instance, surface);
    auto device = createLogicalDevice(physicalDevice, surface, enableValidationLayers);
    auto swapChain = createSwapChain(physicalDevice, surface, device, window);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    vkDeviceWaitIdle(device);

    vkDestroySwapchainKHR(device, swapChain, nullptr);
    vkDestroyDevice(device, nullptr);
    vkDestroySurfaceKHR(instance, surface, nullptr);
    vkDestroyInstance(instance, nullptr);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
