library tizen_interop;

import 'dart:ffi';

import '../../src/bindings/6.0/generated_symbols.dart';
import '../../src/bindings/6.0/generated_bindings_accounts_svc.dart';
import '../../src/bindings/6.0/generated_bindings_appcore_agent.dart';
import '../../src/bindings/6.0/generated_bindings_asp.dart';
import '../../src/bindings/6.0/generated_bindings_badge.dart';
import '../../src/bindings/6.0/generated_bindings_bundle.dart';
import '../../src/bindings/6.0/generated_bindings_calendar_service2.dart';
import '../../src/bindings/6.0/generated_bindings_capi_appfw_alarm.dart';
import '../../src/bindings/6.0/generated_bindings_capi_appfw_app_common.dart';
import '../../src/bindings/6.0/generated_bindings_capi_appfw_app_control.dart';
import '../../src/bindings/6.0/generated_bindings_capi_appfw_app_manager.dart';
import '../../src/bindings/6.0/generated_bindings_capi_appfw_application.dart';
import '../../src/bindings/6.0/generated_bindings_capi_appfw_event.dart';
import '../../src/bindings/6.0/generated_bindings_capi_appfw_job_scheduler.dart';
import '../../src/bindings/6.0/generated_bindings_capi_appfw_package_manager.dart';
import '../../src/bindings/6.0/generated_bindings_capi_appfw_preference.dart';
import '../../src/bindings/6.0/generated_bindings_capi_base_common.dart';
import '../../src/bindings/6.0/generated_bindings_capi_content_media_content.dart';
import '../../src/bindings/6.0/generated_bindings_capi_content_mime_type.dart';
import '../../src/bindings/6.0/generated_bindings_capi_context.dart';
import '../../src/bindings/6.0/generated_bindings_capi_context_motion.dart';
import '../../src/bindings/6.0/generated_bindings_capi_geofence_manager.dart';
import '../../src/bindings/6.0/generated_bindings_capi_location_manager.dart';
import '../../src/bindings/6.0/generated_bindings_capi_media_audio_io.dart';
import '../../src/bindings/6.0/generated_bindings_capi_media_camera.dart';
import '../../src/bindings/6.0/generated_bindings_capi_media_codec.dart';
import '../../src/bindings/6.0/generated_bindings_capi_media_controller.dart';
import '../../src/bindings/6.0/generated_bindings_capi_media_image_util.dart';
import '../../src/bindings/6.0/generated_bindings_capi_media_metadata_editor.dart';
import '../../src/bindings/6.0/generated_bindings_capi_media_metadata_extractor.dart';
import '../../src/bindings/6.0/generated_bindings_capi_media_player.dart';
import '../../src/bindings/6.0/generated_bindings_capi_media_radio.dart';
import '../../src/bindings/6.0/generated_bindings_capi_media_recorder.dart';
import '../../src/bindings/6.0/generated_bindings_capi_media_screen_mirroring.dart';
import '../../src/bindings/6.0/generated_bindings_capi_media_sound_manager.dart';
import '../../src/bindings/6.0/generated_bindings_capi_media_sound_pool.dart';
import '../../src/bindings/6.0/generated_bindings_capi_media_streamer.dart';
import '../../src/bindings/6.0/generated_bindings_capi_media_streamrecorder.dart';
import '../../src/bindings/6.0/generated_bindings_capi_media_thumbnail_util.dart';
import '../../src/bindings/6.0/generated_bindings_capi_media_tone_player.dart';
import '../../src/bindings/6.0/generated_bindings_capi_media_tool.dart';
import '../../src/bindings/6.0/generated_bindings_capi_media_wav_player.dart';
import '../../src/bindings/6.0/generated_bindings_capi_mediademuxer.dart';
import '../../src/bindings/6.0/generated_bindings_capi_mediamuxer.dart';
import '../../src/bindings/6.0/generated_bindings_capi_messaging_email.dart';
import '../../src/bindings/6.0/generated_bindings_capi_network_bluetooth.dart';
import '../../src/bindings/6.0/generated_bindings_capi_network_connection.dart';
import '../../src/bindings/6.0/generated_bindings_capi_network_http.dart';
import '../../src/bindings/6.0/generated_bindings_capi_network_inm.dart';
import '../../src/bindings/6.0/generated_bindings_capi_network_mtp.dart';
import '../../src/bindings/6.0/generated_bindings_capi_network_softap.dart';
import '../../src/bindings/6.0/generated_bindings_capi_network_stc.dart';
import '../../src/bindings/6.0/generated_bindings_capi_network_wifi_manager.dart';
import '../../src/bindings/6.0/generated_bindings_capi_privacy_privilege_manager.dart';
import '../../src/bindings/6.0/generated_bindings_capi_system_device.dart';
import '../../src/bindings/6.0/generated_bindings_capi_system_info.dart';
import '../../src/bindings/6.0/generated_bindings_capi_system_media_key.dart';
import '../../src/bindings/6.0/generated_bindings_capi_system_peripheral_io.dart';
import '../../src/bindings/6.0/generated_bindings_capi_system_runtime_info.dart';
import '../../src/bindings/6.0/generated_bindings_capi_system_sensor.dart';
import '../../src/bindings/6.0/generated_bindings_capi_system_system_settings.dart';
import '../../src/bindings/6.0/generated_bindings_capi_system_usbhost.dart';
import '../../src/bindings/6.0/generated_bindings_capi_ui_autofill.dart';
import '../../src/bindings/6.0/generated_bindings_capi_ui_autofill_common.dart';
import '../../src/bindings/6.0/generated_bindings_capi_ui_autofill_manager.dart';
import '../../src/bindings/6.0/generated_bindings_capi_ui_autofill_service.dart';
import '../../src/bindings/6.0/generated_bindings_capi_ui_inputmethod.dart';
import '../../src/bindings/6.0/generated_bindings_capi_ui_inputmethod_manager.dart';
import '../../src/bindings/6.0/generated_bindings_capi_vpnsvc.dart';
import '../../src/bindings/6.0/generated_bindings_capi_web_url_download.dart';
import '../../src/bindings/6.0/generated_bindings_cbhm.dart';
import '../../src/bindings/6.0/generated_bindings_contacts_service2.dart';
import '../../src/bindings/6.0/generated_bindings_core_sync_client.dart';
import '../../src/bindings/6.0/generated_bindings_csr_client.dart';
import '../../src/bindings/6.0/generated_bindings_data_control.dart';
import '../../src/bindings/6.0/generated_bindings_device_certificate_manager.dart';
import '../../src/bindings/6.0/generated_bindings_diagnostics.dart';
import '../../src/bindings/6.0/generated_bindings_dlog.dart';
import '../../src/bindings/6.0/generated_bindings_dpm.dart';
// import '../../src/bindings/6.0/generated_bindings_eom.dart';
import '../../src/bindings/6.0/generated_bindings_feedback.dart';
import '../../src/bindings/6.0/generated_bindings_fido_client.dart';
import '../../src/bindings/6.0/generated_bindings_iotcon.dart';
import '../../src/bindings/6.0/generated_bindings_key_manager_client.dart';
import '../../src/bindings/6.0/generated_bindings_ma.dart';
import '../../src/bindings/6.0/generated_bindings_message_port.dart';
import '../../src/bindings/6.0/generated_bindings_mv_barcode_detector.dart';
import '../../src/bindings/6.0/generated_bindings_mv_barcode_generator.dart';
import '../../src/bindings/6.0/generated_bindings_mv_common.dart';
import '../../src/bindings/6.0/generated_bindings_mv_face.dart';
import '../../src/bindings/6.0/generated_bindings_mv_image.dart';
import '../../src/bindings/6.0/generated_bindings_mv_inference.dart';
import '../../src/bindings/6.0/generated_bindings_mv_surveillance.dart';
import '../../src/bindings/6.0/generated_bindings_notification.dart';
import '../../src/bindings/6.0/generated_bindings_notification_ex.dart';
import '../../src/bindings/6.0/generated_bindings_nsd_dns_sd.dart';
import '../../src/bindings/6.0/generated_bindings_nsd_ssdp.dart';
import '../../src/bindings/6.0/generated_bindings_oauth2.dart';
import '../../src/bindings/6.0/generated_bindings_phonenumber_utils.dart';
import '../../src/bindings/6.0/generated_bindings_privilege_info.dart';
import '../../src/bindings/6.0/generated_bindings_push.dart';
import '../../src/bindings/6.0/generated_bindings_rpc_port.dart';
import '../../src/bindings/6.0/generated_bindings_shortcut.dart';
import '../../src/bindings/6.0/generated_bindings_storage.dart';
import '../../src/bindings/6.0/generated_bindings_stt.dart';
import '../../src/bindings/6.0/generated_bindings_stt_engine.dart';
import '../../src/bindings/6.0/generated_bindings_tbm.dart';
import '../../src/bindings/6.0/generated_bindings_ttrace.dart';
import '../../src/bindings/6.0/generated_bindings_tts.dart';
import '../../src/bindings/6.0/generated_bindings_tts_engine.dart';
import '../../src/bindings/6.0/generated_bindings_update_control.dart';
import '../../src/bindings/6.0/generated_bindings_vc.dart';
import '../../src/bindings/6.0/generated_bindings_vc_engine.dart';
import '../../src/bindings/6.0/generated_bindings_vc_manager.dart';
import '../../src/bindings/6.0/generated_bindings_wifi_direct.dart';
import '../../src/bindings/6.0/generated_bindings_yaca.dart';
import '../../src/lookup_provider.dart';

