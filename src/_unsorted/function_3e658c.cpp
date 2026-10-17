union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float values[4];
};

extern "C" __m128 _mm_loadu_ps(const float* source);
extern "C" void _mm_storeu_ps(float* dest, __m128 value);
extern "C" char function_3e658c(unsigned char* dest, unsigned char* source) {
    _mm_storeu_ps((float*)(dest + 0x88), _mm_loadu_ps((const float*)source));
    *(int*)(dest + 0x98) = *(int*)(source + 0x10);
    return 1;
}
