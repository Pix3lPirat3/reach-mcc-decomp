typedef union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float lanes[4];
    unsigned long long halves[2];
} __m128;

struct aabb_phantom {
    unsigned char reserved0[0xF0];
    __m128 min_corner;
    __m128 max_corner;
};

struct aabb {
    __m128 min_corner;
    __m128 max_corner;
};

extern "C" float hkpAabbPhantom_getAabb_8b2690(aabb_phantom* phantom, aabb* out) {
    __m128 low = phantom->min_corner;
    out->min_corner = low;
    out->max_corner = phantom->max_corner;
    return low.lanes[0];
}
