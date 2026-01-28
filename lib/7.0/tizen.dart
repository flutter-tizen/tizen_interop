library tizen_interop;

import 'dart:ffi';

import '../../src/bindings/7.0/generated_bindings.dart';
import '../../src/lookup_provider.dart';

import 'package:tizen_interop/7.0/tizen_symbols/accounts_svc_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/appcore_agent_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/asp_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/badge_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/bundle_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/calendar_service2_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_appfw_alarm_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_appfw_app_common_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_appfw_app_control_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_appfw_app_control_uri_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_appfw_app_manager_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_appfw_application_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_appfw_event_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_appfw_job_scheduler_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_appfw_package_manager_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_appfw_preference_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_base_common_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_content_media_content_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_content_mime_type_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_context_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_geofence_manager_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_location_manager_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_media_audio_io_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_media_camera_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_media_codec_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_media_controller_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_media_editor_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_media_image_util_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_media_metadata_editor_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_media_metadata_extractor_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_media_player_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_media_radio_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_media_recorder_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_media_screen_mirroring_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_media_sound_manager_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_media_sound_pool_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_media_streamer_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_media_streamrecorder_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_media_thumbnail_util_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_media_tone_player_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_media_tool_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_media_wav_player_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_media_webrtc_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_mediademuxer_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_mediamuxer_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_messaging_email_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_ml_common_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_ml_inference_single_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_ml_service_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_network_bluetooth_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_network_connection_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_network_http_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_network_inm_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_network_mtp_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_network_softap_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_network_stc_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_network_wifi_manager_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_nnstreamer_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_nntrainer_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_privacy_privilege_manager_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_system_device_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_system_info_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_system_media_key_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_system_peripheral_io_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_system_resource_monitor_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_system_runtime_info_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_system_sensor_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_system_system_settings_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_system_usbhost_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_ui_autofill_common_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_ui_autofill_manager_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_ui_autofill_service_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_ui_autofill_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_ui_inputmethod_manager_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_ui_inputmethod_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_vpnsvc_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/capi_web_url_download_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/cbhm_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/cion_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/contacts_service2_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/core_sync_client_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/csr_client_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/data_control_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/device_certificate_manager_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/diagnostics_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/dlog_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/dpm_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/eom_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/feedback_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/fido_client_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/iotcon_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/key_manager_client_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/ma_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/message_port_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/mv_3d_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/mv_barcode_detector_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/mv_barcode_generator_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/mv_common_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/mv_face_recognition_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/mv_face_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/mv_image_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/mv_inference_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/mv_roi_tracker_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/mv_surveillance_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/notification_ex_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/notification_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/nsd_dns_sd_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/nsd_ssdp_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/oauth2_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/phonenumber_utils_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/privilege_info_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/push_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/rpc_port_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/storage_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/stt_engine_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/stt_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/tbm_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/ttrace_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/tts_engine_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/tts_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/update_control_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/vc_engine_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/vc_manager_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/vc_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/wifi_direct_symbols.dart';
import 'package:tizen_interop/7.0/tizen_symbols/yaca_symbols.dart';

export '../../src/bindings/7.0/generated_bindings.dart';
export '../../src/extensions.dart';

final _lookupProvider = LookupProvider();

Tizen70Native _getTizenNative(Map<String, List<String>> symbolMap) {
  return Tizen70Native.fromLookup(
    <T extends NativeType>(String symbolName) {
      _lookupProvider.registerSymbols(symbolMap);
      return _lookupProvider.lookup<T>(symbolName);
    },
  );
}

Tizen70Native? _tizenAccountsSvc;
Tizen70Native get tizenAccountsSvc =>
    _tizenAccountsSvc ??= _getTizenNative(accountsSvcSymbols);

Tizen70Native? _tizenAppcoreAgent;
Tizen70Native get tizenAppcoreAgent =>
    _tizenAppcoreAgent ??= _getTizenNative(appcoreAgentSymbols);

Tizen70Native? _tizenAsp;
Tizen70Native get tizenAsp => _tizenAsp ??= _getTizenNative(aspSymbols);

Tizen70Native? _tizenBadge;
Tizen70Native get tizenBadge => _tizenBadge ??= _getTizenNative(badgeSymbols);

