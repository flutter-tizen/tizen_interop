library tizen_interop;

import 'dart:ffi';

import '../../src/bindings/8.0/generated_bindings.dart';
import '../../src/lookup_provider.dart';

import 'package:tizen_interop/8.0/tizen_symbols/accounts_svc_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/appcore_agent_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/asp_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/badge_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/bundle_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/calendar_service2_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_appfw_alarm_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_appfw_app_common_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_appfw_app_control_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_appfw_app_control_uri_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_appfw_app_manager_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_appfw_application_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_appfw_event_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_appfw_job_scheduler_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_appfw_package_manager_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_appfw_preference_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_base_common_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_content_media_content_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_content_mime_type_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_context_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_geofence_manager_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_location_manager_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_media_audio_io_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_media_camera_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_media_codec_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_media_controller_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_media_editor_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_media_image_util_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_media_metadata_editor_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_media_metadata_extractor_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_media_player_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_media_radio_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_media_recorder_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_media_screen_mirroring_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_media_sound_manager_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_media_sound_pool_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_media_streamer_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_media_streamrecorder_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_media_thumbnail_util_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_media_tone_player_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_media_tool_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_media_wav_player_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_media_webrtc_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_mediademuxer_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_mediamuxer_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_messaging_email_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_ml_common_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_ml_inference_single_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_ml_service_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_network_bluetooth_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_network_connection_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_network_http_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_network_inm_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_network_mtp_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_network_softap_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_network_stc_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_network_wifi_manager_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_nnstreamer_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_nntrainer_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_privacy_privilege_manager_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_system_device_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_system_info_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_system_media_key_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_system_peripheral_io_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_system_resource_monitor_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_system_runtime_info_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_system_sensor_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_system_system_settings_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_system_usbhost_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_ui_autofill_common_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_ui_autofill_manager_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_ui_autofill_service_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_ui_autofill_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_ui_inputmethod_manager_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_ui_inputmethod_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_vpnsvc_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/capi_web_url_download_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/cion_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/contacts_service2_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/core_sync_client_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/csr_client_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/data_control_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/device_certificate_manager_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/diagnostics_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/dlog_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/dpm_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/eom_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/feedback_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/fido_client_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/iotcon_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/key_manager_client_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/ma_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/message_port_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/mv_3d_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/mv_barcode_detector_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/mv_barcode_generator_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/mv_common_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/mv_face_recognition_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/mv_face_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/mv_image_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/mv_inference_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/mv_roi_tracker_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/mv_surveillance_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/notification_ex_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/notification_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/nsd_dns_sd_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/nsd_ssdp_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/oauth2_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/phonenumber_utils_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/privilege_info_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/push_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/rpc_port_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/storage_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/stt_engine_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/stt_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/tbm_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/ttrace_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/tts_engine_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/tts_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/update_control_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/vc_engine_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/vc_manager_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/vc_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/wifi_direct_symbols.dart';
import 'package:tizen_interop/8.0/tizen_symbols/yaca_symbols.dart';

export '../../src/bindings/8.0/generated_bindings.dart';
export '../../src/extensions.dart';

final _lookupProvider = LookupProvider();

Tizen80Native _getTizenNative(Map<String, List<String>> symbolMap) {
  return Tizen80Native.fromLookup(
    <T extends NativeType>(String symbolName) {
      _lookupProvider.registerSymbols(symbolMap);
      return _lookupProvider.lookup<T>(symbolName);
    },
  );
}

Tizen80Native? _tizenAccountsSvc;
Tizen80Native get tizenAccountsSvc =>
    _tizenAccountsSvc ??= _getTizenNative(accountsSvcSymbols);

Tizen80Native? _tizenAppcoreAgent;
Tizen80Native get tizenAppcoreAgent =>
    _tizenAppcoreAgent ??= _getTizenNative(appcoreAgentSymbols);

Tizen80Native? _tizenAsp;
Tizen80Native get tizenAsp => _tizenAsp ??= _getTizenNative(aspSymbols);

Tizen80Native? _tizenBadge;
Tizen80Native get tizenBadge => _tizenBadge ??= _getTizenNative(badgeSymbols);

