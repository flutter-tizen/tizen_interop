library tizen_interop;

import 'dart:ffi';

import '../../src/bindings/9.0/generated_symbols.dart';
import '../../src/bindings/9.0/generated_bindings_accounts_svc.dart';
import '../../src/bindings/9.0/generated_bindings_appcore_agent.dart';
import '../../src/bindings/9.0/generated_bindings_asp.dart';
import '../../src/bindings/9.0/generated_bindings_badge.dart';
import '../../src/bindings/9.0/generated_bindings_bundle.dart';
import '../../src/bindings/9.0/generated_bindings_calendar_service2.dart';
import '../../src/bindings/9.0/generated_bindings_capi_appfw_alarm.dart';
import '../../src/bindings/9.0/generated_bindings_capi_appfw_app_common.dart';
import '../../src/bindings/9.0/generated_bindings_capi_appfw_app_control.dart';
import '../../src/bindings/9.0/generated_bindings_capi_appfw_app_control_uri.dart';
import '../../src/bindings/9.0/generated_bindings_capi_appfw_app_manager.dart';
import '../../src/bindings/9.0/generated_bindings_capi_appfw_application.dart';
import '../../src/bindings/9.0/generated_bindings_capi_appfw_event.dart';
import '../../src/bindings/9.0/generated_bindings_capi_appfw_job_scheduler.dart';
import '../../src/bindings/9.0/generated_bindings_capi_appfw_package_manager.dart';
import '../../src/bindings/9.0/generated_bindings_capi_appfw_preference.dart';
import '../../src/bindings/9.0/generated_bindings_capi_base_common.dart';
import '../../src/bindings/9.0/generated_bindings_capi_content_media_content.dart';
import '../../src/bindings/9.0/generated_bindings_capi_content_mime_type.dart';
import '../../src/bindings/9.0/generated_bindings_capi_context.dart';
import '../../src/bindings/9.0/generated_bindings_capi_geofence_manager.dart';
import '../../src/bindings/9.0/generated_bindings_capi_location_manager.dart';
import '../../src/bindings/9.0/generated_bindings_capi_media_audio_io.dart';
import '../../src/bindings/9.0/generated_bindings_capi_media_camera.dart';
import '../../src/bindings/9.0/generated_bindings_capi_media_codec.dart';
import '../../src/bindings/9.0/generated_bindings_capi_media_controller.dart';
import '../../src/bindings/9.0/generated_bindings_capi_media_editor.dart';
import '../../src/bindings/9.0/generated_bindings_capi_media_image_util.dart';
import '../../src/bindings/9.0/generated_bindings_capi_media_metadata_editor.dart';
import '../../src/bindings/9.0/generated_bindings_capi_media_metadata_extractor.dart';
import '../../src/bindings/9.0/generated_bindings_capi_media_player.dart';
import '../../src/bindings/9.0/generated_bindings_capi_media_radio.dart';
import '../../src/bindings/9.0/generated_bindings_capi_media_recorder.dart';
import '../../src/bindings/9.0/generated_bindings_capi_media_screen_mirroring.dart';
import '../../src/bindings/9.0/generated_bindings_capi_media_sound_manager.dart';
import '../../src/bindings/9.0/generated_bindings_capi_media_sound_pool.dart';
import '../../src/bindings/9.0/generated_bindings_capi_media_thumbnail_util.dart';
import '../../src/bindings/9.0/generated_bindings_capi_media_tone_player.dart';
import '../../src/bindings/9.0/generated_bindings_capi_media_tool.dart';
import '../../src/bindings/9.0/generated_bindings_capi_media_wav_player.dart';
import '../../src/bindings/9.0/generated_bindings_capi_media_webrtc.dart';
import '../../src/bindings/9.0/generated_bindings_capi_mediademuxer.dart';
import '../../src/bindings/9.0/generated_bindings_capi_mediamuxer.dart';
import '../../src/bindings/9.0/generated_bindings_capi_messaging_email.dart';
import '../../src/bindings/9.0/generated_bindings_capi_ml_common.dart';
import '../../src/bindings/9.0/generated_bindings_capi_ml_inference_single.dart';
import '../../src/bindings/9.0/generated_bindings_capi_ml_service.dart';
import '../../src/bindings/9.0/generated_bindings_capi_network_bluetooth.dart';
import '../../src/bindings/9.0/generated_bindings_capi_network_connection.dart';
import '../../src/bindings/9.0/generated_bindings_capi_network_http.dart';
import '../../src/bindings/9.0/generated_bindings_capi_network_inm.dart';
import '../../src/bindings/9.0/generated_bindings_capi_network_mtp.dart';
import '../../src/bindings/9.0/generated_bindings_capi_network_nfc.dart';
import '../../src/bindings/9.0/generated_bindings_capi_network_softap.dart';
import '../../src/bindings/9.0/generated_bindings_capi_network_stc.dart';
import '../../src/bindings/9.0/generated_bindings_capi_network_wifi_aware.dart';
import '../../src/bindings/9.0/generated_bindings_capi_network_wifi_manager.dart';
import '../../src/bindings/9.0/generated_bindings_capi_nnstreamer.dart';
import '../../src/bindings/9.0/generated_bindings_capi_nntrainer.dart';
import '../../src/bindings/9.0/generated_bindings_capi_privacy_privilege_manager.dart';
import '../../src/bindings/9.0/generated_bindings_capi_system_device.dart';
import '../../src/bindings/9.0/generated_bindings_capi_system_info.dart';
import '../../src/bindings/9.0/generated_bindings_capi_system_media_key.dart';
import '../../src/bindings/9.0/generated_bindings_capi_system_peripheral_io.dart';
import '../../src/bindings/9.0/generated_bindings_capi_system_resource_monitor.dart';
import '../../src/bindings/9.0/generated_bindings_capi_system_runtime_info.dart';
import '../../src/bindings/9.0/generated_bindings_capi_system_sensor.dart';
import '../../src/bindings/9.0/generated_bindings_capi_system_system_settings.dart';
import '../../src/bindings/9.0/generated_bindings_capi_system_usbhost.dart';
import '../../src/bindings/9.0/generated_bindings_capi_ui_autofill.dart';
import '../../src/bindings/9.0/generated_bindings_capi_ui_autofill_common.dart';
import '../../src/bindings/9.0/generated_bindings_capi_ui_autofill_manager.dart';
import '../../src/bindings/9.0/generated_bindings_capi_ui_autofill_service.dart';
import '../../src/bindings/9.0/generated_bindings_capi_ui_inputmethod.dart';
import '../../src/bindings/9.0/generated_bindings_capi_ui_inputmethod_manager.dart';
import '../../src/bindings/9.0/generated_bindings_capi_vpnsvc.dart';
import '../../src/bindings/9.0/generated_bindings_capi_web_url_download.dart';
import '../../src/bindings/9.0/generated_bindings_cion.dart';
import '../../src/bindings/9.0/generated_bindings_contacts_service2.dart';
import '../../src/bindings/9.0/generated_bindings_core_sync_client.dart';
import '../../src/bindings/9.0/generated_bindings_csr_client.dart';
import '../../src/bindings/9.0/generated_bindings_data_control.dart';
import '../../src/bindings/9.0/generated_bindings_device_certificate_manager.dart';
import '../../src/bindings/9.0/generated_bindings_diagnostics.dart';
import '../../src/bindings/9.0/generated_bindings_dlog.dart';
import '../../src/bindings/9.0/generated_bindings_dpm.dart';
import '../../src/bindings/9.0/generated_bindings_eom.dart';
import '../../src/bindings/9.0/generated_bindings_feedback.dart';
import '../../src/bindings/9.0/generated_bindings_fido_client.dart';
import '../../src/bindings/9.0/generated_bindings_iotcon.dart';
import '../../src/bindings/9.0/generated_bindings_key_manager_client.dart';
import '../../src/bindings/9.0/generated_bindings_ma.dart';
import '../../src/bindings/9.0/generated_bindings_message_port.dart';
import '../../src/bindings/9.0/generated_bindings_mmi.dart';
import '../../src/bindings/9.0/generated_bindings_mv_3d.dart';
import '../../src/bindings/9.0/generated_bindings_mv_barcode_detector.dart';
import '../../src/bindings/9.0/generated_bindings_mv_barcode_generator.dart';
import '../../src/bindings/9.0/generated_bindings_mv_common.dart';
import '../../src/bindings/9.0/generated_bindings_mv_face.dart';
import '../../src/bindings/9.0/generated_bindings_mv_face_recognition.dart';
import '../../src/bindings/9.0/generated_bindings_mv_image.dart';
import '../../src/bindings/9.0/generated_bindings_mv_image_classification.dart';
import '../../src/bindings/9.0/generated_bindings_mv_inference.dart';
import '../../src/bindings/9.0/generated_bindings_mv_landmark_detection.dart';
import '../../src/bindings/9.0/generated_bindings_mv_object_detection.dart';
import '../../src/bindings/9.0/generated_bindings_mv_roi_tracker.dart';
import '../../src/bindings/9.0/generated_bindings_mv_surveillance.dart';
import '../../src/bindings/9.0/generated_bindings_notification.dart';
import '../../src/bindings/9.0/generated_bindings_notification_ex.dart';
import '../../src/bindings/9.0/generated_bindings_nsd_dns_sd.dart';
import '../../src/bindings/9.0/generated_bindings_nsd_ssdp.dart';
import '../../src/bindings/9.0/generated_bindings_oauth2.dart';
import '../../src/bindings/9.0/generated_bindings_phonenumber_utils.dart';
import '../../src/bindings/9.0/generated_bindings_privilege_info.dart';
import '../../src/bindings/9.0/generated_bindings_push.dart';
import '../../src/bindings/9.0/generated_bindings_rpc_port.dart';
import '../../src/bindings/9.0/generated_bindings_storage.dart';
import '../../src/bindings/9.0/generated_bindings_stt.dart';
import '../../src/bindings/9.0/generated_bindings_stt_engine.dart';
import '../../src/bindings/9.0/generated_bindings_tbm.dart';
import '../../src/bindings/9.0/generated_bindings_tizen_core.dart';
import '../../src/bindings/9.0/generated_bindings_ttrace.dart';
import '../../src/bindings/9.0/generated_bindings_tts.dart';
import '../../src/bindings/9.0/generated_bindings_tts_engine.dart';
import '../../src/bindings/9.0/generated_bindings_update_control.dart';
import '../../src/bindings/9.0/generated_bindings_vc.dart';
import '../../src/bindings/9.0/generated_bindings_vc_engine.dart';
import '../../src/bindings/9.0/generated_bindings_vc_manager.dart';
import '../../src/bindings/9.0/generated_bindings_webauthn_client.dart';
import '../../src/bindings/9.0/generated_bindings_wifi_direct.dart';
import '../../src/bindings/9.0/generated_bindings_yaca.dart';
import '../../src/lookup_provider.dart';

