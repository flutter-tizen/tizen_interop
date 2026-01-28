library tizen_interop;

import 'dart:ffi';

import '../../src/bindings/6.5/generated_bindings.dart';
import '../../src/lookup_provider.dart';

import 'package:tizen_interop/6.5/tizen_symbols/accounts_svc_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/appcore_agent_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/asp_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/badge_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/bundle_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/calendar_service2_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_appfw_alarm_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_appfw_app_common_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_appfw_app_control_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_appfw_app_control_uri_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_appfw_app_manager_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_appfw_application_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_appfw_event_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_appfw_job_scheduler_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_appfw_package_manager_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_appfw_preference_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_base_common_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_content_media_content_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_content_mime_type_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_context_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_geofence_manager_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_location_manager_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_media_audio_io_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_media_camera_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_media_codec_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_media_controller_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_media_image_util_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_media_metadata_editor_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_media_metadata_extractor_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_media_player_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_media_radio_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_media_recorder_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_media_screen_mirroring_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_media_sound_manager_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_media_sound_pool_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_media_streamer_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_media_streamrecorder_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_media_thumbnail_util_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_media_tone_player_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_media_tool_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_media_wav_player_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_media_webrtc_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_mediademuxer_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_mediamuxer_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_messaging_email_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_network_bluetooth_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_network_connection_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_network_http_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_network_inm_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_network_mtp_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_network_softap_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_network_stc_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_network_wifi_manager_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_nnstreamer_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_nntrainer_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_privacy_privilege_manager_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_system_device_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_system_info_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_system_media_key_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_system_peripheral_io_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_system_runtime_info_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_system_sensor_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_system_system_settings_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_system_usbhost_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_ui_autofill_common_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_ui_autofill_manager_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_ui_autofill_service_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_ui_autofill_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_ui_inputmethod_manager_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_ui_inputmethod_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_vpnsvc_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/capi_web_url_download_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/cbhm_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/cion_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/contacts_service2_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/core_sync_client_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/csr_client_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/data_control_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/device_certificate_manager_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/diagnostics_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/dlog_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/dpm_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/eom_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/feedback_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/fido_client_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/iotcon_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/key_manager_client_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/ma_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/message_port_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/mv_barcode_detector_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/mv_barcode_generator_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/mv_common_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/mv_face_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/mv_image_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/mv_inference_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/mv_surveillance_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/notification_ex_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/notification_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/nsd_dns_sd_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/nsd_ssdp_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/oauth2_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/phonenumber_utils_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/privilege_info_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/push_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/rpc_port_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/shortcut_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/storage_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/stt_engine_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/stt_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/tbm_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/ttrace_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/tts_engine_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/tts_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/update_control_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/vc_engine_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/vc_manager_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/vc_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/wifi_direct_symbols.dart';
import 'package:tizen_interop/6.5/tizen_symbols/yaca_symbols.dart';

export '../../src/bindings/6.5/generated_bindings.dart';
export '../../src/extensions.dart';

final _lookupProvider = LookupProvider();

Tizen65Native _getTizenNative(Map<String, List<String>> symbolMap) {
  return Tizen65Native.fromLookup(
    <T extends NativeType>(String symbolName) {
      _lookupProvider.registerSymbols(symbolMap);
      return _lookupProvider.lookup<T>(symbolName);
    },
  );
}

Tizen65Native? _tizenAccountsSvc;
Tizen65Native get tizenAccountsSvc =>
    _tizenAccountsSvc ??= _getTizenNative(accountsSvcSymbols);

Tizen65Native? _tizenAppcoreAgent;
Tizen65Native get tizenAppcoreAgent =>
    _tizenAppcoreAgent ??= _getTizenNative(appcoreAgentSymbols);

Tizen65Native? _tizenAsp;
Tizen65Native get tizenAsp => _tizenAsp ??= _getTizenNative(aspSymbols);

Tizen65Native? _tizenBadge;
Tizen65Native get tizenBadge => _tizenBadge ??= _getTizenNative(badgeSymbols);

