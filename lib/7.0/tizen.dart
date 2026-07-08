/// Tizen Interop for Tizen 7.0.
library tizen_interop_7_0;

import 'dart:ffi';

import '../../src/bindings/7.0/generated_symbols.dart';
import '../../src/bindings/7.0/generated_bindings_accounts_svc.dart';
import '../../src/bindings/7.0/generated_bindings_appcore_agent.dart';
import '../../src/bindings/7.0/generated_bindings_asp.dart';
import '../../src/bindings/7.0/generated_bindings_badge.dart';
import '../../src/bindings/7.0/generated_bindings_bundle.dart';
import '../../src/bindings/7.0/generated_bindings_calendar_service2.dart';
import '../../src/bindings/7.0/generated_bindings_capi_appfw_alarm.dart';
import '../../src/bindings/7.0/generated_bindings_capi_appfw_app_common.dart';
import '../../src/bindings/7.0/generated_bindings_capi_appfw_app_control.dart';
import '../../src/bindings/7.0/generated_bindings_capi_appfw_app_control_uri.dart';
import '../../src/bindings/7.0/generated_bindings_capi_appfw_app_manager.dart';
import '../../src/bindings/7.0/generated_bindings_capi_appfw_application.dart';
import '../../src/bindings/7.0/generated_bindings_capi_appfw_event.dart';
import '../../src/bindings/7.0/generated_bindings_capi_appfw_job_scheduler.dart';
import '../../src/bindings/7.0/generated_bindings_capi_appfw_package_manager.dart';
import '../../src/bindings/7.0/generated_bindings_capi_appfw_preference.dart';
import '../../src/bindings/7.0/generated_bindings_capi_base_common.dart';
import '../../src/bindings/7.0/generated_bindings_capi_content_media_content.dart';
import '../../src/bindings/7.0/generated_bindings_capi_content_mime_type.dart';
import '../../src/bindings/7.0/generated_bindings_capi_context.dart';
import '../../src/bindings/7.0/generated_bindings_capi_geofence_manager.dart';
import '../../src/bindings/7.0/generated_bindings_capi_location_manager.dart';
import '../../src/bindings/7.0/generated_bindings_capi_media_audio_io.dart';
import '../../src/bindings/7.0/generated_bindings_capi_media_camera.dart';
import '../../src/bindings/7.0/generated_bindings_capi_media_codec.dart';
import '../../src/bindings/7.0/generated_bindings_capi_media_controller.dart';
import '../../src/bindings/7.0/generated_bindings_capi_media_editor.dart';
import '../../src/bindings/7.0/generated_bindings_capi_media_image_util.dart';
import '../../src/bindings/7.0/generated_bindings_capi_media_metadata_editor.dart';
import '../../src/bindings/7.0/generated_bindings_capi_media_metadata_extractor.dart';
import '../../src/bindings/7.0/generated_bindings_capi_media_player.dart';
import '../../src/bindings/7.0/generated_bindings_capi_media_radio.dart';
import '../../src/bindings/7.0/generated_bindings_capi_media_recorder.dart';
import '../../src/bindings/7.0/generated_bindings_capi_media_screen_mirroring.dart';
import '../../src/bindings/7.0/generated_bindings_capi_media_sound_manager.dart';
import '../../src/bindings/7.0/generated_bindings_capi_media_sound_pool.dart';
import '../../src/bindings/7.0/generated_bindings_capi_media_streamer.dart';
import '../../src/bindings/7.0/generated_bindings_capi_media_streamrecorder.dart';
import '../../src/bindings/7.0/generated_bindings_capi_media_thumbnail_util.dart';
import '../../src/bindings/7.0/generated_bindings_capi_media_tone_player.dart';
import '../../src/bindings/7.0/generated_bindings_capi_media_tool.dart';
import '../../src/bindings/7.0/generated_bindings_capi_media_wav_player.dart';
import '../../src/bindings/7.0/generated_bindings_capi_media_webrtc.dart';
import '../../src/bindings/7.0/generated_bindings_capi_mediademuxer.dart';
import '../../src/bindings/7.0/generated_bindings_capi_mediamuxer.dart';
import '../../src/bindings/7.0/generated_bindings_capi_messaging_email.dart';
import '../../src/bindings/7.0/generated_bindings_capi_ml_common.dart';
import '../../src/bindings/7.0/generated_bindings_capi_ml_inference_single.dart';
import '../../src/bindings/7.0/generated_bindings_capi_ml_service.dart';
import '../../src/bindings/7.0/generated_bindings_capi_network_bluetooth.dart';
import '../../src/bindings/7.0/generated_bindings_capi_network_connection.dart';
import '../../src/bindings/7.0/generated_bindings_capi_network_http.dart';
import '../../src/bindings/7.0/generated_bindings_capi_network_inm.dart';
import '../../src/bindings/7.0/generated_bindings_capi_network_mtp.dart';
import '../../src/bindings/7.0/generated_bindings_capi_network_softap.dart';
import '../../src/bindings/7.0/generated_bindings_capi_network_stc.dart';
import '../../src/bindings/7.0/generated_bindings_capi_network_wifi_manager.dart';
import '../../src/bindings/7.0/generated_bindings_capi_nnstreamer.dart';
import '../../src/bindings/7.0/generated_bindings_capi_nntrainer.dart';
import '../../src/bindings/7.0/generated_bindings_capi_privacy_privilege_manager.dart';
import '../../src/bindings/7.0/generated_bindings_capi_system_device.dart';
import '../../src/bindings/7.0/generated_bindings_capi_system_info.dart';
import '../../src/bindings/7.0/generated_bindings_capi_system_media_key.dart';
import '../../src/bindings/7.0/generated_bindings_capi_system_peripheral_io.dart';
import '../../src/bindings/7.0/generated_bindings_capi_system_resource_monitor.dart';
import '../../src/bindings/7.0/generated_bindings_capi_system_runtime_info.dart';
import '../../src/bindings/7.0/generated_bindings_capi_system_sensor.dart';
import '../../src/bindings/7.0/generated_bindings_capi_system_system_settings.dart';
import '../../src/bindings/7.0/generated_bindings_capi_system_usbhost.dart';
import '../../src/bindings/7.0/generated_bindings_capi_ui_autofill.dart';
import '../../src/bindings/7.0/generated_bindings_capi_ui_autofill_common.dart';
import '../../src/bindings/7.0/generated_bindings_capi_ui_autofill_manager.dart';
import '../../src/bindings/7.0/generated_bindings_capi_ui_autofill_service.dart';
import '../../src/bindings/7.0/generated_bindings_capi_ui_inputmethod.dart';
import '../../src/bindings/7.0/generated_bindings_capi_ui_inputmethod_manager.dart';
import '../../src/bindings/7.0/generated_bindings_capi_vpnsvc.dart';
import '../../src/bindings/7.0/generated_bindings_capi_web_url_download.dart';
import '../../src/bindings/7.0/generated_bindings_cbhm.dart';
import '../../src/bindings/7.0/generated_bindings_cion.dart';
import '../../src/bindings/7.0/generated_bindings_contacts_service2.dart';
import '../../src/bindings/7.0/generated_bindings_core_sync_client.dart';
import '../../src/bindings/7.0/generated_bindings_csr_client.dart';
import '../../src/bindings/7.0/generated_bindings_data_control.dart';
import '../../src/bindings/7.0/generated_bindings_device_certificate_manager.dart';
import '../../src/bindings/7.0/generated_bindings_diagnostics.dart';
import '../../src/bindings/7.0/generated_bindings_dlog.dart';
import '../../src/bindings/7.0/generated_bindings_dpm.dart';
import '../../src/bindings/7.0/generated_bindings_eom.dart';
import '../../src/bindings/7.0/generated_bindings_feedback.dart';
import '../../src/bindings/7.0/generated_bindings_fido_client.dart';
import '../../src/bindings/7.0/generated_bindings_iotcon.dart';
import '../../src/bindings/7.0/generated_bindings_key_manager_client.dart';
import '../../src/bindings/7.0/generated_bindings_ma.dart';
import '../../src/bindings/7.0/generated_bindings_message_port.dart';
import '../../src/bindings/7.0/generated_bindings_mv_3d.dart';
import '../../src/bindings/7.0/generated_bindings_mv_barcode_detector.dart';
import '../../src/bindings/7.0/generated_bindings_mv_barcode_generator.dart';
import '../../src/bindings/7.0/generated_bindings_mv_common.dart';
import '../../src/bindings/7.0/generated_bindings_mv_face.dart';
import '../../src/bindings/7.0/generated_bindings_mv_face_recognition.dart';
import '../../src/bindings/7.0/generated_bindings_mv_image.dart';
import '../../src/bindings/7.0/generated_bindings_mv_inference.dart';
import '../../src/bindings/7.0/generated_bindings_mv_roi_tracker.dart';
import '../../src/bindings/7.0/generated_bindings_mv_surveillance.dart';
import '../../src/bindings/7.0/generated_bindings_notification.dart';
import '../../src/bindings/7.0/generated_bindings_notification_ex.dart';
import '../../src/bindings/7.0/generated_bindings_nsd_dns_sd.dart';
import '../../src/bindings/7.0/generated_bindings_nsd_ssdp.dart';
import '../../src/bindings/7.0/generated_bindings_oauth2.dart';
import '../../src/bindings/7.0/generated_bindings_phonenumber_utils.dart';
import '../../src/bindings/7.0/generated_bindings_privilege_info.dart';
import '../../src/bindings/7.0/generated_bindings_push.dart';
import '../../src/bindings/7.0/generated_bindings_rpc_port.dart';
import '../../src/bindings/7.0/generated_bindings_storage.dart';
import '../../src/bindings/7.0/generated_bindings_stt.dart';
import '../../src/bindings/7.0/generated_bindings_stt_engine.dart';
import '../../src/bindings/7.0/generated_bindings_tbm.dart';
import '../../src/bindings/7.0/generated_bindings_ttrace.dart';
import '../../src/bindings/7.0/generated_bindings_tts.dart';
import '../../src/bindings/7.0/generated_bindings_tts_engine.dart';
import '../../src/bindings/7.0/generated_bindings_update_control.dart';
import '../../src/bindings/7.0/generated_bindings_vc.dart';
import '../../src/bindings/7.0/generated_bindings_vc_engine.dart';
import '../../src/bindings/7.0/generated_bindings_vc_manager.dart';
import '../../src/bindings/7.0/generated_bindings_wifi_direct.dart';
import '../../src/bindings/7.0/generated_bindings_yaca.dart';
import '../../src/lookup_provider.dart';