export '../../src/extensions.dart';
export '../../src/bindings/9.0/generated_bindings_accounts_svc.dart';
export '../../src/bindings/9.0/generated_bindings_appcore_agent.dart';
export '../../src/bindings/9.0/generated_bindings_asp.dart';
export '../../src/bindings/9.0/generated_bindings_badge.dart';
export '../../src/bindings/9.0/generated_bindings_bundle.dart';
export '../../src/bindings/9.0/generated_bindings_calendar_service2.dart';
export '../../src/bindings/9.0/generated_bindings_capi_appfw_alarm.dart';
export '../../src/bindings/9.0/generated_bindings_capi_appfw_app_common.dart';
export '../../src/bindings/9.0/generated_bindings_capi_appfw_app_control.dart';
export '../../src/bindings/9.0/generated_bindings_capi_appfw_app_control_uri.dart';
export '../../src/bindings/9.0/generated_bindings_capi_appfw_app_manager.dart';
export '../../src/bindings/9.0/generated_bindings_capi_appfw_application.dart';
export '../../src/bindings/9.0/generated_bindings_capi_appfw_event.dart';
export '../../src/bindings/9.0/generated_bindings_capi_appfw_job_scheduler.dart';
export '../../src/bindings/9.0/generated_bindings_capi_appfw_package_manager.dart';
export '../../src/bindings/9.0/generated_bindings_capi_appfw_preference.dart';
export '../../src/bindings/9.0/generated_bindings_capi_base_common.dart';
export '../../src/bindings/9.0/generated_bindings_capi_content_media_content.dart';
export '../../src/bindings/9.0/generated_bindings_capi_content_mime_type.dart';
export '../../src/bindings/9.0/generated_bindings_capi_context.dart';
export '../../src/bindings/9.0/generated_bindings_capi_geofence_manager.dart';
export '../../src/bindings/9.0/generated_bindings_capi_location_manager.dart';
export '../../src/bindings/9.0/generated_bindings_capi_media_audio_io.dart';
export '../../src/bindings/9.0/generated_bindings_capi_media_camera.dart'
    hide UnnamedUnion1, UnnamedStruct1;
export '../../src/bindings/9.0/generated_bindings_capi_media_codec.dart';
export '../../src/bindings/9.0/generated_bindings_capi_media_controller.dart';
export '../../src/bindings/9.0/generated_bindings_capi_media_editor.dart';
export '../../src/bindings/9.0/generated_bindings_capi_media_image_util.dart';
export '../../src/bindings/9.0/generated_bindings_capi_media_metadata_editor.dart';
export '../../src/bindings/9.0/generated_bindings_capi_media_metadata_extractor.dart';
export '../../src/bindings/9.0/generated_bindings_capi_media_player.dart';
export '../../src/bindings/9.0/generated_bindings_capi_media_radio.dart';
export '../../src/bindings/9.0/generated_bindings_capi_media_recorder.dart';
export '../../src/bindings/9.0/generated_bindings_capi_media_screen_mirroring.dart';
export '../../src/bindings/9.0/generated_bindings_capi_media_sound_manager.dart';
export '../../src/bindings/9.0/generated_bindings_capi_media_sound_pool.dart';
export '../../src/bindings/9.0/generated_bindings_capi_media_thumbnail_util.dart';
export '../../src/bindings/9.0/generated_bindings_capi_media_tone_player.dart';
export '../../src/bindings/9.0/generated_bindings_capi_media_tool.dart';
export '../../src/bindings/9.0/generated_bindings_capi_media_wav_player.dart';
export '../../src/bindings/9.0/generated_bindings_capi_media_webrtc.dart'
    hide UnnamedUnion1;
