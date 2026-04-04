library tizen_interop_10_0;

import 'dart:ffi';

import '../../src/bindings/10.0/generated_bindings.dart';
import '../../src/bindings/10.0/generated_symbols.dart';
import '../../src/lookup_provider.dart';

export '../../src/bindings/10.0/generated_bindings.dart';
export '../../src/extensions.dart';

final _lookupProvider = LookupProvider();

Tizen100Native _getTizenNative(Map<String, List<String>> symbolMap) {
  return Tizen100Native.fromLookup(
    <T extends NativeType>(String symbolName) {
      _lookupProvider.registerSymbols(symbolMap);
      return _lookupProvider.lookup<T>(symbolName);
    },
  );
}

Tizen100Native? _tizenAccountsSvc;
Tizen100Native get tizenAccountsSvc =>
    _tizenAccountsSvc ??= _getTizenNative(accountsSvcSymbols);

Tizen100Native? _tizenAppcoreAgent;
Tizen100Native get tizenAppcoreAgent =>
    _tizenAppcoreAgent ??= _getTizenNative(appcoreAgentSymbols);

Tizen100Native? _tizenBundle;
Tizen100Native get tizenBundle =>
    _tizenBundle ??= _getTizenNative(bundleSymbols);

Tizen100Native? _tizenCapiAppfwAlarm;
Tizen100Native get tizenCapiAppfwAlarm =>
    _tizenCapiAppfwAlarm ??= _getTizenNative(capiAppfwAlarmSymbols);

Tizen100Native? _tizenCapiAppfwAppCommon;
Tizen100Native get tizenCapiAppfwAppCommon =>
    _tizenCapiAppfwAppCommon ??= _getTizenNative(capiAppfwAppCommonSymbols);

Tizen100Native? _tizenCapiAppfwAppControl;
Tizen100Native get tizenCapiAppfwAppControl =>
    _tizenCapiAppfwAppControl ??= _getTizenNative(capiAppfwAppControlSymbols);

Tizen100Native? _tizenCapiAppfwAppControlUri;
Tizen100Native get tizenCapiAppfwAppControlUri =>
    _tizenCapiAppfwAppControlUri ??= _getTizenNative(capiAppfwAppControlUriSymbols);

Tizen100Native? _tizenCapiAppfwAppManager;
Tizen100Native get tizenCapiAppfwAppManager =>
    _tizenCapiAppfwAppManager ??= _getTizenNative(capiAppfwAppManagerSymbols);

Tizen100Native? _tizenCapiAppfwApplication;
Tizen100Native get tizenCapiAppfwApplication =>
    _tizenCapiAppfwApplication ??= _getTizenNative(capiAppfwApplicationSymbols);

Tizen100Native? _tizenCapiAppfwEvent;
Tizen100Native get tizenCapiAppfwEvent =>
    _tizenCapiAppfwEvent ??= _getTizenNative(capiAppfwEventSymbols);

Tizen100Native? _tizenCapiAppfwJobScheduler;
Tizen100Native get tizenCapiAppfwJobScheduler =>
    _tizenCapiAppfwJobScheduler ??= _getTizenNative(capiAppfwJobSchedulerSymbols);

Tizen100Native? _tizenCapiAppfwPackageManager;
Tizen100Native get tizenCapiAppfwPackageManager =>
    _tizenCapiAppfwPackageManager ??= _getTizenNative(capiAppfwPackageManagerSymbols);

Tizen100Native? _tizenCapiAppfwPreference;
Tizen100Native get tizenCapiAppfwPreference =>
    _tizenCapiAppfwPreference ??= _getTizenNative(capiAppfwPreferenceSymbols);

Tizen100Native? _tizenCapiBaseCommon;
Tizen100Native get tizenCapiBaseCommon =>
    _tizenCapiBaseCommon ??= _getTizenNative(capiBaseCommonSymbols);

Tizen100Native? _tizenCapiContentMediaContent;
Tizen100Native get tizenCapiContentMediaContent =>
    _tizenCapiContentMediaContent ??= _getTizenNative(capiContentMediaContentSymbols);

Tizen100Native? _tizenCapiContentMimeType;
Tizen100Native get tizenCapiContentMimeType =>
    _tizenCapiContentMimeType ??= _getTizenNative(capiContentMimeTypeSymbols);

Tizen100Native? _tizenCapiLocationManager;
Tizen100Native get tizenCapiLocationManager =>
    _tizenCapiLocationManager ??= _getTizenNative(capiLocationManagerSymbols);

