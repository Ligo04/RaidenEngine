#pragma once
#include "Luna/RHI/CommandBuffer.hpp"
#include <Luna/RHI/RHI.hpp>
#include <Luna/Runtime/Ref.hpp>

namespace Raiden
{
    using namespace Luna;
    class RenderRHI
    {
        public:
            static void       Create();
            static RenderRHI *GetInstance();

        private:
            static RenderRHI *m_instance;

        public:
            RenderRHI();
            ~RenderRHI();
            RV InitRHI();

        public:
            Ref<RHI::IDevice>        m_device;
            Ref<RHI::ISwapChain>     m_swap_chain;
            Ref<RHI::ICommandBuffer> m_command_buffer;

            u32                      m_graphics_queue;
            u32                      m_async_compute_queue;
            u32                      m_async_copy_queue;
    };
} //namespace Raiden