export '../../src/extensions.dart';
export '../../src/bindings/7.0/generated_bindings_accounts_svc.dart';
export '../../src/bindings/7.0/generated_bindings_appcore_agent.dart';
export '../../src/bindings/7.0/generated_bindings_asp.dart';
export '../../src/bindings/7.0/generated_bindings_badge.dart';
export '../../src/bindings/7.0/generated_bindings_bundle.dart';
export '../../src/bindings/7.0/generated_bindings_calendar_service2.dart';
export '../../src/bindings/7.0/generated_bindings_capi_appfw_alarm.dart';
export '../../src/bindings/7.0/generated_bindings_capi_appfw_app_common.dart';
export '../../src/bindings/7.0/generated_bindings_capi_appfw_app_control.dart';
export '../../src/bindings/7.0/generated_bindings_capi_appfw_app_control_uri.dart';
export '../../src/bindings/7.0/generated_bindings_capi_appfw_app_manager.dart';
export '../../src/bindings/7.0/generated_bindings_capi_appfw_application.dart';
export '../../src/bindings/7.0/generated_bindings_capi_appfw_event.dart';
export '../../src/bindings/7.0/generated_bindings_capi_appfw_job_scheduler.dart';
export '../../src/bindings/7.0/generated_bindings_capi_appfw_package_manager.dart';
export '../../src/bindings/7.0/generated_bindings_capi_appfw_preference.dart';
export '../../src/bindings/7.0/generated_bindings_capi_base_common.dart';
export '../../src/bindings/7.0/generated_bindings_capi_content_media_content.dart';
export '../../src/bindings/7.0/generated_bindings_capi_content_mime_type.dart';
export '../../src/bindings/7.0/generated_bindings_capi_context.dart';
export '../../src/bindings/7.0/generated_bindings_capi_geofence_manager.dart';
export '../../src/bindings/7.0/generated_bindings_capi_location_manager.dart';
export '../../src/bindings/7.0/generated_bindings_capi_media_audio_io.dart';
export '../../src/bindings/7.0/generated_bindings_capi_media_camera.dart'
    hide UnnamedStruct1, UnnamedUnion1;
export '../../src/bindings/7.0/generated_bindings_capi_media_codec.dart';
export '../../src/bindings/7.0/generated_bindings_capi_media_controller.dart';
export '../../src/bindings/7.0/generated_bindings_capi_media_editor.dart';
export '../../src/bindings/7.0/generated_bindings_capi_media_image_util.dart';
export '../../src/bindings/7.0/generated_bindings_capi_media_metadata_editor.dart';
export '../../src/bindings/7.0/generated_bindings_capi_media_metadata_extractor.dart';
export '../../src/bindings/7.0/generated_bindings_capi_media_player.dart';
export '../../src/bindings/7.0/generated_bindings_capi_media_radio.dart';
export '../../src/bindings/7.0/generated_bindings_capi_media_recorder.dart';
export '../../src/bindings/7.0/generated_bindings_capi_media_screen_mirroring.dart';
export '../../src/bindings/7.0/generated_bindings_capi_media_sound_manager.dart';
export '../../src/bindings/7.0/generated_bindings_capi_media_sound_pool.dart';
export '../../src/bindings/7.0/generated_bindings_capi_media_streamer.dart';
export '../../src/bindings/7.0/generated_bindings_capi_media_streamrecorder.dart';
export '../../src/bindings/7.0/generated_bindings_capi_media_thumbnail_util.dart';
export '../../src/bindings/7.0/generated_bindings_capi_media_tone_player.dart';
export '../../src/bindings/7.0/generated_bindings_capi_media_tool.dart';
export '../../src/bindings/7.0/generated_bindings_capi_media_wav_player.dart';
export '../../src/bindings/7.0/generated_bindings_capi_media_webrtc.dart'
    hide UnnamedUnion1;