export '../../src/extensions.dart';
export '../../src/bindings/6.0/generated_bindings_accounts_svc.dart';
export '../../src/bindings/6.0/generated_bindings_appcore_agent.dart';
export '../../src/bindings/6.0/generated_bindings_asp.dart';
export '../../src/bindings/6.0/generated_bindings_badge.dart';
export '../../src/bindings/6.0/generated_bindings_bundle.dart';
export '../../src/bindings/6.0/generated_bindings_calendar_service2.dart';
export '../../src/bindings/6.0/generated_bindings_capi_appfw_alarm.dart';
export '../../src/bindings/6.0/generated_bindings_capi_appfw_app_common.dart';
export '../../src/bindings/6.0/generated_bindings_capi_appfw_app_control.dart';
export '../../src/bindings/6.0/generated_bindings_capi_appfw_app_manager.dart';
export '../../src/bindings/6.0/generated_bindings_capi_appfw_application.dart';
export '../../src/bindings/6.0/generated_bindings_capi_appfw_event.dart';
export '../../src/bindings/6.0/generated_bindings_capi_appfw_job_scheduler.dart';
export '../../src/bindings/6.0/generated_bindings_capi_appfw_package_manager.dart';
export '../../src/bindings/6.0/generated_bindings_capi_appfw_preference.dart';
export '../../src/bindings/6.0/generated_bindings_capi_base_common.dart';
export '../../src/bindings/6.0/generated_bindings_capi_content_media_content.dart';
export '../../src/bindings/6.0/generated_bindings_capi_content_mime_type.dart';
export '../../src/bindings/6.0/generated_bindings_capi_context.dart';
export '../../src/bindings/6.0/generated_bindings_capi_context_motion.dart';
export '../../src/bindings/6.0/generated_bindings_capi_geofence_manager.dart';
export '../../src/bindings/6.0/generated_bindings_capi_location_manager.dart';
export '../../src/bindings/6.0/generated_bindings_capi_media_audio_io.dart';
export '../../src/bindings/6.0/generated_bindings_capi_media_camera.dart'
    hide UnnamedUnion1, UnnamedStruct1;