export '../../src/bindings/9.0/generated_bindings_capi_mediademuxer.dart';
export '../../src/bindings/9.0/generated_bindings_capi_mediamuxer.dart';
export '../../src/bindings/9.0/generated_bindings_capi_messaging_email.dart';
export '../../src/bindings/9.0/generated_bindings_capi_ml_common.dart';
export '../../src/bindings/9.0/generated_bindings_capi_ml_inference_single.dart';
export '../../src/bindings/9.0/generated_bindings_capi_ml_service.dart';
export '../../src/bindings/9.0/generated_bindings_capi_network_bluetooth.dart';
export '../../src/bindings/9.0/generated_bindings_capi_network_connection.dart';
export '../../src/bindings/9.0/generated_bindings_capi_network_http.dart';
export '../../src/bindings/9.0/generated_bindings_capi_network_inm.dart';
export '../../src/bindings/9.0/generated_bindings_capi_network_mtp.dart';
export '../../src/bindings/9.0/generated_bindings_capi_network_nfc.dart';
export '../../src/bindings/9.0/generated_bindings_capi_network_softap.dart';
export '../../src/bindings/9.0/generated_bindings_capi_network_stc.dart';
export '../../src/bindings/9.0/generated_bindings_capi_network_wifi_aware.dart';
export '../../src/bindings/9.0/generated_bindings_capi_network_wifi_manager.dart';
export '../../src/bindings/9.0/generated_bindings_capi_nnstreamer.dart';
export '../../src/bindings/9.0/generated_bindings_capi_nntrainer.dart';
export '../../src/bindings/9.0/generated_bindings_capi_privacy_privilege_manager.dart';
export '../../src/bindings/9.0/generated_bindings_capi_system_device.dart';
export '../../src/bindings/9.0/generated_bindings_capi_system_info.dart';
export '../../src/bindings/9.0/generated_bindings_capi_system_media_key.dart';
export '../../src/bindings/9.0/generated_bindings_capi_system_peripheral_io.dart';
export '../../src/bindings/9.0/generated_bindings_capi_system_resource_monitor.dart';
export '../../src/bindings/9.0/generated_bindings_capi_system_runtime_info.dart';
export '../../src/bindings/9.0/generated_bindings_capi_system_sensor.dart';
export '../../src/bindings/9.0/generated_bindings_capi_system_system_settings.dart';
export '../../src/bindings/9.0/generated_bindings_capi_system_usbhost.dart';
export '../../src/bindings/9.0/generated_bindings_capi_ui_autofill.dart';
export '../../src/bindings/9.0/generated_bindings_capi_ui_autofill_common.dart';
export '../../src/bindings/9.0/generated_bindings_capi_ui_autofill_manager.dart';
export '../../src/bindings/9.0/generated_bindings_capi_ui_autofill_service.dart';
export '../../src/bindings/9.0/generated_bindings_capi_ui_inputmethod.dart';
export '../../src/bindings/9.0/generated_bindings_capi_ui_inputmethod_manager.dart';
export '../../src/bindings/9.0/generated_bindings_capi_vpnsvc.dart';
export '../../src/bindings/9.0/generated_bindings_capi_web_url_download.dart';
export '../../src/bindings/9.0/generated_bindings_cion.dart';
export '../../src/bindings/9.0/generated_bindings_contacts_service2.dart';
export '../../src/bindings/9.0/generated_bindings_core_sync_client.dart';
export '../../src/bindings/9.0/generated_bindings_csr_client.dart';
export '../../src/bindings/9.0/generated_bindings_data_control.dart';
export '../../src/bindings/9.0/generated_bindings_device_certificate_manager.dart';
export '../../src/bindings/9.0/generated_bindings_diagnostics.dart';
export '../../src/bindings/9.0/generated_bindings_dlog.dart';
export '../../src/bindings/9.0/generated_bindings_dpm.dart';
export '../../src/bindings/9.0/generated_bindings_eom.dart';
export '../../src/bindings/9.0/generated_bindings_feedback.dart';
export '../../src/bindings/9.0/generated_bindings_fido_client.dart';
export '../../src/bindings/9.0/generated_bindings_iotcon.dart';
export '../../src/bindings/9.0/generated_bindings_key_manager_client.dart';
export '../../src/bindings/9.0/generated_bindings_ma.dart';
export '../../src/bindings/9.0/generated_bindings_message_port.dart';
export '../../src/bindings/9.0/generated_bindings_mmi.dart';
export '../../src/bindings/9.0/generated_bindings_mv_3d.dart';
export '../../src/bindings/9.0/generated_bindings_mv_barcode_detector.dart';
export '../../src/bindings/9.0/generated_bindings_mv_barcode_generator.dart';
export '../../src/bindings/9.0/generated_bindings_mv_common.dart';
export '../../src/bindings/9.0/generated_bindings_mv_face.dart';
export '../../src/bindings/9.0/generated_bindings_mv_face_recognition.dart';
export '../../src/bindings/9.0/generated_bindings_mv_image.dart';
export '../../src/bindings/9.0/generated_bindings_mv_image_classification.dart';
export '../../src/bindings/9.0/generated_bindings_mv_inference.dart';
export '../../src/bindings/9.0/generated_bindings_mv_landmark_detection.dart';
export '../../src/bindings/9.0/generated_bindings_mv_object_detection.dart';
export '../../src/bindings/9.0/generated_bindings_mv_roi_tracker.dart';
export '../../src/bindings/9.0/generated_bindings_mv_surveillance.dart';
export '../../src/bindings/9.0/generated_bindings_notification.dart';
export '../../src/bindings/9.0/generated_bindings_notification_ex.dart';
export '../../src/bindings/9.0/generated_bindings_nsd_dns_sd.dart';
export '../../src/bindings/9.0/generated_bindings_nsd_ssdp.dart';
export '../../src/bindings/9.0/generated_bindings_oauth2.dart';
export '../../src/bindings/9.0/generated_bindings_phonenumber_utils.dart';
export '../../src/bindings/9.0/generated_bindings_privilege_info.dart';
export '../../src/bindings/9.0/generated_bindings_push.dart';
export '../../src/bindings/9.0/generated_bindings_rpc_port.dart';
export '../../src/bindings/9.0/generated_bindings_storage.dart';
export '../../src/bindings/9.0/generated_bindings_stt.dart';
export '../../src/bindings/9.0/generated_bindings_stt_engine.dart';
export '../../src/bindings/9.0/generated_bindings_tbm.dart';
export '../../src/bindings/9.0/generated_bindings_tizen_core.dart';
export '../../src/bindings/9.0/generated_bindings_ttrace.dart';
export '../../src/bindings/9.0/generated_bindings_tts.dart';
export '../../src/bindings/9.0/generated_bindings_tts_engine.dart';
export '../../src/bindings/9.0/generated_bindings_update_control.dart';
export '../../src/bindings/9.0/generated_bindings_vc.dart';
export '../../src/bindings/9.0/generated_bindings_vc_engine.dart';
export '../../src/bindings/9.0/generated_bindings_vc_manager.dart';
export '../../src/bindings/9.0/generated_bindings_webauthn_client.dart';
export '../../src/bindings/9.0/generated_bindings_wifi_direct.dart';
export '../../src/bindings/9.0/generated_bindings_yaca.dart';
export '../../src/bindings/9.0/generated_bindings_time.dart'
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

Tizen90AccountsSvc? _tizenAccountsSvc;
Tizen90AccountsSvc get tizenAccountsSvc => _tizenAccountsSvc ??=
    _getTizenInstance(accountsSvcSymbols, Tizen90AccountsSvc.fromLookup)!;

Tizen90AppcoreAgent? _tizenAppcoreAgent;
Tizen90AppcoreAgent get tizenAppcoreAgent => _tizenAppcoreAgent ??=
    _getTizenInstance(appcoreAgentSymbols, Tizen90AppcoreAgent.fromLookup)!;

Tizen90Asp? _tizenAsp;
Tizen90Asp get tizenAsp =>
    _tizenAsp ??= _getTizenInstance(aspSymbols, Tizen90Asp.fromLookup)!;

