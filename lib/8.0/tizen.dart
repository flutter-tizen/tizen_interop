/// Tizen Interop for Tizen 8.0.
library tizen_interop_8_0;

import 'dart:ffi';

import '../../src/bindings/8.0/generated_symbols.dart';
import '../../src/bindings/8.0/generated_bindings_accounts_svc.dart';
import '../../src/bindings/8.0/generated_bindings_appcore_agent.dart';
import '../../src/bindings/8.0/generated_bindings_asp.dart';
import '../../src/bindings/8.0/generated_bindings_badge.dart';
import '../../src/bindings/8.0/generated_bindings_bundle.dart';
import '../../src/bindings/8.0/generated_bindings_calendar_service2.dart';
import '../../src/bindings/8.0/generated_bindings_capi_appfw_alarm.dart';
import '../../src/bindings/8.0/generated_bindings_capi_appfw_app_common.dart';
import '../../src/bindings/8.0/generated_bindings_capi_appfw_app_control.dart';
import '../../src/bindings/8.0/generated_bindings_capi_appfw_app_control_uri.dart';
import '../../src/bindings/8.0/generated_bindings_capi_appfw_app_manager.dart';
import '../../src/bindings/8.0/generated_bindings_capi_appfw_application.dart';
import '../../src/bindings/8.0/generated_bindings_capi_appfw_event.dart';
import '../../src/bindings/8.0/generated_bindings_capi_appfw_job_scheduler.dart';
import '../../src/bindings/8.0/generated_bindings_capi_appfw_package_manager.dart';
import '../../src/bindings/8.0/generated_bindings_capi_appfw_preference.dart';
import '../../src/bindings/8.0/generated_bindings_capi_base_common.dart';
import '../../src/bindings/8.0/generated_bindings_capi_content_media_content.dart';
import '../../src/bindings/8.0/generated_bindings_capi_content_mime_type.dart';
import '../../src/bindings/8.0/generated_bindings_capi_context.dart';
import '../../src/bindings/8.0/generated_bindings_capi_geofence_manager.dart';
import '../../src/bindings/8.0/generated_bindings_capi_location_manager.dart';
import '../../src/bindings/8.0/generated_bindings_capi_media_audio_io.dart';
import '../../src/bindings/8.0/generated_bindings_capi_media_camera.dart';
import '../../src/bindings/8.0/generated_bindings_capi_media_codec.dart';
import '../../src/bindings/8.0/generated_bindings_capi_media_controller.dart';
import '../../src/bindings/8.0/generated_bindings_capi_media_editor.dart';
import '../../src/bindings/8.0/generated_bindings_capi_media_image_util.dart';
import '../../src/bindings/8.0/generated_bindings_capi_media_metadata_editor.dart';
import '../../src/bindings/8.0/generated_bindings_capi_media_metadata_extractor.dart';
import '../../src/bindings/8.0/generated_bindings_capi_media_player.dart';
import '../../src/bindings/8.0/generated_bindings_capi_media_radio.dart';
import '../../src/bindings/8.0/generated_bindings_capi_media_recorder.dart';
import '../../src/bindings/8.0/generated_bindings_capi_media_screen_mirroring.dart';
import '../../src/bindings/8.0/generated_bindings_capi_media_sound_manager.dart';
import '../../src/bindings/8.0/generated_bindings_capi_media_sound_pool.dart';
import '../../src/bindings/8.0/generated_bindings_capi_media_streamer.dart';
import '../../src/bindings/8.0/generated_bindings_capi_media_streamrecorder.dart';
import '../../src/bindings/8.0/generated_bindings_capi_media_thumbnail_util.dart';
import '../../src/bindings/8.0/generated_bindings_capi_media_tone_player.dart';
import '../../src/bindings/8.0/generated_bindings_capi_media_tool.dart';
import '../../src/bindings/8.0/generated_bindings_capi_media_wav_player.dart';
import '../../src/bindings/8.0/generated_bindings_capi_media_webrtc.dart';
import '../../src/bindings/8.0/generated_bindings_capi_mediademuxer.dart';
import '../../src/bindings/8.0/generated_bindings_capi_mediamuxer.dart';
import '../../src/bindings/8.0/generated_bindings_capi_messaging_email.dart';
import '../../src/bindings/8.0/generated_bindings_capi_ml_common.dart';
import '../../src/bindings/8.0/generated_bindings_capi_ml_inference_single.dart';
import '../../src/bindings/8.0/generated_bindings_capi_ml_service.dart';
import '../../src/bindings/8.0/generated_bindings_capi_network_bluetooth.dart';
import '../../src/bindings/8.0/generated_bindings_capi_network_connection.dart';
import '../../src/bindings/8.0/generated_bindings_capi_network_http.dart';
import '../../src/bindings/8.0/generated_bindings_capi_network_inm.dart';
import '../../src/bindings/8.0/generated_bindings_capi_network_mtp.dart';
import '../../src/bindings/8.0/generated_bindings_capi_network_softap.dart';
import '../../src/bindings/8.0/generated_bindings_capi_network_stc.dart';
import '../../src/bindings/8.0/generated_bindings_capi_network_wifi_manager.dart';
import '../../src/bindings/8.0/generated_bindings_capi_nnstreamer.dart';
import '../../src/bindings/8.0/generated_bindings_capi_nntrainer.dart';
import '../../src/bindings/8.0/generated_bindings_capi_privacy_privilege_manager.dart';
import '../../src/bindings/8.0/generated_bindings_capi_system_device.dart';
import '../../src/bindings/8.0/generated_bindings_capi_system_info.dart';
import '../../src/bindings/8.0/generated_bindings_capi_system_media_key.dart';
import '../../src/bindings/8.0/generated_bindings_capi_system_peripheral_io.dart';
import '../../src/bindings/8.0/generated_bindings_capi_system_resource_monitor.dart';
import '../../src/bindings/8.0/generated_bindings_capi_system_runtime_info.dart';
import '../../src/bindings/8.0/generated_bindings_capi_system_sensor.dart';
import '../../src/bindings/8.0/generated_bindings_capi_system_system_settings.dart';
import '../../src/bindings/8.0/generated_bindings_capi_system_usbhost.dart';
import '../../src/bindings/8.0/generated_bindings_capi_ui_autofill.dart';
import '../../src/bindings/8.0/generated_bindings_capi_ui_autofill_common.dart';
import '../../src/bindings/8.0/generated_bindings_capi_ui_autofill_manager.dart';
import '../../src/bindings/8.0/generated_bindings_capi_ui_autofill_service.dart';
import '../../src/bindings/8.0/generated_bindings_capi_ui_inputmethod.dart';
import '../../src/bindings/8.0/generated_bindings_capi_ui_inputmethod_manager.dart';
import '../../src/bindings/8.0/generated_bindings_capi_vpnsvc.dart';
import '../../src/bindings/8.0/generated_bindings_capi_web_url_download.dart';
import '../../src/bindings/8.0/generated_bindings_cion.dart';
import '../../src/bindings/8.0/generated_bindings_contacts_service2.dart';
import '../../src/bindings/8.0/generated_bindings_core_sync_client.dart';
import '../../src/bindings/8.0/generated_bindings_csr_client.dart';
import '../../src/bindings/8.0/generated_bindings_data_control.dart';
import '../../src/bindings/8.0/generated_bindings_device_certificate_manager.dart';
import '../../src/bindings/8.0/generated_bindings_diagnostics.dart';
import '../../src/bindings/8.0/generated_bindings_dlog.dart';
import '../../src/bindings/8.0/generated_bindings_dpm.dart';
import '../../src/bindings/8.0/generated_bindings_eom.dart';
import '../../src/bindings/8.0/generated_bindings_feedback.dart';
import '../../src/bindings/8.0/generated_bindings_fido_client.dart';
import '../../src/bindings/8.0/generated_bindings_iotcon.dart';
import '../../src/bindings/8.0/generated_bindings_key_manager_client.dart';
import '../../src/bindings/8.0/generated_bindings_ma.dart';
import '../../src/bindings/8.0/generated_bindings_message_port.dart';
import '../../src/bindings/8.0/generated_bindings_mv_3d.dart';
import '../../src/bindings/8.0/generated_bindings_mv_barcode_detector.dart';
import '../../src/bindings/8.0/generated_bindings_mv_barcode_generator.dart';
import '../../src/bindings/8.0/generated_bindings_mv_common.dart';
import '../../src/bindings/8.0/generated_bindings_mv_face.dart';
import '../../src/bindings/8.0/generated_bindings_mv_face_recognition.dart';
import '../../src/bindings/8.0/generated_bindings_mv_image.dart';
import '../../src/bindings/8.0/generated_bindings_mv_inference.dart';
import '../../src/bindings/8.0/generated_bindings_mv_roi_tracker.dart';
import '../../src/bindings/8.0/generated_bindings_mv_surveillance.dart';
import '../../src/bindings/8.0/generated_bindings_notification.dart';
import '../../src/bindings/8.0/generated_bindings_notification_ex.dart';
import '../../src/bindings/8.0/generated_bindings_nsd_dns_sd.dart';
import '../../src/bindings/8.0/generated_bindings_nsd_ssdp.dart';
import '../../src/bindings/8.0/generated_bindings_oauth2.dart';
import '../../src/bindings/8.0/generated_bindings_phonenumber_utils.dart';
import '../../src/bindings/8.0/generated_bindings_privilege_info.dart';
import '../../src/bindings/8.0/generated_bindings_push.dart';
import '../../src/bindings/8.0/generated_bindings_rpc_port.dart';
import '../../src/bindings/8.0/generated_bindings_storage.dart';
import '../../src/bindings/8.0/generated_bindings_stt.dart';
import '../../src/bindings/8.0/generated_bindings_stt_engine.dart';
import '../../src/bindings/8.0/generated_bindings_tbm.dart';
import '../../src/bindings/8.0/generated_bindings_ttrace.dart';
import '../../src/bindings/8.0/generated_bindings_tts.dart';
import '../../src/bindings/8.0/generated_bindings_tts_engine.dart';
import '../../src/bindings/8.0/generated_bindings_update_control.dart';
import '../../src/bindings/8.0/generated_bindings_vc.dart';
import '../../src/bindings/8.0/generated_bindings_vc_engine.dart';
import '../../src/bindings/8.0/generated_bindings_vc_manager.dart';
import '../../src/bindings/8.0/generated_bindings_wifi_direct.dart';
import '../../src/bindings/8.0/generated_bindings_yaca.dart';
import '../../src/lookup_provider.dart';