Tizen70Native? _tizenBundle;
Tizen70Native get tizenBundle =>
    _tizenBundle ??= _getTizenNative(bundleSymbols);

Tizen70Native? _tizenCalendarService2;
Tizen70Native get tizenCalendarService2 =>
    _tizenCalendarService2 ??= _getTizenNative(calendarService2Symbols);

Tizen70Native? _tizenCapiAppfwAlarm;
Tizen70Native get tizenCapiAppfwAlarm =>
    _tizenCapiAppfwAlarm ??= _getTizenNative(capiAppfwAlarmSymbols);

Tizen70Native? _tizenCapiAppfwAppCommon;
Tizen70Native get tizenCapiAppfwAppCommon =>
    _tizenCapiAppfwAppCommon ??= _getTizenNative(capiAppfwAppCommonSymbols);

Tizen70Native? _tizenCapiAppfwAppControl;
Tizen70Native get tizenCapiAppfwAppControl =>
    _tizenCapiAppfwAppControl ??= _getTizenNative(capiAppfwAppControlSymbols);

Tizen70Native? _tizenCapiAppfwAppControlUri;
Tizen70Native get tizenCapiAppfwAppControlUri =>
    _tizenCapiAppfwAppControlUri ??=
        _getTizenNative(capiAppfwAppControlUriSymbols);

Tizen70Native? _tizenCapiAppfwAppManager;
Tizen70Native get tizenCapiAppfwAppManager =>
    _tizenCapiAppfwAppManager ??= _getTizenNative(capiAppfwAppManagerSymbols);

Tizen70Native? _tizenCapiAppfwApplication;
Tizen70Native get tizenCapiAppfwApplication =>
    _tizenCapiAppfwApplication ??= _getTizenNative(capiAppfwApplicationSymbols);

Tizen70Native? _tizenCapiAppfwEvent;
Tizen70Native get tizenCapiAppfwEvent =>
    _tizenCapiAppfwEvent ??= _getTizenNative(capiAppfwEventSymbols);

Tizen70Native? _tizenCapiAppfwJobScheduler;
Tizen70Native get tizenCapiAppfwJobScheduler => _tizenCapiAppfwJobScheduler ??=
    _getTizenNative(capiAppfwJobSchedulerSymbols);

Tizen70Native? _tizenCapiAppfwPackageManager;
Tizen70Native get tizenCapiAppfwPackageManager =>
    _tizenCapiAppfwPackageManager ??=
        _getTizenNative(capiAppfwPackageManagerSymbols);

Tizen70Native? _tizenCapiAppfwPreference;
Tizen70Native get tizenCapiAppfwPreference =>
    _tizenCapiAppfwPreference ??= _getTizenNative(capiAppfwPreferenceSymbols);

Tizen70Native? _tizenCapiBaseCommon;
Tizen70Native get tizenCapiBaseCommon =>
    _tizenCapiBaseCommon ??= _getTizenNative(capiBaseCommonSymbols);

Tizen70Native? _tizenCapiContentMediaContent;
Tizen70Native get tizenCapiContentMediaContent =>
    _tizenCapiContentMediaContent ??=
        _getTizenNative(capiContentMediaContentSymbols);

Tizen70Native? _tizenCapiContentMimeType;
Tizen70Native get tizenCapiContentMimeType =>
    _tizenCapiContentMimeType ??= _getTizenNative(capiContentMimeTypeSymbols);

Tizen70Native? _tizenCapiContext;
Tizen70Native get tizenCapiContext =>
    _tizenCapiContext ??= _getTizenNative(capiContextSymbols);

Tizen70Native? _tizenCapiGeofenceManager;
Tizen70Native get tizenCapiGeofenceManager =>
    _tizenCapiGeofenceManager ??= _getTizenNative(capiGeofenceManagerSymbols);

Tizen70Native? _tizenCapiLocationManager;
Tizen70Native get tizenCapiLocationManager =>
    _tizenCapiLocationManager ??= _getTizenNative(capiLocationManagerSymbols);

Tizen70Native? _tizenCapiMediaAudioIo;
Tizen70Native get tizenCapiMediaAudioIo =>
    _tizenCapiMediaAudioIo ??= _getTizenNative(capiMediaAudioIoSymbols);