Tizen65Native? _tizenBundle;
Tizen65Native get tizenBundle =>
    _tizenBundle ??= _getTizenNative(bundleSymbols);

Tizen65Native? _tizenCalendarService2;
Tizen65Native get tizenCalendarService2 =>
    _tizenCalendarService2 ??= _getTizenNative(calendarService2Symbols);

Tizen65Native? _tizenCapiAppfwAlarm;
Tizen65Native get tizenCapiAppfwAlarm =>
    _tizenCapiAppfwAlarm ??= _getTizenNative(capiAppfwAlarmSymbols);

Tizen65Native? _tizenCapiAppfwAppCommon;
Tizen65Native get tizenCapiAppfwAppCommon =>
    _tizenCapiAppfwAppCommon ??= _getTizenNative(capiAppfwAppCommonSymbols);

Tizen65Native? _tizenCapiAppfwAppControl;
Tizen65Native get tizenCapiAppfwAppControl =>
    _tizenCapiAppfwAppControl ??= _getTizenNative(capiAppfwAppControlSymbols);

Tizen65Native? _tizenCapiAppfwAppControlUri;
Tizen65Native get tizenCapiAppfwAppControlUri =>
    _tizenCapiAppfwAppControlUri ??=
        _getTizenNative(capiAppfwAppControlUriSymbols);

Tizen65Native? _tizenCapiAppfwAppManager;
Tizen65Native get tizenCapiAppfwAppManager =>
    _tizenCapiAppfwAppManager ??= _getTizenNative(capiAppfwAppManagerSymbols);

Tizen65Native? _tizenCapiAppfwApplication;
Tizen65Native get tizenCapiAppfwApplication =>
    _tizenCapiAppfwApplication ??= _getTizenNative(capiAppfwApplicationSymbols);

Tizen65Native? _tizenCapiAppfwEvent;
Tizen65Native get tizenCapiAppfwEvent =>
    _tizenCapiAppfwEvent ??= _getTizenNative(capiAppfwEventSymbols);

Tizen65Native? _tizenCapiAppfwJobScheduler;
Tizen65Native get tizenCapiAppfwJobScheduler => _tizenCapiAppfwJobScheduler ??=
    _getTizenNative(capiAppfwJobSchedulerSymbols);

Tizen65Native? _tizenCapiAppfwPackageManager;
Tizen65Native get tizenCapiAppfwPackageManager =>
    _tizenCapiAppfwPackageManager ??=
        _getTizenNative(capiAppfwPackageManagerSymbols);

Tizen65Native? _tizenCapiAppfwPreference;
Tizen65Native get tizenCapiAppfwPreference =>
    _tizenCapiAppfwPreference ??= _getTizenNative(capiAppfwPreferenceSymbols);

Tizen65Native? _tizenCapiBaseCommon;
Tizen65Native get tizenCapiBaseCommon =>
    _tizenCapiBaseCommon ??= _getTizenNative(capiBaseCommonSymbols);

Tizen65Native? _tizenCapiContentMediaContent;
Tizen65Native get tizenCapiContentMediaContent =>
    _tizenCapiContentMediaContent ??=
        _getTizenNative(capiContentMediaContentSymbols);

Tizen65Native? _tizenCapiContentMimeType;
Tizen65Native get tizenCapiContentMimeType =>
    _tizenCapiContentMimeType ??= _getTizenNative(capiContentMimeTypeSymbols);

Tizen65Native? _tizenCapiContext;
Tizen65Native get tizenCapiContext =>
    _tizenCapiContext ??= _getTizenNative(capiContextSymbols);

Tizen65Native? _tizenCapiGeofenceManager;
Tizen65Native get tizenCapiGeofenceManager =>
    _tizenCapiGeofenceManager ??= _getTizenNative(capiGeofenceManagerSymbols);

Tizen65Native? _tizenCapiLocationManager;
Tizen65Native get tizenCapiLocationManager =>
    _tizenCapiLocationManager ??= _getTizenNative(capiLocationManagerSymbols);

