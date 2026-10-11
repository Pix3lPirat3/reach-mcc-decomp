struct constraint_data {
    unsigned char reserved0[0x15C];
    float max_linear_impulse;
};

extern "C" void hkpRagdollConstraintData_setMaximumLinearImpulse_8b3680(constraint_data* data, float impulse) {
    data->max_linear_impulse = impulse;
}