Tizen70Native? _tizenCapiMediaCamera;
Tizen70Native get tizenCapiMediaCamera =>
    _tizenCapiMediaCamera ??= _getTizenNative(capiMediaCameraSymbols);

Tizen70Native? _tizenCapiMediaCodec;
Tizen70Native get tizenCapiMediaCodec =>
    _tizenCapiMediaCodec ??= _getTizenNative(capiMediaCodecSymbols);

Tizen70Native? _tizenCapiMediaController;
Tizen70Native get tizenCapiMediaController =>
    _tizenCapiMediaController ??= _getTizenNative(capiMediaControllerSymbols);

Tizen70Native? _tizenCapiMediaEditor;
Tizen70Native get tizenCapiMediaEditor =>
    _tizenCapiMediaEditor ??= _getTizenNative(capiMediaEditorSymbols);

Tizen70Native? _tizenCapiMediaImageUtil;
Tizen70Native get tizenCapiMediaImageUtil =>
    _tizenCapiMediaImageUtil ??= _getTizenNative(capiMediaImageUtilSymbols);

Tizen70Native? _tizenCapiMediaMetadataEditor;
Tizen70Native get tizenCapiMediaMetadataEditor =>
    _tizenCapiMediaMetadataEditor ??=
        _getTizenNative(capiMediaMetadataEditorSymbols);

Tizen70Native? _tizenCapiMediaMetadataExtractor;
Tizen70Native get tizenCapiMediaMetadataExtractor =>
    _tizenCapiMediaMetadataExtractor ??=
        _getTizenNative(capiMediaMetadataExtractorSymbols);

Tizen70Native? _tizenCapiMediaPlayer;
Tizen70Native get tizenCapiMediaPlayer =>
    _tizenCapiMediaPlayer ??= _getTizenNative(capiMediaPlayerSymbols);

Tizen70Native? _tizenCapiMediaRadio;
Tizen70Native get tizenCapiMediaRadio =>
    _tizenCapiMediaRadio ??= _getTizenNative(capiMediaRadioSymbols);

Tizen70Native? _tizenCapiMediaRecorder;
Tizen70Native get tizenCapiMediaRecorder =>
    _tizenCapiMediaRecorder ??= _getTizenNative(capiMediaRecorderSymbols);

Tizen70Native? _tizenCapiMediaScreenMirroring;
Tizen70Native get tizenCapiMediaScreenMirroring =>
    _tizenCapiMediaScreenMirroring ??=
        _getTizenNative(capiMediaScreenMirroringSymbols);

Tizen70Native? _tizenCapiMediaSoundManager;
Tizen70Native get tizenCapiMediaSoundManager => _tizenCapiMediaSoundManager ??=
    _getTizenNative(capiMediaSoundManagerSymbols);

Tizen70Native? _tizenCapiMediaSoundPool;
Tizen70Native get tizenCapiMediaSoundPool =>
    _tizenCapiMediaSoundPool ??= _getTizenNative(capiMediaSoundPoolSymbols);

Tizen70Native? _tizenCapiMediaStreamer;
Tizen70Native get tizenCapiMediaStreamer =>
    _tizenCapiMediaStreamer ??= _getTizenNative(capiMediaStreamerSymbols);

Tizen70Native? _tizenCapiMediaStreamrecorder;
Tizen70Native get tizenCapiMediaStreamrecorder =>
    _tizenCapiMediaStreamrecorder ??=
        _getTizenNative(capiMediaStreamrecorderSymbols);

Tizen70Native? _tizenCapiMediaThumbnailUtil;
Tizen70Native get tizenCapiMediaThumbnailUtil =>
    _tizenCapiMediaThumbnailUtil ??=
        _getTizenNative(capiMediaThumbnailUtilSymbols);

Tizen70Native? _tizenCapiMediaTonePlayer;
Tizen70Native get tizenCapiMediaTonePlayer =>
    _tizenCapiMediaTonePlayer ??= _getTizenNative(capiMediaTonePlayerSymbols);

Tizen70Native? _tizenCapiMediaTool;
Tizen70Native get tizenCapiMediaTool =>
    _tizenCapiMediaTool ??= _getTizenNative(capiMediaToolSymbols);

