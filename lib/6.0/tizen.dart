library tizen_interop;

import 'dart:ffi';

import '../../src/bindings/6.0/generated_bindings.dart';
import '../../src/bindings/6.0/generated_symbols.dart';
import '../../src/lookup_provider.dart';

export '../../src/bindings/6.0/generated_bindings.dart';
export '../../src/extensions.dart';

final _lookupProvider = LookupProvider();

Tizen60Native _getTizenNative(Map<String, List<String>> symbolMap) {
  return Tizen60Native.fromLookup(
    <T extends NativeType>(String symbolName) {
      _lookupProvider.registerSymbols(symbolMap);
      return _lookupProvider.lookup<T>(symbolName);
    },
  );
}

Tizen60Native? _tizenAccountsSvc;
Tizen60Native get tizenAccountsSvc =>
    _tizenAccountsSvc ??= _getTizenNative(accountsSvcSymbols);

Tizen60Native? _tizenAppcoreAgent;
Tizen60Native get tizenAppcoreAgent =>
    _tizenAppcoreAgent ??= _getTizenNative(appcoreAgentSymbols);

Tizen60Native? _tizenAsp;
Tizen60Native get tizenAsp => _tizenAsp ??= _getTizenNative(aspSymbols);

Tizen60Native? _tizenBadge;
Tizen60Native get tizenBadge => _tizenBadge ??= _getTizenNative(badgeSymbols);

Tizen60Native? _tizenBundle;
Tizen60Native get tizenBundle =>
    _tizenBundle ??= _getTizenNative(bundleSymbols);

Tizen60Native? _tizenCalendarService2;
Tizen60Native get tizenCalendarService2 =>
    _tizenCalendarService2 ??= _getTizenNative(calendarService2Symbols);

Tizen60Native? _tizenCapiAppfwAlarm;
Tizen60Native get tizenCapiAppfwAlarm =>
    _tizenCapiAppfwAlarm ??= _getTizenNative(capiAppfwAlarmSymbols);

Tizen60Native? _tizenCapiAppfwAppCommon;
Tizen60Native get tizenCapiAppfwAppCommon =>
    _tizenCapiAppfwAppCommon ??= _getTizenNative(capiAppfwAppCommonSymbols);

Tizen60Native? _tizenCapiAppfwAppControl;
Tizen60Native get tizenCapiAppfwAppControl =>
    _tizenCapiAppfwAppControl ??= _getTizenNative(capiAppfwAppControlSymbols);

Tizen60Native? _tizenCapiAppfwAppManager;
Tizen60Native get tizenCapiAppfwAppManager =>
    _tizenCapiAppfwAppManager ??= _getTizenNative(capiAppfwAppManagerSymbols);

Tizen60Native? _tizenCapiAppfwApplication;
Tizen60Native get tizenCapiAppfwApplication =>
    _tizenCapiAppfwApplication ??= _getTizenNative(capiAppfwApplicationSymbols);

Tizen60Native? _tizenCapiAppfwEvent;
Tizen60Native get tizenCapiAppfwEvent =>
    _tizenCapiAppfwEvent ??= _getTizenNative(capiAppfwEventSymbols);

Tizen60Native? _tizenCapiAppfwJobScheduler;
Tizen60Native get tizenCapiAppfwJobScheduler => _tizenCapiAppfwJobScheduler ??=
    _getTizenNative(capiAppfwJobSchedulerSymbols);

Tizen60Native? _tizenCapiAppfwPackageManager;
Tizen60Native get tizenCapiAppfwPackageManager =>
    _tizenCapiAppfwPackageManager ??=
        _getTizenNative(capiAppfwPackageManagerSymbols);

Tizen60Native? _tizenCapiAppfwPreference;
Tizen60Native get tizenCapiAppfwPreference =>
    _tizenCapiAppfwPreference ??= _getTizenNative(capiAppfwPreferenceSymbols);

Tizen60Native? _tizenCapiBaseCommon;
Tizen60Native get tizenCapiBaseCommon =>
    _tizenCapiBaseCommon ??= _getTizenNative(capiBaseCommonSymbols);

