#include "Runtime/Engine.hpp"
#include <Luna/Runtime/Path.hpp>
#include <Luna/Runtime/Ref.hpp>
#include <Luna/Runtime/Runtime.hpp>

int main()
{
    luassert_always(Luna::init());
    Luna::register_boxed_type<Raiden::RaidenEngine>();
    Luna::Ref<Raiden::RaidenEngine> engine = Luna::new_object<Raiden::RaidenEngine>();
    engine->StartEngine("");
    engine->Run();
    engine->ShutdownEngine();
    return 0;
}