Tizen70Native? _tizenCapiMediaWavPlayer;
Tizen70Native get tizenCapiMediaWavPlayer =>
    _tizenCapiMediaWavPlayer ??= _getTizenNative(capiMediaWavPlayerSymbols);

Tizen70Native? _tizenCapiMediaWebrtc;
Tizen70Native get tizenCapiMediaWebrtc =>
    _tizenCapiMediaWebrtc ??= _getTizenNative(capiMediaWebrtcSymbols);

Tizen70Native? _tizenCapiMediademuxer;
Tizen70Native get tizenCapiMediademuxer =>
    _tizenCapiMediademuxer ??= _getTizenNative(capiMediademuxerSymbols);

Tizen70Native? _tizenCapiMediamuxer;
Tizen70Native get tizenCapiMediamuxer =>
    _tizenCapiMediamuxer ??= _getTizenNative(capiMediamuxerSymbols);

Tizen70Native? _tizenCapiMessagingEmail;
Tizen70Native get tizenCapiMessagingEmail =>
    _tizenCapiMessagingEmail ??= _getTizenNative(capiMessagingEmailSymbols);

Tizen70Native? _tizenCapiMlCommon;
Tizen70Native get tizenCapiMlCommon =>
    _tizenCapiMlCommon ??= _getTizenNative(capiMlCommonSymbols);

Tizen70Native? _tizenCapiMlInferenceSingle;
Tizen70Native get tizenCapiMlInferenceSingle => _tizenCapiMlInferenceSingle ??=
    _getTizenNative(capiMlInferenceSingleSymbols);

Tizen70Native? _tizenCapiMlService;
Tizen70Native get tizenCapiMlService =>
    _tizenCapiMlService ??= _getTizenNative(capiMlServiceSymbols);

Tizen70Native? _tizenCapiNetworkBluetooth;
Tizen70Native get tizenCapiNetworkBluetooth =>
    _tizenCapiNetworkBluetooth ??= _getTizenNative(capiNetworkBluetoothSymbols);

Tizen70Native? _tizenCapiNetworkConnection;
Tizen70Native get tizenCapiNetworkConnection => _tizenCapiNetworkConnection ??=
    _getTizenNative(capiNetworkConnectionSymbols);

Tizen70Native? _tizenCapiNetworkHttp;
Tizen70Native get tizenCapiNetworkHttp =>
    _tizenCapiNetworkHttp ??= _getTizenNative(capiNetworkHttpSymbols);

Tizen70Native? _tizenCapiNetworkInm;
Tizen70Native get tizenCapiNetworkInm =>
    _tizenCapiNetworkInm ??= _getTizenNative(capiNetworkInmSymbols);

Tizen70Native? _tizenCapiNetworkMtp;
Tizen70Native get tizenCapiNetworkMtp =>
    _tizenCapiNetworkMtp ??= _getTizenNative(capiNetworkMtpSymbols);

Tizen70Native? _tizenCapiNetworkSoftap;
Tizen70Native get tizenCapiNetworkSoftap =>
    _tizenCapiNetworkSoftap ??= _getTizenNative(capiNetworkSoftapSymbols);

Tizen70Native? _tizenCapiNetworkStc;
Tizen70Native get tizenCapiNetworkStc =>
    _tizenCapiNetworkStc ??= _getTizenNative(capiNetworkStcSymbols);

Tizen70Native? _tizenCapiNetworkWifiManager;
Tizen70Native get tizenCapiNetworkWifiManager =>
    _tizenCapiNetworkWifiManager ??=
        _getTizenNative(capiNetworkWifiManagerSymbols);

Tizen70Native? _tizenCapiNnstreamer;
Tizen70Native get tizenCapiNnstreamer =>
    _tizenCapiNnstreamer ??= _getTizenNative(capiNnstreamerSymbols);

Tizen70Native? _tizenCapiNntrainer;
Tizen70Native get tizenCapiNntrainer =>
    _tizenCapiNntrainer ??= _getTizenNative(capiNntrainerSymbols);

Tizen70Native? _tizenCapiPrivacyPrivilegeManager;
Tizen70Native get tizenCapiPrivacyPrivilegeManager =>
    _tizenCapiPrivacyPrivilegeManager ??=
        _getTizenNative(capiPrivacyPrivilegeManagerSymbols);