export '../../src/bindings/6.0/generated_bindings_capi_media_codec.dart';
export '../../src/bindings/6.0/generated_bindings_capi_media_controller.dart';
export '../../src/bindings/6.0/generated_bindings_capi_media_image_util.dart';
export '../../src/bindings/6.0/generated_bindings_capi_media_metadata_editor.dart';
export '../../src/bindings/6.0/generated_bindings_capi_media_metadata_extractor.dart';
export '../../src/bindings/6.0/generated_bindings_capi_media_player.dart';
export '../../src/bindings/6.0/generated_bindings_capi_media_radio.dart';
export '../../src/bindings/6.0/generated_bindings_capi_media_recorder.dart';
export '../../src/bindings/6.0/generated_bindings_capi_media_screen_mirroring.dart';
export '../../src/bindings/6.0/generated_bindings_capi_media_sound_manager.dart';
export '../../src/bindings/6.0/generated_bindings_capi_media_sound_pool.dart';
export '../../src/bindings/6.0/generated_bindings_capi_media_streamer.dart';
export '../../src/bindings/6.0/generated_bindings_capi_media_streamrecorder.dart';
export '../../src/bindings/6.0/generated_bindings_capi_media_thumbnail_util.dart';
export '../../src/bindings/6.0/generated_bindings_capi_media_tone_player.dart';
export '../../src/bindings/6.0/generated_bindings_capi_media_tool.dart';
export '../../src/bindings/6.0/generated_bindings_capi_media_wav_player.dart';
export '../../src/bindings/6.0/generated_bindings_capi_mediademuxer.dart';
export '../../src/bindings/6.0/generated_bindings_capi_mediamuxer.dart';
export '../../src/bindings/6.0/generated_bindings_capi_messaging_email.dart';
export '../../src/bindings/6.0/generated_bindings_capi_network_bluetooth.dart';
export '../../src/bindings/6.0/generated_bindings_capi_network_connection.dart';
export '../../src/bindings/6.0/generated_bindings_capi_network_http.dart';
export '../../src/bindings/6.0/generated_bindings_capi_network_inm.dart';
export '../../src/bindings/6.0/generated_bindings_capi_network_mtp.dart';
export '../../src/bindings/6.0/generated_bindings_capi_network_softap.dart';
export '../../src/bindings/6.0/generated_bindings_capi_network_stc.dart';
export '../../src/bindings/6.0/generated_bindings_capi_network_wifi_manager.dart';
export '../../src/bindings/6.0/generated_bindings_capi_privacy_privilege_manager.dart';
export '../../src/bindings/6.0/generated_bindings_capi_system_device.dart';
export '../../src/bindings/6.0/generated_bindings_capi_system_info.dart';
export '../../src/bindings/6.0/generated_bindings_capi_system_media_key.dart';
export '../../src/bindings/6.0/generated_bindings_capi_system_peripheral_io.dart';
export '../../src/bindings/6.0/generated_bindings_capi_system_runtime_info.dart';
export '../../src/bindings/6.0/generated_bindings_capi_system_sensor.dart';
export '../../src/bindings/6.0/generated_bindings_capi_system_system_settings.dart';
export '../../src/bindings/6.0/generated_bindings_capi_system_usbhost.dart';
export '../../src/bindings/6.0/generated_bindings_capi_ui_autofill.dart';
export '../../src/bindings/6.0/generated_bindings_capi_ui_autofill_common.dart';
export '../../src/bindings/6.0/generated_bindings_capi_ui_autofill_manager.dart';
export '../../src/bindings/6.0/generated_bindings_capi_ui_autofill_service.dart';
export '../../src/bindings/6.0/generated_bindings_capi_ui_inputmethod.dart';
export '../../src/bindings/6.0/generated_bindings_capi_ui_inputmethod_manager.dart';
export '../../src/bindings/6.0/generated_bindings_capi_vpnsvc.dart';
export '../../src/bindings/6.0/generated_bindings_capi_web_url_download.dart';
export '../../src/bindings/6.0/generated_bindings_cbhm.dart';
export '../../src/bindings/6.0/generated_bindings_contacts_service2.dart';
export '../../src/bindings/6.0/generated_bindings_core_sync_client.dart';
export '../../src/bindings/6.0/generated_bindings_csr_client.dart';
export '../../src/bindings/6.0/generated_bindings_data_control.dart';
export '../../src/bindings/6.0/generated_bindings_device_certificate_manager.dart';
export '../../src/bindings/6.0/generated_bindings_diagnostics.dart';
export '../../src/bindings/6.0/generated_bindings_dlog.dart';
export '../../src/bindings/6.0/generated_bindings_dpm.dart';
// export '../../src/bindings/6.0/generated_bindings_eom.dart';
export '../../src/bindings/6.0/generated_bindings_feedback.dart';
export '../../src/bindings/6.0/generated_bindings_fido_client.dart';
export '../../src/bindings/6.0/generated_bindings_iotcon.dart';
export '../../src/bindings/6.0/generated_bindings_key_manager_client.dart';
export '../../src/bindings/6.0/generated_bindings_ma.dart';
export '../../src/bindings/6.0/generated_bindings_message_port.dart';
export '../../src/bindings/6.0/generated_bindings_mv_barcode_detector.dart';
export '../../src/bindings/6.0/generated_bindings_mv_barcode_generator.dart';
export '../../src/bindings/6.0/generated_bindings_mv_common.dart';
export '../../src/bindings/6.0/generated_bindings_mv_face.dart';
export '../../src/bindings/6.0/generated_bindings_mv_image.dart';
export '../../src/bindings/6.0/generated_bindings_mv_inference.dart';
export '../../src/bindings/6.0/generated_bindings_mv_surveillance.dart';
export '../../src/bindings/6.0/generated_bindings_notification.dart';
export '../../src/bindings/6.0/generated_bindings_notification_ex.dart';
export '../../src/bindings/6.0/generated_bindings_nsd_dns_sd.dart';
export '../../src/bindings/6.0/generated_bindings_nsd_ssdp.dart';
export '../../src/bindings/6.0/generated_bindings_oauth2.dart';
export '../../src/bindings/6.0/generated_bindings_phonenumber_utils.dart';
export '../../src/bindings/6.0/generated_bindings_privilege_info.dart';
export '../../src/bindings/6.0/generated_bindings_push.dart';
export '../../src/bindings/6.0/generated_bindings_rpc_port.dart';
export '../../src/bindings/6.0/generated_bindings_shortcut.dart';
export '../../src/bindings/6.0/generated_bindings_storage.dart';
export '../../src/bindings/6.0/generated_bindings_stt.dart';
export '../../src/bindings/6.0/generated_bindings_stt_engine.dart';
export '../../src/bindings/6.0/generated_bindings_tbm.dart';
export '../../src/bindings/6.0/generated_bindings_time.dart';
export '../../src/bindings/6.0/generated_bindings_ttrace.dart';
export '../../src/bindings/6.0/generated_bindings_tts.dart';
export '../../src/bindings/6.0/generated_bindings_tts_engine.dart';
export '../../src/bindings/6.0/generated_bindings_update_control.dart';
export '../../src/bindings/6.0/generated_bindings_vc.dart';
export '../../src/bindings/6.0/generated_bindings_vc_engine.dart';
export '../../src/bindings/6.0/generated_bindings_vc_manager.dart';
export '../../src/bindings/6.0/generated_bindings_wifi_direct.dart';
export '../../src/bindings/6.0/generated_bindings_yaca.dart';

final _lookupProvider = LookupProvider();

S _getTizenInstance<S>(Map<String, List<String>> symbolMap,
    S Function(Pointer<T> Function<T extends NativeType>(String)) fromLookup) {
  return fromLookup(
    <T extends NativeType>(String symbolName) {
      _lookupProvider.registerSymbols(symbolMap);
      return _lookupProvider.lookup<T>(symbolName);
    },
  );
}

Tizen60CapiAppfwAppCommon? _tizenCapiAppfwAppCommon;
Tizen60CapiAppfwAppCommon get tizenCapiAppfwAppCommon =>
    _tizenCapiAppfwAppCommon ??= _getTizenInstance(
        capiAppfwAppCommonSymbols, Tizen60CapiAppfwAppCommon.fromLookup)!;