export '../../src/extensions.dart';
export '../../src/bindings/8.0/generated_bindings_accounts_svc.dart';
export '../../src/bindings/8.0/generated_bindings_appcore_agent.dart';
export '../../src/bindings/8.0/generated_bindings_asp.dart';
export '../../src/bindings/8.0/generated_bindings_badge.dart';
export '../../src/bindings/8.0/generated_bindings_bundle.dart';
export '../../src/bindings/8.0/generated_bindings_calendar_service2.dart';
export '../../src/bindings/8.0/generated_bindings_capi_appfw_alarm.dart';
export '../../src/bindings/8.0/generated_bindings_capi_appfw_app_common.dart';
export '../../src/bindings/8.0/generated_bindings_capi_appfw_app_control.dart';
export '../../src/bindings/8.0/generated_bindings_capi_appfw_app_control_uri.dart';
export '../../src/bindings/8.0/generated_bindings_capi_appfw_app_manager.dart';
export '../../src/bindings/8.0/generated_bindings_capi_appfw_application.dart';
export '../../src/bindings/8.0/generated_bindings_capi_appfw_event.dart';
export '../../src/bindings/8.0/generated_bindings_capi_appfw_job_scheduler.dart';
export '../../src/bindings/8.0/generated_bindings_capi_appfw_package_manager.dart';
export '../../src/bindings/8.0/generated_bindings_capi_appfw_preference.dart';
export '../../src/bindings/8.0/generated_bindings_capi_base_common.dart';
export '../../src/bindings/8.0/generated_bindings_capi_content_media_content.dart';
export '../../src/bindings/8.0/generated_bindings_capi_content_mime_type.dart';
export '../../src/bindings/8.0/generated_bindings_capi_context.dart';
export '../../src/bindings/8.0/generated_bindings_capi_geofence_manager.dart';
export '../../src/bindings/8.0/generated_bindings_capi_location_manager.dart';
export '../../src/bindings/8.0/generated_bindings_capi_media_audio_io.dart';
export '../../src/bindings/8.0/generated_bindings_capi_media_camera.dart'
    hide UnnamedUnion1, UnnamedStruct1;
export '../../src/bindings/8.0/generated_bindings_capi_media_codec.dart';
export '../../src/bindings/8.0/generated_bindings_capi_media_controller.dart';
export '../../src/bindings/8.0/generated_bindings_capi_media_editor.dart';
export '../../src/bindings/8.0/generated_bindings_capi_media_image_util.dart';
export '../../src/bindings/8.0/generated_bindings_capi_media_metadata_editor.dart';
export '../../src/bindings/8.0/generated_bindings_capi_media_metadata_extractor.dart';
export '../../src/bindings/8.0/generated_bindings_capi_media_player.dart';
export '../../src/bindings/8.0/generated_bindings_capi_media_radio.dart';
export '../../src/bindings/8.0/generated_bindings_capi_media_recorder.dart';
export '../../src/bindings/8.0/generated_bindings_capi_media_screen_mirroring.dart';
export '../../src/bindings/8.0/generated_bindings_capi_media_sound_manager.dart';
export '../../src/bindings/8.0/generated_bindings_capi_media_sound_pool.dart';
export '../../src/bindings/8.0/generated_bindings_capi_media_streamer.dart';
export '../../src/bindings/8.0/generated_bindings_capi_media_streamrecorder.dart';
export '../../src/bindings/8.0/generated_bindings_capi_media_thumbnail_util.dart';
export '../../src/bindings/8.0/generated_bindings_capi_media_tone_player.dart';
export '../../src/bindings/8.0/generated_bindings_capi_media_tool.dart';
export '../../src/bindings/8.0/generated_bindings_capi_media_wav_player.dart';
export '../../src/bindings/8.0/generated_bindings_capi_media_webrtc.dart'
    hide UnnamedUnion1;