Tizen70Native? _tizenCapiSystemDevice;
Tizen70Native get tizenCapiSystemDevice =>
    _tizenCapiSystemDevice ??= _getTizenNative(capiSystemDeviceSymbols);

Tizen70Native? _tizenCapiSystemInfo;
Tizen70Native get tizenCapiSystemInfo =>
    _tizenCapiSystemInfo ??= _getTizenNative(capiSystemInfoSymbols);

Tizen70Native? _tizenCapiSystemMediaKey;
Tizen70Native get tizenCapiSystemMediaKey =>
    _tizenCapiSystemMediaKey ??= _getTizenNative(capiSystemMediaKeySymbols);

Tizen70Native? _tizenCapiSystemPeripheralIo;
Tizen70Native get tizenCapiSystemPeripheralIo =>
    _tizenCapiSystemPeripheralIo ??=
        _getTizenNative(capiSystemPeripheralIoSymbols);

Tizen70Native? _tizenCapiSystemResourceMonitor;
Tizen70Native get tizenCapiSystemResourceMonitor =>
    _tizenCapiSystemResourceMonitor ??=
        _getTizenNative(capiSystemResourceMonitorSymbols);

Tizen70Native? _tizenCapiSystemRuntimeInfo;
Tizen70Native get tizenCapiSystemRuntimeInfo => _tizenCapiSystemRuntimeInfo ??=
    _getTizenNative(capiSystemRuntimeInfoSymbols);

Tizen70Native? _tizenCapiSystemSensor;
Tizen70Native get tizenCapiSystemSensor =>
    _tizenCapiSystemSensor ??= _getTizenNative(capiSystemSensorSymbols);

Tizen70Native? _tizenCapiSystemSystemSettings;
Tizen70Native get tizenCapiSystemSystemSettings =>
    _tizenCapiSystemSystemSettings ??=
        _getTizenNative(capiSystemSystemSettingsSymbols);

Tizen70Native? _tizenCapiSystemUsbhost;
Tizen70Native get tizenCapiSystemUsbhost =>
    _tizenCapiSystemUsbhost ??= _getTizenNative(capiSystemUsbhostSymbols);

Tizen70Native? _tizenCapiUiAutofillCommon;
Tizen70Native get tizenCapiUiAutofillCommon =>
    _tizenCapiUiAutofillCommon ??= _getTizenNative(capiUiAutofillCommonSymbols);

Tizen70Native? _tizenCapiUiAutofillManager;
Tizen70Native get tizenCapiUiAutofillManager => _tizenCapiUiAutofillManager ??=
    _getTizenNative(capiUiAutofillManagerSymbols);

Tizen70Native? _tizenCapiUiAutofillService;
Tizen70Native get tizenCapiUiAutofillService => _tizenCapiUiAutofillService ??=
    _getTizenNative(capiUiAutofillServiceSymbols);

Tizen70Native? _tizenCapiUiAutofill;
Tizen70Native get tizenCapiUiAutofill =>
    _tizenCapiUiAutofill ??= _getTizenNative(capiUiAutofillSymbols);

Tizen70Native? _tizenCapiUiInputmethodManager;
Tizen70Native get tizenCapiUiInputmethodManager =>
    _tizenCapiUiInputmethodManager ??=
        _getTizenNative(capiUiInputmethodManagerSymbols);

Tizen70Native? _tizenCapiUiInputmethod;
Tizen70Native get tizenCapiUiInputmethod =>
    _tizenCapiUiInputmethod ??= _getTizenNative(capiUiInputmethodSymbols);

Tizen70Native? _tizenCapiVpnsvc;
Tizen70Native get tizenCapiVpnsvc =>
    _tizenCapiVpnsvc ??= _getTizenNative(capiVpnsvcSymbols);

Tizen70Native? _tizenCapiWebUrlDownload;
Tizen70Native get tizenCapiWebUrlDownload =>
    _tizenCapiWebUrlDownload ??= _getTizenNative(capiWebUrlDownloadSymbols);

Tizen70Native? _tizenCbhm;
Tizen70Native get tizenCbhm => _tizenCbhm ??= _getTizenNative(cbhmSymbols);

