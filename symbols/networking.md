# Networking

Part of the MCC Reach system map. Build haloreach.dll, MCC 1.3528 (sha256 738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894). See the [system map](SYSTEM-MAP.md).

Networking covers everything from bringing a session up, through replicating game state between machines, out to the Xbox Live online stack and matchmaking. It is one of the two largest systems in the build.

Two layers sit on top of each other. The lower layer is Bungie's own Halo networking: sessions, a channel and bitstream transport, replication of networked objects, and host migration. The upper layer is the Xbox Live online stack that MCC links in: the Xbox Authentication Library (XAL), the Xbox Services library, a web transport (libHttpClient, websockets, cpprest), and a task queue. A thin set of `mcc_*` functions glues the Halo session code to that online stack.

Read the online subsystems with care. More than half of the `online` tag is an unnamed cluster tail grouped only by shared byte patterns, so most online names below are inferred from vtable slots and library structure, not from gameplay behavior.

Coverage: 2368 of 4585 functions carrying this system tag have a name (775 supported, 0 corroborated, 1593 inferred). The remaining 2217 are tagged to the system but not yet named.

## Subsystems and named functions

### session

The net_session state, its flow state machine, and life-cycle transitions. net_session rows and the duplicate `session` tag were merged here.

Showing 22 of 247 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x440a4` | `player_configuration_set` | supported |
| `0x44d20` | `player_swap` | supported |
| `0x45644` | `local_machine_player_mapping_rebuild` | supported |
| `0x485e8` | `player_index_to_datum_handle` | supported |
| `0x52514` | `player_leave` | supported |
| `0x807e8` | `player_boot` | supported |
| `0x808f0` | `player_boot_request_validate` | supported |
| `0x251280` | `mcc_flow_can_use_online` | supported |
| `0x297844` | `mcc_flow_request_search` | supported |
| `0x2a314c` | `flow_request_post_with_kind_code` | supported |
| `0x2a3744` | `net_session_find_player_slot_by_identity` | supported |
| `0x2d8178` | `ui_message_post` | supported |
| `0x2da840` | `mcc_flow_is_in_session_state` | supported |
| `0x2daa14` | `mcc_flow_request_hnl_state_c` | supported |
| `0x34d3e0` | `mcc_hnl_get_game_identity` | supported |
| `0x34d6fc` | `mcc_hnl_record_mode_nibble` | supported |
| `0x34d738` | `mcc_hnl_set_content_source_kind` | supported |
| `0x38e938` | `net_session_local_peer_is_leader` | supported |
| `0x38e974` | `net_session_delegate_leadership_to_player_slot` | supported |
| `0x38ea2c` | `net_session_boot_player_slot` | supported |
| `0x38fae8` | `net_session_get_active_session` | supported |
| `0x393830` | `net_session_update_state` | supported |



### membership join

Joining a session, invites, party and lobby membership.

Showing 22 of 104 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x1e3034` | `mcc_invite_accept_thunk` | supported |
| `0x1ea298` | `mcc_host_net_send_slot` | supported |
| `0x1ea334` | `mcc_host_net_recv_slot` | supported |
| `0x1f5d30` | `mcc_startup_steam_init_join` | supported |
| `0x2294e4` | `mcc_lobby_start_countdown` | supported |
| `0x23d734` | `mcc_lobby_leave_to_menu` | supported |
| `0x243614` | `mcc_wstring_from_u64` | supported |
| `0x24ce80` | `mcc_invite_accepted` | supported |
| `0x24f4ac` | `mcc_invite_send` | supported |
| `0x250ca8` | `mcc_join_friend` | supported |
| `0x252604` | `mcc_join_leave_game_then_proceed` | supported |
| `0x2acb5c` | `ui_session_error_dialog_show` | supported |
| `0x32b39c` | `mcc_lobby_begin_mode_0a` | supported |
| `0x32b7e4` | `mcc_lobby_enter_custom` | supported |
| `0x32fcdc` | `mcc_steam_new_url_launch_parameters_thunk` | supported |
| `0x32fce4` | `mcc_join_steam_command_line` | supported |
| `0x34cef8` | `mcc_hnl_session_wrapper_get` | supported |
| `0x34d14c` | `mcc_party_record_set_countdown` | supported |
| `0x34d1e4` | `mcc_party_record_get_countdown_active` | supported |
| `0x34d344` | `mcc_hnl_record_set_guid` | supported |
| `0x34d644` | `mcc_party_record_set_game_mode` | supported |
| `0x34d8f8` | `mcc_hnl_record_set_flag10_bit5` | supported |