export '../../src/bindings/8.0/generated_bindings_capi_mediademuxer.dart';
export '../../src/bindings/8.0/generated_bindings_capi_mediamuxer.dart';
export '../../src/bindings/8.0/generated_bindings_capi_messaging_email.dart';
export '../../src/bindings/8.0/generated_bindings_capi_ml_common.dart';
export '../../src/bindings/8.0/generated_bindings_capi_ml_inference_single.dart';
export '../../src/bindings/8.0/generated_bindings_capi_ml_service.dart';
export '../../src/bindings/8.0/generated_bindings_capi_network_bluetooth.dart';
export '../../src/bindings/8.0/generated_bindings_capi_network_connection.dart';
export '../../src/bindings/8.0/generated_bindings_capi_network_http.dart';
export '../../src/bindings/8.0/generated_bindings_capi_network_inm.dart';
export '../../src/bindings/8.0/generated_bindings_capi_network_mtp.dart';
export '../../src/bindings/8.0/generated_bindings_capi_network_softap.dart';
export '../../src/bindings/8.0/generated_bindings_capi_network_stc.dart';
export '../../src/bindings/8.0/generated_bindings_capi_network_wifi_manager.dart';
export '../../src/bindings/8.0/generated_bindings_capi_nnstreamer.dart';
export '../../src/bindings/8.0/generated_bindings_capi_nntrainer.dart';
export '../../src/bindings/8.0/generated_bindings_capi_privacy_privilege_manager.dart';
export '../../src/bindings/8.0/generated_bindings_capi_system_device.dart';
export '../../src/bindings/8.0/generated_bindings_capi_system_info.dart';
export '../../src/bindings/8.0/generated_bindings_capi_system_media_key.dart';
export '../../src/bindings/8.0/generated_bindings_capi_system_peripheral_io.dart';
export '../../src/bindings/8.0/generated_bindings_capi_system_resource_monitor.dart';
export '../../src/bindings/8.0/generated_bindings_capi_system_runtime_info.dart';
export '../../src/bindings/8.0/generated_bindings_capi_system_sensor.dart';
export '../../src/bindings/8.0/generated_bindings_capi_system_system_settings.dart';
export '../../src/bindings/8.0/generated_bindings_capi_system_usbhost.dart';
export '../../src/bindings/8.0/generated_bindings_capi_ui_autofill.dart';
export '../../src/bindings/8.0/generated_bindings_capi_ui_autofill_common.dart';
export '../../src/bindings/8.0/generated_bindings_capi_ui_autofill_manager.dart';
export '../../src/bindings/8.0/generated_bindings_capi_ui_autofill_service.dart';
export '../../src/bindings/8.0/generated_bindings_capi_ui_inputmethod.dart';
export '../../src/bindings/8.0/generated_bindings_capi_ui_inputmethod_manager.dart';
export '../../src/bindings/8.0/generated_bindings_capi_vpnsvc.dart';
export '../../src/bindings/8.0/generated_bindings_capi_web_url_download.dart';
export '../../src/bindings/8.0/generated_bindings_cion.dart';
export '../../src/bindings/8.0/generated_bindings_contacts_service2.dart';
export '../../src/bindings/8.0/generated_bindings_core_sync_client.dart';
export '../../src/bindings/8.0/generated_bindings_csr_client.dart';
export '../../src/bindings/8.0/generated_bindings_data_control.dart';
export '../../src/bindings/8.0/generated_bindings_device_certificate_manager.dart';
export '../../src/bindings/8.0/generated_bindings_diagnostics.dart';
export '../../src/bindings/8.0/generated_bindings_dlog.dart';
export '../../src/bindings/8.0/generated_bindings_dpm.dart';
export '../../src/bindings/8.0/generated_bindings_eom.dart';
export '../../src/bindings/8.0/generated_bindings_feedback.dart';
export '../../src/bindings/8.0/generated_bindings_fido_client.dart';
export '../../src/bindings/8.0/generated_bindings_iotcon.dart';
export '../../src/bindings/8.0/generated_bindings_key_manager_client.dart';
export '../../src/bindings/8.0/generated_bindings_ma.dart';
export '../../src/bindings/8.0/generated_bindings_message_port.dart';
export '../../src/bindings/8.0/generated_bindings_mv_3d.dart';
export '../../src/bindings/8.0/generated_bindings_mv_barcode_detector.dart';
export '../../src/bindings/8.0/generated_bindings_mv_barcode_generator.dart';
export '../../src/bindings/8.0/generated_bindings_mv_common.dart';
export '../../src/bindings/8.0/generated_bindings_mv_face.dart';
export '../../src/bindings/8.0/generated_bindings_mv_face_recognition.dart';
export '../../src/bindings/8.0/generated_bindings_mv_image.dart';
export '../../src/bindings/8.0/generated_bindings_mv_inference.dart';
export '../../src/bindings/8.0/generated_bindings_mv_roi_tracker.dart';
export '../../src/bindings/8.0/generated_bindings_mv_surveillance.dart';
export '../../src/bindings/8.0/generated_bindings_notification.dart';
export '../../src/bindings/8.0/generated_bindings_notification_ex.dart';
export '../../src/bindings/8.0/generated_bindings_nsd_dns_sd.dart';
export '../../src/bindings/8.0/generated_bindings_nsd_ssdp.dart';
export '../../src/bindings/8.0/generated_bindings_oauth2.dart';
export '../../src/bindings/8.0/generated_bindings_phonenumber_utils.dart';
export '../../src/bindings/8.0/generated_bindings_privilege_info.dart';
export '../../src/bindings/8.0/generated_bindings_push.dart';
export '../../src/bindings/8.0/generated_bindings_rpc_port.dart';
export '../../src/bindings/8.0/generated_bindings_storage.dart';
export '../../src/bindings/8.0/generated_bindings_stt.dart';
export '../../src/bindings/8.0/generated_bindings_stt_engine.dart';
export '../../src/bindings/8.0/generated_bindings_tbm.dart';
export '../../src/bindings/8.0/generated_bindings_ttrace.dart';
export '../../src/bindings/8.0/generated_bindings_tts.dart';
export '../../src/bindings/8.0/generated_bindings_tts_engine.dart';
export '../../src/bindings/8.0/generated_bindings_update_control.dart';
export '../../src/bindings/8.0/generated_bindings_vc.dart';
export '../../src/bindings/8.0/generated_bindings_vc_engine.dart';
export '../../src/bindings/8.0/generated_bindings_vc_manager.dart';
export '../../src/bindings/8.0/generated_bindings_wifi_direct.dart';
export '../../src/bindings/8.0/generated_bindings_yaca.dart';
export '../../src/bindings/8.0/generated_bindings_time.dart'
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

Tizen80AccountsSvc? _tizenAccountsSvc;
Tizen80AccountsSvc get tizenAccountsSvc => _tizenAccountsSvc ??=
    _getTizenInstance(accountsSvcSymbols, Tizen80AccountsSvc.fromLookup)!;

Tizen80AppcoreAgent? _tizenAppcoreAgent;
Tizen80AppcoreAgent get tizenAppcoreAgent => _tizenAppcoreAgent ??=
    _getTizenInstance(appcoreAgentSymbols, Tizen80AppcoreAgent.fromLookup)!;

Tizen80Asp? _tizenAsp;
Tizen80Asp get tizenAsp =>
    _tizenAsp ??= _getTizenInstance(aspSymbols, Tizen80Asp.fromLookup)!;