Tizen100Native? _tizenCapiMediaAudioIo;
Tizen100Native get tizenCapiMediaAudioIo =>
    _tizenCapiMediaAudioIo ??= _getTizenNative(capiMediaAudioIoSymbols);

Tizen100Native? _tizenCapiMediaCamera;
Tizen100Native get tizenCapiMediaCamera =>
    _tizenCapiMediaCamera ??= _getTizenNative(capiMediaCameraSymbols);

Tizen100Native? _tizenCapiMediaCodec;
Tizen100Native get tizenCapiMediaCodec =>
    _tizenCapiMediaCodec ??= _getTizenNative(capiMediaCodecSymbols);

Tizen100Native? _tizenCapiMediaController;
Tizen100Native get tizenCapiMediaController =>
    _tizenCapiMediaController ??= _getTizenNative(capiMediaControllerSymbols);

Tizen100Native? _tizenCapiMediaEditor;
Tizen100Native get tizenCapiMediaEditor =>
    _tizenCapiMediaEditor ??= _getTizenNative(capiMediaEditorSymbols);

Tizen100Native? _tizenCapiMediaImageUtil;
Tizen100Native get tizenCapiMediaImageUtil =>
    _tizenCapiMediaImageUtil ??= _getTizenNative(capiMediaImageUtilSymbols);

Tizen100Native? _tizenCapiMediaMetadataExtractor;
Tizen100Native get tizenCapiMediaMetadataExtractor =>
    _tizenCapiMediaMetadataExtractor ??= _getTizenNative(capiMediaMetadataExtractorSymbols);

Tizen100Native? _tizenCapiMediaPlayer;
Tizen100Native get tizenCapiMediaPlayer =>
    _tizenCapiMediaPlayer ??= _getTizenNative(capiMediaPlayerSymbols);

Tizen100Native? _tizenCapiMediaRadio;
Tizen100Native get tizenCapiMediaRadio =>
    _tizenCapiMediaRadio ??= _getTizenNative(capiMediaRadioSymbols);

Tizen100Native? _tizenCapiMediaRecorder;
Tizen100Native get tizenCapiMediaRecorder =>
    _tizenCapiMediaRecorder ??= _getTizenNative(capiMediaRecorderSymbols);

Tizen100Native? _tizenCapiMediaScreenMirroring;
Tizen100Native get tizenCapiMediaScreenMirroring =>
    _tizenCapiMediaScreenMirroring ??= _getTizenNative(capiMediaScreenMirroringSymbols);

Tizen100Native? _tizenCapiMediaSoundManager;
Tizen100Native get tizenCapiMediaSoundManager =>
    _tizenCapiMediaSoundManager ??= _getTizenNative(capiMediaSoundManagerSymbols);

Tizen100Native? _tizenCapiMediaSoundPool;
Tizen100Native get tizenCapiMediaSoundPool =>
    _tizenCapiMediaSoundPool ??= _getTizenNative(capiMediaSoundPoolSymbols);

Tizen100Native? _tizenCapiMediaThumbnailUtil;
Tizen100Native get tizenCapiMediaThumbnailUtil =>
    _tizenCapiMediaThumbnailUtil ??= _getTizenNative(capiMediaThumbnailUtilSymbols);

Tizen100Native? _tizenCapiMediaTonePlayer;
Tizen100Native get tizenCapiMediaTonePlayer =>
    _tizenCapiMediaTonePlayer ??= _getTizenNative(capiMediaTonePlayerSymbols);

Tizen100Native? _tizenCapiMediaTool;
Tizen100Native get tizenCapiMediaTool =>
    _tizenCapiMediaTool ??= _getTizenNative(capiMediaToolSymbols);

Tizen100Native? _tizenCapiMediaWavPlayer;
Tizen100Native get tizenCapiMediaWavPlayer =>
    _tizenCapiMediaWavPlayer ??= _getTizenNative(capiMediaWavPlayerSymbols);

Tizen100Native? _tizenCapiMediaWebrtc;
Tizen100Native get tizenCapiMediaWebrtc =>
    _tizenCapiMediaWebrtc ??= _getTizenNative(capiMediaWebrtcSymbols);

Tizen100Native? _tizenCapiMlInferenceSingle;
Tizen100Native get tizenCapiMlInferenceSingle =>
    _tizenCapiMlInferenceSingle ??= _getTizenNative(capiMlInferenceSingleSymbols);