Tizen60Native? _tizenCapiContentMediaContent;
Tizen60Native get tizenCapiContentMediaContent =>
    _tizenCapiContentMediaContent ??=
        _getTizenNative(capiContentMediaContentSymbols);

Tizen60Native? _tizenCapiContentMimeType;
Tizen60Native get tizenCapiContentMimeType =>
    _tizenCapiContentMimeType ??= _getTizenNative(capiContentMimeTypeSymbols);

Tizen60Native? _tizenCapiContextMotion;
Tizen60Native get tizenCapiContextMotion =>
    _tizenCapiContextMotion ??= _getTizenNative(capiContextMotionSymbols);

Tizen60Native? _tizenCapiContext;
Tizen60Native get tizenCapiContext =>
    _tizenCapiContext ??= _getTizenNative(capiContextSymbols);

Tizen60Native? _tizenCapiGeofenceManager;
Tizen60Native get tizenCapiGeofenceManager =>
    _tizenCapiGeofenceManager ??= _getTizenNative(capiGeofenceManagerSymbols);

Tizen60Native? _tizenCapiLocationManager;
Tizen60Native get tizenCapiLocationManager =>
    _tizenCapiLocationManager ??= _getTizenNative(capiLocationManagerSymbols);

Tizen60Native? _tizenCapiMediaAudioIo;
Tizen60Native get tizenCapiMediaAudioIo =>
    _tizenCapiMediaAudioIo ??= _getTizenNative(capiMediaAudioIoSymbols);

Tizen60Native? _tizenCapiMediaCamera;
Tizen60Native get tizenCapiMediaCamera =>
    _tizenCapiMediaCamera ??= _getTizenNative(capiMediaCameraSymbols);

Tizen60Native? _tizenCapiMediaCodec;
Tizen60Native get tizenCapiMediaCodec =>
    _tizenCapiMediaCodec ??= _getTizenNative(capiMediaCodecSymbols);

Tizen60Native? _tizenCapiMediaController;
Tizen60Native get tizenCapiMediaController =>
    _tizenCapiMediaController ??= _getTizenNative(capiMediaControllerSymbols);

Tizen60Native? _tizenCapiMediaImageUtil;
Tizen60Native get tizenCapiMediaImageUtil =>
    _tizenCapiMediaImageUtil ??= _getTizenNative(capiMediaImageUtilSymbols);

Tizen60Native? _tizenCapiMediaMetadataEditor;
Tizen60Native get tizenCapiMediaMetadataEditor =>
    _tizenCapiMediaMetadataEditor ??=
        _getTizenNative(capiMediaMetadataEditorSymbols);

Tizen60Native? _tizenCapiMediaMetadataExtractor;
Tizen60Native get tizenCapiMediaMetadataExtractor =>
    _tizenCapiMediaMetadataExtractor ??=
        _getTizenNative(capiMediaMetadataExtractorSymbols);

Tizen60Native? _tizenCapiMediaPlayer;
Tizen60Native get tizenCapiMediaPlayer =>
    _tizenCapiMediaPlayer ??= _getTizenNative(capiMediaPlayerSymbols);

Tizen60Native? _tizenCapiMediaRadio;
Tizen60Native get tizenCapiMediaRadio =>
    _tizenCapiMediaRadio ??= _getTizenNative(capiMediaRadioSymbols);

Tizen60Native? _tizenCapiMediaRecorder;
Tizen60Native get tizenCapiMediaRecorder =>
    _tizenCapiMediaRecorder ??= _getTizenNative(capiMediaRecorderSymbols);

Tizen60Native? _tizenCapiMediaScreenMirroring;
Tizen60Native get tizenCapiMediaScreenMirroring =>
    _tizenCapiMediaScreenMirroring ??=
        _getTizenNative(capiMediaScreenMirroringSymbols);

Tizen60Native? _tizenCapiMediaSoundManager;
Tizen60Native get tizenCapiMediaSoundManager => _tizenCapiMediaSoundManager ??=
    _getTizenNative(capiMediaSoundManagerSymbols);