Tizen65Native? _tizenCapiMediaAudioIo;
Tizen65Native get tizenCapiMediaAudioIo =>
    _tizenCapiMediaAudioIo ??= _getTizenNative(capiMediaAudioIoSymbols);

Tizen65Native? _tizenCapiMediaCamera;
Tizen65Native get tizenCapiMediaCamera =>
    _tizenCapiMediaCamera ??= _getTizenNative(capiMediaCameraSymbols);

Tizen65Native? _tizenCapiMediaCodec;
Tizen65Native get tizenCapiMediaCodec =>
    _tizenCapiMediaCodec ??= _getTizenNative(capiMediaCodecSymbols);

Tizen65Native? _tizenCapiMediaController;
Tizen65Native get tizenCapiMediaController =>
    _tizenCapiMediaController ??= _getTizenNative(capiMediaControllerSymbols);

Tizen65Native? _tizenCapiMediaImageUtil;
Tizen65Native get tizenCapiMediaImageUtil =>
    _tizenCapiMediaImageUtil ??= _getTizenNative(capiMediaImageUtilSymbols);

Tizen65Native? _tizenCapiMediaMetadataEditor;
Tizen65Native get tizenCapiMediaMetadataEditor =>
    _tizenCapiMediaMetadataEditor ??=
        _getTizenNative(capiMediaMetadataEditorSymbols);

Tizen65Native? _tizenCapiMediaMetadataExtractor;
Tizen65Native get tizenCapiMediaMetadataExtractor =>
    _tizenCapiMediaMetadataExtractor ??=
        _getTizenNative(capiMediaMetadataExtractorSymbols);

Tizen65Native? _tizenCapiMediaPlayer;
Tizen65Native get tizenCapiMediaPlayer =>
    _tizenCapiMediaPlayer ??= _getTizenNative(capiMediaPlayerSymbols);

Tizen65Native? _tizenCapiMediaRadio;
Tizen65Native get tizenCapiMediaRadio =>
    _tizenCapiMediaRadio ??= _getTizenNative(capiMediaRadioSymbols);

Tizen65Native? _tizenCapiMediaRecorder;
Tizen65Native get tizenCapiMediaRecorder =>
    _tizenCapiMediaRecorder ??= _getTizenNative(capiMediaRecorderSymbols);

Tizen65Native? _tizenCapiMediaScreenMirroring;
Tizen65Native get tizenCapiMediaScreenMirroring =>
    _tizenCapiMediaScreenMirroring ??=
        _getTizenNative(capiMediaScreenMirroringSymbols);

Tizen65Native? _tizenCapiMediaSoundManager;
Tizen65Native get tizenCapiMediaSoundManager => _tizenCapiMediaSoundManager ??=
    _getTizenNative(capiMediaSoundManagerSymbols);

Tizen65Native? _tizenCapiMediaSoundPool;
Tizen65Native get tizenCapiMediaSoundPool =>
    _tizenCapiMediaSoundPool ??= _getTizenNative(capiMediaSoundPoolSymbols);

Tizen65Native? _tizenCapiMediaStreamer;
Tizen65Native get tizenCapiMediaStreamer =>
    _tizenCapiMediaStreamer ??= _getTizenNative(capiMediaStreamerSymbols);

Tizen65Native? _tizenCapiMediaStreamrecorder;
Tizen65Native get tizenCapiMediaStreamrecorder =>
    _tizenCapiMediaStreamrecorder ??=
        _getTizenNative(capiMediaStreamrecorderSymbols);

Tizen65Native? _tizenCapiMediaThumbnailUtil;
Tizen65Native get tizenCapiMediaThumbnailUtil =>
    _tizenCapiMediaThumbnailUtil ??=
        _getTizenNative(capiMediaThumbnailUtilSymbols);

Tizen65Native? _tizenCapiMediaTonePlayer;
Tizen65Native get tizenCapiMediaTonePlayer =>
    _tizenCapiMediaTonePlayer ??= _getTizenNative(capiMediaTonePlayerSymbols);

