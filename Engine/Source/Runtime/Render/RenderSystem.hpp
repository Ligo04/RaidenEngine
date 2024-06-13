#pragma once

#include "Runtime/Render/RenderRHI.hpp"
#include <Luna/RHI/RHI.hpp>
#include <Luna/Runtime/Ref.hpp>
#include <Luna/Window/Window.hpp>

namespace Raiden
{
    using namespace Luna;
    class RenderSystem
    {
        public:
            lustruct("RenderEngine", "{C2D09E8F-1FFA-B7A5-1A0D-FDC67F24ED25}");

        public:
            static void          Create();
            static RenderSystem *GetInstance();

        private:
            static RenderSystem *m_instance;

        public:
            RenderSystem();
            ~RenderSystem() = default;

            void Initialize();
            void Tick(float delta_time);
            void Clear();

            bool WindowShouldClose() const;
            void CloseWindow();
            bool IsWindowClosed() const;

        private:
            Ref<Window::IWindow> m_window{ nullptr };
            Ref<RenderRHI>       m_render_rhi{ nullptr };
    };
} //namespace Raiden