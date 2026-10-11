typedef union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
    unsigned long long m128_u64[2];
} __m128;

extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" float _mm_cvtss_f32(__m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);

struct motion {
    unsigned char reserved0[0xD0];
    __m128 inverse_inertia;
    unsigned char reservede0[0x10];
    __m128 angular_velocity;
};

extern "C" float hkpSphereMotion_applyAngularImpulse_8b84c0(motion* body, __m128* impulse) {
    __m128 velocity = _mm_add_ps(_mm_mul_ps(body->inverse_inertia, *impulse), body->angular_velocity);
    body->angular_velocity = velocity;
    return _mm_cvtss_f32(velocity);
}
