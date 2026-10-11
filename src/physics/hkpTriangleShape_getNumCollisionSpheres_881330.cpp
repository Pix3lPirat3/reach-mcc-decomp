struct triangle_shape {
    unsigned char reserved0[0x2B];
    unsigned char extra_sphere;
};

extern "C" int hkpTriangleShape_getNumCollisionSpheres_881330(triangle_shape* shape) {
    int count = shape->extra_sphere + 1;
    return count * 3;
}
