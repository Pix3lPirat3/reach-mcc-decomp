# Engine host (Unreal Engine 4 runtime and low-level services)

Part of the MCC Reach system map. Build haloreach.dll, MCC 1.3528 (sha256 738dd2d24ea3aea12e1ee9aa4a61094bf116027d42004c35a19e5048608b0894). See the [system map](SYSTEM-MAP.md).

Engine host is the Unreal Engine 4 runtime that MCC runs Reach inside, plus low-level memory, platform services and Halo-side engine-core glue. This is the single largest system by function count, and most of it is not Reach gameplay at all: it is the UE4 reflected runtime (Kismet/Blueprint libraries, the Gameplay Ability System, actors and components, media players, Wwise audio) that MCC wraps the game in.

Readers should treat this system as the host, not the game. Its presence is the main reason the binary is so large. Reach's own engine logic lives in the other systems; what is here is the shell MCC provides.

Coverage: 4372 of 5070 functions carrying this system tag have a name (4223 supported, 1 corroborated, 148 inferred). The remaining 698 are tagged to the system but not yet named.

## Subsystems and named functions

### memory

Allocators, pools, heap and memory-region bookkeeping.

Showing 16 of 177 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x15fd8` | `memory_region_carve` | supported |
| `0x387b0` | `memory_region_reserve_aligned_64k` | supported |
| `0x1d1bb4` | `fallback_optional_cache_memory_pool_create` | supported |
| `0x27bf7c` | `restricted_region_member_register_with_callback_2795f0` | supported |
| `0x2c3dc8` | `restricted_region_member_register_with_callback_2b821c` | supported |
| `0x2c3e70` | `restricted_region_member_register_with_callback_2b81f0` | supported |
| `0x2c3f18` | `restricted_region_member_register_with_callback_2b81c4` | supported |
| `0x2c3fc0` | `restricted_region_member_register_with_callback_2b81a0` | supported |
| `0x68911c` | `os_heap_alloc` | supported |
| `0x689140` | `os_heap_free` | supported |
| `0x689170` | `os_heap_realloc` | supported |
| `0x6893d4` | `os_query_logical_processor_information` | supported |
| `0x68a094` | `relative_heap_new` | supported |
| `0x68a270` | `relative_heap_alloc` | supported |
| `0x68a4b0` | `relative_heap_header_init` | supported |
| `0x68a720` | `relative_heap_block_create` | supported |



### platform

OS and store platform services (Steam, product ids, platform libraries).

Showing 2 of 2 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x32f5c0` | `mcc_steam_register_callbacks` | supported |
| `0x3c3ab4` | `mcc_game_id_to_product_index` | supported |



### ue unclassified

Showing 16 of 844 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x207810` | `UObject_GetFunctionCallspace` | supported |
| `0x908634` | `IConsoleVariable_SetInt` | supported |
| `0x98ae80` | `SAkWaapiFieldNamesConv_GetPrivateStaticClass` | supported |
| `0x98b1f4` | `SAkWaapiFieldNamesConv_StaticRegisterNatives` | supported |
| `0x9df3e4` | `WebBrowser_GetPrivateStaticClass` | supported |
| `0x9df520` | `WebBrowser_StaticRegisterNatives` | supported |
| `0x9df574` | `WebBrowser_execExecuteJavascript` | supported |
| `0x9df610` | `WebBrowser_execGetTitleText` | supported |
| `0x9df688` | `WebBrowser_execGetUrl` | supported |
| `0x9df704` | `WebBrowser_execLoadString` | supported |
| `0x9df828` | `WebBrowser_execLoadURL` | supported |
| `0x9f4be0` | `PartyMemberState_GetPrivateStaticClass` | supported |
| `0x9f4cc0` | `PartyMemberState_StaticRegisterNatives` | supported |
| `0x9f4efc` | `PartyMemberState_execIsLocalPlayer` | supported |
| `0x9f4f20` | `PartyMemberState_execIsPartyLeader` | supported |
| `0xa0c868` | `OnlineHotfixManager_GetPrivateStaticClass` | supported |



### ue audio wwise

Showing 16 of 162 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x980a3c` | `AkAcousticPortal_GetPrivateStaticClass` | supported |
| `0x980adc` | `AkAmbientSound_GetPrivateStaticClass` | supported |
| `0x980e78` | `AkCheckBox_GetPrivateStaticClass` | supported |
| `0x980fb8` | `AkGameplayStatics_GetPrivateStaticClass` | supported |
| `0x9811f4` | `AkAcousticPortal_StaticRegisterNatives` | supported |
| `0x981218` | `AkAmbientSound_StaticRegisterNatives` | supported |
| `0x981260` | `AkCheckBox_StaticRegisterNatives` | supported |
| `0x9812a8` | `AkGameplayStatics_StaticRegisterNatives` | supported |
| `0x9814f8` | `AkGameplayStatics_execAddOutputCaptureMarker` | supported |
| `0x981584` | `AkGameplayStatics_execCancelEventCallback` | supported |
| `0x981624` | `AkGameplayStatics_execClearBanks` | supported |
| `0x981638` | `AkAcousticPortal_execClosePortal` | supported |
| `0x981780` | `AkCheckBox_execGetAkItemId` | supported |
| `0x9817b0` | `AkCheckBox_execGetAkProperty` | supported |
| `0x981868` | `AkCheckBox_execGetCheckedState` | supported |
| `0x98188c` | `AkAcousticPortal_execGetCurrentState` | supported |