Tizen80Native? _tizenBundle;
Tizen80Native get tizenBundle =>
    _tizenBundle ??= _getTizenNative(bundleSymbols);

Tizen80Native? _tizenCalendarService2;
Tizen80Native get tizenCalendarService2 =>
    _tizenCalendarService2 ??= _getTizenNative(calendarService2Symbols);

Tizen80Native? _tizenCapiAppfwAlarm;
Tizen80Native get tizenCapiAppfwAlarm =>
    _tizenCapiAppfwAlarm ??= _getTizenNative(capiAppfwAlarmSymbols);

Tizen80Native? _tizenCapiAppfwAppCommon;
Tizen80Native get tizenCapiAppfwAppCommon =>
    _tizenCapiAppfwAppCommon ??= _getTizenNative(capiAppfwAppCommonSymbols);

Tizen80Native? _tizenCapiAppfwAppControl;
Tizen80Native get tizenCapiAppfwAppControl =>
    _tizenCapiAppfwAppControl ??= _getTizenNative(capiAppfwAppControlSymbols);

Tizen80Native? _tizenCapiAppfwAppControlUri;
Tizen80Native get tizenCapiAppfwAppControlUri =>
    _tizenCapiAppfwAppControlUri ??=
        _getTizenNative(capiAppfwAppControlUriSymbols);

Tizen80Native? _tizenCapiAppfwAppManager;
Tizen80Native get tizenCapiAppfwAppManager =>
    _tizenCapiAppfwAppManager ??= _getTizenNative(capiAppfwAppManagerSymbols);

Tizen80Native? _tizenCapiAppfwApplication;
Tizen80Native get tizenCapiAppfwApplication =>
    _tizenCapiAppfwApplication ??= _getTizenNative(capiAppfwApplicationSymbols);

Tizen80Native? _tizenCapiAppfwEvent;
Tizen80Native get tizenCapiAppfwEvent =>
    _tizenCapiAppfwEvent ??= _getTizenNative(capiAppfwEventSymbols);

Tizen80Native? _tizenCapiAppfwJobScheduler;
Tizen80Native get tizenCapiAppfwJobScheduler => _tizenCapiAppfwJobScheduler ??=
    _getTizenNative(capiAppfwJobSchedulerSymbols);

Tizen80Native? _tizenCapiAppfwPackageManager;
Tizen80Native get tizenCapiAppfwPackageManager =>
    _tizenCapiAppfwPackageManager ??=
        _getTizenNative(capiAppfwPackageManagerSymbols);

Tizen80Native? _tizenCapiAppfwPreference;
Tizen80Native get tizenCapiAppfwPreference =>
    _tizenCapiAppfwPreference ??= _getTizenNative(capiAppfwPreferenceSymbols);

Tizen80Native? _tizenCapiBaseCommon;
Tizen80Native get tizenCapiBaseCommon =>
    _tizenCapiBaseCommon ??= _getTizenNative(capiBaseCommonSymbols);

Tizen80Native? _tizenCapiContentMediaContent;
Tizen80Native get tizenCapiContentMediaContent =>
    _tizenCapiContentMediaContent ??=
        _getTizenNative(capiContentMediaContentSymbols);

Tizen80Native? _tizenCapiContentMimeType;
Tizen80Native get tizenCapiContentMimeType =>
    _tizenCapiContentMimeType ??= _getTizenNative(capiContentMimeTypeSymbols);

Tizen80Native? _tizenCapiContext;
Tizen80Native get tizenCapiContext =>
    _tizenCapiContext ??= _getTizenNative(capiContextSymbols);

Tizen80Native? _tizenCapiGeofenceManager;
Tizen80Native get tizenCapiGeofenceManager =>
    _tizenCapiGeofenceManager ??= _getTizenNative(capiGeofenceManagerSymbols);

Tizen80Native? _tizenCapiLocationManager;
Tizen80Native get tizenCapiLocationManager =>
    _tizenCapiLocationManager ??= _getTizenNative(capiLocationManagerSymbols);

Tizen80Native? _tizenCapiMediaAudioIo;
Tizen80Native get tizenCapiMediaAudioIo =>
    _tizenCapiMediaAudioIo ??= _getTizenNative(capiMediaAudioIoSymbols);

