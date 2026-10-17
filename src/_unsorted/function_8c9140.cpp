struct world_object {
    unsigned char reserved0[8];
    int field_8;
};

extern "C" void function_8c8ff0(void * world, void* second);
extern "C" void function_8c8ea0(void * world, void* second);

extern "C" void function_8c9140(world_object* world, void* second) {
    world->field_8 = 0;
    function_8c8ff0(world, second);
    return function_8c8ea0(world, second);
}
