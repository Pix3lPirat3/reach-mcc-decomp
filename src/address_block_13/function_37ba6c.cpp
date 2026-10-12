struct Left {
    int field_0;
};
struct Right {
    int field_0;
};
extern "C" int function_37b97c(Left* left, Right* right);
extern "C" int function_37ba6c(Left* left, Right* right)
{
    unsigned int diff = left->field_0 - right->field_0;
    if (diff != 0)
        return diff;
    return function_37b97c(left, right);
}