Tizen60Native? _tizenCapiMediaSoundPool;
Tizen60Native get tizenCapiMediaSoundPool =>
    _tizenCapiMediaSoundPool ??= _getTizenNative(capiMediaSoundPoolSymbols);

Tizen60Native? _tizenCapiMediaStreamer;
Tizen60Native get tizenCapiMediaStreamer =>
    _tizenCapiMediaStreamer ??= _getTizenNative(capiMediaStreamerSymbols);

Tizen60Native? _tizenCapiMediaStreamrecorder;
Tizen60Native get tizenCapiMediaStreamrecorder =>
    _tizenCapiMediaStreamrecorder ??=
        _getTizenNative(capiMediaStreamrecorderSymbols);

Tizen60Native? _tizenCapiMediaThumbnailUtil;
Tizen60Native get tizenCapiMediaThumbnailUtil =>
    _tizenCapiMediaThumbnailUtil ??=
        _getTizenNative(capiMediaThumbnailUtilSymbols);

Tizen60Native? _tizenCapiMediaTonePlayer;
Tizen60Native get tizenCapiMediaTonePlayer =>
    _tizenCapiMediaTonePlayer ??= _getTizenNative(capiMediaTonePlayerSymbols);

Tizen60Native? _tizenCapiMediaTool;
Tizen60Native get tizenCapiMediaTool =>
    _tizenCapiMediaTool ??= _getTizenNative(capiMediaToolSymbols);

Tizen60Native? _tizenCapiMediaWavPlayer;
Tizen60Native get tizenCapiMediaWavPlayer =>
    _tizenCapiMediaWavPlayer ??= _getTizenNative(capiMediaWavPlayerSymbols);

Tizen60Native? _tizenCapiMediademuxer;
Tizen60Native get tizenCapiMediademuxer =>
    _tizenCapiMediademuxer ??= _getTizenNative(capiMediademuxerSymbols);

Tizen60Native? _tizenCapiMediamuxer;
Tizen60Native get tizenCapiMediamuxer =>
    _tizenCapiMediamuxer ??= _getTizenNative(capiMediamuxerSymbols);

Tizen60Native? _tizenCapiMessagingEmail;
Tizen60Native get tizenCapiMessagingEmail =>
    _tizenCapiMessagingEmail ??= _getTizenNative(capiMessagingEmailSymbols);

Tizen60Native? _tizenCapiNetworkBluetooth;
Tizen60Native get tizenCapiNetworkBluetooth =>
    _tizenCapiNetworkBluetooth ??= _getTizenNative(capiNetworkBluetoothSymbols);

Tizen60Native? _tizenCapiNetworkConnection;
Tizen60Native get tizenCapiNetworkConnection => _tizenCapiNetworkConnection ??=
    _getTizenNative(capiNetworkConnectionSymbols);

Tizen60Native? _tizenCapiNetworkHttp;
Tizen60Native get tizenCapiNetworkHttp =>
    _tizenCapiNetworkHttp ??= _getTizenNative(capiNetworkHttpSymbols);

Tizen60Native? _tizenCapiNetworkInm;
Tizen60Native get tizenCapiNetworkInm =>
    _tizenCapiNetworkInm ??= _getTizenNative(capiNetworkInmSymbols);

Tizen60Native? _tizenCapiNetworkMtp;
Tizen60Native get tizenCapiNetworkMtp =>
    _tizenCapiNetworkMtp ??= _getTizenNative(capiNetworkMtpSymbols);

Tizen60Native? _tizenCapiNetworkSoftap;
Tizen60Native get tizenCapiNetworkSoftap =>
    _tizenCapiNetworkSoftap ??= _getTizenNative(capiNetworkSoftapSymbols);

Tizen60Native? _tizenCapiNetworkStc;
Tizen60Native get tizenCapiNetworkStc =>
    _tizenCapiNetworkStc ??= _getTizenNative(capiNetworkStcSymbols);

Tizen60Native? _tizenCapiNetworkWifiManager;
Tizen60Native get tizenCapiNetworkWifiManager =>
    _tizenCapiNetworkWifiManager ??=
        _getTizenNative(capiNetworkWifiManagerSymbols);

