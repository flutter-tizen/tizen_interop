// Account
#include <account.h>
#include <fido.h>                    // deprecated
#include <fido_uaf_authenticator.h>  // deprecated
#include <fido_uaf_client.h>         // deprecated
#include <oauth2.h>
#include <oauth2_error.h>
#include <oauth2_manager.h>
#include <oauth2_request.h>
#include <oauth2_response.h>
#include <oauth2_types.h>
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
#include <badge.h>
#include <bundle.h>
#include <cion.h>
#include <cion_client.h>
#include <cion_connection_result.h>
#include <cion_error.h>
#include <cion_group.h>
#include <cion_payload.h>
#include <cion_payload_async_result.h>
#include <cion_peer_info.h>
#include <cion_security.h>
#include <cion_server.h>
#include <data_control.h>
#include <data_control_bulk.h>
#include <data_control_map.h>
#include <data_control_noti.h>
#include <data_control_provider.h>
#include <data_control_sql.h>
#include <data_control_sql_cursor.h>
#include <data_control_types.h>
#include <job_scheduler.h>
#include <message_port.h>
#include <notification.h>
#include <notification_error.h>
#include <notification_ex.h>
#include <notification_ex_app_control_action.h>
#include <notification_ex_button.h>
#include <notification_ex_chat_message.h>
#include <notification_ex_checkbox.h>
#include <notification_ex_entry.h>
#include <notification_ex_error.h>
#include <notification_ex_event_info.h>
#include <notification_ex_group.h>
#include <notification_ex_image.h>
#include <notification_ex_input_selector.h>
#include <notification_ex_item.h>
#include <notification_ex_manager.h>
#include <notification_ex_multi_language.h>
#include <notification_ex_progress.h>
#include <notification_ex_reporter.h>
#include <notification_ex_text.h>
#include <notification_ex_time.h>
#include <notification_ex_visibility_action.h>
#include <notification_status.h>
#include <notification_type.h>
#include <package_archive_info.h>
#include <package_manager.h>
#include <rpc-port-parcel.h>
#include <rpc-port.h>
#include <service_app.h>
#include <shortcut_error.h>
#include <shortcut_manager.h>

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
#include <ml-api-common.h>
#include <ml-api-service.h>
#include <nnstreamer-single.h>
#include <nnstreamer.h>
#include <nntrainer.h>

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
#include <media_controller_type.h>
#include <media_editor.h>
#include <media_format.h>
#include <media_packet.h>
#include <media_streamer.h>  //deprecated
#include <mediademuxer.h>
#include <mediamuxer.h>
#include <metadata_editor.h>
#include <metadata_editor_type.h>
#include <metadata_extractor.h>
#include <metadata_extractor_type.h>
#include <mv_3d.h>
#include <mv_barcode.h>
#include <mv_barcode_detect.h>
#include <mv_barcode_generate.h>
#include <mv_barcode_type.h>
#include <mv_common.h>
#include <mv_face.h>
#include <mv_face_recognition.h>
#include <mv_face_recognition_type.h>
#include <mv_face_type.h>
#include <mv_image.h>
#include <mv_image_type.h>
#include <mv_inference.h>
#include <mv_inference_type.h>
#include <mv_roi_tracker.h>
#include <mv_surveillance.h>
#include <player.h>
#include <radio.h>
#include <recorder.h>
#include <scmirroring_sink.h>
#include <scmirroring_type.h>
#include <sound_manager.h>
#include <sound_pool.h>
#include <sound_pool_type.h>
#include <streamrecorder.h>  //deprecated
#include <thumbnail_util.h>
#include <thumbnail_util_type.h>
#include <tone_player.h>
#include <wav_player.h>
#include <webrtc.h>

// Network
#include <asp.h>
#include <bluetooth.h>
#include <bluetooth_type.h>
#include <dns-sd.h>
#include <http.h>
#include <inm.h>
#include <iotcon.h>
#include <mtp.h>
#include <net_connection.h>
#include <softap.h>
#include <ssdp.h>
#include <stc.h>
#include <vpn_service.h>
#include <wifi-direct.h>
#include <wifi-manager.h>

// Security
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
#include <privilege_information.h>      // deprecated
#include <yaca_crypto.h>
#include <yaca_digest.h>
#include <yaca_encrypt.h>
#include <yaca_error.h>
#include <yaca_key.h>
#include <yaca_rsa.h>
#include <yaca_seal.h>
#include <yaca_sign.h>
#include <yaca_simple.h>
#include <yaca_types.h>

// Social
#include <calendar.h>
#include <calendar_db.h>
#include <calendar_errors.h>
#include <calendar_filter.h>
#include <calendar_list.h>
#include <calendar_query.h>
#include <calendar_record.h>
#include <calendar_reminder.h>
#include <calendar_service.h>
#include <calendar_types.h>
#include <calendar_vcalendar.h>
#include <calendar_view.h>
#include <contacts.h>
#include <contacts_activity.h>
#include <contacts_db.h>
#include <contacts_db_status.h>
#include <contacts_errors.h>
#include <contacts_filter.h>
#include <contacts_group.h>
#include <contacts_list.h>
#include <contacts_person.h>
#include <contacts_phone_log.h>
#include <contacts_query.h>
#include <contacts_record.h>
#include <contacts_service.h>
#include <contacts_setting.h>
#include <contacts_sim.h>
#include <contacts_types.h>
#include <contacts_vcard.h>
#include <contacts_views.h>
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
#include <resource-monitor.h>
#include <runtime_info.h>
#include <sensor.h>
#include <storage.h>
#include <system_info.h>
#include <system_info_type.h>
#include <system_settings.h>
#include <trace.h>
#include <update_control.h>
#include <usb_host.h>

// UI
#include <eom.h>  // deprecated
#include <tbm_surface.h>
#include <tbm_type.h>

// UIX
#include <autofill.h>
#include <autofill_common.h>
#include <autofill_manager.h>
#include <autofill_service.h>
#include <inputmethod.h>
#include <inputmethod_manager.h>
#include <multi_assistant.h>
#include <multi_assistant_common.h>
#include <stt.h>
#include <stte.h>
#include <tts.h>
#include <ttse.h>
#include <vce.h>
#include <voice_control.h>
#include <voice_control_manager.h>
