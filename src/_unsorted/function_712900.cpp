struct Object;

struct Object {
    short field_0;
    char field_2;
};

extern "C" bool function_712900(Object *object) {
    if (object->field_0 <= 1) {
        return 1;
    }
    if (object->field_0 != 2) {
        char result = object->field_0 != 3 ? 1 : !(object->field_2 & 96);
        return result;
    }
    return 0;
}