### ue components

Showing 16 of 1035 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x980d44` | `AkAudioInputComponent_GetPrivateStaticClass` | supported |
| `0x980f18` | `AkComponent_GetPrivateStaticClass` | supported |
| `0x98123c` | `AkAudioInputComponent_StaticRegisterNatives` | supported |
| `0x981284` | `AkComponent_StaticRegisterNatives` | supported |
| `0x98164c` | `AkGameplayStatics_execGetAkComponent` | supported |
| `0x981840` | `AkComponent_execGetAttenuationRadius` | supported |
| `0x981ed4` | `AkComponent_execPostAkEvent` | supported |
| `0x98205c` | `AkComponent_execPostAkEventAndWaitForEnd` | supported |
| `0x9821a8` | `AkComponent_execPostAkEventByName` | supported |
| `0x982408` | `AkComponent_execPostAssociatedAkEvent` | supported |
| `0x9824f4` | `AkComponent_execPostAssociatedAkEventAndWaitForEnd` | supported |
| `0x9825a4` | `AkAudioInputComponent_execPostAssociatedAudioInputEvent` | supported |
| `0x982d9c` | `AkComponent_execPostTrigger` | supported |
| `0x983018` | `AkComponent_execSetAttenuationScalingFactor` | supported |
| `0x983250` | `AkComponent_execSetListeners` | supported |
| `0x983754` | `AkComponent_execSetOutputBusVolume` | supported |



### ue media

Showing 16 of 127 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0xa2be44` | `BinkMediaPlayer_GetPrivateStaticClass` | supported |
| `0xa2c068` | `BinkMediaPlayer_StaticRegisterNatives` | supported |
| `0xa2c2cc` | `BinkMediaPlayer_execCanPause` | supported |
| `0xa2c2f0` | `BinkMediaPlayer_execCanPlay` | supported |
| `0xa2c328` | `BinkMediaPlayer_execCloseUrl` | supported |
| `0xa2c33c` | `BinkMediaPlayer_execDraw` | supported |
| `0xa2c47c` | `BinkMediaPlayer_execGetDuration` | supported |
| `0xa2c4a8` | `BinkMediaPlayer_execGetRate` | supported |
| `0xa2c4d0` | `BinkMediaPlayer_execGetTime` | supported |
| `0xa2c4fc` | `BinkMediaPlayer_execGetUrl` | supported |
| `0xa2c56c` | `BinkMediaPlayer_execIsLooping` | supported |
| `0xa2c590` | `BinkMediaPlayer_execIsPaused` | supported |
| `0xa2c5b4` | `BinkMediaPlayer_execIsPlaying` | supported |
| `0xa2c5d8` | `BinkMediaPlayer_execIsStopped` | supported |
| `0xa2c5fc` | `BinkMediaPlayer_execOpenUrl` | supported |
| `0xa2c6a4` | `BinkMediaPlayer_execPause` | supported |



### ue kismet

