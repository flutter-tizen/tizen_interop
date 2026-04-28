/// Tizen Interop for Tizen 10.0.
library tizen_interop_10_0;

import 'dart:ffi';

import '../../src/bindings/10.0/generated_symbols.dart';
import '../../src/bindings/10.0/generated_bindings_accounts_svc.dart';
import '../../src/bindings/10.0/generated_bindings_appcore_agent.dart';
import '../../src/bindings/10.0/generated_bindings_asp.dart';
import '../../src/bindings/10.0/generated_bindings_badge.dart';
import '../../src/bindings/10.0/generated_bindings_bundle.dart';
import '../../src/bindings/10.0/generated_bindings_calendar_service2.dart';
import '../../src/bindings/10.0/generated_bindings_capi_appfw_alarm.dart';
import '../../src/bindings/10.0/generated_bindings_capi_appfw_app_common.dart';
import '../../src/bindings/10.0/generated_bindings_capi_appfw_app_control.dart';
import '../../src/bindings/10.0/generated_bindings_capi_appfw_app_control_uri.dart';
import '../../src/bindings/10.0/generated_bindings_capi_appfw_app_manager.dart';
import '../../src/bindings/10.0/generated_bindings_capi_appfw_application.dart';
import '../../src/bindings/10.0/generated_bindings_capi_appfw_event.dart';
import '../../src/bindings/10.0/generated_bindings_capi_appfw_job_scheduler.dart';
import '../../src/bindings/10.0/generated_bindings_capi_appfw_package_manager.dart';
import '../../src/bindings/10.0/generated_bindings_capi_appfw_preference.dart';
import '../../src/bindings/10.0/generated_bindings_capi_base_common.dart';
import '../../src/bindings/10.0/generated_bindings_capi_content_media_content.dart';
import '../../src/bindings/10.0/generated_bindings_capi_content_mime_type.dart';
import '../../src/bindings/10.0/generated_bindings_capi_context.dart';
import '../../src/bindings/10.0/generated_bindings_capi_location_manager.dart';
import '../../src/bindings/10.0/generated_bindings_capi_media_audio_io.dart';
import '../../src/bindings/10.0/generated_bindings_capi_media_camera.dart';
import '../../src/bindings/10.0/generated_bindings_capi_media_codec.dart';
import '../../src/bindings/10.0/generated_bindings_capi_media_controller.dart';
import '../../src/bindings/10.0/generated_bindings_capi_media_editor.dart';
import '../../src/bindings/10.0/generated_bindings_capi_media_image_util.dart';
import '../../src/bindings/10.0/generated_bindings_capi_media_metadata_editor.dart';
import '../../src/bindings/10.0/generated_bindings_capi_media_metadata_extractor.dart';
import '../../src/bindings/10.0/generated_bindings_capi_media_player.dart';
import '../../src/bindings/10.0/generated_bindings_capi_media_radio.dart';
import '../../src/bindings/10.0/generated_bindings_capi_media_recorder.dart';
import '../../src/bindings/10.0/generated_bindings_capi_media_screen_mirroring.dart';
import '../../src/bindings/10.0/generated_bindings_capi_media_sound_manager.dart';
import '../../src/bindings/10.0/generated_bindings_capi_media_sound_pool.dart';
import '../../src/bindings/10.0/generated_bindings_capi_media_thumbnail_util.dart';
import '../../src/bindings/10.0/generated_bindings_capi_media_tone_player.dart';
import '../../src/bindings/10.0/generated_bindings_capi_media_tool.dart';
import '../../src/bindings/10.0/generated_bindings_capi_media_wav_player.dart';
import '../../src/bindings/10.0/generated_bindings_capi_media_webrtc.dart';
import '../../src/bindings/10.0/generated_bindings_capi_mediademuxer.dart';
import '../../src/bindings/10.0/generated_bindings_capi_mediamuxer.dart';
import '../../src/bindings/10.0/generated_bindings_capi_ml_common.dart';
import '../../src/bindings/10.0/generated_bindings_capi_ml_inference_single.dart';
import '../../src/bindings/10.0/generated_bindings_capi_ml_service.dart';
import '../../src/bindings/10.0/generated_bindings_capi_network_bluetooth.dart';
import '../../src/bindings/10.0/generated_bindings_capi_network_connection.dart';
import '../../src/bindings/10.0/generated_bindings_capi_network_http.dart';
import '../../src/bindings/10.0/generated_bindings_capi_network_inm.dart';
import '../../src/bindings/10.0/generated_bindings_capi_network_mtp.dart';
import '../../src/bindings/10.0/generated_bindings_capi_network_nfc.dart';
import '../../src/bindings/10.0/generated_bindings_capi_network_softap.dart';
import '../../src/bindings/10.0/generated_bindings_capi_network_stc.dart';
import '../../src/bindings/10.0/generated_bindings_capi_network_wifi_aware.dart';
import '../../src/bindings/10.0/generated_bindings_capi_network_wifi_manager.dart';
import '../../src/bindings/10.0/generated_bindings_capi_nnstreamer.dart';
import '../../src/bindings/10.0/generated_bindings_capi_nntrainer.dart';
import '../../src/bindings/10.0/generated_bindings_capi_privacy_privilege_manager.dart';
import '../../src/bindings/10.0/generated_bindings_capi_system_device.dart';
import '../../src/bindings/10.0/generated_bindings_capi_system_info.dart';
import '../../src/bindings/10.0/generated_bindings_capi_system_media_key.dart';
import '../../src/bindings/10.0/generated_bindings_capi_system_peripheral_io.dart';
import '../../src/bindings/10.0/generated_bindings_capi_system_resource_monitor.dart';
import '../../src/bindings/10.0/generated_bindings_capi_system_runtime_info.dart';
import '../../src/bindings/10.0/generated_bindings_capi_system_sensor.dart';
import '../../src/bindings/10.0/generated_bindings_capi_system_system_settings.dart';
import '../../src/bindings/10.0/generated_bindings_capi_system_usbhost.dart';
import '../../src/bindings/10.0/generated_bindings_capi_ui_autofill.dart';
import '../../src/bindings/10.0/generated_bindings_capi_ui_autofill_common.dart';
import '../../src/bindings/10.0/generated_bindings_capi_ui_autofill_manager.dart';
import '../../src/bindings/10.0/generated_bindings_capi_ui_autofill_service.dart';
import '../../src/bindings/10.0/generated_bindings_capi_ui_inputmethod.dart';
import '../../src/bindings/10.0/generated_bindings_capi_ui_inputmethod_manager.dart';
import '../../src/bindings/10.0/generated_bindings_capi_vpnsvc.dart';
import '../../src/bindings/10.0/generated_bindings_capi_web_url_download.dart';
import '../../src/bindings/10.0/generated_bindings_cion.dart';
import '../../src/bindings/10.0/generated_bindings_contacts_service2.dart';
import '../../src/bindings/10.0/generated_bindings_core_sync_client.dart';
import '../../src/bindings/10.0/generated_bindings_data_control.dart';
import '../../src/bindings/10.0/generated_bindings_device_certificate_manager.dart';
import '../../src/bindings/10.0/generated_bindings_diagnostics.dart';
import '../../src/bindings/10.0/generated_bindings_dlog.dart';
import '../../src/bindings/10.0/generated_bindings_dpm.dart';
import '../../src/bindings/10.0/generated_bindings_feedback.dart';
import '../../src/bindings/10.0/generated_bindings_iotcon.dart';
import '../../src/bindings/10.0/generated_bindings_key_manager_client.dart';
import '../../src/bindings/10.0/generated_bindings_ma.dart';
import '../../src/bindings/10.0/generated_bindings_message_port.dart';
import '../../src/bindings/10.0/generated_bindings_mmi.dart';
import '../../src/bindings/10.0/generated_bindings_mv_3d.dart';
import '../../src/bindings/10.0/generated_bindings_mv_barcode_detector.dart';
import '../../src/bindings/10.0/generated_bindings_mv_barcode_generator.dart';
import '../../src/bindings/10.0/generated_bindings_mv_common.dart';
import '../../src/bindings/10.0/generated_bindings_mv_face.dart';
import '../../src/bindings/10.0/generated_bindings_mv_face_recognition.dart';
import '../../src/bindings/10.0/generated_bindings_mv_image.dart';
import '../../src/bindings/10.0/generated_bindings_mv_image_classification.dart';
import '../../src/bindings/10.0/generated_bindings_mv_inference.dart';
import '../../src/bindings/10.0/generated_bindings_mv_landmark_detection.dart';
import '../../src/bindings/10.0/generated_bindings_mv_object_detection.dart';
import '../../src/bindings/10.0/generated_bindings_mv_roi_tracker.dart';
import '../../src/bindings/10.0/generated_bindings_mv_surveillance.dart';
import '../../src/bindings/10.0/generated_bindings_notification.dart';
import '../../src/bindings/10.0/generated_bindings_notification_ex.dart';
import '../../src/bindings/10.0/generated_bindings_nsd_dns_sd.dart';
import '../../src/bindings/10.0/generated_bindings_nsd_ssdp.dart';
import '../../src/bindings/10.0/generated_bindings_oauth2.dart';
import '../../src/bindings/10.0/generated_bindings_openal.dart';
import '../../src/bindings/10.0/generated_bindings_phonenumber_utils.dart';
import '../../src/bindings/10.0/generated_bindings_privilege_info.dart';
import '../../src/bindings/10.0/generated_bindings_push.dart';
import '../../src/bindings/10.0/generated_bindings_rpc_port.dart';
import '../../src/bindings/10.0/generated_bindings_shortcut.dart';
import '../../src/bindings/10.0/generated_bindings_storage.dart';
import '../../src/bindings/10.0/generated_bindings_stt.dart';
import '../../src/bindings/10.0/generated_bindings_stt_engine.dart';
import '../../src/bindings/10.0/generated_bindings_tbm.dart';
import '../../src/bindings/10.0/generated_bindings_tizen_core.dart';
import '../../src/bindings/10.0/generated_bindings_ttrace.dart';
import '../../src/bindings/10.0/generated_bindings_tts.dart';
import '../../src/bindings/10.0/generated_bindings_tts_engine.dart';
import '../../src/bindings/10.0/generated_bindings_update_control.dart';
import '../../src/bindings/10.0/generated_bindings_vc.dart';
import '../../src/bindings/10.0/generated_bindings_vc_engine.dart';
import '../../src/bindings/10.0/generated_bindings_vc_manager.dart';
import '../../src/bindings/10.0/generated_bindings_webauthn_client.dart';
import '../../src/bindings/10.0/generated_bindings_wifi_direct.dart';
import '../../src/bindings/10.0/generated_bindings_yaca.dart';
import '../../src/lookup_provider.dart';

