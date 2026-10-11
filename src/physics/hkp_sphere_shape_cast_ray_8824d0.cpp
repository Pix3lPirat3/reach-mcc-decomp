struct sphere_shape {
    unsigned char reserved0[0x20];
    float radius;
};

extern "C" long long function_677fb0(void* result, float radius, void* ray, void* output);

extern "C" void* hkp_sphere_shape_cast_ray_8824d0(sphere_shape* shape, void* result, void* ray, void* output) {
    function_677fb0(result, shape->radius, ray, output);
    return result;
}
