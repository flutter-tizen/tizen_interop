library tizen_interop_9_0;

import 'dart:ffi';

import '../../src/bindings/9.0/generated_bindings.dart';
import '../../src/bindings/9.0/generated_symbols.dart';
import '../../src/lookup_provider.dart';

export '../../src/bindings/9.0/generated_bindings.dart';
export '../../src/extensions.dart';

final _lookupProvider = LookupProvider();

Tizen90Native _getTizenNative(Map<String, List<String>> symbolMap) {
  return Tizen90Native.fromLookup(
    <T extends NativeType>(String symbolName) {
      _lookupProvider.registerSymbols(symbolMap);
      return _lookupProvider.lookup<T>(symbolName);
    },
  );
}

Tizen90Native? _tizenAccountsSvc;
Tizen90Native get tizenAccountsSvc =>
    _tizenAccountsSvc ??= _getTizenNative(accountsSvcSymbols);

Tizen90Native? _tizenAppcoreAgent;
Tizen90Native get tizenAppcoreAgent =>
    _tizenAppcoreAgent ??= _getTizenNative(appcoreAgentSymbols);

Tizen90Native? _tizenAsp;
Tizen90Native get tizenAsp => _tizenAsp ??= _getTizenNative(aspSymbols);

Tizen90Native? _tizenBadge;
Tizen90Native get tizenBadge => _tizenBadge ??= _getTizenNative(badgeSymbols);

Tizen90Native? _tizenBundle;
Tizen90Native get tizenBundle =>
    _tizenBundle ??= _getTizenNative(bundleSymbols);

Tizen90Native? _tizenCalendarService2;
Tizen90Native get tizenCalendarService2 =>
    _tizenCalendarService2 ??= _getTizenNative(calendarService2Symbols);

Tizen90Native? _tizenCapiAppfwAlarm;
Tizen90Native get tizenCapiAppfwAlarm =>
    _tizenCapiAppfwAlarm ??= _getTizenNative(capiAppfwAlarmSymbols);

Tizen90Native? _tizenCapiAppfwAppCommon;
Tizen90Native get tizenCapiAppfwAppCommon =>
    _tizenCapiAppfwAppCommon ??= _getTizenNative(capiAppfwAppCommonSymbols);

Tizen90Native? _tizenCapiAppfwAppControl;
Tizen90Native get tizenCapiAppfwAppControl =>
    _tizenCapiAppfwAppControl ??= _getTizenNative(capiAppfwAppControlSymbols);

Tizen90Native? _tizenCapiAppfwAppControlUri;
Tizen90Native get tizenCapiAppfwAppControlUri =>
    _tizenCapiAppfwAppControlUri ??=
        _getTizenNative(capiAppfwAppControlUriSymbols);

Tizen90Native? _tizenCapiAppfwAppManager;
Tizen90Native get tizenCapiAppfwAppManager =>
    _tizenCapiAppfwAppManager ??= _getTizenNative(capiAppfwAppManagerSymbols);

Tizen90Native? _tizenCapiAppfwApplication;
Tizen90Native get tizenCapiAppfwApplication =>
    _tizenCapiAppfwApplication ??= _getTizenNative(capiAppfwApplicationSymbols);

Tizen90Native? _tizenCapiAppfwEvent;
Tizen90Native get tizenCapiAppfwEvent =>
    _tizenCapiAppfwEvent ??= _getTizenNative(capiAppfwEventSymbols);

Tizen90Native? _tizenCapiAppfwJobScheduler;
Tizen90Native get tizenCapiAppfwJobScheduler => _tizenCapiAppfwJobScheduler ??=
    _getTizenNative(capiAppfwJobSchedulerSymbols);

Tizen90Native? _tizenCapiAppfwPackageManager;
Tizen90Native get tizenCapiAppfwPackageManager =>
    _tizenCapiAppfwPackageManager ??=
        _getTizenNative(capiAppfwPackageManagerSymbols);