Tizen80Badge? _tizenBadge;
Tizen80Badge get tizenBadge =>
    _tizenBadge ??= _getTizenInstance(badgeSymbols, Tizen80Badge.fromLookup)!;

Tizen80Bundle? _tizenBundle;
Tizen80Bundle get tizenBundle => _tizenBundle ??=
    _getTizenInstance(bundleSymbols, Tizen80Bundle.fromLookup)!;

Tizen80CalendarService2? _tizenCalendarService2;
Tizen80CalendarService2 get tizenCalendarService2 =>
    _tizenCalendarService2 ??= _getTizenInstance(
        calendarService2Symbols, Tizen80CalendarService2.fromLookup)!;

Tizen80CapiAppfwAlarm? _tizenCapiAppfwAlarm;
Tizen80CapiAppfwAlarm get tizenCapiAppfwAlarm => _tizenCapiAppfwAlarm ??=
    _getTizenInstance(capiAppfwAlarmSymbols, Tizen80CapiAppfwAlarm.fromLookup)!;

Tizen80CapiAppfwAppCommon? _tizenCapiAppfwAppCommon;
Tizen80CapiAppfwAppCommon get tizenCapiAppfwAppCommon =>
    _tizenCapiAppfwAppCommon ??= _getTizenInstance(
        capiAppfwAppCommonSymbols, Tizen80CapiAppfwAppCommon.fromLookup)!;

Tizen80CapiAppfwAppControl? _tizenCapiAppfwAppControl;
Tizen80CapiAppfwAppControl get tizenCapiAppfwAppControl =>
    _tizenCapiAppfwAppControl ??= _getTizenInstance(
        capiAppfwAppControlSymbols, Tizen80CapiAppfwAppControl.fromLookup)!;

Tizen80CapiAppfwAppControlUri? _tizenCapiAppfwAppControlUri;
Tizen80CapiAppfwAppControlUri get tizenCapiAppfwAppControlUri =>
    _tizenCapiAppfwAppControlUri ??= _getTizenInstance(
        capiAppfwAppControlUriSymbols,
        Tizen80CapiAppfwAppControlUri.fromLookup)!;

Tizen80CapiAppfwAppManager? _tizenCapiAppfwAppManager;
Tizen80CapiAppfwAppManager get tizenCapiAppfwAppManager =>
    _tizenCapiAppfwAppManager ??= _getTizenInstance(
        capiAppfwAppManagerSymbols, Tizen80CapiAppfwAppManager.fromLookup)!;

Tizen80CapiAppfwApplication? _tizenCapiAppfwApplication;
Tizen80CapiAppfwApplication get tizenCapiAppfwApplication =>
    _tizenCapiAppfwApplication ??= _getTizenInstance(
        capiAppfwApplicationSymbols, Tizen80CapiAppfwApplication.fromLookup)!;

Tizen80CapiAppfwEvent? _tizenCapiAppfwEvent;
Tizen80CapiAppfwEvent get tizenCapiAppfwEvent => _tizenCapiAppfwEvent ??=
    _getTizenInstance(capiAppfwEventSymbols, Tizen80CapiAppfwEvent.fromLookup)!;

Tizen80CapiAppfwJobScheduler? _tizenCapiAppfwJobScheduler;
Tizen80CapiAppfwJobScheduler get tizenCapiAppfwJobScheduler =>
    _tizenCapiAppfwJobScheduler ??= _getTizenInstance(
        capiAppfwJobSchedulerSymbols, Tizen80CapiAppfwJobScheduler.fromLookup)!;

Tizen80CapiAppfwPackageManager? _tizenCapiAppfwPackageManager;
Tizen80CapiAppfwPackageManager get tizenCapiAppfwPackageManager =>
    _tizenCapiAppfwPackageManager ??= _getTizenInstance(
        capiAppfwPackageManagerSymbols,
        Tizen80CapiAppfwPackageManager.fromLookup)!;

Tizen80CapiAppfwPreference? _tizenCapiAppfwPreference;
Tizen80CapiAppfwPreference get tizenCapiAppfwPreference =>
    _tizenCapiAppfwPreference ??= _getTizenInstance(
        capiAppfwPreferenceSymbols, Tizen80CapiAppfwPreference.fromLookup)!;

Tizen80CapiBaseCommon? _tizenCapiBaseCommon;
Tizen80CapiBaseCommon get tizenCapiBaseCommon => _tizenCapiBaseCommon ??=
    _getTizenInstance(capiBaseCommonSymbols, Tizen80CapiBaseCommon.fromLookup)!;

Tizen80CapiContentMediaContent? _tizenCapiContentMediaContent;
Tizen80CapiContentMediaContent get tizenCapiContentMediaContent =>
    _tizenCapiContentMediaContent ??= _getTizenInstance(
        capiContentMediaContentSymbols,
        Tizen80CapiContentMediaContent.fromLookup)!;

Tizen80CapiContentMimeType? _tizenCapiContentMimeType;
Tizen80CapiContentMimeType get tizenCapiContentMimeType =>
    _tizenCapiContentMimeType ??= _getTizenInstance(
        capiContentMimeTypeSymbols, Tizen80CapiContentMimeType.fromLookup)!;

Tizen80CapiContext? _tizenCapiContext;
Tizen80CapiContext get tizenCapiContext => _tizenCapiContext ??=
    _getTizenInstance(capiContextSymbols, Tizen80CapiContext.fromLookup)!;

Tizen80CapiGeofenceManager? _tizenCapiGeofenceManager;
Tizen80CapiGeofenceManager get tizenCapiGeofenceManager =>
    _tizenCapiGeofenceManager ??= _getTizenInstance(
        capiGeofenceManagerSymbols, Tizen80CapiGeofenceManager.fromLookup)!;

Tizen80CapiLocationManager? _tizenCapiLocationManager;
Tizen80CapiLocationManager get tizenCapiLocationManager =>
    _tizenCapiLocationManager ??= _getTizenInstance(
        capiLocationManagerSymbols, Tizen80CapiLocationManager.fromLookup)!;

Tizen80CapiMediaAudioIo? _tizenCapiMediaAudioIo;
Tizen80CapiMediaAudioIo get tizenCapiMediaAudioIo =>
    _tizenCapiMediaAudioIo ??= _getTizenInstance(
        capiMediaAudioIoSymbols, Tizen80CapiMediaAudioIo.fromLookup)!;

Tizen80CapiMediaCamera? _tizenCapiMediaCamera;
Tizen80CapiMediaCamera get tizenCapiMediaCamera =>
    _tizenCapiMediaCamera ??= _getTizenInstance(
        capiMediaCameraSymbols, Tizen80CapiMediaCamera.fromLookup)!;

Tizen80CapiMediaCodec? _tizenCapiMediaCodec;
Tizen80CapiMediaCodec get tizenCapiMediaCodec => _tizenCapiMediaCodec ??=
    _getTizenInstance(capiMediaCodecSymbols, Tizen80CapiMediaCodec.fromLookup)!;

Tizen80CapiMediaController? _tizenCapiMediaController;
Tizen80CapiMediaController get tizenCapiMediaController =>
    _tizenCapiMediaController ??= _getTizenInstance(
        capiMediaControllerSymbols, Tizen80CapiMediaController.fromLookup)!;