export '../../src/bindings/7.0/generated_bindings_capi_mediademuxer.dart';
export '../../src/bindings/7.0/generated_bindings_capi_mediamuxer.dart';
export '../../src/bindings/7.0/generated_bindings_capi_messaging_email.dart';
export '../../src/bindings/7.0/generated_bindings_capi_ml_common.dart';
export '../../src/bindings/7.0/generated_bindings_capi_ml_inference_single.dart';
export '../../src/bindings/7.0/generated_bindings_capi_ml_service.dart';
export '../../src/bindings/7.0/generated_bindings_capi_network_bluetooth.dart';
export '../../src/bindings/7.0/generated_bindings_capi_network_connection.dart';
export '../../src/bindings/7.0/generated_bindings_capi_network_http.dart';
export '../../src/bindings/7.0/generated_bindings_capi_network_inm.dart';
export '../../src/bindings/7.0/generated_bindings_capi_network_mtp.dart';
export '../../src/bindings/7.0/generated_bindings_capi_network_softap.dart';
export '../../src/bindings/7.0/generated_bindings_capi_network_stc.dart';
export '../../src/bindings/7.0/generated_bindings_capi_network_wifi_manager.dart';
export '../../src/bindings/7.0/generated_bindings_capi_nnstreamer.dart';
export '../../src/bindings/7.0/generated_bindings_capi_nntrainer.dart';
export '../../src/bindings/7.0/generated_bindings_capi_privacy_privilege_manager.dart';
export '../../src/bindings/7.0/generated_bindings_capi_system_device.dart';
export '../../src/bindings/7.0/generated_bindings_capi_system_info.dart';
export '../../src/bindings/7.0/generated_bindings_capi_system_media_key.dart';
export '../../src/bindings/7.0/generated_bindings_capi_system_peripheral_io.dart';
export '../../src/bindings/7.0/generated_bindings_capi_system_resource_monitor.dart';
export '../../src/bindings/7.0/generated_bindings_capi_system_runtime_info.dart';
export '../../src/bindings/7.0/generated_bindings_capi_system_sensor.dart';
export '../../src/bindings/7.0/generated_bindings_capi_system_system_settings.dart';
export '../../src/bindings/7.0/generated_bindings_capi_system_usbhost.dart';
export '../../src/bindings/7.0/generated_bindings_capi_ui_autofill.dart';
export '../../src/bindings/7.0/generated_bindings_capi_ui_autofill_common.dart';
export '../../src/bindings/7.0/generated_bindings_capi_ui_autofill_manager.dart';
export '../../src/bindings/7.0/generated_bindings_capi_ui_autofill_service.dart';
export '../../src/bindings/7.0/generated_bindings_capi_ui_inputmethod.dart';
export '../../src/bindings/7.0/generated_bindings_capi_ui_inputmethod_manager.dart';
export '../../src/bindings/7.0/generated_bindings_capi_vpnsvc.dart';
export '../../src/bindings/7.0/generated_bindings_capi_web_url_download.dart';
export '../../src/bindings/7.0/generated_bindings_cbhm.dart';
export '../../src/bindings/7.0/generated_bindings_cion.dart';
export '../../src/bindings/7.0/generated_bindings_contacts_service2.dart';
export '../../src/bindings/7.0/generated_bindings_core_sync_client.dart';
export '../../src/bindings/7.0/generated_bindings_csr_client.dart';
export '../../src/bindings/7.0/generated_bindings_data_control.dart';
export '../../src/bindings/7.0/generated_bindings_device_certificate_manager.dart';
export '../../src/bindings/7.0/generated_bindings_diagnostics.dart';
export '../../src/bindings/7.0/generated_bindings_dlog.dart';
export '../../src/bindings/7.0/generated_bindings_dpm.dart';
export '../../src/bindings/7.0/generated_bindings_eom.dart';
export '../../src/bindings/7.0/generated_bindings_feedback.dart';
export '../../src/bindings/7.0/generated_bindings_fido_client.dart';
export '../../src/bindings/7.0/generated_bindings_iotcon.dart';
export '../../src/bindings/7.0/generated_bindings_key_manager_client.dart';
export '../../src/bindings/7.0/generated_bindings_ma.dart';
export '../../src/bindings/7.0/generated_bindings_message_port.dart';
export '../../src/bindings/7.0/generated_bindings_mv_3d.dart';
export '../../src/bindings/7.0/generated_bindings_mv_barcode_detector.dart';
export '../../src/bindings/7.0/generated_bindings_mv_barcode_generator.dart';
export '../../src/bindings/7.0/generated_bindings_mv_common.dart';
export '../../src/bindings/7.0/generated_bindings_mv_face.dart';
export '../../src/bindings/7.0/generated_bindings_mv_face_recognition.dart';
export '../../src/bindings/7.0/generated_bindings_mv_image.dart';
export '../../src/bindings/7.0/generated_bindings_mv_inference.dart';
export '../../src/bindings/7.0/generated_bindings_mv_roi_tracker.dart';
export '../../src/bindings/7.0/generated_bindings_mv_surveillance.dart';
export '../../src/bindings/7.0/generated_bindings_notification.dart';
export '../../src/bindings/7.0/generated_bindings_notification_ex.dart';
export '../../src/bindings/7.0/generated_bindings_nsd_dns_sd.dart';
export '../../src/bindings/7.0/generated_bindings_nsd_ssdp.dart';
export '../../src/bindings/7.0/generated_bindings_oauth2.dart';
export '../../src/bindings/7.0/generated_bindings_phonenumber_utils.dart';
export '../../src/bindings/7.0/generated_bindings_privilege_info.dart';
export '../../src/bindings/7.0/generated_bindings_push.dart';
export '../../src/bindings/7.0/generated_bindings_rpc_port.dart';
export '../../src/bindings/7.0/generated_bindings_storage.dart';
export '../../src/bindings/7.0/generated_bindings_stt.dart';
export '../../src/bindings/7.0/generated_bindings_stt_engine.dart';
export '../../src/bindings/7.0/generated_bindings_tbm.dart';
export '../../src/bindings/7.0/generated_bindings_ttrace.dart';
export '../../src/bindings/7.0/generated_bindings_tts.dart';
export '../../src/bindings/7.0/generated_bindings_tts_engine.dart';
export '../../src/bindings/7.0/generated_bindings_update_control.dart';
export '../../src/bindings/7.0/generated_bindings_vc.dart';
export '../../src/bindings/7.0/generated_bindings_vc_engine.dart';
export '../../src/bindings/7.0/generated_bindings_vc_manager.dart';
export '../../src/bindings/7.0/generated_bindings_wifi_direct.dart';
export '../../src/bindings/7.0/generated_bindings_yaca.dart';
export '../../src/bindings/7.0/generated_bindings_time.dart'
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

Tizen70AccountsSvc? _tizenAccountsSvc;
Tizen70AccountsSvc get tizenAccountsSvc => _tizenAccountsSvc ??=
    _getTizenInstance(accountsSvcSymbols, Tizen70AccountsSvc.fromLookup)!;

Tizen70AppcoreAgent? _tizenAppcoreAgent;
Tizen70AppcoreAgent get tizenAppcoreAgent => _tizenAppcoreAgent ??=
    _getTizenInstance(appcoreAgentSymbols, Tizen70AppcoreAgent.fromLookup)!;

Tizen70Asp? _tizenAsp;
Tizen70Asp get tizenAsp =>
    _tizenAsp ??= _getTizenInstance(aspSymbols, Tizen70Asp.fromLookup)!;

