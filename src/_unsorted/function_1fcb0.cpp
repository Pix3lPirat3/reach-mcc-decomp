struct vec3 {
    float x;
    float y;
    float z;
};

extern "C" float function_1fcb0(vec3* v) {
    return v->x * v->x + v->y * v->y + v->z * v->z;
}
