struct pickup_action {
    unsigned char reserved0[4];
    int object_index;
};

extern "C" void function_48d144(int unit_index);
extern "C" void function_48cec8(int unit_index, int object_index);

extern "C" char unit_action_equipment_pickup_callback_50eb94(int unit_index, pickup_action* action) {
    function_48d144(unit_index);
    int object_index = action->object_index;
    if (object_index == -1)
        return 1;
    function_48cec8(unit_index, object_index);
    return 1;
}