Tizen80Native? _tizenCapiMediaCamera;
Tizen80Native get tizenCapiMediaCamera =>
    _tizenCapiMediaCamera ??= _getTizenNative(capiMediaCameraSymbols);

Tizen80Native? _tizenCapiMediaCodec;
Tizen80Native get tizenCapiMediaCodec =>
    _tizenCapiMediaCodec ??= _getTizenNative(capiMediaCodecSymbols);

Tizen80Native? _tizenCapiMediaController;
Tizen80Native get tizenCapiMediaController =>
    _tizenCapiMediaController ??= _getTizenNative(capiMediaControllerSymbols);

Tizen80Native? _tizenCapiMediaEditor;
Tizen80Native get tizenCapiMediaEditor =>
    _tizenCapiMediaEditor ??= _getTizenNative(capiMediaEditorSymbols);

Tizen80Native? _tizenCapiMediaImageUtil;
Tizen80Native get tizenCapiMediaImageUtil =>
    _tizenCapiMediaImageUtil ??= _getTizenNative(capiMediaImageUtilSymbols);

Tizen80Native? _tizenCapiMediaMetadataEditor;
Tizen80Native get tizenCapiMediaMetadataEditor =>
    _tizenCapiMediaMetadataEditor ??=
        _getTizenNative(capiMediaMetadataEditorSymbols);

Tizen80Native? _tizenCapiMediaMetadataExtractor;
Tizen80Native get tizenCapiMediaMetadataExtractor =>
    _tizenCapiMediaMetadataExtractor ??=
        _getTizenNative(capiMediaMetadataExtractorSymbols);

Tizen80Native? _tizenCapiMediaPlayer;
Tizen80Native get tizenCapiMediaPlayer =>
    _tizenCapiMediaPlayer ??= _getTizenNative(capiMediaPlayerSymbols);

Tizen80Native? _tizenCapiMediaRadio;
Tizen80Native get tizenCapiMediaRadio =>
    _tizenCapiMediaRadio ??= _getTizenNative(capiMediaRadioSymbols);

Tizen80Native? _tizenCapiMediaRecorder;
Tizen80Native get tizenCapiMediaRecorder =>
    _tizenCapiMediaRecorder ??= _getTizenNative(capiMediaRecorderSymbols);

Tizen80Native? _tizenCapiMediaScreenMirroring;
Tizen80Native get tizenCapiMediaScreenMirroring =>
    _tizenCapiMediaScreenMirroring ??=
        _getTizenNative(capiMediaScreenMirroringSymbols);

Tizen80Native? _tizenCapiMediaSoundManager;
Tizen80Native get tizenCapiMediaSoundManager => _tizenCapiMediaSoundManager ??=
    _getTizenNative(capiMediaSoundManagerSymbols);

Tizen80Native? _tizenCapiMediaSoundPool;
Tizen80Native get tizenCapiMediaSoundPool =>
    _tizenCapiMediaSoundPool ??= _getTizenNative(capiMediaSoundPoolSymbols);

Tizen80Native? _tizenCapiMediaStreamer;
Tizen80Native get tizenCapiMediaStreamer =>
    _tizenCapiMediaStreamer ??= _getTizenNative(capiMediaStreamerSymbols);

Tizen80Native? _tizenCapiMediaStreamrecorder;
Tizen80Native get tizenCapiMediaStreamrecorder =>
    _tizenCapiMediaStreamrecorder ??=
        _getTizenNative(capiMediaStreamrecorderSymbols);

Tizen80Native? _tizenCapiMediaThumbnailUtil;
Tizen80Native get tizenCapiMediaThumbnailUtil =>
    _tizenCapiMediaThumbnailUtil ??=
        _getTizenNative(capiMediaThumbnailUtilSymbols);

Tizen80Native? _tizenCapiMediaTonePlayer;
Tizen80Native get tizenCapiMediaTonePlayer =>
    _tizenCapiMediaTonePlayer ??= _getTizenNative(capiMediaTonePlayerSymbols);

Tizen80Native? _tizenCapiMediaTool;
Tizen80Native get tizenCapiMediaTool =>
    _tizenCapiMediaTool ??= _getTizenNative(capiMediaToolSymbols);

