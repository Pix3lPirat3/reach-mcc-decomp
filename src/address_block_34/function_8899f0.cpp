struct machine_holder {
    unsigned char reserved0[0x20];
    unsigned char machine[1];
};

extern "C" void function_899f70(void* machine, void* world);

extern "C" void function_8899f0(machine_holder* self, void* world) {
    return function_899f70(self->machine, world);
}