### replication

State replication and sync of networked objects. The duplicate `replication` and `netcode_replication` tags plus `sync` were merged here.

Showing 22 of 394 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x794e8` | `simulation_world_start_entities_create` | supported |
| `0x1014dc` | `blf_parse_cmpn_chunk_file` | supported |
| `0x10e794` | `event_participant_decode` | supported |
| `0x14d5d0` | `game_engine_megalo_team_entity_create` | supported |
| `0x3a4370` | `player_presence_boot_event_encode` | supported |
| `0x3a58a4` | `object_has_client_simulation_entity` | supported |
| `0x3a5cb8` | `game_engine_statborg_entity_create` | supported |
| `0x3a61a4` | `simulation_resolve_player_entity_id` | supported |
| `0x3a6210` | `game_campaign_metagame_entity_create` | supported |
| `0x3a664c` | `object_mark_simulation_dirty` | supported |
| `0x3a66f4` | `simulation_object_entity_remove` | supported |
| `0x3a9f28` | `simulation_mode_set_from_context` | supported |
| `0x3ab66c` | `simulation_view_find_by_channel` | supported |
| `0x3b03e4` | `simulation_event_default_calculate_relevance` | supported |
| `0x3b0664` | `biped_entity_get_name` | supported |
| `0x3b066c` | `biped_entity_get_state_size` | supported |
| `0x3bf844` | `simulation_view_update` | supported |
| `0x3c0e50` | `simulation_world_broadcast_sync_mode` | supported |
| `0x3c14b4` | `simulation_world_receive_catchup_update` | supported |
| `0x3c20c0` | `simulation_world_update_queue_limiter_update` | supported |
| `0x3c22f0` | `simulation_world_halt_manager_update` | supported |
| `0x3c2cfc` | `simulation_view_send_player_acknowledge` | supported |



### netcode transport

Packet and channel transport, net messages, and bitstream (bit-level) encoding.

Showing 22 of 702 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x8fb0` | `static_init_global_2d572b8` | supported |
| `0x6d9a4` | `map_variant_compare_serialized` | supported |
| `0xdcfc4` | `bitstream_write_bits_slow` | supported |
| `0x10c550` | `incident_audience_build_filtered` | supported |
| `0x2a3744` | `net_session_find_player_slot_by_identity` | supported |
| `0x3372d0` | `webapi_matchmaking_nightmap_image_request` | supported |
| `0x351e38` | `webapi_matchmaking_tips_request` | supported |
| `0x38e938` | `net_session_local_peer_is_leader` | supported |
| `0x38e974` | `net_session_delegate_leadership_to_player_slot` | supported |
| `0x38ea2c` | `net_session_boot_player_slot` | supported |
| `0x38fae8` | `net_session_get_active_session` | supported |
| `0x392874` | `net_session_begin_join` | supported |
| `0x393830` | `net_session_update_state` | supported |
| `0x3942d8` | `net_session_end` | supported |
| `0x394440` | `net_session_leave` | supported |
| `0x394e78` | `net_session_delegate_leadership` | supported |
| `0x394f94` | `net_session_leader_request_boot_peer` | supported |
| `0x395090` | `session_boot_machine` | supported |
| `0x39563c` | `net_message_join_abort_handle` | supported |
| `0x3958cc` | `net_session_peer_leave_handle` | supported |
| `0x395d10` | `session_machine_find_by_address` | supported |
| `0x395de8` | `session_remove_remote_machine` | supported |



### host migration

Host selection, loss detection, migration, and the network manager.

Showing 20 of 20 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x10008` | `host_message_queue_post_string_command` | supported |
| `0x255794` | `mcc_online_broadcast_packet` | supported |
| `0x3951ac` | `net_session_leave_become_host` | supported |
| `0x397048` | `net_session_host_lost` | supported |
| `0x402bd4` | `net_session_become_host` | supported |
| `0x402e8c` | `net_session_election_start` | supported |
| `0x403bcc` | `net_session_new_host_wait_update` | supported |
| `0x403e88` | `net_session_election_update` | supported |
| `0x425568` | `net_message_shared_encode_host_handoff_peer_handoff` | supported |
| `0x4255e0` | `net_message_shared_decode_host_handoff_peer_handoff` | supported |
| `0x42564c` | `net_message_encode_64bit_block_and_address` | supported |
| `0x425680` | `net_message_host_transition_decode` | supported |
| `0x4276fc` | `net_message_encode_two_64bit_blocks` | supported |
| `0x42b2c4` | `net_message_handle_peer_handoff` | supported |
| `0x44a234` | `net_message_handle_host_handoff` | supported |
| `0x44a6d4` | `net_session_election_evaluate` | supported |
| `0x473744` | `mcc_network_manager_get` | supported |
| `0x474244` | `mcc_network_manager_send` | supported |
| `0x4743d0` | `mcc_network_manager_receive` | supported |
| `0x392b84` | `network_session_reset_parameters_for_new_host` | inferred |



### privacy policy

Join privacy modes and the EAC anti-cheat join gate.

Showing 6 of 6 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x1eabf8` | `mcc_host_content_policy_lookup` | supported |
| `0x1fb608` | `mcc_privacy_set_join_mode` | supported |
| `0x2f4c50` | `mcc_privacy_vm_get` | supported |
| `0x2f4e0c` | `mcc_privacy_vm_set_mode` | supported |
| `0xad9e64` | `mcc_ui_eac_gate` | supported |
| `0xb8a310` | `mcc_eac_squad_violation_check` | inferred |