Tizen90Badge? _tizenBadge;
Tizen90Badge get tizenBadge =>
    _tizenBadge ??= _getTizenInstance(badgeSymbols, Tizen90Badge.fromLookup)!;

Tizen90Bundle? _tizenBundle;
Tizen90Bundle get tizenBundle => _tizenBundle ??=
    _getTizenInstance(bundleSymbols, Tizen90Bundle.fromLookup)!;

Tizen90CalendarService2? _tizenCalendarService2;
Tizen90CalendarService2 get tizenCalendarService2 =>
    _tizenCalendarService2 ??= _getTizenInstance(
        calendarService2Symbols, Tizen90CalendarService2.fromLookup)!;

Tizen90CapiAppfwAlarm? _tizenCapiAppfwAlarm;
Tizen90CapiAppfwAlarm get tizenCapiAppfwAlarm => _tizenCapiAppfwAlarm ??=
    _getTizenInstance(capiAppfwAlarmSymbols, Tizen90CapiAppfwAlarm.fromLookup)!;

Tizen90CapiAppfwAppCommon? _tizenCapiAppfwAppCommon;
Tizen90CapiAppfwAppCommon get tizenCapiAppfwAppCommon =>
    _tizenCapiAppfwAppCommon ??= _getTizenInstance(
        capiAppfwAppCommonSymbols, Tizen90CapiAppfwAppCommon.fromLookup)!;

Tizen90CapiAppfwAppControl? _tizenCapiAppfwAppControl;
Tizen90CapiAppfwAppControl get tizenCapiAppfwAppControl =>
    _tizenCapiAppfwAppControl ??= _getTizenInstance(
        capiAppfwAppControlSymbols, Tizen90CapiAppfwAppControl.fromLookup)!;

Tizen90CapiAppfwAppControlUri? _tizenCapiAppfwAppControlUri;
Tizen90CapiAppfwAppControlUri get tizenCapiAppfwAppControlUri =>
    _tizenCapiAppfwAppControlUri ??= _getTizenInstance(
        capiAppfwAppControlUriSymbols,
        Tizen90CapiAppfwAppControlUri.fromLookup)!;

Tizen90CapiAppfwAppManager? _tizenCapiAppfwAppManager;
Tizen90CapiAppfwAppManager get tizenCapiAppfwAppManager =>
    _tizenCapiAppfwAppManager ??= _getTizenInstance(
        capiAppfwAppManagerSymbols, Tizen90CapiAppfwAppManager.fromLookup)!;

Tizen90CapiAppfwApplication? _tizenCapiAppfwApplication;
Tizen90CapiAppfwApplication get tizenCapiAppfwApplication =>
    _tizenCapiAppfwApplication ??= _getTizenInstance(
        capiAppfwApplicationSymbols, Tizen90CapiAppfwApplication.fromLookup)!;

Tizen90CapiAppfwEvent? _tizenCapiAppfwEvent;
Tizen90CapiAppfwEvent get tizenCapiAppfwEvent => _tizenCapiAppfwEvent ??=
    _getTizenInstance(capiAppfwEventSymbols, Tizen90CapiAppfwEvent.fromLookup)!;

Tizen90CapiAppfwJobScheduler? _tizenCapiAppfwJobScheduler;
Tizen90CapiAppfwJobScheduler get tizenCapiAppfwJobScheduler =>
    _tizenCapiAppfwJobScheduler ??= _getTizenInstance(
        capiAppfwJobSchedulerSymbols, Tizen90CapiAppfwJobScheduler.fromLookup)!;

Tizen90CapiAppfwPackageManager? _tizenCapiAppfwPackageManager;
Tizen90CapiAppfwPackageManager get tizenCapiAppfwPackageManager =>
    _tizenCapiAppfwPackageManager ??= _getTizenInstance(
        capiAppfwPackageManagerSymbols,
        Tizen90CapiAppfwPackageManager.fromLookup)!;

Tizen90CapiAppfwPreference? _tizenCapiAppfwPreference;
Tizen90CapiAppfwPreference get tizenCapiAppfwPreference =>
    _tizenCapiAppfwPreference ??= _getTizenInstance(
        capiAppfwPreferenceSymbols, Tizen90CapiAppfwPreference.fromLookup)!;

Tizen90CapiBaseCommon? _tizenCapiBaseCommon;
Tizen90CapiBaseCommon get tizenCapiBaseCommon => _tizenCapiBaseCommon ??=
    _getTizenInstance(capiBaseCommonSymbols, Tizen90CapiBaseCommon.fromLookup)!;

Tizen90CapiContentMediaContent? _tizenCapiContentMediaContent;
Tizen90CapiContentMediaContent get tizenCapiContentMediaContent =>
    _tizenCapiContentMediaContent ??= _getTizenInstance(
        capiContentMediaContentSymbols,
        Tizen90CapiContentMediaContent.fromLookup)!;

Tizen90CapiContentMimeType? _tizenCapiContentMimeType;
Tizen90CapiContentMimeType get tizenCapiContentMimeType =>
    _tizenCapiContentMimeType ??= _getTizenInstance(
        capiContentMimeTypeSymbols, Tizen90CapiContentMimeType.fromLookup)!;

Tizen90CapiContext? _tizenCapiContext;
Tizen90CapiContext get tizenCapiContext => _tizenCapiContext ??=
    _getTizenInstance(capiContextSymbols, Tizen90CapiContext.fromLookup)!;

Tizen90CapiGeofenceManager? _tizenCapiGeofenceManager;
Tizen90CapiGeofenceManager get tizenCapiGeofenceManager =>
    _tizenCapiGeofenceManager ??= _getTizenInstance(
        capiGeofenceManagerSymbols, Tizen90CapiGeofenceManager.fromLookup)!;

Tizen90CapiLocationManager? _tizenCapiLocationManager;
Tizen90CapiLocationManager get tizenCapiLocationManager =>
    _tizenCapiLocationManager ??= _getTizenInstance(
        capiLocationManagerSymbols, Tizen90CapiLocationManager.fromLookup)!;

Tizen90CapiMediaAudioIo? _tizenCapiMediaAudioIo;
Tizen90CapiMediaAudioIo get tizenCapiMediaAudioIo =>
    _tizenCapiMediaAudioIo ??= _getTizenInstance(
        capiMediaAudioIoSymbols, Tizen90CapiMediaAudioIo.fromLookup)!;

Tizen90CapiMediaCamera? _tizenCapiMediaCamera;
Tizen90CapiMediaCamera get tizenCapiMediaCamera =>
    _tizenCapiMediaCamera ??= _getTizenInstance(
        capiMediaCameraSymbols, Tizen90CapiMediaCamera.fromLookup)!;

Tizen90CapiMediaCodec? _tizenCapiMediaCodec;
Tizen90CapiMediaCodec get tizenCapiMediaCodec => _tizenCapiMediaCodec ??=
    _getTizenInstance(capiMediaCodecSymbols, Tizen90CapiMediaCodec.fromLookup)!;

Tizen90CapiMediaController? _tizenCapiMediaController;
Tizen90CapiMediaController get tizenCapiMediaController =>
    _tizenCapiMediaController ??= _getTizenInstance(
        capiMediaControllerSymbols, Tizen90CapiMediaController.fromLookup)!;

Tizen90CapiMediaEditor? _tizenCapiMediaEditor;
Tizen90CapiMediaEditor get tizenCapiMediaEditor =>
    _tizenCapiMediaEditor ??= _getTizenInstance(
        capiMediaEditorSymbols, Tizen90CapiMediaEditor.fromLookup)!;