Showing 16 of 1078 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0xc486e4` | `SDUIFunctionLibrary_GetPrivateStaticClass` | supported |
| `0xc48d98` | `SDUIFunctionLibrary_StaticRegisterNatives` | supported |
| `0xc49490` | `SDUIFunctionLibrary_execBool_BindIsEnabled` | supported |
| `0xc495ac` | `SDUIFunctionLibrary_execBool_BindToggleState` | supported |
| `0xc496c8` | `SDUIFunctionLibrary_execColor_BindColorAndOpacity` | supported |
| `0xc497ec` | `SDUIFunctionLibrary_execColor_BindImageColorAndOpacity` | supported |
| `0xc49910` | `SDUIFunctionLibrary_execFloat_BindProgressBarPercent` | supported |
| `0xc49a54` | `SDUIFunctionLibrary_execFloat_BindRenderOpacity` | supported |
| `0xc49b98` | `SDUIFunctionLibrary_execFloat_BindScalarParameterValue` | supported |
| `0xc49d18` | `SDUIFunctionLibrary_execFloat_BindSliderValue` | supported |
| `0xc49eb0` | `SDUIFunctionLibrary_execGetColorByThemeName` | supported |
| `0xc4a018` | `SDUIFunctionLibrary_execInt32_BindActiveWidgetIndex` | supported |
| `0xc4aaf0` | `SDUIFunctionLibrary_execString_BindComboBoxStringOption` | supported |
| `0xc4ac10` | `SDUIFunctionLibrary_execText_BindEditableTextBoxText` | supported |
| `0xc4ad04` | `SDUIFunctionLibrary_execText_BindRichTextBlockText` | supported |
| `0xc4adf8` | `SDUIFunctionLibrary_execText_BindSDEditableTextBoxText` | supported |



### ue assetregistry

Showing 16 of 18 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x17696f4` | `AssetRegistry_GetPrivateStaticClass` | supported |
| `0x1769978` | `AssetRegistry_StaticRegisterNatives` | supported |
| `0x1769d80` | `AssetRegistry_execGetAllAssets` | supported |
| `0x1769e70` | `AssetRegistry_execGetAllCachedPaths` | supported |
| `0x176a038` | `AssetRegistry_execGetAssetByObjectPath` | supported |
| `0x176a188` | `AssetRegistry_execGetAssets` | supported |
| `0x176a2bc` | `AssetRegistry_execGetAssetsByClass` | supported |
| `0x176a3e0` | `AssetRegistry_execGetAssetsByPackageName` | supported |
| `0x176a504` | `AssetRegistry_execGetAssetsByPath` | supported |
| `0x176a9d8` | `AssetRegistry_execGetSubPaths` | supported |
| `0x176acf0` | `AssetRegistry_execHasAssets` | supported |
| `0x176aeac` | `AssetRegistry_execIsLoadingAssets` | supported |
| `0x176b1c8` | `AssetRegistry_execPrioritizeSearchPath` | supported |
| `0x176b268` | `AssetRegistry_execRunAssetsThroughFilter` | supported |
| `0x176b39c` | `AssetRegistry_execScanFilesSynchronous` | supported |
| `0x176b4bc` | `AssetRegistry_execScanModifiedAssetFiles` | supported |



### ue actor