### online mcc

MCC glue that drives the online stack (mcc_online_*).

Showing 3 of 3 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x25119c` | `mcc_online_manager_player_count` | supported |
| `0x245850` | `mcc_online_full_leave` | inferred |
| `0x2512e0` | `mcc_online_local_users_flag_check` | inferred |



### online xal

Xbox Authentication Library: continuations, shared state, async queue, user set, client operations. Names are inferred from the library's vtable and type structure.

Showing 22 of 329 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x1e5590` | `Xal::Exception::vfunc1` | inferred |
| `0x1faa38` | `Xal::Platform::Oauth::TokenStackOperationFactoryOauth::vfunc0` | inferred |
| `0x209454` | `Xal::AsyncQueue::State::vfunc0` | inferred |
| `0x210fa0` | `Xal::Auth::DeviceInfoWin32::vfunc2` | inferred |
| `0x32f22c` | `Xal::User::vfunc0` | inferred |
| `0x5a73d0` | `Xal::Detail::ContinuationBase::vfunc6` | inferred |
| `0x5eba20` | `Xal::ClientOperation::vfunc3` | inferred |
| `0x9a3304` | `Xal::Auth::DeviceInfoWin32::vfunc3` | inferred |
| `0xa1f894` | `Xal::Auth::DeviceInfoWin32::vfunc4` | inferred |
| `0xe52280` | `Xal::Detail::OperationBaseInvariant::vfunc3` | inferred |
| `0x20ad318` | `Xal::Exception::vfunc0` | inferred |
| `0x20b06f4` | `Detail::Xal::Continuation::vfunc7` | inferred |
| `0x20b07a8` | `Detail::Xal::Continuation::vfunc7` | inferred |
| `0x20b084c` | `Detail::Xal::Continuation::vfunc7` | inferred |
| `0x20b08bc` | `Detail::Xal::Continuation::vfunc7` | inferred |
| `0x20b092c` | `Detail::Xal::Continuation::vfunc7` | inferred |
| `0x20b09e0` | `Detail::Xal::Continuation::vfunc7` | inferred |
| `0x20b1bcc` | `Detail::Xal::Continuation::vfunc2` | inferred |
| `0x20b1cec` | `Detail::Xal::Continuation::vfunc2` | inferred |
| `0x20b1d98` | `Detail::Xal::Continuation::vfunc2` | inferred |
| `0x20b1dc0` | `Detail::Xal::Continuation::vfunc2` | inferred |
| `0x20b1f18` | `Detail::Xal::Continuation::vfunc2` | inferred |



### online xbl services

Xbox Services library: user, social, real-time activity, REST and websocket pieces. Inferred from structure.

