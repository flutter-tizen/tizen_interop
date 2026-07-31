/// Tizen Interop for Tizen 6.5.
library tizen_interop_6_5;

import 'dart:ffi';

import '../../src/bindings/6.5/generated_symbols.dart';
import '../../src/bindings/6.5/generated_bindings_accounts_svc.dart';
import '../../src/bindings/6.5/generated_bindings_appcore_agent.dart';
import '../../src/bindings/6.5/generated_bindings_asp.dart';
import '../../src/bindings/6.5/generated_bindings_badge.dart';
import '../../src/bindings/6.5/generated_bindings_bundle.dart';
import '../../src/bindings/6.5/generated_bindings_calendar_service2.dart';
import '../../src/bindings/6.5/generated_bindings_capi_appfw_alarm.dart';
import '../../src/bindings/6.5/generated_bindings_capi_appfw_app_common.dart';
import '../../src/bindings/6.5/generated_bindings_capi_appfw_app_control.dart';
import '../../src/bindings/6.5/generated_bindings_capi_appfw_app_control_uri.dart';
import '../../src/bindings/6.5/generated_bindings_capi_appfw_app_manager.dart';
import '../../src/bindings/6.5/generated_bindings_capi_appfw_application.dart';
import '../../src/bindings/6.5/generated_bindings_capi_appfw_event.dart';
import '../../src/bindings/6.5/generated_bindings_capi_appfw_job_scheduler.dart';
import '../../src/bindings/6.5/generated_bindings_capi_appfw_package_manager.dart';
import '../../src/bindings/6.5/generated_bindings_capi_appfw_preference.dart';
import '../../src/bindings/6.5/generated_bindings_capi_base_common.dart';
import '../../src/bindings/6.5/generated_bindings_capi_content_media_content.dart';
import '../../src/bindings/6.5/generated_bindings_capi_content_mime_type.dart';
import '../../src/bindings/6.5/generated_bindings_capi_context.dart';
import '../../src/bindings/6.5/generated_bindings_capi_context_motion.dart';
import '../../src/bindings/6.5/generated_bindings_capi_geofence_manager.dart';
import '../../src/bindings/6.5/generated_bindings_capi_location_manager.dart';
import '../../src/bindings/6.5/generated_bindings_capi_media_audio_io.dart';
import '../../src/bindings/6.5/generated_bindings_capi_media_camera.dart';
import '../../src/bindings/6.5/generated_bindings_capi_media_codec.dart';
import '../../src/bindings/6.5/generated_bindings_capi_media_controller.dart';
import '../../src/bindings/6.5/generated_bindings_capi_media_image_util.dart';
import '../../src/bindings/6.5/generated_bindings_capi_media_metadata_editor.dart';
import '../../src/bindings/6.5/generated_bindings_capi_media_metadata_extractor.dart';
import '../../src/bindings/6.5/generated_bindings_capi_media_player.dart';
import '../../src/bindings/6.5/generated_bindings_capi_media_radio.dart';
import '../../src/bindings/6.5/generated_bindings_capi_media_recorder.dart';
import '../../src/bindings/6.5/generated_bindings_capi_media_screen_mirroring.dart';
import '../../src/bindings/6.5/generated_bindings_capi_media_sound_manager.dart';
import '../../src/bindings/6.5/generated_bindings_capi_media_sound_pool.dart';
import '../../src/bindings/6.5/generated_bindings_capi_media_streamer.dart';
import '../../src/bindings/6.5/generated_bindings_capi_media_streamrecorder.dart';
import '../../src/bindings/6.5/generated_bindings_capi_media_thumbnail_util.dart';
import '../../src/bindings/6.5/generated_bindings_capi_media_tone_player.dart';
import '../../src/bindings/6.5/generated_bindings_capi_media_tool.dart';
import '../../src/bindings/6.5/generated_bindings_capi_media_wav_player.dart';
import '../../src/bindings/6.5/generated_bindings_capi_media_webrtc.dart';
import '../../src/bindings/6.5/generated_bindings_capi_mediademuxer.dart';
import '../../src/bindings/6.5/generated_bindings_capi_mediamuxer.dart';
import '../../src/bindings/6.5/generated_bindings_capi_messaging_email.dart';
import '../../src/bindings/6.5/generated_bindings_capi_network_bluetooth.dart';
import '../../src/bindings/6.5/generated_bindings_capi_network_connection.dart';
import '../../src/bindings/6.5/generated_bindings_capi_network_http.dart';
import '../../src/bindings/6.5/generated_bindings_capi_network_inm.dart';
import '../../src/bindings/6.5/generated_bindings_capi_network_mtp.dart';
import '../../src/bindings/6.5/generated_bindings_capi_network_softap.dart';
import '../../src/bindings/6.5/generated_bindings_capi_network_stc.dart';
import '../../src/bindings/6.5/generated_bindings_capi_network_wifi_manager.dart';
import '../../src/bindings/6.5/generated_bindings_capi_nnstreamer.dart';
import '../../src/bindings/6.5/generated_bindings_capi_nntrainer.dart';
import '../../src/bindings/6.5/generated_bindings_capi_privacy_privilege_manager.dart';
import '../../src/bindings/6.5/generated_bindings_capi_system_device.dart';
import '../../src/bindings/6.5/generated_bindings_capi_system_info.dart';
import '../../src/bindings/6.5/generated_bindings_capi_system_media_key.dart';
import '../../src/bindings/6.5/generated_bindings_capi_system_peripheral_io.dart';
import '../../src/bindings/6.5/generated_bindings_capi_system_runtime_info.dart';
import '../../src/bindings/6.5/generated_bindings_capi_system_sensor.dart';
import '../../src/bindings/6.5/generated_bindings_capi_system_system_settings.dart';
import '../../src/bindings/6.5/generated_bindings_capi_system_usbhost.dart';
import '../../src/bindings/6.5/generated_bindings_capi_ui_autofill.dart';
import '../../src/bindings/6.5/generated_bindings_capi_ui_autofill_common.dart';
import '../../src/bindings/6.5/generated_bindings_capi_ui_autofill_manager.dart';
import '../../src/bindings/6.5/generated_bindings_capi_ui_autofill_service.dart';
import '../../src/bindings/6.5/generated_bindings_capi_ui_inputmethod.dart';
import '../../src/bindings/6.5/generated_bindings_capi_ui_inputmethod_manager.dart';
import '../../src/bindings/6.5/generated_bindings_capi_vpnsvc.dart';
import '../../src/bindings/6.5/generated_bindings_capi_web_url_download.dart';
import '../../src/bindings/6.5/generated_bindings_cbhm.dart';
import '../../src/bindings/6.5/generated_bindings_cion.dart';
import '../../src/bindings/6.5/generated_bindings_contacts_service2.dart';
import '../../src/bindings/6.5/generated_bindings_core_sync_client.dart';
import '../../src/bindings/6.5/generated_bindings_csr_client.dart';
import '../../src/bindings/6.5/generated_bindings_data_control.dart';
import '../../src/bindings/6.5/generated_bindings_device_certificate_manager.dart';
import '../../src/bindings/6.5/generated_bindings_diagnostics.dart';
import '../../src/bindings/6.5/generated_bindings_dlog.dart';
import '../../src/bindings/6.5/generated_bindings_dpm.dart';
import '../../src/bindings/6.5/generated_bindings_eom.dart';
import '../../src/bindings/6.5/generated_bindings_feedback.dart';
import '../../src/bindings/6.5/generated_bindings_fido_client.dart';
import '../../src/bindings/6.5/generated_bindings_iotcon.dart';
import '../../src/bindings/6.5/generated_bindings_key_manager_client.dart';
import '../../src/bindings/6.5/generated_bindings_ma.dart';
import '../../src/bindings/6.5/generated_bindings_message_port.dart';
import '../../src/bindings/6.5/generated_bindings_mv_barcode_detector.dart';
import '../../src/bindings/6.5/generated_bindings_mv_barcode_generator.dart';
import '../../src/bindings/6.5/generated_bindings_mv_common.dart';
import '../../src/bindings/6.5/generated_bindings_mv_face.dart';
import '../../src/bindings/6.5/generated_bindings_mv_image.dart';
import '../../src/bindings/6.5/generated_bindings_mv_inference.dart';
import '../../src/bindings/6.5/generated_bindings_mv_surveillance.dart';
import '../../src/bindings/6.5/generated_bindings_notification.dart';
import '../../src/bindings/6.5/generated_bindings_notification_ex.dart';
import '../../src/bindings/6.5/generated_bindings_nsd_dns_sd.dart';
import '../../src/bindings/6.5/generated_bindings_nsd_ssdp.dart';
import '../../src/bindings/6.5/generated_bindings_oauth2.dart';
import '../../src/bindings/6.5/generated_bindings_phonenumber_utils.dart';
import '../../src/bindings/6.5/generated_bindings_privilege_info.dart';
import '../../src/bindings/6.5/generated_bindings_push.dart';
import '../../src/bindings/6.5/generated_bindings_rpc_port.dart';
import '../../src/bindings/6.5/generated_bindings_shortcut.dart';
import '../../src/bindings/6.5/generated_bindings_storage.dart';
import '../../src/bindings/6.5/generated_bindings_stt.dart';
import '../../src/bindings/6.5/generated_bindings_stt_engine.dart';
import '../../src/bindings/6.5/generated_bindings_tbm.dart';
import '../../src/bindings/6.5/generated_bindings_ttrace.dart';
import '../../src/bindings/6.5/generated_bindings_tts.dart';
import '../../src/bindings/6.5/generated_bindings_tts_engine.dart';
import '../../src/bindings/6.5/generated_bindings_update_control.dart';
import '../../src/bindings/6.5/generated_bindings_vc.dart';
import '../../src/bindings/6.5/generated_bindings_vc_engine.dart';
import '../../src/bindings/6.5/generated_bindings_vc_manager.dart';
import '../../src/bindings/6.5/generated_bindings_wifi_direct.dart';
import '../../src/bindings/6.5/generated_bindings_yaca.dart';
import '../../src/lookup_provider.dart';

