struct gpu_emitter {
    unsigned char reserved0[0x18];
    unsigned int field_18;
    unsigned int field_1c;
};

extern "C" void c_particle_emitter_gpu_method_slot_19_27c240(gpu_emitter* emitter, unsigned int first, unsigned int second) {
    emitter->field_18 = first >> 3;
    emitter->field_1c = second >> 3;
}