Tizen70Badge? _tizenBadge;
Tizen70Badge get tizenBadge =>
    _tizenBadge ??= _getTizenInstance(badgeSymbols, Tizen70Badge.fromLookup)!;

Tizen70Bundle? _tizenBundle;
Tizen70Bundle get tizenBundle => _tizenBundle ??=
    _getTizenInstance(bundleSymbols, Tizen70Bundle.fromLookup)!;

Tizen70CalendarService2? _tizenCalendarService2;
Tizen70CalendarService2 get tizenCalendarService2 =>
    _tizenCalendarService2 ??= _getTizenInstance(
        calendarService2Symbols, Tizen70CalendarService2.fromLookup)!;

Tizen70CapiAppfwAlarm? _tizenCapiAppfwAlarm;
Tizen70CapiAppfwAlarm get tizenCapiAppfwAlarm => _tizenCapiAppfwAlarm ??=
    _getTizenInstance(capiAppfwAlarmSymbols, Tizen70CapiAppfwAlarm.fromLookup)!;

Tizen70CapiAppfwAppCommon? _tizenCapiAppfwAppCommon;
Tizen70CapiAppfwAppCommon get tizenCapiAppfwAppCommon =>
    _tizenCapiAppfwAppCommon ??= _getTizenInstance(
        capiAppfwAppCommonSymbols, Tizen70CapiAppfwAppCommon.fromLookup)!;

Tizen70CapiAppfwAppControl? _tizenCapiAppfwAppControl;
Tizen70CapiAppfwAppControl get tizenCapiAppfwAppControl =>
    _tizenCapiAppfwAppControl ??= _getTizenInstance(
        capiAppfwAppControlSymbols, Tizen70CapiAppfwAppControl.fromLookup)!;

Tizen70CapiAppfwAppControlUri? _tizenCapiAppfwAppControlUri;
Tizen70CapiAppfwAppControlUri get tizenCapiAppfwAppControlUri =>
    _tizenCapiAppfwAppControlUri ??= _getTizenInstance(
        capiAppfwAppControlUriSymbols,
        Tizen70CapiAppfwAppControlUri.fromLookup)!;

Tizen70CapiAppfwAppManager? _tizenCapiAppfwAppManager;
Tizen70CapiAppfwAppManager get tizenCapiAppfwAppManager =>
    _tizenCapiAppfwAppManager ??= _getTizenInstance(
        capiAppfwAppManagerSymbols, Tizen70CapiAppfwAppManager.fromLookup)!;

Tizen70CapiAppfwApplication? _tizenCapiAppfwApplication;
Tizen70CapiAppfwApplication get tizenCapiAppfwApplication =>
    _tizenCapiAppfwApplication ??= _getTizenInstance(
        capiAppfwApplicationSymbols, Tizen70CapiAppfwApplication.fromLookup)!;

Tizen70CapiAppfwEvent? _tizenCapiAppfwEvent;
Tizen70CapiAppfwEvent get tizenCapiAppfwEvent => _tizenCapiAppfwEvent ??=
    _getTizenInstance(capiAppfwEventSymbols, Tizen70CapiAppfwEvent.fromLookup)!;

Tizen70CapiAppfwJobScheduler? _tizenCapiAppfwJobScheduler;
Tizen70CapiAppfwJobScheduler get tizenCapiAppfwJobScheduler =>
    _tizenCapiAppfwJobScheduler ??= _getTizenInstance(
        capiAppfwJobSchedulerSymbols, Tizen70CapiAppfwJobScheduler.fromLookup)!;

Tizen70CapiAppfwPackageManager? _tizenCapiAppfwPackageManager;
Tizen70CapiAppfwPackageManager get tizenCapiAppfwPackageManager =>
    _tizenCapiAppfwPackageManager ??= _getTizenInstance(
        capiAppfwPackageManagerSymbols,
        Tizen70CapiAppfwPackageManager.fromLookup)!;

Tizen70CapiAppfwPreference? _tizenCapiAppfwPreference;
Tizen70CapiAppfwPreference get tizenCapiAppfwPreference =>
    _tizenCapiAppfwPreference ??= _getTizenInstance(
        capiAppfwPreferenceSymbols, Tizen70CapiAppfwPreference.fromLookup)!;

Tizen70CapiBaseCommon? _tizenCapiBaseCommon;
Tizen70CapiBaseCommon get tizenCapiBaseCommon => _tizenCapiBaseCommon ??=
    _getTizenInstance(capiBaseCommonSymbols, Tizen70CapiBaseCommon.fromLookup)!;

Tizen70CapiContentMediaContent? _tizenCapiContentMediaContent;
Tizen70CapiContentMediaContent get tizenCapiContentMediaContent =>
    _tizenCapiContentMediaContent ??= _getTizenInstance(
        capiContentMediaContentSymbols,
        Tizen70CapiContentMediaContent.fromLookup)!;

Tizen70CapiContentMimeType? _tizenCapiContentMimeType;
Tizen70CapiContentMimeType get tizenCapiContentMimeType =>
    _tizenCapiContentMimeType ??= _getTizenInstance(
        capiContentMimeTypeSymbols, Tizen70CapiContentMimeType.fromLookup)!;

Tizen70CapiContext? _tizenCapiContext;
Tizen70CapiContext get tizenCapiContext => _tizenCapiContext ??=
    _getTizenInstance(capiContextSymbols, Tizen70CapiContext.fromLookup)!;

Tizen70CapiGeofenceManager? _tizenCapiGeofenceManager;
Tizen70CapiGeofenceManager get tizenCapiGeofenceManager =>
    _tizenCapiGeofenceManager ??= _getTizenInstance(
        capiGeofenceManagerSymbols, Tizen70CapiGeofenceManager.fromLookup)!;

Tizen70CapiLocationManager? _tizenCapiLocationManager;
Tizen70CapiLocationManager get tizenCapiLocationManager =>
    _tizenCapiLocationManager ??= _getTizenInstance(
        capiLocationManagerSymbols, Tizen70CapiLocationManager.fromLookup)!;

Tizen70CapiMediaAudioIo? _tizenCapiMediaAudioIo;
Tizen70CapiMediaAudioIo get tizenCapiMediaAudioIo =>
    _tizenCapiMediaAudioIo ??= _getTizenInstance(
        capiMediaAudioIoSymbols, Tizen70CapiMediaAudioIo.fromLookup)!;

Tizen70CapiMediaCamera? _tizenCapiMediaCamera;
Tizen70CapiMediaCamera get tizenCapiMediaCamera =>
    _tizenCapiMediaCamera ??= _getTizenInstance(
        capiMediaCameraSymbols, Tizen70CapiMediaCamera.fromLookup)!;

Tizen70CapiMediaCodec? _tizenCapiMediaCodec;
Tizen70CapiMediaCodec get tizenCapiMediaCodec => _tizenCapiMediaCodec ??=
    _getTizenInstance(capiMediaCodecSymbols, Tizen70CapiMediaCodec.fromLookup)!;

Tizen70CapiMediaController? _tizenCapiMediaController;
Tizen70CapiMediaController get tizenCapiMediaController =>
    _tizenCapiMediaController ??= _getTizenInstance(
        capiMediaControllerSymbols, Tizen70CapiMediaController.fromLookup)!;