export '../../src/extensions.dart';
export '../../src/bindings/10.0/generated_bindings_accounts_svc.dart';
export '../../src/bindings/10.0/generated_bindings_appcore_agent.dart';
export '../../src/bindings/10.0/generated_bindings_asp.dart';
export '../../src/bindings/10.0/generated_bindings_badge.dart';
export '../../src/bindings/10.0/generated_bindings_bundle.dart';
export '../../src/bindings/10.0/generated_bindings_calendar_service2.dart';
export '../../src/bindings/10.0/generated_bindings_capi_appfw_alarm.dart';
export '../../src/bindings/10.0/generated_bindings_capi_appfw_app_common.dart';
export '../../src/bindings/10.0/generated_bindings_capi_appfw_app_control.dart';
export '../../src/bindings/10.0/generated_bindings_capi_appfw_app_control_uri.dart';
export '../../src/bindings/10.0/generated_bindings_capi_appfw_app_manager.dart';
export '../../src/bindings/10.0/generated_bindings_capi_appfw_application.dart';
export '../../src/bindings/10.0/generated_bindings_capi_appfw_event.dart';
export '../../src/bindings/10.0/generated_bindings_capi_appfw_job_scheduler.dart';
export '../../src/bindings/10.0/generated_bindings_capi_appfw_package_manager.dart';
export '../../src/bindings/10.0/generated_bindings_capi_appfw_preference.dart';
export '../../src/bindings/10.0/generated_bindings_capi_base_common.dart';
export '../../src/bindings/10.0/generated_bindings_capi_content_media_content.dart';
export '../../src/bindings/10.0/generated_bindings_capi_content_mime_type.dart';
export '../../src/bindings/10.0/generated_bindings_capi_context.dart';
export '../../src/bindings/10.0/generated_bindings_capi_location_manager.dart';
export '../../src/bindings/10.0/generated_bindings_capi_media_audio_io.dart';
export '../../src/bindings/10.0/generated_bindings_capi_media_camera.dart'
    hide UnnamedUnion1, UnnamedStruct1;
export '../../src/bindings/10.0/generated_bindings_capi_media_codec.dart';
export '../../src/bindings/10.0/generated_bindings_capi_media_controller.dart';
export '../../src/bindings/10.0/generated_bindings_capi_media_editor.dart';
export '../../src/bindings/10.0/generated_bindings_capi_media_image_util.dart';
export '../../src/bindings/10.0/generated_bindings_capi_media_metadata_editor.dart';
export '../../src/bindings/10.0/generated_bindings_capi_media_metadata_extractor.dart';
export '../../src/bindings/10.0/generated_bindings_capi_media_player.dart';
export '../../src/bindings/10.0/generated_bindings_capi_media_radio.dart';
export '../../src/bindings/10.0/generated_bindings_capi_media_recorder.dart';
export '../../src/bindings/10.0/generated_bindings_capi_media_screen_mirroring.dart';
export '../../src/bindings/10.0/generated_bindings_capi_media_sound_manager.dart';
export '../../src/bindings/10.0/generated_bindings_capi_media_sound_pool.dart';
export '../../src/bindings/10.0/generated_bindings_capi_media_thumbnail_util.dart';
export '../../src/bindings/10.0/generated_bindings_capi_media_tone_player.dart';
export '../../src/bindings/10.0/generated_bindings_capi_media_tool.dart';
export '../../src/bindings/10.0/generated_bindings_capi_media_wav_player.dart';
export '../../src/bindings/10.0/generated_bindings_capi_media_webrtc.dart'
    hide UnnamedUnion1;
