#include "WindowsManager.hpp"
#include "Luna/Runtime/Error.hpp"
#include "Luna/Runtime/Ref.hpp"
#include "Luna/Runtime/Result.hpp"
#include "Luna/Window/MessageBox.hpp"
#include "Luna/Window/Source/GLFW/Window.hpp"
#include "Luna/Window/Window.hpp"

namespace Raiden
{
    WindowsManager *WindowsManager::m_instance = nullptr;

    void            WindowsManager::Create() { m_instance = new WindowsManager(); }

    WindowsManager *WindowsManager::GetInstance() { return m_instance; }

    WindowsManager::WindowsManager()
    {
        lutry { luexp(Init()); }
        lucatch
        {
            auto _ = Window::message_box(explain(luerr),
                                         "Windows Init Failed.",
                                         Window::MessageBoxType::ok,
                                         Window::MessageBoxIcon::error);
            return;
        }
    }

    RV WindowsManager::Init()
    {
        lutry
        {
            luset(m_window,
                  Window::new_window("Raiden Engine",
                                     Window::WindowDisplaySettings::as_windowed(),
                                     Window::WindowCreationFlag::resizable));
            m_window->get_close_event().add_handler([](Window::IWindow *window) { window->close(); });
            m_window->get_framebuffer_resize_event().add_handler(
                [this](Window::IWindow *window, u32 width, u32 height) {
                    //TODO: Windows Resize Event
                });
        }
        lucatchret;
        return ok;
    }

    Ref<Window::IWindow> WindowsManager::GetWindows() { return m_window.get(); }

    bool                 WindowsManager::WindowsIsMinied() { return m_window->is_minimized(); }

    bool                 WindowsManager::WindowsShouldClose() { return m_window->is_closed(); }

} //namespace Raiden