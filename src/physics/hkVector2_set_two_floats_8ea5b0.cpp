struct float_pair {
    float first;
    float second;
};

extern "C" void hkVector2_set_two_floats_8ea5b0(float first, float second, float_pair* pair) {
    pair->first = first;
    pair->second = second;
}
