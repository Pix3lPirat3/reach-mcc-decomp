struct session_membership {
    unsigned char reserved0[8];
    unsigned int update_counter;
    unsigned char reserved_c[4];
    unsigned int host_peer_index;
    unsigned char reserved14[0x4420];
    unsigned int local_peer_index;
    unsigned int peer_update_counter;
};

extern "C" long long platform_session_player_list_report_d6b8(session_membership* membership, long long offset, long long state);

extern "C" long long c_network_session_membership__set_peer_state_39c668(session_membership* membership, int peer_index, long long state) {
    long long peer_offset = static_cast<long long>(peer_index) * 0x158;
    *reinterpret_cast<int*>(peer_offset + reinterpret_cast<char*>(membership) + 0x38) = static_cast<int>(state);
    if (static_cast<int>(state) == 8) {
        *reinterpret_cast<long long*>(peer_offset + reinterpret_cast<char*>(membership) + 0x168) = 0;
    }
    membership->update_counter = membership->update_counter + 1;
    membership->peer_update_counter = membership->peer_update_counter + 1;
    if (membership->update_counter == -1) {
        return peer_index;
    }
    long long host = membership->host_peer_index;
    if (static_cast<int>(host) == -1) {
        return host;
    }
    if (membership->local_peer_index != static_cast<unsigned int>(host)) {
        return host;
    }
    return platform_session_player_list_report_d6b8(membership, peer_offset, state);
}