export '../../src/extensions.dart';
export '../../src/bindings/6.5/generated_bindings_accounts_svc.dart';
export '../../src/bindings/6.5/generated_bindings_appcore_agent.dart';
export '../../src/bindings/6.5/generated_bindings_asp.dart';
export '../../src/bindings/6.5/generated_bindings_badge.dart';
export '../../src/bindings/6.5/generated_bindings_bundle.dart';
export '../../src/bindings/6.5/generated_bindings_calendar_service2.dart';
export '../../src/bindings/6.5/generated_bindings_capi_appfw_alarm.dart';
export '../../src/bindings/6.5/generated_bindings_capi_appfw_app_common.dart';
export '../../src/bindings/6.5/generated_bindings_capi_appfw_app_control.dart';
export '../../src/bindings/6.5/generated_bindings_capi_appfw_app_control_uri.dart';
export '../../src/bindings/6.5/generated_bindings_capi_appfw_app_manager.dart';
export '../../src/bindings/6.5/generated_bindings_capi_appfw_application.dart';
export '../../src/bindings/6.5/generated_bindings_capi_appfw_event.dart';
export '../../src/bindings/6.5/generated_bindings_capi_appfw_job_scheduler.dart';
export '../../src/bindings/6.5/generated_bindings_capi_appfw_package_manager.dart';
export '../../src/bindings/6.5/generated_bindings_capi_appfw_preference.dart';
export '../../src/bindings/6.5/generated_bindings_capi_base_common.dart';
export '../../src/bindings/6.5/generated_bindings_capi_content_media_content.dart';
export '../../src/bindings/6.5/generated_bindings_capi_content_mime_type.dart';
export '../../src/bindings/6.5/generated_bindings_capi_context.dart';
export '../../src/bindings/6.5/generated_bindings_capi_context_motion.dart';
export '../../src/bindings/6.5/generated_bindings_capi_geofence_manager.dart';
export '../../src/bindings/6.5/generated_bindings_capi_location_manager.dart';
export '../../src/bindings/6.5/generated_bindings_capi_media_audio_io.dart';
export '../../src/bindings/6.5/generated_bindings_capi_media_camera.dart'
    hide UnnamedStruct1, UnnamedUnion1;
