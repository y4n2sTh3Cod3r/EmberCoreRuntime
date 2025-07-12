#include "frame.h"
#include <LLGL/LLGL.h>

void ELGR_API ELGR::Frame()
{
	LLGL::RenderSystemPtr renderer = LLGL::RenderSystem::Load("Vulkan");

	LLGL::SwapChainDescriptor swapChainDesc;
	swapChainDesc.resolution = { 640, 480 };
	swapChainDesc.resizable = true;
	LLGL::SwapChain* swapChain = renderer->CreateSwapChain(swapChainDesc);

	LLGL::Window& window = LLGL::CastTo<LLGL::Window>(swapChain->GetSurface());

	window.SetTitle("ELGR Renderer");

	window.Show();

	while (window.ProcessEvents() && !window.HasQuit())
	{
		LLGL::CommandBuffer* cmdBuffer = renderer->CreateCommandBuffer(LLGL::CommandBufferFlags::ImmediateSubmit);
		cmdBuffer->BeginRenderPass(*swapChain);

		cmdBuffer->SetViewport(swapChain->GetResolution());

		cmdBuffer->Clear(LLGL::ClearFlags::Color, { 0.2, 0.3, 0.5, 1 });

		cmdBuffer->EndRenderPass();
		cmdBuffer->End();

		swapChain->Present();
	}
}