Tizen60Native? _tizenCapiPrivacyPrivilegeManager;
Tizen60Native get tizenCapiPrivacyPrivilegeManager =>
    _tizenCapiPrivacyPrivilegeManager ??=
        _getTizenNative(capiPrivacyPrivilegeManagerSymbols);

Tizen60Native? _tizenCapiSystemDevice;
Tizen60Native get tizenCapiSystemDevice =>
    _tizenCapiSystemDevice ??= _getTizenNative(capiSystemDeviceSymbols);

Tizen60Native? _tizenCapiSystemInfo;
Tizen60Native get tizenCapiSystemInfo =>
    _tizenCapiSystemInfo ??= _getTizenNative(capiSystemInfoSymbols);

Tizen60Native? _tizenCapiSystemMediaKey;
Tizen60Native get tizenCapiSystemMediaKey =>
    _tizenCapiSystemMediaKey ??= _getTizenNative(capiSystemMediaKeySymbols);

Tizen60Native? _tizenCapiSystemPeripheralIo;
Tizen60Native get tizenCapiSystemPeripheralIo =>
    _tizenCapiSystemPeripheralIo ??=
        _getTizenNative(capiSystemPeripheralIoSymbols);

Tizen60Native? _tizenCapiSystemRuntimeInfo;
Tizen60Native get tizenCapiSystemRuntimeInfo => _tizenCapiSystemRuntimeInfo ??=
    _getTizenNative(capiSystemRuntimeInfoSymbols);

Tizen60Native? _tizenCapiSystemSensor;
Tizen60Native get tizenCapiSystemSensor =>
    _tizenCapiSystemSensor ??= _getTizenNative(capiSystemSensorSymbols);

Tizen60Native? _tizenCapiSystemSystemSettings;
Tizen60Native get tizenCapiSystemSystemSettings =>
    _tizenCapiSystemSystemSettings ??=
        _getTizenNative(capiSystemSystemSettingsSymbols);

Tizen60Native? _tizenCapiSystemUsbhost;
Tizen60Native get tizenCapiSystemUsbhost =>
    _tizenCapiSystemUsbhost ??= _getTizenNative(capiSystemUsbhostSymbols);

Tizen60Native? _tizenCapiUiAutofillCommon;
Tizen60Native get tizenCapiUiAutofillCommon =>
    _tizenCapiUiAutofillCommon ??= _getTizenNative(capiUiAutofillCommonSymbols);

Tizen60Native? _tizenCapiUiAutofillManager;
Tizen60Native get tizenCapiUiAutofillManager => _tizenCapiUiAutofillManager ??=
    _getTizenNative(capiUiAutofillManagerSymbols);

Tizen60Native? _tizenCapiUiAutofillService;
Tizen60Native get tizenCapiUiAutofillService => _tizenCapiUiAutofillService ??=
    _getTizenNative(capiUiAutofillServiceSymbols);

Tizen60Native? _tizenCapiUiAutofill;
Tizen60Native get tizenCapiUiAutofill =>
    _tizenCapiUiAutofill ??= _getTizenNative(capiUiAutofillSymbols);

Tizen60Native? _tizenCapiUiInputmethodManager;
Tizen60Native get tizenCapiUiInputmethodManager =>
    _tizenCapiUiInputmethodManager ??=
        _getTizenNative(capiUiInputmethodManagerSymbols);

Tizen60Native? _tizenCapiUiInputmethod;
Tizen60Native get tizenCapiUiInputmethod =>
    _tizenCapiUiInputmethod ??= _getTizenNative(capiUiInputmethodSymbols);

Tizen60Native? _tizenCapiVpnsvc;
Tizen60Native get tizenCapiVpnsvc =>
    _tizenCapiVpnsvc ??= _getTizenNative(capiVpnsvcSymbols);

Tizen60Native? _tizenCapiWebUrlDownload;
Tizen60Native get tizenCapiWebUrlDownload =>
    _tizenCapiWebUrlDownload ??= _getTizenNative(capiWebUrlDownloadSymbols);

