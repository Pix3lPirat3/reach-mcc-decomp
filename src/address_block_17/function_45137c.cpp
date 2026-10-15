struct picker_slot {
    int reserved[4];
};

struct picker_group {
    int field_0;
    int field_4;
    int field_8;
    picker_slot slots[16];
};

extern "C" void * function_45136c(void * slot);

extern "C" picker_group* function_45137c(picker_group* group) {
    for (int index = 0; index < 16; index++)
        function_45136c(&group->slots[index]);
    group->field_4 = 0;
    group->field_8 = 0;
    group->field_0 = -1;
    return group;
}
