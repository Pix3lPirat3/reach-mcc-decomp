typedef union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float lanes[4];
    unsigned long long halves[2];
} __m128;

extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" float _mm_cvtss_f32(__m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);

struct character_motion {
    unsigned char reserved0[0xD0];
    __m128 inverse_inertia;
    __m128 reserved_e0;
    __m128 angular_velocity;
};

extern "C" float hkpCharacterMotion_applyAngularImpulse_8b8db0(character_motion* motion, const __m128* impulse) {
    __m128 result = _mm_add_ps(_mm_mul_ps(motion->inverse_inertia, *impulse), motion->angular_velocity);
    motion->angular_velocity = result;
    return _mm_cvtss_f32(result);
}