Showing 16 of 511 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x9fe1ac` | `HUD_execNextDebugTarget` | supported |
| `0x9fe1c4` | `Pawn_execDetachFromControllerPendingDestroy` | supported |
| `0x1d5b458` | `Actor_GetPrivateStaticClass` | supported |
| `0x1d5be78` | `Actor_StaticRegisterNatives` | supported |
| `0x1d5c1d8` | `Actor_execActorHasTag` | supported |
| `0x1d5c260` | `Actor_execAddComponent` | supported |
| `0x1d5c3f4` | `Actor_execAddTickPrerequisiteActor` | supported |
| `0x1d5c474` | `Actor_execAddTickPrerequisiteComponent` | supported |
| `0x1d5c4f4` | `Actor_execDetachRootComponentFromParent` | supported |
| `0x1d5c568` | `Actor_execFlushNetDormancy` | supported |
| `0x1d5c57c` | `Actor_execForceNetUpdate` | supported |
| `0x1d5c594` | `Actor_execGetActorBounds` | supported |
| `0x1d5c6ac` | `Actor_execGetActorEnableCollision` | supported |
| `0x1d5c6c8` | `Actor_execGetActorEyesViewPoint` | supported |
| `0x1d5c7a4` | `Actor_execGetActorForwardVector` | supported |
| `0x1d5c808` | `Actor_execGetActorRelativeScale3D` | supported |



### ue settings

Showing 16 of 53 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x1dbbff8` | `GameUserSettings_GetPrivateStaticClass` | supported |
| `0x1dbc248` | `GameUserSettings_StaticRegisterNatives` | supported |
| `0x1dbc68c` | `GameUserSettings_execEnableHDRDisplayOutput` | supported |
| `0x1dbc744` | `GameUserSettings_execGetAntiAliasingQuality` | supported |
| `0x1dbc768` | `GameUserSettings_execGetAudioQualityLevel` | supported |
| `0x1dbc780` | `GameUserSettings_execGetCurrentHDRDisplayNits` | supported |
| `0x1dbc7a4` | `GameUserSettings_execGetDefaultResolution` | supported |
| `0x1dbc7d4` | `GameUserSettings_execGetDefaultResolutionScale` | supported |
| `0x1dbc800` | `GameUserSettings_execGetDefaultWindowMode` | supported |
| `0x1dbc824` | `GameUserSettings_execGetDefaultWindowPosition` | supported |
| `0x1dbc854` | `GameUserSettings_execGetDesktopResolution` | supported |
| `0x1dbc884` | `GameUserSettings_execGetFoliageQuality` | supported |
| `0x1dbc8d0` | `GameUserSettings_execGetFullscreenDisplayIndex` | supported |
| `0x1dbc918` | `GameUserSettings_execGetGameBrightness` | supported |
| `0x1dbc940` | `GameUserSettings_execGetGameResolutionScale` | supported |
| `0x1dbc968` | `GameUserSettings_execGetGameUserSettings` | supported |



### ue ability

Showing 16 of 365 named functions in this subsystem (names and the rest of the set live in symbols.csv).

| RVA | Name | Confidence |
| --- | --- | --- |
| `0x1ee9b6c` | `GameplayTask_GetPrivateStaticClass` | supported |
| `0x1ee9d34` | `GameplayTask_ClaimResource_GetPrivateStaticClass` | supported |
| `0x1ee9dd4` | `GameplayTask_SpawnActor_GetPrivateStaticClass` | supported |
| `0x1ee9f14` | `GameplayTask_WaitDelay_GetPrivateStaticClass` | supported |
| `0x1ee9fb4` | `GameplayTasksComponent_GetPrivateStaticClass` | supported |
| `0x1eea064` | `GameplayTask_StaticRegisterNatives` | supported |
| `0x1eea088` | `GameplayTask_ClaimResource_StaticRegisterNatives` | supported |
| `0x1eea0ac` | `GameplayTask_SpawnActor_StaticRegisterNatives` | supported |
| `0x1eea0d0` | `GameplayTask_WaitDelay_StaticRegisterNatives` | supported |
| `0x1eea0f4` | `GameplayTasksComponent_StaticRegisterNatives` | supported |
| `0x1eea314` | `GameplayTask_SpawnActor_execBeginSpawningActor` | supported |
| `0x1eea3e0` | `GameplayTask_ClaimResource_execClaimResource` | supported |
| `0x1eea520` | `GameplayTask_ClaimResource_execClaimResources` | supported |
| `0x1eea6cc` | `GameplayTask_execEndTask` | supported |
| `0x1eea6e0` | `GameplayTask_SpawnActor_execFinishSpawningActor` | supported |
| `0x1eea79c` | `GameplayTasksComponent_execK2_RunGameplayTask` | supported |


## Data structures

Most structures here are Unreal UObject/UClass instances defined by UE4 reflection, plus allocator and pool descriptors on the memory side. The `matg` globals tag (on-disk) carries engine-wide globals and string tables.

Runtime memory pools (name, count, element size) are listed in pools.csv; the memory subsystem creates and tracks them.

## Entry points and call flow

Entry points: the UObject machinery (`UObject_ProcessEvent`, `UE4CodeGen_Private_ConstructUClass` and friends) is Unreal's own reflection and dispatch. The memory subsystem brings allocators and pools up at process start.

This system is documented by component rather than by a Reach call trace, because its flow is Unreal's, not Reach's.

## Open questions / not yet mapped

- A large part of ue_runtime is an unclassified cluster tail that matches no name rule yet.
- Which Unreal components Reach actually uses (versus those merely present in the engine) is not separated.
- The Halo engine-core glue is small and only partly named.
