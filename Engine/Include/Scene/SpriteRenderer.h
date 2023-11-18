#pragma once

#include <memory>
#include <string>

namespace Trinity
{
	class BatchRenderer;
	class Scene;
	class Camera;
	class RenderTarget;
	class RenderPass;

	class SpriteRenderer
	{
	public:

		static constexpr const char* kShader = "/Assets/Engine/Shaders/SpriteRenderer.wgsl";

		SpriteRenderer() = default;
		virtual ~SpriteRenderer() = default;

		SpriteRenderer(const SpriteRenderer&) = delete;
		SpriteRenderer& operator = (const SpriteRenderer&) = delete;

		SpriteRenderer(SpriteRenderer&&) = default;
		SpriteRenderer& operator = (SpriteRenderer&&) = default;

		virtual bool create(Scene& scene, RenderTarget& renderTarget);
		virtual void destroy();

		virtual void setCamera(const std::string& nodeName);
		virtual void draw(const RenderPass& renderPass);

	protected:

		Scene* mScene{ nullptr };
		Camera* mCamera{ nullptr };
		std::unique_ptr<BatchRenderer> mRenderer{ nullptr };
	};
}