Tizen100Native? _tizenCapiMlService;
Tizen100Native get tizenCapiMlService =>
    _tizenCapiMlService ??= _getTizenNative(capiMlServiceSymbols);

Tizen100Native? _tizenCapiNetworkBluetooth;
Tizen100Native get tizenCapiNetworkBluetooth =>
    _tizenCapiNetworkBluetooth ??= _getTizenNative(capiNetworkBluetoothSymbols);

Tizen100Native? _tizenCapiNetworkConnection;
Tizen100Native get tizenCapiNetworkConnection =>
    _tizenCapiNetworkConnection ??= _getTizenNative(capiNetworkConnectionSymbols);

Tizen100Native? _tizenCapiNetworkInm;
Tizen100Native get tizenCapiNetworkInm =>
    _tizenCapiNetworkInm ??= _getTizenNative(capiNetworkInmSymbols);

Tizen100Native? _tizenCapiNetworkMtp;
Tizen100Native get tizenCapiNetworkMtp =>
    _tizenCapiNetworkMtp ??= _getTizenNative(capiNetworkMtpSymbols);

Tizen100Native? _tizenCapiNetworkSoftap;
Tizen100Native get tizenCapiNetworkSoftap =>
    _tizenCapiNetworkSoftap ??= _getTizenNative(capiNetworkSoftapSymbols);

Tizen100Native? _tizenCapiNetworkWifiAware;
Tizen100Native get tizenCapiNetworkWifiAware =>
    _tizenCapiNetworkWifiAware ??= _getTizenNative(capiNetworkWifiAwareSymbols);

Tizen100Native? _tizenCapiNetworkWifiManager;
Tizen100Native get tizenCapiNetworkWifiManager =>
    _tizenCapiNetworkWifiManager ??= _getTizenNative(capiNetworkWifiManagerSymbols);

Tizen100Native? _tizenCapiNnstreamer;
Tizen100Native get tizenCapiNnstreamer =>
    _tizenCapiNnstreamer ??= _getTizenNative(capiNnstreamerSymbols);

Tizen100Native? _tizenCapiNntrainer;
Tizen100Native get tizenCapiNntrainer =>
    _tizenCapiNntrainer ??= _getTizenNative(capiNntrainerSymbols);

Tizen100Native? _tizenCapiSystemDevice;
Tizen100Native get tizenCapiSystemDevice =>
    _tizenCapiSystemDevice ??= _getTizenNative(capiSystemDeviceSymbols);

Tizen100Native? _tizenCapiSystemInfo;
Tizen100Native get tizenCapiSystemInfo =>
    _tizenCapiSystemInfo ??= _getTizenNative(capiSystemInfoSymbols);

Tizen100Native? _tizenCapiSystemMediaKey;
Tizen100Native get tizenCapiSystemMediaKey =>
    _tizenCapiSystemMediaKey ??= _getTizenNative(capiSystemMediaKeySymbols);

Tizen100Native? _tizenCapiSystemResourceMonitor;
Tizen100Native get tizenCapiSystemResourceMonitor =>
    _tizenCapiSystemResourceMonitor ??= _getTizenNative(capiSystemResourceMonitorSymbols);

Tizen100Native? _tizenCapiSystemRuntimeInfo;
Tizen100Native get tizenCapiSystemRuntimeInfo =>
    _tizenCapiSystemRuntimeInfo ??= _getTizenNative(capiSystemRuntimeInfoSymbols);

Tizen100Native? _tizenCapiSystemSensor;
Tizen100Native get tizenCapiSystemSensor =>
    _tizenCapiSystemSensor ??= _getTizenNative(capiSystemSensorSymbols);

Tizen100Native? _tizenCapiSystemSystemSettings;
Tizen100Native get tizenCapiSystemSystemSettings =>
    _tizenCapiSystemSystemSettings ??= _getTizenNative(capiSystemSystemSettingsSymbols);

Tizen100Native? _tizenCapiSystemUsbhost;
Tizen100Native get tizenCapiSystemUsbhost =>
    _tizenCapiSystemUsbhost ??= _getTizenNative(capiSystemUsbhostSymbols);

Tizen100Native? _tizenCapiUiAutofillCommon;
Tizen100Native get tizenCapiUiAutofillCommon =>
    _tizenCapiUiAutofillCommon ??= _getTizenNative(capiUiAutofillCommonSymbols);