Tizen80CapiMediaEditor? _tizenCapiMediaEditor;
Tizen80CapiMediaEditor get tizenCapiMediaEditor =>
    _tizenCapiMediaEditor ??= _getTizenInstance(
        capiMediaEditorSymbols, Tizen80CapiMediaEditor.fromLookup)!;

Tizen80CapiMediaImageUtil? _tizenCapiMediaImageUtil;
Tizen80CapiMediaImageUtil get tizenCapiMediaImageUtil =>
    _tizenCapiMediaImageUtil ??= _getTizenInstance(
        capiMediaImageUtilSymbols, Tizen80CapiMediaImageUtil.fromLookup)!;

Tizen80CapiMediaMetadataEditor? _tizenCapiMediaMetadataEditor;
Tizen80CapiMediaMetadataEditor get tizenCapiMediaMetadataEditor =>
    _tizenCapiMediaMetadataEditor ??= _getTizenInstance(
        capiMediaMetadataEditorSymbols,
        Tizen80CapiMediaMetadataEditor.fromLookup)!;

Tizen80CapiMediaMetadataExtractor? _tizenCapiMediaMetadataExtractor;
Tizen80CapiMediaMetadataExtractor get tizenCapiMediaMetadataExtractor =>
    _tizenCapiMediaMetadataExtractor ??= _getTizenInstance(
        capiMediaMetadataExtractorSymbols,
        Tizen80CapiMediaMetadataExtractor.fromLookup)!;

Tizen80CapiMediaPlayer? _tizenCapiMediaPlayer;
Tizen80CapiMediaPlayer get tizenCapiMediaPlayer =>
    _tizenCapiMediaPlayer ??= _getTizenInstance(
        capiMediaPlayerSymbols, Tizen80CapiMediaPlayer.fromLookup)!;

Tizen80CapiMediaRadio? _tizenCapiMediaRadio;
Tizen80CapiMediaRadio get tizenCapiMediaRadio => _tizenCapiMediaRadio ??=
    _getTizenInstance(capiMediaRadioSymbols, Tizen80CapiMediaRadio.fromLookup)!;

Tizen80CapiMediaRecorder? _tizenCapiMediaRecorder;
Tizen80CapiMediaRecorder get tizenCapiMediaRecorder =>
    _tizenCapiMediaRecorder ??= _getTizenInstance(
        capiMediaRecorderSymbols, Tizen80CapiMediaRecorder.fromLookup)!;

Tizen80CapiMediaScreenMirroring? _tizenCapiMediaScreenMirroring;
Tizen80CapiMediaScreenMirroring get tizenCapiMediaScreenMirroring =>
    _tizenCapiMediaScreenMirroring ??= _getTizenInstance(
        capiMediaScreenMirroringSymbols,
        Tizen80CapiMediaScreenMirroring.fromLookup)!;

Tizen80CapiMediaSoundManager? _tizenCapiMediaSoundManager;
Tizen80CapiMediaSoundManager get tizenCapiMediaSoundManager =>
    _tizenCapiMediaSoundManager ??= _getTizenInstance(
        capiMediaSoundManagerSymbols, Tizen80CapiMediaSoundManager.fromLookup)!;

Tizen80CapiMediaSoundPool? _tizenCapiMediaSoundPool;
Tizen80CapiMediaSoundPool get tizenCapiMediaSoundPool =>
    _tizenCapiMediaSoundPool ??= _getTizenInstance(
        capiMediaSoundPoolSymbols, Tizen80CapiMediaSoundPool.fromLookup)!;

Tizen80CapiMediaStreamer? _tizenCapiMediaStreamer;
Tizen80CapiMediaStreamer get tizenCapiMediaStreamer =>
    _tizenCapiMediaStreamer ??= _getTizenInstance(
        capiMediaStreamerSymbols, Tizen80CapiMediaStreamer.fromLookup)!;

Tizen80CapiMediaStreamrecorder? _tizenCapiMediaStreamrecorder;
Tizen80CapiMediaStreamrecorder get tizenCapiMediaStreamrecorder =>
    _tizenCapiMediaStreamrecorder ??= _getTizenInstance(
        capiMediaStreamrecorderSymbols,
        Tizen80CapiMediaStreamrecorder.fromLookup)!;

Tizen80CapiMediaThumbnailUtil? _tizenCapiMediaThumbnailUtil;
Tizen80CapiMediaThumbnailUtil get tizenCapiMediaThumbnailUtil =>
    _tizenCapiMediaThumbnailUtil ??= _getTizenInstance(
        capiMediaThumbnailUtilSymbols,
        Tizen80CapiMediaThumbnailUtil.fromLookup)!;

Tizen80CapiMediaTonePlayer? _tizenCapiMediaTonePlayer;
Tizen80CapiMediaTonePlayer get tizenCapiMediaTonePlayer =>
    _tizenCapiMediaTonePlayer ??= _getTizenInstance(
        capiMediaTonePlayerSymbols, Tizen80CapiMediaTonePlayer.fromLookup)!;

Tizen80CapiMediaTool? _tizenCapiMediaTool;
Tizen80CapiMediaTool get tizenCapiMediaTool => _tizenCapiMediaTool ??=
    _getTizenInstance(capiMediaToolSymbols, Tizen80CapiMediaTool.fromLookup)!;

Tizen80CapiMediaWavPlayer? _tizenCapiMediaWavPlayer;
Tizen80CapiMediaWavPlayer get tizenCapiMediaWavPlayer =>
    _tizenCapiMediaWavPlayer ??= _getTizenInstance(
        capiMediaWavPlayerSymbols, Tizen80CapiMediaWavPlayer.fromLookup)!;

Tizen80CapiMediaWebrtc? _tizenCapiMediaWebrtc;
Tizen80CapiMediaWebrtc get tizenCapiMediaWebrtc =>
    _tizenCapiMediaWebrtc ??= _getTizenInstance(
        capiMediaWebrtcSymbols, Tizen80CapiMediaWebrtc.fromLookup)!;

Tizen80CapiMediademuxer? _tizenCapiMediademuxer;
Tizen80CapiMediademuxer get tizenCapiMediademuxer =>
    _tizenCapiMediademuxer ??= _getTizenInstance(
        capiMediademuxerSymbols, Tizen80CapiMediademuxer.fromLookup)!;

Tizen80CapiMediamuxer? _tizenCapiMediamuxer;
Tizen80CapiMediamuxer get tizenCapiMediamuxer => _tizenCapiMediamuxer ??=
    _getTizenInstance(capiMediamuxerSymbols, Tizen80CapiMediamuxer.fromLookup)!;

Tizen80CapiMessagingEmail? _tizenCapiMessagingEmail;
Tizen80CapiMessagingEmail get tizenCapiMessagingEmail =>
    _tizenCapiMessagingEmail ??= _getTizenInstance(
        capiMessagingEmailSymbols, Tizen80CapiMessagingEmail.fromLookup)!;

Tizen80CapiMlCommon? _tizenCapiMlCommon;
Tizen80CapiMlCommon get tizenCapiMlCommon => _tizenCapiMlCommon ??=
    _getTizenInstance(capiMlCommonSymbols, Tizen80CapiMlCommon.fromLookup)!;