export '../../src/bindings/10.0/generated_bindings_capi_mediademuxer.dart';
export '../../src/bindings/10.0/generated_bindings_capi_mediamuxer.dart';
export '../../src/bindings/10.0/generated_bindings_capi_ml_common.dart';
export '../../src/bindings/10.0/generated_bindings_capi_ml_inference_single.dart';
export '../../src/bindings/10.0/generated_bindings_capi_ml_service.dart';
export '../../src/bindings/10.0/generated_bindings_capi_network_bluetooth.dart';
export '../../src/bindings/10.0/generated_bindings_capi_network_connection.dart';
export '../../src/bindings/10.0/generated_bindings_capi_network_http.dart';
export '../../src/bindings/10.0/generated_bindings_capi_network_inm.dart';
export '../../src/bindings/10.0/generated_bindings_capi_network_mtp.dart';
export '../../src/bindings/10.0/generated_bindings_capi_network_nfc.dart';
export '../../src/bindings/10.0/generated_bindings_capi_network_softap.dart';
export '../../src/bindings/10.0/generated_bindings_capi_network_stc.dart';
export '../../src/bindings/10.0/generated_bindings_capi_network_wifi_aware.dart';
export '../../src/bindings/10.0/generated_bindings_capi_network_wifi_manager.dart';
export '../../src/bindings/10.0/generated_bindings_capi_nnstreamer.dart';
export '../../src/bindings/10.0/generated_bindings_capi_nntrainer.dart';
export '../../src/bindings/10.0/generated_bindings_capi_privacy_privilege_manager.dart';
export '../../src/bindings/10.0/generated_bindings_capi_system_device.dart';
export '../../src/bindings/10.0/generated_bindings_capi_system_info.dart';
export '../../src/bindings/10.0/generated_bindings_capi_system_media_key.dart';
export '../../src/bindings/10.0/generated_bindings_capi_system_peripheral_io.dart';
export '../../src/bindings/10.0/generated_bindings_capi_system_resource_monitor.dart';
export '../../src/bindings/10.0/generated_bindings_capi_system_runtime_info.dart';
export '../../src/bindings/10.0/generated_bindings_capi_system_sensor.dart';
export '../../src/bindings/10.0/generated_bindings_capi_system_system_settings.dart';
export '../../src/bindings/10.0/generated_bindings_capi_system_usbhost.dart';
export '../../src/bindings/10.0/generated_bindings_capi_ui_autofill.dart';
export '../../src/bindings/10.0/generated_bindings_capi_ui_autofill_common.dart';
export '../../src/bindings/10.0/generated_bindings_capi_ui_autofill_manager.dart';
export '../../src/bindings/10.0/generated_bindings_capi_ui_autofill_service.dart';
export '../../src/bindings/10.0/generated_bindings_capi_ui_inputmethod.dart';
export '../../src/bindings/10.0/generated_bindings_capi_ui_inputmethod_manager.dart';
export '../../src/bindings/10.0/generated_bindings_capi_vpnsvc.dart';
export '../../src/bindings/10.0/generated_bindings_capi_web_url_download.dart';
export '../../src/bindings/10.0/generated_bindings_cion.dart';
export '../../src/bindings/10.0/generated_bindings_contacts_service2.dart';
export '../../src/bindings/10.0/generated_bindings_core_sync_client.dart';
export '../../src/bindings/10.0/generated_bindings_data_control.dart';
export '../../src/bindings/10.0/generated_bindings_device_certificate_manager.dart';
export '../../src/bindings/10.0/generated_bindings_diagnostics.dart';
export '../../src/bindings/10.0/generated_bindings_dlog.dart';
export '../../src/bindings/10.0/generated_bindings_dpm.dart';
export '../../src/bindings/10.0/generated_bindings_feedback.dart';
export '../../src/bindings/10.0/generated_bindings_iotcon.dart';
export '../../src/bindings/10.0/generated_bindings_key_manager_client.dart';
export '../../src/bindings/10.0/generated_bindings_ma.dart';
export '../../src/bindings/10.0/generated_bindings_message_port.dart';
export '../../src/bindings/10.0/generated_bindings_mmi.dart';
export '../../src/bindings/10.0/generated_bindings_mv_3d.dart';
export '../../src/bindings/10.0/generated_bindings_mv_barcode_detector.dart';
export '../../src/bindings/10.0/generated_bindings_mv_barcode_generator.dart';
export '../../src/bindings/10.0/generated_bindings_mv_common.dart';
export '../../src/bindings/10.0/generated_bindings_mv_face.dart';
export '../../src/bindings/10.0/generated_bindings_mv_face_recognition.dart';
export '../../src/bindings/10.0/generated_bindings_mv_image.dart';
export '../../src/bindings/10.0/generated_bindings_mv_image_classification.dart';
export '../../src/bindings/10.0/generated_bindings_mv_inference.dart';
export '../../src/bindings/10.0/generated_bindings_mv_landmark_detection.dart';
export '../../src/bindings/10.0/generated_bindings_mv_object_detection.dart';
export '../../src/bindings/10.0/generated_bindings_mv_roi_tracker.dart';
export '../../src/bindings/10.0/generated_bindings_mv_surveillance.dart';
export '../../src/bindings/10.0/generated_bindings_notification.dart';
export '../../src/bindings/10.0/generated_bindings_notification_ex.dart';
export '../../src/bindings/10.0/generated_bindings_nsd_dns_sd.dart';
export '../../src/bindings/10.0/generated_bindings_nsd_ssdp.dart';
export '../../src/bindings/10.0/generated_bindings_oauth2.dart';
export '../../src/bindings/10.0/generated_bindings_openal.dart';
export '../../src/bindings/10.0/generated_bindings_phonenumber_utils.dart';
export '../../src/bindings/10.0/generated_bindings_privilege_info.dart';
export '../../src/bindings/10.0/generated_bindings_push.dart';
export '../../src/bindings/10.0/generated_bindings_rpc_port.dart';
export '../../src/bindings/10.0/generated_bindings_shortcut.dart';
export '../../src/bindings/10.0/generated_bindings_storage.dart';
export '../../src/bindings/10.0/generated_bindings_stt.dart';
export '../../src/bindings/10.0/generated_bindings_stt_engine.dart';
export '../../src/bindings/10.0/generated_bindings_tbm.dart';
export '../../src/bindings/10.0/generated_bindings_tizen_core.dart';
export '../../src/bindings/10.0/generated_bindings_ttrace.dart';
export '../../src/bindings/10.0/generated_bindings_tts.dart';
export '../../src/bindings/10.0/generated_bindings_tts_engine.dart';
export '../../src/bindings/10.0/generated_bindings_update_control.dart';
export '../../src/bindings/10.0/generated_bindings_vc.dart';
export '../../src/bindings/10.0/generated_bindings_vc_engine.dart';
export '../../src/bindings/10.0/generated_bindings_vc_manager.dart';
export '../../src/bindings/10.0/generated_bindings_webauthn_client.dart';
export '../../src/bindings/10.0/generated_bindings_wifi_direct.dart';
export '../../src/bindings/10.0/generated_bindings_yaca.dart';
export '../../src/bindings/10.0/generated_bindings_time.dart'
    hide UnnamedUnion1, UnnamedStruct1;

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

Tizen100AccountsSvc? _tizenAccountsSvc;
Tizen100AccountsSvc get tizenAccountsSvc => _tizenAccountsSvc ??=
    _getTizenInstance(accountsSvcSymbols, Tizen100AccountsSvc.fromLookup)!;

Tizen100AppcoreAgent? _tizenAppcoreAgent;
Tizen100AppcoreAgent get tizenAppcoreAgent => _tizenAppcoreAgent ??=
    _getTizenInstance(appcoreAgentSymbols, Tizen100AppcoreAgent.fromLookup)!;

Tizen100Asp? _tizenAsp;
Tizen100Asp get tizenAsp =>
    _tizenAsp ??= _getTizenInstance(aspSymbols, Tizen100Asp.fromLookup)!;

