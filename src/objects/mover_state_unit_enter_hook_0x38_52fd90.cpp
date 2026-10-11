extern "C" void* unit_apply_seat_flags_to_object_4c9590(int unit, int object);

extern "C" char mover_state_unit_enter_hook_0x38_52fd90(int unit, int object) {
    unit_apply_seat_flags_to_object_4c9590(unit, object);
    return 1;
}