export '../../src/bindings/6.5/generated_bindings_capi_media_codec.dart';
export '../../src/bindings/6.5/generated_bindings_capi_media_controller.dart';
export '../../src/bindings/6.5/generated_bindings_capi_media_image_util.dart';
export '../../src/bindings/6.5/generated_bindings_capi_media_metadata_editor.dart';
export '../../src/bindings/6.5/generated_bindings_capi_media_metadata_extractor.dart';
export '../../src/bindings/6.5/generated_bindings_capi_media_player.dart';
export '../../src/bindings/6.5/generated_bindings_capi_media_radio.dart';
export '../../src/bindings/6.5/generated_bindings_capi_media_recorder.dart';
export '../../src/bindings/6.5/generated_bindings_capi_media_screen_mirroring.dart';
export '../../src/bindings/6.5/generated_bindings_capi_media_sound_manager.dart';
export '../../src/bindings/6.5/generated_bindings_capi_media_sound_pool.dart';
export '../../src/bindings/6.5/generated_bindings_capi_media_streamer.dart';
export '../../src/bindings/6.5/generated_bindings_capi_media_streamrecorder.dart';
export '../../src/bindings/6.5/generated_bindings_capi_media_thumbnail_util.dart';
export '../../src/bindings/6.5/generated_bindings_capi_media_tone_player.dart';
export '../../src/bindings/6.5/generated_bindings_capi_media_tool.dart';
export '../../src/bindings/6.5/generated_bindings_capi_media_wav_player.dart';
export '../../src/bindings/6.5/generated_bindings_capi_media_webrtc.dart';
export '../../src/bindings/6.5/generated_bindings_capi_mediademuxer.dart';
export '../../src/bindings/6.5/generated_bindings_capi_mediamuxer.dart';
export '../../src/bindings/6.5/generated_bindings_capi_messaging_email.dart';
export '../../src/bindings/6.5/generated_bindings_capi_network_bluetooth.dart';
export '../../src/bindings/6.5/generated_bindings_capi_network_connection.dart';
export '../../src/bindings/6.5/generated_bindings_capi_network_http.dart';
export '../../src/bindings/6.5/generated_bindings_capi_network_inm.dart';
export '../../src/bindings/6.5/generated_bindings_capi_network_mtp.dart';
export '../../src/bindings/6.5/generated_bindings_capi_network_softap.dart';
export '../../src/bindings/6.5/generated_bindings_capi_network_stc.dart';
export '../../src/bindings/6.5/generated_bindings_capi_network_wifi_manager.dart';
export '../../src/bindings/6.5/generated_bindings_capi_nnstreamer.dart';
export '../../src/bindings/6.5/generated_bindings_capi_nntrainer.dart';
export '../../src/bindings/6.5/generated_bindings_capi_privacy_privilege_manager.dart';
export '../../src/bindings/6.5/generated_bindings_capi_system_device.dart';
export '../../src/bindings/6.5/generated_bindings_capi_system_info.dart';
export '../../src/bindings/6.5/generated_bindings_capi_system_media_key.dart';
export '../../src/bindings/6.5/generated_bindings_capi_system_peripheral_io.dart';
export '../../src/bindings/6.5/generated_bindings_capi_system_runtime_info.dart';
export '../../src/bindings/6.5/generated_bindings_capi_system_sensor.dart';
export '../../src/bindings/6.5/generated_bindings_capi_system_system_settings.dart';
export '../../src/bindings/6.5/generated_bindings_capi_system_usbhost.dart';
export '../../src/bindings/6.5/generated_bindings_capi_ui_autofill.dart';
export '../../src/bindings/6.5/generated_bindings_capi_ui_autofill_common.dart';
export '../../src/bindings/6.5/generated_bindings_capi_ui_autofill_manager.dart';
export '../../src/bindings/6.5/generated_bindings_capi_ui_autofill_service.dart';
export '../../src/bindings/6.5/generated_bindings_capi_ui_inputmethod.dart';
export '../../src/bindings/6.5/generated_bindings_capi_ui_inputmethod_manager.dart';
export '../../src/bindings/6.5/generated_bindings_capi_vpnsvc.dart';
export '../../src/bindings/6.5/generated_bindings_capi_web_url_download.dart';
export '../../src/bindings/6.5/generated_bindings_cbhm.dart';
export '../../src/bindings/6.5/generated_bindings_cion.dart';
export '../../src/bindings/6.5/generated_bindings_contacts_service2.dart';
export '../../src/bindings/6.5/generated_bindings_core_sync_client.dart';
export '../../src/bindings/6.5/generated_bindings_csr_client.dart';
export '../../src/bindings/6.5/generated_bindings_data_control.dart';
export '../../src/bindings/6.5/generated_bindings_device_certificate_manager.dart';
export '../../src/bindings/6.5/generated_bindings_diagnostics.dart';
export '../../src/bindings/6.5/generated_bindings_dlog.dart';
export '../../src/bindings/6.5/generated_bindings_dpm.dart';
export '../../src/bindings/6.5/generated_bindings_eom.dart';
export '../../src/bindings/6.5/generated_bindings_feedback.dart';
export '../../src/bindings/6.5/generated_bindings_fido_client.dart';
export '../../src/bindings/6.5/generated_bindings_iotcon.dart';
export '../../src/bindings/6.5/generated_bindings_key_manager_client.dart';
export '../../src/bindings/6.5/generated_bindings_ma.dart';
export '../../src/bindings/6.5/generated_bindings_message_port.dart';
export '../../src/bindings/6.5/generated_bindings_mv_barcode_detector.dart';
export '../../src/bindings/6.5/generated_bindings_mv_barcode_generator.dart';
export '../../src/bindings/6.5/generated_bindings_mv_common.dart';
export '../../src/bindings/6.5/generated_bindings_mv_face.dart';
export '../../src/bindings/6.5/generated_bindings_mv_image.dart';
export '../../src/bindings/6.5/generated_bindings_mv_inference.dart';
export '../../src/bindings/6.5/generated_bindings_mv_surveillance.dart';
export '../../src/bindings/6.5/generated_bindings_notification.dart';
export '../../src/bindings/6.5/generated_bindings_notification_ex.dart';
export '../../src/bindings/6.5/generated_bindings_nsd_dns_sd.dart';
export '../../src/bindings/6.5/generated_bindings_nsd_ssdp.dart';
export '../../src/bindings/6.5/generated_bindings_oauth2.dart';
export '../../src/bindings/6.5/generated_bindings_phonenumber_utils.dart';
export '../../src/bindings/6.5/generated_bindings_privilege_info.dart';
export '../../src/bindings/6.5/generated_bindings_push.dart';
export '../../src/bindings/6.5/generated_bindings_rpc_port.dart';
export '../../src/bindings/6.5/generated_bindings_shortcut.dart';
export '../../src/bindings/6.5/generated_bindings_storage.dart';
export '../../src/bindings/6.5/generated_bindings_stt.dart';
export '../../src/bindings/6.5/generated_bindings_stt_engine.dart';
export '../../src/bindings/6.5/generated_bindings_tbm.dart';
export '../../src/bindings/6.5/generated_bindings_ttrace.dart';
export '../../src/bindings/6.5/generated_bindings_tts.dart';
export '../../src/bindings/6.5/generated_bindings_tts_engine.dart';
export '../../src/bindings/6.5/generated_bindings_update_control.dart';
export '../../src/bindings/6.5/generated_bindings_vc.dart';
export '../../src/bindings/6.5/generated_bindings_vc_engine.dart';
export '../../src/bindings/6.5/generated_bindings_vc_manager.dart';
export '../../src/bindings/6.5/generated_bindings_wifi_direct.dart';
export '../../src/bindings/6.5/generated_bindings_yaca.dart';
export '../../src/bindings/6.5/generated_bindings_time.dart'
    hide UnnamedStruct1, UnnamedUnion1;

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

Tizen65AccountsSvc? _tizenAccountsSvc;
Tizen65AccountsSvc get tizenAccountsSvc => _tizenAccountsSvc ??=
    _getTizenInstance(accountsSvcSymbols, Tizen65AccountsSvc.fromLookup)!;

Tizen65AppcoreAgent? _tizenAppcoreAgent;
Tizen65AppcoreAgent get tizenAppcoreAgent => _tizenAppcoreAgent ??=
    _getTizenInstance(appcoreAgentSymbols, Tizen65AppcoreAgent.fromLookup)!;