Tizen100Native? _tizenCapiUiAutofillManager;
Tizen100Native get tizenCapiUiAutofillManager =>
    _tizenCapiUiAutofillManager ??= _getTizenNative(capiUiAutofillManagerSymbols);

Tizen100Native? _tizenCapiUiAutofillService;
Tizen100Native get tizenCapiUiAutofillService =>
    _tizenCapiUiAutofillService ??= _getTizenNative(capiUiAutofillServiceSymbols);

Tizen100Native? _tizenCapiUiAutofill;
Tizen100Native get tizenCapiUiAutofill =>
    _tizenCapiUiAutofill ??= _getTizenNative(capiUiAutofillSymbols);

Tizen100Native? _tizenCapiUiInputmethodManager;
Tizen100Native get tizenCapiUiInputmethodManager =>
    _tizenCapiUiInputmethodManager ??= _getTizenNative(capiUiInputmethodManagerSymbols);

Tizen100Native? _tizenCapiUiInputmethod;
Tizen100Native get tizenCapiUiInputmethod =>
    _tizenCapiUiInputmethod ??= _getTizenNative(capiUiInputmethodSymbols);

Tizen100Native? _tizenCapiVpnsvc;
Tizen100Native get tizenCapiVpnsvc =>
    _tizenCapiVpnsvc ??= _getTizenNative(capiVpnsvcSymbols);

Tizen100Native? _tizenCapiWebUrlDownload;
Tizen100Native get tizenCapiWebUrlDownload =>
    _tizenCapiWebUrlDownload ??= _getTizenNative(capiWebUrlDownloadSymbols);

Tizen100Native? _tizenCoreSyncClient;
Tizen100Native get tizenCoreSyncClient =>
    _tizenCoreSyncClient ??= _getTizenNative(coreSyncClientSymbols);

Tizen100Native? _tizenDeviceCertificateManager;
Tizen100Native get tizenDeviceCertificateManager =>
    _tizenDeviceCertificateManager ??= _getTizenNative(deviceCertificateManagerSymbols);

Tizen100Native? _tizenDlog;
Tizen100Native get tizenDlog =>
    _tizenDlog ??= _getTizenNative(dlogSymbols);

Tizen100Native? _tizenFeedback;
Tizen100Native get tizenFeedback =>
    _tizenFeedback ??= _getTizenNative(feedbackSymbols);

Tizen100Native? _tizenIotcon;
Tizen100Native get tizenIotcon =>
    _tizenIotcon ??= _getTizenNative(iotconSymbols);

Tizen100Native? _tizenKeyManagerClient;
Tizen100Native get tizenKeyManagerClient =>
    _tizenKeyManagerClient ??= _getTizenNative(keyManagerClientSymbols);

Tizen100Native? _tizenMa;
Tizen100Native get tizenMa =>
    _tizenMa ??= _getTizenNative(maSymbols);

Tizen100Native? _tizenMessagePort;
Tizen100Native get tizenMessagePort =>
    _tizenMessagePort ??= _getTizenNative(messagePortSymbols);

Tizen100Native? _tizenMmi;
Tizen100Native get tizenMmi =>
    _tizenMmi ??= _getTizenNative(mmiSymbols);

Tizen100Native? _tizenMv3d;
Tizen100Native get tizenMv3d =>
    _tizenMv3d ??= _getTizenNative(mv_3dSymbols);

Tizen100Native? _tizenMvCommon;
Tizen100Native get tizenMvCommon =>
    _tizenMvCommon ??= _getTizenNative(mv_commonSymbols);

Tizen100Native? _tizenMvFace;
Tizen100Native get tizenMvFace =>
    _tizenMvFace ??= _getTizenNative(mv_faceSymbols);

Tizen100Native? _tizenMvFaceRecognition;
Tizen100Native get tizenMvFaceRecognition =>
    _tizenMvFaceRecognition ??= _getTizenNative(mv_face_recognitionSymbols);

Tizen100Native? _tizenMvImage;
Tizen100Native get tizenMvImage =>
    _tizenMvImage ??= _getTizenNative(mv_imageSymbols);

Tizen100Native? _tizenMvImageClassification;
Tizen100Native get tizenMvImageClassification =>
    _tizenMvImageClassification ??= _getTizenNative(mv_image_classificationSymbols);

Tizen100Native? _tizenMvInference;
Tizen100Native get tizenMvInference =>
    _tizenMvInference ??= _getTizenNative(mv_inferenceSymbols);