Tizen70Native? _tizenCion;
Tizen70Native get tizenCion => _tizenCion ??= _getTizenNative(cionSymbols);

Tizen70Native? _tizenContactsService2;
Tizen70Native get tizenContactsService2 =>
    _tizenContactsService2 ??= _getTizenNative(contactsService2Symbols);

Tizen70Native? _tizenCoreSyncClient;
Tizen70Native get tizenCoreSyncClient =>
    _tizenCoreSyncClient ??= _getTizenNative(coreSyncClientSymbols);

Tizen70Native? _tizenCsrClient;
Tizen70Native get tizenCsrClient =>
    _tizenCsrClient ??= _getTizenNative(csrClientSymbols);

Tizen70Native? _tizenDataControl;
Tizen70Native get tizenDataControl =>
    _tizenDataControl ??= _getTizenNative(dataControlSymbols);

Tizen70Native? _tizenDeviceCertificateManager;
Tizen70Native get tizenDeviceCertificateManager =>
    _tizenDeviceCertificateManager ??=
        _getTizenNative(deviceCertificateManagerSymbols);

Tizen70Native? _tizenDiagnostics;
Tizen70Native get tizenDiagnostics =>
    _tizenDiagnostics ??= _getTizenNative(diagnosticsSymbols);

Tizen70Native? _tizenDlog;
Tizen70Native get tizenDlog => _tizenDlog ??= _getTizenNative(dlogSymbols);

Tizen70Native? _tizenDpm;
Tizen70Native get tizenDpm => _tizenDpm ??= _getTizenNative(dpmSymbols);

Tizen70Native? _tizenEom;
Tizen70Native get tizenEom => _tizenEom ??= _getTizenNative(eomSymbols);

Tizen70Native? _tizenFeedback;
Tizen70Native get tizenFeedback =>
    _tizenFeedback ??= _getTizenNative(feedbackSymbols);

Tizen70Native? _tizenFidoClient;
Tizen70Native get tizenFidoClient =>
    _tizenFidoClient ??= _getTizenNative(fidoClientSymbols);

Tizen70Native? _tizenIotcon;
Tizen70Native get tizenIotcon =>
    _tizenIotcon ??= _getTizenNative(iotconSymbols);

Tizen70Native? _tizenKeyManagerClient;
Tizen70Native get tizenKeyManagerClient =>
    _tizenKeyManagerClient ??= _getTizenNative(keyManagerClientSymbols);

Tizen70Native? _tizenMa;
Tizen70Native get tizenMa => _tizenMa ??= _getTizenNative(maSymbols);

Tizen70Native? _tizenMessagePort;
Tizen70Native get tizenMessagePort =>
    _tizenMessagePort ??= _getTizenNative(messagePortSymbols);

Tizen70Native? _tizenMv3d;
Tizen70Native get tizenMv3d => _tizenMv3d ??= _getTizenNative(mv_3dSymbols);

Tizen70Native? _tizenMvBarcodeDetector;
Tizen70Native get tizenMvBarcodeDetector =>
    _tizenMvBarcodeDetector ??= _getTizenNative(mv_barcode_detectorSymbols);

Tizen70Native? _tizenMvBarcodeGenerator;
Tizen70Native get tizenMvBarcodeGenerator =>
    _tizenMvBarcodeGenerator ??= _getTizenNative(mv_barcode_generatorSymbols);

Tizen70Native? _tizenMvCommon;
Tizen70Native get tizenMvCommon =>
    _tizenMvCommon ??= _getTizenNative(mv_commonSymbols);

Tizen70Native? _tizenMvFaceRecognition;
Tizen70Native get tizenMvFaceRecognition =>
    _tizenMvFaceRecognition ??= _getTizenNative(mv_face_recognitionSymbols);

Tizen70Native? _tizenMvFace;
Tizen70Native get tizenMvFace =>
    _tizenMvFace ??= _getTizenNative(mv_faceSymbols);

Tizen70Native? _tizenMvImage;
Tizen70Native get tizenMvImage =>
    _tizenMvImage ??= _getTizenNative(mv_imageSymbols);

Tizen70Native? _tizenMvInference;
Tizen70Native get tizenMvInference =>
    _tizenMvInference ??= _getTizenNative(mv_inferenceSymbols);