Tizen90Native? _tizenCapiAppfwPreference;
Tizen90Native get tizenCapiAppfwPreference =>
    _tizenCapiAppfwPreference ??= _getTizenNative(capiAppfwPreferenceSymbols);

Tizen90Native? _tizenCapiBaseCommon;
Tizen90Native get tizenCapiBaseCommon =>
    _tizenCapiBaseCommon ??= _getTizenNative(capiBaseCommonSymbols);

Tizen90Native? _tizenCapiContentMediaContent;
Tizen90Native get tizenCapiContentMediaContent =>
    _tizenCapiContentMediaContent ??=
        _getTizenNative(capiContentMediaContentSymbols);

Tizen90Native? _tizenCapiContentMimeType;
Tizen90Native get tizenCapiContentMimeType =>
    _tizenCapiContentMimeType ??= _getTizenNative(capiContentMimeTypeSymbols);

Tizen90Native? _tizenCapiContext;
Tizen90Native get tizenCapiContext =>
    _tizenCapiContext ??= _getTizenNative(capiContextSymbols);

Tizen90Native? _tizenCapiGeofenceManager;
Tizen90Native get tizenCapiGeofenceManager =>
    _tizenCapiGeofenceManager ??= _getTizenNative(capiGeofenceManagerSymbols);

Tizen90Native? _tizenCapiLocationManager;
Tizen90Native get tizenCapiLocationManager =>
    _tizenCapiLocationManager ??= _getTizenNative(capiLocationManagerSymbols);

Tizen90Native? _tizenCapiMediaAudioIo;
Tizen90Native get tizenCapiMediaAudioIo =>
    _tizenCapiMediaAudioIo ??= _getTizenNative(capiMediaAudioIoSymbols);

Tizen90Native? _tizenCapiMediaCamera;
Tizen90Native get tizenCapiMediaCamera =>
    _tizenCapiMediaCamera ??= _getTizenNative(capiMediaCameraSymbols);

Tizen90Native? _tizenCapiMediaCodec;
Tizen90Native get tizenCapiMediaCodec =>
    _tizenCapiMediaCodec ??= _getTizenNative(capiMediaCodecSymbols);

Tizen90Native? _tizenCapiMediaController;
Tizen90Native get tizenCapiMediaController =>
    _tizenCapiMediaController ??= _getTizenNative(capiMediaControllerSymbols);

Tizen90Native? _tizenCapiMediaEditor;
Tizen90Native get tizenCapiMediaEditor =>
    _tizenCapiMediaEditor ??= _getTizenNative(capiMediaEditorSymbols);

Tizen90Native? _tizenCapiMediaImageUtil;
Tizen90Native get tizenCapiMediaImageUtil =>
    _tizenCapiMediaImageUtil ??= _getTizenNative(capiMediaImageUtilSymbols);

Tizen90Native? _tizenCapiMediaMetadataEditor;
Tizen90Native get tizenCapiMediaMetadataEditor =>
    _tizenCapiMediaMetadataEditor ??=
        _getTizenNative(capiMediaMetadataEditorSymbols);

Tizen90Native? _tizenCapiMediaMetadataExtractor;
Tizen90Native get tizenCapiMediaMetadataExtractor =>
    _tizenCapiMediaMetadataExtractor ??=
        _getTizenNative(capiMediaMetadataExtractorSymbols);

Tizen90Native? _tizenCapiMediaPlayer;
Tizen90Native get tizenCapiMediaPlayer =>
    _tizenCapiMediaPlayer ??= _getTizenNative(capiMediaPlayerSymbols);

Tizen90Native? _tizenCapiMediaRadio;
Tizen90Native get tizenCapiMediaRadio =>
    _tizenCapiMediaRadio ??= _getTizenNative(capiMediaRadioSymbols);

Tizen90Native? _tizenCapiMediaRecorder;
Tizen90Native get tizenCapiMediaRecorder =>
    _tizenCapiMediaRecorder ??= _getTizenNative(capiMediaRecorderSymbols);