Tizen80Native? _tizenCapiMediaWavPlayer;
Tizen80Native get tizenCapiMediaWavPlayer =>
    _tizenCapiMediaWavPlayer ??= _getTizenNative(capiMediaWavPlayerSymbols);

Tizen80Native? _tizenCapiMediaWebrtc;
Tizen80Native get tizenCapiMediaWebrtc =>
    _tizenCapiMediaWebrtc ??= _getTizenNative(capiMediaWebrtcSymbols);

Tizen80Native? _tizenCapiMediademuxer;
Tizen80Native get tizenCapiMediademuxer =>
    _tizenCapiMediademuxer ??= _getTizenNative(capiMediademuxerSymbols);

Tizen80Native? _tizenCapiMediamuxer;
Tizen80Native get tizenCapiMediamuxer =>
    _tizenCapiMediamuxer ??= _getTizenNative(capiMediamuxerSymbols);

Tizen80Native? _tizenCapiMessagingEmail;
Tizen80Native get tizenCapiMessagingEmail =>
    _tizenCapiMessagingEmail ??= _getTizenNative(capiMessagingEmailSymbols);

Tizen80Native? _tizenCapiMlCommon;
Tizen80Native get tizenCapiMlCommon =>
    _tizenCapiMlCommon ??= _getTizenNative(capiMlCommonSymbols);

Tizen80Native? _tizenCapiMlInferenceSingle;
Tizen80Native get tizenCapiMlInferenceSingle => _tizenCapiMlInferenceSingle ??=
    _getTizenNative(capiMlInferenceSingleSymbols);

Tizen80Native? _tizenCapiMlService;
Tizen80Native get tizenCapiMlService =>
    _tizenCapiMlService ??= _getTizenNative(capiMlServiceSymbols);

Tizen80Native? _tizenCapiNetworkBluetooth;
Tizen80Native get tizenCapiNetworkBluetooth =>
    _tizenCapiNetworkBluetooth ??= _getTizenNative(capiNetworkBluetoothSymbols);

Tizen80Native? _tizenCapiNetworkConnection;
Tizen80Native get tizenCapiNetworkConnection => _tizenCapiNetworkConnection ??=
    _getTizenNative(capiNetworkConnectionSymbols);

Tizen80Native? _tizenCapiNetworkHttp;
Tizen80Native get tizenCapiNetworkHttp =>
    _tizenCapiNetworkHttp ??= _getTizenNative(capiNetworkHttpSymbols);

Tizen80Native? _tizenCapiNetworkInm;
Tizen80Native get tizenCapiNetworkInm =>
    _tizenCapiNetworkInm ??= _getTizenNative(capiNetworkInmSymbols);

Tizen80Native? _tizenCapiNetworkMtp;
Tizen80Native get tizenCapiNetworkMtp =>
    _tizenCapiNetworkMtp ??= _getTizenNative(capiNetworkMtpSymbols);

Tizen80Native? _tizenCapiNetworkSoftap;
Tizen80Native get tizenCapiNetworkSoftap =>
    _tizenCapiNetworkSoftap ??= _getTizenNative(capiNetworkSoftapSymbols);

Tizen80Native? _tizenCapiNetworkStc;
Tizen80Native get tizenCapiNetworkStc =>
    _tizenCapiNetworkStc ??= _getTizenNative(capiNetworkStcSymbols);

Tizen80Native? _tizenCapiNetworkWifiManager;
Tizen80Native get tizenCapiNetworkWifiManager =>
    _tizenCapiNetworkWifiManager ??=
        _getTizenNative(capiNetworkWifiManagerSymbols);

Tizen80Native? _tizenCapiNnstreamer;
Tizen80Native get tizenCapiNnstreamer =>
    _tizenCapiNnstreamer ??= _getTizenNative(capiNnstreamerSymbols);

Tizen80Native? _tizenCapiNntrainer;
Tizen80Native get tizenCapiNntrainer =>
    _tizenCapiNntrainer ??= _getTizenNative(capiNntrainerSymbols);

Tizen80Native? _tizenCapiPrivacyPrivilegeManager;
Tizen80Native get tizenCapiPrivacyPrivilegeManager =>
    _tizenCapiPrivacyPrivilegeManager ??=
        _getTizenNative(capiPrivacyPrivilegeManagerSymbols);