Tizen70CapiMediaEditor? _tizenCapiMediaEditor;
Tizen70CapiMediaEditor get tizenCapiMediaEditor =>
    _tizenCapiMediaEditor ??= _getTizenInstance(
        capiMediaEditorSymbols, Tizen70CapiMediaEditor.fromLookup)!;

Tizen70CapiMediaImageUtil? _tizenCapiMediaImageUtil;
Tizen70CapiMediaImageUtil get tizenCapiMediaImageUtil =>
    _tizenCapiMediaImageUtil ??= _getTizenInstance(
        capiMediaImageUtilSymbols, Tizen70CapiMediaImageUtil.fromLookup)!;

Tizen70CapiMediaMetadataEditor? _tizenCapiMediaMetadataEditor;
Tizen70CapiMediaMetadataEditor get tizenCapiMediaMetadataEditor =>
    _tizenCapiMediaMetadataEditor ??= _getTizenInstance(
        capiMediaMetadataEditorSymbols,
        Tizen70CapiMediaMetadataEditor.fromLookup)!;

Tizen70CapiMediaMetadataExtractor? _tizenCapiMediaMetadataExtractor;
Tizen70CapiMediaMetadataExtractor get tizenCapiMediaMetadataExtractor =>
    _tizenCapiMediaMetadataExtractor ??= _getTizenInstance(
        capiMediaMetadataExtractorSymbols,
        Tizen70CapiMediaMetadataExtractor.fromLookup)!;

Tizen70CapiMediaPlayer? _tizenCapiMediaPlayer;
Tizen70CapiMediaPlayer get tizenCapiMediaPlayer =>
    _tizenCapiMediaPlayer ??= _getTizenInstance(
        capiMediaPlayerSymbols, Tizen70CapiMediaPlayer.fromLookup)!;

Tizen70CapiMediaRadio? _tizenCapiMediaRadio;
Tizen70CapiMediaRadio get tizenCapiMediaRadio => _tizenCapiMediaRadio ??=
    _getTizenInstance(capiMediaRadioSymbols, Tizen70CapiMediaRadio.fromLookup)!;

Tizen70CapiMediaRecorder? _tizenCapiMediaRecorder;
Tizen70CapiMediaRecorder get tizenCapiMediaRecorder =>
    _tizenCapiMediaRecorder ??= _getTizenInstance(
        capiMediaRecorderSymbols, Tizen70CapiMediaRecorder.fromLookup)!;

Tizen70CapiMediaScreenMirroring? _tizenCapiMediaScreenMirroring;
Tizen70CapiMediaScreenMirroring get tizenCapiMediaScreenMirroring =>
    _tizenCapiMediaScreenMirroring ??= _getTizenInstance(
        capiMediaScreenMirroringSymbols,
        Tizen70CapiMediaScreenMirroring.fromLookup)!;

Tizen70CapiMediaSoundManager? _tizenCapiMediaSoundManager;
Tizen70CapiMediaSoundManager get tizenCapiMediaSoundManager =>
    _tizenCapiMediaSoundManager ??= _getTizenInstance(
        capiMediaSoundManagerSymbols, Tizen70CapiMediaSoundManager.fromLookup)!;

Tizen70CapiMediaSoundPool? _tizenCapiMediaSoundPool;
Tizen70CapiMediaSoundPool get tizenCapiMediaSoundPool =>
    _tizenCapiMediaSoundPool ??= _getTizenInstance(
        capiMediaSoundPoolSymbols, Tizen70CapiMediaSoundPool.fromLookup)!;

Tizen70CapiMediaStreamer? _tizenCapiMediaStreamer;
Tizen70CapiMediaStreamer get tizenCapiMediaStreamer =>
    _tizenCapiMediaStreamer ??= _getTizenInstance(
        capiMediaStreamerSymbols, Tizen70CapiMediaStreamer.fromLookup)!;

Tizen70CapiMediaStreamrecorder? _tizenCapiMediaStreamrecorder;
Tizen70CapiMediaStreamrecorder get tizenCapiMediaStreamrecorder =>
    _tizenCapiMediaStreamrecorder ??= _getTizenInstance(
        capiMediaStreamrecorderSymbols,
        Tizen70CapiMediaStreamrecorder.fromLookup)!;

Tizen70CapiMediaThumbnailUtil? _tizenCapiMediaThumbnailUtil;
Tizen70CapiMediaThumbnailUtil get tizenCapiMediaThumbnailUtil =>
    _tizenCapiMediaThumbnailUtil ??= _getTizenInstance(
        capiMediaThumbnailUtilSymbols,
        Tizen70CapiMediaThumbnailUtil.fromLookup)!;

Tizen70CapiMediaTonePlayer? _tizenCapiMediaTonePlayer;
Tizen70CapiMediaTonePlayer get tizenCapiMediaTonePlayer =>
    _tizenCapiMediaTonePlayer ??= _getTizenInstance(
        capiMediaTonePlayerSymbols, Tizen70CapiMediaTonePlayer.fromLookup)!;

Tizen70CapiMediaTool? _tizenCapiMediaTool;
Tizen70CapiMediaTool get tizenCapiMediaTool => _tizenCapiMediaTool ??=
    _getTizenInstance(capiMediaToolSymbols, Tizen70CapiMediaTool.fromLookup)!;

Tizen70CapiMediaWavPlayer? _tizenCapiMediaWavPlayer;
Tizen70CapiMediaWavPlayer get tizenCapiMediaWavPlayer =>
    _tizenCapiMediaWavPlayer ??= _getTizenInstance(
        capiMediaWavPlayerSymbols, Tizen70CapiMediaWavPlayer.fromLookup)!;

Tizen70CapiMediaWebrtc? _tizenCapiMediaWebrtc;
Tizen70CapiMediaWebrtc get tizenCapiMediaWebrtc =>
    _tizenCapiMediaWebrtc ??= _getTizenInstance(
        capiMediaWebrtcSymbols, Tizen70CapiMediaWebrtc.fromLookup)!;

Tizen70CapiMediademuxer? _tizenCapiMediademuxer;
Tizen70CapiMediademuxer get tizenCapiMediademuxer =>
    _tizenCapiMediademuxer ??= _getTizenInstance(
        capiMediademuxerSymbols, Tizen70CapiMediademuxer.fromLookup)!;

Tizen70CapiMediamuxer? _tizenCapiMediamuxer;
Tizen70CapiMediamuxer get tizenCapiMediamuxer => _tizenCapiMediamuxer ??=
    _getTizenInstance(capiMediamuxerSymbols, Tizen70CapiMediamuxer.fromLookup)!;

Tizen70CapiMessagingEmail? _tizenCapiMessagingEmail;
Tizen70CapiMessagingEmail get tizenCapiMessagingEmail =>
    _tizenCapiMessagingEmail ??= _getTizenInstance(
        capiMessagingEmailSymbols, Tizen70CapiMessagingEmail.fromLookup)!;

Tizen70CapiMlCommon? _tizenCapiMlCommon;
Tizen70CapiMlCommon get tizenCapiMlCommon => _tizenCapiMlCommon ??=
    _getTizenInstance(capiMlCommonSymbols, Tizen70CapiMlCommon.fromLookup)!;