Tizen70Native? _tizenMvRoiTracker;
Tizen70Native get tizenMvRoiTracker =>
    _tizenMvRoiTracker ??= _getTizenNative(mv_roi_trackerSymbols);

Tizen70Native? _tizenMvSurveillance;
Tizen70Native get tizenMvSurveillance =>
    _tizenMvSurveillance ??= _getTizenNative(mv_surveillanceSymbols);

Tizen70Native? _tizenNotificationEx;
Tizen70Native get tizenNotificationEx =>
    _tizenNotificationEx ??= _getTizenNative(notificationExSymbols);

Tizen70Native? _tizenNotification;
Tizen70Native get tizenNotification =>
    _tizenNotification ??= _getTizenNative(notificationSymbols);

Tizen70Native? _tizenNsdDnsSd;
Tizen70Native get tizenNsdDnsSd =>
    _tizenNsdDnsSd ??= _getTizenNative(nsdDnsSdSymbols);

Tizen70Native? _tizenNsdSsdp;
Tizen70Native get tizenNsdSsdp =>
    _tizenNsdSsdp ??= _getTizenNative(nsdSsdpSymbols);

Tizen70Native? _tizenOauth2;
Tizen70Native get tizenOauth2 =>
    _tizenOauth2 ??= _getTizenNative(oauth2Symbols);

Tizen70Native? _tizenPhonenumberUtils;
Tizen70Native get tizenPhonenumberUtils =>
    _tizenPhonenumberUtils ??= _getTizenNative(phonenumberUtilsSymbols);

Tizen70Native? _tizenPrivilegeInfo;
Tizen70Native get tizenPrivilegeInfo =>
    _tizenPrivilegeInfo ??= _getTizenNative(privilegeInfoSymbols);

Tizen70Native? _tizenPush;
Tizen70Native get tizenPush => _tizenPush ??= _getTizenNative(pushSymbols);

Tizen70Native? _tizenRpcPort;
Tizen70Native get tizenRpcPort =>
    _tizenRpcPort ??= _getTizenNative(rpcPortSymbols);

Tizen70Native? _tizenStorage;
Tizen70Native get tizenStorage =>
    _tizenStorage ??= _getTizenNative(storageSymbols);

Tizen70Native? _tizenSttEngine;
Tizen70Native get tizenSttEngine =>
    _tizenSttEngine ??= _getTizenNative(stt_engineSymbols);

Tizen70Native? _tizenStt;
Tizen70Native get tizenStt => _tizenStt ??= _getTizenNative(sttSymbols);

Tizen70Native? _tizenTbm;
Tizen70Native get tizenTbm => _tizenTbm ??= _getTizenNative(tbmSymbols);

Tizen70Native? _tizenTtrace;
Tizen70Native get tizenTtrace =>
    _tizenTtrace ??= _getTizenNative(ttraceSymbols);

Tizen70Native? _tizenTtsEngine;
Tizen70Native get tizenTtsEngine =>
    _tizenTtsEngine ??= _getTizenNative(tts_engineSymbols);

Tizen70Native? _tizenTts;
Tizen70Native get tizenTts => _tizenTts ??= _getTizenNative(ttsSymbols);

Tizen70Native? _tizenUpdateControl;
Tizen70Native get tizenUpdateControl =>
    _tizenUpdateControl ??= _getTizenNative(updateControlSymbols);

Tizen70Native? _tizenVcEngine;
Tizen70Native get tizenVcEngine =>
    _tizenVcEngine ??= _getTizenNative(vc_engineSymbols);

Tizen70Native? _tizenVcManager;
Tizen70Native get tizenVcManager =>
    _tizenVcManager ??= _getTizenNative(vc_managerSymbols);

Tizen70Native? _tizenVc;
Tizen70Native get tizenVc => _tizenVc ??= _getTizenNative(vcSymbols);

Tizen70Native? _tizenWifiDirect;
Tizen70Native get tizenWifiDirect =>
    _tizenWifiDirect ??= _getTizenNative(wifiDirectSymbols);

Tizen70Native? _tizenYaca;
Tizen70Native get tizenYaca => _tizenYaca ??= _getTizenNative(yacaSymbols);
