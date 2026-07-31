import 'dart:ffi';
import 'package:ffi/ffi.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:integration_test/integration_test.dart';
import 'package:tizen_interop/6.0/tizen.dart';

enum DeviceType {
  kIsEmulator,
  kIsRPI,
  kIsTV,
}

void main() {
  IntegrationTestWidgetsFlutterBinding.ensureInitialized();

  // Check if running on emulator before tests
  DeviceType deviceType = DeviceType.kIsRPI;
  using((Arena arena) {
    final modelKey =
        'http://tizen.org/system/model_name'.toNativeChar(allocator: arena);
    final modelPtr = arena<Pointer<Char>>();
    final result =
        tizenCapiSystemInfo.system_info_get_platform_string(modelKey, modelPtr);
    if (result == 0) {
      final modelName = modelPtr.value.toDartString();
      if (modelName.contains('emulator') || modelName.contains('Emulator')) {
        deviceType = DeviceType.kIsEmulator;
      } else if (modelName.contains('rpi') || modelName.contains('Rpi')) {
        deviceType = DeviceType.kIsRPI;
      } else {
        deviceType = DeviceType.kIsTV;
      }
      arena.using(modelPtr.value, calloc.free);
    }
  });

  testWidgets('tizenCapiSystemRuntimeInfo: runtime_info_get_value_bool',
      (WidgetTester tester) async {
    final tizen = tizenCapiSystemRuntimeInfo;
    expect(tizen, isNotNull);
    using((Arena arena) {
      const int key = runtime_info_key_e.RUNTIME_INFO_KEY_BLUETOOTH_ENABLED;
      final valuePtr = arena<Bool>();
      // On emulator, this key might not be supported or return false
      final result = tizen.runtime_info_get_value_bool(key, valuePtr);
      expect(result, 0);
    });
  }, skip: deviceType == DeviceType.kIsEmulator);

  testWidgets('tizenCapiSystemSystemSettings: system_settings_get_value_int',
      (WidgetTester tester) async {
    final tizen = tizenCapiSystemSystemSettings;
    expect(tizen, isNotNull);
    using((Arena arena) {
      const int key = system_settings_key_e.SYSTEM_SETTINGS_KEY_FONT_SIZE;
      final valuePtr = arena<Int>();
      final result = tizen.system_settings_get_value_int(key, valuePtr);
      expect(result, 0); // Should succeed usually
    });
  }, skip: deviceType == DeviceType.kIsTV);

  testWidgets('tizenCapiSystemDevice: device_display_get_numbers',
      (WidgetTester tester) async {
    final tizen = tizenCapiSystemDevice;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final displayNumPtr = arena<Int>();
      final result = tizen.device_display_get_numbers(displayNumPtr);
      expect(result, 0);
    });
  });

  testWidgets('tizenCapiSystemSensor: sensor_is_supported',
      (WidgetTester tester) async {
    final tizen = tizenCapiSystemSensor;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final supportedPtr = arena<Bool>();
      const type = sensor_type_e.SENSOR_ACCELEROMETER;
      final result = tizen.sensor_is_supported(type, supportedPtr);
      expect(result, 0);
    });
  });

  testWidgets('tizenCapiAppfwAppCommon: app_get_id',
      (WidgetTester tester) async {
    final tizen = tizenCapiAppfwAppCommon;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final appIdPtr = arena<Pointer<Char>>();
      final result = tizen.app_get_id(appIdPtr);
      expect(result, 0);
      arena.using(appIdPtr.value, calloc.free);
    });
  });

  testWidgets(
      'tizenCapiAppfwAppControl: app_control_create & app_control_destroy',
      (WidgetTester tester) async {
    final tizen = tizenCapiAppfwAppControl;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<app_control_h>();
      var result = tizen.app_control_create(handlePtr);
      expect(result, 0);
      expect(handlePtr.value, isNot(nullptr));
      result = tizen.app_control_destroy(handlePtr.value);
      expect(result, 0);
    });
  });

  testWidgets(
      'tizenCapiAppfwAppManager: app_manager_get_app_context & app_context_destroy',
      (WidgetTester tester) async {
    final tizen = tizenCapiAppfwAppManager;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final contextPtr = arena<app_context_h>();
      final appId =
          'com.example.tizen_interop_example'.toNativeChar(allocator: arena);
      var result = tizen.app_manager_get_app_context(appId, contextPtr);
      expect(result, 0);
      expect(contextPtr.value, isNot(nullptr));
      result = tizen.app_context_destroy(contextPtr.value);
      expect(result, 0);
    });
  });

  testWidgets('tizenBundle: bundle_create & bundle_free',
      (WidgetTester tester) async {
    final tizen = tizenBundle;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final bundle = tizen.bundle_create();
      expect(bundle, isNot(nullptr));
      final result = tizen.bundle_free(bundle);
      expect(result, 0);
    });
  });

  testWidgets(
      'tizenCapiAppfwPackageManager: package_manager_create & package_manager_destroy',
      (WidgetTester tester) async {
    final tizen = tizenCapiAppfwPackageManager;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<package_manager_h>();
      var result = tizen.package_manager_create(handlePtr);
      expect(result, 0);
      expect(handlePtr.value, isNot(nullptr));
      result = tizen.package_manager_destroy(handlePtr.value);
      expect(result, 0);
    });
  });

  testWidgets('tizenNotification: notification_create & notification_free',
      (WidgetTester tester) async {
    final tizen = tizenNotification;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handle =
          tizen.notification_create(notification_type.NOTIFICATION_TYPE_NOTI);
      if (handle != nullptr) {
        final result = tizen.notification_free(handle);
        expect(result, 0);
      }
    });
  });

  testWidgets('tizenAccountsSvc: account_connect & account_disconnect',
      (WidgetTester tester) async {
    final tizen = tizenAccountsSvc;
    expect(tizen, isNotNull);
    using((Arena arena) {
      var result = tizen.account_connect();
      expect(result, 0);
      result = tizen.account_disconnect();
      expect(result, 0);
    });
  });

  testWidgets(
      'tizenCapiNetworkConnection: connection_create & connection_destroy',
      (WidgetTester tester) async {
    final tizen = tizenCapiNetworkConnection;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<connection_h>();
      var result = tizen.connection_create(handlePtr);
      expect(result, 0);
      result = tizen.connection_destroy(handlePtr.value);
      expect(result, 0);
    });
  });

  testWidgets(
      'tizenCapiNetworkWifiManager: wifi_manager_initialize & wifi_manager_deinitialize',
      (WidgetTester tester) async {
    final tizen = tizenCapiNetworkWifiManager;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<wifi_manager_h>();
      var result = tizen.wifi_manager_initialize(handlePtr);
      expect(result, 0);
      result = tizen.wifi_manager_deinitialize(handlePtr.value);
      expect(result, 0);
    });
  }, skip: deviceType == DeviceType.kIsEmulator);

  testWidgets(
      'tizenCapiAppfwPreference: preference_set_int & preference_get_int',
      (WidgetTester tester) async {
    final tizen = tizenCapiAppfwPreference;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final key = 'test_pref_int'.toNativeChar(allocator: arena);
      tizen.preference_set_int(key, 123);
      final valuePtr = arena<Int>();
      final result = tizen.preference_get_int(key, valuePtr);
      expect(result, 0);
      expect(valuePtr.value, 123);
    });
  });

  testWidgets(
      'tizenCapiLocationManager: location_manager_create & location_manager_destroy',
      (WidgetTester tester) async {
    final tizen = tizenCapiLocationManager;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<location_manager_h>();
      var result = tizen.location_manager_create(
          location_method_e.LOCATIONS_METHOD_HYBRID, handlePtr);
      expect(result, 0);
      result = tizen.location_manager_destroy(handlePtr.value);
      expect(result, 0);
    });
  }, skip: deviceType == DeviceType.kIsTV);

  testWidgets(
      'tizenCapiContentMediaContent: media_content_connect & media_content_disconnect',
      (WidgetTester tester) async {
    final tizen = tizenCapiContentMediaContent;
    expect(tizen, isNotNull);
    using((Arena arena) {
      var result = tizen.media_content_connect();
      expect(result, 0);
      result = tizen.media_content_disconnect();
      expect(result, 0);
    });
  });

  testWidgets('tizenCapiMediaSoundManager: sound_manager_get_volume',
      (WidgetTester tester) async {
    final tizen = tizenCapiMediaSoundManager;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final volPtr = arena<Int>();
      final result = tizen.sound_manager_get_volume(
          sound_type_e.SOUND_TYPE_SYSTEM, volPtr);
      expect(result, 0);
    });
  });

  testWidgets(
      'tizenCapiMediaSoundManager: sound_manager_create_stream_information & sound_manager_destroy_stream_information',
      (WidgetTester tester) async {
    final tizen = tizenCapiMediaSoundManager;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<sound_stream_info_h>();
      var result = tizen.sound_manager_create_stream_information(
          sound_stream_type_e.SOUND_STREAM_TYPE_MEDIA,
          Pointer.fromFunction(_soundManagerCallback),
          nullptr,
          handlePtr);
      expect(result, 0);
      result = tizen.sound_manager_destroy_stream_information(handlePtr.value);
      expect(result, 0);
    });
  });

  testWidgets('tizenRpcPort: rpc_port_parcel_create & rpc_port_parcel_destroy',
      (WidgetTester tester) async {
    final tizen = tizenRpcPort;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<rpc_port_parcel_h>();
      var result = tizen.rpc_port_parcel_create(handlePtr);
      expect(result, 0);
      expect(handlePtr, isNot(nullptr));
      result = tizen.rpc_port_parcel_destroy(handlePtr.value);
      expect(result, 0);
    });
  });

  testWidgets('tizenFeedback: feedback_initialize & feedback_deinitialize',
      (WidgetTester tester) async {
    final tizen = tizenFeedback;
    expect(tizen, isNotNull);
    using((Arena arena) {
      var result = tizen.feedback_initialize();
      expect(result, 0);
      result = tizen.feedback_deinitialize();
      expect(result, 0);
    });
  });

  testWidgets('tizenAppcoreAgent: service_app_add_event_handler',
      (WidgetTester tester) async {
    final tizen = tizenAppcoreAgent;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<app_event_handler_h>();
      final result = tizen.service_app_add_event_handler(
          handlePtr,
          app_event_type_e.APP_EVENT_LOW_MEMORY,
          Pointer.fromFunction(_serviceAppCallback),
          nullptr);
      expect(result, 0);
    });
  });

  testWidgets('tizenCapiAppfwAlarm: alarm_get_current_time',
      (WidgetTester tester) async {
    final tizen = tizenCapiAppfwAlarm;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final date = arena<tm>();
      final result = tizen.alarm_get_current_time(date);
      expect(result, 0);
    });
  });

  testWidgets('tizenCapiAppfwApplication: app_get_device_orientation',
      (WidgetTester tester) async {
    final tizen = tizenCapiAppfwApplication;
    expect(tizen, isNotNull);
    final result = tizen.app_get_device_orientation();
    expect(result, isA<int>());
  });

  testWidgets('tizenCapiAppfwEvent: event_add_event_handler',
      (WidgetTester tester) async {
    final tizen = tizenCapiAppfwEvent;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final eventName = 'eventName'.toNativeChar(allocator: arena);
      final handlePtr = arena<event_handler_h>();
      final result = tizen.event_add_event_handler(eventName,
          Pointer.fromFunction(_eventAddCallback), nullptr, handlePtr);
      expect(result, 0);
      expect(handlePtr.value, isNot(nullptr));
    });
  });

  testWidgets('tizenCapiAppfwJobScheduler: job_info_create & job_info_destroy',
      (WidgetTester tester) async {
    final tizen = tizenCapiAppfwJobScheduler;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<job_info_h>();
      var result = tizen.job_info_create(handlePtr);
      expect(result, 0);
      expect(handlePtr.value, isNot(nullptr));
      result = tizen.job_info_destroy(handlePtr.value);
    });
  }, skip: deviceType == DeviceType.kIsTV);

  testWidgets(
      'tizenCapiSystemDevice: device_battery_get_percent & tizenCapiBaseCommon: get_error_message',
      (WidgetTester tester) async {
    final tizen = tizenCapiSystemDevice;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final percentPtr = arena<Int>();
      final result = tizen.device_battery_get_percent(percentPtr);
      if (result != 0) {
        final errMsg = tizenCapiBaseCommon.get_error_message(result);
        expect(errMsg, isNot(null));
      }
    });
  });

  testWidgets('tizenCapiContentMimeType: mime_type_get_file_extension',
      (WidgetTester tester) async {
    final tizen = tizenCapiContentMimeType;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final mimeType = 'image/jpeg'.toNativeChar(allocator: arena);
      final extension = arena<Pointer<Pointer<Char>>>();
      final length = arena<Int>();
      final result =
          tizen.mime_type_get_file_extension(mimeType, extension, length);
      expect(result, 0);
    });
  });

  testWidgets('tizenCapiMediaAudioIo: audio_out_create_new',
      (WidgetTester tester) async {
    final tizen = tizenCapiMediaAudioIo;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<audio_out_h>();
      var result = tizen.audio_out_create_new(
          192000,
          audio_channel_e.AUDIO_CHANNEL_MONO,
          audio_sample_type_e.AUDIO_SAMPLE_TYPE_S32_LE,
          handlePtr);
      expect(result, 0);
      result = tizen.audio_out_destroy(handlePtr.value);
      expect(result, 0);
    });
  });

  testWidgets('tizenCapiMediaCamera: camera_create & camera_destroy',
      (WidgetTester tester) async {
    final tizen = tizenCapiMediaCamera;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<camera_h>();
      var result =
          tizen.camera_create(camera_device_e.CAMERA_DEVICE_CAMERA0, handlePtr);
      expect(result, 0);
      result = tizen.camera_destroy(handlePtr.value);
      expect(result, 0);
    });
  }, skip: deviceType == DeviceType.kIsTV);

  testWidgets('tizenCapiMediaController: mc_client_create & mc_client_destroy',
      (WidgetTester tester) async {
    final tizen = tizenCapiMediaController;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<mc_client_h>();
      var result = tizen.mc_client_create(handlePtr);
      expect(result, 0);
      result = tizen.mc_client_destroy(handlePtr.value);
      expect(result, 0);
    });
  });

  testWidgets(
      'tizenCapiMediaImageUtil: image_util_create_image & image_util_destroy_image',
      (WidgetTester tester) async {
    final tizen = tizenCapiMediaImageUtil;
    expect(tizen, isNotNull);
    using((Arena arena) {
      const width = 100;
      const height = 100;
      const dataSize = width * height * 4; // 4 bytes for RGBA8888
      final rawData = arena<UnsignedChar>(dataSize);
      for (int i = 0; i < dataSize; i++) {
        rawData[i] = 255;
      }
      final handlePtr = arena<image_util_image_h>();
      var result = tizen.image_util_create_image(
          width,
          height,
          image_util_colorspace_e.IMAGE_UTIL_COLORSPACE_RGBA8888,
          rawData,
          dataSize,
          handlePtr);
      expect(result, 0);
      result = tizen.image_util_destroy_image(handlePtr.value);
      expect(result, 0);
    });
  });

  testWidgets(
      'tizenCapiMediaMetadataExtractor: metadata_extractor_create & metadata_extractor_destroy',
      (WidgetTester tester) async {
    final tizen = tizenCapiMediaMetadataExtractor;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<metadata_extractor_h>();
      var result = tizen.metadata_extractor_create(handlePtr);
      expect(result, 0);
      result = tizen.metadata_extractor_destroy(handlePtr.value);
      expect(result, 0);
    });
  });

  testWidgets('tizenCapiMediaPlayer: player_create & player_destroy',
      (WidgetTester tester) async {
    final tizen = tizenCapiMediaPlayer;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<player_h>();
      var result = tizen.player_create(handlePtr);
      expect(result, 0);
      result = tizen.player_destroy(handlePtr.value);
      expect(result, 0);
    });
  });

  testWidgets(
      'tizenCapiMediaRecorder: recorder_create_audiorecorder & recorder_destroy',
      (WidgetTester tester) async {
    final tizen = tizenCapiMediaRecorder;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<recorder_h>();
      var result = tizen.recorder_create_audiorecorder(handlePtr);
      expect(result, 0);
      result = tizen.recorder_destroy(handlePtr.value);
      expect(result, 0);
    });
  }, skip: deviceType == DeviceType.kIsTV);

  testWidgets('tizenCapiMediaTool: media_format_create & media_format_unref',
      (WidgetTester tester) async {
    final tizen = tizenCapiMediaTool;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<media_format_h>();
      var result = tizen.media_format_create(handlePtr);
      expect(result, 0);
      result = tizen.media_format_unref(handlePtr.value);
      expect(result, 0);
    });
  });

  testWidgets('tizenCapiNetworkBluetooth: bt_adapter_get_state',
      (WidgetTester tester) async {
    final tizen = tizenCapiNetworkBluetooth;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final state = arena<Int32>();
      var result = tizen.bt_initialize();
      expect(result, 0);
      result = tizen.bt_adapter_get_state(state);
      expect(result, 0);
      expect(state.value, isA<int>());
      result = tizen.bt_deinitialize();
      expect(result, 0);
    });
  }, skip: deviceType == DeviceType.kIsEmulator);

  testWidgets('tizenCapiNetworkInm: inm_initialize & inm_deinitialize',
      (WidgetTester tester) async {
    final tizen = tizenCapiNetworkInm;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<inm_h>();
      var result = tizen.inm_initialize(handlePtr);
      expect(result, 0);
      result = tizen.inm_deinitialize(handlePtr.value);
      expect(result, 0);
    });
  }, skip: deviceType == DeviceType.kIsEmulator);

  testWidgets('tizenCapiNetworkSoftap: softap_create & softap_destroy',
      (WidgetTester tester) async {
    final tizen = tizenCapiNetworkSoftap;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<softap_h>();
      var result = tizen.softap_create(handlePtr);
      expect(result, 0);
      result = tizen.softap_destroy(handlePtr.value);
      expect(result, 0);
    });
  },
      skip: deviceType == DeviceType.kIsEmulator ||
          deviceType == DeviceType.kIsTV);

  testWidgets('tizenCapiSystemUsbhost: usb_host_create & usb_host_destroy',
      (WidgetTester tester) async {
    final tizen = tizenCapiSystemUsbhost;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<usb_host_context_h>();
      var result = tizen.usb_host_create(handlePtr);
      expect(result, 0);
      result = tizen.usb_host_destroy(handlePtr.value);
      expect(result, 0);
    });
  },
      skip: deviceType == DeviceType.kIsEmulator ||
          deviceType == DeviceType.kIsTV);

  testWidgets('tizenCapiVpnsvc: vpnsvc_init & vpnsvc_deinit',
      (WidgetTester tester) async {
    final tizen = tizenCapiVpnsvc;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<vpnsvc_h>();
      final ifaceName = 'tun0'.toNativeChar(allocator: arena);
      var result = tizen.vpnsvc_init(ifaceName, handlePtr);
      expect(result, 0);
      result = tizen.vpnsvc_deinit(handlePtr.value);
      expect(result, 0);
    });
  },
      skip: deviceType == DeviceType.kIsEmulator ||
          deviceType == DeviceType.kIsTV);

  testWidgets('tizenMa: ma_initialize & ma_deinitialize',
      (WidgetTester tester) async {
    final tizen = tizenMa;
    expect(tizen, isNotNull);
    using((Arena arena) {
      var result = tizen.ma_initialize();
      expect(result, 0);
      result = tizen.ma_prepare();
      expect(result, 0);

      result = tizen.ma_unprepare();
      expect(result, 0);
      result = tizen.ma_deinitialize();
      expect(result, 0);
    });
  });

  testWidgets('tizenMvCommon: mv_create_source & mv_destroy_source',
      (WidgetTester tester) async {
    final tizen = tizenMvCommon;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<mv_source_h>();
      var result = tizen.mv_create_source(handlePtr);
      expect(result, 0);
      result = tizen.mv_destroy_source(handlePtr.value);
      expect(result, 0);
    });
  });

  testWidgets('tizenMvImage: mv_image_object_create & mv_image_object_destroy',
      (WidgetTester tester) async {
    final tizen = tizenMvImage;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<mv_image_object_h>();
      var result = tizen.mv_image_object_create(handlePtr);
      expect(result, 0);
      result = tizen.mv_image_object_destroy(handlePtr.value);
      expect(result, 0);
    });
  });

  testWidgets('tizenMvInference: mv_inference_create & mv_inference_destroy',
      (WidgetTester tester) async {
    final tizen = tizenMvInference;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<mv_inference_h>();
      var result = tizen.mv_inference_create(handlePtr);
      expect(result, 0);
      result = tizen.mv_inference_destroy(handlePtr.value);
      expect(result, 0);
    });
  }, skip: deviceType == DeviceType.kIsTV);

  testWidgets(
      'tizenMvSurveillance: mv_surveillance_event_trigger_create & mv_surveillance_event_trigger_destroy',
      (WidgetTester tester) async {
    final tizen = tizenMvSurveillance;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<mv_surveillance_event_trigger_h>();
      final type = 'motion'.toNativeChar(allocator: arena);
      var result = tizen.mv_surveillance_event_trigger_create(type, handlePtr);
      expect(result, 0);
      result = tizen.mv_surveillance_event_trigger_destroy(handlePtr.value);
      expect(result, 0);
    });
  });

  testWidgets('tizenNsdDnsSd: dnssd_initialize & dnssd_deinitialize',
      (WidgetTester tester) async {
    final tizen = tizenNsdDnsSd;
    expect(tizen, isNotNull);
    using((Arena arena) {
      var result = tizen.dnssd_initialize();
      expect(result, 0);
      result = tizen.dnssd_deinitialize();
      expect(result, 0);
    });
  });

  testWidgets('tizenNsdSsdp: ssdp_initialize & ssdp_deinitialize',
      (WidgetTester tester) async {
    final tizen = tizenNsdSsdp;
    expect(tizen, isNotNull);
    using((Arena arena) {
      var result = tizen.ssdp_initialize();
      expect(result, 0);
      result = tizen.ssdp_deinitialize();
      expect(result, 0);
    });
  });

  testWidgets(
      'tizenPrivilegeInfo: privilege_info_get_display_name & privilege_info_get_description',
      (WidgetTester tester) async {
    final tizen = tizenPrivilegeInfo;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final displayName = arena<Pointer<Char>>();
      final description = arena<Pointer<Char>>();
      var result = tizen.privilege_info_get_display_name(
          "10.0".toNativeChar(allocator: arena),
          "http://tizen.org/privilege/application.launch"
              .toNativeChar(allocator: arena),
          displayName);
      expect(result, 0);
      result = tizen.privilege_info_get_description(
          "10.0".toNativeChar(allocator: arena),
          "http://tizen.org/privilege/application.launch"
              .toNativeChar(allocator: arena),
          description);
      expect(result, 0);
    });
  });

  testWidgets('tizenStt: stt_create & stt_destroy',
      (WidgetTester tester) async {
    final tizen = tizenStt;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<stt_h>();
      var result = tizen.stt_create(handlePtr);
      expect(result, 0);
      result = tizen.stt_destroy(handlePtr.value);
      expect(result, 0);
    });
  });

  testWidgets('tizenTts: tts_create & tts_destroy',
      (WidgetTester tester) async {
    final tizen = tizenTts;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final handlePtr = arena<tts_h>();
      var result = tizen.tts_create(handlePtr);
      expect(result, 0);
      result = tizen.tts_destroy(handlePtr.value);
      expect(result, 0);
    });
  });

  testWidgets(
      'tizenYaca: yaca_initialize, yaca_key_generate, yaca_key_destroy, yaca_cleanup',
      (WidgetTester tester) async {
    final tizen = tizenYaca;
    expect(tizen, isNotNull);
    using((Arena arena) {
      var result = tizen.yaca_initialize();
      expect(result, 0);
      final handlePtr = arena<yaca_key_h>();
      result = tizen.yaca_key_generate(yaca_key_type_e.YACA_KEY_TYPE_SYMMETRIC,
          yaca_key_bit_length_e.YACA_KEY_LENGTH_256BIT, handlePtr);
      expect(result, 0);
      tizen.yaca_key_destroy(handlePtr.value);
      tizen.yaca_cleanup();
    });
  });

  testWidgets('tizenVc: vc_initialize & vc_deinitialize',
      (WidgetTester tester) async {
    final tizen = tizenVc;
    expect(tizen, isNotNull);
    using((Arena arena) {
      var result = tizen.vc_initialize();
      expect(result, isA<int>());
      if (result == 0) {
        result = tizen.vc_deinitialize();
        expect(result, 0);
      }
    });
  });

  testWidgets('tizenVcEngine: vce_set_private_data',
      (WidgetTester tester) async {
    final tizen = tizenVcEngine;
    expect(tizen, isNotNull);
    using((Arena arena) {
      final key = 'test_key'.toNativeChar(allocator: arena);
      final data = 'test_data'.toNativeChar(allocator: arena);
      final result = tizen.vce_set_private_data(key, data);
      expect(result, isA<int>());
    });
  });

  testWidgets('tizenVcManager: vc_mgr_initialize & vc_mgr_deinitialize',
      (WidgetTester tester) async {
    final tizen = tizenVcManager;
    expect(tizen, isNotNull);
    using((Arena arena) {
      var result = tizen.vc_mgr_initialize();
      expect(result, isA<int>());
      if (result == 0) {
        result = tizen.vc_mgr_deinitialize();
        expect(result, 0);
      }
    });
  });
}

void _serviceAppCallback(app_event_info_h eventInfo, Pointer<Void> userData) {}

void _eventAddCallback(Pointer<Char> eventName, Pointer<bundle> eventData,
    Pointer<Void> userData) {}

void _soundManagerCallback(
    sound_stream_info_h streamInfo,
    int focusMask,
    int focusState,
    int reason,
    int soundBehavior,
    Pointer<Char> extraInfo,
    Pointer<Void> userData) {}