Tizen80CapiMlInferenceSingle? _tizenCapiMlInferenceSingle;
Tizen80CapiMlInferenceSingle get tizenCapiMlInferenceSingle =>
    _tizenCapiMlInferenceSingle ??= _getTizenInstance(
        capiMlInferenceSingleSymbols, Tizen80CapiMlInferenceSingle.fromLookup)!;

Tizen80CapiMlService? _tizenCapiMlService;
Tizen80CapiMlService get tizenCapiMlService => _tizenCapiMlService ??=
    _getTizenInstance(capiMlServiceSymbols, Tizen80CapiMlService.fromLookup)!;

Tizen80CapiNetworkBluetooth? _tizenCapiNetworkBluetooth;
Tizen80CapiNetworkBluetooth get tizenCapiNetworkBluetooth =>
    _tizenCapiNetworkBluetooth ??= _getTizenInstance(
        capiNetworkBluetoothSymbols, Tizen80CapiNetworkBluetooth.fromLookup)!;

Tizen80CapiNetworkConnection? _tizenCapiNetworkConnection;
Tizen80CapiNetworkConnection get tizenCapiNetworkConnection =>
    _tizenCapiNetworkConnection ??= _getTizenInstance(
        capiNetworkConnectionSymbols, Tizen80CapiNetworkConnection.fromLookup)!;

Tizen80CapiNetworkHttp? _tizenCapiNetworkHttp;
Tizen80CapiNetworkHttp get tizenCapiNetworkHttp =>
    _tizenCapiNetworkHttp ??= _getTizenInstance(
        capiNetworkHttpSymbols, Tizen80CapiNetworkHttp.fromLookup)!;

Tizen80CapiNetworkInm? _tizenCapiNetworkInm;
Tizen80CapiNetworkInm get tizenCapiNetworkInm => _tizenCapiNetworkInm ??=
    _getTizenInstance(capiNetworkInmSymbols, Tizen80CapiNetworkInm.fromLookup)!;

Tizen80CapiNetworkMtp? _tizenCapiNetworkMtp;
Tizen80CapiNetworkMtp get tizenCapiNetworkMtp => _tizenCapiNetworkMtp ??=
    _getTizenInstance(capiNetworkMtpSymbols, Tizen80CapiNetworkMtp.fromLookup)!;

Tizen80CapiNetworkSoftap? _tizenCapiNetworkSoftap;
Tizen80CapiNetworkSoftap get tizenCapiNetworkSoftap =>
    _tizenCapiNetworkSoftap ??= _getTizenInstance(
        capiNetworkSoftapSymbols, Tizen80CapiNetworkSoftap.fromLookup)!;

Tizen80CapiNetworkStc? _tizenCapiNetworkStc;
Tizen80CapiNetworkStc get tizenCapiNetworkStc => _tizenCapiNetworkStc ??=
    _getTizenInstance(capiNetworkStcSymbols, Tizen80CapiNetworkStc.fromLookup)!;

Tizen80CapiNetworkWifiManager? _tizenCapiNetworkWifiManager;
Tizen80CapiNetworkWifiManager get tizenCapiNetworkWifiManager =>
    _tizenCapiNetworkWifiManager ??= _getTizenInstance(
        capiNetworkWifiManagerSymbols,
        Tizen80CapiNetworkWifiManager.fromLookup)!;

Tizen80CapiNnstreamer? _tizenCapiNnstreamer;
Tizen80CapiNnstreamer get tizenCapiNnstreamer => _tizenCapiNnstreamer ??=
    _getTizenInstance(capiNnstreamerSymbols, Tizen80CapiNnstreamer.fromLookup)!;

Tizen80CapiNntrainer? _tizenCapiNntrainer;
Tizen80CapiNntrainer get tizenCapiNntrainer => _tizenCapiNntrainer ??=
    _getTizenInstance(capiNntrainerSymbols, Tizen80CapiNntrainer.fromLookup)!;

Tizen80CapiPrivacyPrivilegeManager? _tizenCapiPrivacyPrivilegeManager;
Tizen80CapiPrivacyPrivilegeManager get tizenCapiPrivacyPrivilegeManager =>
    _tizenCapiPrivacyPrivilegeManager ??= _getTizenInstance(
        capiPrivacyPrivilegeManagerSymbols,
        Tizen80CapiPrivacyPrivilegeManager.fromLookup)!;

Tizen80CapiSystemDevice? _tizenCapiSystemDevice;
Tizen80CapiSystemDevice get tizenCapiSystemDevice =>
    _tizenCapiSystemDevice ??= _getTizenInstance(
        capiSystemDeviceSymbols, Tizen80CapiSystemDevice.fromLookup)!;

Tizen80CapiSystemInfo? _tizenCapiSystemInfo;
Tizen80CapiSystemInfo get tizenCapiSystemInfo => _tizenCapiSystemInfo ??=
    _getTizenInstance(capiSystemInfoSymbols, Tizen80CapiSystemInfo.fromLookup)!;

Tizen80CapiSystemMediaKey? _tizenCapiSystemMediaKey;
Tizen80CapiSystemMediaKey get tizenCapiSystemMediaKey =>
    _tizenCapiSystemMediaKey ??= _getTizenInstance(
        capiSystemMediaKeySymbols, Tizen80CapiSystemMediaKey.fromLookup)!;

Tizen80CapiSystemPeripheralIo? _tizenCapiSystemPeripheralIo;
Tizen80CapiSystemPeripheralIo get tizenCapiSystemPeripheralIo =>
    _tizenCapiSystemPeripheralIo ??= _getTizenInstance(
        capiSystemPeripheralIoSymbols,
        Tizen80CapiSystemPeripheralIo.fromLookup)!;

Tizen80CapiSystemResourceMonitor? _tizenCapiSystemResourceMonitor;
Tizen80CapiSystemResourceMonitor get tizenCapiSystemResourceMonitor =>
    _tizenCapiSystemResourceMonitor ??= _getTizenInstance(
        capiSystemResourceMonitorSymbols,
        Tizen80CapiSystemResourceMonitor.fromLookup)!;

Tizen80CapiSystemRuntimeInfo? _tizenCapiSystemRuntimeInfo;
Tizen80CapiSystemRuntimeInfo get tizenCapiSystemRuntimeInfo =>
    _tizenCapiSystemRuntimeInfo ??= _getTizenInstance(
        capiSystemRuntimeInfoSymbols, Tizen80CapiSystemRuntimeInfo.fromLookup)!;

Tizen80CapiSystemSensor? _tizenCapiSystemSensor;
Tizen80CapiSystemSensor get tizenCapiSystemSensor =>
    _tizenCapiSystemSensor ??= _getTizenInstance(
        capiSystemSensorSymbols, Tizen80CapiSystemSensor.fromLookup)!;

Tizen80CapiSystemSystemSettings? _tizenCapiSystemSystemSettings;
Tizen80CapiSystemSystemSettings get tizenCapiSystemSystemSettings =>
    _tizenCapiSystemSystemSettings ??= _getTizenInstance(
        capiSystemSystemSettingsSymbols,
        Tizen80CapiSystemSystemSettings.fromLookup)!;

Tizen80CapiSystemUsbhost? _tizenCapiSystemUsbhost;
Tizen80CapiSystemUsbhost get tizenCapiSystemUsbhost =>
    _tizenCapiSystemUsbhost ??= _getTizenInstance(
        capiSystemUsbhostSymbols, Tizen80CapiSystemUsbhost.fromLookup)!;

