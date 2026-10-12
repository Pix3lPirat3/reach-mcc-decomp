struct six_slots {
    long long slot0;
    long long slot1;
    long long slot2;
    long long slot3;
    long long slot4;
    long long slot5;
};

extern "C" six_slots* function_1cd02c(six_slots* slots) {
    slots->slot0 = 0;
    slots->slot1 = 0;
    slots->slot2 = 0;
    slots->slot3 = 0;
    slots->slot4 = 0;
    slots->slot5 = 0;
    return slots;
}
