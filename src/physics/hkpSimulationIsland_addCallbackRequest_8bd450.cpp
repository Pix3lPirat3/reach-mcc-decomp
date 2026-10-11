struct callback_target {
    unsigned char reserved0[0x22];
    unsigned char requests;
};

struct request_source {
    unsigned char reserved0[0x60];
    callback_target* target;
};

extern "C" long long hkpSimulationIsland_addCallbackRequest_8bd450(void*, request_source* source, char request) {
    callback_target* target = source->target;
    target->requests = target->requests | request;
    return (long long)target;
}
