typedef union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
    unsigned long long m128_u64[2];
} __m128;

extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" float _mm_cvtss_f32(__m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);

struct motion {
    unsigned char reserved0[0xD0];
    __m128 inverse_mass_vector;
    __m128 linear_velocity;
};

extern "C" float hkpMotion_applyLinearImpulse_8b1fe0(motion* body, __m128* impulse) {
    __m128 mass = body->inverse_mass_vector;
    __m128 velocity = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(mass, mass, 0xFF), *impulse), body->linear_velocity);
    body->linear_velocity = velocity;
    return _mm_cvtss_f32(velocity);
}