Tizen60Native? _tizenCbhm;
Tizen60Native get tizenCbhm => _tizenCbhm ??= _getTizenNative(cbhmSymbols);

Tizen60Native? _tizenContactsService2;
Tizen60Native get tizenContactsService2 =>
    _tizenContactsService2 ??= _getTizenNative(contactsService2Symbols);

Tizen60Native? _tizenCoreSyncClient;
Tizen60Native get tizenCoreSyncClient =>
    _tizenCoreSyncClient ??= _getTizenNative(coreSyncClientSymbols);

Tizen60Native? _tizenCsrClient;
Tizen60Native get tizenCsrClient =>
    _tizenCsrClient ??= _getTizenNative(csrClientSymbols);

Tizen60Native? _tizenDataControl;
Tizen60Native get tizenDataControl =>
    _tizenDataControl ??= _getTizenNative(dataControlSymbols);

Tizen60Native? _tizenDeviceCertificateManager;
Tizen60Native get tizenDeviceCertificateManager =>
    _tizenDeviceCertificateManager ??=
        _getTizenNative(deviceCertificateManagerSymbols);

Tizen60Native? _tizenDiagnostics;
Tizen60Native get tizenDiagnostics =>
    _tizenDiagnostics ??= _getTizenNative(diagnosticsSymbols);

Tizen60Native? _tizenDlog;
Tizen60Native get tizenDlog => _tizenDlog ??= _getTizenNative(dlogSymbols);

Tizen60Native? _tizenDpm;
Tizen60Native get tizenDpm => _tizenDpm ??= _getTizenNative(dpmSymbols);

Tizen60Native? _tizenEom;
Tizen60Native get tizenEom => _tizenEom ??= _getTizenNative(eomSymbols);

Tizen60Native? _tizenFeedback;
Tizen60Native get tizenFeedback =>
    _tizenFeedback ??= _getTizenNative(feedbackSymbols);

Tizen60Native? _tizenFidoClient;
Tizen60Native get tizenFidoClient =>
    _tizenFidoClient ??= _getTizenNative(fidoClientSymbols);

Tizen60Native? _tizenIotcon;
Tizen60Native get tizenIotcon =>
    _tizenIotcon ??= _getTizenNative(iotconSymbols);

Tizen60Native? _tizenKeyManagerClient;
Tizen60Native get tizenKeyManagerClient =>
    _tizenKeyManagerClient ??= _getTizenNative(keyManagerClientSymbols);

Tizen60Native? _tizenMa;
Tizen60Native get tizenMa => _tizenMa ??= _getTizenNative(maSymbols);

Tizen60Native? _tizenMessagePort;
Tizen60Native get tizenMessagePort =>
    _tizenMessagePort ??= _getTizenNative(messagePortSymbols);

Tizen60Native? _tizenMvBarcodeDetector;
Tizen60Native get tizenMvBarcodeDetector =>
    _tizenMvBarcodeDetector ??= _getTizenNative(mv_barcode_detectorSymbols);

Tizen60Native? _tizenMvBarcodeGenerator;
Tizen60Native get tizenMvBarcodeGenerator =>
    _tizenMvBarcodeGenerator ??= _getTizenNative(mv_barcode_generatorSymbols);

Tizen60Native? _tizenMvCommon;
Tizen60Native get tizenMvCommon =>
    _tizenMvCommon ??= _getTizenNative(mv_commonSymbols);

Tizen60Native? _tizenMvFace;
Tizen60Native get tizenMvFace =>
    _tizenMvFace ??= _getTizenNative(mv_faceSymbols);

Tizen60Native? _tizenMvImage;
Tizen60Native get tizenMvImage =>
    _tizenMvImage ??= _getTizenNative(mv_imageSymbols);

Tizen60Native? _tizenMvInference;
Tizen60Native get tizenMvInference =>
    _tizenMvInference ??= _getTizenNative(mv_inferenceSymbols);

