#pragma once
#include "Luna/Runtime/Ref.hpp"
#include "Luna/Runtime/Result.hpp"
#include <Luna/Window/Window.hpp>
namespace Raiden
{
    using namespace Luna;
    class WindowsManager
    {
        public:
            static void            Create();
            static WindowsManager *GetInstance();

        private:
            static WindowsManager *m_instance;

        public:
            WindowsManager();
            ~WindowsManager() = default;
            RV                   Init();
            void                 Show();
            Ref<Window::IWindow> GetWindows();
            void                 SetTitle(u64 fps);

        private:
            Ref<Window::IWindow> m_window{ nullptr };
    };
} //namespace Raiden