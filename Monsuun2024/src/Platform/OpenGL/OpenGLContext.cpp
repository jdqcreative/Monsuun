#include "mupch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Monsuun {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		MU_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		MU_CORE_ASSERT(status, "Failed to initialize Glad!");

		MU_CORE_INFO("OpenGL Info:");
		MU_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		MU_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		MU_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}