Tizen90CapiMediaImageUtil? _tizenCapiMediaImageUtil;
Tizen90CapiMediaImageUtil get tizenCapiMediaImageUtil =>
    _tizenCapiMediaImageUtil ??= _getTizenInstance(
        capiMediaImageUtilSymbols, Tizen90CapiMediaImageUtil.fromLookup)!;

Tizen90CapiMediaMetadataEditor? _tizenCapiMediaMetadataEditor;
Tizen90CapiMediaMetadataEditor get tizenCapiMediaMetadataEditor =>
    _tizenCapiMediaMetadataEditor ??= _getTizenInstance(
        capiMediaMetadataEditorSymbols,
        Tizen90CapiMediaMetadataEditor.fromLookup)!;

Tizen90CapiMediaMetadataExtractor? _tizenCapiMediaMetadataExtractor;
Tizen90CapiMediaMetadataExtractor get tizenCapiMediaMetadataExtractor =>
    _tizenCapiMediaMetadataExtractor ??= _getTizenInstance(
        capiMediaMetadataExtractorSymbols,
        Tizen90CapiMediaMetadataExtractor.fromLookup)!;

Tizen90CapiMediaPlayer? _tizenCapiMediaPlayer;
Tizen90CapiMediaPlayer get tizenCapiMediaPlayer =>
    _tizenCapiMediaPlayer ??= _getTizenInstance(
        capiMediaPlayerSymbols, Tizen90CapiMediaPlayer.fromLookup)!;

Tizen90CapiMediaRadio? _tizenCapiMediaRadio;
Tizen90CapiMediaRadio get tizenCapiMediaRadio => _tizenCapiMediaRadio ??=
    _getTizenInstance(capiMediaRadioSymbols, Tizen90CapiMediaRadio.fromLookup)!;

Tizen90CapiMediaRecorder? _tizenCapiMediaRecorder;
Tizen90CapiMediaRecorder get tizenCapiMediaRecorder =>
    _tizenCapiMediaRecorder ??= _getTizenInstance(
        capiMediaRecorderSymbols, Tizen90CapiMediaRecorder.fromLookup)!;

Tizen90CapiMediaScreenMirroring? _tizenCapiMediaScreenMirroring;
Tizen90CapiMediaScreenMirroring get tizenCapiMediaScreenMirroring =>
    _tizenCapiMediaScreenMirroring ??= _getTizenInstance(
        capiMediaScreenMirroringSymbols,
        Tizen90CapiMediaScreenMirroring.fromLookup)!;

Tizen90CapiMediaSoundManager? _tizenCapiMediaSoundManager;
Tizen90CapiMediaSoundManager get tizenCapiMediaSoundManager =>
    _tizenCapiMediaSoundManager ??= _getTizenInstance(
        capiMediaSoundManagerSymbols, Tizen90CapiMediaSoundManager.fromLookup)!;

Tizen90CapiMediaSoundPool? _tizenCapiMediaSoundPool;
Tizen90CapiMediaSoundPool get tizenCapiMediaSoundPool =>
    _tizenCapiMediaSoundPool ??= _getTizenInstance(
        capiMediaSoundPoolSymbols, Tizen90CapiMediaSoundPool.fromLookup)!;

Tizen90CapiMediaThumbnailUtil? _tizenCapiMediaThumbnailUtil;
Tizen90CapiMediaThumbnailUtil get tizenCapiMediaThumbnailUtil =>
    _tizenCapiMediaThumbnailUtil ??= _getTizenInstance(
        capiMediaThumbnailUtilSymbols,
        Tizen90CapiMediaThumbnailUtil.fromLookup)!;

Tizen90CapiMediaTonePlayer? _tizenCapiMediaTonePlayer;
Tizen90CapiMediaTonePlayer get tizenCapiMediaTonePlayer =>
    _tizenCapiMediaTonePlayer ??= _getTizenInstance(
        capiMediaTonePlayerSymbols, Tizen90CapiMediaTonePlayer.fromLookup)!;

Tizen90CapiMediaTool? _tizenCapiMediaTool;
Tizen90CapiMediaTool get tizenCapiMediaTool => _tizenCapiMediaTool ??=
    _getTizenInstance(capiMediaToolSymbols, Tizen90CapiMediaTool.fromLookup)!;

Tizen90CapiMediaWavPlayer? _tizenCapiMediaWavPlayer;
Tizen90CapiMediaWavPlayer get tizenCapiMediaWavPlayer =>
    _tizenCapiMediaWavPlayer ??= _getTizenInstance(
        capiMediaWavPlayerSymbols, Tizen90CapiMediaWavPlayer.fromLookup)!;

Tizen90CapiMediaWebrtc? _tizenCapiMediaWebrtc;
Tizen90CapiMediaWebrtc get tizenCapiMediaWebrtc =>
    _tizenCapiMediaWebrtc ??= _getTizenInstance(
        capiMediaWebrtcSymbols, Tizen90CapiMediaWebrtc.fromLookup)!;

Tizen90CapiMediademuxer? _tizenCapiMediademuxer;
Tizen90CapiMediademuxer get tizenCapiMediademuxer =>
    _tizenCapiMediademuxer ??= _getTizenInstance(
        capiMediademuxerSymbols, Tizen90CapiMediademuxer.fromLookup)!;

Tizen90CapiMediamuxer? _tizenCapiMediamuxer;
Tizen90CapiMediamuxer get tizenCapiMediamuxer => _tizenCapiMediamuxer ??=
    _getTizenInstance(capiMediamuxerSymbols, Tizen90CapiMediamuxer.fromLookup)!;

Tizen90CapiMessagingEmail? _tizenCapiMessagingEmail;
Tizen90CapiMessagingEmail get tizenCapiMessagingEmail =>
    _tizenCapiMessagingEmail ??= _getTizenInstance(
        capiMessagingEmailSymbols, Tizen90CapiMessagingEmail.fromLookup)!;

Tizen90CapiMlCommon? _tizenCapiMlCommon;
Tizen90CapiMlCommon get tizenCapiMlCommon => _tizenCapiMlCommon ??=
    _getTizenInstance(capiMlCommonSymbols, Tizen90CapiMlCommon.fromLookup)!;

Tizen90CapiMlInferenceSingle? _tizenCapiMlInferenceSingle;
Tizen90CapiMlInferenceSingle get tizenCapiMlInferenceSingle =>
    _tizenCapiMlInferenceSingle ??= _getTizenInstance(
        capiMlInferenceSingleSymbols, Tizen90CapiMlInferenceSingle.fromLookup)!;

Tizen90CapiMlService? _tizenCapiMlService;
Tizen90CapiMlService get tizenCapiMlService => _tizenCapiMlService ??=
    _getTizenInstance(capiMlServiceSymbols, Tizen90CapiMlService.fromLookup)!;

Tizen90CapiNetworkBluetooth? _tizenCapiNetworkBluetooth;
Tizen90CapiNetworkBluetooth get tizenCapiNetworkBluetooth =>
    _tizenCapiNetworkBluetooth ??= _getTizenInstance(
        capiNetworkBluetoothSymbols, Tizen90CapiNetworkBluetooth.fromLookup)!;

Tizen90CapiNetworkConnection? _tizenCapiNetworkConnection;
Tizen90CapiNetworkConnection get tizenCapiNetworkConnection =>
    _tizenCapiNetworkConnection ??= _getTizenInstance(
        capiNetworkConnectionSymbols, Tizen90CapiNetworkConnection.fromLookup)!;

