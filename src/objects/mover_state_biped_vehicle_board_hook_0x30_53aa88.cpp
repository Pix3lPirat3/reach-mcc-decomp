extern "C" long long biped_vehicle_board_end_53a7e8(int unit);

extern "C" char mover_state_biped_vehicle_board_hook_0x30_53aa88(int unit) {
    biped_vehicle_board_end_53a7e8(unit);
    return 1;
}