Tizen80Native? _tizenCapiSystemDevice;
Tizen80Native get tizenCapiSystemDevice =>
    _tizenCapiSystemDevice ??= _getTizenNative(capiSystemDeviceSymbols);

Tizen80Native? _tizenCapiSystemInfo;
Tizen80Native get tizenCapiSystemInfo =>
    _tizenCapiSystemInfo ??= _getTizenNative(capiSystemInfoSymbols);

Tizen80Native? _tizenCapiSystemMediaKey;
Tizen80Native get tizenCapiSystemMediaKey =>
    _tizenCapiSystemMediaKey ??= _getTizenNative(capiSystemMediaKeySymbols);

Tizen80Native? _tizenCapiSystemPeripheralIo;
Tizen80Native get tizenCapiSystemPeripheralIo =>
    _tizenCapiSystemPeripheralIo ??=
        _getTizenNative(capiSystemPeripheralIoSymbols);

Tizen80Native? _tizenCapiSystemResourceMonitor;
Tizen80Native get tizenCapiSystemResourceMonitor =>
    _tizenCapiSystemResourceMonitor ??=
        _getTizenNative(capiSystemResourceMonitorSymbols);

Tizen80Native? _tizenCapiSystemRuntimeInfo;
Tizen80Native get tizenCapiSystemRuntimeInfo => _tizenCapiSystemRuntimeInfo ??=
    _getTizenNative(capiSystemRuntimeInfoSymbols);

Tizen80Native? _tizenCapiSystemSensor;
Tizen80Native get tizenCapiSystemSensor =>
    _tizenCapiSystemSensor ??= _getTizenNative(capiSystemSensorSymbols);

Tizen80Native? _tizenCapiSystemSystemSettings;
Tizen80Native get tizenCapiSystemSystemSettings =>
    _tizenCapiSystemSystemSettings ??=
        _getTizenNative(capiSystemSystemSettingsSymbols);

Tizen80Native? _tizenCapiSystemUsbhost;
Tizen80Native get tizenCapiSystemUsbhost =>
    _tizenCapiSystemUsbhost ??= _getTizenNative(capiSystemUsbhostSymbols);

Tizen80Native? _tizenCapiUiAutofillCommon;
Tizen80Native get tizenCapiUiAutofillCommon =>
    _tizenCapiUiAutofillCommon ??= _getTizenNative(capiUiAutofillCommonSymbols);

Tizen80Native? _tizenCapiUiAutofillManager;
Tizen80Native get tizenCapiUiAutofillManager => _tizenCapiUiAutofillManager ??=
    _getTizenNative(capiUiAutofillManagerSymbols);

Tizen80Native? _tizenCapiUiAutofillService;
Tizen80Native get tizenCapiUiAutofillService => _tizenCapiUiAutofillService ??=
    _getTizenNative(capiUiAutofillServiceSymbols);

Tizen80Native? _tizenCapiUiAutofill;
Tizen80Native get tizenCapiUiAutofill =>
    _tizenCapiUiAutofill ??= _getTizenNative(capiUiAutofillSymbols);

Tizen80Native? _tizenCapiUiInputmethodManager;
Tizen80Native get tizenCapiUiInputmethodManager =>
    _tizenCapiUiInputmethodManager ??=
        _getTizenNative(capiUiInputmethodManagerSymbols);

Tizen80Native? _tizenCapiUiInputmethod;
Tizen80Native get tizenCapiUiInputmethod =>
    _tizenCapiUiInputmethod ??= _getTizenNative(capiUiInputmethodSymbols);

Tizen80Native? _tizenCapiVpnsvc;
Tizen80Native get tizenCapiVpnsvc =>
    _tizenCapiVpnsvc ??= _getTizenNative(capiVpnsvcSymbols);

Tizen80Native? _tizenCapiWebUrlDownload;
Tizen80Native get tizenCapiWebUrlDownload =>
    _tizenCapiWebUrlDownload ??= _getTizenNative(capiWebUrlDownloadSymbols);

