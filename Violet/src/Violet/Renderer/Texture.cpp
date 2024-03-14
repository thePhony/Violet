#include "vlpch.h"
#include "Texture.h"

#include "Renderer.h"
#include <Platform/OpenGL/OpenGLTexture.h>

// #include "Platform/OpenGL/OpenGLTexture.h"


namespace Violet {
	Ref<Texture2D> Texture2D::Create(const std::string& path) {
		switch (Renderer::GetAPI()) {
		case RendererAPI::API::None:
			VL_CORE_ASSERT(false, "RendererAPI::None is currentlly not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLTexture2D>(path);
		}

		VL_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
	Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
	{
		switch (Renderer::GetAPI()) {
		case RendererAPI::API::None:
			VL_CORE_ASSERT(false, "RendererAPI::None is currentlly not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLTexture2D>(width, height);
		}

		VL_CORE_ASSERT(false, "Unknown RendererAPI!");

		return nullptr;
	}
}