Tizen60CapiAppfwPreference? _tizenCapiAppfwPreference;
Tizen60CapiAppfwPreference get tizenCapiAppfwPreference =>
    _tizenCapiAppfwPreference ??= _getTizenInstance(
        capiAppfwPreferenceSymbols, Tizen60CapiAppfwPreference.fromLookup)!;

Tizen60CapiSystemRuntimeInfo? _tizenCapiSystemRuntimeInfo;
Tizen60CapiSystemRuntimeInfo get tizenCapiSystemRuntimeInfo =>
    _tizenCapiSystemRuntimeInfo ??= _getTizenInstance(
        capiSystemRuntimeInfoSymbols, Tizen60CapiSystemRuntimeInfo.fromLookup)!;

Tizen60AccountsSvc? _tizenAccountsSvc;
Tizen60AccountsSvc get tizenAccountsSvc => _tizenAccountsSvc ??=
    _getTizenInstance(accountsSvcSymbols, Tizen60AccountsSvc.fromLookup)!;

Tizen60AppcoreAgent? _tizenAppcoreAgent;
Tizen60AppcoreAgent get tizenAppcoreAgent => _tizenAppcoreAgent ??=
    _getTizenInstance(appcoreAgentSymbols, Tizen60AppcoreAgent.fromLookup)!;

Tizen60Asp? _tizenAsp;
Tizen60Asp get tizenAsp =>
    _tizenAsp ??= _getTizenInstance(aspSymbols, Tizen60Asp.fromLookup)!;

Tizen60Badge? _tizenBadge;
Tizen60Badge get tizenBadge =>
    _tizenBadge ??= _getTizenInstance(badgeSymbols, Tizen60Badge.fromLookup)!;

Tizen60Bundle? _tizenBundle;
Tizen60Bundle get tizenBundle => _tizenBundle ??=
    _getTizenInstance(bundleSymbols, Tizen60Bundle.fromLookup)!;

Tizen60CalendarService2? _tizenCalendarService2;
Tizen60CalendarService2 get tizenCalendarService2 =>
    _tizenCalendarService2 ??= _getTizenInstance(
        calendarService2Symbols, Tizen60CalendarService2.fromLookup)!;

Tizen60CapiAppfwAlarm? _tizenCapiAppfwAlarm;
Tizen60CapiAppfwAlarm get tizenCapiAppfwAlarm => _tizenCapiAppfwAlarm ??=
    _getTizenInstance(capiAppfwAlarmSymbols, Tizen60CapiAppfwAlarm.fromLookup)!;

Tizen60CapiAppfwAppControl? _tizenCapiAppfwAppControl;
Tizen60CapiAppfwAppControl get tizenCapiAppfwAppControl =>
    _tizenCapiAppfwAppControl ??= _getTizenInstance(
        capiAppfwAppControlSymbols, Tizen60CapiAppfwAppControl.fromLookup)!;

Tizen60CapiAppfwAppManager? _tizenCapiAppfwAppManager;
Tizen60CapiAppfwAppManager get tizenCapiAppfwAppManager =>
    _tizenCapiAppfwAppManager ??= _getTizenInstance(
        capiAppfwAppManagerSymbols, Tizen60CapiAppfwAppManager.fromLookup)!;

Tizen60CapiAppfwApplication? _tizenCapiAppfwApplication;
Tizen60CapiAppfwApplication get tizenCapiAppfwApplication =>
    _tizenCapiAppfwApplication ??= _getTizenInstance(
        capiAppfwApplicationSymbols, Tizen60CapiAppfwApplication.fromLookup)!;

Tizen60CapiAppfwEvent? _tizenCapiAppfwEvent;
Tizen60CapiAppfwEvent get tizenCapiAppfwEvent => _tizenCapiAppfwEvent ??=
    _getTizenInstance(capiAppfwEventSymbols, Tizen60CapiAppfwEvent.fromLookup)!;

Tizen60CapiAppfwJobScheduler? _tizenCapiAppfwJobScheduler;
Tizen60CapiAppfwJobScheduler get tizenCapiAppfwJobScheduler =>
    _tizenCapiAppfwJobScheduler ??= _getTizenInstance(
        capiAppfwJobSchedulerSymbols, Tizen60CapiAppfwJobScheduler.fromLookup)!;

Tizen60CapiAppfwPackageManager? _tizenCapiAppfwPackageManager;
Tizen60CapiAppfwPackageManager get tizenCapiAppfwPackageManager =>
    _tizenCapiAppfwPackageManager ??= _getTizenInstance(
        capiAppfwPackageManagerSymbols,
        Tizen60CapiAppfwPackageManager.fromLookup)!;

Tizen60CapiBaseCommon? _tizenCapiBaseCommon;
Tizen60CapiBaseCommon get tizenCapiBaseCommon => _tizenCapiBaseCommon ??=
    _getTizenInstance(capiBaseCommonSymbols, Tizen60CapiBaseCommon.fromLookup)!;

Tizen60CapiContentMediaContent? _tizenCapiContentMediaContent;
Tizen60CapiContentMediaContent get tizenCapiContentMediaContent =>
    _tizenCapiContentMediaContent ??= _getTizenInstance(
        capiContentMediaContentSymbols,
        Tizen60CapiContentMediaContent.fromLookup)!;

Tizen60CapiContentMimeType? _tizenCapiContentMimeType;
Tizen60CapiContentMimeType get tizenCapiContentMimeType =>
    _tizenCapiContentMimeType ??= _getTizenInstance(
        capiContentMimeTypeSymbols, Tizen60CapiContentMimeType.fromLookup)!;

Tizen60CapiContextMotion? _tizenCapiContextMotion;
Tizen60CapiContextMotion get tizenCapiContextMotion =>
    _tizenCapiContextMotion ??= _getTizenInstance(
        capiContextMotionSymbols, Tizen60CapiContextMotion.fromLookup)!;

Tizen60CapiContext? _tizenCapiContext;
Tizen60CapiContext get tizenCapiContext => _tizenCapiContext ??=
    _getTizenInstance(capiContextSymbols, Tizen60CapiContext.fromLookup)!;

Tizen60CapiGeofenceManager? _tizenCapiGeofenceManager;
Tizen60CapiGeofenceManager get tizenCapiGeofenceManager =>
    _tizenCapiGeofenceManager ??= _getTizenInstance(
        capiGeofenceManagerSymbols, Tizen60CapiGeofenceManager.fromLookup)!;

Tizen60CapiLocationManager? _tizenCapiLocationManager;
Tizen60CapiLocationManager get tizenCapiLocationManager =>
    _tizenCapiLocationManager ??= _getTizenInstance(
        capiLocationManagerSymbols, Tizen60CapiLocationManager.fromLookup)!;