Tizen90Native? _tizenCapiMediaScreenMirroring;
Tizen90Native get tizenCapiMediaScreenMirroring =>
    _tizenCapiMediaScreenMirroring ??=
        _getTizenNative(capiMediaScreenMirroringSymbols);

Tizen90Native? _tizenCapiMediaSoundManager;
Tizen90Native get tizenCapiMediaSoundManager => _tizenCapiMediaSoundManager ??=
    _getTizenNative(capiMediaSoundManagerSymbols);

Tizen90Native? _tizenCapiMediaSoundPool;
Tizen90Native get tizenCapiMediaSoundPool =>
    _tizenCapiMediaSoundPool ??= _getTizenNative(capiMediaSoundPoolSymbols);

Tizen90Native? _tizenCapiMediaThumbnailUtil;
Tizen90Native get tizenCapiMediaThumbnailUtil =>
    _tizenCapiMediaThumbnailUtil ??=
        _getTizenNative(capiMediaThumbnailUtilSymbols);

Tizen90Native? _tizenCapiMediaTonePlayer;
Tizen90Native get tizenCapiMediaTonePlayer =>
    _tizenCapiMediaTonePlayer ??= _getTizenNative(capiMediaTonePlayerSymbols);

Tizen90Native? _tizenCapiMediaTool;
Tizen90Native get tizenCapiMediaTool =>
    _tizenCapiMediaTool ??= _getTizenNative(capiMediaToolSymbols);

Tizen90Native? _tizenCapiMediaWavPlayer;
Tizen90Native get tizenCapiMediaWavPlayer =>
    _tizenCapiMediaWavPlayer ??= _getTizenNative(capiMediaWavPlayerSymbols);

Tizen90Native? _tizenCapiMediaWebrtc;
Tizen90Native get tizenCapiMediaWebrtc =>
    _tizenCapiMediaWebrtc ??= _getTizenNative(capiMediaWebrtcSymbols);

Tizen90Native? _tizenCapiMediademuxer;
Tizen90Native get tizenCapiMediademuxer =>
    _tizenCapiMediademuxer ??= _getTizenNative(capiMediademuxerSymbols);

Tizen90Native? _tizenCapiMediamuxer;
Tizen90Native get tizenCapiMediamuxer =>
    _tizenCapiMediamuxer ??= _getTizenNative(capiMediamuxerSymbols);

Tizen90Native? _tizenCapiMessagingEmail;
Tizen90Native get tizenCapiMessagingEmail =>
    _tizenCapiMessagingEmail ??= _getTizenNative(capiMessagingEmailSymbols);

Tizen90Native? _tizenCapiMlCommon;
Tizen90Native get tizenCapiMlCommon =>
    _tizenCapiMlCommon ??= _getTizenNative(capiMlCommonSymbols);

Tizen90Native? _tizenCapiMlInferenceSingle;
Tizen90Native get tizenCapiMlInferenceSingle => _tizenCapiMlInferenceSingle ??=
    _getTizenNative(capiMlInferenceSingleSymbols);

Tizen90Native? _tizenCapiMlService;
Tizen90Native get tizenCapiMlService =>
    _tizenCapiMlService ??= _getTizenNative(capiMlServiceSymbols);

Tizen90Native? _tizenCapiNetworkBluetooth;
Tizen90Native get tizenCapiNetworkBluetooth =>
    _tizenCapiNetworkBluetooth ??= _getTizenNative(capiNetworkBluetoothSymbols);

Tizen90Native? _tizenCapiNetworkConnection;
Tizen90Native get tizenCapiNetworkConnection => _tizenCapiNetworkConnection ??=
    _getTizenNative(capiNetworkConnectionSymbols);

Tizen90Native? _tizenCapiNetworkHttp;
Tizen90Native get tizenCapiNetworkHttp =>
    _tizenCapiNetworkHttp ??= _getTizenNative(capiNetworkHttpSymbols);

