typedef union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
    unsigned long long m128_u64[2];
} __m128;

extern "C" int _mm_comigt_ss(__m128, __m128);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_setzero_ps(void);

struct constraint_data {
    unsigned char reserved0[0x54];
    float rest_length;
};

extern "C" char* hkpStiffSpringConstraintData_isValid_8b4b10(constraint_data* data, char* result) {
    *result = _mm_comigt_ss(_mm_load_ss(&data->rest_length), _mm_setzero_ps()) != 0;
    return result;
}