Tizen65Native? _tizenCapiMediaTool;
Tizen65Native get tizenCapiMediaTool =>
    _tizenCapiMediaTool ??= _getTizenNative(capiMediaToolSymbols);

Tizen65Native? _tizenCapiMediaWavPlayer;
Tizen65Native get tizenCapiMediaWavPlayer =>
    _tizenCapiMediaWavPlayer ??= _getTizenNative(capiMediaWavPlayerSymbols);

Tizen65Native? _tizenCapiMediaWebrtc;
Tizen65Native get tizenCapiMediaWebrtc =>
    _tizenCapiMediaWebrtc ??= _getTizenNative(capiMediaWebrtcSymbols);

Tizen65Native? _tizenCapiMediademuxer;
Tizen65Native get tizenCapiMediademuxer =>
    _tizenCapiMediademuxer ??= _getTizenNative(capiMediademuxerSymbols);

Tizen65Native? _tizenCapiMediamuxer;
Tizen65Native get tizenCapiMediamuxer =>
    _tizenCapiMediamuxer ??= _getTizenNative(capiMediamuxerSymbols);

Tizen65Native? _tizenCapiMessagingEmail;
Tizen65Native get tizenCapiMessagingEmail =>
    _tizenCapiMessagingEmail ??= _getTizenNative(capiMessagingEmailSymbols);

Tizen65Native? _tizenCapiNetworkBluetooth;
Tizen65Native get tizenCapiNetworkBluetooth =>
    _tizenCapiNetworkBluetooth ??= _getTizenNative(capiNetworkBluetoothSymbols);

Tizen65Native? _tizenCapiNetworkConnection;
Tizen65Native get tizenCapiNetworkConnection => _tizenCapiNetworkConnection ??=
    _getTizenNative(capiNetworkConnectionSymbols);

Tizen65Native? _tizenCapiNetworkHttp;
Tizen65Native get tizenCapiNetworkHttp =>
    _tizenCapiNetworkHttp ??= _getTizenNative(capiNetworkHttpSymbols);

Tizen65Native? _tizenCapiNetworkInm;
Tizen65Native get tizenCapiNetworkInm =>
    _tizenCapiNetworkInm ??= _getTizenNative(capiNetworkInmSymbols);

Tizen65Native? _tizenCapiNetworkMtp;
Tizen65Native get tizenCapiNetworkMtp =>
    _tizenCapiNetworkMtp ??= _getTizenNative(capiNetworkMtpSymbols);

Tizen65Native? _tizenCapiNetworkSoftap;
Tizen65Native get tizenCapiNetworkSoftap =>
    _tizenCapiNetworkSoftap ??= _getTizenNative(capiNetworkSoftapSymbols);

Tizen65Native? _tizenCapiNetworkStc;
Tizen65Native get tizenCapiNetworkStc =>
    _tizenCapiNetworkStc ??= _getTizenNative(capiNetworkStcSymbols);

Tizen65Native? _tizenCapiNetworkWifiManager;
Tizen65Native get tizenCapiNetworkWifiManager =>
    _tizenCapiNetworkWifiManager ??=
        _getTizenNative(capiNetworkWifiManagerSymbols);

Tizen65Native? _tizenCapiNnstreamer;
Tizen65Native get tizenCapiNnstreamer =>
    _tizenCapiNnstreamer ??= _getTizenNative(capiNnstreamerSymbols);

Tizen65Native? _tizenCapiNntrainer;
Tizen65Native get tizenCapiNntrainer =>
    _tizenCapiNntrainer ??= _getTizenNative(capiNntrainerSymbols);

Tizen65Native? _tizenCapiPrivacyPrivilegeManager;
Tizen65Native get tizenCapiPrivacyPrivilegeManager =>
    _tizenCapiPrivacyPrivilegeManager ??=
        _getTizenNative(capiPrivacyPrivilegeManagerSymbols);