Tizen65Asp? _tizenAsp;
Tizen65Asp get tizenAsp =>
    _tizenAsp ??= _getTizenInstance(aspSymbols, Tizen65Asp.fromLookup)!;

Tizen65Badge? _tizenBadge;
Tizen65Badge get tizenBadge =>
    _tizenBadge ??= _getTizenInstance(badgeSymbols, Tizen65Badge.fromLookup)!;

Tizen65Bundle? _tizenBundle;
Tizen65Bundle get tizenBundle => _tizenBundle ??=
    _getTizenInstance(bundleSymbols, Tizen65Bundle.fromLookup)!;

Tizen65CalendarService2? _tizenCalendarService2;
Tizen65CalendarService2 get tizenCalendarService2 =>
    _tizenCalendarService2 ??= _getTizenInstance(
        calendarService2Symbols, Tizen65CalendarService2.fromLookup)!;

Tizen65CapiAppfwAlarm? _tizenCapiAppfwAlarm;
Tizen65CapiAppfwAlarm get tizenCapiAppfwAlarm => _tizenCapiAppfwAlarm ??=
    _getTizenInstance(capiAppfwAlarmSymbols, Tizen65CapiAppfwAlarm.fromLookup)!;

Tizen65CapiAppfwAppCommon? _tizenCapiAppfwAppCommon;
Tizen65CapiAppfwAppCommon get tizenCapiAppfwAppCommon =>
    _tizenCapiAppfwAppCommon ??= _getTizenInstance(
        capiAppfwAppCommonSymbols, Tizen65CapiAppfwAppCommon.fromLookup)!;

Tizen65CapiAppfwAppControl? _tizenCapiAppfwAppControl;
Tizen65CapiAppfwAppControl get tizenCapiAppfwAppControl =>
    _tizenCapiAppfwAppControl ??= _getTizenInstance(
        capiAppfwAppControlSymbols, Tizen65CapiAppfwAppControl.fromLookup)!;

Tizen65CapiAppfwAppControlUri? _tizenCapiAppfwAppControlUri;
Tizen65CapiAppfwAppControlUri get tizenCapiAppfwAppControlUri =>
    _tizenCapiAppfwAppControlUri ??= _getTizenInstance(
        capiAppfwAppControlUriSymbols,
        Tizen65CapiAppfwAppControlUri.fromLookup)!;

Tizen65CapiAppfwAppManager? _tizenCapiAppfwAppManager;
Tizen65CapiAppfwAppManager get tizenCapiAppfwAppManager =>
    _tizenCapiAppfwAppManager ??= _getTizenInstance(
        capiAppfwAppManagerSymbols, Tizen65CapiAppfwAppManager.fromLookup)!;

Tizen65CapiAppfwApplication? _tizenCapiAppfwApplication;
Tizen65CapiAppfwApplication get tizenCapiAppfwApplication =>
    _tizenCapiAppfwApplication ??= _getTizenInstance(
        capiAppfwApplicationSymbols, Tizen65CapiAppfwApplication.fromLookup)!;

Tizen65CapiAppfwEvent? _tizenCapiAppfwEvent;
Tizen65CapiAppfwEvent get tizenCapiAppfwEvent => _tizenCapiAppfwEvent ??=
    _getTizenInstance(capiAppfwEventSymbols, Tizen65CapiAppfwEvent.fromLookup)!;

Tizen65CapiAppfwJobScheduler? _tizenCapiAppfwJobScheduler;
Tizen65CapiAppfwJobScheduler get tizenCapiAppfwJobScheduler =>
    _tizenCapiAppfwJobScheduler ??= _getTizenInstance(
        capiAppfwJobSchedulerSymbols, Tizen65CapiAppfwJobScheduler.fromLookup)!;

Tizen65CapiAppfwPackageManager? _tizenCapiAppfwPackageManager;
Tizen65CapiAppfwPackageManager get tizenCapiAppfwPackageManager =>
    _tizenCapiAppfwPackageManager ??= _getTizenInstance(
        capiAppfwPackageManagerSymbols,
        Tizen65CapiAppfwPackageManager.fromLookup)!;

Tizen65CapiAppfwPreference? _tizenCapiAppfwPreference;
Tizen65CapiAppfwPreference get tizenCapiAppfwPreference =>
    _tizenCapiAppfwPreference ??= _getTizenInstance(
        capiAppfwPreferenceSymbols, Tizen65CapiAppfwPreference.fromLookup)!;

Tizen65CapiBaseCommon? _tizenCapiBaseCommon;
Tizen65CapiBaseCommon get tizenCapiBaseCommon => _tizenCapiBaseCommon ??=
    _getTizenInstance(capiBaseCommonSymbols, Tizen65CapiBaseCommon.fromLookup)!;

Tizen65CapiContentMediaContent? _tizenCapiContentMediaContent;
Tizen65CapiContentMediaContent get tizenCapiContentMediaContent =>
    _tizenCapiContentMediaContent ??= _getTizenInstance(
        capiContentMediaContentSymbols,
        Tizen65CapiContentMediaContent.fromLookup)!;

Tizen65CapiContentMimeType? _tizenCapiContentMimeType;
Tizen65CapiContentMimeType get tizenCapiContentMimeType =>
    _tizenCapiContentMimeType ??= _getTizenInstance(
        capiContentMimeTypeSymbols, Tizen65CapiContentMimeType.fromLookup)!;

Tizen65CapiContext? _tizenCapiContext;
Tizen65CapiContext get tizenCapiContext => _tizenCapiContext ??=
    _getTizenInstance(capiContextSymbols, Tizen65CapiContext.fromLookup)!;

Tizen65CapiContextMotion? _tizenCapiContextMotion;
Tizen65CapiContextMotion get tizenCapiContextMotion =>
    _tizenCapiContextMotion ??= _getTizenInstance(
        capiContextMotionSymbols, Tizen65CapiContextMotion.fromLookup)!;

Tizen65CapiGeofenceManager? _tizenCapiGeofenceManager;
Tizen65CapiGeofenceManager get tizenCapiGeofenceManager =>
    _tizenCapiGeofenceManager ??= _getTizenInstance(
        capiGeofenceManagerSymbols, Tizen65CapiGeofenceManager.fromLookup)!;

Tizen65CapiLocationManager? _tizenCapiLocationManager;
Tizen65CapiLocationManager get tizenCapiLocationManager =>
    _tizenCapiLocationManager ??= _getTizenInstance(
        capiLocationManagerSymbols, Tizen65CapiLocationManager.fromLookup)!;

Tizen65CapiMediaAudioIo? _tizenCapiMediaAudioIo;
Tizen65CapiMediaAudioIo get tizenCapiMediaAudioIo =>
    _tizenCapiMediaAudioIo ??= _getTizenInstance(
        capiMediaAudioIoSymbols, Tizen65CapiMediaAudioIo.fromLookup)!;

Tizen65CapiMediaCamera? _tizenCapiMediaCamera;
Tizen65CapiMediaCamera get tizenCapiMediaCamera =>
    _tizenCapiMediaCamera ??= _getTizenInstance(
        capiMediaCameraSymbols, Tizen65CapiMediaCamera.fromLookup)!;

