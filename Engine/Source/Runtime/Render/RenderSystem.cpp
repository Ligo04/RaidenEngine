#include "RenderSystem.hpp"
#include "Runtime/Render/WindowsManager.hpp"

namespace Raiden
{
    RenderSystem *RenderSystem::m_instance = nullptr;

    void          RenderSystem::Create() { m_instance = new RenderSystem(); }

    RenderSystem::RenderSystem() {}

    RenderSystem *RenderSystem::GetInstance() { return m_instance; }

    void          RenderSystem::Initialize() {}

    void          RenderSystem::Tick(float delta_time) {}

    void          RenderSystem::Clear() {}

} //namespace Raiden