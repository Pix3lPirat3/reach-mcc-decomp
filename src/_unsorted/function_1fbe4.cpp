struct Object3;
struct Object2;

struct Object3 {
    float field_0;
    float field_4;
    float field_8;
};

struct Object2 {
    float field_0;
    float field_4;
    float field_8;
};

extern "C" float function_1fbe4(Object2 *object2, Object3 *object3) {
    float local3;
    float local2;
    float local1;
    local2 = object3->field_0 - object2->field_0;
    local1 = object3->field_4 - object2->field_4;
    local3 = object3->field_8 - object2->field_8;
    return local1 * local1 + local2 * local2 + local3 * local3;
}
