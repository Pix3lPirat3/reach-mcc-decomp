struct timer_source {
    unsigned int count;
    int value;
    unsigned char reserved8[4];
    unsigned char payload[8];
    char flag;
};

extern "C" char net_session_parameter_countdown_timer_apply_value_3fa568(void* session, char flag, long long count, long long extra, int value, void* payload);

extern "C" char function_3fa544(void* session, timer_source* source, long long, long long extra) {
    return net_session_parameter_countdown_timer_apply_value_3fa568(session, source->flag, source->count, extra, source->value, source->payload);
}
