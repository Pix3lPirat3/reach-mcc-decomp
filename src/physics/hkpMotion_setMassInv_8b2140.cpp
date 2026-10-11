struct motion {
    unsigned char reserved0[0xDC];
    float inverse_mass;
};

extern "C" void hkpMotion_setMassInv_8b2140(motion* body, float inverse_mass) {
    body->inverse_mass = inverse_mass;
}
