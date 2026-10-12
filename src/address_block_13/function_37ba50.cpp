struct Left {
    int field_0;
};
struct Right {
    int field_0;
};
extern "C" int function_37b97c(Left* left, Right* right);
extern "C" char function_37ba50(Left* left, Right* right)
{
    int diff = left->field_0 - right->field_0;
    if (diff != 0)
        return diff > 0;
    return function_37b97c(left, right) > 0;
}
