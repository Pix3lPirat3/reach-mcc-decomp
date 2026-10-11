struct action_request {
    int action_id;
    unsigned char reserved4[76];
};

extern "C" char function_49f24c(unsigned int unit, action_request* request);
extern "C" long long function_78932a(void* buffer, long long value, long long size);

extern "C" char unit_action_start_by_id_49f210(int unit, int action_id) {
    action_request request;
    function_78932a(&request, 0, 0x44);
    request.action_id = action_id;
    return function_49f24c(unit, &request);
}
