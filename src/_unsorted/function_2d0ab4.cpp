struct ramp {
    char reserved0[8];
    float start;
    char reserved0c[0xc];
    float step;
};

extern "C" float function_2d0ab4(ramp* self, int index) {
    return (float)index * self->step + self->start;
}
