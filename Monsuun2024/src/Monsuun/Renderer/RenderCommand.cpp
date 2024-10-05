#include "mupch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Monsuun {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}