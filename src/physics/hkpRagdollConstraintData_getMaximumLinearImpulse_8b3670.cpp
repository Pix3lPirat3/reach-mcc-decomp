struct constraint_data {
    unsigned char reserved0[0x15C];
    float max_linear_impulse;
};

extern "C" float hkpRagdollConstraintData_getMaximumLinearImpulse_8b3670(constraint_data* data) {
    return data->max_linear_impulse;
}