Tizen65CapiMediaCodec? _tizenCapiMediaCodec;
Tizen65CapiMediaCodec get tizenCapiMediaCodec => _tizenCapiMediaCodec ??=
    _getTizenInstance(capiMediaCodecSymbols, Tizen65CapiMediaCodec.fromLookup)!;

Tizen65CapiMediaController? _tizenCapiMediaController;
Tizen65CapiMediaController get tizenCapiMediaController =>
    _tizenCapiMediaController ??= _getTizenInstance(
        capiMediaControllerSymbols, Tizen65CapiMediaController.fromLookup)!;

Tizen65CapiMediaImageUtil? _tizenCapiMediaImageUtil;
Tizen65CapiMediaImageUtil get tizenCapiMediaImageUtil =>
    _tizenCapiMediaImageUtil ??= _getTizenInstance(
        capiMediaImageUtilSymbols, Tizen65CapiMediaImageUtil.fromLookup)!;

Tizen65CapiMediaMetadataEditor? _tizenCapiMediaMetadataEditor;
Tizen65CapiMediaMetadataEditor get tizenCapiMediaMetadataEditor =>
    _tizenCapiMediaMetadataEditor ??= _getTizenInstance(
        capiMediaMetadataEditorSymbols,
        Tizen65CapiMediaMetadataEditor.fromLookup)!;

Tizen65CapiMediaMetadataExtractor? _tizenCapiMediaMetadataExtractor;
Tizen65CapiMediaMetadataExtractor get tizenCapiMediaMetadataExtractor =>
    _tizenCapiMediaMetadataExtractor ??= _getTizenInstance(
        capiMediaMetadataExtractorSymbols,
        Tizen65CapiMediaMetadataExtractor.fromLookup)!;

Tizen65CapiMediaPlayer? _tizenCapiMediaPlayer;
Tizen65CapiMediaPlayer get tizenCapiMediaPlayer =>
    _tizenCapiMediaPlayer ??= _getTizenInstance(
        capiMediaPlayerSymbols, Tizen65CapiMediaPlayer.fromLookup)!;

Tizen65CapiMediaRadio? _tizenCapiMediaRadio;
Tizen65CapiMediaRadio get tizenCapiMediaRadio => _tizenCapiMediaRadio ??=
    _getTizenInstance(capiMediaRadioSymbols, Tizen65CapiMediaRadio.fromLookup)!;

Tizen65CapiMediaRecorder? _tizenCapiMediaRecorder;
Tizen65CapiMediaRecorder get tizenCapiMediaRecorder =>
    _tizenCapiMediaRecorder ??= _getTizenInstance(
        capiMediaRecorderSymbols, Tizen65CapiMediaRecorder.fromLookup)!;

Tizen65CapiMediaScreenMirroring? _tizenCapiMediaScreenMirroring;
Tizen65CapiMediaScreenMirroring get tizenCapiMediaScreenMirroring =>
    _tizenCapiMediaScreenMirroring ??= _getTizenInstance(
        capiMediaScreenMirroringSymbols,
        Tizen65CapiMediaScreenMirroring.fromLookup)!;

Tizen65CapiMediaSoundManager? _tizenCapiMediaSoundManager;
Tizen65CapiMediaSoundManager get tizenCapiMediaSoundManager =>
    _tizenCapiMediaSoundManager ??= _getTizenInstance(
        capiMediaSoundManagerSymbols, Tizen65CapiMediaSoundManager.fromLookup)!;

Tizen65CapiMediaSoundPool? _tizenCapiMediaSoundPool;
Tizen65CapiMediaSoundPool get tizenCapiMediaSoundPool =>
    _tizenCapiMediaSoundPool ??= _getTizenInstance(
        capiMediaSoundPoolSymbols, Tizen65CapiMediaSoundPool.fromLookup)!;

Tizen65CapiMediaStreamer? _tizenCapiMediaStreamer;
Tizen65CapiMediaStreamer get tizenCapiMediaStreamer =>
    _tizenCapiMediaStreamer ??= _getTizenInstance(
        capiMediaStreamerSymbols, Tizen65CapiMediaStreamer.fromLookup)!;

Tizen65CapiMediaStreamrecorder? _tizenCapiMediaStreamrecorder;
Tizen65CapiMediaStreamrecorder get tizenCapiMediaStreamrecorder =>
    _tizenCapiMediaStreamrecorder ??= _getTizenInstance(
        capiMediaStreamrecorderSymbols,
        Tizen65CapiMediaStreamrecorder.fromLookup)!;

Tizen65CapiMediaThumbnailUtil? _tizenCapiMediaThumbnailUtil;
Tizen65CapiMediaThumbnailUtil get tizenCapiMediaThumbnailUtil =>
    _tizenCapiMediaThumbnailUtil ??= _getTizenInstance(
        capiMediaThumbnailUtilSymbols,
        Tizen65CapiMediaThumbnailUtil.fromLookup)!;

Tizen65CapiMediaTonePlayer? _tizenCapiMediaTonePlayer;
Tizen65CapiMediaTonePlayer get tizenCapiMediaTonePlayer =>
    _tizenCapiMediaTonePlayer ??= _getTizenInstance(
        capiMediaTonePlayerSymbols, Tizen65CapiMediaTonePlayer.fromLookup)!;

Tizen65CapiMediaTool? _tizenCapiMediaTool;
Tizen65CapiMediaTool get tizenCapiMediaTool => _tizenCapiMediaTool ??=
    _getTizenInstance(capiMediaToolSymbols, Tizen65CapiMediaTool.fromLookup)!;

Tizen65CapiMediaWavPlayer? _tizenCapiMediaWavPlayer;
Tizen65CapiMediaWavPlayer get tizenCapiMediaWavPlayer =>
    _tizenCapiMediaWavPlayer ??= _getTizenInstance(
        capiMediaWavPlayerSymbols, Tizen65CapiMediaWavPlayer.fromLookup)!;

Tizen65CapiMediaWebrtc? _tizenCapiMediaWebrtc;
Tizen65CapiMediaWebrtc get tizenCapiMediaWebrtc =>
    _tizenCapiMediaWebrtc ??= _getTizenInstance(
        capiMediaWebrtcSymbols, Tizen65CapiMediaWebrtc.fromLookup)!;

Tizen65CapiMediademuxer? _tizenCapiMediademuxer;
Tizen65CapiMediademuxer get tizenCapiMediademuxer =>
    _tizenCapiMediademuxer ??= _getTizenInstance(
        capiMediademuxerSymbols, Tizen65CapiMediademuxer.fromLookup)!;

Tizen65CapiMediamuxer? _tizenCapiMediamuxer;
Tizen65CapiMediamuxer get tizenCapiMediamuxer => _tizenCapiMediamuxer ??=
    _getTizenInstance(capiMediamuxerSymbols, Tizen65CapiMediamuxer.fromLookup)!;