Tizen100Badge? _tizenBadge;
Tizen100Badge get tizenBadge =>
    _tizenBadge ??= _getTizenInstance(badgeSymbols, Tizen100Badge.fromLookup)!;

Tizen100Bundle? _tizenBundle;
Tizen100Bundle get tizenBundle => _tizenBundle ??=
    _getTizenInstance(bundleSymbols, Tizen100Bundle.fromLookup)!;

Tizen100CalendarService2? _tizenCalendarService2;
Tizen100CalendarService2 get tizenCalendarService2 =>
    _tizenCalendarService2 ??= _getTizenInstance(
        calendarService2Symbols, Tizen100CalendarService2.fromLookup)!;

Tizen100CapiAppfwAlarm? _tizenCapiAppfwAlarm;
Tizen100CapiAppfwAlarm get tizenCapiAppfwAlarm =>
    _tizenCapiAppfwAlarm ??= _getTizenInstance(
        capiAppfwAlarmSymbols, Tizen100CapiAppfwAlarm.fromLookup)!;

Tizen100CapiAppfwAppCommon? _tizenCapiAppfwAppCommon;
Tizen100CapiAppfwAppCommon get tizenCapiAppfwAppCommon =>
    _tizenCapiAppfwAppCommon ??= _getTizenInstance(
        capiAppfwAppCommonSymbols, Tizen100CapiAppfwAppCommon.fromLookup)!;

Tizen100CapiAppfwAppControl? _tizenCapiAppfwAppControl;
Tizen100CapiAppfwAppControl get tizenCapiAppfwAppControl =>
    _tizenCapiAppfwAppControl ??= _getTizenInstance(
        capiAppfwAppControlSymbols, Tizen100CapiAppfwAppControl.fromLookup)!;

Tizen100CapiAppfwAppControlUri? _tizenCapiAppfwAppControlUri;
Tizen100CapiAppfwAppControlUri get tizenCapiAppfwAppControlUri =>
    _tizenCapiAppfwAppControlUri ??= _getTizenInstance(
        capiAppfwAppControlUriSymbols,
        Tizen100CapiAppfwAppControlUri.fromLookup)!;

Tizen100CapiAppfwAppManager? _tizenCapiAppfwAppManager;
Tizen100CapiAppfwAppManager get tizenCapiAppfwAppManager =>
    _tizenCapiAppfwAppManager ??= _getTizenInstance(
        capiAppfwAppManagerSymbols, Tizen100CapiAppfwAppManager.fromLookup)!;

Tizen100CapiAppfwApplication? _tizenCapiAppfwApplication;
Tizen100CapiAppfwApplication get tizenCapiAppfwApplication =>
    _tizenCapiAppfwApplication ??= _getTizenInstance(
        capiAppfwApplicationSymbols, Tizen100CapiAppfwApplication.fromLookup)!;

Tizen100CapiAppfwEvent? _tizenCapiAppfwEvent;
Tizen100CapiAppfwEvent get tizenCapiAppfwEvent =>
    _tizenCapiAppfwEvent ??= _getTizenInstance(
        capiAppfwEventSymbols, Tizen100CapiAppfwEvent.fromLookup)!;

Tizen100CapiAppfwJobScheduler? _tizenCapiAppfwJobScheduler;
Tizen100CapiAppfwJobScheduler get tizenCapiAppfwJobScheduler =>
    _tizenCapiAppfwJobScheduler ??= _getTizenInstance(
        capiAppfwJobSchedulerSymbols,
        Tizen100CapiAppfwJobScheduler.fromLookup)!;

Tizen100CapiAppfwPackageManager? _tizenCapiAppfwPackageManager;
Tizen100CapiAppfwPackageManager get tizenCapiAppfwPackageManager =>
    _tizenCapiAppfwPackageManager ??= _getTizenInstance(
        capiAppfwPackageManagerSymbols,
        Tizen100CapiAppfwPackageManager.fromLookup)!;

Tizen100CapiAppfwPreference? _tizenCapiAppfwPreference;
Tizen100CapiAppfwPreference get tizenCapiAppfwPreference =>
    _tizenCapiAppfwPreference ??= _getTizenInstance(
        capiAppfwPreferenceSymbols, Tizen100CapiAppfwPreference.fromLookup)!;

Tizen100CapiBaseCommon? _tizenCapiBaseCommon;
Tizen100CapiBaseCommon get tizenCapiBaseCommon =>
    _tizenCapiBaseCommon ??= _getTizenInstance(
        capiBaseCommonSymbols, Tizen100CapiBaseCommon.fromLookup)!;

Tizen100CapiContentMediaContent? _tizenCapiContentMediaContent;
Tizen100CapiContentMediaContent get tizenCapiContentMediaContent =>
    _tizenCapiContentMediaContent ??= _getTizenInstance(
        capiContentMediaContentSymbols,
        Tizen100CapiContentMediaContent.fromLookup)!;

Tizen100CapiContentMimeType? _tizenCapiContentMimeType;
Tizen100CapiContentMimeType get tizenCapiContentMimeType =>
    _tizenCapiContentMimeType ??= _getTizenInstance(
        capiContentMimeTypeSymbols, Tizen100CapiContentMimeType.fromLookup)!;

Tizen100CapiContext? _tizenCapiContext;
Tizen100CapiContext get tizenCapiContext => _tizenCapiContext ??=
    _getTizenInstance(capiContextSymbols, Tizen100CapiContext.fromLookup)!;

Tizen100CapiLocationManager? _tizenCapiLocationManager;
Tizen100CapiLocationManager get tizenCapiLocationManager =>
    _tizenCapiLocationManager ??= _getTizenInstance(
        capiLocationManagerSymbols, Tizen100CapiLocationManager.fromLookup)!;

Tizen100CapiMediaAudioIo? _tizenCapiMediaAudioIo;
Tizen100CapiMediaAudioIo get tizenCapiMediaAudioIo =>
    _tizenCapiMediaAudioIo ??= _getTizenInstance(
        capiMediaAudioIoSymbols, Tizen100CapiMediaAudioIo.fromLookup)!;

Tizen100CapiMediaCamera? _tizenCapiMediaCamera;
Tizen100CapiMediaCamera get tizenCapiMediaCamera =>
    _tizenCapiMediaCamera ??= _getTizenInstance(
        capiMediaCameraSymbols, Tizen100CapiMediaCamera.fromLookup)!;

Tizen100CapiMediaCodec? _tizenCapiMediaCodec;
Tizen100CapiMediaCodec get tizenCapiMediaCodec =>
    _tizenCapiMediaCodec ??= _getTizenInstance(
        capiMediaCodecSymbols, Tizen100CapiMediaCodec.fromLookup)!;

Tizen100CapiMediaController? _tizenCapiMediaController;
Tizen100CapiMediaController get tizenCapiMediaController =>
    _tizenCapiMediaController ??= _getTizenInstance(
        capiMediaControllerSymbols, Tizen100CapiMediaController.fromLookup)!;

Tizen100CapiMediaEditor? _tizenCapiMediaEditor;
Tizen100CapiMediaEditor get tizenCapiMediaEditor =>
    _tizenCapiMediaEditor ??= _getTizenInstance(
        capiMediaEditorSymbols, Tizen100CapiMediaEditor.fromLookup)!;