Showing 22 of 396 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x1e0520` | `XblRealTimeActivitySubscription::vfunc0` | inferred |
| `0x282d90` | `xbox::services::legacy::xbox_services_error_code_category_impl::vfunc1` | inferred |
| `0x29dc00` | `Z::services::xbox::Callable::vfunc0` | inferred |
| `0x9084e0` | `J::services::xbox::ClientOperation::vfunc1` | inferred |
| `0x2669870` | `xbox::httpclient::hc_task::vfunc0` | inferred |
| `0x26698d0` | `xbox::httpclient::winhttp_http_task::vfunc0` | inferred |
| `0x26845e0` | `XblMultiplayerSession::vfunc0` | inferred |
| `0x26888e0` | `XblMultiplayerSession::vfunc1` | inferred |
| `0x2696a70` | `Z::services::xbox::Callable::vfunc1` | inferred |
| `0x2696a80` | `Z::services::xbox::Callable::vfunc1` | inferred |
| `0x2696a90` | `Z::services::xbox::Callable::vfunc1` | inferred |
| `0x2696b50` | `Z::services::xbox::Callable::vfunc1` | inferred |
| `0x2696b60` | `services::xbox::Callable::vfunc1` | inferred |
| `0x2696b70` | `Z::services::xbox::Callable::vfunc1` | inferred |
| `0x2696b80` | `Z::services::xbox::Callable::vfunc1` | inferred |
| `0x2696c30` | `Z::services::xbox::Callable::vfunc1` | inferred |
| `0x2696ce0` | `Z::services::xbox::Callable::vfunc1` | inferred |
| `0x2696d90` | `Z::services::xbox::Callable::vfunc1` | inferred |
| `0x2696f30` | `Z::services::xbox::Callable::vfunc1` | inferred |
| `0x2697080` | `Z::services::xbox::Callable::vfunc1` | inferred |
| `0x2697220` | `Z::services::xbox::Callable::vfunc1` | inferred |
| `0x26972d0` | `Z::services::xbox::Callable::vfunc1` | inferred |



### online web transport

Web transport: libHttpClient (hc_*), websockets, cpprest/asio.

Showing 4 of 4 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x2660df0` | `HC_CALL::vfunc0` | inferred |
| `0x2669740` | `HC_PERFORM_ENV::vfunc0` | inferred |
| `0x26747a0` | `hc_websocket_impl::vfunc0` | inferred |
| `0x267cfc0` | `HC_WEBSOCKET::vfunc0` | inferred |



### online taskqueue

TaskQueue and AsyncQueue implementation used by the online stack.

Showing 22 of 36 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x1e4100` | `TaskQueuePortContextImpl::vfunc5` | inferred |
| `0x206240` | `TaskQueuePortImpl::vfunc3` | inferred |
| `0x3562c0` | `TaskQueuePortContextImpl::vfunc3` | inferred |
| `0x5a8710` | `TaskQueuePortContextImpl::vfunc1` | inferred |
| `0x5af1f0` | `TaskQueuePortContextImpl::vfunc4` | inferred |
| `0x265a5c0` | `TaskQueueImpl::vfunc12` | inferred |
| `0x265a6d0` | `TaskQueuePortImpl::vfunc17` | inferred |
| `0x265a730` | `TaskQueuePortContextImpl::vfunc0` | inferred |
| `0x265a740` | `TaskQueuePortContextImpl::vfunc10` | inferred |
| `0x265a910` | `TaskQueuePortImpl::vfunc10` | inferred |
| `0x265a930` | `TaskQueueImpl::vfunc10` | inferred |
| `0x265a940` | `TaskQueueImpl::vfunc9` | inferred |
| `0x265ab50` | `TaskQueuePortImpl::vfunc8` | inferred |
| `0x265aba0` | `TaskQueuePortImpl::vfunc11` | inferred |
| `0x265abf0` | `TaskQueuePortImpl::vfunc12` | inferred |
| `0x265ae20` | `TaskQueueImpl::vfunc4` | inferred |
| `0x265b5c0` | `TaskQueuePortImpl::vfunc14` | inferred |
| `0x265b610` | `TaskQueuePortContextImpl::vfunc9` | inferred |
| `0x265b790` | `TaskQueuePortImpl::vfunc7` | inferred |
| `0x265b940` | `TaskQueuePortContextImpl::vfunc2` | inferred |
| `0x265b9b0` | `TaskQueuePortImpl::vfunc4` | inferred |
| `0x265bb70` | `TaskQueueImpl::vfunc7` | inferred |



### online std

STL template instantiations pulled into the online module.

Showing 22 of 109 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x1c8908` | `std::basic_stringstream::vfunc0` | inferred |
| `0x204dd0` | `std::_Ref_count_obj_alloc::vfunc0` | inferred |
| `0x207188` | `std::_Ref_count_obj_alloc::vfunc2` | inferred |
| `0x208fc0` | `std::_Ref_count_obj_alloc::vfunc2` | inferred |
| `0x211a00` | `std::_Ref_count_obj_alloc::vfunc2` | inferred |
| `0x211d30` | `std::_Ref_count_obj_alloc::vfunc2` | inferred |
| `0x234850` | `std::_Ref_count_obj_alloc::vfunc2` | inferred |
| `0x236d8c` | `std::_Ref_count_obj_alloc::vfunc2` | inferred |
| `0x23a444` | `std::basic_stringstream::vfunc0` | inferred |
| `0x23ad70` | `std::_Ref_count_obj_alloc::vfunc2` | inferred |
| `0x276130` | `std::_Ref_count_obj_alloc::vfunc2` | inferred |
| `0x276520` | `std::_Ref_count_obj_alloc::vfunc2` | inferred |
| `0x27d610` | `std::_Ref_count_obj_alloc::vfunc2` | inferred |
| `0x2bd720` | `std::_Ref_count_obj_alloc::vfunc2` | inferred |
| `0x2c0ef0` | `std::_Ref_count_obj_alloc::vfunc2` | inferred |
| `0x2c34bc` | `std::_Ref_count_obj_alloc::vfunc2` | inferred |
| `0x33fd90` | `std::_Ref_count_obj_alloc::vfunc2` | inferred |
| `0x352da0` | `std::_Ref_count_obj_alloc::vfunc2` | inferred |
| `0x352dd0` | `std::_Ref_count_obj_alloc::vfunc2` | inferred |
| `0x3b2770` | `std::_Ref_count_obj_alloc::vfunc2` | inferred |
| `0x507f10` | `std::_Ref_count_obj_alloc::vfunc2` | inferred |
| `0x553780` | `std::_Ref_count_obj_alloc::vfunc2` | inferred |