Tizen65CapiMessagingEmail? _tizenCapiMessagingEmail;
Tizen65CapiMessagingEmail get tizenCapiMessagingEmail =>
    _tizenCapiMessagingEmail ??= _getTizenInstance(
        capiMessagingEmailSymbols, Tizen65CapiMessagingEmail.fromLookup)!;

Tizen65CapiNetworkBluetooth? _tizenCapiNetworkBluetooth;
Tizen65CapiNetworkBluetooth get tizenCapiNetworkBluetooth =>
    _tizenCapiNetworkBluetooth ??= _getTizenInstance(
        capiNetworkBluetoothSymbols, Tizen65CapiNetworkBluetooth.fromLookup)!;

Tizen65CapiNetworkConnection? _tizenCapiNetworkConnection;
Tizen65CapiNetworkConnection get tizenCapiNetworkConnection =>
    _tizenCapiNetworkConnection ??= _getTizenInstance(
        capiNetworkConnectionSymbols, Tizen65CapiNetworkConnection.fromLookup)!;

Tizen65CapiNetworkHttp? _tizenCapiNetworkHttp;
Tizen65CapiNetworkHttp get tizenCapiNetworkHttp =>
    _tizenCapiNetworkHttp ??= _getTizenInstance(
        capiNetworkHttpSymbols, Tizen65CapiNetworkHttp.fromLookup)!;

Tizen65CapiNetworkInm? _tizenCapiNetworkInm;
Tizen65CapiNetworkInm get tizenCapiNetworkInm => _tizenCapiNetworkInm ??=
    _getTizenInstance(capiNetworkInmSymbols, Tizen65CapiNetworkInm.fromLookup)!;

Tizen65CapiNetworkMtp? _tizenCapiNetworkMtp;
Tizen65CapiNetworkMtp get tizenCapiNetworkMtp => _tizenCapiNetworkMtp ??=
    _getTizenInstance(capiNetworkMtpSymbols, Tizen65CapiNetworkMtp.fromLookup)!;

Tizen65CapiNetworkSoftap? _tizenCapiNetworkSoftap;
Tizen65CapiNetworkSoftap get tizenCapiNetworkSoftap =>
    _tizenCapiNetworkSoftap ??= _getTizenInstance(
        capiNetworkSoftapSymbols, Tizen65CapiNetworkSoftap.fromLookup)!;

Tizen65CapiNetworkStc? _tizenCapiNetworkStc;
Tizen65CapiNetworkStc get tizenCapiNetworkStc => _tizenCapiNetworkStc ??=
    _getTizenInstance(capiNetworkStcSymbols, Tizen65CapiNetworkStc.fromLookup)!;

Tizen65CapiNetworkWifiManager? _tizenCapiNetworkWifiManager;
Tizen65CapiNetworkWifiManager get tizenCapiNetworkWifiManager =>
    _tizenCapiNetworkWifiManager ??= _getTizenInstance(
        capiNetworkWifiManagerSymbols,
        Tizen65CapiNetworkWifiManager.fromLookup)!;

Tizen65CapiNnstreamer? _tizenCapiNnstreamer;
Tizen65CapiNnstreamer get tizenCapiNnstreamer => _tizenCapiNnstreamer ??=
    _getTizenInstance(capiNnstreamerSymbols, Tizen65CapiNnstreamer.fromLookup)!;

Tizen65CapiNntrainer? _tizenCapiNntrainer;
Tizen65CapiNntrainer get tizenCapiNntrainer => _tizenCapiNntrainer ??=
    _getTizenInstance(capiNntrainerSymbols, Tizen65CapiNntrainer.fromLookup)!;

Tizen65CapiPrivacyPrivilegeManager? _tizenCapiPrivacyPrivilegeManager;
Tizen65CapiPrivacyPrivilegeManager get tizenCapiPrivacyPrivilegeManager =>
    _tizenCapiPrivacyPrivilegeManager ??= _getTizenInstance(
        capiPrivacyPrivilegeManagerSymbols,
        Tizen65CapiPrivacyPrivilegeManager.fromLookup)!;

Tizen65CapiSystemDevice? _tizenCapiSystemDevice;
Tizen65CapiSystemDevice get tizenCapiSystemDevice =>
    _tizenCapiSystemDevice ??= _getTizenInstance(
        capiSystemDeviceSymbols, Tizen65CapiSystemDevice.fromLookup)!;

Tizen65CapiSystemInfo? _tizenCapiSystemInfo;
Tizen65CapiSystemInfo get tizenCapiSystemInfo => _tizenCapiSystemInfo ??=
    _getTizenInstance(capiSystemInfoSymbols, Tizen65CapiSystemInfo.fromLookup)!;

Tizen65CapiSystemMediaKey? _tizenCapiSystemMediaKey;
Tizen65CapiSystemMediaKey get tizenCapiSystemMediaKey =>
    _tizenCapiSystemMediaKey ??= _getTizenInstance(
        capiSystemMediaKeySymbols, Tizen65CapiSystemMediaKey.fromLookup)!;

Tizen65CapiSystemPeripheralIo? _tizenCapiSystemPeripheralIo;
Tizen65CapiSystemPeripheralIo get tizenCapiSystemPeripheralIo =>
    _tizenCapiSystemPeripheralIo ??= _getTizenInstance(
        capiSystemPeripheralIoSymbols,
        Tizen65CapiSystemPeripheralIo.fromLookup)!;

Tizen65CapiSystemRuntimeInfo? _tizenCapiSystemRuntimeInfo;
Tizen65CapiSystemRuntimeInfo get tizenCapiSystemRuntimeInfo =>
    _tizenCapiSystemRuntimeInfo ??= _getTizenInstance(
        capiSystemRuntimeInfoSymbols, Tizen65CapiSystemRuntimeInfo.fromLookup)!;

Tizen65CapiSystemSensor? _tizenCapiSystemSensor;
Tizen65CapiSystemSensor get tizenCapiSystemSensor =>
    _tizenCapiSystemSensor ??= _getTizenInstance(
        capiSystemSensorSymbols, Tizen65CapiSystemSensor.fromLookup)!;

Tizen65CapiSystemSystemSettings? _tizenCapiSystemSystemSettings;
Tizen65CapiSystemSystemSettings get tizenCapiSystemSystemSettings =>
    _tizenCapiSystemSystemSettings ??= _getTizenInstance(
        capiSystemSystemSettingsSymbols,
        Tizen65CapiSystemSystemSettings.fromLookup)!;

Tizen65CapiSystemUsbhost? _tizenCapiSystemUsbhost;
Tizen65CapiSystemUsbhost get tizenCapiSystemUsbhost =>
    _tizenCapiSystemUsbhost ??= _getTizenInstance(
        capiSystemUsbhostSymbols, Tizen65CapiSystemUsbhost.fromLookup)!;

