struct constraint_data {
    unsigned char reserved0[0xEC];
    float max_linear_impulse;
};

extern "C" void hkpLimitedHingeConstraintData_setMaximumLinearImpulse_8b45a0(constraint_data* data, float impulse) {
    data->max_linear_impulse = impulse;
}