Tizen100CapiMediaImageUtil? _tizenCapiMediaImageUtil;
Tizen100CapiMediaImageUtil get tizenCapiMediaImageUtil =>
    _tizenCapiMediaImageUtil ??= _getTizenInstance(
        capiMediaImageUtilSymbols, Tizen100CapiMediaImageUtil.fromLookup)!;

Tizen100CapiMediaMetadataEditor? _tizenCapiMediaMetadataEditor;
Tizen100CapiMediaMetadataEditor get tizenCapiMediaMetadataEditor =>
    _tizenCapiMediaMetadataEditor ??= _getTizenInstance(
        capiMediaMetadataEditorSymbols,
        Tizen100CapiMediaMetadataEditor.fromLookup)!;

Tizen100CapiMediaMetadataExtractor? _tizenCapiMediaMetadataExtractor;
Tizen100CapiMediaMetadataExtractor get tizenCapiMediaMetadataExtractor =>
    _tizenCapiMediaMetadataExtractor ??= _getTizenInstance(
        capiMediaMetadataExtractorSymbols,
        Tizen100CapiMediaMetadataExtractor.fromLookup)!;

Tizen100CapiMediaPlayer? _tizenCapiMediaPlayer;
Tizen100CapiMediaPlayer get tizenCapiMediaPlayer =>
    _tizenCapiMediaPlayer ??= _getTizenInstance(
        capiMediaPlayerSymbols, Tizen100CapiMediaPlayer.fromLookup)!;

Tizen100CapiMediaRadio? _tizenCapiMediaRadio;
Tizen100CapiMediaRadio get tizenCapiMediaRadio =>
    _tizenCapiMediaRadio ??= _getTizenInstance(
        capiMediaRadioSymbols, Tizen100CapiMediaRadio.fromLookup)!;

Tizen100CapiMediaRecorder? _tizenCapiMediaRecorder;
Tizen100CapiMediaRecorder get tizenCapiMediaRecorder =>
    _tizenCapiMediaRecorder ??= _getTizenInstance(
        capiMediaRecorderSymbols, Tizen100CapiMediaRecorder.fromLookup)!;

Tizen100CapiMediaScreenMirroring? _tizenCapiMediaScreenMirroring;
Tizen100CapiMediaScreenMirroring get tizenCapiMediaScreenMirroring =>
    _tizenCapiMediaScreenMirroring ??= _getTizenInstance(
        capiMediaScreenMirroringSymbols,
        Tizen100CapiMediaScreenMirroring.fromLookup)!;

Tizen100CapiMediaSoundManager? _tizenCapiMediaSoundManager;
Tizen100CapiMediaSoundManager get tizenCapiMediaSoundManager =>
    _tizenCapiMediaSoundManager ??= _getTizenInstance(
        capiMediaSoundManagerSymbols,
        Tizen100CapiMediaSoundManager.fromLookup)!;

Tizen100CapiMediaSoundPool? _tizenCapiMediaSoundPool;
Tizen100CapiMediaSoundPool get tizenCapiMediaSoundPool =>
    _tizenCapiMediaSoundPool ??= _getTizenInstance(
        capiMediaSoundPoolSymbols, Tizen100CapiMediaSoundPool.fromLookup)!;

Tizen100CapiMediaThumbnailUtil? _tizenCapiMediaThumbnailUtil;
Tizen100CapiMediaThumbnailUtil get tizenCapiMediaThumbnailUtil =>
    _tizenCapiMediaThumbnailUtil ??= _getTizenInstance(
        capiMediaThumbnailUtilSymbols,
        Tizen100CapiMediaThumbnailUtil.fromLookup)!;

Tizen100CapiMediaTonePlayer? _tizenCapiMediaTonePlayer;
Tizen100CapiMediaTonePlayer get tizenCapiMediaTonePlayer =>
    _tizenCapiMediaTonePlayer ??= _getTizenInstance(
        capiMediaTonePlayerSymbols, Tizen100CapiMediaTonePlayer.fromLookup)!;

Tizen100CapiMediaTool? _tizenCapiMediaTool;
Tizen100CapiMediaTool get tizenCapiMediaTool => _tizenCapiMediaTool ??=
    _getTizenInstance(capiMediaToolSymbols, Tizen100CapiMediaTool.fromLookup)!;

Tizen100CapiMediaWavPlayer? _tizenCapiMediaWavPlayer;
Tizen100CapiMediaWavPlayer get tizenCapiMediaWavPlayer =>
    _tizenCapiMediaWavPlayer ??= _getTizenInstance(
        capiMediaWavPlayerSymbols, Tizen100CapiMediaWavPlayer.fromLookup)!;

Tizen100CapiMediaWebrtc? _tizenCapiMediaWebrtc;
Tizen100CapiMediaWebrtc get tizenCapiMediaWebrtc =>
    _tizenCapiMediaWebrtc ??= _getTizenInstance(
        capiMediaWebrtcSymbols, Tizen100CapiMediaWebrtc.fromLookup)!;

Tizen100CapiMediademuxer? _tizenCapiMediademuxer;
Tizen100CapiMediademuxer get tizenCapiMediademuxer =>
    _tizenCapiMediademuxer ??= _getTizenInstance(
        capiMediademuxerSymbols, Tizen100CapiMediademuxer.fromLookup)!;

Tizen100CapiMediamuxer? _tizenCapiMediamuxer;
Tizen100CapiMediamuxer get tizenCapiMediamuxer =>
    _tizenCapiMediamuxer ??= _getTizenInstance(
        capiMediamuxerSymbols, Tizen100CapiMediamuxer.fromLookup)!;

Tizen100CapiMlCommon? _tizenCapiMlCommon;
Tizen100CapiMlCommon get tizenCapiMlCommon => _tizenCapiMlCommon ??=
    _getTizenInstance(capiMlCommonSymbols, Tizen100CapiMlCommon.fromLookup)!;

Tizen100CapiMlInferenceSingle? _tizenCapiMlInferenceSingle;
Tizen100CapiMlInferenceSingle get tizenCapiMlInferenceSingle =>
    _tizenCapiMlInferenceSingle ??= _getTizenInstance(
        capiMlInferenceSingleSymbols,
        Tizen100CapiMlInferenceSingle.fromLookup)!;

Tizen100CapiMlService? _tizenCapiMlService;
Tizen100CapiMlService get tizenCapiMlService => _tizenCapiMlService ??=
    _getTizenInstance(capiMlServiceSymbols, Tizen100CapiMlService.fromLookup)!;

Tizen100CapiNetworkBluetooth? _tizenCapiNetworkBluetooth;
Tizen100CapiNetworkBluetooth get tizenCapiNetworkBluetooth =>
    _tizenCapiNetworkBluetooth ??= _getTizenInstance(
        capiNetworkBluetoothSymbols, Tizen100CapiNetworkBluetooth.fromLookup)!;

Tizen100CapiNetworkConnection? _tizenCapiNetworkConnection;
Tizen100CapiNetworkConnection get tizenCapiNetworkConnection =>
    _tizenCapiNetworkConnection ??= _getTizenInstance(
        capiNetworkConnectionSymbols,
        Tizen100CapiNetworkConnection.fromLookup)!;

Tizen100CapiNetworkHttp? _tizenCapiNetworkHttp;
Tizen100CapiNetworkHttp get tizenCapiNetworkHttp =>
    _tizenCapiNetworkHttp ??= _getTizenInstance(
        capiNetworkHttpSymbols, Tizen100CapiNetworkHttp.fromLookup)!;

