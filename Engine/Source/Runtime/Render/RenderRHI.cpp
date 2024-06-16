#include "RenderRHI.hpp"
#include "Luna/Runtime/Base.hpp"
#include "Luna/Runtime/Result.hpp"
#include "Luna/Window/MessageBox.hpp"
#include "WindowsManager.hpp"
#include <Luna/RHI/Device.hpp>

namespace Raiden
{
    RenderRHI *RenderRHI::m_instance = nullptr;

    void       RenderRHI::Create() { m_instance = new RenderRHI(); }

    RenderRHI *RenderRHI::GetInstance() { return m_instance; }

    RenderRHI::RenderRHI()
    {
        lutry { luexp(InitRHI()); }
        lucatch
        {
            auto _ = Window::message_box(explain(luerr),
                                         "RenderRHI Init Failed.",
                                         Window::MessageBoxType::ok,
                                         Window::MessageBoxIcon::error);
            return;
        }
    }

    RV RenderRHI::InitRHI()
    {
        lutry
        {
            m_device              = RHI::get_main_device();
            u32 num_queues        = m_device->get_num_command_queues();
            m_graphics_queue      = U32_MAX;
            m_async_compute_queue = U32_MAX;
            m_async_copy_queue    = U32_MAX;

            for (u32 i = 0; i < num_queues; i++)
            {
                auto desc = m_device->get_command_queue_desc(i);
                if (desc.type == RHI::CommandQueueType::graphics && m_graphics_queue == U32_MAX)
                    m_graphics_queue = i;
                else if (desc.type == RHI::CommandQueueType::compute && m_async_compute_queue == U32_MAX)
                    m_async_compute_queue = i;
                else if (desc.type == RHI::CommandQueueType::copy && m_async_copy_queue == U32_MAX)
                    m_async_copy_queue = i;
            }

            if (m_async_compute_queue == U32_MAX)
            {
                m_async_compute_queue = m_graphics_queue;
            }
            if (m_async_copy_queue == U32_MAX)
            {
                m_async_copy_queue = m_graphics_queue;
            }

            luset(m_swap_chain,
                  m_device->new_swap_chain(m_graphics_queue,
                                           WindowsManager::GetInstance()->GetWindows(),
                                           RHI::SwapChainDesc{ 0, 0, 2, RHI::Format::bgra8_unorm, true }));
            luset(m_command_buffer, m_device->new_command_buffer(m_graphics_queue));
        }
        lucatchret;
        return ok;
    }

} //namespace Raiden