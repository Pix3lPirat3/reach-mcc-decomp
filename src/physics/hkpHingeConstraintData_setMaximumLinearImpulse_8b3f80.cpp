struct constraint_data {
    unsigned char reserved0[0xB8];
    float max_linear_impulse;
};

extern "C" void hkpHingeConstraintData_setMaximumLinearImpulse_8b3f80(constraint_data* data, float impulse) {
    data->max_linear_impulse = impulse;
}