Tizen65Native? _tizenCapiSystemDevice;
Tizen65Native get tizenCapiSystemDevice =>
    _tizenCapiSystemDevice ??= _getTizenNative(capiSystemDeviceSymbols);

Tizen65Native? _tizenCapiSystemInfo;
Tizen65Native get tizenCapiSystemInfo =>
    _tizenCapiSystemInfo ??= _getTizenNative(capiSystemInfoSymbols);

Tizen65Native? _tizenCapiSystemMediaKey;
Tizen65Native get tizenCapiSystemMediaKey =>
    _tizenCapiSystemMediaKey ??= _getTizenNative(capiSystemMediaKeySymbols);

Tizen65Native? _tizenCapiSystemPeripheralIo;
Tizen65Native get tizenCapiSystemPeripheralIo =>
    _tizenCapiSystemPeripheralIo ??=
        _getTizenNative(capiSystemPeripheralIoSymbols);

Tizen65Native? _tizenCapiSystemRuntimeInfo;
Tizen65Native get tizenCapiSystemRuntimeInfo => _tizenCapiSystemRuntimeInfo ??=
    _getTizenNative(capiSystemRuntimeInfoSymbols);

Tizen65Native? _tizenCapiSystemSensor;
Tizen65Native get tizenCapiSystemSensor =>
    _tizenCapiSystemSensor ??= _getTizenNative(capiSystemSensorSymbols);

Tizen65Native? _tizenCapiSystemSystemSettings;
Tizen65Native get tizenCapiSystemSystemSettings =>
    _tizenCapiSystemSystemSettings ??=
        _getTizenNative(capiSystemSystemSettingsSymbols);

Tizen65Native? _tizenCapiSystemUsbhost;
Tizen65Native get tizenCapiSystemUsbhost =>
    _tizenCapiSystemUsbhost ??= _getTizenNative(capiSystemUsbhostSymbols);

Tizen65Native? _tizenCapiUiAutofillCommon;
Tizen65Native get tizenCapiUiAutofillCommon =>
    _tizenCapiUiAutofillCommon ??= _getTizenNative(capiUiAutofillCommonSymbols);

Tizen65Native? _tizenCapiUiAutofillManager;
Tizen65Native get tizenCapiUiAutofillManager => _tizenCapiUiAutofillManager ??=
    _getTizenNative(capiUiAutofillManagerSymbols);

Tizen65Native? _tizenCapiUiAutofillService;
Tizen65Native get tizenCapiUiAutofillService => _tizenCapiUiAutofillService ??=
    _getTizenNative(capiUiAutofillServiceSymbols);

Tizen65Native? _tizenCapiUiAutofill;
Tizen65Native get tizenCapiUiAutofill =>
    _tizenCapiUiAutofill ??= _getTizenNative(capiUiAutofillSymbols);

Tizen65Native? _tizenCapiUiInputmethodManager;
Tizen65Native get tizenCapiUiInputmethodManager =>
    _tizenCapiUiInputmethodManager ??=
        _getTizenNative(capiUiInputmethodManagerSymbols);

Tizen65Native? _tizenCapiUiInputmethod;
Tizen65Native get tizenCapiUiInputmethod =>
    _tizenCapiUiInputmethod ??= _getTizenNative(capiUiInputmethodSymbols);

Tizen65Native? _tizenCapiVpnsvc;
Tizen65Native get tizenCapiVpnsvc =>
    _tizenCapiVpnsvc ??= _getTizenNative(capiVpnsvcSymbols);

Tizen65Native? _tizenCapiWebUrlDownload;
Tizen65Native get tizenCapiWebUrlDownload =>
    _tizenCapiWebUrlDownload ??= _getTizenNative(capiWebUrlDownloadSymbols);

Tizen65Native? _tizenCbhm;
Tizen65Native get tizenCbhm => _tizenCbhm ??= _getTizenNative(cbhmSymbols);

