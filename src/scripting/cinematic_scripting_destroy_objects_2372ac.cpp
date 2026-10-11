struct cinematic_scene {
    unsigned char reserved0[0x20];
    int object_count;
};

extern "C" void* cinematic_scripting_destroy_object_2371bc(int scene_index, int object_index);
extern "C" cinematic_scene* cinematic_scripting_get_scene_236a04(int scene_index);

extern "C" void* cinematic_scripting_destroy_objects_2372ac(int scene_index) {
    cinematic_scene* scene = cinematic_scripting_get_scene_236a04(scene_index);
    int index = 0;
    if (scene == 0)
        return scene;
    if (scene->object_count <= index)
        return scene;
    void* result;
    do {
        result = cinematic_scripting_destroy_object_2371bc(scene_index, index);
        index++;
    } while (index < scene->object_count);
    return result;
}
