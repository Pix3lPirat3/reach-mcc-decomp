struct constraint_data {
    unsigned char reserved0[0xEC];
    float max_linear_impulse;
};

extern "C" float hkpLimitedHingeConstraintData_getMaximumLinearImpulse_8b4590(constraint_data* data) {
    return data->max_linear_impulse;
}
