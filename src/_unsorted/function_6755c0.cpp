struct object_a {
    bool field_0;
};
extern "C" object_a* function_6755c0(object_a* object, unsigned long long second, unsigned long long third) {
    object->field_0 = second < third;
    return object;
}
