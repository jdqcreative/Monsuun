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
		MU_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		MU_CORE_ASSERT(status, "Failed to initialize Glad!");

		MU_CORE_INFO("OpenGL Info:");
		MU_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		MU_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		MU_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));

	#ifdef MU_ENABLE_ASSERTS
		int versionMajor;
		int versionMinor;

		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		MU_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Monsuun requires at least OpenGL version 4.5!");

	#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		MU_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}