Tizen100CapiNetworkInm? _tizenCapiNetworkInm;
Tizen100CapiNetworkInm get tizenCapiNetworkInm =>
    _tizenCapiNetworkInm ??= _getTizenInstance(
        capiNetworkInmSymbols, Tizen100CapiNetworkInm.fromLookup)!;

Tizen100CapiNetworkMtp? _tizenCapiNetworkMtp;
Tizen100CapiNetworkMtp get tizenCapiNetworkMtp =>
    _tizenCapiNetworkMtp ??= _getTizenInstance(
        capiNetworkMtpSymbols, Tizen100CapiNetworkMtp.fromLookup)!;

Tizen100CapiNetworkNfc? _tizenCapiNetworkNfc;
Tizen100CapiNetworkNfc get tizenCapiNetworkNfc =>
    _tizenCapiNetworkNfc ??= _getTizenInstance(
        capiNetworkNfcSymbols, Tizen100CapiNetworkNfc.fromLookup)!;

Tizen100CapiNetworkSoftap? _tizenCapiNetworkSoftap;
Tizen100CapiNetworkSoftap get tizenCapiNetworkSoftap =>
    _tizenCapiNetworkSoftap ??= _getTizenInstance(
        capiNetworkSoftapSymbols, Tizen100CapiNetworkSoftap.fromLookup)!;

Tizen100CapiNetworkStc? _tizenCapiNetworkStc;
Tizen100CapiNetworkStc get tizenCapiNetworkStc =>
    _tizenCapiNetworkStc ??= _getTizenInstance(
        capiNetworkStcSymbols, Tizen100CapiNetworkStc.fromLookup)!;

Tizen100CapiNetworkWifiAware? _tizenCapiNetworkWifiAware;
Tizen100CapiNetworkWifiAware get tizenCapiNetworkWifiAware =>
    _tizenCapiNetworkWifiAware ??= _getTizenInstance(
        capiNetworkWifiAwareSymbols, Tizen100CapiNetworkWifiAware.fromLookup)!;

Tizen100CapiNetworkWifiManager? _tizenCapiNetworkWifiManager;
Tizen100CapiNetworkWifiManager get tizenCapiNetworkWifiManager =>
    _tizenCapiNetworkWifiManager ??= _getTizenInstance(
        capiNetworkWifiManagerSymbols,
        Tizen100CapiNetworkWifiManager.fromLookup)!;

Tizen100CapiNnstreamer? _tizenCapiNnstreamer;
Tizen100CapiNnstreamer get tizenCapiNnstreamer =>
    _tizenCapiNnstreamer ??= _getTizenInstance(
        capiNnstreamerSymbols, Tizen100CapiNnstreamer.fromLookup)!;

Tizen100CapiNntrainer? _tizenCapiNntrainer;
Tizen100CapiNntrainer get tizenCapiNntrainer => _tizenCapiNntrainer ??=
    _getTizenInstance(capiNntrainerSymbols, Tizen100CapiNntrainer.fromLookup)!;

Tizen100CapiPrivacyPrivilegeManager? _tizenCapiPrivacyPrivilegeManager;
Tizen100CapiPrivacyPrivilegeManager get tizenCapiPrivacyPrivilegeManager =>
    _tizenCapiPrivacyPrivilegeManager ??= _getTizenInstance(
        capiPrivacyPrivilegeManagerSymbols,
        Tizen100CapiPrivacyPrivilegeManager.fromLookup)!;

Tizen100CapiSystemDevice? _tizenCapiSystemDevice;
Tizen100CapiSystemDevice get tizenCapiSystemDevice =>
    _tizenCapiSystemDevice ??= _getTizenInstance(
        capiSystemDeviceSymbols, Tizen100CapiSystemDevice.fromLookup)!;

Tizen100CapiSystemInfo? _tizenCapiSystemInfo;
Tizen100CapiSystemInfo get tizenCapiSystemInfo =>
    _tizenCapiSystemInfo ??= _getTizenInstance(
        capiSystemInfoSymbols, Tizen100CapiSystemInfo.fromLookup)!;

Tizen100CapiSystemMediaKey? _tizenCapiSystemMediaKey;
Tizen100CapiSystemMediaKey get tizenCapiSystemMediaKey =>
    _tizenCapiSystemMediaKey ??= _getTizenInstance(
        capiSystemMediaKeySymbols, Tizen100CapiSystemMediaKey.fromLookup)!;

Tizen100CapiSystemPeripheralIo? _tizenCapiSystemPeripheralIo;
Tizen100CapiSystemPeripheralIo get tizenCapiSystemPeripheralIo =>
    _tizenCapiSystemPeripheralIo ??= _getTizenInstance(
        capiSystemPeripheralIoSymbols,
        Tizen100CapiSystemPeripheralIo.fromLookup)!;

Tizen100CapiSystemResourceMonitor? _tizenCapiSystemResourceMonitor;
Tizen100CapiSystemResourceMonitor get tizenCapiSystemResourceMonitor =>
    _tizenCapiSystemResourceMonitor ??= _getTizenInstance(
        capiSystemResourceMonitorSymbols,
        Tizen100CapiSystemResourceMonitor.fromLookup)!;

Tizen100CapiSystemRuntimeInfo? _tizenCapiSystemRuntimeInfo;
Tizen100CapiSystemRuntimeInfo get tizenCapiSystemRuntimeInfo =>
    _tizenCapiSystemRuntimeInfo ??= _getTizenInstance(
        capiSystemRuntimeInfoSymbols,
        Tizen100CapiSystemRuntimeInfo.fromLookup)!;

Tizen100CapiSystemSensor? _tizenCapiSystemSensor;
Tizen100CapiSystemSensor get tizenCapiSystemSensor =>
    _tizenCapiSystemSensor ??= _getTizenInstance(
        capiSystemSensorSymbols, Tizen100CapiSystemSensor.fromLookup)!;

Tizen100CapiSystemSystemSettings? _tizenCapiSystemSystemSettings;
Tizen100CapiSystemSystemSettings get tizenCapiSystemSystemSettings =>
    _tizenCapiSystemSystemSettings ??= _getTizenInstance(
        capiSystemSystemSettingsSymbols,
        Tizen100CapiSystemSystemSettings.fromLookup)!;

Tizen100CapiSystemUsbhost? _tizenCapiSystemUsbhost;
Tizen100CapiSystemUsbhost get tizenCapiSystemUsbhost =>
    _tizenCapiSystemUsbhost ??= _getTizenInstance(
        capiSystemUsbhostSymbols, Tizen100CapiSystemUsbhost.fromLookup)!;

Tizen100CapiUiAutofill? _tizenCapiUiAutofill;
Tizen100CapiUiAutofill get tizenCapiUiAutofill =>
    _tizenCapiUiAutofill ??= _getTizenInstance(
        capiUiAutofillSymbols, Tizen100CapiUiAutofill.fromLookup)!;

Tizen100CapiUiAutofillCommon? _tizenCapiUiAutofillCommon;
Tizen100CapiUiAutofillCommon get tizenCapiUiAutofillCommon =>
    _tizenCapiUiAutofillCommon ??= _getTizenInstance(
        capiUiAutofillCommonSymbols, Tizen100CapiUiAutofillCommon.fromLookup)!;

Tizen100CapiUiAutofillManager? _tizenCapiUiAutofillManager;
Tizen100CapiUiAutofillManager get tizenCapiUiAutofillManager =>
    _tizenCapiUiAutofillManager ??= _getTizenInstance(
        capiUiAutofillManagerSymbols,
        Tizen100CapiUiAutofillManager.fromLookup)!;