Tizen80Native? _tizenCion;
Tizen80Native get tizenCion => _tizenCion ??= _getTizenNative(cionSymbols);

Tizen80Native? _tizenContactsService2;
Tizen80Native get tizenContactsService2 =>
    _tizenContactsService2 ??= _getTizenNative(contactsService2Symbols);

Tizen80Native? _tizenCoreSyncClient;
Tizen80Native get tizenCoreSyncClient =>
    _tizenCoreSyncClient ??= _getTizenNative(coreSyncClientSymbols);

Tizen80Native? _tizenCsrClient;
Tizen80Native get tizenCsrClient =>
    _tizenCsrClient ??= _getTizenNative(csrClientSymbols);

Tizen80Native? _tizenDataControl;
Tizen80Native get tizenDataControl =>
    _tizenDataControl ??= _getTizenNative(dataControlSymbols);

Tizen80Native? _tizenDeviceCertificateManager;
Tizen80Native get tizenDeviceCertificateManager =>
    _tizenDeviceCertificateManager ??=
        _getTizenNative(deviceCertificateManagerSymbols);

Tizen80Native? _tizenDiagnostics;
Tizen80Native get tizenDiagnostics =>
    _tizenDiagnostics ??= _getTizenNative(diagnosticsSymbols);

Tizen80Native? _tizenDlog;
Tizen80Native get tizenDlog => _tizenDlog ??= _getTizenNative(dlogSymbols);

Tizen80Native? _tizenDpm;
Tizen80Native get tizenDpm => _tizenDpm ??= _getTizenNative(dpmSymbols);

Tizen80Native? _tizenEom;
Tizen80Native get tizenEom => _tizenEom ??= _getTizenNative(eomSymbols);

Tizen80Native? _tizenFeedback;
Tizen80Native get tizenFeedback =>
    _tizenFeedback ??= _getTizenNative(feedbackSymbols);

Tizen80Native? _tizenFidoClient;
Tizen80Native get tizenFidoClient =>
    _tizenFidoClient ??= _getTizenNative(fidoClientSymbols);

Tizen80Native? _tizenIotcon;
Tizen80Native get tizenIotcon =>
    _tizenIotcon ??= _getTizenNative(iotconSymbols);

Tizen80Native? _tizenKeyManagerClient;
Tizen80Native get tizenKeyManagerClient =>
    _tizenKeyManagerClient ??= _getTizenNative(keyManagerClientSymbols);

Tizen80Native? _tizenMa;
Tizen80Native get tizenMa => _tizenMa ??= _getTizenNative(maSymbols);

Tizen80Native? _tizenMessagePort;
Tizen80Native get tizenMessagePort =>
    _tizenMessagePort ??= _getTizenNative(messagePortSymbols);

Tizen80Native? _tizenMv3d;
Tizen80Native get tizenMv3d => _tizenMv3d ??= _getTizenNative(mv_3dSymbols);

Tizen80Native? _tizenMvBarcodeDetector;
Tizen80Native get tizenMvBarcodeDetector =>
    _tizenMvBarcodeDetector ??= _getTizenNative(mv_barcode_detectorSymbols);

Tizen80Native? _tizenMvBarcodeGenerator;
Tizen80Native get tizenMvBarcodeGenerator =>
    _tizenMvBarcodeGenerator ??= _getTizenNative(mv_barcode_generatorSymbols);

Tizen80Native? _tizenMvCommon;
Tizen80Native get tizenMvCommon =>
    _tizenMvCommon ??= _getTizenNative(mv_commonSymbols);

Tizen80Native? _tizenMvFaceRecognition;
Tizen80Native get tizenMvFaceRecognition =>
    _tizenMvFaceRecognition ??= _getTizenNative(mv_face_recognitionSymbols);

Tizen80Native? _tizenMvFace;
Tizen80Native get tizenMvFace =>
    _tizenMvFace ??= _getTizenNative(mv_faceSymbols);

Tizen80Native? _tizenMvImage;
Tizen80Native get tizenMvImage =>
    _tizenMvImage ??= _getTizenNative(mv_imageSymbols);

Tizen80Native? _tizenMvInference;
Tizen80Native get tizenMvInference =>
    _tizenMvInference ??= _getTizenNative(mv_inferenceSymbols);