Tizen65Native? _tizenCion;
Tizen65Native get tizenCion => _tizenCion ??= _getTizenNative(cionSymbols);

Tizen65Native? _tizenContactsService2;
Tizen65Native get tizenContactsService2 =>
    _tizenContactsService2 ??= _getTizenNative(contactsService2Symbols);

Tizen65Native? _tizenCoreSyncClient;
Tizen65Native get tizenCoreSyncClient =>
    _tizenCoreSyncClient ??= _getTizenNative(coreSyncClientSymbols);

Tizen65Native? _tizenCsrClient;
Tizen65Native get tizenCsrClient =>
    _tizenCsrClient ??= _getTizenNative(csrClientSymbols);

Tizen65Native? _tizenDataControl;
Tizen65Native get tizenDataControl =>
    _tizenDataControl ??= _getTizenNative(dataControlSymbols);

Tizen65Native? _tizenDeviceCertificateManager;
Tizen65Native get tizenDeviceCertificateManager =>
    _tizenDeviceCertificateManager ??=
        _getTizenNative(deviceCertificateManagerSymbols);

Tizen65Native? _tizenDiagnostics;
Tizen65Native get tizenDiagnostics =>
    _tizenDiagnostics ??= _getTizenNative(diagnosticsSymbols);

Tizen65Native? _tizenDlog;
Tizen65Native get tizenDlog => _tizenDlog ??= _getTizenNative(dlogSymbols);

Tizen65Native? _tizenDpm;
Tizen65Native get tizenDpm => _tizenDpm ??= _getTizenNative(dpmSymbols);

Tizen65Native? _tizenEom;
Tizen65Native get tizenEom => _tizenEom ??= _getTizenNative(eomSymbols);

Tizen65Native? _tizenFeedback;
Tizen65Native get tizenFeedback =>
    _tizenFeedback ??= _getTizenNative(feedbackSymbols);

Tizen65Native? _tizenFidoClient;
Tizen65Native get tizenFidoClient =>
    _tizenFidoClient ??= _getTizenNative(fidoClientSymbols);

Tizen65Native? _tizenIotcon;
Tizen65Native get tizenIotcon =>
    _tizenIotcon ??= _getTizenNative(iotconSymbols);

Tizen65Native? _tizenKeyManagerClient;
Tizen65Native get tizenKeyManagerClient =>
    _tizenKeyManagerClient ??= _getTizenNative(keyManagerClientSymbols);

Tizen65Native? _tizenMa;
Tizen65Native get tizenMa => _tizenMa ??= _getTizenNative(maSymbols);

Tizen65Native? _tizenMessagePort;
Tizen65Native get tizenMessagePort =>
    _tizenMessagePort ??= _getTizenNative(messagePortSymbols);

Tizen65Native? _tizenMvBarcodeDetector;
Tizen65Native get tizenMvBarcodeDetector =>
    _tizenMvBarcodeDetector ??= _getTizenNative(mv_barcode_detectorSymbols);

Tizen65Native? _tizenMvBarcodeGenerator;
Tizen65Native get tizenMvBarcodeGenerator =>
    _tizenMvBarcodeGenerator ??= _getTizenNative(mv_barcode_generatorSymbols);

Tizen65Native? _tizenMvCommon;
Tizen65Native get tizenMvCommon =>
    _tizenMvCommon ??= _getTizenNative(mv_commonSymbols);

Tizen65Native? _tizenMvFace;
Tizen65Native get tizenMvFace =>
    _tizenMvFace ??= _getTizenNative(mv_faceSymbols);

Tizen65Native? _tizenMvImage;
Tizen65Native get tizenMvImage =>
    _tizenMvImage ??= _getTizenNative(mv_imageSymbols);

Tizen65Native? _tizenMvInference;
Tizen65Native get tizenMvInference =>
    _tizenMvInference ??= _getTizenNative(mv_inferenceSymbols);

Tizen65Native? _tizenMvSurveillance;
Tizen65Native get tizenMvSurveillance =>
    _tizenMvSurveillance ??= _getTizenNative(mv_surveillanceSymbols);