Tizen90CapiNetworkHttp? _tizenCapiNetworkHttp;
Tizen90CapiNetworkHttp get tizenCapiNetworkHttp =>
    _tizenCapiNetworkHttp ??= _getTizenInstance(
        capiNetworkHttpSymbols, Tizen90CapiNetworkHttp.fromLookup)!;

Tizen90CapiNetworkInm? _tizenCapiNetworkInm;
Tizen90CapiNetworkInm get tizenCapiNetworkInm => _tizenCapiNetworkInm ??=
    _getTizenInstance(capiNetworkInmSymbols, Tizen90CapiNetworkInm.fromLookup)!;

Tizen90CapiNetworkMtp? _tizenCapiNetworkMtp;
Tizen90CapiNetworkMtp get tizenCapiNetworkMtp => _tizenCapiNetworkMtp ??=
    _getTizenInstance(capiNetworkMtpSymbols, Tizen90CapiNetworkMtp.fromLookup)!;

Tizen90CapiNetworkNfc? _tizenCapiNetworkNfc;
Tizen90CapiNetworkNfc get tizenCapiNetworkNfc => _tizenCapiNetworkNfc ??=
    _getTizenInstance(capiNetworkNfcSymbols, Tizen90CapiNetworkNfc.fromLookup)!;

Tizen90CapiNetworkSoftap? _tizenCapiNetworkSoftap;
Tizen90CapiNetworkSoftap get tizenCapiNetworkSoftap =>
    _tizenCapiNetworkSoftap ??= _getTizenInstance(
        capiNetworkSoftapSymbols, Tizen90CapiNetworkSoftap.fromLookup)!;

Tizen90CapiNetworkStc? _tizenCapiNetworkStc;
Tizen90CapiNetworkStc get tizenCapiNetworkStc => _tizenCapiNetworkStc ??=
    _getTizenInstance(capiNetworkStcSymbols, Tizen90CapiNetworkStc.fromLookup)!;

Tizen90CapiNetworkWifiAware? _tizenCapiNetworkWifiAware;
Tizen90CapiNetworkWifiAware get tizenCapiNetworkWifiAware =>
    _tizenCapiNetworkWifiAware ??= _getTizenInstance(
        capiNetworkWifiAwareSymbols, Tizen90CapiNetworkWifiAware.fromLookup)!;

Tizen90CapiNetworkWifiManager? _tizenCapiNetworkWifiManager;
Tizen90CapiNetworkWifiManager get tizenCapiNetworkWifiManager =>
    _tizenCapiNetworkWifiManager ??= _getTizenInstance(
        capiNetworkWifiManagerSymbols,
        Tizen90CapiNetworkWifiManager.fromLookup)!;

Tizen90CapiNnstreamer? _tizenCapiNnstreamer;
Tizen90CapiNnstreamer get tizenCapiNnstreamer => _tizenCapiNnstreamer ??=
    _getTizenInstance(capiNnstreamerSymbols, Tizen90CapiNnstreamer.fromLookup)!;

Tizen90CapiNntrainer? _tizenCapiNntrainer;
Tizen90CapiNntrainer get tizenCapiNntrainer => _tizenCapiNntrainer ??=
    _getTizenInstance(capiNntrainerSymbols, Tizen90CapiNntrainer.fromLookup)!;

Tizen90CapiPrivacyPrivilegeManager? _tizenCapiPrivacyPrivilegeManager;
Tizen90CapiPrivacyPrivilegeManager get tizenCapiPrivacyPrivilegeManager =>
    _tizenCapiPrivacyPrivilegeManager ??= _getTizenInstance(
        capiPrivacyPrivilegeManagerSymbols,
        Tizen90CapiPrivacyPrivilegeManager.fromLookup)!;

Tizen90CapiSystemDevice? _tizenCapiSystemDevice;
Tizen90CapiSystemDevice get tizenCapiSystemDevice =>
    _tizenCapiSystemDevice ??= _getTizenInstance(
        capiSystemDeviceSymbols, Tizen90CapiSystemDevice.fromLookup)!;

Tizen90CapiSystemInfo? _tizenCapiSystemInfo;
Tizen90CapiSystemInfo get tizenCapiSystemInfo => _tizenCapiSystemInfo ??=
    _getTizenInstance(capiSystemInfoSymbols, Tizen90CapiSystemInfo.fromLookup)!;

Tizen90CapiSystemMediaKey? _tizenCapiSystemMediaKey;
Tizen90CapiSystemMediaKey get tizenCapiSystemMediaKey =>
    _tizenCapiSystemMediaKey ??= _getTizenInstance(
        capiSystemMediaKeySymbols, Tizen90CapiSystemMediaKey.fromLookup)!;

Tizen90CapiSystemPeripheralIo? _tizenCapiSystemPeripheralIo;
Tizen90CapiSystemPeripheralIo get tizenCapiSystemPeripheralIo =>
    _tizenCapiSystemPeripheralIo ??= _getTizenInstance(
        capiSystemPeripheralIoSymbols,
        Tizen90CapiSystemPeripheralIo.fromLookup)!;

Tizen90CapiSystemResourceMonitor? _tizenCapiSystemResourceMonitor;
Tizen90CapiSystemResourceMonitor get tizenCapiSystemResourceMonitor =>
    _tizenCapiSystemResourceMonitor ??= _getTizenInstance(
        capiSystemResourceMonitorSymbols,
        Tizen90CapiSystemResourceMonitor.fromLookup)!;

Tizen90CapiSystemRuntimeInfo? _tizenCapiSystemRuntimeInfo;
Tizen90CapiSystemRuntimeInfo get tizenCapiSystemRuntimeInfo =>
    _tizenCapiSystemRuntimeInfo ??= _getTizenInstance(
        capiSystemRuntimeInfoSymbols, Tizen90CapiSystemRuntimeInfo.fromLookup)!;

Tizen90CapiSystemSensor? _tizenCapiSystemSensor;
Tizen90CapiSystemSensor get tizenCapiSystemSensor =>
    _tizenCapiSystemSensor ??= _getTizenInstance(
        capiSystemSensorSymbols, Tizen90CapiSystemSensor.fromLookup)!;

Tizen90CapiSystemSystemSettings? _tizenCapiSystemSystemSettings;
Tizen90CapiSystemSystemSettings get tizenCapiSystemSystemSettings =>
    _tizenCapiSystemSystemSettings ??= _getTizenInstance(
        capiSystemSystemSettingsSymbols,
        Tizen90CapiSystemSystemSettings.fromLookup)!;

Tizen90CapiSystemUsbhost? _tizenCapiSystemUsbhost;
Tizen90CapiSystemUsbhost get tizenCapiSystemUsbhost =>
    _tizenCapiSystemUsbhost ??= _getTizenInstance(
        capiSystemUsbhostSymbols, Tizen90CapiSystemUsbhost.fromLookup)!;

Tizen90CapiUiAutofill? _tizenCapiUiAutofill;
Tizen90CapiUiAutofill get tizenCapiUiAutofill => _tizenCapiUiAutofill ??=
    _getTizenInstance(capiUiAutofillSymbols, Tizen90CapiUiAutofill.fromLookup)!;

Tizen90CapiUiAutofillCommon? _tizenCapiUiAutofillCommon;
Tizen90CapiUiAutofillCommon get tizenCapiUiAutofillCommon =>
    _tizenCapiUiAutofillCommon ??= _getTizenInstance(
        capiUiAutofillCommonSymbols, Tizen90CapiUiAutofillCommon.fromLookup)!;

Tizen90CapiUiAutofillManager? _tizenCapiUiAutofillManager;
Tizen90CapiUiAutofillManager get tizenCapiUiAutofillManager =>
    _tizenCapiUiAutofillManager ??= _getTizenInstance(
        capiUiAutofillManagerSymbols, Tizen90CapiUiAutofillManager.fromLookup)!;