Tizen100CapiUiAutofillService? _tizenCapiUiAutofillService;
Tizen100CapiUiAutofillService get tizenCapiUiAutofillService =>
    _tizenCapiUiAutofillService ??= _getTizenInstance(
        capiUiAutofillServiceSymbols,
        Tizen100CapiUiAutofillService.fromLookup)!;

Tizen100CapiUiInputmethod? _tizenCapiUiInputmethod;
Tizen100CapiUiInputmethod get tizenCapiUiInputmethod =>
    _tizenCapiUiInputmethod ??= _getTizenInstance(
        capiUiInputmethodSymbols, Tizen100CapiUiInputmethod.fromLookup)!;

Tizen100CapiUiInputmethodManager? _tizenCapiUiInputmethodManager;
Tizen100CapiUiInputmethodManager get tizenCapiUiInputmethodManager =>
    _tizenCapiUiInputmethodManager ??= _getTizenInstance(
        capiUiInputmethodManagerSymbols,
        Tizen100CapiUiInputmethodManager.fromLookup)!;

Tizen100CapiVpnsvc? _tizenCapiVpnsvc;
Tizen100CapiVpnsvc get tizenCapiVpnsvc => _tizenCapiVpnsvc ??=
    _getTizenInstance(capiVpnsvcSymbols, Tizen100CapiVpnsvc.fromLookup)!;

Tizen100CapiWebUrlDownload? _tizenCapiWebUrlDownload;
Tizen100CapiWebUrlDownload get tizenCapiWebUrlDownload =>
    _tizenCapiWebUrlDownload ??= _getTizenInstance(
        capiWebUrlDownloadSymbols, Tizen100CapiWebUrlDownload.fromLookup)!;

Tizen100Cion? _tizenCion;
Tizen100Cion get tizenCion =>
    _tizenCion ??= _getTizenInstance(cionSymbols, Tizen100Cion.fromLookup)!;

Tizen100ContactsService2? _tizenContactsService2;
Tizen100ContactsService2 get tizenContactsService2 =>
    _tizenContactsService2 ??= _getTizenInstance(
        contactsService2Symbols, Tizen100ContactsService2.fromLookup)!;

Tizen100CoreSyncClient? _tizenCoreSyncClient;
Tizen100CoreSyncClient get tizenCoreSyncClient =>
    _tizenCoreSyncClient ??= _getTizenInstance(
        coreSyncClientSymbols, Tizen100CoreSyncClient.fromLookup)!;

Tizen100DataControl? _tizenDataControl;
Tizen100DataControl get tizenDataControl => _tizenDataControl ??=
    _getTizenInstance(dataControlSymbols, Tizen100DataControl.fromLookup)!;

Tizen100DeviceCertificateManager? _tizenDeviceCertificateManager;
Tizen100DeviceCertificateManager get tizenDeviceCertificateManager =>
    _tizenDeviceCertificateManager ??= _getTizenInstance(
        deviceCertificateManagerSymbols,
        Tizen100DeviceCertificateManager.fromLookup)!;

Tizen100Diagnostics? _tizenDiagnostics;
Tizen100Diagnostics get tizenDiagnostics => _tizenDiagnostics ??=
    _getTizenInstance(diagnosticsSymbols, Tizen100Diagnostics.fromLookup)!;

Tizen100Dlog? _tizenDlog;
Tizen100Dlog get tizenDlog =>
    _tizenDlog ??= _getTizenInstance(dlogSymbols, Tizen100Dlog.fromLookup)!;

Tizen100Dpm? _tizenDpm;
Tizen100Dpm get tizenDpm =>
    _tizenDpm ??= _getTizenInstance(dpmSymbols, Tizen100Dpm.fromLookup)!;

Tizen100Feedback? _tizenFeedback;
Tizen100Feedback get tizenFeedback => _tizenFeedback ??=
    _getTizenInstance(feedbackSymbols, Tizen100Feedback.fromLookup)!;

Tizen100Iotcon? _tizenIotcon;
Tizen100Iotcon get tizenIotcon => _tizenIotcon ??=
    _getTizenInstance(iotconSymbols, Tizen100Iotcon.fromLookup)!;

Tizen100KeyManagerClient? _tizenKeyManagerClient;
Tizen100KeyManagerClient get tizenKeyManagerClient =>
    _tizenKeyManagerClient ??= _getTizenInstance(
        keyManagerClientSymbols, Tizen100KeyManagerClient.fromLookup)!;

Tizen100Ma? _tizenMa;
Tizen100Ma get tizenMa =>
    _tizenMa ??= _getTizenInstance(maSymbols, Tizen100Ma.fromLookup)!;

Tizen100MessagePort? _tizenMessagePort;
Tizen100MessagePort get tizenMessagePort => _tizenMessagePort ??=
    _getTizenInstance(messagePortSymbols, Tizen100MessagePort.fromLookup)!;

Tizen100Mmi? _tizenMmi;
Tizen100Mmi get tizenMmi =>
    _tizenMmi ??= _getTizenInstance(mmiSymbols, Tizen100Mmi.fromLookup)!;

Tizen100Mv3d? _tizenMv3d;
Tizen100Mv3d get tizenMv3d =>
    _tizenMv3d ??= _getTizenInstance(mv3dSymbols, Tizen100Mv3d.fromLookup)!;

Tizen100MvBarcodeDetector? _tizenMvBarcodeDetector;
Tizen100MvBarcodeDetector get tizenMvBarcodeDetector =>
    _tizenMvBarcodeDetector ??= _getTizenInstance(
        mvBarcodeDetectorSymbols, Tizen100MvBarcodeDetector.fromLookup)!;

Tizen100MvBarcodeGenerator? _tizenMvBarcodeGenerator;
Tizen100MvBarcodeGenerator get tizenMvBarcodeGenerator =>
    _tizenMvBarcodeGenerator ??= _getTizenInstance(
        mvBarcodeGeneratorSymbols, Tizen100MvBarcodeGenerator.fromLookup)!;

Tizen100MvCommon? _tizenMvCommon;
Tizen100MvCommon get tizenMvCommon => _tizenMvCommon ??=
    _getTizenInstance(mvCommonSymbols, Tizen100MvCommon.fromLookup)!;

Tizen100MvFace? _tizenMvFace;
Tizen100MvFace get tizenMvFace => _tizenMvFace ??=
    _getTizenInstance(mvFaceSymbols, Tizen100MvFace.fromLookup)!;

Tizen100MvFaceRecognition? _tizenMvFaceRecognition;
Tizen100MvFaceRecognition get tizenMvFaceRecognition =>
    _tizenMvFaceRecognition ??= _getTizenInstance(
        mvFaceRecognitionSymbols, Tizen100MvFaceRecognition.fromLookup)!;

Tizen100MvImage? _tizenMvImage;
Tizen100MvImage get tizenMvImage => _tizenMvImage ??=
    _getTizenInstance(mvImageSymbols, Tizen100MvImage.fromLookup)!;

Tizen100MvImageClassification? _tizenMvImageClassification;
Tizen100MvImageClassification get tizenMvImageClassification =>
    _tizenMvImageClassification ??= _getTizenInstance(
        mvImageClassificationSymbols,
        Tizen100MvImageClassification.fromLookup)!;

