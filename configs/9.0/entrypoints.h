// Account
#include <account.h>
#include <fido.h>                    // deprecated
#include <fido_uaf_authenticator.h>  // deprecated
#include <fido_uaf_client.h>         // deprecated
#include <oauth2.h>
#include <sync_adapter.h>
#include <sync_manager.h>

// Application Framework
#include <app.h>
#include <app_alarm.h>
#include <app_common.h>
#include <app_control.h>
#include <app_control_uri.h>
#include <app_event.h>
#include <app_manager.h>
#include <app_preference.h>
#include <app_resource_manager.h>
#include <badge.h>  // deprecated
#include <bundle.h>
#include <cion.h>
#include <data_control.h>
#include <job_scheduler.h>
#include <message_port.h>
#include <notification.h>
#include <notification_ex.h>
#include <package_archive_info.h>
#include <package_manager.h>
#include <rpc-port-parcel.h>
#include <rpc-port.h>
#include <service_app.h>
#include <tizen_core.h>

// Base
#include <tizen.h>
#include <tizen_error.h>
#include <tizen_type.h>

// Content
#include <download.h>
#include <media_content.h>
#include <mime_type.h>

// Context
#include <context_history.h>
#include <context_trigger.h>

// Location
#include <geofence_manager.h>  // deprecated
#include <geofence_type.h>     // deprecated
#include <locations.h>

// Machine Learning
#include <nnstreamer/ml-api-service.h>
#include <nnstreamer/nnstreamer-single.h>
#include <nnstreamer/nnstreamer.h>
#include <nntrainer/nntrainer.h>

// Messaging
#include <email.h>  //deprecated
#include <push-service.h>

// Multimedia
#include <audio_io.h>
#include <camera.h>
#include <image_util.h>
#include <media_codec.h>
#include <media_controller_client.h>
#include <media_controller_metadata.h>
#include <media_controller_playlist.h>
#include <media_controller_server.h>
#include <media_editor.h>
#include <media_format.h>
#include <media_packet.h>
#include <mediademuxer.h>
#include <mediamuxer.h>
#include <metadata_editor.h>  //deprecated
#include <metadata_extractor.h>
#include <mv_3d.h>
#include <mv_barcode.h>
#include <mv_common.h>
#include <mv_face.h>  //deprecated
#include <mv_face_recognition.h>
#include <mv_facial_landmark.h>
#include <mv_image.h>  //deprecated
#include <mv_image_classification.h>
#include <mv_inference.h>  //deprecated
#include <mv_object_detection.h>
#include <mv_pose_landmark.h>
#include <mv_roi_tracker.h>
#include <mv_surveillance.h>  //deprecated
#include <player.h>
#include <radio.h>
#include <recorder.h>
#include <scmirroring_sink.h>
#include <sound_manager.h>
#include <sound_pool.h>
#include <thumbnail_util.h>
#include <tone_player.h>
#include <wav_player.h>
#include <webrtc.h>

// Network
#include <asp.h>  //deprecated
#include <bluetooth.h>
#include <dns-sd.h>
#include <http.h>  //deprecated
#include <inm.h>
#include <iotcon.h>
#include <mtp.h>
#include <net_connection.h>
#include <nfc.h>
#include <softap.h>
#include <ssdp.h>
#include <stc.h>
#include <vpn_service.h>
#include <wifi-aware.h>
#include <wifi-direct.h>
#include <wifi-manager.h>

// Security
#include <ckmc/ckmc-extended.h>
#include <ckmc/ckmc-manager.h>
#include <ckmc/ckmc-type.h>
#include <csr-content-screening-types.h>  // deprecated
#include <csr-content-screening.h>        // deprecated
#include <csr-engine-manager.h>           // deprecated
#include <csr-error.h>                    // deprecated
#include <csr-web-protection-types.h>     // deprecated
#include <csr-web-protection.h>           // deprecated
#include <device_certificate_manager.h>
#include <dpm/device-policy-manager.h>  // deprecated
#include <dpm/password.h>               // deprecated
#include <dpm/restriction.h>            // deprecated
#include <dpm/security.h>               // deprecated
#include <dpm/zone.h>                   // deprecated
#include <privacy_privilege_manager.h>  // deprecated
#include <privilege_information.h>
#include <webauthn.h>
#include <yaca/yaca_key.h>
#include <yaca/yaca_rsa.h>
#include <yaca/yaca_simple.h>
#include <yaca_crypto.h>
#include <yaca_digest.h>
#include <yaca_encrypt.h>
#include <yaca_error.h>
#include <yaca_seal.h>
#include <yaca_sign.h>
#include <yaca_types.h>

// Social
#include <calendar.h>
#include <contacts.h>
#include <phone_number.h>

// System
#include <device/battery.h>
#include <device/callback.h>
#include <device/display.h>
#include <device/haptic.h>
#include <device/ir.h>
#include <device/led.h>
#include <device/power.h>
#include <device/temperature.h>
#include <diagnostics.h>
#include <dlog.h>
#include <feedback.h>
#include <media_key.h>
#include <peripheral_io.h>
#include <runtime_info.h>
#include <sensor.h>
#include <storage.h>
#include <system/resource-monitor.h>
#include <system_info.h>
#include <system_settings.h>
#include <trace.h>
#include <update_control.h>
#include <usb_host.h>

// UI
#include <eom.h>  // deprecated
#include <tbm_surface.h>

// UIX
#include <autofill.h>
#include <autofill_common.h>
#include <autofill_manager.h>
#include <autofill_service.h>
#include <inputmethod.h>
#include <inputmethod_manager.h>
#include <mmi-node.h>
#include <mmi-workflow.h>
#include <mmi.h>
#include <multi_assistant.h>
#include <multi_assistant_common.h>
#include <stt.h>
#include <stte.h>
#include <tts.h>
#include <ttse.h>
#include <vce.h>
#include <voice_control.h>
#include <voice_control_manager.h>
