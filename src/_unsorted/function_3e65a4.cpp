union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float values[4];
};

extern "C" __m128 _mm_loadu_ps(const float* source);
extern "C" void _mm_storeu_ps(float* dest, __m128 value);
extern "C" int function_3e65a4(unsigned char* source, void*, void*, unsigned char* dest) {
    _mm_storeu_ps((float*)dest, _mm_loadu_ps((const float*)(source + 0x9C)));
    int tail = *(int*)(source + 0xAC);
    *(int*)(dest + 0x10) = tail;
    return tail;
}