### online unclassified

Residual byte-family members not yet cleanly placed. A few rows here are mis-tagged and belong to other systems.

Showing 18 of 18 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x2ee8d4` | `cui_binding_record__init` | inferred |
| `0x8fe7f0` | `hkpGsk_computeFacePlane` | inferred |
| `0x20c3918` | `X::Xal::OperationBase::vfunc5` | inferred |
| `0x20c3a50` | `X::Xal::OperationBaseNoTelemetry::vfunc5` | inferred |
| `0x20c3c90` | `X::Operations::State::Xal::StateOperationBase::vfunc5` | inferred |
| `0x20c4cec` | `X::Operations::State::Xal::StateOperationBase::vfunc6` | inferred |
| `0x20e4e74` | `X::Xal::SimpleClientOperation::vfunc5` | inferred |
| `0x20e54e0` | `X::Xal::SimpleClientOperation::vfunc9` | inferred |
| `0x265a560` | `Api::vfunc17` | inferred |
| `0x265a590` | `Api::vfunc12` | inferred |
| `0x265a710` | `Api::vfunc0` | inferred |
| `0x265b880` | `Api::vfunc2` | inferred |
| `0x265b8e0` | `Api::vfunc2` | inferred |
| `0x265b980` | `Api::vfunc18` | inferred |
| `0x265b990` | `Api::vfunc13` | inferred |
| `0x265c080` | `Api::vfunc1` | inferred |
| `0x265c0e0` | `Api::vfunc1` | inferred |
| `0x26dd820` | `AsyncContext::vfunc0` | inferred |


## Data structures

There is no single on-disk tag that describes the network layer; its structures are runtime objects recovered by direct reading of the code, so these are runtime layouts, not tag layouts.

- net_session: the session object the state machine runs on. Session state is set through `net_session_state_set` and advanced each tick by `net_session_update_state`. State values 1, 3 and 7 appear in the teardown and boot paths.
- Player slot and machine tables: `net_session_find_player_slot_by_identity`, `local_machine_player_mapping_rebuild` and `player_index_to_datum_handle` show a per-session table that maps machines and player identities to player datum handles.
- Bitstream: a bit-level reader/writer (`bitstream_write_bits_slow` and friends) encodes net messages and serialized blobs such as the map variant.

## Entry points and call flow

Known, grounded entry points (names from this build):

- Host handoff: `net_session_host_lost`, `net_session_become_host`, `net_session_leave_become_host` are the host-migration entry points.
- Membership: `mcc_startup_steam_init_join`, `mcc_invite_accept_thunk`, `mcc_lobby_start_countdown` drive join and lobby start on the MCC side.
- Transport: net messages are built and parsed through the `net_message_*` and bitstream functions; the same machinery carries the Forge edit command and the map variant.

Full packet-by-packet call flow is only partly mapped. The session state machine transitions are named but the complete state diagram is not yet proven end to end.

## Open questions / not yet mapped

- The online stack is dominated by an unnamed cluster tail. Names on XAL, Xbox Services and web transport are inferred from vtable slots and library layout, not from behavior, and should be treated as provisional.
- The exact meaning of individual net_session state numbers beyond the boot and teardown path is not fully established.
- Replication of specific object types (which fields sync, at what rate) is only partly mapped.
- A handful of rows under online_unclassified are mis-tagged (for example a Havok helper) and need re-homing.