Tizen90CapiUiAutofillService? _tizenCapiUiAutofillService;
Tizen90CapiUiAutofillService get tizenCapiUiAutofillService =>
    _tizenCapiUiAutofillService ??= _getTizenInstance(
        capiUiAutofillServiceSymbols, Tizen90CapiUiAutofillService.fromLookup)!;

Tizen90CapiUiInputmethod? _tizenCapiUiInputmethod;
Tizen90CapiUiInputmethod get tizenCapiUiInputmethod =>
    _tizenCapiUiInputmethod ??= _getTizenInstance(
        capiUiInputmethodSymbols, Tizen90CapiUiInputmethod.fromLookup)!;

Tizen90CapiUiInputmethodManager? _tizenCapiUiInputmethodManager;
Tizen90CapiUiInputmethodManager get tizenCapiUiInputmethodManager =>
    _tizenCapiUiInputmethodManager ??= _getTizenInstance(
        capiUiInputmethodManagerSymbols,
        Tizen90CapiUiInputmethodManager.fromLookup)!;

Tizen90CapiVpnsvc? _tizenCapiVpnsvc;
Tizen90CapiVpnsvc get tizenCapiVpnsvc => _tizenCapiVpnsvc ??=
    _getTizenInstance(capiVpnsvcSymbols, Tizen90CapiVpnsvc.fromLookup)!;

Tizen90CapiWebUrlDownload? _tizenCapiWebUrlDownload;
Tizen90CapiWebUrlDownload get tizenCapiWebUrlDownload =>
    _tizenCapiWebUrlDownload ??= _getTizenInstance(
        capiWebUrlDownloadSymbols, Tizen90CapiWebUrlDownload.fromLookup)!;

Tizen90Cion? _tizenCion;
Tizen90Cion get tizenCion =>
    _tizenCion ??= _getTizenInstance(cionSymbols, Tizen90Cion.fromLookup)!;

Tizen90ContactsService2? _tizenContactsService2;
Tizen90ContactsService2 get tizenContactsService2 =>
    _tizenContactsService2 ??= _getTizenInstance(
        contactsService2Symbols, Tizen90ContactsService2.fromLookup)!;

Tizen90CoreSyncClient? _tizenCoreSyncClient;
Tizen90CoreSyncClient get tizenCoreSyncClient => _tizenCoreSyncClient ??=
    _getTizenInstance(coreSyncClientSymbols, Tizen90CoreSyncClient.fromLookup)!;

Tizen90CsrClient? _tizenCsrClient;
Tizen90CsrClient get tizenCsrClient => _tizenCsrClient ??=
    _getTizenInstance(csrClientSymbols, Tizen90CsrClient.fromLookup)!;

Tizen90DataControl? _tizenDataControl;
Tizen90DataControl get tizenDataControl => _tizenDataControl ??=
    _getTizenInstance(dataControlSymbols, Tizen90DataControl.fromLookup)!;

Tizen90DeviceCertificateManager? _tizenDeviceCertificateManager;
Tizen90DeviceCertificateManager get tizenDeviceCertificateManager =>
    _tizenDeviceCertificateManager ??= _getTizenInstance(
        deviceCertificateManagerSymbols,
        Tizen90DeviceCertificateManager.fromLookup)!;

Tizen90Diagnostics? _tizenDiagnostics;
Tizen90Diagnostics get tizenDiagnostics => _tizenDiagnostics ??=
    _getTizenInstance(diagnosticsSymbols, Tizen90Diagnostics.fromLookup)!;

Tizen90Dlog? _tizenDlog;
Tizen90Dlog get tizenDlog =>
    _tizenDlog ??= _getTizenInstance(dlogSymbols, Tizen90Dlog.fromLookup)!;

Tizen90Dpm? _tizenDpm;
Tizen90Dpm get tizenDpm =>
    _tizenDpm ??= _getTizenInstance(dpmSymbols, Tizen90Dpm.fromLookup)!;

Tizen90Eom? _tizenEom;
Tizen90Eom get tizenEom =>
    _tizenEom ??= _getTizenInstance(eomSymbols, Tizen90Eom.fromLookup)!;

Tizen90Feedback? _tizenFeedback;
Tizen90Feedback get tizenFeedback => _tizenFeedback ??=
    _getTizenInstance(feedbackSymbols, Tizen90Feedback.fromLookup)!;

Tizen90FidoClient? _tizenFidoClient;
Tizen90FidoClient get tizenFidoClient => _tizenFidoClient ??=
    _getTizenInstance(fidoClientSymbols, Tizen90FidoClient.fromLookup)!;

Tizen90Iotcon? _tizenIotcon;
Tizen90Iotcon get tizenIotcon => _tizenIotcon ??=
    _getTizenInstance(iotconSymbols, Tizen90Iotcon.fromLookup)!;

Tizen90KeyManagerClient? _tizenKeyManagerClient;
Tizen90KeyManagerClient get tizenKeyManagerClient =>
    _tizenKeyManagerClient ??= _getTizenInstance(
        keyManagerClientSymbols, Tizen90KeyManagerClient.fromLookup)!;

Tizen90Ma? _tizenMa;
Tizen90Ma get tizenMa =>
    _tizenMa ??= _getTizenInstance(maSymbols, Tizen90Ma.fromLookup)!;

Tizen90MessagePort? _tizenMessagePort;
Tizen90MessagePort get tizenMessagePort => _tizenMessagePort ??=
    _getTizenInstance(messagePortSymbols, Tizen90MessagePort.fromLookup)!;

Tizen90Mmi? _tizenMmi;
Tizen90Mmi get tizenMmi =>
    _tizenMmi ??= _getTizenInstance(mmiSymbols, Tizen90Mmi.fromLookup)!;

Tizen90Mv3d? _tizenMv3d;
Tizen90Mv3d get tizenMv3d =>
    _tizenMv3d ??= _getTizenInstance(mv3dSymbols, Tizen90Mv3d.fromLookup)!;

Tizen90MvBarcodeDetector? _tizenMvBarcodeDetector;
Tizen90MvBarcodeDetector get tizenMvBarcodeDetector =>
    _tizenMvBarcodeDetector ??= _getTizenInstance(
        mvBarcodeDetectorSymbols, Tizen90MvBarcodeDetector.fromLookup)!;

Tizen90MvBarcodeGenerator? _tizenMvBarcodeGenerator;
Tizen90MvBarcodeGenerator get tizenMvBarcodeGenerator =>
    _tizenMvBarcodeGenerator ??= _getTizenInstance(
        mvBarcodeGeneratorSymbols, Tizen90MvBarcodeGenerator.fromLookup)!;

Tizen90MvCommon? _tizenMvCommon;
Tizen90MvCommon get tizenMvCommon => _tizenMvCommon ??=
    _getTizenInstance(mvCommonSymbols, Tizen90MvCommon.fromLookup)!;

Tizen90MvFace? _tizenMvFace;
Tizen90MvFace get tizenMvFace => _tizenMvFace ??=
    _getTizenInstance(mvFaceSymbols, Tizen90MvFace.fromLookup)!;

Tizen90MvFaceRecognition? _tizenMvFaceRecognition;
Tizen90MvFaceRecognition get tizenMvFaceRecognition =>
    _tizenMvFaceRecognition ??= _getTizenInstance(
        mvFaceRecognitionSymbols, Tizen90MvFaceRecognition.fromLookup)!;