Tizen90Native? _tizenCapiNetworkInm;
Tizen90Native get tizenCapiNetworkInm =>
    _tizenCapiNetworkInm ??= _getTizenNative(capiNetworkInmSymbols);

Tizen90Native? _tizenCapiNetworkMtp;
Tizen90Native get tizenCapiNetworkMtp =>
    _tizenCapiNetworkMtp ??= _getTizenNative(capiNetworkMtpSymbols);

Tizen90Native? _tizenCapiNetworkSoftap;
Tizen90Native get tizenCapiNetworkSoftap =>
    _tizenCapiNetworkSoftap ??= _getTizenNative(capiNetworkSoftapSymbols);

Tizen90Native? _tizenCapiNetworkStc;
Tizen90Native get tizenCapiNetworkStc =>
    _tizenCapiNetworkStc ??= _getTizenNative(capiNetworkStcSymbols);

Tizen90Native? _tizenCapiNetworkWifiAware;
Tizen90Native get tizenCapiNetworkWifiAware =>
    _tizenCapiNetworkWifiAware ??= _getTizenNative(capiNetworkWifiAwareSymbols);

Tizen90Native? _tizenCapiNetworkWifiManager;
Tizen90Native get tizenCapiNetworkWifiManager =>
    _tizenCapiNetworkWifiManager ??=
        _getTizenNative(capiNetworkWifiManagerSymbols);

Tizen90Native? _tizenCapiNnstreamer;
Tizen90Native get tizenCapiNnstreamer =>
    _tizenCapiNnstreamer ??= _getTizenNative(capiNnstreamerSymbols);

Tizen90Native? _tizenCapiNntrainer;
Tizen90Native get tizenCapiNntrainer =>
    _tizenCapiNntrainer ??= _getTizenNative(capiNntrainerSymbols);

Tizen90Native? _tizenCapiPrivacyPrivilegeManager;
Tizen90Native get tizenCapiPrivacyPrivilegeManager =>
    _tizenCapiPrivacyPrivilegeManager ??=
        _getTizenNative(capiPrivacyPrivilegeManagerSymbols);

Tizen90Native? _tizenCapiSystemDevice;
Tizen90Native get tizenCapiSystemDevice =>
    _tizenCapiSystemDevice ??= _getTizenNative(capiSystemDeviceSymbols);

Tizen90Native? _tizenCapiSystemInfo;
Tizen90Native get tizenCapiSystemInfo =>
    _tizenCapiSystemInfo ??= _getTizenNative(capiSystemInfoSymbols);

Tizen90Native? _tizenCapiSystemMediaKey;
Tizen90Native get tizenCapiSystemMediaKey =>
    _tizenCapiSystemMediaKey ??= _getTizenNative(capiSystemMediaKeySymbols);

Tizen90Native? _tizenCapiSystemPeripheralIo;
Tizen90Native get tizenCapiSystemPeripheralIo =>
    _tizenCapiSystemPeripheralIo ??=
        _getTizenNative(capiSystemPeripheralIoSymbols);

Tizen90Native? _tizenCapiSystemResourceMonitor;
Tizen90Native get tizenCapiSystemResourceMonitor =>
    _tizenCapiSystemResourceMonitor ??=
        _getTizenNative(capiSystemResourceMonitorSymbols);

Tizen90Native? _tizenCapiSystemRuntimeInfo;
Tizen90Native get tizenCapiSystemRuntimeInfo => _tizenCapiSystemRuntimeInfo ??=
    _getTizenNative(capiSystemRuntimeInfoSymbols);

Tizen90Native? _tizenCapiSystemSensor;
Tizen90Native get tizenCapiSystemSensor =>
    _tizenCapiSystemSensor ??= _getTizenNative(capiSystemSensorSymbols);

Tizen90Native? _tizenCapiSystemSystemSettings;
Tizen90Native get tizenCapiSystemSystemSettings =>
    _tizenCapiSystemSystemSettings ??=
        _getTizenNative(capiSystemSystemSettingsSymbols);