Tizen80CapiUiAutofill? _tizenCapiUiAutofill;
Tizen80CapiUiAutofill get tizenCapiUiAutofill => _tizenCapiUiAutofill ??=
    _getTizenInstance(capiUiAutofillSymbols, Tizen80CapiUiAutofill.fromLookup)!;

Tizen80CapiUiAutofillCommon? _tizenCapiUiAutofillCommon;
Tizen80CapiUiAutofillCommon get tizenCapiUiAutofillCommon =>
    _tizenCapiUiAutofillCommon ??= _getTizenInstance(
        capiUiAutofillCommonSymbols, Tizen80CapiUiAutofillCommon.fromLookup)!;

Tizen80CapiUiAutofillManager? _tizenCapiUiAutofillManager;
Tizen80CapiUiAutofillManager get tizenCapiUiAutofillManager =>
    _tizenCapiUiAutofillManager ??= _getTizenInstance(
        capiUiAutofillManagerSymbols, Tizen80CapiUiAutofillManager.fromLookup)!;

Tizen80CapiUiAutofillService? _tizenCapiUiAutofillService;
Tizen80CapiUiAutofillService get tizenCapiUiAutofillService =>
    _tizenCapiUiAutofillService ??= _getTizenInstance(
        capiUiAutofillServiceSymbols, Tizen80CapiUiAutofillService.fromLookup)!;

Tizen80CapiUiInputmethod? _tizenCapiUiInputmethod;
Tizen80CapiUiInputmethod get tizenCapiUiInputmethod =>
    _tizenCapiUiInputmethod ??= _getTizenInstance(
        capiUiInputmethodSymbols, Tizen80CapiUiInputmethod.fromLookup)!;

Tizen80CapiUiInputmethodManager? _tizenCapiUiInputmethodManager;
Tizen80CapiUiInputmethodManager get tizenCapiUiInputmethodManager =>
    _tizenCapiUiInputmethodManager ??= _getTizenInstance(
        capiUiInputmethodManagerSymbols,
        Tizen80CapiUiInputmethodManager.fromLookup)!;

Tizen80CapiVpnsvc? _tizenCapiVpnsvc;
Tizen80CapiVpnsvc get tizenCapiVpnsvc => _tizenCapiVpnsvc ??=
    _getTizenInstance(capiVpnsvcSymbols, Tizen80CapiVpnsvc.fromLookup)!;

Tizen80CapiWebUrlDownload? _tizenCapiWebUrlDownload;
Tizen80CapiWebUrlDownload get tizenCapiWebUrlDownload =>
    _tizenCapiWebUrlDownload ??= _getTizenInstance(
        capiWebUrlDownloadSymbols, Tizen80CapiWebUrlDownload.fromLookup)!;

Tizen80Cion? _tizenCion;
Tizen80Cion get tizenCion =>
    _tizenCion ??= _getTizenInstance(cionSymbols, Tizen80Cion.fromLookup)!;

Tizen80ContactsService2? _tizenContactsService2;
Tizen80ContactsService2 get tizenContactsService2 =>
    _tizenContactsService2 ??= _getTizenInstance(
        contactsService2Symbols, Tizen80ContactsService2.fromLookup)!;

Tizen80CoreSyncClient? _tizenCoreSyncClient;
Tizen80CoreSyncClient get tizenCoreSyncClient => _tizenCoreSyncClient ??=
    _getTizenInstance(coreSyncClientSymbols, Tizen80CoreSyncClient.fromLookup)!;

Tizen80CsrClient? _tizenCsrClient;
Tizen80CsrClient get tizenCsrClient => _tizenCsrClient ??=
    _getTizenInstance(csrClientSymbols, Tizen80CsrClient.fromLookup)!;

Tizen80DataControl? _tizenDataControl;
Tizen80DataControl get tizenDataControl => _tizenDataControl ??=
    _getTizenInstance(dataControlSymbols, Tizen80DataControl.fromLookup)!;

Tizen80DeviceCertificateManager? _tizenDeviceCertificateManager;
Tizen80DeviceCertificateManager get tizenDeviceCertificateManager =>
    _tizenDeviceCertificateManager ??= _getTizenInstance(
        deviceCertificateManagerSymbols,
        Tizen80DeviceCertificateManager.fromLookup)!;

Tizen80Diagnostics? _tizenDiagnostics;
Tizen80Diagnostics get tizenDiagnostics => _tizenDiagnostics ??=
    _getTizenInstance(diagnosticsSymbols, Tizen80Diagnostics.fromLookup)!;

Tizen80Dlog? _tizenDlog;
Tizen80Dlog get tizenDlog =>
    _tizenDlog ??= _getTizenInstance(dlogSymbols, Tizen80Dlog.fromLookup)!;

Tizen80Dpm? _tizenDpm;
Tizen80Dpm get tizenDpm =>
    _tizenDpm ??= _getTizenInstance(dpmSymbols, Tizen80Dpm.fromLookup)!;

Tizen80Eom? _tizenEom;
Tizen80Eom get tizenEom =>
    _tizenEom ??= _getTizenInstance(eomSymbols, Tizen80Eom.fromLookup)!;

Tizen80Feedback? _tizenFeedback;
Tizen80Feedback get tizenFeedback => _tizenFeedback ??=
    _getTizenInstance(feedbackSymbols, Tizen80Feedback.fromLookup)!;

Tizen80FidoClient? _tizenFidoClient;
Tizen80FidoClient get tizenFidoClient => _tizenFidoClient ??=
    _getTizenInstance(fidoClientSymbols, Tizen80FidoClient.fromLookup)!;

Tizen80Iotcon? _tizenIotcon;
Tizen80Iotcon get tizenIotcon => _tizenIotcon ??=
    _getTizenInstance(iotconSymbols, Tizen80Iotcon.fromLookup)!;

Tizen80KeyManagerClient? _tizenKeyManagerClient;
Tizen80KeyManagerClient get tizenKeyManagerClient =>
    _tizenKeyManagerClient ??= _getTizenInstance(
        keyManagerClientSymbols, Tizen80KeyManagerClient.fromLookup)!;

Tizen80Ma? _tizenMa;
Tizen80Ma get tizenMa =>
    _tizenMa ??= _getTizenInstance(maSymbols, Tizen80Ma.fromLookup)!;

Tizen80MessagePort? _tizenMessagePort;
Tizen80MessagePort get tizenMessagePort => _tizenMessagePort ??=
    _getTizenInstance(messagePortSymbols, Tizen80MessagePort.fromLookup)!;

Tizen80Mv3d? _tizenMv3d;
Tizen80Mv3d get tizenMv3d =>
    _tizenMv3d ??= _getTizenInstance(mv3dSymbols, Tizen80Mv3d.fromLookup)!;

Tizen80MvBarcodeDetector? _tizenMvBarcodeDetector;
Tizen80MvBarcodeDetector get tizenMvBarcodeDetector =>
    _tizenMvBarcodeDetector ??= _getTizenInstance(
        mvBarcodeDetectorSymbols, Tizen80MvBarcodeDetector.fromLookup)!;