Tizen90MvImage? _tizenMvImage;
Tizen90MvImage get tizenMvImage => _tizenMvImage ??=
    _getTizenInstance(mvImageSymbols, Tizen90MvImage.fromLookup)!;

Tizen90MvImageClassification? _tizenMvImageClassification;
Tizen90MvImageClassification get tizenMvImageClassification =>
    _tizenMvImageClassification ??= _getTizenInstance(
        mvImageClassificationSymbols, Tizen90MvImageClassification.fromLookup)!;

Tizen90MvInference? _tizenMvInference;
Tizen90MvInference get tizenMvInference => _tizenMvInference ??=
    _getTizenInstance(mvInferenceSymbols, Tizen90MvInference.fromLookup)!;

Tizen90MvLandmarkDetection? _tizenMvLandmarkDetection;
Tizen90MvLandmarkDetection get tizenMvLandmarkDetection =>
    _tizenMvLandmarkDetection ??= _getTizenInstance(
        mvLandmarkDetectionSymbols, Tizen90MvLandmarkDetection.fromLookup)!;

Tizen90MvObjectDetection? _tizenMvObjectDetection;
Tizen90MvObjectDetection get tizenMvObjectDetection =>
    _tizenMvObjectDetection ??= _getTizenInstance(
        mvObjectDetectionSymbols, Tizen90MvObjectDetection.fromLookup)!;

Tizen90MvRoiTracker? _tizenMvRoiTracker;
Tizen90MvRoiTracker get tizenMvRoiTracker => _tizenMvRoiTracker ??=
    _getTizenInstance(mvRoiTrackerSymbols, Tizen90MvRoiTracker.fromLookup)!;

Tizen90MvSurveillance? _tizenMvSurveillance;
Tizen90MvSurveillance get tizenMvSurveillance => _tizenMvSurveillance ??=
    _getTizenInstance(mvSurveillanceSymbols, Tizen90MvSurveillance.fromLookup)!;

Tizen90Notification? _tizenNotification;
Tizen90Notification get tizenNotification => _tizenNotification ??=
    _getTizenInstance(notificationSymbols, Tizen90Notification.fromLookup)!;

Tizen90NotificationEx? _tizenNotificationEx;
Tizen90NotificationEx get tizenNotificationEx => _tizenNotificationEx ??=
    _getTizenInstance(notificationExSymbols, Tizen90NotificationEx.fromLookup)!;

Tizen90NsdDnsSd? _tizenNsdDnsSd;
Tizen90NsdDnsSd get tizenNsdDnsSd => _tizenNsdDnsSd ??=
    _getTizenInstance(nsdDnsSdSymbols, Tizen90NsdDnsSd.fromLookup)!;

Tizen90NsdSsdp? _tizenNsdSsdp;
Tizen90NsdSsdp get tizenNsdSsdp => _tizenNsdSsdp ??=
    _getTizenInstance(nsdSsdpSymbols, Tizen90NsdSsdp.fromLookup)!;

Tizen90Oauth2? _tizenOauth2;
Tizen90Oauth2 get tizenOauth2 => _tizenOauth2 ??=
    _getTizenInstance(oauth2Symbols, Tizen90Oauth2.fromLookup)!;

Tizen90PhonenumberUtils? _tizenPhonenumberUtils;
Tizen90PhonenumberUtils get tizenPhonenumberUtils =>
    _tizenPhonenumberUtils ??= _getTizenInstance(
        phonenumberUtilsSymbols, Tizen90PhonenumberUtils.fromLookup)!;

Tizen90PrivilegeInfo? _tizenPrivilegeInfo;
Tizen90PrivilegeInfo get tizenPrivilegeInfo => _tizenPrivilegeInfo ??=
    _getTizenInstance(privilegeInfoSymbols, Tizen90PrivilegeInfo.fromLookup)!;

Tizen90Push? _tizenPush;
Tizen90Push get tizenPush =>
    _tizenPush ??= _getTizenInstance(pushSymbols, Tizen90Push.fromLookup)!;

Tizen90RpcPort? _tizenRpcPort;
Tizen90RpcPort get tizenRpcPort => _tizenRpcPort ??=
    _getTizenInstance(rpcPortSymbols, Tizen90RpcPort.fromLookup)!;

Tizen90Storage? _tizenStorage;
Tizen90Storage get tizenStorage => _tizenStorage ??=
    _getTizenInstance(storageSymbols, Tizen90Storage.fromLookup)!;

Tizen90Stt? _tizenStt;
Tizen90Stt get tizenStt =>
    _tizenStt ??= _getTizenInstance(sttSymbols, Tizen90Stt.fromLookup)!;

Tizen90SttEngine? _tizenSttEngine;
Tizen90SttEngine get tizenSttEngine => _tizenSttEngine ??=
    _getTizenInstance(sttEngineSymbols, Tizen90SttEngine.fromLookup)!;

Tizen90Tbm? _tizenTbm;
Tizen90Tbm get tizenTbm =>
    _tizenTbm ??= _getTizenInstance(tbmSymbols, Tizen90Tbm.fromLookup)!;

Tizen90TizenCore? _tizenTizenCore;
Tizen90TizenCore get tizenTizenCore => _tizenTizenCore ??=
    _getTizenInstance(tizenCoreSymbols, Tizen90TizenCore.fromLookup)!;

Tizen90Ttrace? _tizenTtrace;
Tizen90Ttrace get tizenTtrace => _tizenTtrace ??=
    _getTizenInstance(ttraceSymbols, Tizen90Ttrace.fromLookup)!;

Tizen90Tts? _tizenTts;
Tizen90Tts get tizenTts =>
    _tizenTts ??= _getTizenInstance(ttsSymbols, Tizen90Tts.fromLookup)!;

Tizen90TtsEngine? _tizenTtsEngine;
Tizen90TtsEngine get tizenTtsEngine => _tizenTtsEngine ??=
    _getTizenInstance(ttsEngineSymbols, Tizen90TtsEngine.fromLookup)!;

Tizen90UpdateControl? _tizenUpdateControl;
Tizen90UpdateControl get tizenUpdateControl => _tizenUpdateControl ??=
    _getTizenInstance(updateControlSymbols, Tizen90UpdateControl.fromLookup)!;

Tizen90Vc? _tizenVc;
Tizen90Vc get tizenVc =>
    _tizenVc ??= _getTizenInstance(vcSymbols, Tizen90Vc.fromLookup)!;

Tizen90VcEngine? _tizenVcEngine;
Tizen90VcEngine get tizenVcEngine => _tizenVcEngine ??=
    _getTizenInstance(vcEngineSymbols, Tizen90VcEngine.fromLookup)!;

Tizen90VcManager? _tizenVcManager;
Tizen90VcManager get tizenVcManager => _tizenVcManager ??=
    _getTizenInstance(vcManagerSymbols, Tizen90VcManager.fromLookup)!;

Tizen90WebauthnClient? _tizenWebauthnClient;
Tizen90WebauthnClient get tizenWebauthnClient => _tizenWebauthnClient ??=
    _getTizenInstance(webauthnClientSymbols, Tizen90WebauthnClient.fromLookup)!;

Tizen90WifiDirect? _tizenWifiDirect;
Tizen90WifiDirect get tizenWifiDirect => _tizenWifiDirect ??=
    _getTizenInstance(wifiDirectSymbols, Tizen90WifiDirect.fromLookup)!;

Tizen90Yaca? _tizenYaca;
Tizen90Yaca get tizenYaca =>
    _tizenYaca ??= _getTizenInstance(yacaSymbols, Tizen90Yaca.fromLookup)!;