Tizen70CapiMlInferenceSingle? _tizenCapiMlInferenceSingle;
Tizen70CapiMlInferenceSingle get tizenCapiMlInferenceSingle =>
    _tizenCapiMlInferenceSingle ??= _getTizenInstance(
        capiMlInferenceSingleSymbols, Tizen70CapiMlInferenceSingle.fromLookup)!;

Tizen70CapiMlService? _tizenCapiMlService;
Tizen70CapiMlService get tizenCapiMlService => _tizenCapiMlService ??=
    _getTizenInstance(capiMlServiceSymbols, Tizen70CapiMlService.fromLookup)!;

Tizen70CapiNetworkBluetooth? _tizenCapiNetworkBluetooth;
Tizen70CapiNetworkBluetooth get tizenCapiNetworkBluetooth =>
    _tizenCapiNetworkBluetooth ??= _getTizenInstance(
        capiNetworkBluetoothSymbols, Tizen70CapiNetworkBluetooth.fromLookup)!;

Tizen70CapiNetworkConnection? _tizenCapiNetworkConnection;
Tizen70CapiNetworkConnection get tizenCapiNetworkConnection =>
    _tizenCapiNetworkConnection ??= _getTizenInstance(
        capiNetworkConnectionSymbols, Tizen70CapiNetworkConnection.fromLookup)!;

Tizen70CapiNetworkHttp? _tizenCapiNetworkHttp;
Tizen70CapiNetworkHttp get tizenCapiNetworkHttp =>
    _tizenCapiNetworkHttp ??= _getTizenInstance(
        capiNetworkHttpSymbols, Tizen70CapiNetworkHttp.fromLookup)!;

Tizen70CapiNetworkInm? _tizenCapiNetworkInm;
Tizen70CapiNetworkInm get tizenCapiNetworkInm => _tizenCapiNetworkInm ??=
    _getTizenInstance(capiNetworkInmSymbols, Tizen70CapiNetworkInm.fromLookup)!;

Tizen70CapiNetworkMtp? _tizenCapiNetworkMtp;
Tizen70CapiNetworkMtp get tizenCapiNetworkMtp => _tizenCapiNetworkMtp ??=
    _getTizenInstance(capiNetworkMtpSymbols, Tizen70CapiNetworkMtp.fromLookup)!;

Tizen70CapiNetworkSoftap? _tizenCapiNetworkSoftap;
Tizen70CapiNetworkSoftap get tizenCapiNetworkSoftap =>
    _tizenCapiNetworkSoftap ??= _getTizenInstance(
        capiNetworkSoftapSymbols, Tizen70CapiNetworkSoftap.fromLookup)!;

Tizen70CapiNetworkStc? _tizenCapiNetworkStc;
Tizen70CapiNetworkStc get tizenCapiNetworkStc => _tizenCapiNetworkStc ??=
    _getTizenInstance(capiNetworkStcSymbols, Tizen70CapiNetworkStc.fromLookup)!;

Tizen70CapiNetworkWifiManager? _tizenCapiNetworkWifiManager;
Tizen70CapiNetworkWifiManager get tizenCapiNetworkWifiManager =>
    _tizenCapiNetworkWifiManager ??= _getTizenInstance(
        capiNetworkWifiManagerSymbols,
        Tizen70CapiNetworkWifiManager.fromLookup)!;

Tizen70CapiNnstreamer? _tizenCapiNnstreamer;
Tizen70CapiNnstreamer get tizenCapiNnstreamer => _tizenCapiNnstreamer ??=
    _getTizenInstance(capiNnstreamerSymbols, Tizen70CapiNnstreamer.fromLookup)!;

Tizen70CapiNntrainer? _tizenCapiNntrainer;
Tizen70CapiNntrainer get tizenCapiNntrainer => _tizenCapiNntrainer ??=
    _getTizenInstance(capiNntrainerSymbols, Tizen70CapiNntrainer.fromLookup)!;

Tizen70CapiPrivacyPrivilegeManager? _tizenCapiPrivacyPrivilegeManager;
Tizen70CapiPrivacyPrivilegeManager get tizenCapiPrivacyPrivilegeManager =>
    _tizenCapiPrivacyPrivilegeManager ??= _getTizenInstance(
        capiPrivacyPrivilegeManagerSymbols,
        Tizen70CapiPrivacyPrivilegeManager.fromLookup)!;

Tizen70CapiSystemDevice? _tizenCapiSystemDevice;
Tizen70CapiSystemDevice get tizenCapiSystemDevice =>
    _tizenCapiSystemDevice ??= _getTizenInstance(
        capiSystemDeviceSymbols, Tizen70CapiSystemDevice.fromLookup)!;

Tizen70CapiSystemInfo? _tizenCapiSystemInfo;
Tizen70CapiSystemInfo get tizenCapiSystemInfo => _tizenCapiSystemInfo ??=
    _getTizenInstance(capiSystemInfoSymbols, Tizen70CapiSystemInfo.fromLookup)!;

Tizen70CapiSystemMediaKey? _tizenCapiSystemMediaKey;
Tizen70CapiSystemMediaKey get tizenCapiSystemMediaKey =>
    _tizenCapiSystemMediaKey ??= _getTizenInstance(
        capiSystemMediaKeySymbols, Tizen70CapiSystemMediaKey.fromLookup)!;

Tizen70CapiSystemPeripheralIo? _tizenCapiSystemPeripheralIo;
Tizen70CapiSystemPeripheralIo get tizenCapiSystemPeripheralIo =>
    _tizenCapiSystemPeripheralIo ??= _getTizenInstance(
        capiSystemPeripheralIoSymbols,
        Tizen70CapiSystemPeripheralIo.fromLookup)!;

Tizen70CapiSystemResourceMonitor? _tizenCapiSystemResourceMonitor;
Tizen70CapiSystemResourceMonitor get tizenCapiSystemResourceMonitor =>
    _tizenCapiSystemResourceMonitor ??= _getTizenInstance(
        capiSystemResourceMonitorSymbols,
        Tizen70CapiSystemResourceMonitor.fromLookup)!;

Tizen70CapiSystemRuntimeInfo? _tizenCapiSystemRuntimeInfo;
Tizen70CapiSystemRuntimeInfo get tizenCapiSystemRuntimeInfo =>
    _tizenCapiSystemRuntimeInfo ??= _getTizenInstance(
        capiSystemRuntimeInfoSymbols, Tizen70CapiSystemRuntimeInfo.fromLookup)!;

Tizen70CapiSystemSensor? _tizenCapiSystemSensor;
Tizen70CapiSystemSensor get tizenCapiSystemSensor =>
    _tizenCapiSystemSensor ??= _getTizenInstance(
        capiSystemSensorSymbols, Tizen70CapiSystemSensor.fromLookup)!;

Tizen70CapiSystemSystemSettings? _tizenCapiSystemSystemSettings;
Tizen70CapiSystemSystemSettings get tizenCapiSystemSystemSettings =>
    _tizenCapiSystemSystemSettings ??= _getTizenInstance(
        capiSystemSystemSettingsSymbols,
        Tizen70CapiSystemSystemSettings.fromLookup)!;

Tizen70CapiSystemUsbhost? _tizenCapiSystemUsbhost;
Tizen70CapiSystemUsbhost get tizenCapiSystemUsbhost =>
    _tizenCapiSystemUsbhost ??= _getTizenInstance(
        capiSystemUsbhostSymbols, Tizen70CapiSystemUsbhost.fromLookup)!;

