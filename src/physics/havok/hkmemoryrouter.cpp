extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned int index);
extern "C" unsigned int data_2a57f0c;
extern "C" void* function_86ca20(void) {
    return TlsGetValue(data_2a57f0c);
}