Tizen80MvBarcodeGenerator? _tizenMvBarcodeGenerator;
Tizen80MvBarcodeGenerator get tizenMvBarcodeGenerator =>
    _tizenMvBarcodeGenerator ??= _getTizenInstance(
        mvBarcodeGeneratorSymbols, Tizen80MvBarcodeGenerator.fromLookup)!;

Tizen80MvCommon? _tizenMvCommon;
Tizen80MvCommon get tizenMvCommon => _tizenMvCommon ??=
    _getTizenInstance(mvCommonSymbols, Tizen80MvCommon.fromLookup)!;

Tizen80MvFace? _tizenMvFace;
Tizen80MvFace get tizenMvFace => _tizenMvFace ??=
    _getTizenInstance(mvFaceSymbols, Tizen80MvFace.fromLookup)!;

Tizen80MvFaceRecognition? _tizenMvFaceRecognition;
Tizen80MvFaceRecognition get tizenMvFaceRecognition =>
    _tizenMvFaceRecognition ??= _getTizenInstance(
        mvFaceRecognitionSymbols, Tizen80MvFaceRecognition.fromLookup)!;

Tizen80MvImage? _tizenMvImage;
Tizen80MvImage get tizenMvImage => _tizenMvImage ??=
    _getTizenInstance(mvImageSymbols, Tizen80MvImage.fromLookup)!;

Tizen80MvInference? _tizenMvInference;
Tizen80MvInference get tizenMvInference => _tizenMvInference ??=
    _getTizenInstance(mvInferenceSymbols, Tizen80MvInference.fromLookup)!;

Tizen80MvRoiTracker? _tizenMvRoiTracker;
Tizen80MvRoiTracker get tizenMvRoiTracker => _tizenMvRoiTracker ??=
    _getTizenInstance(mvRoiTrackerSymbols, Tizen80MvRoiTracker.fromLookup)!;

Tizen80MvSurveillance? _tizenMvSurveillance;
Tizen80MvSurveillance get tizenMvSurveillance => _tizenMvSurveillance ??=
    _getTizenInstance(mvSurveillanceSymbols, Tizen80MvSurveillance.fromLookup)!;

Tizen80Notification? _tizenNotification;
Tizen80Notification get tizenNotification => _tizenNotification ??=
    _getTizenInstance(notificationSymbols, Tizen80Notification.fromLookup)!;

Tizen80NotificationEx? _tizenNotificationEx;
Tizen80NotificationEx get tizenNotificationEx => _tizenNotificationEx ??=
    _getTizenInstance(notificationExSymbols, Tizen80NotificationEx.fromLookup)!;

Tizen80NsdDnsSd? _tizenNsdDnsSd;
Tizen80NsdDnsSd get tizenNsdDnsSd => _tizenNsdDnsSd ??=
    _getTizenInstance(nsdDnsSdSymbols, Tizen80NsdDnsSd.fromLookup)!;

Tizen80NsdSsdp? _tizenNsdSsdp;
Tizen80NsdSsdp get tizenNsdSsdp => _tizenNsdSsdp ??=
    _getTizenInstance(nsdSsdpSymbols, Tizen80NsdSsdp.fromLookup)!;

Tizen80Oauth2? _tizenOauth2;
Tizen80Oauth2 get tizenOauth2 => _tizenOauth2 ??=
    _getTizenInstance(oauth2Symbols, Tizen80Oauth2.fromLookup)!;

Tizen80PhonenumberUtils? _tizenPhonenumberUtils;
Tizen80PhonenumberUtils get tizenPhonenumberUtils =>
    _tizenPhonenumberUtils ??= _getTizenInstance(
        phonenumberUtilsSymbols, Tizen80PhonenumberUtils.fromLookup)!;

Tizen80PrivilegeInfo? _tizenPrivilegeInfo;
Tizen80PrivilegeInfo get tizenPrivilegeInfo => _tizenPrivilegeInfo ??=
    _getTizenInstance(privilegeInfoSymbols, Tizen80PrivilegeInfo.fromLookup)!;

Tizen80Push? _tizenPush;
Tizen80Push get tizenPush =>
    _tizenPush ??= _getTizenInstance(pushSymbols, Tizen80Push.fromLookup)!;

Tizen80RpcPort? _tizenRpcPort;
Tizen80RpcPort get tizenRpcPort => _tizenRpcPort ??=
    _getTizenInstance(rpcPortSymbols, Tizen80RpcPort.fromLookup)!;

Tizen80Storage? _tizenStorage;
Tizen80Storage get tizenStorage => _tizenStorage ??=
    _getTizenInstance(storageSymbols, Tizen80Storage.fromLookup)!;

Tizen80Stt? _tizenStt;
Tizen80Stt get tizenStt =>
    _tizenStt ??= _getTizenInstance(sttSymbols, Tizen80Stt.fromLookup)!;

Tizen80SttEngine? _tizenSttEngine;
Tizen80SttEngine get tizenSttEngine => _tizenSttEngine ??=
    _getTizenInstance(sttEngineSymbols, Tizen80SttEngine.fromLookup)!;

Tizen80Tbm? _tizenTbm;
Tizen80Tbm get tizenTbm =>
    _tizenTbm ??= _getTizenInstance(tbmSymbols, Tizen80Tbm.fromLookup)!;

Tizen80Ttrace? _tizenTtrace;
Tizen80Ttrace get tizenTtrace => _tizenTtrace ??=
    _getTizenInstance(ttraceSymbols, Tizen80Ttrace.fromLookup)!;

Tizen80Tts? _tizenTts;
Tizen80Tts get tizenTts =>
    _tizenTts ??= _getTizenInstance(ttsSymbols, Tizen80Tts.fromLookup)!;

Tizen80TtsEngine? _tizenTtsEngine;
Tizen80TtsEngine get tizenTtsEngine => _tizenTtsEngine ??=
    _getTizenInstance(ttsEngineSymbols, Tizen80TtsEngine.fromLookup)!;

Tizen80UpdateControl? _tizenUpdateControl;
Tizen80UpdateControl get tizenUpdateControl => _tizenUpdateControl ??=
    _getTizenInstance(updateControlSymbols, Tizen80UpdateControl.fromLookup)!;

Tizen80Vc? _tizenVc;
Tizen80Vc get tizenVc =>
    _tizenVc ??= _getTizenInstance(vcSymbols, Tizen80Vc.fromLookup)!;

Tizen80VcEngine? _tizenVcEngine;
Tizen80VcEngine get tizenVcEngine => _tizenVcEngine ??=
    _getTizenInstance(vcEngineSymbols, Tizen80VcEngine.fromLookup)!;

Tizen80VcManager? _tizenVcManager;
Tizen80VcManager get tizenVcManager => _tizenVcManager ??=
    _getTizenInstance(vcManagerSymbols, Tizen80VcManager.fromLookup)!;

Tizen80WifiDirect? _tizenWifiDirect;
Tizen80WifiDirect get tizenWifiDirect => _tizenWifiDirect ??=
    _getTizenInstance(wifiDirectSymbols, Tizen80WifiDirect.fromLookup)!;

Tizen80Yaca? _tizenYaca;
Tizen80Yaca get tizenYaca =>
    _tizenYaca ??= _getTizenInstance(yacaSymbols, Tizen80Yaca.fromLookup)!;