Tizen100MvInference? _tizenMvInference;
Tizen100MvInference get tizenMvInference => _tizenMvInference ??=
    _getTizenInstance(mvInferenceSymbols, Tizen100MvInference.fromLookup)!;

Tizen100MvLandmarkDetection? _tizenMvLandmarkDetection;
Tizen100MvLandmarkDetection get tizenMvLandmarkDetection =>
    _tizenMvLandmarkDetection ??= _getTizenInstance(
        mvLandmarkDetectionSymbols, Tizen100MvLandmarkDetection.fromLookup)!;

Tizen100MvObjectDetection? _tizenMvObjectDetection;
Tizen100MvObjectDetection get tizenMvObjectDetection =>
    _tizenMvObjectDetection ??= _getTizenInstance(
        mvObjectDetectionSymbols, Tizen100MvObjectDetection.fromLookup)!;

Tizen100MvRoiTracker? _tizenMvRoiTracker;
Tizen100MvRoiTracker get tizenMvRoiTracker => _tizenMvRoiTracker ??=
    _getTizenInstance(mvRoiTrackerSymbols, Tizen100MvRoiTracker.fromLookup)!;

Tizen100MvSurveillance? _tizenMvSurveillance;
Tizen100MvSurveillance get tizenMvSurveillance =>
    _tizenMvSurveillance ??= _getTizenInstance(
        mvSurveillanceSymbols, Tizen100MvSurveillance.fromLookup)!;

Tizen100Notification? _tizenNotification;
Tizen100Notification get tizenNotification => _tizenNotification ??=
    _getTizenInstance(notificationSymbols, Tizen100Notification.fromLookup)!;

Tizen100NotificationEx? _tizenNotificationEx;
Tizen100NotificationEx get tizenNotificationEx =>
    _tizenNotificationEx ??= _getTizenInstance(
        notificationExSymbols, Tizen100NotificationEx.fromLookup)!;

Tizen100NsdDnsSd? _tizenNsdDnsSd;
Tizen100NsdDnsSd get tizenNsdDnsSd => _tizenNsdDnsSd ??=
    _getTizenInstance(nsdDnsSdSymbols, Tizen100NsdDnsSd.fromLookup)!;

Tizen100NsdSsdp? _tizenNsdSsdp;
Tizen100NsdSsdp get tizenNsdSsdp => _tizenNsdSsdp ??=
    _getTizenInstance(nsdSsdpSymbols, Tizen100NsdSsdp.fromLookup)!;

Tizen100Oauth2? _tizenOauth2;
Tizen100Oauth2 get tizenOauth2 => _tizenOauth2 ??=
    _getTizenInstance(oauth2Symbols, Tizen100Oauth2.fromLookup)!;

Tizen100Openal? _tizenOpenal;
Tizen100Openal get tizenOpenal => _tizenOpenal ??=
    _getTizenInstance(openalSymbols, Tizen100Openal.fromLookup)!;

Tizen100PhonenumberUtils? _tizenPhonenumberUtils;
Tizen100PhonenumberUtils get tizenPhonenumberUtils =>
    _tizenPhonenumberUtils ??= _getTizenInstance(
        phonenumberUtilsSymbols, Tizen100PhonenumberUtils.fromLookup)!;

Tizen100PrivilegeInfo? _tizenPrivilegeInfo;
Tizen100PrivilegeInfo get tizenPrivilegeInfo => _tizenPrivilegeInfo ??=
    _getTizenInstance(privilegeInfoSymbols, Tizen100PrivilegeInfo.fromLookup)!;

Tizen100Push? _tizenPush;
Tizen100Push get tizenPush =>
    _tizenPush ??= _getTizenInstance(pushSymbols, Tizen100Push.fromLookup)!;

Tizen100RpcPort? _tizenRpcPort;
Tizen100RpcPort get tizenRpcPort => _tizenRpcPort ??=
    _getTizenInstance(rpcPortSymbols, Tizen100RpcPort.fromLookup)!;

Tizen100Shortcut? _tizenShortcut;
Tizen100Shortcut get tizenShortcut => _tizenShortcut ??=
    _getTizenInstance(shortcutSymbols, Tizen100Shortcut.fromLookup)!;

Tizen100Storage? _tizenStorage;
Tizen100Storage get tizenStorage => _tizenStorage ??=
    _getTizenInstance(storageSymbols, Tizen100Storage.fromLookup)!;

Tizen100Stt? _tizenStt;
Tizen100Stt get tizenStt =>
    _tizenStt ??= _getTizenInstance(sttSymbols, Tizen100Stt.fromLookup)!;

Tizen100SttEngine? _tizenSttEngine;
Tizen100SttEngine get tizenSttEngine => _tizenSttEngine ??=
    _getTizenInstance(sttEngineSymbols, Tizen100SttEngine.fromLookup)!;

Tizen100Tbm? _tizenTbm;
Tizen100Tbm get tizenTbm =>
    _tizenTbm ??= _getTizenInstance(tbmSymbols, Tizen100Tbm.fromLookup)!;

Tizen100TizenCore? _tizenTizenCore;
Tizen100TizenCore get tizenTizenCore => _tizenTizenCore ??=
    _getTizenInstance(tizenCoreSymbols, Tizen100TizenCore.fromLookup)!;

Tizen100Ttrace? _tizenTtrace;
Tizen100Ttrace get tizenTtrace => _tizenTtrace ??=
    _getTizenInstance(ttraceSymbols, Tizen100Ttrace.fromLookup)!;

Tizen100Tts? _tizenTts;
Tizen100Tts get tizenTts =>
    _tizenTts ??= _getTizenInstance(ttsSymbols, Tizen100Tts.fromLookup)!;

Tizen100TtsEngine? _tizenTtsEngine;
Tizen100TtsEngine get tizenTtsEngine => _tizenTtsEngine ??=
    _getTizenInstance(ttsEngineSymbols, Tizen100TtsEngine.fromLookup)!;

Tizen100UpdateControl? _tizenUpdateControl;
Tizen100UpdateControl get tizenUpdateControl => _tizenUpdateControl ??=
    _getTizenInstance(updateControlSymbols, Tizen100UpdateControl.fromLookup)!;

Tizen100Vc? _tizenVc;
Tizen100Vc get tizenVc =>
    _tizenVc ??= _getTizenInstance(vcSymbols, Tizen100Vc.fromLookup)!;

Tizen100VcEngine? _tizenVcEngine;
Tizen100VcEngine get tizenVcEngine => _tizenVcEngine ??=
    _getTizenInstance(vcEngineSymbols, Tizen100VcEngine.fromLookup)!;

Tizen100VcManager? _tizenVcManager;
Tizen100VcManager get tizenVcManager => _tizenVcManager ??=
    _getTizenInstance(vcManagerSymbols, Tizen100VcManager.fromLookup)!;

Tizen100WebauthnClient? _tizenWebauthnClient;
Tizen100WebauthnClient get tizenWebauthnClient =>
    _tizenWebauthnClient ??= _getTizenInstance(
        webauthnClientSymbols, Tizen100WebauthnClient.fromLookup)!;

Tizen100WifiDirect? _tizenWifiDirect;
Tizen100WifiDirect get tizenWifiDirect => _tizenWifiDirect ??=
    _getTizenInstance(wifiDirectSymbols, Tizen100WifiDirect.fromLookup)!;

Tizen100Yaca? _tizenYaca;
Tizen100Yaca get tizenYaca =>
    _tizenYaca ??= _getTizenInstance(yacaSymbols, Tizen100Yaca.fromLookup)!;