Tizen90Native? _tizenCapiSystemUsbhost;
Tizen90Native get tizenCapiSystemUsbhost =>
    _tizenCapiSystemUsbhost ??= _getTizenNative(capiSystemUsbhostSymbols);

Tizen90Native? _tizenCapiUiAutofillCommon;
Tizen90Native get tizenCapiUiAutofillCommon =>
    _tizenCapiUiAutofillCommon ??= _getTizenNative(capiUiAutofillCommonSymbols);

Tizen90Native? _tizenCapiUiAutofillManager;
Tizen90Native get tizenCapiUiAutofillManager => _tizenCapiUiAutofillManager ??=
    _getTizenNative(capiUiAutofillManagerSymbols);

Tizen90Native? _tizenCapiUiAutofillService;
Tizen90Native get tizenCapiUiAutofillService => _tizenCapiUiAutofillService ??=
    _getTizenNative(capiUiAutofillServiceSymbols);

Tizen90Native? _tizenCapiUiAutofill;
Tizen90Native get tizenCapiUiAutofill =>
    _tizenCapiUiAutofill ??= _getTizenNative(capiUiAutofillSymbols);

Tizen90Native? _tizenCapiUiInputmethodManager;
Tizen90Native get tizenCapiUiInputmethodManager =>
    _tizenCapiUiInputmethodManager ??=
        _getTizenNative(capiUiInputmethodManagerSymbols);

Tizen90Native? _tizenCapiUiInputmethod;
Tizen90Native get tizenCapiUiInputmethod =>
    _tizenCapiUiInputmethod ??= _getTizenNative(capiUiInputmethodSymbols);

Tizen90Native? _tizenCapiVpnsvc;
Tizen90Native get tizenCapiVpnsvc =>
    _tizenCapiVpnsvc ??= _getTizenNative(capiVpnsvcSymbols);

Tizen90Native? _tizenCapiWebUrlDownload;
Tizen90Native get tizenCapiWebUrlDownload =>
    _tizenCapiWebUrlDownload ??= _getTizenNative(capiWebUrlDownloadSymbols);

Tizen90Native? _tizenCion;
Tizen90Native get tizenCion => _tizenCion ??= _getTizenNative(cionSymbols);

Tizen90Native? _tizenContactsService2;
Tizen90Native get tizenContactsService2 =>
    _tizenContactsService2 ??= _getTizenNative(contactsService2Symbols);

Tizen90Native? _tizenCoreSyncClient;
Tizen90Native get tizenCoreSyncClient =>
    _tizenCoreSyncClient ??= _getTizenNative(coreSyncClientSymbols);

Tizen90Native? _tizenCsrClient;
Tizen90Native get tizenCsrClient =>
    _tizenCsrClient ??= _getTizenNative(csrClientSymbols);

Tizen90Native? _tizenDataControl;
Tizen90Native get tizenDataControl =>
    _tizenDataControl ??= _getTizenNative(dataControlSymbols);

Tizen90Native? _tizenDeviceCertificateManager;
Tizen90Native get tizenDeviceCertificateManager =>
    _tizenDeviceCertificateManager ??=
        _getTizenNative(deviceCertificateManagerSymbols);

Tizen90Native? _tizenDiagnostics;
Tizen90Native get tizenDiagnostics =>
    _tizenDiagnostics ??= _getTizenNative(diagnosticsSymbols);

Tizen90Native? _tizenDlog;
Tizen90Native get tizenDlog => _tizenDlog ??= _getTizenNative(dlogSymbols);

Tizen90Native? _tizenDpm;
Tizen90Native get tizenDpm => _tizenDpm ??= _getTizenNative(dpmSymbols);

Tizen90Native? _tizenEom;
Tizen90Native get tizenEom => _tizenEom ??= _getTizenNative(eomSymbols);