Tizen60CapiMediaAudioIo? _tizenCapiMediaAudioIo;
Tizen60CapiMediaAudioIo get tizenCapiMediaAudioIo =>
    _tizenCapiMediaAudioIo ??= _getTizenInstance(
        capiMediaAudioIoSymbols, Tizen60CapiMediaAudioIo.fromLookup)!;

Tizen60CapiMediaCamera? _tizenCapiMediaCamera;
Tizen60CapiMediaCamera get tizenCapiMediaCamera =>
    _tizenCapiMediaCamera ??= _getTizenInstance(
        capiMediaCameraSymbols, Tizen60CapiMediaCamera.fromLookup)!;

Tizen60CapiMediaCodec? _tizenCapiMediaCodec;
Tizen60CapiMediaCodec get tizenCapiMediaCodec => _tizenCapiMediaCodec ??=
    _getTizenInstance(capiMediaCodecSymbols, Tizen60CapiMediaCodec.fromLookup)!;

Tizen60CapiMediaController? _tizenCapiMediaController;
Tizen60CapiMediaController get tizenCapiMediaController =>
    _tizenCapiMediaController ??= _getTizenInstance(
        capiMediaControllerSymbols, Tizen60CapiMediaController.fromLookup)!;

Tizen60CapiMediaImageUtil? _tizenCapiMediaImageUtil;
Tizen60CapiMediaImageUtil get tizenCapiMediaImageUtil =>
    _tizenCapiMediaImageUtil ??= _getTizenInstance(
        capiMediaImageUtilSymbols, Tizen60CapiMediaImageUtil.fromLookup)!;

Tizen60CapiMediaMetadataEditor? _tizenCapiMediaMetadataEditor;
Tizen60CapiMediaMetadataEditor get tizenCapiMediaMetadataEditor =>
    _tizenCapiMediaMetadataEditor ??= _getTizenInstance(
        capiMediaMetadataEditorSymbols,
        Tizen60CapiMediaMetadataEditor.fromLookup)!;

Tizen60CapiMediaMetadataExtractor? _tizenCapiMediaMetadataExtractor;
Tizen60CapiMediaMetadataExtractor get tizenCapiMediaMetadataExtractor =>
    _tizenCapiMediaMetadataExtractor ??= _getTizenInstance(
        capiMediaMetadataExtractorSymbols,
        Tizen60CapiMediaMetadataExtractor.fromLookup)!;

Tizen60CapiMediaPlayer? _tizenCapiMediaPlayer;
Tizen60CapiMediaPlayer get tizenCapiMediaPlayer =>
    _tizenCapiMediaPlayer ??= _getTizenInstance(
        capiMediaPlayerSymbols, Tizen60CapiMediaPlayer.fromLookup)!;

Tizen60CapiMediaRadio? _tizenCapiMediaRadio;
Tizen60CapiMediaRadio get tizenCapiMediaRadio => _tizenCapiMediaRadio ??=
    _getTizenInstance(capiMediaRadioSymbols, Tizen60CapiMediaRadio.fromLookup)!;

Tizen60CapiMediaRecorder? _tizenCapiMediaRecorder;
Tizen60CapiMediaRecorder get tizenCapiMediaRecorder =>
    _tizenCapiMediaRecorder ??= _getTizenInstance(
        capiMediaRecorderSymbols, Tizen60CapiMediaRecorder.fromLookup)!;

Tizen60CapiMediaScreenMirroring? _tizenCapiMediaScreenMirroring;
Tizen60CapiMediaScreenMirroring get tizenCapiMediaScreenMirroring =>
    _tizenCapiMediaScreenMirroring ??= _getTizenInstance(
        capiMediaScreenMirroringSymbols,
        Tizen60CapiMediaScreenMirroring.fromLookup)!;

Tizen60CapiMediaSoundManager? _tizenCapiMediaSoundManager;
Tizen60CapiMediaSoundManager get tizenCapiMediaSoundManager =>
    _tizenCapiMediaSoundManager ??= _getTizenInstance(
        capiMediaSoundManagerSymbols, Tizen60CapiMediaSoundManager.fromLookup)!;

Tizen60CapiMediaSoundPool? _tizenCapiMediaSoundPool;
Tizen60CapiMediaSoundPool get tizenCapiMediaSoundPool =>
    _tizenCapiMediaSoundPool ??= _getTizenInstance(
        capiMediaSoundPoolSymbols, Tizen60CapiMediaSoundPool.fromLookup)!;

Tizen60CapiMediaStreamer? _tizenCapiMediaStreamer;
Tizen60CapiMediaStreamer get tizenCapiMediaStreamer =>
    _tizenCapiMediaStreamer ??= _getTizenInstance(
        capiMediaStreamerSymbols, Tizen60CapiMediaStreamer.fromLookup)!;

Tizen60CapiMediaStreamrecorder? _tizenCapiMediaStreamrecorder;
Tizen60CapiMediaStreamrecorder get tizenCapiMediaStreamrecorder =>
    _tizenCapiMediaStreamrecorder ??= _getTizenInstance(
        capiMediaStreamrecorderSymbols,
        Tizen60CapiMediaStreamrecorder.fromLookup)!;

Tizen60CapiMediaThumbnailUtil? _tizenCapiMediaThumbnailUtil;
Tizen60CapiMediaThumbnailUtil get tizenCapiMediaThumbnailUtil =>
    _tizenCapiMediaThumbnailUtil ??= _getTizenInstance(
        capiMediaThumbnailUtilSymbols,
        Tizen60CapiMediaThumbnailUtil.fromLookup)!;

Tizen60CapiMediaTonePlayer? _tizenCapiMediaTonePlayer;
Tizen60CapiMediaTonePlayer get tizenCapiMediaTonePlayer =>
    _tizenCapiMediaTonePlayer ??= _getTizenInstance(
        capiMediaTonePlayerSymbols, Tizen60CapiMediaTonePlayer.fromLookup)!;

Tizen60CapiMediaTool? _tizenCapiMediaTool;
Tizen60CapiMediaTool get tizenCapiMediaTool => _tizenCapiMediaTool ??=
    _getTizenInstance(capiMediaToolSymbols, Tizen60CapiMediaTool.fromLookup)!;

Tizen60CapiMediaWavPlayer? _tizenCapiMediaWavPlayer;
Tizen60CapiMediaWavPlayer get tizenCapiMediaWavPlayer =>
    _tizenCapiMediaWavPlayer ??= _getTizenInstance(
        capiMediaWavPlayerSymbols, Tizen60CapiMediaWavPlayer.fromLookup)!;

Tizen60CapiMediademuxer? _tizenCapiMediademuxer;
Tizen60CapiMediademuxer get tizenCapiMediademuxer =>
    _tizenCapiMediademuxer ??= _getTizenInstance(
        capiMediademuxerSymbols, Tizen60CapiMediademuxer.fromLookup)!;

