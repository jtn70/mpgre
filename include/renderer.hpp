#pragma once
#include <iostream>
#include <iomanip>
#include <numeric>

#include <vulkan/vulkan.hpp>

#ifdef NDEBUG						// NDEBUG is standard macro for "NOT DEBUG" in C++
const bool MPGRE_DEBUG = false;
#else
const bool MPGRE_DEBUG = true;
#endif

namespace mpgre
{
	class renderer
	{
	private:
		const std::string engineName = "MPGRE";
		const uint32_t engineVersion = VK_MAKE_VERSION(0, 1, 0);
		const uint32_t apiVersion = VK_API_VERSION_1_3;

		vk::Instance instance = { };

	public:
		renderer(int number);
		~renderer();

		void mainLoop();

	private:
		// void createWindow();
		void createInstance(std::string appName, uint32_t appVersion);
		vk::DebugUtilsMessengerCreateInfoEXT makeDebugUtilsMessengerCreateInfoEXT();
		
	};
}

VKAPI_ATTR VkBool32 VKAPI_CALL debugUtilsMessengerCallback(
	VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
	VkDebugUtilsMessageTypeFlagsEXT messageTypes,
	VkDebugUtilsMessengerCallbackDataEXT const* pCallbackData,
	void* /*pUserData*/);
