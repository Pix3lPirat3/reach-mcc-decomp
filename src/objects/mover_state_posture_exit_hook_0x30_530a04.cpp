extern "C" char mover_state_posture_exit_hook_0x38_530980(int unit, void* data);

extern "C" char mover_state_posture_exit_hook_0x30_530a04(int unit, void* data) {
    mover_state_posture_exit_hook_0x38_530980(unit, data);
    return 1;
}