Tizen65CapiUiAutofill? _tizenCapiUiAutofill;
Tizen65CapiUiAutofill get tizenCapiUiAutofill => _tizenCapiUiAutofill ??=
    _getTizenInstance(capiUiAutofillSymbols, Tizen65CapiUiAutofill.fromLookup)!;

Tizen65CapiUiAutofillCommon? _tizenCapiUiAutofillCommon;
Tizen65CapiUiAutofillCommon get tizenCapiUiAutofillCommon =>
    _tizenCapiUiAutofillCommon ??= _getTizenInstance(
        capiUiAutofillCommonSymbols, Tizen65CapiUiAutofillCommon.fromLookup)!;

Tizen65CapiUiAutofillManager? _tizenCapiUiAutofillManager;
Tizen65CapiUiAutofillManager get tizenCapiUiAutofillManager =>
    _tizenCapiUiAutofillManager ??= _getTizenInstance(
        capiUiAutofillManagerSymbols, Tizen65CapiUiAutofillManager.fromLookup)!;

Tizen65CapiUiAutofillService? _tizenCapiUiAutofillService;
Tizen65CapiUiAutofillService get tizenCapiUiAutofillService =>
    _tizenCapiUiAutofillService ??= _getTizenInstance(
        capiUiAutofillServiceSymbols, Tizen65CapiUiAutofillService.fromLookup)!;

Tizen65CapiUiInputmethod? _tizenCapiUiInputmethod;
Tizen65CapiUiInputmethod get tizenCapiUiInputmethod =>
    _tizenCapiUiInputmethod ??= _getTizenInstance(
        capiUiInputmethodSymbols, Tizen65CapiUiInputmethod.fromLookup)!;

Tizen65CapiUiInputmethodManager? _tizenCapiUiInputmethodManager;
Tizen65CapiUiInputmethodManager get tizenCapiUiInputmethodManager =>
    _tizenCapiUiInputmethodManager ??= _getTizenInstance(
        capiUiInputmethodManagerSymbols,
        Tizen65CapiUiInputmethodManager.fromLookup)!;

Tizen65CapiVpnsvc? _tizenCapiVpnsvc;
Tizen65CapiVpnsvc get tizenCapiVpnsvc => _tizenCapiVpnsvc ??=
    _getTizenInstance(capiVpnsvcSymbols, Tizen65CapiVpnsvc.fromLookup)!;

Tizen65CapiWebUrlDownload? _tizenCapiWebUrlDownload;
Tizen65CapiWebUrlDownload get tizenCapiWebUrlDownload =>
    _tizenCapiWebUrlDownload ??= _getTizenInstance(
        capiWebUrlDownloadSymbols, Tizen65CapiWebUrlDownload.fromLookup)!;

Tizen65Cbhm? _tizenCbhm;
Tizen65Cbhm get tizenCbhm =>
    _tizenCbhm ??= _getTizenInstance(cbhmSymbols, Tizen65Cbhm.fromLookup)!;

Tizen65Cion? _tizenCion;
Tizen65Cion get tizenCion =>
    _tizenCion ??= _getTizenInstance(cionSymbols, Tizen65Cion.fromLookup)!;

Tizen65ContactsService2? _tizenContactsService2;
Tizen65ContactsService2 get tizenContactsService2 =>
    _tizenContactsService2 ??= _getTizenInstance(
        contactsService2Symbols, Tizen65ContactsService2.fromLookup)!;

Tizen65CoreSyncClient? _tizenCoreSyncClient;
Tizen65CoreSyncClient get tizenCoreSyncClient => _tizenCoreSyncClient ??=
    _getTizenInstance(coreSyncClientSymbols, Tizen65CoreSyncClient.fromLookup)!;

Tizen65CsrClient? _tizenCsrClient;
Tizen65CsrClient get tizenCsrClient => _tizenCsrClient ??=
    _getTizenInstance(csrClientSymbols, Tizen65CsrClient.fromLookup)!;

Tizen65DataControl? _tizenDataControl;
Tizen65DataControl get tizenDataControl => _tizenDataControl ??=
    _getTizenInstance(dataControlSymbols, Tizen65DataControl.fromLookup)!;

Tizen65DeviceCertificateManager? _tizenDeviceCertificateManager;
Tizen65DeviceCertificateManager get tizenDeviceCertificateManager =>
    _tizenDeviceCertificateManager ??= _getTizenInstance(
        deviceCertificateManagerSymbols,
        Tizen65DeviceCertificateManager.fromLookup)!;

Tizen65Diagnostics? _tizenDiagnostics;
Tizen65Diagnostics get tizenDiagnostics => _tizenDiagnostics ??=
    _getTizenInstance(diagnosticsSymbols, Tizen65Diagnostics.fromLookup)!;

Tizen65Dlog? _tizenDlog;
Tizen65Dlog get tizenDlog =>
    _tizenDlog ??= _getTizenInstance(dlogSymbols, Tizen65Dlog.fromLookup)!;

Tizen65Dpm? _tizenDpm;
Tizen65Dpm get tizenDpm =>
    _tizenDpm ??= _getTizenInstance(dpmSymbols, Tizen65Dpm.fromLookup)!;

Tizen65Eom? _tizenEom;
Tizen65Eom get tizenEom =>
    _tizenEom ??= _getTizenInstance(eomSymbols, Tizen65Eom.fromLookup)!;

Tizen65Feedback? _tizenFeedback;
Tizen65Feedback get tizenFeedback => _tizenFeedback ??=
    _getTizenInstance(feedbackSymbols, Tizen65Feedback.fromLookup)!;

Tizen65FidoClient? _tizenFidoClient;
Tizen65FidoClient get tizenFidoClient => _tizenFidoClient ??=
    _getTizenInstance(fidoClientSymbols, Tizen65FidoClient.fromLookup)!;

Tizen65Iotcon? _tizenIotcon;
Tizen65Iotcon get tizenIotcon => _tizenIotcon ??=
    _getTizenInstance(iotconSymbols, Tizen65Iotcon.fromLookup)!;

Tizen65KeyManagerClient? _tizenKeyManagerClient;
Tizen65KeyManagerClient get tizenKeyManagerClient =>
    _tizenKeyManagerClient ??= _getTizenInstance(
        keyManagerClientSymbols, Tizen65KeyManagerClient.fromLookup)!;

Tizen65Ma? _tizenMa;
Tizen65Ma get tizenMa =>
    _tizenMa ??= _getTizenInstance(maSymbols, Tizen65Ma.fromLookup)!;

Tizen65MessagePort? _tizenMessagePort;
Tizen65MessagePort get tizenMessagePort => _tizenMessagePort ??=
    _getTizenInstance(messagePortSymbols, Tizen65MessagePort.fromLookup)!;

Tizen65MvBarcodeDetector? _tizenMvBarcodeDetector;
Tizen65MvBarcodeDetector get tizenMvBarcodeDetector =>
    _tizenMvBarcodeDetector ??= _getTizenInstance(
        mvBarcodeDetectorSymbols, Tizen65MvBarcodeDetector.fromLookup)!;