Tizen70CapiUiAutofill? _tizenCapiUiAutofill;
Tizen70CapiUiAutofill get tizenCapiUiAutofill => _tizenCapiUiAutofill ??=
    _getTizenInstance(capiUiAutofillSymbols, Tizen70CapiUiAutofill.fromLookup)!;

Tizen70CapiUiAutofillCommon? _tizenCapiUiAutofillCommon;
Tizen70CapiUiAutofillCommon get tizenCapiUiAutofillCommon =>
    _tizenCapiUiAutofillCommon ??= _getTizenInstance(
        capiUiAutofillCommonSymbols, Tizen70CapiUiAutofillCommon.fromLookup)!;

Tizen70CapiUiAutofillManager? _tizenCapiUiAutofillManager;
Tizen70CapiUiAutofillManager get tizenCapiUiAutofillManager =>
    _tizenCapiUiAutofillManager ??= _getTizenInstance(
        capiUiAutofillManagerSymbols, Tizen70CapiUiAutofillManager.fromLookup)!;

Tizen70CapiUiAutofillService? _tizenCapiUiAutofillService;
Tizen70CapiUiAutofillService get tizenCapiUiAutofillService =>
    _tizenCapiUiAutofillService ??= _getTizenInstance(
        capiUiAutofillServiceSymbols, Tizen70CapiUiAutofillService.fromLookup)!;

Tizen70CapiUiInputmethod? _tizenCapiUiInputmethod;
Tizen70CapiUiInputmethod get tizenCapiUiInputmethod =>
    _tizenCapiUiInputmethod ??= _getTizenInstance(
        capiUiInputmethodSymbols, Tizen70CapiUiInputmethod.fromLookup)!;

Tizen70CapiUiInputmethodManager? _tizenCapiUiInputmethodManager;
Tizen70CapiUiInputmethodManager get tizenCapiUiInputmethodManager =>
    _tizenCapiUiInputmethodManager ??= _getTizenInstance(
        capiUiInputmethodManagerSymbols,
        Tizen70CapiUiInputmethodManager.fromLookup)!;

Tizen70CapiVpnsvc? _tizenCapiVpnsvc;
Tizen70CapiVpnsvc get tizenCapiVpnsvc => _tizenCapiVpnsvc ??=
    _getTizenInstance(capiVpnsvcSymbols, Tizen70CapiVpnsvc.fromLookup)!;

Tizen70CapiWebUrlDownload? _tizenCapiWebUrlDownload;
Tizen70CapiWebUrlDownload get tizenCapiWebUrlDownload =>
    _tizenCapiWebUrlDownload ??= _getTizenInstance(
        capiWebUrlDownloadSymbols, Tizen70CapiWebUrlDownload.fromLookup)!;

Tizen70Cbhm? _tizenCbhm;
Tizen70Cbhm get tizenCbhm =>
    _tizenCbhm ??= _getTizenInstance(cbhmSymbols, Tizen70Cbhm.fromLookup)!;

Tizen70Cion? _tizenCion;
Tizen70Cion get tizenCion =>
    _tizenCion ??= _getTizenInstance(cionSymbols, Tizen70Cion.fromLookup)!;

Tizen70ContactsService2? _tizenContactsService2;
Tizen70ContactsService2 get tizenContactsService2 =>
    _tizenContactsService2 ??= _getTizenInstance(
        contactsService2Symbols, Tizen70ContactsService2.fromLookup)!;

Tizen70CoreSyncClient? _tizenCoreSyncClient;
Tizen70CoreSyncClient get tizenCoreSyncClient => _tizenCoreSyncClient ??=
    _getTizenInstance(coreSyncClientSymbols, Tizen70CoreSyncClient.fromLookup)!;

Tizen70CsrClient? _tizenCsrClient;
Tizen70CsrClient get tizenCsrClient => _tizenCsrClient ??=
    _getTizenInstance(csrClientSymbols, Tizen70CsrClient.fromLookup)!;

Tizen70DataControl? _tizenDataControl;
Tizen70DataControl get tizenDataControl => _tizenDataControl ??=
    _getTizenInstance(dataControlSymbols, Tizen70DataControl.fromLookup)!;

Tizen70DeviceCertificateManager? _tizenDeviceCertificateManager;
Tizen70DeviceCertificateManager get tizenDeviceCertificateManager =>
    _tizenDeviceCertificateManager ??= _getTizenInstance(
        deviceCertificateManagerSymbols,
        Tizen70DeviceCertificateManager.fromLookup)!;

Tizen70Diagnostics? _tizenDiagnostics;
Tizen70Diagnostics get tizenDiagnostics => _tizenDiagnostics ??=
    _getTizenInstance(diagnosticsSymbols, Tizen70Diagnostics.fromLookup)!;

Tizen70Dlog? _tizenDlog;
Tizen70Dlog get tizenDlog =>
    _tizenDlog ??= _getTizenInstance(dlogSymbols, Tizen70Dlog.fromLookup)!;

Tizen70Dpm? _tizenDpm;
Tizen70Dpm get tizenDpm =>
    _tizenDpm ??= _getTizenInstance(dpmSymbols, Tizen70Dpm.fromLookup)!;

Tizen70Eom? _tizenEom;
Tizen70Eom get tizenEom =>
    _tizenEom ??= _getTizenInstance(eomSymbols, Tizen70Eom.fromLookup)!;

Tizen70Feedback? _tizenFeedback;
Tizen70Feedback get tizenFeedback => _tizenFeedback ??=
    _getTizenInstance(feedbackSymbols, Tizen70Feedback.fromLookup)!;

Tizen70FidoClient? _tizenFidoClient;
Tizen70FidoClient get tizenFidoClient => _tizenFidoClient ??=
    _getTizenInstance(fidoClientSymbols, Tizen70FidoClient.fromLookup)!;

Tizen70Iotcon? _tizenIotcon;
Tizen70Iotcon get tizenIotcon => _tizenIotcon ??=
    _getTizenInstance(iotconSymbols, Tizen70Iotcon.fromLookup)!;

Tizen70KeyManagerClient? _tizenKeyManagerClient;
Tizen70KeyManagerClient get tizenKeyManagerClient =>
    _tizenKeyManagerClient ??= _getTizenInstance(
        keyManagerClientSymbols, Tizen70KeyManagerClient.fromLookup)!;

Tizen70Ma? _tizenMa;
Tizen70Ma get tizenMa =>
    _tizenMa ??= _getTizenInstance(maSymbols, Tizen70Ma.fromLookup)!;

Tizen70MessagePort? _tizenMessagePort;
Tizen70MessagePort get tizenMessagePort => _tizenMessagePort ??=
    _getTizenInstance(messagePortSymbols, Tizen70MessagePort.fromLookup)!;

Tizen70Mv3d? _tizenMv3d;
Tizen70Mv3d get tizenMv3d =>
    _tizenMv3d ??= _getTizenInstance(mv3dSymbols, Tizen70Mv3d.fromLookup)!;

Tizen70MvBarcodeDetector? _tizenMvBarcodeDetector;
Tizen70MvBarcodeDetector get tizenMvBarcodeDetector =>
    _tizenMvBarcodeDetector ??= _getTizenInstance(
        mvBarcodeDetectorSymbols, Tizen70MvBarcodeDetector.fromLookup)!;