Tizen90Native? _tizenFeedback;
Tizen90Native get tizenFeedback =>
    _tizenFeedback ??= _getTizenNative(feedbackSymbols);

Tizen90Native? _tizenFidoClient;
Tizen90Native get tizenFidoClient =>
    _tizenFidoClient ??= _getTizenNative(fidoClientSymbols);

Tizen90Native? _tizenIotcon;
Tizen90Native get tizenIotcon =>
    _tizenIotcon ??= _getTizenNative(iotconSymbols);

Tizen90Native? _tizenKeyManagerClient;
Tizen90Native get tizenKeyManagerClient =>
    _tizenKeyManagerClient ??= _getTizenNative(keyManagerClientSymbols);

Tizen90Native? _tizenMa;
Tizen90Native get tizenMa => _tizenMa ??= _getTizenNative(maSymbols);

Tizen90Native? _tizenMessagePort;
Tizen90Native get tizenMessagePort =>
    _tizenMessagePort ??= _getTizenNative(messagePortSymbols);

Tizen90Native? _tizenMmi;
Tizen90Native get tizenMmi => _tizenMmi ??= _getTizenNative(mmiSymbols);

Tizen90Native? _tizenMv3d;
Tizen90Native get tizenMv3d => _tizenMv3d ??= _getTizenNative(mv_3dSymbols);

Tizen90Native? _tizenMvBarcodeDetector;
Tizen90Native get tizenMvBarcodeDetector =>
    _tizenMvBarcodeDetector ??= _getTizenNative(mv_barcode_detectorSymbols);

Tizen90Native? _tizenMvBarcodeGenerator;
Tizen90Native get tizenMvBarcodeGenerator =>
    _tizenMvBarcodeGenerator ??= _getTizenNative(mv_barcode_generatorSymbols);

Tizen90Native? _tizenMvCommon;
Tizen90Native get tizenMvCommon =>
    _tizenMvCommon ??= _getTizenNative(mv_commonSymbols);

Tizen90Native? _tizenMvFaceRecognition;
Tizen90Native get tizenMvFaceRecognition =>
    _tizenMvFaceRecognition ??= _getTizenNative(mv_face_recognitionSymbols);

Tizen90Native? _tizenMvFace;
Tizen90Native get tizenMvFace =>
    _tizenMvFace ??= _getTizenNative(mv_faceSymbols);

Tizen90Native? _tizenMvImageClassification;
Tizen90Native get tizenMvImageClassification => _tizenMvImageClassification ??=
    _getTizenNative(mv_image_classificationSymbols);

Tizen90Native? _tizenMvImage;
Tizen90Native get tizenMvImage =>
    _tizenMvImage ??= _getTizenNative(mv_imageSymbols);

Tizen90Native? _tizenMvInference;
Tizen90Native get tizenMvInference =>
    _tizenMvInference ??= _getTizenNative(mv_inferenceSymbols);

Tizen90Native? _tizenMvLandmarkDetection;
Tizen90Native get tizenMvLandmarkDetection =>
    _tizenMvLandmarkDetection ??= _getTizenNative(mv_landmark_detectionSymbols);

Tizen90Native? _tizenMvObjectDetection;
Tizen90Native get tizenMvObjectDetection =>
    _tizenMvObjectDetection ??= _getTizenNative(mv_object_detectionSymbols);

Tizen90Native? _tizenMvRoiTracker;
Tizen90Native get tizenMvRoiTracker =>
    _tizenMvRoiTracker ??= _getTizenNative(mv_roi_trackerSymbols);

Tizen90Native? _tizenMvSurveillance;
Tizen90Native get tizenMvSurveillance =>
    _tizenMvSurveillance ??= _getTizenNative(mv_surveillanceSymbols);

Tizen90Native? _tizenNotificationEx;
Tizen90Native get tizenNotificationEx =>
    _tizenNotificationEx ??= _getTizenNative(notificationExSymbols);