Tizen65Native? _tizenNotificationEx;
Tizen65Native get tizenNotificationEx =>
    _tizenNotificationEx ??= _getTizenNative(notificationExSymbols);

Tizen65Native? _tizenNotification;
Tizen65Native get tizenNotification =>
    _tizenNotification ??= _getTizenNative(notificationSymbols);

Tizen65Native? _tizenNsdDnsSd;
Tizen65Native get tizenNsdDnsSd =>
    _tizenNsdDnsSd ??= _getTizenNative(nsdDnsSdSymbols);

Tizen65Native? _tizenNsdSsdp;
Tizen65Native get tizenNsdSsdp =>
    _tizenNsdSsdp ??= _getTizenNative(nsdSsdpSymbols);

Tizen65Native? _tizenOauth2;
Tizen65Native get tizenOauth2 =>
    _tizenOauth2 ??= _getTizenNative(oauth2Symbols);

Tizen65Native? _tizenPhonenumberUtils;
Tizen65Native get tizenPhonenumberUtils =>
    _tizenPhonenumberUtils ??= _getTizenNative(phonenumberUtilsSymbols);

Tizen65Native? _tizenPrivilegeInfo;
Tizen65Native get tizenPrivilegeInfo =>
    _tizenPrivilegeInfo ??= _getTizenNative(privilegeInfoSymbols);

Tizen65Native? _tizenPush;
Tizen65Native get tizenPush => _tizenPush ??= _getTizenNative(pushSymbols);

Tizen65Native? _tizenRpcPort;
Tizen65Native get tizenRpcPort =>
    _tizenRpcPort ??= _getTizenNative(rpcPortSymbols);

Tizen65Native? _tizenShortcut;
Tizen65Native get tizenShortcut =>
    _tizenShortcut ??= _getTizenNative(shortcutSymbols);

Tizen65Native? _tizenStorage;
Tizen65Native get tizenStorage =>
    _tizenStorage ??= _getTizenNative(storageSymbols);

Tizen65Native? _tizenSttEngine;
Tizen65Native get tizenSttEngine =>
    _tizenSttEngine ??= _getTizenNative(stt_engineSymbols);

Tizen65Native? _tizenStt;
Tizen65Native get tizenStt => _tizenStt ??= _getTizenNative(sttSymbols);

Tizen65Native? _tizenTbm;
Tizen65Native get tizenTbm => _tizenTbm ??= _getTizenNative(tbmSymbols);

Tizen65Native? _tizenTtrace;
Tizen65Native get tizenTtrace =>
    _tizenTtrace ??= _getTizenNative(ttraceSymbols);

Tizen65Native? _tizenTtsEngine;
Tizen65Native get tizenTtsEngine =>
    _tizenTtsEngine ??= _getTizenNative(tts_engineSymbols);

Tizen65Native? _tizenTts;
Tizen65Native get tizenTts => _tizenTts ??= _getTizenNative(ttsSymbols);

Tizen65Native? _tizenUpdateControl;
Tizen65Native get tizenUpdateControl =>
    _tizenUpdateControl ??= _getTizenNative(updateControlSymbols);

Tizen65Native? _tizenVcEngine;
Tizen65Native get tizenVcEngine =>
    _tizenVcEngine ??= _getTizenNative(vc_engineSymbols);

Tizen65Native? _tizenVcManager;
Tizen65Native get tizenVcManager =>
    _tizenVcManager ??= _getTizenNative(vc_managerSymbols);

Tizen65Native? _tizenVc;
Tizen65Native get tizenVc => _tizenVc ??= _getTizenNative(vcSymbols);

Tizen65Native? _tizenWifiDirect;
Tizen65Native get tizenWifiDirect =>
    _tizenWifiDirect ??= _getTizenNative(wifiDirectSymbols);

Tizen65Native? _tizenYaca;
Tizen65Native get tizenYaca => _tizenYaca ??= _getTizenNative(yacaSymbols);
