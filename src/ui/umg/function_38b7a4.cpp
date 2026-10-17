extern "C" long long user_interface_squad_get_game_variant_398c80();

extern "C" long long function_38b7a4() {
    long long variant = user_interface_squad_get_game_variant_398c80();
    if (variant == 0 || *(int*)variant != 2)
        return 0;
    return variant + 0x8C;
}
