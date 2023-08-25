#include "renderer.hpp"

using namespace mpgre;

renderer::renderer(int number)
{
	if (MPGRE_DEBUG) std::cout << "renderer() ::: START" << std::endl;

	createInstance("test", VK_MAKE_VERSION(1, 0, 0));
}

renderer::~renderer()
{
	if (MPGRE_DEBUG) std::cout << "~renderer() ::: START" << std::endl;

	instance.destroy();

	if (MPGRE_DEBUG) std::cout << "~renderer() ::: END" << std::endl;
}

void renderer::mainLoop()
{
	if (MPGRE_DEBUG) std::cout << "mainLoop() ::: START" << std::endl;

}

void renderer::createInstance(std::string appName, uint32_t appVersion)
{
	if (MPGRE_DEBUG) std::cout << "createInstance() ::: START" << std::endl;

	try
	{
		vk::ApplicationInfo applicationInfo(appName.c_str(), appVersion, engineName.c_str(), engineVersion, apiVersion);
		vk::InstanceCreateInfo instanceCreateInfo({}, &applicationInfo);
		instance = vk::createInstance(instanceCreateInfo);

		if (MPGRE_DEBUG) std::cout << "createInstance() ::: END" << std::endl;

	}
	catch (vk::SystemError& err)
	{
		std::cout << "vk::SystemError: " << err.what() << std::endl;
		exit(-1);
	}
	catch (std::exception& err)
	{
		std::cout << "std::exception: " << err.what() << std::endl;
		exit(-1);
	}
	catch (...)
	{
		std::cout << "Unkown error!?" << std::endl;
		exit(-1);
	}
}

vk::DebugUtilsMessengerCreateInfoEXT makeDebugUtilsMessengerCreateInfoEXT()
{
	return { {},
			 vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning | vk::DebugUtilsMessageSeverityFlagBitsEXT::eError,
			 vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral | vk::DebugUtilsMessageTypeFlagBitsEXT::ePerformance | vk::DebugUtilsMessageTypeFlagBitsEXT::eValidation,
			 &debugUtilsMessengerCallback};
}

VKAPI_ATTR VkBool32 VKAPI_CALL debugUtilsMessengerCallback(
	VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
	VkDebugUtilsMessageTypeFlagsEXT messageTypes,
	VkDebugUtilsMessengerCallbackDataEXT const * pCallbackData,
	void* /*pUserData*/)
{
	if (MPGRE_DEBUG)
	{
		
		if (pCallbackData->messageIdNumber == 648835635) return vk::False;
		if (pCallbackData->messageIdNumber == 767975156) return vk::False;
	}

	std::cerr << vk::to_string(static_cast<vk::DebugUtilsMessageSeverityFlagBitsEXT>(messageSeverity)) << ": "
		<< vk::to_string(static_cast<vk::DebugUtilsMessageTypeFlagsEXT>(messageTypes)) << ":\n";
	std::cerr << std::string("\t") << "messageIDName   = <" << pCallbackData->pMessageIdName << ">\n";
	std::cerr << std::string("\t") << "messageIDNumber = " << pCallbackData->messageIdNumber << "\n";
	std::cerr << std::string("\t") << "message         = <" << pCallbackData->pMessage << ">\n";

	if (0 < pCallbackData->queueLabelCount)
	{
		std::cerr << std::string("\t") << "Queue Labels:\n";
		for (uint32_t i = 0; i < pCallbackData->queueLabelCount; i++)
		{ 
			std::cerr << std::string("\t\t") << "labelName = <" << pCallbackData->pQueueLabels[i].pLabelName << ">\n";
		}
	}

	if (0 < pCallbackData->cmdBufLabelCount)
	{
		std::cerr << std::string("\t") << "CommandBuffer Labels:\n";
		for (uint32_t i = 0; i < pCallbackData->cmdBufLabelCount; i++)
		{
			std::cerr << std::string("\t\t") << "labelName = <" << pCallbackData->pCmdBufLabels[i].pLabelName << ">\n";
		}
	}

	if (0 < pCallbackData->objectCount)
	{
		for (uint32_t i = 0; i < pCallbackData->objectCount; i++)
		{
			std::cerr << std::string("\t\t") << "Object " << i << "\n";
			std::cerr << std::string("\t\t\t") << "objectType =   " << vk::to_string(static_cast<vk::ObjectType>(pCallbackData->pObjects[i].objectType)) << "\n";
			std::cerr << std::string("\t\t\t") << "objectHandle = " << pCallbackData->pObjects[i].objectHandle << "\n";											
			if (pCallbackData->pObjects[i].pObjectName)
			{
				std::cerr << std::string("\t\t\t") << "objectName   = <" << pCallbackData->pObjects[i].pObjectName << ">\n";
			}
		}
	}
	return vk::False;
}