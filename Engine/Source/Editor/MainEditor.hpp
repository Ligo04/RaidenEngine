#pragma once
#include "Editor/UI/EditorUI.hpp"
#include "Luna/Runtime/UniquePtr.hpp"
#include "Runtime/Engine.hpp"

namespace Raiden
{
    class RaidenEngine;
    class RaidenEditor
    {
        public:
        protected:
            Luna::UniquePtr<EditorUI>     m_editor_ui;
            Luna::UniquePtr<RaidenEngine> m_engine;
    };
} //namespace Raiden