struct Item {
    char reserved_0[0x1a0];
    unsigned int field_1a0;
};
extern "C" char function_3724b8(Item* first, Item* second)
{
    return static_cast<int>(second->field_1a0 - first->field_1a0) > 0;
}
