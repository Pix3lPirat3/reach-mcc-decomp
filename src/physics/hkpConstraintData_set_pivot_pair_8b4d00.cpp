typedef union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float lanes[4];
    unsigned long long halves[2];
} __m128;

extern "C" float _mm_cvtss_f32(__m128);

struct constraint_data {
    unsigned char reserved0[0x30];
    __m128 pivot_a;
    __m128 pivot_b;
};

extern "C" float hkpConstraintData_set_pivot_pair_8b4d00(constraint_data* data, const __m128* pivot_a, const __m128* pivot_b) {
    __m128 first = *pivot_a;
    data->pivot_a = first;
    data->pivot_b = *pivot_b;
    return _mm_cvtss_f32(first);
}