Tizen60CapiMediamuxer? _tizenCapiMediamuxer;
Tizen60CapiMediamuxer get tizenCapiMediamuxer => _tizenCapiMediamuxer ??=
    _getTizenInstance(capiMediamuxerSymbols, Tizen60CapiMediamuxer.fromLookup)!;

Tizen60CapiMessagingEmail? _tizenCapiMessagingEmail;
Tizen60CapiMessagingEmail get tizenCapiMessagingEmail =>
    _tizenCapiMessagingEmail ??= _getTizenInstance(
        capiMessagingEmailSymbols, Tizen60CapiMessagingEmail.fromLookup)!;

Tizen60CapiNetworkBluetooth? _tizenCapiNetworkBluetooth;
Tizen60CapiNetworkBluetooth get tizenCapiNetworkBluetooth =>
    _tizenCapiNetworkBluetooth ??= _getTizenInstance(
        capiNetworkBluetoothSymbols, Tizen60CapiNetworkBluetooth.fromLookup)!;

Tizen60CapiNetworkConnection? _tizenCapiNetworkConnection;
Tizen60CapiNetworkConnection get tizenCapiNetworkConnection =>
    _tizenCapiNetworkConnection ??= _getTizenInstance(
        capiNetworkConnectionSymbols, Tizen60CapiNetworkConnection.fromLookup)!;

Tizen60CapiNetworkHttp? _tizenCapiNetworkHttp;
Tizen60CapiNetworkHttp get tizenCapiNetworkHttp =>
    _tizenCapiNetworkHttp ??= _getTizenInstance(
        capiNetworkHttpSymbols, Tizen60CapiNetworkHttp.fromLookup)!;

Tizen60CapiNetworkInm? _tizenCapiNetworkInm;
Tizen60CapiNetworkInm get tizenCapiNetworkInm => _tizenCapiNetworkInm ??=
    _getTizenInstance(capiNetworkInmSymbols, Tizen60CapiNetworkInm.fromLookup)!;

Tizen60CapiNetworkMtp? _tizenCapiNetworkMtp;
Tizen60CapiNetworkMtp get tizenCapiNetworkMtp => _tizenCapiNetworkMtp ??=
    _getTizenInstance(capiNetworkMtpSymbols, Tizen60CapiNetworkMtp.fromLookup)!;

Tizen60CapiNetworkSoftap? _tizenCapiNetworkSoftap;
Tizen60CapiNetworkSoftap get tizenCapiNetworkSoftap =>
    _tizenCapiNetworkSoftap ??= _getTizenInstance(
        capiNetworkSoftapSymbols, Tizen60CapiNetworkSoftap.fromLookup)!;

Tizen60CapiNetworkStc? _tizenCapiNetworkStc;
Tizen60CapiNetworkStc get tizenCapiNetworkStc => _tizenCapiNetworkStc ??=
    _getTizenInstance(capiNetworkStcSymbols, Tizen60CapiNetworkStc.fromLookup)!;

Tizen60CapiNetworkWifiManager? _tizenCapiNetworkWifiManager;
Tizen60CapiNetworkWifiManager get tizenCapiNetworkWifiManager =>
    _tizenCapiNetworkWifiManager ??= _getTizenInstance(
        capiNetworkWifiManagerSymbols,
        Tizen60CapiNetworkWifiManager.fromLookup)!;

Tizen60CapiPrivacyPrivilegeManager? _tizenCapiPrivacyPrivilegeManager;
Tizen60CapiPrivacyPrivilegeManager get tizenCapiPrivacyPrivilegeManager =>
    _tizenCapiPrivacyPrivilegeManager ??= _getTizenInstance(
        capiPrivacyPrivilegeManagerSymbols,
        Tizen60CapiPrivacyPrivilegeManager.fromLookup)!;

Tizen60CapiSystemDevice? _tizenCapiSystemDevice;
Tizen60CapiSystemDevice get tizenCapiSystemDevice =>
    _tizenCapiSystemDevice ??= _getTizenInstance(
        capiSystemDeviceSymbols, Tizen60CapiSystemDevice.fromLookup)!;

Tizen60CapiSystemInfo? _tizenCapiSystemInfo;
Tizen60CapiSystemInfo get tizenCapiSystemInfo => _tizenCapiSystemInfo ??=
    _getTizenInstance(capiSystemInfoSymbols, Tizen60CapiSystemInfo.fromLookup)!;

Tizen60CapiSystemMediaKey? _tizenCapiSystemMediaKey;
Tizen60CapiSystemMediaKey get tizenCapiSystemMediaKey =>
    _tizenCapiSystemMediaKey ??= _getTizenInstance(
        capiSystemMediaKeySymbols, Tizen60CapiSystemMediaKey.fromLookup)!;

Tizen60CapiSystemPeripheralIo? _tizenCapiSystemPeripheralIo;
Tizen60CapiSystemPeripheralIo get tizenCapiSystemPeripheralIo =>
    _tizenCapiSystemPeripheralIo ??= _getTizenInstance(
        capiSystemPeripheralIoSymbols,
        Tizen60CapiSystemPeripheralIo.fromLookup)!;

Tizen60CapiSystemSensor? _tizenCapiSystemSensor;
Tizen60CapiSystemSensor get tizenCapiSystemSensor =>
    _tizenCapiSystemSensor ??= _getTizenInstance(
        capiSystemSensorSymbols, Tizen60CapiSystemSensor.fromLookup)!;

Tizen60CapiSystemSystemSettings? _tizenCapiSystemSystemSettings;
Tizen60CapiSystemSystemSettings get tizenCapiSystemSystemSettings =>
    _tizenCapiSystemSystemSettings ??= _getTizenInstance(
        capiSystemSystemSettingsSymbols,
        Tizen60CapiSystemSystemSettings.fromLookup)!;

Tizen60CapiSystemUsbhost? _tizenCapiSystemUsbhost;
Tizen60CapiSystemUsbhost get tizenCapiSystemUsbhost =>
    _tizenCapiSystemUsbhost ??= _getTizenInstance(
        capiSystemUsbhostSymbols, Tizen60CapiSystemUsbhost.fromLookup)!;

Tizen60CapiUiAutofill? _tizenCapiUiAutofill;
Tizen60CapiUiAutofill get tizenCapiUiAutofill => _tizenCapiUiAutofill ??=
    _getTizenInstance(capiUiAutofillSymbols, Tizen60CapiUiAutofill.fromLookup)!;

