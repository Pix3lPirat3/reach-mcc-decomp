struct engine {
    unsigned char reserved0[0x90];
    void* cmd_defns;
};

extern "C" int ENGINE_set_cmd_defns_7d1f40(engine* target, void* defns) {
    target->cmd_defns = defns;
    return 1;
}