Tizen70MvBarcodeGenerator? _tizenMvBarcodeGenerator;
Tizen70MvBarcodeGenerator get tizenMvBarcodeGenerator =>
    _tizenMvBarcodeGenerator ??= _getTizenInstance(
        mvBarcodeGeneratorSymbols, Tizen70MvBarcodeGenerator.fromLookup)!;

Tizen70MvCommon? _tizenMvCommon;
Tizen70MvCommon get tizenMvCommon => _tizenMvCommon ??=
    _getTizenInstance(mvCommonSymbols, Tizen70MvCommon.fromLookup)!;

Tizen70MvFace? _tizenMvFace;
Tizen70MvFace get tizenMvFace => _tizenMvFace ??=
    _getTizenInstance(mvFaceSymbols, Tizen70MvFace.fromLookup)!;

Tizen70MvFaceRecognition? _tizenMvFaceRecognition;
Tizen70MvFaceRecognition get tizenMvFaceRecognition =>
    _tizenMvFaceRecognition ??= _getTizenInstance(
        mvFaceRecognitionSymbols, Tizen70MvFaceRecognition.fromLookup)!;

Tizen70MvImage? _tizenMvImage;
Tizen70MvImage get tizenMvImage => _tizenMvImage ??=
    _getTizenInstance(mvImageSymbols, Tizen70MvImage.fromLookup)!;

Tizen70MvInference? _tizenMvInference;
Tizen70MvInference get tizenMvInference => _tizenMvInference ??=
    _getTizenInstance(mvInferenceSymbols, Tizen70MvInference.fromLookup)!;

Tizen70MvRoiTracker? _tizenMvRoiTracker;
Tizen70MvRoiTracker get tizenMvRoiTracker => _tizenMvRoiTracker ??=
    _getTizenInstance(mvRoiTrackerSymbols, Tizen70MvRoiTracker.fromLookup)!;

Tizen70MvSurveillance? _tizenMvSurveillance;
Tizen70MvSurveillance get tizenMvSurveillance => _tizenMvSurveillance ??=
    _getTizenInstance(mvSurveillanceSymbols, Tizen70MvSurveillance.fromLookup)!;

Tizen70Notification? _tizenNotification;
Tizen70Notification get tizenNotification => _tizenNotification ??=
    _getTizenInstance(notificationSymbols, Tizen70Notification.fromLookup)!;

Tizen70NotificationEx? _tizenNotificationEx;
Tizen70NotificationEx get tizenNotificationEx => _tizenNotificationEx ??=
    _getTizenInstance(notificationExSymbols, Tizen70NotificationEx.fromLookup)!;

Tizen70NsdDnsSd? _tizenNsdDnsSd;
Tizen70NsdDnsSd get tizenNsdDnsSd => _tizenNsdDnsSd ??=
    _getTizenInstance(nsdDnsSdSymbols, Tizen70NsdDnsSd.fromLookup)!;

Tizen70NsdSsdp? _tizenNsdSsdp;
Tizen70NsdSsdp get tizenNsdSsdp => _tizenNsdSsdp ??=
    _getTizenInstance(nsdSsdpSymbols, Tizen70NsdSsdp.fromLookup)!;

Tizen70Oauth2? _tizenOauth2;
Tizen70Oauth2 get tizenOauth2 => _tizenOauth2 ??=
    _getTizenInstance(oauth2Symbols, Tizen70Oauth2.fromLookup)!;

Tizen70PhonenumberUtils? _tizenPhonenumberUtils;
Tizen70PhonenumberUtils get tizenPhonenumberUtils =>
    _tizenPhonenumberUtils ??= _getTizenInstance(
        phonenumberUtilsSymbols, Tizen70PhonenumberUtils.fromLookup)!;

Tizen70PrivilegeInfo? _tizenPrivilegeInfo;
Tizen70PrivilegeInfo get tizenPrivilegeInfo => _tizenPrivilegeInfo ??=
    _getTizenInstance(privilegeInfoSymbols, Tizen70PrivilegeInfo.fromLookup)!;

Tizen70Push? _tizenPush;
Tizen70Push get tizenPush =>
    _tizenPush ??= _getTizenInstance(pushSymbols, Tizen70Push.fromLookup)!;

Tizen70RpcPort? _tizenRpcPort;
Tizen70RpcPort get tizenRpcPort => _tizenRpcPort ??=
    _getTizenInstance(rpcPortSymbols, Tizen70RpcPort.fromLookup)!;

Tizen70Storage? _tizenStorage;
Tizen70Storage get tizenStorage => _tizenStorage ??=
    _getTizenInstance(storageSymbols, Tizen70Storage.fromLookup)!;

Tizen70Stt? _tizenStt;
Tizen70Stt get tizenStt =>
    _tizenStt ??= _getTizenInstance(sttSymbols, Tizen70Stt.fromLookup)!;

Tizen70SttEngine? _tizenSttEngine;
Tizen70SttEngine get tizenSttEngine => _tizenSttEngine ??=
    _getTizenInstance(sttEngineSymbols, Tizen70SttEngine.fromLookup)!;

Tizen70Tbm? _tizenTbm;
Tizen70Tbm get tizenTbm =>
    _tizenTbm ??= _getTizenInstance(tbmSymbols, Tizen70Tbm.fromLookup)!;

Tizen70Ttrace? _tizenTtrace;
Tizen70Ttrace get tizenTtrace => _tizenTtrace ??=
    _getTizenInstance(ttraceSymbols, Tizen70Ttrace.fromLookup)!;

Tizen70Tts? _tizenTts;
Tizen70Tts get tizenTts =>
    _tizenTts ??= _getTizenInstance(ttsSymbols, Tizen70Tts.fromLookup)!;

Tizen70TtsEngine? _tizenTtsEngine;
Tizen70TtsEngine get tizenTtsEngine => _tizenTtsEngine ??=
    _getTizenInstance(ttsEngineSymbols, Tizen70TtsEngine.fromLookup)!;

Tizen70UpdateControl? _tizenUpdateControl;
Tizen70UpdateControl get tizenUpdateControl => _tizenUpdateControl ??=
    _getTizenInstance(updateControlSymbols, Tizen70UpdateControl.fromLookup)!;

Tizen70Vc? _tizenVc;
Tizen70Vc get tizenVc =>
    _tizenVc ??= _getTizenInstance(vcSymbols, Tizen70Vc.fromLookup)!;

Tizen70VcEngine? _tizenVcEngine;
Tizen70VcEngine get tizenVcEngine => _tizenVcEngine ??=
    _getTizenInstance(vcEngineSymbols, Tizen70VcEngine.fromLookup)!;

Tizen70VcManager? _tizenVcManager;
Tizen70VcManager get tizenVcManager => _tizenVcManager ??=
    _getTizenInstance(vcManagerSymbols, Tizen70VcManager.fromLookup)!;

Tizen70WifiDirect? _tizenWifiDirect;
Tizen70WifiDirect get tizenWifiDirect => _tizenWifiDirect ??=
    _getTizenInstance(wifiDirectSymbols, Tizen70WifiDirect.fromLookup)!;

Tizen70Yaca? _tizenYaca;
Tizen70Yaca get tizenYaca =>
    _tizenYaca ??= _getTizenInstance(yacaSymbols, Tizen70Yaca.fromLookup)!;
