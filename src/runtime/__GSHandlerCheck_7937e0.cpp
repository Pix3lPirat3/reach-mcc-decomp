struct dispatcher_context {
    unsigned char reserved0[0x38];
    void* scope_table;
};

extern "C" long long __GSHandlerCheckCommon_793800(void* frame, dispatcher_context* context, void* scope_table);

extern "C" long long __GSHandlerCheck_7937e0(long long, void* frame, long long, dispatcher_context* context) {
    __GSHandlerCheckCommon_793800(frame, context, context->scope_table);
    return 1;
}