Tizen60CapiUiAutofillCommon? _tizenCapiUiAutofillCommon;
Tizen60CapiUiAutofillCommon get tizenCapiUiAutofillCommon =>
    _tizenCapiUiAutofillCommon ??= _getTizenInstance(
        capiUiAutofillCommonSymbols, Tizen60CapiUiAutofillCommon.fromLookup)!;

Tizen60CapiUiAutofillManager? _tizenCapiUiAutofillManager;
Tizen60CapiUiAutofillManager get tizenCapiUiAutofillManager =>
    _tizenCapiUiAutofillManager ??= _getTizenInstance(
        capiUiAutofillManagerSymbols, Tizen60CapiUiAutofillManager.fromLookup)!;

Tizen60CapiUiAutofillService? _tizenCapiUiAutofillService;
Tizen60CapiUiAutofillService get tizenCapiUiAutofillService =>
    _tizenCapiUiAutofillService ??= _getTizenInstance(
        capiUiAutofillServiceSymbols, Tizen60CapiUiAutofillService.fromLookup)!;

Tizen60CapiUiInputmethod? _tizenCapiUiInputmethod;
Tizen60CapiUiInputmethod get tizenCapiUiInputmethod =>
    _tizenCapiUiInputmethod ??= _getTizenInstance(
        capiUiInputmethodSymbols, Tizen60CapiUiInputmethod.fromLookup)!;

Tizen60CapiUiInputmethodManager? _tizenCapiUiInputmethodManager;
Tizen60CapiUiInputmethodManager get tizenCapiUiInputmethodManager =>
    _tizenCapiUiInputmethodManager ??= _getTizenInstance(
        capiUiInputmethodManagerSymbols,
        Tizen60CapiUiInputmethodManager.fromLookup)!;

Tizen60CapiVpnsvc? _tizenCapiVpnsvc;
Tizen60CapiVpnsvc get tizenCapiVpnsvc => _tizenCapiVpnsvc ??=
    _getTizenInstance(capiVpnsvcSymbols, Tizen60CapiVpnsvc.fromLookup)!;

Tizen60CapiWebUrlDownload? _tizenCapiWebUrlDownload;
Tizen60CapiWebUrlDownload get tizenCapiWebUrlDownload =>
    _tizenCapiWebUrlDownload ??= _getTizenInstance(
        capiWebUrlDownloadSymbols, Tizen60CapiWebUrlDownload.fromLookup)!;

Tizen60Cbhm? _tizenCbhm;
Tizen60Cbhm get tizenCbhm =>
    _tizenCbhm ??= _getTizenInstance(cbhmSymbols, Tizen60Cbhm.fromLookup)!;

Tizen60ContactsService2? _tizenContactsService2;
Tizen60ContactsService2 get tizenContactsService2 => _tizenContactsService2 ??=
    _getTizenInstance(contactsService2Symbols, Tizen60ContactsService2.fromLookup)!;

Tizen60CoreSyncClient? _tizenCoreSyncClient;
Tizen60CoreSyncClient get tizenCoreSyncClient => _tizenCoreSyncClient ??=
    _getTizenInstance(coreSyncClientSymbols, Tizen60CoreSyncClient.fromLookup)!;

Tizen60CsrClient? _tizenCsrClient;
Tizen60CsrClient get tizenCsrClient => _tizenCsrClient ??=
    _getTizenInstance(csrClientSymbols, Tizen60CsrClient.fromLookup)!;

Tizen60DataControl? _tizenDataControl;
Tizen60DataControl get tizenDataControl => _tizenDataControl ??=
    _getTizenInstance(dataControlSymbols, Tizen60DataControl.fromLookup)!;

Tizen60DeviceCertificateManager? _tizenDeviceCertificateManager;
Tizen60DeviceCertificateManager get tizenDeviceCertificateManager =>
    _tizenDeviceCertificateManager ??= _getTizenInstance(
        deviceCertificateManagerSymbols,
        Tizen60DeviceCertificateManager.fromLookup)!;

Tizen60Diagnostics? _tizenDiagnostics;
Tizen60Diagnostics get tizenDiagnostics => _tizenDiagnostics ??=
    _getTizenInstance(diagnosticsSymbols, Tizen60Diagnostics.fromLookup)!;

Tizen60Dlog? _tizenDlog;
Tizen60Dlog get tizenDlog =>
    _tizenDlog ??= _getTizenInstance(dlogSymbols, Tizen60Dlog.fromLookup)!;

Tizen60Dpm? _tizenDpm;
Tizen60Dpm get tizenDpm =>
    _tizenDpm ??= _getTizenInstance(dpmSymbols, Tizen60Dpm.fromLookup)!;

// Tizen60Eom? _tizenEom;
// Tizen60Eom get tizenEom => _tizenEom ??= _getTizenInstance(eomSymbols, Tizen60Eom.fromLookup)!;

Tizen60Feedback? _tizenFeedback;
Tizen60Feedback get tizenFeedback => _tizenFeedback ??=
    _getTizenInstance(feedbackSymbols, Tizen60Feedback.fromLookup)!;

Tizen60FidoClient? _tizenFidoClient;
Tizen60FidoClient get tizenFidoClient => _tizenFidoClient ??=
    _getTizenInstance(fidoClientSymbols, Tizen60FidoClient.fromLookup)!;

Tizen60Iotcon? _tizenIotcon;
Tizen60Iotcon get tizenIotcon => _tizenIotcon ??=
    _getTizenInstance(iotconSymbols, Tizen60Iotcon.fromLookup)!;

Tizen60KeyManagerClient? _tizenKeyManagerClient;
Tizen60KeyManagerClient get tizenKeyManagerClient =>
    _tizenKeyManagerClient ??= _getTizenInstance(
        keyManagerClientSymbols, Tizen60KeyManagerClient.fromLookup)!;

Tizen60Ma? _tizenMa;
Tizen60Ma get tizenMa =>
    _tizenMa ??= _getTizenInstance(maSymbols, Tizen60Ma.fromLookup)!;

Tizen60MessagePort? _tizenMessagePort;
Tizen60MessagePort get tizenMessagePort => _tizenMessagePort ??=
    _getTizenInstance(messagePortSymbols, Tizen60MessagePort.fromLookup)!;

Tizen60MvBarcodeDetector? _tizenMvBarcodeDetector;
Tizen60MvBarcodeDetector get tizenMvBarcodeDetector =>
    _tizenMvBarcodeDetector ??= _getTizenInstance(
        mv_barcode_detectorSymbols, Tizen60MvBarcodeDetector.fromLookup)!;

Tizen60MvBarcodeGenerator? _tizenMvBarcodeGenerator;
Tizen60MvBarcodeGenerator get tizenMvBarcodeGenerator =>
    _tizenMvBarcodeGenerator ??= _getTizenInstance(
        mv_barcode_generatorSymbols, Tizen60MvBarcodeGenerator.fromLookup)!;

