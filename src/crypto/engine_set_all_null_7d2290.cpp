struct engine_methods {
    void* slot00;
    void* slot08;
    void* slot10;
    void* slot18;
    void* slot20;
    void* reserved28;
    void* slot30;
    void* slot38;
    void* slot40;
    void* reserved48[2];
    void* slot58;
    void* slot60;
    void* slot68;
    void* slot70;
    void* slot78;
    void* slot80;
    void* reserved88;
    void* slot90;
    int slot98;
};

extern "C" long long engine_set_all_null_7d2290(engine_methods* engine) {
    engine->slot00 = 0;
    engine->slot08 = 0;
    engine->slot10 = 0;
    engine->slot18 = 0;
    engine->slot20 = 0;
    engine->slot30 = 0;
    engine->slot38 = 0;
    engine->slot40 = 0;
    engine->slot58 = 0;
    engine->slot60 = 0;
    engine->slot68 = 0;
    engine->slot70 = 0;
    engine->slot78 = 0;
    engine->slot80 = 0;
    engine->slot90 = 0;
    engine->slot98 = 0;
    return 0;
}
