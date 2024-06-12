
target('RaidenEngine')
    set_program()
    add_options("rhi_api")
    add_headerfiles("**.hpp")
    add_includedirs("Source")
    add_files("**.cpp")
    add_deps("Runtime", "VariantUtils", "HID", "Window", "RHI", "Image", "Font", "ImGui", "Asset", "ObjLoader", "RG", "JobSystem")
target_end()