Tizen80Native? _tizenMvRoiTracker;
Tizen80Native get tizenMvRoiTracker =>
    _tizenMvRoiTracker ??= _getTizenNative(mv_roi_trackerSymbols);

Tizen80Native? _tizenMvSurveillance;
Tizen80Native get tizenMvSurveillance =>
    _tizenMvSurveillance ??= _getTizenNative(mv_surveillanceSymbols);

Tizen80Native? _tizenNotificationEx;
Tizen80Native get tizenNotificationEx =>
    _tizenNotificationEx ??= _getTizenNative(notificationExSymbols);

Tizen80Native? _tizenNotification;
Tizen80Native get tizenNotification =>
    _tizenNotification ??= _getTizenNative(notificationSymbols);

Tizen80Native? _tizenNsdDnsSd;
Tizen80Native get tizenNsdDnsSd =>
    _tizenNsdDnsSd ??= _getTizenNative(nsdDnsSdSymbols);

Tizen80Native? _tizenNsdSsdp;
Tizen80Native get tizenNsdSsdp =>
    _tizenNsdSsdp ??= _getTizenNative(nsdSsdpSymbols);

Tizen80Native? _tizenOauth2;
Tizen80Native get tizenOauth2 =>
    _tizenOauth2 ??= _getTizenNative(oauth2Symbols);

Tizen80Native? _tizenPhonenumberUtils;
Tizen80Native get tizenPhonenumberUtils =>
    _tizenPhonenumberUtils ??= _getTizenNative(phonenumberUtilsSymbols);

Tizen80Native? _tizenPrivilegeInfo;
Tizen80Native get tizenPrivilegeInfo =>
    _tizenPrivilegeInfo ??= _getTizenNative(privilegeInfoSymbols);

Tizen80Native? _tizenPush;
Tizen80Native get tizenPush => _tizenPush ??= _getTizenNative(pushSymbols);

Tizen80Native? _tizenRpcPort;
Tizen80Native get tizenRpcPort =>
    _tizenRpcPort ??= _getTizenNative(rpcPortSymbols);

Tizen80Native? _tizenStorage;
Tizen80Native get tizenStorage =>
    _tizenStorage ??= _getTizenNative(storageSymbols);

Tizen80Native? _tizenSttEngine;
Tizen80Native get tizenSttEngine =>
    _tizenSttEngine ??= _getTizenNative(stt_engineSymbols);

Tizen80Native? _tizenStt;
Tizen80Native get tizenStt => _tizenStt ??= _getTizenNative(sttSymbols);

Tizen80Native? _tizenTbm;
Tizen80Native get tizenTbm => _tizenTbm ??= _getTizenNative(tbmSymbols);

Tizen80Native? _tizenTtrace;
Tizen80Native get tizenTtrace =>
    _tizenTtrace ??= _getTizenNative(ttraceSymbols);

Tizen80Native? _tizenTtsEngine;
Tizen80Native get tizenTtsEngine =>
    _tizenTtsEngine ??= _getTizenNative(tts_engineSymbols);

Tizen80Native? _tizenTts;
Tizen80Native get tizenTts => _tizenTts ??= _getTizenNative(ttsSymbols);

Tizen80Native? _tizenUpdateControl;
Tizen80Native get tizenUpdateControl =>
    _tizenUpdateControl ??= _getTizenNative(updateControlSymbols);

Tizen80Native? _tizenVcEngine;
Tizen80Native get tizenVcEngine =>
    _tizenVcEngine ??= _getTizenNative(vc_engineSymbols);

Tizen80Native? _tizenVcManager;
Tizen80Native get tizenVcManager =>
    _tizenVcManager ??= _getTizenNative(vc_managerSymbols);

Tizen80Native? _tizenVc;
Tizen80Native get tizenVc => _tizenVc ??= _getTizenNative(vcSymbols);

Tizen80Native? _tizenWifiDirect;
Tizen80Native get tizenWifiDirect =>
    _tizenWifiDirect ??= _getTizenNative(wifiDirectSymbols);

Tizen80Native? _tizenYaca;
Tizen80Native get tizenYaca => _tizenYaca ??= _getTizenNative(yacaSymbols);