Tizen100Native? _tizenMvLandmarkDetection;
Tizen100Native get tizenMvLandmarkDetection =>
    _tizenMvLandmarkDetection ??= _getTizenNative(mv_landmark_detectionSymbols);

Tizen100Native? _tizenMvObjectDetection;
Tizen100Native get tizenMvObjectDetection =>
    _tizenMvObjectDetection ??= _getTizenNative(mv_object_detectionSymbols);

Tizen100Native? _tizenMvRoiTracker;
Tizen100Native get tizenMvRoiTracker =>
    _tizenMvRoiTracker ??= _getTizenNative(mv_roi_trackerSymbols);

Tizen100Native? _tizenMvSurveillance;
Tizen100Native get tizenMvSurveillance =>
    _tizenMvSurveillance ??= _getTizenNative(mv_surveillanceSymbols);

Tizen100Native? _tizenNotification;
Tizen100Native get tizenNotification =>
    _tizenNotification ??= _getTizenNative(notificationSymbols);

Tizen100Native? _tizenNsdDnsSd;
Tizen100Native get tizenNsdDnsSd =>
    _tizenNsdDnsSd ??= _getTizenNative(nsdDnsSdSymbols);

Tizen100Native? _tizenNsdSsdp;
Tizen100Native get tizenNsdSsdp =>
    _tizenNsdSsdp ??= _getTizenNative(nsdSsdpSymbols);

Tizen100Native? _tizenPhonenumberUtils;
Tizen100Native get tizenPhonenumberUtils =>
    _tizenPhonenumberUtils ??= _getTizenNative(phonenumberUtilsSymbols);

Tizen100Native? _tizenPrivilegeInfo;
Tizen100Native get tizenPrivilegeInfo =>
    _tizenPrivilegeInfo ??= _getTizenNative(privilegeInfoSymbols);

Tizen100Native? _tizenPush;
Tizen100Native get tizenPush =>
    _tizenPush ??= _getTizenNative(pushSymbols);

Tizen100Native? _tizenRpcPort;
Tizen100Native get tizenRpcPort =>
    _tizenRpcPort ??= _getTizenNative(rpcPortSymbols);

Tizen100Native? _tizenStt;
Tizen100Native get tizenStt =>
    _tizenStt ??= _getTizenNative(sttSymbols);

Tizen100Native? _tizenSttEngine;
Tizen100Native get tizenSttEngine =>
    _tizenSttEngine ??= _getTizenNative(stt_engineSymbols);

Tizen100Native? _tizenTbm;
Tizen100Native get tizenTbm =>
    _tizenTbm ??= _getTizenNative(tbmSymbols);

Tizen100Native? _tizenTizenCore;
Tizen100Native get tizenTizenCore =>
    _tizenTizenCore ??= _getTizenNative(tizenCoreSymbols);

Tizen100Native? _tizenTts;
Tizen100Native get tizenTts =>
    _tizenTts ??= _getTizenNative(ttsSymbols);

Tizen100Native? _tizenTtsEngine;
Tizen100Native get tizenTtsEngine =>
    _tizenTtsEngine ??= _getTizenNative(tts_engineSymbols);

Tizen100Native? _tizenUpdateControl;
Tizen100Native get tizenUpdateControl =>
    _tizenUpdateControl ??= _getTizenNative(updateControlSymbols);

Tizen100Native? _tizenVc;
Tizen100Native get tizenVc =>
    _tizenVc ??= _getTizenNative(vcSymbols);

Tizen100Native? _tizenVcEngine;
Tizen100Native get tizenVcEngine =>
    _tizenVcEngine ??= _getTizenNative(vc_engineSymbols);

Tizen100Native? _tizenVcManager;
Tizen100Native get tizenVcManager =>
    _tizenVcManager ??= _getTizenNative(vc_managerSymbols);

Tizen100Native? _tizenWebauthnClient;
Tizen100Native get tizenWebauthnClient =>
    _tizenWebauthnClient ??= _getTizenNative(webauthnClientSymbols);

Tizen100Native? _tizenWifiDirect;
Tizen100Native get tizenWifiDirect =>
    _tizenWifiDirect ??= _getTizenNative(wifiDirectSymbols);

Tizen100Native? _tizenYaca;
Tizen100Native get tizenYaca =>
    _tizenYaca ??= _getTizenNative(yacaSymbols);
