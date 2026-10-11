struct constraint_data {
    unsigned char reserved0[0xB8];
    float max_linear_impulse;
};

extern "C" float hkpHingeConstraintData_getMaximumLinearImpulse_8b3f70(constraint_data* data) {
    return data->max_linear_impulse;
}
