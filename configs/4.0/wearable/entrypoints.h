#define __GLIBC_USE

// Account
#include <account.h>
#include <fido.h>
#include <fido_uaf_authenticator.h>
#include <fido_uaf_client.h>
#include <oauth2.h>
#include <sync_manager.h>
#include <sync_adapter.h>

// Application Framework
#include <app.h>
#include <app_alarm.h>
#include <app_control.h>
#include <app_event.h>
#include <job_scheduler.h>
#include <app_preference.h>
#include <app_resource_manager.h>
#include <app_manager.h>
#include <badge.h>
#include <bundle.h>
#include <data_control.h>
#include <message_port.h>
#include <notification.h>
#include <package_manager.h>
#include <package_archive_info.h>
#include <service_app.h>
#include <watch_app.h>
#include <watch_app_efl.h>
#include <widget_service.h>
#include <widget_errno.h>
#include <widget_viewer_evas.h>

// Content
#include <mime_type.h>
#include <media_content.h>

// Context
#include <activity_recognition.h>
#include <wearable/context_history.h>
#include <gesture_recognition.h>

// Location
#include <locations.h>
#include <maps_service.h>

// Messaging
#include <email.h>
#include <messages.h>
#include <push-service.h>

// Multimedia
#include <audio_io.h>
#include <camera.h>
#include <image_util.h>
#include <media_codec.h>
#include <media_controller_server.h>
#include <media_controller_client.h>
#include <mediademuxer.h>
#include <mediamuxer.h>
#include <media_streamer.h>
#include <media_packet.h>
#include <media_format.h>
#include <mv_barcode.h>
#include <mv_common.h>
#include <mv_face.h>
#include <mv_image.h>
#include <mv_surveillance.h>
#include <metadata_editor.h>
#include <metadata_extractor.h>
#include <player.h>
#include <radio.h>
#include <recorder.h>
#include <sound_manager.h>
#include <sound_pool.h>
#include <streamrecorder.h>
#include <thumbnail_util.h>
#include <tone_player.h>
#include <wav_player.h>

// Network
#include <asp.h>
#include <bluetooth.h>
#include <net_connection.h>
#include <dns-sd.h>
#include <http.h>
#include <iotcon.h>
#include <nfc.h>
#include <ssdp.h>
#include <stc.h>
#include <smartcard.h>
#include <wifi-manager.h>

// Security
#include <csr-engine-manager.h>
#include <csr-content-screening.h>
#include <csr-content-screening-types.h>
#include <csr-error.h>
#include <csr-web-protection.h>
#include <csr-web-protection-types.h>
#include <dpm/password.h>
#include <dpm/device-policy-manager.h>
#include <dpm/restriction.h>
#include <dpm/security.h>
#include <dpm/zone.h>
#include <ckmc/ckmc-manager.h>
#include <ckmc/ckmc-type.h>
#include <privacy_privilege_manager.h>
#include <privilege_information.h>
#include <yaca/yaca_crypto.h>
#include <yaca/yaca_encrypt.h>
#include <yaca/yaca_seal.h>
#include <yaca/yaca_types.h>
#include <yaca/yaca_error.h>
#include <yaca/yaca_sign.h>
#include <yaca/yaca_digest.h>
#include <yaca/yaca_key.h>
#include <yaca/yaca_rsa.h>
#include <yaca/yaca_simple.h>

// Social
#include <calendar.h>
#include <contacts.h>
#include <phone_number.h>

// System
#include <device/battery.h>
#include <device/callback.h>
#include <device/display.h>
#include <device/haptic.h>
#include <device/led.h>
#include <device/power.h>
#include <device/ir.h>
#include <dlog.h>
#include <feedback.h>
#include <media_key.h>
#include <runtime_info.h>
#include <sensor.h>
#include <storage.h>
#include <system_info.h>
#include <system_settings.h>
#include <trace.h>

// Telephony
#include <telephony.h>

// UIX
#include <inputmethod.h>
#include <inputmethod_manager.h>
#include <stt.h>
#include <stte.h>
#include <tts.h>
#include <ttse.h>
#include <voice_control.h>