Tizen60MvCommon? _tizenMvCommon;
Tizen60MvCommon get tizenMvCommon => _tizenMvCommon ??=
    _getTizenInstance(mv_commonSymbols, Tizen60MvCommon.fromLookup)!;

Tizen60MvFace? _tizenMvFace;
Tizen60MvFace get tizenMvFace => _tizenMvFace ??=
    _getTizenInstance(mv_faceSymbols, Tizen60MvFace.fromLookup)!;

Tizen60MvImage? _tizenMvImage;
Tizen60MvImage get tizenMvImage => _tizenMvImage ??=
    _getTizenInstance(mv_imageSymbols, Tizen60MvImage.fromLookup)!;

Tizen60MvInference? _tizenMvInference;
Tizen60MvInference get tizenMvInference => _tizenMvInference ??=
    _getTizenInstance(mv_inferenceSymbols, Tizen60MvInference.fromLookup)!;

Tizen60MvSurveillance? _tizenMvSurveillance;
Tizen60MvSurveillance get tizenMvSurveillance =>
    _tizenMvSurveillance ??= _getTizenInstance(
        mv_surveillanceSymbols, Tizen60MvSurveillance.fromLookup)!;

Tizen60Notification? _tizenNotification;
Tizen60Notification get tizenNotification => _tizenNotification ??=
    _getTizenInstance(notificationSymbols, Tizen60Notification.fromLookup)!;

Tizen60NotificationEx? _tizenNotificationEx;
Tizen60NotificationEx get tizenNotificationEx => _tizenNotificationEx ??=
    _getTizenInstance(notificationExSymbols, Tizen60NotificationEx.fromLookup)!;

Tizen60NsdDnsSd? _tizenNsdDnsSd;
Tizen60NsdDnsSd get tizenNsdDnsSd => _tizenNsdDnsSd ??=
    _getTizenInstance(nsdDnsSdSymbols, Tizen60NsdDnsSd.fromLookup)!;

Tizen60NsdSsdp? _tizenNsdSsdp;
Tizen60NsdSsdp get tizenNsdSsdp => _tizenNsdSsdp ??=
    _getTizenInstance(nsdSsdpSymbols, Tizen60NsdSsdp.fromLookup)!;

Tizen60Oauth2? _tizenOauth2;
Tizen60Oauth2 get tizenOauth2 => _tizenOauth2 ??=
    _getTizenInstance(oauth2Symbols, Tizen60Oauth2.fromLookup)!;

Tizen60PhonenumberUtils? _tizenPhonenumberUtils;
Tizen60PhonenumberUtils get tizenPhonenumberUtils =>
    _tizenPhonenumberUtils ??= _getTizenInstance(
        phonenumberUtilsSymbols, Tizen60PhonenumberUtils.fromLookup)!;

Tizen60PrivilegeInfo? _tizenPrivilegeInfo;
Tizen60PrivilegeInfo get tizenPrivilegeInfo => _tizenPrivilegeInfo ??=
    _getTizenInstance(privilegeInfoSymbols, Tizen60PrivilegeInfo.fromLookup)!;

Tizen60Push? _tizenPush;
Tizen60Push get tizenPush =>
    _tizenPush ??= _getTizenInstance(pushSymbols, Tizen60Push.fromLookup)!;

Tizen60RpcPort? _tizenRpcPort;
Tizen60RpcPort get tizenRpcPort => _tizenRpcPort ??=
    _getTizenInstance(rpcPortSymbols, Tizen60RpcPort.fromLookup)!;

Tizen60Shortcut? _tizenShortcut;
Tizen60Shortcut get tizenShortcut => _tizenShortcut ??=
    _getTizenInstance(shortcutSymbols, Tizen60Shortcut.fromLookup)!;

Tizen60Storage? _tizenStorage;
Tizen60Storage get tizenStorage => _tizenStorage ??=
    _getTizenInstance(storageSymbols, Tizen60Storage.fromLookup)!;

Tizen60Stt? _tizenStt;
Tizen60Stt get tizenStt =>
    _tizenStt ??= _getTizenInstance(sttSymbols, Tizen60Stt.fromLookup)!;

Tizen60SttEngine? _tizenSttEngine;
Tizen60SttEngine get tizenSttEngine => _tizenSttEngine ??=
    _getTizenInstance(stt_engineSymbols, Tizen60SttEngine.fromLookup)!;

Tizen60Tbm? _tizenTbm;
Tizen60Tbm get tizenTbm =>
    _tizenTbm ??= _getTizenInstance(tbmSymbols, Tizen60Tbm.fromLookup)!;

Tizen60Ttrace? _tizenTtrace;
Tizen60Ttrace get tizenTtrace => _tizenTtrace ??=
    _getTizenInstance(ttraceSymbols, Tizen60Ttrace.fromLookup)!;

Tizen60Tts? _tizenTts;
Tizen60Tts get tizenTts =>
    _tizenTts ??= _getTizenInstance(ttsSymbols, Tizen60Tts.fromLookup)!;

Tizen60TtsEngine? _tizenTtsEngine;
Tizen60TtsEngine get tizenTtsEngine => _tizenTtsEngine ??=
    _getTizenInstance(tts_engineSymbols, Tizen60TtsEngine.fromLookup)!;

Tizen60UpdateControl? _tizenUpdateControl;
Tizen60UpdateControl get tizenUpdateControl => _tizenUpdateControl ??=
    _getTizenInstance(updateControlSymbols, Tizen60UpdateControl.fromLookup)!;

Tizen60Vc? _tizenVc;
Tizen60Vc get tizenVc => _tizenVc ??= _getTizenInstance(vcSymbols, Tizen60Vc.fromLookup)!;

Tizen60VcEngine? _tizenVcEngine;
Tizen60VcEngine get tizenVcEngine =>
    _tizenVcEngine ??= _getTizenInstance(vc_engineSymbols, Tizen60VcEngine.fromLookup)!;

Tizen60VcManager? _tizenVcManager;
Tizen60VcManager get tizenVcManager =>
    _tizenVcManager ??= _getTizenInstance(vc_managerSymbols, Tizen60VcManager.fromLookup)!;

Tizen60WifiDirect? _tizenWifiDirect;
Tizen60WifiDirect get tizenWifiDirect => _tizenWifiDirect ??=
    _getTizenInstance(wifiDirectSymbols, Tizen60WifiDirect.fromLookup)!;

Tizen60Yaca? _tizenYaca;
Tizen60Yaca get tizenYaca =>
    _tizenYaca ??= _getTizenInstance(yacaSymbols, Tizen60Yaca.fromLookup)!;
