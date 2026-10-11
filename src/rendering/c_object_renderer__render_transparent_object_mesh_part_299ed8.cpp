extern "C" long long c_object_renderer__render_transparent_object_mesh_part_for_pass_299ef0(void* renderer, long long mesh, short part, short flags, int pass);

extern "C" long long c_object_renderer__render_transparent_object_mesh_part_299ed8(void* renderer, long long mesh, short part, short flags) {
    return c_object_renderer__render_transparent_object_mesh_part_for_pass_299ef0(renderer, mesh, part, flags, 2);
}
