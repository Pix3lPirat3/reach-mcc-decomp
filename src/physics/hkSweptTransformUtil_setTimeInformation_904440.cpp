struct swept_transform {
    unsigned char reserved0[0x4C];
    float time0;
    unsigned char reserved50[0xC];
    float time1;
};

extern "C" void hkSweptTransformUtil_setTimeInformation_904440(float first, float second, swept_transform* transform) {
    transform->time0 = first;
    transform->time1 = second;
}