Tizen65MvBarcodeGenerator? _tizenMvBarcodeGenerator;
Tizen65MvBarcodeGenerator get tizenMvBarcodeGenerator =>
    _tizenMvBarcodeGenerator ??= _getTizenInstance(
        mvBarcodeGeneratorSymbols, Tizen65MvBarcodeGenerator.fromLookup)!;

Tizen65MvCommon? _tizenMvCommon;
Tizen65MvCommon get tizenMvCommon => _tizenMvCommon ??=
    _getTizenInstance(mvCommonSymbols, Tizen65MvCommon.fromLookup)!;

Tizen65MvFace? _tizenMvFace;
Tizen65MvFace get tizenMvFace => _tizenMvFace ??=
    _getTizenInstance(mvFaceSymbols, Tizen65MvFace.fromLookup)!;

Tizen65MvImage? _tizenMvImage;
Tizen65MvImage get tizenMvImage => _tizenMvImage ??=
    _getTizenInstance(mvImageSymbols, Tizen65MvImage.fromLookup)!;

Tizen65MvInference? _tizenMvInference;
Tizen65MvInference get tizenMvInference => _tizenMvInference ??=
    _getTizenInstance(mvInferenceSymbols, Tizen65MvInference.fromLookup)!;

Tizen65MvSurveillance? _tizenMvSurveillance;
Tizen65MvSurveillance get tizenMvSurveillance => _tizenMvSurveillance ??=
    _getTizenInstance(mvSurveillanceSymbols, Tizen65MvSurveillance.fromLookup)!;

Tizen65Notification? _tizenNotification;
Tizen65Notification get tizenNotification => _tizenNotification ??=
    _getTizenInstance(notificationSymbols, Tizen65Notification.fromLookup)!;

Tizen65NotificationEx? _tizenNotificationEx;
Tizen65NotificationEx get tizenNotificationEx => _tizenNotificationEx ??=
    _getTizenInstance(notificationExSymbols, Tizen65NotificationEx.fromLookup)!;

Tizen65NsdDnsSd? _tizenNsdDnsSd;
Tizen65NsdDnsSd get tizenNsdDnsSd => _tizenNsdDnsSd ??=
    _getTizenInstance(nsdDnsSdSymbols, Tizen65NsdDnsSd.fromLookup)!;

Tizen65NsdSsdp? _tizenNsdSsdp;
Tizen65NsdSsdp get tizenNsdSsdp => _tizenNsdSsdp ??=
    _getTizenInstance(nsdSsdpSymbols, Tizen65NsdSsdp.fromLookup)!;

Tizen65Oauth2? _tizenOauth2;
Tizen65Oauth2 get tizenOauth2 => _tizenOauth2 ??=
    _getTizenInstance(oauth2Symbols, Tizen65Oauth2.fromLookup)!;

Tizen65PhonenumberUtils? _tizenPhonenumberUtils;
Tizen65PhonenumberUtils get tizenPhonenumberUtils =>
    _tizenPhonenumberUtils ??= _getTizenInstance(
        phonenumberUtilsSymbols, Tizen65PhonenumberUtils.fromLookup)!;

Tizen65PrivilegeInfo? _tizenPrivilegeInfo;
Tizen65PrivilegeInfo get tizenPrivilegeInfo => _tizenPrivilegeInfo ??=
    _getTizenInstance(privilegeInfoSymbols, Tizen65PrivilegeInfo.fromLookup)!;

Tizen65Push? _tizenPush;
Tizen65Push get tizenPush =>
    _tizenPush ??= _getTizenInstance(pushSymbols, Tizen65Push.fromLookup)!;

Tizen65RpcPort? _tizenRpcPort;
Tizen65RpcPort get tizenRpcPort => _tizenRpcPort ??=
    _getTizenInstance(rpcPortSymbols, Tizen65RpcPort.fromLookup)!;

Tizen65Shortcut? _tizenShortcut;
Tizen65Shortcut get tizenShortcut => _tizenShortcut ??=
    _getTizenInstance(shortcutSymbols, Tizen65Shortcut.fromLookup)!;

Tizen65Storage? _tizenStorage;
Tizen65Storage get tizenStorage => _tizenStorage ??=
    _getTizenInstance(storageSymbols, Tizen65Storage.fromLookup)!;

Tizen65Stt? _tizenStt;
Tizen65Stt get tizenStt =>
    _tizenStt ??= _getTizenInstance(sttSymbols, Tizen65Stt.fromLookup)!;

Tizen65SttEngine? _tizenSttEngine;
Tizen65SttEngine get tizenSttEngine => _tizenSttEngine ??=
    _getTizenInstance(sttEngineSymbols, Tizen65SttEngine.fromLookup)!;

Tizen65Tbm? _tizenTbm;
Tizen65Tbm get tizenTbm =>
    _tizenTbm ??= _getTizenInstance(tbmSymbols, Tizen65Tbm.fromLookup)!;

Tizen65Ttrace? _tizenTtrace;
Tizen65Ttrace get tizenTtrace => _tizenTtrace ??=
    _getTizenInstance(ttraceSymbols, Tizen65Ttrace.fromLookup)!;

Tizen65Tts? _tizenTts;
Tizen65Tts get tizenTts =>
    _tizenTts ??= _getTizenInstance(ttsSymbols, Tizen65Tts.fromLookup)!;

Tizen65TtsEngine? _tizenTtsEngine;
Tizen65TtsEngine get tizenTtsEngine => _tizenTtsEngine ??=
    _getTizenInstance(ttsEngineSymbols, Tizen65TtsEngine.fromLookup)!;

Tizen65UpdateControl? _tizenUpdateControl;
Tizen65UpdateControl get tizenUpdateControl => _tizenUpdateControl ??=
    _getTizenInstance(updateControlSymbols, Tizen65UpdateControl.fromLookup)!;

Tizen65Vc? _tizenVc;
Tizen65Vc get tizenVc =>
    _tizenVc ??= _getTizenInstance(vcSymbols, Tizen65Vc.fromLookup)!;

Tizen65VcEngine? _tizenVcEngine;
Tizen65VcEngine get tizenVcEngine => _tizenVcEngine ??=
    _getTizenInstance(vcEngineSymbols, Tizen65VcEngine.fromLookup)!;

Tizen65VcManager? _tizenVcManager;
Tizen65VcManager get tizenVcManager => _tizenVcManager ??=
    _getTizenInstance(vcManagerSymbols, Tizen65VcManager.fromLookup)!;

Tizen65WifiDirect? _tizenWifiDirect;
Tizen65WifiDirect get tizenWifiDirect => _tizenWifiDirect ??=
    _getTizenInstance(wifiDirectSymbols, Tizen65WifiDirect.fromLookup)!;

Tizen65Yaca? _tizenYaca;
Tizen65Yaca get tizenYaca =>
    _tizenYaca ??= _getTizenInstance(yacaSymbols, Tizen65Yaca.fromLookup)!;
