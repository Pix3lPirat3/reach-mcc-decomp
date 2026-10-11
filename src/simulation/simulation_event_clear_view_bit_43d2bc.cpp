struct simulation_event_manager {
    unsigned char reserved0[8];
    void* world;
};

struct simulation_event {
    unsigned char reserved0[44];
    int view_mask;
};

extern "C" long long simulation_event_free_43d254(simulation_event_manager* manager, simulation_event* event);
extern "C" long long simulation_event_release_references_43d56c(void* world, simulation_event* event);

extern "C" int simulation_event_clear_view_bit_43d2bc(simulation_event_manager* manager, int view_index, simulation_event* event) {
    long long mask = (unsigned int)~(1 << view_index);
    int remaining = event->view_mask & (int)mask;
    event->view_mask = remaining;
    if (remaining != 0)
        return (int)mask;
    simulation_event_release_references_43d56c(manager->world, event);
    return (int)simulation_event_free_43d254(manager, event);
}