Tizen90Native? _tizenNotification;
Tizen90Native get tizenNotification =>
    _tizenNotification ??= _getTizenNative(notificationSymbols);

Tizen90Native? _tizenNsdDnsSd;
Tizen90Native get tizenNsdDnsSd =>
    _tizenNsdDnsSd ??= _getTizenNative(nsdDnsSdSymbols);

Tizen90Native? _tizenNsdSsdp;
Tizen90Native get tizenNsdSsdp =>
    _tizenNsdSsdp ??= _getTizenNative(nsdSsdpSymbols);

Tizen90Native? _tizenOauth2;
Tizen90Native get tizenOauth2 =>
    _tizenOauth2 ??= _getTizenNative(oauth2Symbols);

Tizen90Native? _tizenPhonenumberUtils;
Tizen90Native get tizenPhonenumberUtils =>
    _tizenPhonenumberUtils ??= _getTizenNative(phonenumberUtilsSymbols);

Tizen90Native? _tizenPrivilegeInfo;
Tizen90Native get tizenPrivilegeInfo =>
    _tizenPrivilegeInfo ??= _getTizenNative(privilegeInfoSymbols);

Tizen90Native? _tizenPush;
Tizen90Native get tizenPush => _tizenPush ??= _getTizenNative(pushSymbols);

Tizen90Native? _tizenRpcPort;
Tizen90Native get tizenRpcPort =>
    _tizenRpcPort ??= _getTizenNative(rpcPortSymbols);

Tizen90Native? _tizenStorage;
Tizen90Native get tizenStorage =>
    _tizenStorage ??= _getTizenNative(storageSymbols);

Tizen90Native? _tizenSttEngine;
Tizen90Native get tizenSttEngine =>
    _tizenSttEngine ??= _getTizenNative(stt_engineSymbols);

Tizen90Native? _tizenStt;
Tizen90Native get tizenStt => _tizenStt ??= _getTizenNative(sttSymbols);

Tizen90Native? _tizenTbm;
Tizen90Native get tizenTbm => _tizenTbm ??= _getTizenNative(tbmSymbols);

Tizen90Native? _tizenTizenCore;
Tizen90Native get tizenTizenCore =>
    _tizenTizenCore ??= _getTizenNative(tizenCoreSymbols);

Tizen90Native? _tizenTtrace;
Tizen90Native get tizenTtrace =>
    _tizenTtrace ??= _getTizenNative(ttraceSymbols);

Tizen90Native? _tizenTtsEngine;
Tizen90Native get tizenTtsEngine =>
    _tizenTtsEngine ??= _getTizenNative(tts_engineSymbols);

Tizen90Native? _tizenTts;
Tizen90Native get tizenTts => _tizenTts ??= _getTizenNative(ttsSymbols);

Tizen90Native? _tizenUpdateControl;
Tizen90Native get tizenUpdateControl =>
    _tizenUpdateControl ??= _getTizenNative(updateControlSymbols);

Tizen90Native? _tizenVcEngine;
Tizen90Native get tizenVcEngine =>
    _tizenVcEngine ??= _getTizenNative(vc_engineSymbols);

Tizen90Native? _tizenVcManager;
Tizen90Native get tizenVcManager =>
    _tizenVcManager ??= _getTizenNative(vc_managerSymbols);

Tizen90Native? _tizenVc;
Tizen90Native get tizenVc => _tizenVc ??= _getTizenNative(vcSymbols);

Tizen90Native? _tizenWebauthnClient;
Tizen90Native get tizenWebauthnClient =>
    _tizenWebauthnClient ??= _getTizenNative(webauthnClientSymbols);

Tizen90Native? _tizenWifiDirect;
Tizen90Native get tizenWifiDirect =>
    _tizenWifiDirect ??= _getTizenNative(wifiDirectSymbols);

Tizen90Native? _tizenYaca;
Tizen90Native get tizenYaca => _tizenYaca ??= _getTizenNative(yacaSymbols);
