union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float values[4];
};

extern "C" __m128 _mm_loadu_ps(const float* source);
extern "C" void _mm_storeu_ps(float* dest, __m128 value);
extern "C" float _mm_cvtss_f32(__m128 value);

extern "C" float function_3e6ac8(unsigned char* source, void*, void*, float* dest) {
    __m128 first = _mm_loadu_ps((const float*)(source + 0xA8));
    _mm_storeu_ps(dest, first);
    _mm_storeu_ps(dest + 4, _mm_loadu_ps((const float*)(source + 0xB8)));
    return _mm_cvtss_f32(first);
}