Tizen60Native? _tizenMvSurveillance;
Tizen60Native get tizenMvSurveillance =>
    _tizenMvSurveillance ??= _getTizenNative(mv_surveillanceSymbols);

Tizen60Native? _tizenNotificationEx;
Tizen60Native get tizenNotificationEx =>
    _tizenNotificationEx ??= _getTizenNative(notificationExSymbols);

Tizen60Native? _tizenNotification;
Tizen60Native get tizenNotification =>
    _tizenNotification ??= _getTizenNative(notificationSymbols);

Tizen60Native? _tizenNsdDnsSd;
Tizen60Native get tizenNsdDnsSd =>
    _tizenNsdDnsSd ??= _getTizenNative(nsdDnsSdSymbols);

Tizen60Native? _tizenNsdSsdp;
Tizen60Native get tizenNsdSsdp =>
    _tizenNsdSsdp ??= _getTizenNative(nsdSsdpSymbols);

Tizen60Native? _tizenOauth2;
Tizen60Native get tizenOauth2 =>
    _tizenOauth2 ??= _getTizenNative(oauth2Symbols);

Tizen60Native? _tizenPhonenumberUtils;
Tizen60Native get tizenPhonenumberUtils =>
    _tizenPhonenumberUtils ??= _getTizenNative(phonenumberUtilsSymbols);

Tizen60Native? _tizenPrivilegeInfo;
Tizen60Native get tizenPrivilegeInfo =>
    _tizenPrivilegeInfo ??= _getTizenNative(privilegeInfoSymbols);

Tizen60Native? _tizenPush;
Tizen60Native get tizenPush => _tizenPush ??= _getTizenNative(pushSymbols);

Tizen60Native? _tizenRpcPort;
Tizen60Native get tizenRpcPort =>
    _tizenRpcPort ??= _getTizenNative(rpcPortSymbols);

Tizen60Native? _tizenShortcut;
Tizen60Native get tizenShortcut =>
    _tizenShortcut ??= _getTizenNative(shortcutSymbols);

Tizen60Native? _tizenStorage;
Tizen60Native get tizenStorage =>
    _tizenStorage ??= _getTizenNative(storageSymbols);

Tizen60Native? _tizenSttEngine;
Tizen60Native get tizenSttEngine =>
    _tizenSttEngine ??= _getTizenNative(stt_engineSymbols);

Tizen60Native? _tizenStt;
Tizen60Native get tizenStt => _tizenStt ??= _getTizenNative(sttSymbols);

Tizen60Native? _tizenTbm;
Tizen60Native get tizenTbm => _tizenTbm ??= _getTizenNative(tbmSymbols);

Tizen60Native? _tizenTtrace;
Tizen60Native get tizenTtrace =>
    _tizenTtrace ??= _getTizenNative(ttraceSymbols);

Tizen60Native? _tizenTtsEngine;
Tizen60Native get tizenTtsEngine =>
    _tizenTtsEngine ??= _getTizenNative(tts_engineSymbols);

Tizen60Native? _tizenTts;
Tizen60Native get tizenTts => _tizenTts ??= _getTizenNative(ttsSymbols);

Tizen60Native? _tizenUpdateControl;
Tizen60Native get tizenUpdateControl =>
    _tizenUpdateControl ??= _getTizenNative(updateControlSymbols);

Tizen60Native? _tizenVcEngine;
Tizen60Native get tizenVcEngine =>
    _tizenVcEngine ??= _getTizenNative(vc_engineSymbols);

Tizen60Native? _tizenVcManager;
Tizen60Native get tizenVcManager =>
    _tizenVcManager ??= _getTizenNative(vc_managerSymbols);

Tizen60Native? _tizenVc;
Tizen60Native get tizenVc => _tizenVc ??= _getTizenNative(vcSymbols);

Tizen60Native? _tizenWifiDirect;
Tizen60Native get tizenWifiDirect =>
    _tizenWifiDirect ??= _getTizenNative(wifiDirectSymbols);

Tizen60Native? _tizenYaca;
Tizen60Native get tizenYaca => _tizenYaca ??= _getTizenNative(yacaSymbols);
