/*
 * RenderSystem.PipelineState.inl
 *
 * Copyright (c) 2015 Lukas Hermanns. All rights reserved.
 * Licensed under the terms of the BSD 3-Clause license (see LICENSE.txt).
 */

/* ----- Pipeline States ----- */

virtual LLGL::PipelineState* CreatePipelineState(
    const LLGL::GraphicsPipelineDescriptor& pipelineStateDesc,
    LLGL::PipelineCache*                    pipelineCache       = nullptr
) override final;

virtual LLGL::PipelineState* CreatePipelineState(
    const LLGL::ComputePipelineDescriptor&  pipelineStateDesc,
    LLGL::PipelineCache*                    pipelineCache       = nullptr
) override final;

virtual PipelineState* CreatePipelineState(
    const LLGL::MeshPipelineDescriptor&     pipelineStateDesc,
    LLGL::PipelineCache*                    pipelineCache       = nullptr
) override final;

virtual void Release(
    LLGL::PipelineState&                    pipelineState
) override final;



// ================================================================================
