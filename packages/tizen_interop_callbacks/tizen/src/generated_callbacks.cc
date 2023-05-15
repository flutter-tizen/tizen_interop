#include "tizen_interop_callbacks_plugin.h"

#include <cstdint>
#include <map>
#include <string>

#include "macros.h"
#include "types.h"

static constexpr int32_t kNoUserDataCallbackCount = 54;

uint32_t reserved_callback_ids[kProxyInstanceCount * kNoUserDataCallbackCount] = {};

typedef bool (*account_cb)(void* account, void* user_data);
#define CB_PARAMS_NAMES account, user_data
PROXY_GROUP_RETURN(account_cb, bool, void* account, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*account_custom_cb)(char* key, char* value, void* user_data);
#define CB_PARAMS_NAMES key, value, user_data
PROXY_GROUP_RETURN(account_custom_cb, bool, char* key, char* value, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*account_event_cb)(const char* event_type, int account_id, void* user_data);
#define CB_PARAMS_NAMES event_type, account_id, user_data
PROXY_GROUP_RETURN(account_event_cb, bool, const char* event_type, int account_id, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*account_label_cb)(char* app_id, char* label, char* locale, void* user_data);
#define CB_PARAMS_NAMES app_id, label, locale, user_data
PROXY_GROUP_RETURN(account_label_cb, bool, char* app_id, char* label, char* locale, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*account_type_cb)(void* account_type, void* user_data);
#define CB_PARAMS_NAMES account_type, user_data
PROXY_GROUP_RETURN(account_type_cb, bool, void* account_type, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*activity_recognition_cb)(some_enum activity, const void* data, double timestamp, some_enum error, void* user_data);
#define CB_PARAMS_NAMES activity, data, timestamp, error, user_data
PROXY_GROUP_NON_BLOCKING(activity_recognition_cb, some_enum activity, const void* data, double timestamp, some_enum error, void* user_data)
PROXY_GROUP_BLOCKING(activity_recognition_cb, some_enum activity, const void* data, double timestamp, some_enum error, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*alarm_registered_alarm_cb)(int alarm_id, void* user_data);
#define CB_PARAMS_NAMES alarm_id, user_data
PROXY_GROUP_RETURN(alarm_registered_alarm_cb, bool, int alarm_id, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*app_control_action_cb)(const char* action, void* app_control, void* user_data);
#define CB_PARAMS_NAMES action, app_control, user_data
PROXY_GROUP_NON_BLOCKING(app_control_action_cb, const char* action, void* app_control, void* user_data)
PROXY_GROUP_BLOCKING(app_control_action_cb, const char* action, void* app_control, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*app_control_app_matched_cb)(void* app_control, const char* appid, void* user_data);
#define CB_PARAMS_NAMES app_control, appid, user_data
PROXY_GROUP_RETURN(app_control_app_matched_cb, bool, void* app_control, const char* appid, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*app_control_cb)(void* app_control, void* user_data);
#define CB_PARAMS_NAMES app_control, user_data
PROXY_GROUP_NON_BLOCKING(app_control_cb, void* app_control, void* user_data)
PROXY_GROUP_BLOCKING(app_control_cb, void* app_control, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*app_control_extra_data_cb)(void* app_control, const char* key, void* user_data);
#define CB_PARAMS_NAMES app_control, key, user_data
PROXY_GROUP_RETURN(app_control_extra_data_cb, bool, void* app_control, const char* key, void* user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_app_control_host_res_fn 0
typedef int (*app_control_host_res_fn)(void* data);
#define CB_PARAMS_NAMES data
PROXY_GROUP_RETURN_NO_USER_DATA(app_control_host_res_fn, int, void* data)
#undef CB_PARAMS_NAMES

typedef void (*app_control_reply_cb)(void* request, void* reply, some_enum result, void* user_data);
#define CB_PARAMS_NAMES request, reply, result, user_data
PROXY_GROUP_NON_BLOCKING(app_control_reply_cb, void* request, void* reply, some_enum result, void* user_data)
PROXY_GROUP_BLOCKING(app_control_reply_cb, void* request, void* reply, some_enum result, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*app_control_result_cb)(void* request, some_enum result, void* user_data);
#define CB_PARAMS_NAMES request, result, user_data
PROXY_GROUP_NON_BLOCKING(app_control_result_cb, void* request, some_enum result, void* user_data)
PROXY_GROUP_BLOCKING(app_control_result_cb, void* request, some_enum result, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*app_control_uri_query_foreach_cb)(const char* key, const char* val, void* user_data);
#define CB_PARAMS_NAMES key, val, user_data
PROXY_GROUP_RETURN(app_control_uri_query_foreach_cb, bool, const char* key, const char* val, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*app_create_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_RETURN(app_create_cb, bool, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*app_event_cb)(void* event_info, void* user_data);
#define CB_PARAMS_NAMES event_info, user_data
PROXY_GROUP_NON_BLOCKING(app_event_cb, void* event_info, void* user_data)
PROXY_GROUP_BLOCKING(app_event_cb, void* event_info, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*app_manager_app_context_cb)(void* app_context, void* user_data);
#define CB_PARAMS_NAMES app_context, user_data
PROXY_GROUP_RETURN(app_manager_app_context_cb, bool, void* app_context, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*app_manager_app_context_event_cb)(void* app_context, some_enum event, void* user_data);
#define CB_PARAMS_NAMES app_context, event, user_data
PROXY_GROUP_NON_BLOCKING(app_manager_app_context_event_cb, void* app_context, some_enum event, void* user_data)
PROXY_GROUP_BLOCKING(app_manager_app_context_event_cb, void* app_context, some_enum event, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*app_manager_app_info_cb)(void* app_info, void* user_data);
#define CB_PARAMS_NAMES app_info, user_data
PROXY_GROUP_RETURN(app_manager_app_info_cb, bool, void* app_info, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*app_manager_event_cb)(const char* type, const char* app_id, some_enum event_type, some_enum event_state, void* handle, void* user_data);
#define CB_PARAMS_NAMES type, app_id, event_type, event_state, handle, user_data
PROXY_GROUP_NON_BLOCKING(app_manager_event_cb, const char* type, const char* app_id, some_enum event_type, some_enum event_state, void* handle, void* user_data)
PROXY_GROUP_BLOCKING(app_manager_event_cb, const char* type, const char* app_id, some_enum event_type, some_enum event_state, void* handle, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*app_pause_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(app_pause_cb, void* user_data)
PROXY_GROUP_BLOCKING(app_pause_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*app_resume_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(app_resume_cb, void* user_data)
PROXY_GROUP_BLOCKING(app_resume_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*app_terminate_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(app_terminate_cb, void* user_data)
PROXY_GROUP_BLOCKING(app_terminate_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*asp_advert_status_changed_cb)(void* adv_service, some_enum status, some_enum reason, void* user_data);
#define CB_PARAMS_NAMES adv_service, status, reason, user_data
PROXY_GROUP_NON_BLOCKING(asp_advert_status_changed_cb, void* adv_service, some_enum status, some_enum reason, void* user_data)
PROXY_GROUP_BLOCKING(asp_advert_status_changed_cb, void* adv_service, some_enum status, some_enum reason, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*asp_seek_search_result_cb)(int error_code, void* seek_service, const char* service_mac, unsigned int adv_id, some_enum config_method, const char* instance_name, const char* service_info, int info_size, unsigned char status, void* user_data);
#define CB_PARAMS_NAMES error_code, seek_service, service_mac, adv_id, config_method, instance_name, service_info, info_size, status, user_data
PROXY_GROUP_NON_BLOCKING(asp_seek_search_result_cb, int error_code, void* seek_service, const char* service_mac, unsigned int adv_id, some_enum config_method, const char* instance_name, const char* service_info, int info_size, unsigned char status, void* user_data)
PROXY_GROUP_BLOCKING(asp_seek_search_result_cb, int error_code, void* seek_service, const char* service_mac, unsigned int adv_id, some_enum config_method, const char* instance_name, const char* service_info, int info_size, unsigned char status, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*asp_session_config_request_cb)(int error_code, void* session, bool get_pin, const char* config_pin, void* user_data);
#define CB_PARAMS_NAMES error_code, session, get_pin, config_pin, user_data
PROXY_GROUP_NON_BLOCKING(asp_session_config_request_cb, int error_code, void* session, bool get_pin, const char* config_pin, void* user_data)
PROXY_GROUP_BLOCKING(asp_session_config_request_cb, int error_code, void* session, bool get_pin, const char* config_pin, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*asp_session_connect_status_cb)(int error_code, void* session, some_enum status, const char* deferred_resp, int resp_size, void* user_data);
#define CB_PARAMS_NAMES error_code, session, status, deferred_resp, resp_size, user_data
PROXY_GROUP_NON_BLOCKING(asp_session_connect_status_cb, int error_code, void* session, some_enum status, const char* deferred_resp, int resp_size, void* user_data)
PROXY_GROUP_BLOCKING(asp_session_connect_status_cb, int error_code, void* session, some_enum status, const char* deferred_resp, int resp_size, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*asp_session_port_status_cb)(int error_code, void* session, const char* ip_address, int port, int proto, some_enum status, void* user_data);
#define CB_PARAMS_NAMES error_code, session, ip_address, port, proto, status, user_data
PROXY_GROUP_NON_BLOCKING(asp_session_port_status_cb, int error_code, void* session, const char* ip_address, int port, int proto, some_enum status, void* user_data)
PROXY_GROUP_BLOCKING(asp_session_port_status_cb, int error_code, void* session, const char* ip_address, int port, int proto, some_enum status, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*asp_session_request_cb)(int error_code, void* adv_service, void* session, const char* device_name, const char* info, int info_size, bool get_network_config_pin, const char* network_config_pin, void* user_data);
#define CB_PARAMS_NAMES error_code, adv_service, session, device_name, info, info_size, get_network_config_pin, network_config_pin, user_data
PROXY_GROUP_NON_BLOCKING(asp_session_request_cb, int error_code, void* adv_service, void* session, const char* device_name, const char* info, int info_size, bool get_network_config_pin, const char* network_config_pin, void* user_data)
PROXY_GROUP_BLOCKING(asp_session_request_cb, int error_code, void* adv_service, void* session, const char* device_name, const char* info, int info_size, bool get_network_config_pin, const char* network_config_pin, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*asp_session_status_cb)(int error_code, void* session, some_enum state, const char* additional_info, void* user_data);
#define CB_PARAMS_NAMES error_code, session, state, additional_info, user_data
PROXY_GROUP_NON_BLOCKING(asp_session_status_cb, int error_code, void* session, some_enum state, const char* additional_info, void* user_data)
PROXY_GROUP_BLOCKING(asp_session_status_cb, int error_code, void* session, some_enum state, const char* additional_info, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*audio_in_state_changed_cb)(void* handle, some_enum previous, some_enum current, bool by_policy, void* user_data);
#define CB_PARAMS_NAMES handle, previous, current, by_policy, user_data
PROXY_GROUP_NON_BLOCKING(audio_in_state_changed_cb, void* handle, some_enum previous, some_enum current, bool by_policy, void* user_data)
PROXY_GROUP_BLOCKING(audio_in_state_changed_cb, void* handle, some_enum previous, some_enum current, bool by_policy, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*audio_in_stream_cb)(void* handle, size_t nbytes, void* user_data);
#define CB_PARAMS_NAMES handle, nbytes, user_data
PROXY_GROUP_NON_BLOCKING(audio_in_stream_cb, void* handle, size_t nbytes, void* user_data)
PROXY_GROUP_BLOCKING(audio_in_stream_cb, void* handle, size_t nbytes, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*audio_io_interrupted_cb)(some_enum code, void* user_data);
#define CB_PARAMS_NAMES code, user_data
PROXY_GROUP_NON_BLOCKING(audio_io_interrupted_cb, some_enum code, void* user_data)
PROXY_GROUP_BLOCKING(audio_io_interrupted_cb, some_enum code, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*audio_out_state_changed_cb)(void* handle, some_enum previous, some_enum current, bool by_policy, void* user_data);
#define CB_PARAMS_NAMES handle, previous, current, by_policy, user_data
PROXY_GROUP_NON_BLOCKING(audio_out_state_changed_cb, void* handle, some_enum previous, some_enum current, bool by_policy, void* user_data)
PROXY_GROUP_BLOCKING(audio_out_state_changed_cb, void* handle, some_enum previous, some_enum current, bool by_policy, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*audio_out_stream_cb)(void* handle, size_t nbytes, void* user_data);
#define CB_PARAMS_NAMES handle, nbytes, user_data
PROXY_GROUP_NON_BLOCKING(audio_out_stream_cb, void* handle, size_t nbytes, void* user_data)
PROXY_GROUP_BLOCKING(audio_out_stream_cb, void* handle, size_t nbytes, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*autofill_auth_info_received_cb)(void* ah, void* auth_info, void* user_data);
#define CB_PARAMS_NAMES ah, auth_info, user_data
PROXY_GROUP_NON_BLOCKING(autofill_auth_info_received_cb, void* ah, void* auth_info, void* user_data)
PROXY_GROUP_BLOCKING(autofill_auth_info_received_cb, void* ah, void* auth_info, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*autofill_connection_status_changed_cb)(void* ah, some_enum status, void* user_data);
#define CB_PARAMS_NAMES ah, status, user_data
PROXY_GROUP_NON_BLOCKING(autofill_connection_status_changed_cb, void* ah, some_enum status, void* user_data)
PROXY_GROUP_BLOCKING(autofill_connection_status_changed_cb, void* ah, some_enum status, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*autofill_error_info_received_cb)(void* ah, void* error_info, void* user_data);
#define CB_PARAMS_NAMES ah, error_info, user_data
PROXY_GROUP_NON_BLOCKING(autofill_error_info_received_cb, void* ah, void* error_info, void* user_data)
PROXY_GROUP_BLOCKING(autofill_error_info_received_cb, void* ah, void* error_info, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*autofill_fill_response_group_cb)(void* item, void* user_data);
#define CB_PARAMS_NAMES item, user_data
PROXY_GROUP_RETURN(autofill_fill_response_group_cb, bool, void* item, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*autofill_fill_response_item_cb)(void* item, void* user_data);
#define CB_PARAMS_NAMES item, user_data
PROXY_GROUP_RETURN(autofill_fill_response_item_cb, bool, void* item, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*autofill_fill_response_received_cb)(void* ah, void* fill_response_h, void* user_data);
#define CB_PARAMS_NAMES ah, fill_response_h, user_data
PROXY_GROUP_NON_BLOCKING(autofill_fill_response_received_cb, void* ah, void* fill_response_h, void* user_data)
PROXY_GROUP_BLOCKING(autofill_fill_response_received_cb, void* ah, void* fill_response_h, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*autofill_item_cb)(void* item, void* user_data);
#define CB_PARAMS_NAMES item, user_data
PROXY_GROUP_RETURN(autofill_item_cb, bool, void* item, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*autofill_manager_autofill_service_cb)(const char* app_id, void* user_data);
#define CB_PARAMS_NAMES app_id, user_data
PROXY_GROUP_RETURN(autofill_manager_autofill_service_cb, bool, const char* app_id, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*autofill_manager_connection_status_changed_cb)(void* amh, some_enum status, void* user_data);
#define CB_PARAMS_NAMES amh, status, user_data
PROXY_GROUP_NON_BLOCKING(autofill_manager_connection_status_changed_cb, void* amh, some_enum status, void* user_data)
PROXY_GROUP_BLOCKING(autofill_manager_connection_status_changed_cb, void* amh, some_enum status, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*autofill_save_item_cb)(void* item, void* user_data);
#define CB_PARAMS_NAMES item, user_data
PROXY_GROUP_RETURN(autofill_save_item_cb, bool, void* item, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*autofill_service_auth_info_requested_cb)(int context_id, void* vi, void* user_data);
#define CB_PARAMS_NAMES context_id, vi, user_data
PROXY_GROUP_NON_BLOCKING(autofill_service_auth_info_requested_cb, int context_id, void* vi, void* user_data)
PROXY_GROUP_BLOCKING(autofill_service_auth_info_requested_cb, int context_id, void* vi, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*autofill_service_cancel_fill_requested_cb)(int context_id, void* vi, void* user_data);
#define CB_PARAMS_NAMES context_id, vi, user_data
PROXY_GROUP_NON_BLOCKING(autofill_service_cancel_fill_requested_cb, int context_id, void* vi, void* user_data)
PROXY_GROUP_BLOCKING(autofill_service_cancel_fill_requested_cb, int context_id, void* vi, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*autofill_service_committed_cb)(int context_id, void* vi, void* user_data);
#define CB_PARAMS_NAMES context_id, vi, user_data
PROXY_GROUP_NON_BLOCKING(autofill_service_committed_cb, int context_id, void* vi, void* user_data)
PROXY_GROUP_BLOCKING(autofill_service_committed_cb, int context_id, void* vi, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*autofill_service_fill_requested_cb)(int context_id, void* vi, void* user_data);
#define CB_PARAMS_NAMES context_id, vi, user_data
PROXY_GROUP_NON_BLOCKING(autofill_service_fill_requested_cb, int context_id, void* vi, void* user_data)
PROXY_GROUP_BLOCKING(autofill_service_fill_requested_cb, int context_id, void* vi, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*autofill_service_terminate_received_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(autofill_service_terminate_received_cb, void* user_data)
PROXY_GROUP_BLOCKING(autofill_service_terminate_received_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*badge_change_cb)(unsigned int action, const char* app_id, unsigned int count, void* user_data);
#define CB_PARAMS_NAMES action, app_id, count, user_data
PROXY_GROUP_NON_BLOCKING(badge_change_cb, unsigned int action, const char* app_id, unsigned int count, void* user_data)
PROXY_GROUP_BLOCKING(badge_change_cb, unsigned int action, const char* app_id, unsigned int count, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*badge_foreach_cb)(const char* app_id, unsigned int count, void* user_data);
#define CB_PARAMS_NAMES app_id, count, user_data
PROXY_GROUP_RETURN(badge_foreach_cb, bool, const char* app_id, unsigned int count, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*bundle_iterator_t)(const char* key, const int type, const void* kv, void* user_data);
#define CB_PARAMS_NAMES key, type, kv, user_data
PROXY_GROUP_NON_BLOCKING(bundle_iterator_t, const char* key, const int type, const void* kv, void* user_data)
PROXY_GROUP_BLOCKING(bundle_iterator_t, const char* key, const int type, const void* kv, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*camera_attr_hdr_progress_cb)(int percent, void* user_data);
#define CB_PARAMS_NAMES percent, user_data
PROXY_GROUP_NON_BLOCKING(camera_attr_hdr_progress_cb, int percent, void* user_data)
PROXY_GROUP_BLOCKING(camera_attr_hdr_progress_cb, int percent, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*camera_attr_supported_af_mode_cb)(some_enum mode, void* user_data);
#define CB_PARAMS_NAMES mode, user_data
PROXY_GROUP_RETURN(camera_attr_supported_af_mode_cb, bool, some_enum mode, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*camera_attr_supported_effect_cb)(some_enum effect, void* user_data);
#define CB_PARAMS_NAMES effect, user_data
PROXY_GROUP_RETURN(camera_attr_supported_effect_cb, bool, some_enum effect, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*camera_attr_supported_exposure_mode_cb)(some_enum mode, void* user_data);
#define CB_PARAMS_NAMES mode, user_data
PROXY_GROUP_RETURN(camera_attr_supported_exposure_mode_cb, bool, some_enum mode, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*camera_attr_supported_flash_mode_cb)(some_enum mode, void* user_data);
#define CB_PARAMS_NAMES mode, user_data
PROXY_GROUP_RETURN(camera_attr_supported_flash_mode_cb, bool, some_enum mode, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*camera_attr_supported_fps_cb)(some_enum fps, void* user_data);
#define CB_PARAMS_NAMES fps, user_data
PROXY_GROUP_RETURN(camera_attr_supported_fps_cb, bool, some_enum fps, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*camera_attr_supported_iso_cb)(some_enum iso, void* user_data);
#define CB_PARAMS_NAMES iso, user_data
PROXY_GROUP_RETURN(camera_attr_supported_iso_cb, bool, some_enum iso, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*camera_attr_supported_ptz_type_cb)(some_enum type, void* user_data);
#define CB_PARAMS_NAMES type, user_data
PROXY_GROUP_RETURN(camera_attr_supported_ptz_type_cb, bool, some_enum type, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*camera_attr_supported_scene_mode_cb)(some_enum mode, void* user_data);
#define CB_PARAMS_NAMES mode, user_data
PROXY_GROUP_RETURN(camera_attr_supported_scene_mode_cb, bool, some_enum mode, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*camera_attr_supported_stream_flip_cb)(some_enum flip, void* user_data);
#define CB_PARAMS_NAMES flip, user_data
PROXY_GROUP_RETURN(camera_attr_supported_stream_flip_cb, bool, some_enum flip, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*camera_attr_supported_stream_rotation_cb)(some_enum rotation, void* user_data);
#define CB_PARAMS_NAMES rotation, user_data
PROXY_GROUP_RETURN(camera_attr_supported_stream_rotation_cb, bool, some_enum rotation, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*camera_attr_supported_theater_mode_cb)(some_enum mode, void* user_data);
#define CB_PARAMS_NAMES mode, user_data
PROXY_GROUP_RETURN(camera_attr_supported_theater_mode_cb, bool, some_enum mode, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*camera_attr_supported_whitebalance_cb)(some_enum wb, void* user_data);
#define CB_PARAMS_NAMES wb, user_data
PROXY_GROUP_RETURN(camera_attr_supported_whitebalance_cb, bool, some_enum wb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*camera_capture_completed_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(camera_capture_completed_cb, void* user_data)
PROXY_GROUP_BLOCKING(camera_capture_completed_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*camera_capturing_cb)(void* image, void* postview, void* thumbnail, void* user_data);
#define CB_PARAMS_NAMES image, postview, thumbnail, user_data
PROXY_GROUP_NON_BLOCKING(camera_capturing_cb, void* image, void* postview, void* thumbnail, void* user_data)
PROXY_GROUP_BLOCKING(camera_capturing_cb, void* image, void* postview, void* thumbnail, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*camera_device_connection_changed_cb)(void* device, bool is_connected, void* user_data);
#define CB_PARAMS_NAMES device, is_connected, user_data
PROXY_GROUP_NON_BLOCKING(camera_device_connection_changed_cb, void* device, bool is_connected, void* user_data)
PROXY_GROUP_BLOCKING(camera_device_connection_changed_cb, void* device, bool is_connected, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*camera_device_state_changed_cb)(some_enum device, some_enum state, void* user_data);
#define CB_PARAMS_NAMES device, state, user_data
PROXY_GROUP_NON_BLOCKING(camera_device_state_changed_cb, some_enum device, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(camera_device_state_changed_cb, some_enum device, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*camera_error_cb)(some_enum error, some_enum current_state, void* user_data);
#define CB_PARAMS_NAMES error, current_state, user_data
PROXY_GROUP_NON_BLOCKING(camera_error_cb, some_enum error, some_enum current_state, void* user_data)
PROXY_GROUP_BLOCKING(camera_error_cb, some_enum error, some_enum current_state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*camera_extra_preview_cb)(void* frame, int stream_id, void* user_data);
#define CB_PARAMS_NAMES frame, stream_id, user_data
PROXY_GROUP_NON_BLOCKING(camera_extra_preview_cb, void* frame, int stream_id, void* user_data)
PROXY_GROUP_BLOCKING(camera_extra_preview_cb, void* frame, int stream_id, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*camera_face_detected_cb)(void* faces, int count, void* user_data);
#define CB_PARAMS_NAMES faces, count, user_data
PROXY_GROUP_NON_BLOCKING(camera_face_detected_cb, void* faces, int count, void* user_data)
PROXY_GROUP_BLOCKING(camera_face_detected_cb, void* faces, int count, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*camera_focus_changed_cb)(some_enum state, void* user_data);
#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(camera_focus_changed_cb, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(camera_focus_changed_cb, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*camera_interrupt_started_cb)(some_enum policy, some_enum state, void* user_data);
#define CB_PARAMS_NAMES policy, state, user_data
PROXY_GROUP_NON_BLOCKING(camera_interrupt_started_cb, some_enum policy, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(camera_interrupt_started_cb, some_enum policy, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*camera_interrupted_cb)(some_enum policy, some_enum previous, some_enum current, void* user_data);
#define CB_PARAMS_NAMES policy, previous, current, user_data
PROXY_GROUP_NON_BLOCKING(camera_interrupted_cb, some_enum policy, some_enum previous, some_enum current, void* user_data)
PROXY_GROUP_BLOCKING(camera_interrupted_cb, some_enum policy, some_enum previous, some_enum current, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*camera_media_packet_preview_cb)(void* pkt, void* user_data);
#define CB_PARAMS_NAMES pkt, user_data
PROXY_GROUP_NON_BLOCKING(camera_media_packet_preview_cb, void* pkt, void* user_data)
PROXY_GROUP_BLOCKING(camera_media_packet_preview_cb, void* pkt, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*camera_preview_cb)(void* frame, void* user_data);
#define CB_PARAMS_NAMES frame, user_data
PROXY_GROUP_NON_BLOCKING(camera_preview_cb, void* frame, void* user_data)
PROXY_GROUP_BLOCKING(camera_preview_cb, void* frame, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*camera_state_changed_cb)(some_enum previous, some_enum current, bool by_policy, void* user_data);
#define CB_PARAMS_NAMES previous, current, by_policy, user_data
PROXY_GROUP_NON_BLOCKING(camera_state_changed_cb, some_enum previous, some_enum current, bool by_policy, void* user_data)
PROXY_GROUP_BLOCKING(camera_state_changed_cb, some_enum previous, some_enum current, bool by_policy, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*camera_supported_capture_format_cb)(some_enum format, void* user_data);
#define CB_PARAMS_NAMES format, user_data
PROXY_GROUP_RETURN(camera_supported_capture_format_cb, bool, some_enum format, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*camera_supported_capture_resolution_cb)(int width, int height, void* user_data);
#define CB_PARAMS_NAMES width, height, user_data
PROXY_GROUP_RETURN(camera_supported_capture_resolution_cb, bool, int width, int height, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*camera_supported_device_cb)(void* device, void* user_data);
#define CB_PARAMS_NAMES device, user_data
PROXY_GROUP_RETURN(camera_supported_device_cb, bool, void* device, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*camera_supported_preview_format_cb)(some_enum format, void* user_data);
#define CB_PARAMS_NAMES format, user_data
PROXY_GROUP_RETURN(camera_supported_preview_format_cb, bool, some_enum format, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*camera_supported_preview_resolution_cb)(int width, int height, void* user_data);
#define CB_PARAMS_NAMES width, height, user_data
PROXY_GROUP_RETURN(camera_supported_preview_resolution_cb, bool, int width, int height, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*capability_cb)(const char* capability_type, some_enum capability_state, void* user_data);
#define CB_PARAMS_NAMES capability_type, capability_state, user_data
PROXY_GROUP_RETURN(capability_cb, bool, const char* capability_type, some_enum capability_state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*cbhm_item_changed_cb)(void* cbhm_handle, int item_count, void* user_data);
#define CB_PARAMS_NAMES cbhm_handle, item_count, user_data
PROXY_GROUP_NON_BLOCKING(cbhm_item_changed_cb, void* cbhm_handle, int item_count, void* user_data)
PROXY_GROUP_BLOCKING(cbhm_item_changed_cb, void* cbhm_handle, int item_count, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*cbhm_monitor_cb)(void* cbhm_handle, bool active_state, void* user_data);
#define CB_PARAMS_NAMES cbhm_handle, active_state, user_data
PROXY_GROUP_NON_BLOCKING(cbhm_monitor_cb, void* cbhm_handle, bool active_state, void* user_data)
PROXY_GROUP_BLOCKING(cbhm_monitor_cb, void* cbhm_handle, bool active_state, void* user_data)
#undef CB_PARAMS_NAMES

typedef int (*cbhm_selected_cb)(void* cbhm_handle, void* user_data);
#define CB_PARAMS_NAMES cbhm_handle, user_data
PROXY_GROUP_RETURN(cbhm_selected_cb, int, void* cbhm_handle, void* user_data)
#undef CB_PARAMS_NAMES

typedef int (*cbhm_selection_data_cb)(void* cbhm_handle, const char* buf, size_t len, void* user_data);
#define CB_PARAMS_NAMES cbhm_handle, buf, len, user_data
PROXY_GROUP_RETURN(cbhm_selection_data_cb, int, void* cbhm_handle, const char* buf, size_t len, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*connection_address_changed_cb)(const char* ipv4_address, const char* ipv6_address, void* user_data);
#define CB_PARAMS_NAMES ipv4_address, ipv6_address, user_data
PROXY_GROUP_NON_BLOCKING(connection_address_changed_cb, const char* ipv4_address, const char* ipv6_address, void* user_data)
PROXY_GROUP_BLOCKING(connection_address_changed_cb, const char* ipv4_address, const char* ipv6_address, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*connection_closed_cb)(some_enum result, void* user_data);
#define CB_PARAMS_NAMES result, user_data
PROXY_GROUP_NON_BLOCKING(connection_closed_cb, some_enum result, void* user_data)
PROXY_GROUP_BLOCKING(connection_closed_cb, some_enum result, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*connection_ethernet_cable_state_chaged_cb)(some_enum state, void* user_data);
#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(connection_ethernet_cable_state_chaged_cb, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(connection_ethernet_cable_state_chaged_cb, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*connection_ethernet_cable_state_changed_cb)(some_enum state, void* user_data);
#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(connection_ethernet_cable_state_changed_cb, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(connection_ethernet_cable_state_changed_cb, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*connection_internet_state_changed_cb)(some_enum state, void* user_data);
#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(connection_internet_state_changed_cb, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(connection_internet_state_changed_cb, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*connection_ipv6_address_cb)(char* ipv6_address, void* user_data);
#define CB_PARAMS_NAMES ipv6_address, user_data
PROXY_GROUP_RETURN(connection_ipv6_address_cb, bool, char* ipv6_address, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*connection_opened_cb)(some_enum result, void* user_data);
#define CB_PARAMS_NAMES result, user_data
PROXY_GROUP_NON_BLOCKING(connection_opened_cb, some_enum result, void* user_data)
PROXY_GROUP_BLOCKING(connection_opened_cb, some_enum result, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*connection_reset_cb)(some_enum result, void* user_data);
#define CB_PARAMS_NAMES result, user_data
PROXY_GROUP_NON_BLOCKING(connection_reset_cb, some_enum result, void* user_data)
PROXY_GROUP_BLOCKING(connection_reset_cb, some_enum result, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*connection_set_default_cb)(some_enum result, void* user_data);
#define CB_PARAMS_NAMES result, user_data
PROXY_GROUP_NON_BLOCKING(connection_set_default_cb, some_enum result, void* user_data)
PROXY_GROUP_BLOCKING(connection_set_default_cb, some_enum result, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*connection_state_changed_cb)(some_enum state, void* user_data);
#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(connection_state_changed_cb, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(connection_state_changed_cb, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*connection_type_changed_cb)(some_enum type, void* user_data);
#define CB_PARAMS_NAMES type, user_data
PROXY_GROUP_NON_BLOCKING(connection_type_changed_cb, some_enum type, void* user_data)
PROXY_GROUP_BLOCKING(connection_type_changed_cb, some_enum type, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*csr_cs_cancelled_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(csr_cs_cancelled_cb, void* user_data)
PROXY_GROUP_BLOCKING(csr_cs_cancelled_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*csr_cs_completed_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(csr_cs_completed_cb, void* user_data)
PROXY_GROUP_BLOCKING(csr_cs_completed_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*csr_cs_detected_cb)(void* malware, void* user_data);
#define CB_PARAMS_NAMES malware, user_data
PROXY_GROUP_NON_BLOCKING(csr_cs_detected_cb, void* malware, void* user_data)
PROXY_GROUP_BLOCKING(csr_cs_detected_cb, void* malware, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*csr_cs_error_cb)(int error_code, void* user_data);
#define CB_PARAMS_NAMES error_code, user_data
PROXY_GROUP_NON_BLOCKING(csr_cs_error_cb, int error_code, void* user_data)
PROXY_GROUP_BLOCKING(csr_cs_error_cb, int error_code, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*csr_cs_file_scanned_cb)(const char* file_path, void* user_data);
#define CB_PARAMS_NAMES file_path, user_data
PROXY_GROUP_NON_BLOCKING(csr_cs_file_scanned_cb, const char* file_path, void* user_data)
PROXY_GROUP_BLOCKING(csr_cs_file_scanned_cb, const char* file_path, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*device_changed_cb)(some_enum type, void* value, void* user_data);
#define CB_PARAMS_NAMES type, value, user_data
PROXY_GROUP_NON_BLOCKING(device_changed_cb, some_enum type, void* value, void* user_data)
PROXY_GROUP_BLOCKING(device_changed_cb, some_enum type, void* value, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*diagnostics_notification_cb)(void* ctx, void* user_data);
#define CB_PARAMS_NAMES ctx, user_data
PROXY_GROUP_NON_BLOCKING(diagnostics_notification_cb, void* ctx, void* user_data)
PROXY_GROUP_BLOCKING(diagnostics_notification_cb, void* ctx, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*diagnostics_request_cb)(void* data, char** params, int params_size, void* ctx, void* user_data);
#define CB_PARAMS_NAMES data, params, params_size, ctx, user_data
PROXY_GROUP_NON_BLOCKING(diagnostics_request_cb, void* data, char** params, int params_size, void* ctx, void* user_data)
PROXY_GROUP_BLOCKING(diagnostics_request_cb, void* data, char** params, int params_size, void* ctx, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*dnssd_found_cb)(some_enum service_state, unsigned int remote_service, void* user_data);
#define CB_PARAMS_NAMES service_state, remote_service, user_data
PROXY_GROUP_NON_BLOCKING(dnssd_found_cb, some_enum service_state, unsigned int remote_service, void* user_data)
PROXY_GROUP_BLOCKING(dnssd_found_cb, some_enum service_state, unsigned int remote_service, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*dnssd_registered_cb)(some_enum result, unsigned int local_service, void* user_data);
#define CB_PARAMS_NAMES result, local_service, user_data
PROXY_GROUP_NON_BLOCKING(dnssd_registered_cb, some_enum result, unsigned int local_service, void* user_data)
PROXY_GROUP_BLOCKING(dnssd_registered_cb, some_enum result, unsigned int local_service, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*dnssd_resolved_cb)(some_enum result, unsigned int remote_service, void* user_data);
#define CB_PARAMS_NAMES result, remote_service, user_data
PROXY_GROUP_NON_BLOCKING(dnssd_resolved_cb, some_enum result, unsigned int remote_service, void* user_data)
PROXY_GROUP_BLOCKING(dnssd_resolved_cb, some_enum result, unsigned int remote_service, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*download_progress_cb)(int download_id, unsigned long long received, void* user_data);
#define CB_PARAMS_NAMES download_id, received, user_data
PROXY_GROUP_NON_BLOCKING(download_progress_cb, int download_id, unsigned long long received, void* user_data)
PROXY_GROUP_BLOCKING(download_progress_cb, int download_id, unsigned long long received, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*download_state_changed_cb)(int download_id, some_enum state, void* user_data);
#define CB_PARAMS_NAMES download_id, state, user_data
PROXY_GROUP_NON_BLOCKING(download_state_changed_cb, int download_id, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(download_state_changed_cb, int download_id, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*dpm_policy_changed_cb)(const char* name, const char* state, void* user_data);
#define CB_PARAMS_NAMES name, state, user_data
PROXY_GROUP_NON_BLOCKING(dpm_policy_changed_cb, const char* name, const char* state, void* user_data)
PROXY_GROUP_BLOCKING(dpm_policy_changed_cb, const char* name, const char* state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*dpm_signal_cb)(const char* name, const char* object, void* user_data);
#define CB_PARAMS_NAMES name, object, user_data
PROXY_GROUP_NON_BLOCKING(dpm_signal_cb, const char* name, const char* object, void* user_data)
PROXY_GROUP_BLOCKING(dpm_signal_cb, const char* name, const char* object, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*dpm_zone_foreach_name_cb)(const char* name, void* user_data);
#define CB_PARAMS_NAMES name, user_data
PROXY_GROUP_RETURN(dpm_zone_foreach_name_cb, bool, const char* name, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*email_message_sent_cb)(void* email, some_enum result, void* user_data);
#define CB_PARAMS_NAMES email, result, user_data
PROXY_GROUP_NON_BLOCKING(email_message_sent_cb, void* email, some_enum result, void* user_data)
PROXY_GROUP_BLOCKING(email_message_sent_cb, void* email, some_enum result, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*eom_attribute_changed_cb)(unsigned int output_id, void* user_data);
#define CB_PARAMS_NAMES output_id, user_data
PROXY_GROUP_NON_BLOCKING(eom_attribute_changed_cb, unsigned int output_id, void* user_data)
PROXY_GROUP_BLOCKING(eom_attribute_changed_cb, unsigned int output_id, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*eom_mode_changed_cb)(unsigned int output_id, void* user_data);
#define CB_PARAMS_NAMES output_id, user_data
PROXY_GROUP_NON_BLOCKING(eom_mode_changed_cb, unsigned int output_id, void* user_data)
PROXY_GROUP_BLOCKING(eom_mode_changed_cb, unsigned int output_id, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*eom_output_added_cb)(unsigned int output_id, void* user_data);
#define CB_PARAMS_NAMES output_id, user_data
PROXY_GROUP_NON_BLOCKING(eom_output_added_cb, unsigned int output_id, void* user_data)
PROXY_GROUP_BLOCKING(eom_output_added_cb, unsigned int output_id, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*eom_output_removed_cb)(unsigned int output_id, void* user_data);
#define CB_PARAMS_NAMES output_id, user_data
PROXY_GROUP_NON_BLOCKING(eom_output_removed_cb, unsigned int output_id, void* user_data)
PROXY_GROUP_BLOCKING(eom_output_removed_cb, unsigned int output_id, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*event_cb)(const char* event_name, void* event_data, void* user_data);
#define CB_PARAMS_NAMES event_name, event_data, user_data
PROXY_GROUP_NON_BLOCKING(event_cb, const char* event_name, void* event_data, void* user_data)
PROXY_GROUP_BLOCKING(event_cb, const char* event_name, void* event_data, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*fido_attestation_type_cb)(some_enum att_type, void* user_data);
#define CB_PARAMS_NAMES att_type, user_data
PROXY_GROUP_NON_BLOCKING(fido_attestation_type_cb, some_enum att_type, void* user_data)
PROXY_GROUP_BLOCKING(fido_attestation_type_cb, some_enum att_type, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*fido_authenticator_cb)(const void* auth_info, void* user_data);
#define CB_PARAMS_NAMES auth_info, user_data
PROXY_GROUP_NON_BLOCKING(fido_authenticator_cb, const void* auth_info, void* user_data)
PROXY_GROUP_BLOCKING(fido_authenticator_cb, const void* auth_info, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*fido_uaf_response_message_cb)(some_enum tizen_error_code, const char* uaf_response_json, void* user_data);
#define CB_PARAMS_NAMES tizen_error_code, uaf_response_json, user_data
PROXY_GROUP_NON_BLOCKING(fido_uaf_response_message_cb, some_enum tizen_error_code, const char* uaf_response_json, void* user_data)
PROXY_GROUP_BLOCKING(fido_uaf_response_message_cb, some_enum tizen_error_code, const char* uaf_response_json, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*geofence_event_cb)(int place_id, int geofence_id, some_enum error, some_enum manage, void* user_data);
#define CB_PARAMS_NAMES place_id, geofence_id, error, manage, user_data
PROXY_GROUP_NON_BLOCKING(geofence_event_cb, int place_id, int geofence_id, some_enum error, some_enum manage, void* user_data)
PROXY_GROUP_BLOCKING(geofence_event_cb, int place_id, int geofence_id, some_enum error, some_enum manage, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*geofence_manager_fence_cb)(int geofence_id, void* fence, int fence_index, int fence_cnt, void* user_data);
#define CB_PARAMS_NAMES geofence_id, fence, fence_index, fence_cnt, user_data
PROXY_GROUP_RETURN(geofence_manager_fence_cb, bool, int geofence_id, void* fence, int fence_index, int fence_cnt, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*geofence_manager_place_cb)(int place_id, const char* place_name, int place_index, int place_cnt, void* user_data);
#define CB_PARAMS_NAMES place_id, place_name, place_index, place_cnt, user_data
PROXY_GROUP_RETURN(geofence_manager_place_cb, bool, int place_id, const char* place_name, int place_index, int place_cnt, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*geofence_proximity_state_changed_cb)(int geofence_id, some_enum state, some_enum provider, void* user_data);
#define CB_PARAMS_NAMES geofence_id, state, provider, user_data
PROXY_GROUP_NON_BLOCKING(geofence_proximity_state_changed_cb, int geofence_id, some_enum state, some_enum provider, void* user_data)
PROXY_GROUP_BLOCKING(geofence_proximity_state_changed_cb, int geofence_id, some_enum state, some_enum provider, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*geofence_state_changed_cb)(int geofence_id, some_enum state, void* user_data);
#define CB_PARAMS_NAMES geofence_id, state, user_data
PROXY_GROUP_NON_BLOCKING(geofence_state_changed_cb, int geofence_id, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(geofence_state_changed_cb, int geofence_id, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*gesture_recognition_cb)(some_enum gesture, const void* data, double timestamp, some_enum error, void* user_data);
#define CB_PARAMS_NAMES gesture, data, timestamp, error, user_data
PROXY_GROUP_NON_BLOCKING(gesture_recognition_cb, some_enum gesture, const void* data, double timestamp, some_enum error, void* user_data)
PROXY_GROUP_BLOCKING(gesture_recognition_cb, some_enum gesture, const void* data, double timestamp, some_enum error, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*gps_status_get_satellites_cb)(unsigned int azimuth, unsigned int elevation, unsigned int prn, int snr, bool is_active, void* user_data);
#define CB_PARAMS_NAMES azimuth, elevation, prn, snr, is_active, user_data
PROXY_GROUP_RETURN(gps_status_get_satellites_cb, bool, unsigned int azimuth, unsigned int elevation, unsigned int prn, int snr, bool is_active, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*gps_status_satellite_updated_cb)(int num_of_active, int num_of_inview, time_t timestamp, void* user_data);
#define CB_PARAMS_NAMES num_of_active, num_of_inview, timestamp, user_data
PROXY_GROUP_NON_BLOCKING(gps_status_satellite_updated_cb, int num_of_active, int num_of_inview, time_t timestamp, void* user_data)
PROXY_GROUP_BLOCKING(gps_status_satellite_updated_cb, int num_of_active, int num_of_inview, time_t timestamp, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*http_transaction_aborted_cb)(void* http_transaction, some_enum error, void* user_data);
#define CB_PARAMS_NAMES http_transaction, error, user_data
PROXY_GROUP_NON_BLOCKING(http_transaction_aborted_cb, void* http_transaction, some_enum error, void* user_data)
PROXY_GROUP_BLOCKING(http_transaction_aborted_cb, void* http_transaction, some_enum error, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*http_transaction_body_cb)(void* http_transaction, char* body, size_t size, size_t count, void* user_data);
#define CB_PARAMS_NAMES http_transaction, body, size, count, user_data
PROXY_GROUP_NON_BLOCKING(http_transaction_body_cb, void* http_transaction, char* body, size_t size, size_t count, void* user_data)
PROXY_GROUP_BLOCKING(http_transaction_body_cb, void* http_transaction, char* body, size_t size, size_t count, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*http_transaction_completed_cb)(void* http_transaction, void* user_data);
#define CB_PARAMS_NAMES http_transaction, user_data
PROXY_GROUP_NON_BLOCKING(http_transaction_completed_cb, void* http_transaction, void* user_data)
PROXY_GROUP_BLOCKING(http_transaction_completed_cb, void* http_transaction, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*http_transaction_header_cb)(void* http_transaction, char* header, size_t header_len, void* user_data);
#define CB_PARAMS_NAMES http_transaction, header, header_len, user_data
PROXY_GROUP_NON_BLOCKING(http_transaction_header_cb, void* http_transaction, char* header, size_t header_len, void* user_data)
PROXY_GROUP_BLOCKING(http_transaction_header_cb, void* http_transaction, char* header, size_t header_len, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*http_transaction_progress_cb)(void* http_transaction, double download_total, double download_now, double upload_total, double upload_now, void* user_data);
#define CB_PARAMS_NAMES http_transaction, download_total, download_now, upload_total, upload_now, user_data
PROXY_GROUP_NON_BLOCKING(http_transaction_progress_cb, void* http_transaction, double download_total, double download_now, double upload_total, double upload_now, void* user_data)
PROXY_GROUP_BLOCKING(http_transaction_progress_cb, void* http_transaction, double download_total, double download_now, double upload_total, double upload_now, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*http_transaction_write_cb)(void* http_transaction, int recommended_chunk_size, void* user_data);
#define CB_PARAMS_NAMES http_transaction, recommended_chunk_size, user_data
PROXY_GROUP_NON_BLOCKING(http_transaction_write_cb, void* http_transaction, int recommended_chunk_size, void* user_data)
PROXY_GROUP_BLOCKING(http_transaction_write_cb, void* http_transaction, int recommended_chunk_size, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*image_util_supported_colorspace_cb)(some_enum colorspace, void* user_data);
#define CB_PARAMS_NAMES colorspace, user_data
PROXY_GROUP_RETURN(image_util_supported_colorspace_cb, bool, some_enum colorspace, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_accessibility_state_changed_cb)(bool state, void* user_data);
#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(ime_accessibility_state_changed_cb, bool state, void* user_data)
PROXY_GROUP_BLOCKING(ime_accessibility_state_changed_cb, bool state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_create_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(ime_create_cb, void* user_data)
PROXY_GROUP_BLOCKING(ime_create_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_cursor_position_updated_cb)(int cursor_pos, void* user_data);
#define CB_PARAMS_NAMES cursor_pos, user_data
PROXY_GROUP_NON_BLOCKING(ime_cursor_position_updated_cb, int cursor_pos, void* user_data)
PROXY_GROUP_BLOCKING(ime_cursor_position_updated_cb, int cursor_pos, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_display_language_changed_cb)(const char* language, void* user_data);
#define CB_PARAMS_NAMES language, user_data
PROXY_GROUP_NON_BLOCKING(ime_display_language_changed_cb, const char* language, void* user_data)
PROXY_GROUP_BLOCKING(ime_display_language_changed_cb, const char* language, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_focus_in_cb)(int context_id, void* user_data);
#define CB_PARAMS_NAMES context_id, user_data
PROXY_GROUP_NON_BLOCKING(ime_focus_in_cb, int context_id, void* user_data)
PROXY_GROUP_BLOCKING(ime_focus_in_cb, int context_id, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_focus_out_cb)(int context_id, void* user_data);
#define CB_PARAMS_NAMES context_id, user_data
PROXY_GROUP_NON_BLOCKING(ime_focus_out_cb, int context_id, void* user_data)
PROXY_GROUP_BLOCKING(ime_focus_out_cb, int context_id, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_geometry_requested_cb)(void* user_data, int* x, int* y, int* w, int* h);
#define CB_PARAMS_NAMES user_data, x, y, w, h
PROXY_GROUP_NON_BLOCKING(ime_geometry_requested_cb, void* user_data, int* x, int* y, int* w, int* h)
PROXY_GROUP_BLOCKING(ime_geometry_requested_cb, void* user_data, int* x, int* y, int* w, int* h)
#undef CB_PARAMS_NAMES

typedef void (*ime_hide_cb)(int context_id, void* user_data);
#define CB_PARAMS_NAMES context_id, user_data
PROXY_GROUP_NON_BLOCKING(ime_hide_cb, int context_id, void* user_data)
PROXY_GROUP_BLOCKING(ime_hide_cb, int context_id, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_imdata_requested_cb)(void* user_data, void** data, unsigned int* data_length);
#define CB_PARAMS_NAMES user_data, data, data_length
PROXY_GROUP_NON_BLOCKING(ime_imdata_requested_cb, void* user_data, void** data, unsigned int* data_length)
PROXY_GROUP_BLOCKING(ime_imdata_requested_cb, void* user_data, void** data, unsigned int* data_length)
#undef CB_PARAMS_NAMES

typedef void (*ime_imdata_set_cb)(void* data, unsigned int data_length, void* user_data);
#define CB_PARAMS_NAMES data, data_length, user_data
PROXY_GROUP_NON_BLOCKING(ime_imdata_set_cb, void* data, unsigned int data_length, void* user_data)
PROXY_GROUP_BLOCKING(ime_imdata_set_cb, void* data, unsigned int data_length, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_input_context_reset_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(ime_input_context_reset_cb, void* user_data)
PROXY_GROUP_BLOCKING(ime_input_context_reset_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_input_hint_set_cb)(some_enum input_hint, void* user_data);
#define CB_PARAMS_NAMES input_hint, user_data
PROXY_GROUP_NON_BLOCKING(ime_input_hint_set_cb, some_enum input_hint, void* user_data)
PROXY_GROUP_BLOCKING(ime_input_hint_set_cb, some_enum input_hint, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_language_requested_cb)(void* user_data, char** lang_code);
#define CB_PARAMS_NAMES user_data, lang_code
PROXY_GROUP_NON_BLOCKING(ime_language_requested_cb, void* user_data, char** lang_code)
PROXY_GROUP_BLOCKING(ime_language_requested_cb, void* user_data, char** lang_code)
#undef CB_PARAMS_NAMES

typedef void (*ime_language_set_cb)(some_enum language, void* user_data);
#define CB_PARAMS_NAMES language, user_data
PROXY_GROUP_NON_BLOCKING(ime_language_set_cb, some_enum language, void* user_data)
PROXY_GROUP_BLOCKING(ime_language_set_cb, some_enum language, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_layout_set_cb)(some_enum layout, void* user_data);
#define CB_PARAMS_NAMES layout, user_data
PROXY_GROUP_NON_BLOCKING(ime_layout_set_cb, some_enum layout, void* user_data)
PROXY_GROUP_BLOCKING(ime_layout_set_cb, some_enum layout, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_mime_type_set_request_cb)(const char* mime_type, void* user_data);
#define CB_PARAMS_NAMES mime_type, user_data
PROXY_GROUP_NON_BLOCKING(ime_mime_type_set_request_cb, const char* mime_type, void* user_data)
PROXY_GROUP_BLOCKING(ime_mime_type_set_request_cb, const char* mime_type, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_option_window_created_cb)(void* window, some_enum type, void* user_data);
#define CB_PARAMS_NAMES window, type, user_data
PROXY_GROUP_NON_BLOCKING(ime_option_window_created_cb, void* window, some_enum type, void* user_data)
PROXY_GROUP_BLOCKING(ime_option_window_created_cb, void* window, some_enum type, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_option_window_destroyed_cb)(void* window, void* user_data);
#define CB_PARAMS_NAMES window, user_data
PROXY_GROUP_NON_BLOCKING(ime_option_window_destroyed_cb, void* window, void* user_data)
PROXY_GROUP_BLOCKING(ime_option_window_destroyed_cb, void* window, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_prediction_hint_data_set_cb)(const char* key, const char* value, void* user_data);
#define CB_PARAMS_NAMES key, value, user_data
PROXY_GROUP_NON_BLOCKING(ime_prediction_hint_data_set_cb, const char* key, const char* value, void* user_data)
PROXY_GROUP_BLOCKING(ime_prediction_hint_data_set_cb, const char* key, const char* value, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_prediction_hint_set_cb)(const char* prediction_hint, void* user_data);
#define CB_PARAMS_NAMES prediction_hint, user_data
PROXY_GROUP_NON_BLOCKING(ime_prediction_hint_set_cb, const char* prediction_hint, void* user_data)
PROXY_GROUP_BLOCKING(ime_prediction_hint_set_cb, const char* prediction_hint, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*ime_process_key_event_cb)(some_enum key_code, some_enum key_mask, void* dev_info, void* user_data);
#define CB_PARAMS_NAMES key_code, key_mask, dev_info, user_data
PROXY_GROUP_RETURN(ime_process_key_event_cb, bool, some_enum key_code, some_enum key_mask, void* dev_info, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*ime_process_key_event_with_keycode_cb)(unsigned int key_code, some_enum key_sym, some_enum key_mask, void* dev_info, void* user_data);
#define CB_PARAMS_NAMES key_code, key_sym, key_mask, dev_info, user_data
PROXY_GROUP_RETURN(ime_process_key_event_with_keycode_cb, bool, unsigned int key_code, some_enum key_sym, some_enum key_mask, void* dev_info, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_return_key_state_set_cb)(bool disabled, void* user_data);
#define CB_PARAMS_NAMES disabled, user_data
PROXY_GROUP_NON_BLOCKING(ime_return_key_state_set_cb, bool disabled, void* user_data)
PROXY_GROUP_BLOCKING(ime_return_key_state_set_cb, bool disabled, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_return_key_type_set_cb)(some_enum type, void* user_data);
#define CB_PARAMS_NAMES type, user_data
PROXY_GROUP_NON_BLOCKING(ime_return_key_type_set_cb, some_enum type, void* user_data)
PROXY_GROUP_BLOCKING(ime_return_key_type_set_cb, some_enum type, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_rotation_degree_changed_cb)(int degree, void* user_data);
#define CB_PARAMS_NAMES degree, user_data
PROXY_GROUP_NON_BLOCKING(ime_rotation_degree_changed_cb, int degree, void* user_data)
PROXY_GROUP_BLOCKING(ime_rotation_degree_changed_cb, int degree, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_show_cb)(int context_id, void* context, void* user_data);
#define CB_PARAMS_NAMES context_id, context, user_data
PROXY_GROUP_NON_BLOCKING(ime_show_cb, int context_id, void* context, void* user_data)
PROXY_GROUP_BLOCKING(ime_show_cb, int context_id, void* context, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_surrounding_text_updated_cb)(int context_id, const char* text, int cursor_pos, void* user_data);
#define CB_PARAMS_NAMES context_id, text, cursor_pos, user_data
PROXY_GROUP_NON_BLOCKING(ime_surrounding_text_updated_cb, int context_id, const char* text, int cursor_pos, void* user_data)
PROXY_GROUP_BLOCKING(ime_surrounding_text_updated_cb, int context_id, const char* text, int cursor_pos, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ime_terminate_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(ime_terminate_cb, void* user_data)
PROXY_GROUP_BLOCKING(ime_terminate_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*inm_arp_request_ip_found_cb)(bool found, const char* ip, void* user_data);
#define CB_PARAMS_NAMES found, ip, user_data
PROXY_GROUP_NON_BLOCKING(inm_arp_request_ip_found_cb, bool found, const char* ip, void* user_data)
PROXY_GROUP_BLOCKING(inm_arp_request_ip_found_cb, bool found, const char* ip, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*inm_cellular_state_changed_cb)(some_enum state, void* user_data);
#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(inm_cellular_state_changed_cb, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(inm_cellular_state_changed_cb, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*inm_channel_interference_cb)(int freq, double channel_intf, void* user_data);
#define CB_PARAMS_NAMES freq, channel_intf, user_data
PROXY_GROUP_NON_BLOCKING(inm_channel_interference_cb, int freq, double channel_intf, void* user_data)
PROXY_GROUP_BLOCKING(inm_channel_interference_cb, int freq, double channel_intf, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*inm_congestion_level_cb)(some_enum level, void* user_data);
#define CB_PARAMS_NAMES level, user_data
PROXY_GROUP_NON_BLOCKING(inm_congestion_level_cb, some_enum level, void* user_data)
PROXY_GROUP_BLOCKING(inm_congestion_level_cb, some_enum level, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*inm_default_dns_lookup_result_cb)(bool found, void* user_data);
#define CB_PARAMS_NAMES found, user_data
PROXY_GROUP_NON_BLOCKING(inm_default_dns_lookup_result_cb, bool found, void* user_data)
PROXY_GROUP_BLOCKING(inm_default_dns_lookup_result_cb, bool found, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*inm_default_gateway_found_cb)(bool found, const char* gateway_ip, void* user_data);
#define CB_PARAMS_NAMES found, gateway_ip, user_data
PROXY_GROUP_NON_BLOCKING(inm_default_gateway_found_cb, bool found, const char* gateway_ip, void* user_data)
PROXY_GROUP_BLOCKING(inm_default_gateway_found_cb, bool found, const char* gateway_ip, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*inm_ethernet_cable_state_changed_cb)(some_enum state, void* user_data);
#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(inm_ethernet_cable_state_changed_cb, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(inm_ethernet_cable_state_changed_cb, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*inm_ethernet_state_changed_cb)(some_enum state, void* user_data);
#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(inm_ethernet_state_changed_cb, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(inm_ethernet_state_changed_cb, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*inm_ip_conflict_cb)(char* if_name, char* ip, some_enum state, void* user_data);
#define CB_PARAMS_NAMES if_name, ip, state, user_data
PROXY_GROUP_NON_BLOCKING(inm_ip_conflict_cb, char* if_name, char* ip, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(inm_ip_conflict_cb, char* if_name, char* ip, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*inm_link_address_cb)(void* address, void* user_data);
#define CB_PARAMS_NAMES address, user_data
PROXY_GROUP_RETURN(inm_link_address_cb, bool, void* address, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*inm_link_cb)(void* link, void* user_data);
#define CB_PARAMS_NAMES link, user_data
PROXY_GROUP_RETURN(inm_link_cb, bool, void* link, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*inm_link_route_cb)(void* route, void* user_data);
#define CB_PARAMS_NAMES route, user_data
PROXY_GROUP_RETURN(inm_link_route_cb, bool, void* route, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*inm_reachable_urls_check_result_cb)(some_enum result, const char* url, void* user_data);
#define CB_PARAMS_NAMES result, url, user_data
PROXY_GROUP_NON_BLOCKING(inm_reachable_urls_check_result_cb, some_enum result, const char* url, void* user_data)
PROXY_GROUP_BLOCKING(inm_reachable_urls_check_result_cb, some_enum result, const char* url, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*inm_retry_tx_rate_cb)(int rate, void* user_data);
#define CB_PARAMS_NAMES rate, user_data
PROXY_GROUP_NON_BLOCKING(inm_retry_tx_rate_cb, int rate, void* user_data)
PROXY_GROUP_BLOCKING(inm_retry_tx_rate_cb, int rate, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*inm_wifi_ap_vsie_cb)(unsigned char* vsie, int length, void* user_data);
#define CB_PARAMS_NAMES vsie, length, user_data
PROXY_GROUP_RETURN(inm_wifi_ap_vsie_cb, bool, unsigned char* vsie, int length, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*inm_wifi_found_ap_cb)(void* ap, void* user_data);
#define CB_PARAMS_NAMES ap, user_data
PROXY_GROUP_RETURN(inm_wifi_found_ap_cb, bool, void* ap, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*inm_wifi_module_state_changed_cb)(some_enum state, void* user_data);
#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(inm_wifi_module_state_changed_cb, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(inm_wifi_module_state_changed_cb, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*inm_wifi_scan_state_changed_cb)(some_enum state, void* user_data);
#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(inm_wifi_scan_state_changed_cb, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(inm_wifi_scan_state_changed_cb, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*inm_wifi_state_changed_cb)(some_enum state, void* user_data);
#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(inm_wifi_state_changed_cb, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(inm_wifi_state_changed_cb, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*iotcon_generated_pin_cb)(const char* pin, void* user_data);
#define CB_PARAMS_NAMES pin, user_data
PROXY_GROUP_NON_BLOCKING(iotcon_generated_pin_cb, const char* pin, void* user_data)
PROXY_GROUP_BLOCKING(iotcon_generated_pin_cb, const char* pin, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*job_scheduler_foreach_job_cb)(void* job_info, void* user_data);
#define CB_PARAMS_NAMES job_info, user_data
PROXY_GROUP_RETURN(job_scheduler_foreach_job_cb, bool, void* job_info, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*job_service_start_cb)(void* job_info, void* user_data);
#define CB_PARAMS_NAMES job_info, user_data
PROXY_GROUP_NON_BLOCKING(job_service_start_cb, void* job_info, void* user_data)
PROXY_GROUP_BLOCKING(job_service_start_cb, void* job_info, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*job_service_stop_cb)(void* job_info, void* user_data);
#define CB_PARAMS_NAMES job_info, user_data
PROXY_GROUP_NON_BLOCKING(job_service_stop_cb, void* job_info, void* user_data)
PROXY_GROUP_BLOCKING(job_service_stop_cb, void* job_info, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*location_batch_cb)(int num_of_location, void* user_data);
#define CB_PARAMS_NAMES num_of_location, user_data
PROXY_GROUP_NON_BLOCKING(location_batch_cb, int num_of_location, void* user_data)
PROXY_GROUP_BLOCKING(location_batch_cb, int num_of_location, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*location_batch_get_location_cb)(double latitude, double longitude, double altitude, double speed, double direction, double horizontal, double vertical, time_t timestamp, void* user_data);
#define CB_PARAMS_NAMES latitude, longitude, altitude, speed, direction, horizontal, vertical, timestamp, user_data
PROXY_GROUP_RETURN(location_batch_get_location_cb, bool, double latitude, double longitude, double altitude, double speed, double direction, double horizontal, double vertical, time_t timestamp, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*location_bounds_cb)(void* bounds, void* user_data);
#define CB_PARAMS_NAMES bounds, user_data
PROXY_GROUP_RETURN(location_bounds_cb, bool, void* bounds, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*location_changed_cb)(double latitude, double longitude, double altitude, double speed, double direction, double horizontal_accuracy, time_t timestamp, void* user_data);
#define CB_PARAMS_NAMES latitude, longitude, altitude, speed, direction, horizontal_accuracy, timestamp, user_data
PROXY_GROUP_NON_BLOCKING(location_changed_cb, double latitude, double longitude, double altitude, double speed, double direction, double horizontal_accuracy, time_t timestamp, void* user_data)
PROXY_GROUP_BLOCKING(location_changed_cb, double latitude, double longitude, double altitude, double speed, double direction, double horizontal_accuracy, time_t timestamp, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*location_position_updated_cb)(double latitude, double longitude, double altitude, time_t timestamp, void* user_data);
#define CB_PARAMS_NAMES latitude, longitude, altitude, timestamp, user_data
PROXY_GROUP_NON_BLOCKING(location_position_updated_cb, double latitude, double longitude, double altitude, time_t timestamp, void* user_data)
PROXY_GROUP_BLOCKING(location_position_updated_cb, double latitude, double longitude, double altitude, time_t timestamp, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*location_service_state_changed_cb)(some_enum state, void* user_data);
#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(location_service_state_changed_cb, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(location_service_state_changed_cb, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*location_setting_changed_cb)(some_enum method, bool enable, void* user_data);
#define CB_PARAMS_NAMES method, enable, user_data
PROXY_GROUP_NON_BLOCKING(location_setting_changed_cb, some_enum method, bool enable, void* user_data)
PROXY_GROUP_BLOCKING(location_setting_changed_cb, some_enum method, bool enable, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*location_updated_cb)(some_enum error, double latitude, double longitude, double altitude, time_t timestamp, double speed, double direction, double climb, void* user_data);
#define CB_PARAMS_NAMES error, latitude, longitude, altitude, timestamp, speed, direction, climb, user_data
PROXY_GROUP_NON_BLOCKING(location_updated_cb, some_enum error, double latitude, double longitude, double altitude, time_t timestamp, double speed, double direction, double climb, void* user_data)
PROXY_GROUP_BLOCKING(location_updated_cb, some_enum error, double latitude, double longitude, double altitude, time_t timestamp, double speed, double direction, double climb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*location_velocity_updated_cb)(double speed, double direction, double climb, time_t timestamp, void* user_data);
#define CB_PARAMS_NAMES speed, direction, climb, timestamp, user_data
PROXY_GROUP_NON_BLOCKING(location_velocity_updated_cb, double speed, double direction, double climb, time_t timestamp, void* user_data)
PROXY_GROUP_BLOCKING(location_velocity_updated_cb, double speed, double direction, double climb, time_t timestamp, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*location_zone_changed_cb)(some_enum state, double latitude, double longitude, double altitude, time_t timestamp, void* user_data);
#define CB_PARAMS_NAMES state, latitude, longitude, altitude, timestamp, user_data
PROXY_GROUP_NON_BLOCKING(location_zone_changed_cb, some_enum state, double latitude, double longitude, double altitude, time_t timestamp, void* user_data)
PROXY_GROUP_BLOCKING(location_zone_changed_cb, some_enum state, double latitude, double longitude, double altitude, time_t timestamp, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ma_active_state_changed_cb)(some_enum previous, some_enum current, void* user_data);
#define CB_PARAMS_NAMES previous, current, user_data
PROXY_GROUP_NON_BLOCKING(ma_active_state_changed_cb, some_enum previous, some_enum current, void* user_data)
PROXY_GROUP_BLOCKING(ma_active_state_changed_cb, some_enum previous, some_enum current, void* user_data)
#undef CB_PARAMS_NAMES

typedef int (*ma_assistant_info_list_cb)(void* handle, void* user_data);
#define CB_PARAMS_NAMES handle, user_data
PROXY_GROUP_RETURN(ma_assistant_info_list_cb, int, void* handle, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ma_audio_streaming_cb)(some_enum event, char* buffer, int len, void* user_data);
#define CB_PARAMS_NAMES event, buffer, len, user_data
PROXY_GROUP_NON_BLOCKING(ma_audio_streaming_cb, some_enum event, char* buffer, int len, void* user_data)
PROXY_GROUP_BLOCKING(ma_audio_streaming_cb, some_enum event, char* buffer, int len, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ma_audio_streaming_data_section_changed_cb)(some_enum section, void* user_data);
#define CB_PARAMS_NAMES section, user_data
PROXY_GROUP_NON_BLOCKING(ma_audio_streaming_data_section_changed_cb, some_enum section, void* user_data)
PROXY_GROUP_BLOCKING(ma_audio_streaming_data_section_changed_cb, some_enum section, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ma_error_cb)(some_enum reason, void* user_data);
#define CB_PARAMS_NAMES reason, user_data
PROXY_GROUP_NON_BLOCKING(ma_error_cb, some_enum reason, void* user_data)
PROXY_GROUP_BLOCKING(ma_error_cb, some_enum reason, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ma_language_changed_cb)(const char* previous, const char* current, void* user_data);
#define CB_PARAMS_NAMES previous, current, user_data
PROXY_GROUP_NON_BLOCKING(ma_language_changed_cb, const char* previous, const char* current, void* user_data)
PROXY_GROUP_BLOCKING(ma_language_changed_cb, const char* previous, const char* current, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ma_preprocessing_information_changed_cb)(const char* app_id, void* user_data);
#define CB_PARAMS_NAMES app_id, user_data
PROXY_GROUP_NON_BLOCKING(ma_preprocessing_information_changed_cb, const char* app_id, void* user_data)
PROXY_GROUP_BLOCKING(ma_preprocessing_information_changed_cb, const char* app_id, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ma_service_state_changed_cb)(some_enum previous, some_enum current, void* user_data);
#define CB_PARAMS_NAMES previous, current, user_data
PROXY_GROUP_NON_BLOCKING(ma_service_state_changed_cb, some_enum previous, some_enum current, void* user_data)
PROXY_GROUP_BLOCKING(ma_service_state_changed_cb, some_enum previous, some_enum current, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ma_state_changed_cb)(some_enum previous, some_enum current, void* user_data);
#define CB_PARAMS_NAMES previous, current, user_data
PROXY_GROUP_NON_BLOCKING(ma_state_changed_cb, some_enum previous, some_enum current, void* user_data)
PROXY_GROUP_BLOCKING(ma_state_changed_cb, some_enum previous, some_enum current, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ma_voice_key_status_changed_cb)(some_enum status, void* user_data);
#define CB_PARAMS_NAMES status, user_data
PROXY_GROUP_NON_BLOCKING(ma_voice_key_status_changed_cb, some_enum status, void* user_data)
PROXY_GROUP_BLOCKING(ma_voice_key_status_changed_cb, some_enum status, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ma_wakeup_engine_command_cb)(const char* command, void* user_data);
#define CB_PARAMS_NAMES command, user_data
PROXY_GROUP_NON_BLOCKING(ma_wakeup_engine_command_cb, const char* command, void* user_data)
PROXY_GROUP_BLOCKING(ma_wakeup_engine_command_cb, const char* command, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_ability_support_updated_cb)(const char* server_name, some_enum ability, some_enum support, void* user_data);
#define CB_PARAMS_NAMES server_name, ability, support, user_data
PROXY_GROUP_NON_BLOCKING(mc_ability_support_updated_cb, const char* server_name, some_enum ability, some_enum support, void* user_data)
PROXY_GROUP_BLOCKING(mc_ability_support_updated_cb, const char* server_name, some_enum ability, some_enum support, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_ability_supported_items_updated_cb)(const char* server_name, unsigned int supported_items, void* user_data);
#define CB_PARAMS_NAMES server_name, supported_items, user_data
PROXY_GROUP_NON_BLOCKING(mc_ability_supported_items_updated_cb, const char* server_name, unsigned int supported_items, void* user_data)
PROXY_GROUP_BLOCKING(mc_ability_supported_items_updated_cb, const char* server_name, unsigned int supported_items, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*mc_activated_client_cb)(const char* client_name, void* user_data);
#define CB_PARAMS_NAMES client_name, user_data
PROXY_GROUP_RETURN(mc_activated_client_cb, bool, const char* client_name, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*mc_activated_server_cb)(const char* server_name, void* user_data);
#define CB_PARAMS_NAMES server_name, user_data
PROXY_GROUP_RETURN(mc_activated_server_cb, bool, const char* server_name, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_bool_attribute_updated_cb)(const char* server_name, bool enabled, void* user_data);
#define CB_PARAMS_NAMES server_name, enabled, user_data
PROXY_GROUP_NON_BLOCKING(mc_bool_attribute_updated_cb, const char* server_name, bool enabled, void* user_data)
PROXY_GROUP_BLOCKING(mc_bool_attribute_updated_cb, const char* server_name, bool enabled, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_client_custom_event_received_cb)(const char* server_name, const char* request_id, const char* event, void* data, void* user_data);
#define CB_PARAMS_NAMES server_name, request_id, event, data, user_data
PROXY_GROUP_NON_BLOCKING(mc_client_custom_event_received_cb, const char* server_name, const char* request_id, const char* event, void* data, void* user_data)
PROXY_GROUP_BLOCKING(mc_client_custom_event_received_cb, const char* server_name, const char* request_id, const char* event, void* data, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_cmd_reply_received_cb)(const char* server_name, const char* request_id, int result_code, void* data, void* user_data);
#define CB_PARAMS_NAMES server_name, request_id, result_code, data, user_data
PROXY_GROUP_NON_BLOCKING(mc_cmd_reply_received_cb, const char* server_name, const char* request_id, int result_code, void* data, void* user_data)
PROXY_GROUP_BLOCKING(mc_cmd_reply_received_cb, const char* server_name, const char* request_id, int result_code, void* data, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_command_reply_received_cb)(const char* server_name, int result_code, void* data, void* user_data);
#define CB_PARAMS_NAMES server_name, result_code, data, user_data
PROXY_GROUP_NON_BLOCKING(mc_command_reply_received_cb, const char* server_name, int result_code, void* data, void* user_data)
PROXY_GROUP_BLOCKING(mc_command_reply_received_cb, const char* server_name, int result_code, void* data, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_display_mode_updated_cb)(const char* server_name, some_enum mode, void* user_data);
#define CB_PARAMS_NAMES server_name, mode, user_data
PROXY_GROUP_NON_BLOCKING(mc_display_mode_updated_cb, const char* server_name, some_enum mode, void* user_data)
PROXY_GROUP_BLOCKING(mc_display_mode_updated_cb, const char* server_name, some_enum mode, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_display_rotation_updated_cb)(const char* server_name, some_enum rotation, void* user_data);
#define CB_PARAMS_NAMES server_name, rotation, user_data
PROXY_GROUP_NON_BLOCKING(mc_display_rotation_updated_cb, const char* server_name, some_enum rotation, void* user_data)
PROXY_GROUP_BLOCKING(mc_display_rotation_updated_cb, const char* server_name, some_enum rotation, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_metadata_updated_cb)(const char* server_name, void* metadata, void* user_data);
#define CB_PARAMS_NAMES server_name, metadata, user_data
PROXY_GROUP_NON_BLOCKING(mc_metadata_updated_cb, const char* server_name, void* metadata, void* user_data)
PROXY_GROUP_BLOCKING(mc_metadata_updated_cb, const char* server_name, void* metadata, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_playback_ability_updated_cb)(const char* server_name, void* ability, void* user_data);
#define CB_PARAMS_NAMES server_name, ability, user_data
PROXY_GROUP_NON_BLOCKING(mc_playback_ability_updated_cb, const char* server_name, void* ability, void* user_data)
PROXY_GROUP_BLOCKING(mc_playback_ability_updated_cb, const char* server_name, void* ability, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_playback_updated_cb)(const char* server_name, void* playback, void* user_data);
#define CB_PARAMS_NAMES server_name, playback, user_data
PROXY_GROUP_NON_BLOCKING(mc_playback_updated_cb, const char* server_name, void* playback, void* user_data)
PROXY_GROUP_BLOCKING(mc_playback_updated_cb, const char* server_name, void* playback, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*mc_playlist_cb)(void* playlist, void* user_data);
#define CB_PARAMS_NAMES playlist, user_data
PROXY_GROUP_RETURN(mc_playlist_cb, bool, void* playlist, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*mc_playlist_item_cb)(const char* index, void* metadata, void* user_data);
#define CB_PARAMS_NAMES index, metadata, user_data
PROXY_GROUP_RETURN(mc_playlist_item_cb, bool, const char* index, void* metadata, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_playlist_updated_cb)(const char* server_name, some_enum mode, const char* playlist_name, void* playlist, void* user_data);
#define CB_PARAMS_NAMES server_name, mode, playlist_name, playlist, user_data
PROXY_GROUP_NON_BLOCKING(mc_playlist_updated_cb, const char* server_name, some_enum mode, const char* playlist_name, void* playlist, void* user_data)
PROXY_GROUP_BLOCKING(mc_playlist_updated_cb, const char* server_name, some_enum mode, const char* playlist_name, void* playlist, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_repeat_ability_updated_cb)(const char* server_name, some_enum support, void* user_data);
#define CB_PARAMS_NAMES server_name, support, user_data
PROXY_GROUP_NON_BLOCKING(mc_repeat_ability_updated_cb, const char* server_name, some_enum support, void* user_data)
PROXY_GROUP_BLOCKING(mc_repeat_ability_updated_cb, const char* server_name, some_enum support, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_repeat_mode_changed_cb)(const char* server_name, some_enum mode, void* user_data);
#define CB_PARAMS_NAMES server_name, mode, user_data
PROXY_GROUP_NON_BLOCKING(mc_repeat_mode_changed_cb, const char* server_name, some_enum mode, void* user_data)
PROXY_GROUP_BLOCKING(mc_repeat_mode_changed_cb, const char* server_name, some_enum mode, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_repeat_mode_updated_cb)(const char* server_name, some_enum mode, void* user_data);
#define CB_PARAMS_NAMES server_name, mode, user_data
PROXY_GROUP_NON_BLOCKING(mc_repeat_mode_updated_cb, const char* server_name, some_enum mode, void* user_data)
PROXY_GROUP_BLOCKING(mc_repeat_mode_updated_cb, const char* server_name, some_enum mode, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*mc_search_condition_cb)(some_enum content_type, some_enum category, const char* search_keyword, void* data, void* user_data);
#define CB_PARAMS_NAMES content_type, category, search_keyword, data, user_data
PROXY_GROUP_RETURN(mc_search_condition_cb, bool, some_enum content_type, some_enum category, const char* search_keyword, void* data, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_server_custom_cmd_received_cb)(const char* client_name, const char* request_id, const char* command, void* data, void* user_data);
#define CB_PARAMS_NAMES client_name, request_id, command, data, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_custom_cmd_received_cb, const char* client_name, const char* request_id, const char* command, void* data, void* user_data)
PROXY_GROUP_BLOCKING(mc_server_custom_cmd_received_cb, const char* client_name, const char* request_id, const char* command, void* data, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_server_custom_command_received_cb)(const char* client_name, const char* command, void* data, void* user_data);
#define CB_PARAMS_NAMES client_name, command, data, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_custom_command_received_cb, const char* client_name, const char* command, void* data, void* user_data)
PROXY_GROUP_BLOCKING(mc_server_custom_command_received_cb, const char* client_name, const char* command, void* data, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_server_display_mode_cmd_received_cb)(const char* client_name, const char* request_id, some_enum mode, void* user_data);
#define CB_PARAMS_NAMES client_name, request_id, mode, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_display_mode_cmd_received_cb, const char* client_name, const char* request_id, some_enum mode, void* user_data)
PROXY_GROUP_BLOCKING(mc_server_display_mode_cmd_received_cb, const char* client_name, const char* request_id, some_enum mode, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_server_display_rotation_cmd_received_cb)(const char* client_name, const char* request_id, some_enum rotation, void* user_data);
#define CB_PARAMS_NAMES client_name, request_id, rotation, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_display_rotation_cmd_received_cb, const char* client_name, const char* request_id, some_enum rotation, void* user_data)
PROXY_GROUP_BLOCKING(mc_server_display_rotation_cmd_received_cb, const char* client_name, const char* request_id, some_enum rotation, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_server_enable_cmd_received_cb)(const char* client_name, const char* request_id, bool enabled, void* user_data);
#define CB_PARAMS_NAMES client_name, request_id, enabled, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_enable_cmd_received_cb, const char* client_name, const char* request_id, bool enabled, void* user_data)
PROXY_GROUP_BLOCKING(mc_server_enable_cmd_received_cb, const char* client_name, const char* request_id, bool enabled, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_server_event_reply_received_cb)(const char* client_name, const char* request_id, int result_code, void* data, void* user_data);
#define CB_PARAMS_NAMES client_name, request_id, result_code, data, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_event_reply_received_cb, const char* client_name, const char* request_id, int result_code, void* data, void* user_data)
PROXY_GROUP_BLOCKING(mc_server_event_reply_received_cb, const char* client_name, const char* request_id, int result_code, void* data, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_server_playback_action_cmd_received_cb)(const char* client_name, const char* request_id, some_enum action, void* user_data);
#define CB_PARAMS_NAMES client_name, request_id, action, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_playback_action_cmd_received_cb, const char* client_name, const char* request_id, some_enum action, void* user_data)
PROXY_GROUP_BLOCKING(mc_server_playback_action_cmd_received_cb, const char* client_name, const char* request_id, some_enum action, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_server_playback_position_cmd_received_cb)(const char* client_name, const char* request_id, unsigned long long position, void* user_data);
#define CB_PARAMS_NAMES client_name, request_id, position, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_playback_position_cmd_received_cb, const char* client_name, const char* request_id, unsigned long long position, void* user_data)
PROXY_GROUP_BLOCKING(mc_server_playback_position_cmd_received_cb, const char* client_name, const char* request_id, unsigned long long position, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_server_playback_state_command_received_cb)(const char* client_name, some_enum state, void* user_data);
#define CB_PARAMS_NAMES client_name, state, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_playback_state_command_received_cb, const char* client_name, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(mc_server_playback_state_command_received_cb, const char* client_name, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_server_playlist_cmd_received_cb)(const char* client_name, const char* request_id, const char* playlist_name, const char* index, some_enum action, unsigned long long position, void* user_data);
#define CB_PARAMS_NAMES client_name, request_id, playlist_name, index, action, position, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_playlist_cmd_received_cb, const char* client_name, const char* request_id, const char* playlist_name, const char* index, some_enum action, unsigned long long position, void* user_data)
PROXY_GROUP_BLOCKING(mc_server_playlist_cmd_received_cb, const char* client_name, const char* request_id, const char* playlist_name, const char* index, some_enum action, unsigned long long position, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_server_repeat_mode_cmd_received_cb)(const char* client_name, const char* request_id, some_enum repeat_mode, void* user_data);
#define CB_PARAMS_NAMES client_name, request_id, repeat_mode, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_repeat_mode_cmd_received_cb, const char* client_name, const char* request_id, some_enum repeat_mode, void* user_data)
PROXY_GROUP_BLOCKING(mc_server_repeat_mode_cmd_received_cb, const char* client_name, const char* request_id, some_enum repeat_mode, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_server_search_cmd_received_cb)(const char* client_name, const char* request_id, void* search, void* user_data);
#define CB_PARAMS_NAMES client_name, request_id, search, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_search_cmd_received_cb, const char* client_name, const char* request_id, void* search, void* user_data)
PROXY_GROUP_BLOCKING(mc_server_search_cmd_received_cb, const char* client_name, const char* request_id, void* search, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_server_shuffle_mode_cmd_received_cb)(const char* client_name, const char* request_id, some_enum shuffle_mode, void* user_data);
#define CB_PARAMS_NAMES client_name, request_id, shuffle_mode, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_shuffle_mode_cmd_received_cb, const char* client_name, const char* request_id, some_enum shuffle_mode, void* user_data)
PROXY_GROUP_BLOCKING(mc_server_shuffle_mode_cmd_received_cb, const char* client_name, const char* request_id, some_enum shuffle_mode, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_server_state_updated_cb)(const char* server_name, some_enum state, void* user_data);
#define CB_PARAMS_NAMES server_name, state, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_state_updated_cb, const char* server_name, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(mc_server_state_updated_cb, const char* server_name, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_shuffle_ability_updated_cb)(const char* server_name, some_enum support, void* user_data);
#define CB_PARAMS_NAMES server_name, support, user_data
PROXY_GROUP_NON_BLOCKING(mc_shuffle_ability_updated_cb, const char* server_name, some_enum support, void* user_data)
PROXY_GROUP_BLOCKING(mc_shuffle_ability_updated_cb, const char* server_name, some_enum support, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_shuffle_mode_changed_cb)(const char* server_name, some_enum mode, void* user_data);
#define CB_PARAMS_NAMES server_name, mode, user_data
PROXY_GROUP_NON_BLOCKING(mc_shuffle_mode_changed_cb, const char* server_name, some_enum mode, void* user_data)
PROXY_GROUP_BLOCKING(mc_shuffle_mode_changed_cb, const char* server_name, some_enum mode, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mc_shuffle_mode_updated_cb)(const char* server_name, some_enum mode, void* user_data);
#define CB_PARAMS_NAMES server_name, mode, user_data
PROXY_GROUP_NON_BLOCKING(mc_shuffle_mode_updated_cb, const char* server_name, some_enum mode, void* user_data)
PROXY_GROUP_BLOCKING(mc_shuffle_mode_updated_cb, const char* server_name, some_enum mode, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*mc_subscribed_server_cb)(const char* server_name, void* user_data);
#define CB_PARAMS_NAMES server_name, user_data
PROXY_GROUP_RETURN(mc_subscribed_server_cb, bool, const char* server_name, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*media_key_event_cb)(some_enum key, some_enum status, void* user_data);
#define CB_PARAMS_NAMES key, status, user_data
PROXY_GROUP_NON_BLOCKING(media_key_event_cb, some_enum key, some_enum status, void* user_data)
PROXY_GROUP_BLOCKING(media_key_event_cb, some_enum key, some_enum status, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*media_packet_dispose_cb)(void* packet, void* user_data);
#define CB_PARAMS_NAMES packet, user_data
PROXY_GROUP_NON_BLOCKING(media_packet_dispose_cb, void* packet, void* user_data)
PROXY_GROUP_BLOCKING(media_packet_dispose_cb, void* packet, void* user_data)
#undef CB_PARAMS_NAMES

typedef int (*media_packet_finalize_cb)(void* packet, int error_code, void* user_data);
#define CB_PARAMS_NAMES packet, error_code, user_data
PROXY_GROUP_RETURN(media_packet_finalize_cb, int, void* packet, int error_code, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*media_streamer_custom_buffer_status_cb)(void* src, some_enum status, void* user_data);
#define CB_PARAMS_NAMES src, status, user_data
PROXY_GROUP_NON_BLOCKING(media_streamer_custom_buffer_status_cb, void* src, some_enum status, void* user_data)
PROXY_GROUP_BLOCKING(media_streamer_custom_buffer_status_cb, void* src, some_enum status, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*media_streamer_error_cb)(void* streamer, some_enum error, void* user_data);
#define CB_PARAMS_NAMES streamer, error, user_data
PROXY_GROUP_NON_BLOCKING(media_streamer_error_cb, void* streamer, some_enum error, void* user_data)
PROXY_GROUP_BLOCKING(media_streamer_error_cb, void* streamer, some_enum error, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*media_streamer_interrupted_cb)(some_enum code, void* user_data);
#define CB_PARAMS_NAMES code, user_data
PROXY_GROUP_NON_BLOCKING(media_streamer_interrupted_cb, some_enum code, void* user_data)
PROXY_GROUP_BLOCKING(media_streamer_interrupted_cb, some_enum code, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*media_streamer_node_decoded_ready_cb)(void* node, const char* src_pad_name, const char* media_type, void* user_data);
#define CB_PARAMS_NAMES node, src_pad_name, media_type, user_data
PROXY_GROUP_NON_BLOCKING(media_streamer_node_decoded_ready_cb, void* node, const char* src_pad_name, const char* media_type, void* user_data)
PROXY_GROUP_BLOCKING(media_streamer_node_decoded_ready_cb, void* node, const char* src_pad_name, const char* media_type, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*media_streamer_position_changed_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(media_streamer_position_changed_cb, void* user_data)
PROXY_GROUP_BLOCKING(media_streamer_position_changed_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*media_streamer_sink_data_ready_cb)(void* sink, void* user_data);
#define CB_PARAMS_NAMES sink, user_data
PROXY_GROUP_NON_BLOCKING(media_streamer_sink_data_ready_cb, void* sink, void* user_data)
PROXY_GROUP_BLOCKING(media_streamer_sink_data_ready_cb, void* sink, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*media_streamer_sink_eos_cb)(void* sink, void* user_data);
#define CB_PARAMS_NAMES sink, user_data
PROXY_GROUP_NON_BLOCKING(media_streamer_sink_eos_cb, void* sink, void* user_data)
PROXY_GROUP_BLOCKING(media_streamer_sink_eos_cb, void* sink, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*media_streamer_state_changed_cb)(void* streamer, some_enum previous_state, some_enum current_state, void* user_data);
#define CB_PARAMS_NAMES streamer, previous_state, current_state, user_data
PROXY_GROUP_NON_BLOCKING(media_streamer_state_changed_cb, void* streamer, some_enum previous_state, some_enum current_state, void* user_data)
PROXY_GROUP_BLOCKING(media_streamer_state_changed_cb, void* streamer, some_enum previous_state, some_enum current_state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*media_streamer_webrtc_message_cb)(void* webrtc, const char* message, void* user_data);
#define CB_PARAMS_NAMES webrtc, message, user_data
PROXY_GROUP_NON_BLOCKING(media_streamer_webrtc_message_cb, void* webrtc, const char* message, void* user_data)
PROXY_GROUP_BLOCKING(media_streamer_webrtc_message_cb, void* webrtc, const char* message, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mediacodec_buffer_status_cb)(some_enum status, void* user_data);
#define CB_PARAMS_NAMES status, user_data
PROXY_GROUP_NON_BLOCKING(mediacodec_buffer_status_cb, some_enum status, void* user_data)
PROXY_GROUP_BLOCKING(mediacodec_buffer_status_cb, some_enum status, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mediacodec_eos_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(mediacodec_eos_cb, void* user_data)
PROXY_GROUP_BLOCKING(mediacodec_eos_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mediacodec_error_cb)(some_enum error, void* user_data);
#define CB_PARAMS_NAMES error, user_data
PROXY_GROUP_NON_BLOCKING(mediacodec_error_cb, some_enum error, void* user_data)
PROXY_GROUP_BLOCKING(mediacodec_error_cb, some_enum error, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mediacodec_input_buffer_used_cb)(void* packet, void* user_data);
#define CB_PARAMS_NAMES packet, user_data
PROXY_GROUP_NON_BLOCKING(mediacodec_input_buffer_used_cb, void* packet, void* user_data)
PROXY_GROUP_BLOCKING(mediacodec_input_buffer_used_cb, void* packet, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mediacodec_output_buffer_available_cb)(void* packet, void* user_data);
#define CB_PARAMS_NAMES packet, user_data
PROXY_GROUP_NON_BLOCKING(mediacodec_output_buffer_available_cb, void* packet, void* user_data)
PROXY_GROUP_BLOCKING(mediacodec_output_buffer_available_cb, void* packet, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*mediacodec_supported_codec_cb)(some_enum codec_type, void* user_data);
#define CB_PARAMS_NAMES codec_type, user_data
PROXY_GROUP_RETURN(mediacodec_supported_codec_cb, bool, some_enum codec_type, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mediademuxer_eos_cb)(int track_num, void* user_data);
#define CB_PARAMS_NAMES track_num, user_data
PROXY_GROUP_NON_BLOCKING(mediademuxer_eos_cb, int track_num, void* user_data)
PROXY_GROUP_BLOCKING(mediademuxer_eos_cb, int track_num, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mediademuxer_error_cb)(some_enum error, void* user_data);
#define CB_PARAMS_NAMES error, user_data
PROXY_GROUP_NON_BLOCKING(mediademuxer_error_cb, some_enum error, void* user_data)
PROXY_GROUP_BLOCKING(mediademuxer_error_cb, some_enum error, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mediaeditor_error_cb)(some_enum error, some_enum state, void* user_data);
#define CB_PARAMS_NAMES error, state, user_data
PROXY_GROUP_NON_BLOCKING(mediaeditor_error_cb, some_enum error, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(mediaeditor_error_cb, some_enum error, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mediaeditor_layer_priority_changed_cb)(void* layer_infos, unsigned int size, void* user_data);
#define CB_PARAMS_NAMES layer_infos, size, user_data
PROXY_GROUP_NON_BLOCKING(mediaeditor_layer_priority_changed_cb, void* layer_infos, unsigned int size, void* user_data)
PROXY_GROUP_BLOCKING(mediaeditor_layer_priority_changed_cb, void* layer_infos, unsigned int size, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mediaeditor_project_loaded_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(mediaeditor_project_loaded_cb, void* user_data)
PROXY_GROUP_BLOCKING(mediaeditor_project_loaded_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mediaeditor_render_completed_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(mediaeditor_render_completed_cb, void* user_data)
PROXY_GROUP_BLOCKING(mediaeditor_render_completed_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mediaeditor_state_changed_cb)(some_enum previous, some_enum current, void* user_data);
#define CB_PARAMS_NAMES previous, current, user_data
PROXY_GROUP_NON_BLOCKING(mediaeditor_state_changed_cb, some_enum previous, some_enum current, void* user_data)
PROXY_GROUP_BLOCKING(mediaeditor_state_changed_cb, some_enum previous, some_enum current, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mediamuxer_eos_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(mediamuxer_eos_cb, void* user_data)
PROXY_GROUP_BLOCKING(mediamuxer_eos_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mediamuxer_error_cb)(some_enum error, void* user_data);
#define CB_PARAMS_NAMES error, user_data
PROXY_GROUP_NON_BLOCKING(mediamuxer_error_cb, some_enum error, void* user_data)
PROXY_GROUP_BLOCKING(mediamuxer_error_cb, some_enum error, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*message_port_message_cb)(int local_port_id, const char* remote_app_id, const char* remote_port, bool trusted_remote_port, void* message, void* user_data);
#define CB_PARAMS_NAMES local_port_id, remote_app_id, remote_port, trusted_remote_port, message, user_data
PROXY_GROUP_NON_BLOCKING(message_port_message_cb, int local_port_id, const char* remote_app_id, const char* remote_port, bool trusted_remote_port, void* message, void* user_data)
PROXY_GROUP_BLOCKING(message_port_message_cb, int local_port_id, const char* remote_app_id, const char* remote_port, bool trusted_remote_port, void* message, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*message_port_registration_event_cb)(const char* remote_app_id, const char* remote_port, bool trusted_remote_port, void* user_data);
#define CB_PARAMS_NAMES remote_app_id, remote_port, trusted_remote_port, user_data
PROXY_GROUP_NON_BLOCKING(message_port_registration_event_cb, const char* remote_app_id, const char* remote_port, bool trusted_remote_port, void* user_data)
PROXY_GROUP_BLOCKING(message_port_registration_event_cb, const char* remote_app_id, const char* remote_port, bool trusted_remote_port, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*message_port_trusted_message_cb)(int trusted_local_port_id, const char* remote_app_id, const char* remote_port, bool trusted_remote_port, void* message, void* user_data);
#define CB_PARAMS_NAMES trusted_local_port_id, remote_app_id, remote_port, trusted_remote_port, message, user_data
PROXY_GROUP_NON_BLOCKING(message_port_trusted_message_cb, int trusted_local_port_id, const char* remote_app_id, const char* remote_port, bool trusted_remote_port, void* message, void* user_data)
PROXY_GROUP_BLOCKING(message_port_trusted_message_cb, int trusted_local_port_id, const char* remote_app_id, const char* remote_port, bool trusted_remote_port, void* message, void* user_data)
#undef CB_PARAMS_NAMES

typedef int (*ml_custom_easy_invoke_cb)(const void* in, void* out, void* user_data);
#define CB_PARAMS_NAMES in, out, user_data
PROXY_GROUP_RETURN(ml_custom_easy_invoke_cb, int, const void* in, void* out, void* user_data)
#undef CB_PARAMS_NAMES

typedef int (*ml_pipeline_if_custom_cb)(const void* data, const void* info, int* result, void* user_data);
#define CB_PARAMS_NAMES data, info, result, user_data
PROXY_GROUP_RETURN(ml_pipeline_if_custom_cb, int, const void* data, const void* info, int* result, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ml_pipeline_sink_cb)(const void* data, const void* info, void* user_data);
#define CB_PARAMS_NAMES data, info, user_data
PROXY_GROUP_NON_BLOCKING(ml_pipeline_sink_cb, const void* data, const void* info, void* user_data)
PROXY_GROUP_BLOCKING(ml_pipeline_sink_cb, const void* data, const void* info, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ml_pipeline_state_cb)(some_enum state, void* user_data);
#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(ml_pipeline_state_cb, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(ml_pipeline_state_cb, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mtp_event_cb)(some_enum event, int event_parameter, void* user_data);
#define CB_PARAMS_NAMES event, event_parameter, user_data
PROXY_GROUP_NON_BLOCKING(mtp_event_cb, some_enum event, int event_parameter, void* user_data)
PROXY_GROUP_BLOCKING(mtp_event_cb, some_enum event, int event_parameter, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mv_3d_depth_cb)(void* source, void* depth, unsigned int width, unsigned int height, void* user_data);
#define CB_PARAMS_NAMES source, depth, width, height, user_data
PROXY_GROUP_NON_BLOCKING(mv_3d_depth_cb, void* source, void* depth, unsigned int width, unsigned int height, void* user_data)
PROXY_GROUP_BLOCKING(mv_3d_depth_cb, void* source, void* depth, unsigned int width, unsigned int height, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mv_3d_pointcloud_cb)(void* source, void* pointcloud, void* user_data);
#define CB_PARAMS_NAMES source, pointcloud, user_data
PROXY_GROUP_NON_BLOCKING(mv_3d_pointcloud_cb, void* source, void* pointcloud, void* user_data)
PROXY_GROUP_BLOCKING(mv_3d_pointcloud_cb, void* source, void* pointcloud, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mv_face_detected_cb)(void* source, void* engine_cfg, void* faces_locations, int number_of_faces, void* user_data);
#define CB_PARAMS_NAMES source, engine_cfg, faces_locations, number_of_faces, user_data
PROXY_GROUP_NON_BLOCKING(mv_face_detected_cb, void* source, void* engine_cfg, void* faces_locations, int number_of_faces, void* user_data)
PROXY_GROUP_BLOCKING(mv_face_detected_cb, void* source, void* engine_cfg, void* faces_locations, int number_of_faces, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mv_face_eye_condition_recognized_cb)(void* source, void* engine_cfg, mv_rectangle_s_copy face_location, some_enum eye_condition, void* user_data);
#define CB_PARAMS_NAMES source, engine_cfg, face_location, eye_condition, user_data
PROXY_GROUP_NON_BLOCKING(mv_face_eye_condition_recognized_cb, void* source, void* engine_cfg, mv_rectangle_s_copy face_location, some_enum eye_condition, void* user_data)
PROXY_GROUP_BLOCKING(mv_face_eye_condition_recognized_cb, void* source, void* engine_cfg, mv_rectangle_s_copy face_location, some_enum eye_condition, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mv_face_facial_expression_recognized_cb)(void* source, void* engine_cfg, mv_rectangle_s_copy face_location, some_enum facial_expression, void* user_data);
#define CB_PARAMS_NAMES source, engine_cfg, face_location, facial_expression, user_data
PROXY_GROUP_NON_BLOCKING(mv_face_facial_expression_recognized_cb, void* source, void* engine_cfg, mv_rectangle_s_copy face_location, some_enum facial_expression, void* user_data)
PROXY_GROUP_BLOCKING(mv_face_facial_expression_recognized_cb, void* source, void* engine_cfg, mv_rectangle_s_copy face_location, some_enum facial_expression, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mv_face_recognized_cb)(void* source, void* recognition_model, void* engine_cfg, void* face_location, const int* face_label, double confidence, void* user_data);
#define CB_PARAMS_NAMES source, recognition_model, engine_cfg, face_location, face_label, confidence, user_data
PROXY_GROUP_NON_BLOCKING(mv_face_recognized_cb, void* source, void* recognition_model, void* engine_cfg, void* face_location, const int* face_label, double confidence, void* user_data)
PROXY_GROUP_BLOCKING(mv_face_recognized_cb, void* source, void* recognition_model, void* engine_cfg, void* face_location, const int* face_label, double confidence, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mv_face_tracked_cb)(void* source, void* tracking_model, void* engine_cfg, void* location, double confidence, void* user_data);
#define CB_PARAMS_NAMES source, tracking_model, engine_cfg, location, confidence, user_data
PROXY_GROUP_NON_BLOCKING(mv_face_tracked_cb, void* source, void* tracking_model, void* engine_cfg, void* location, double confidence, void* user_data)
PROXY_GROUP_BLOCKING(mv_face_tracked_cb, void* source, void* tracking_model, void* engine_cfg, void* location, double confidence, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mv_image_recognized_cb)(void* source, void* engine_cfg, const void* image_objects, void* locations, unsigned int number_of_objects, void* user_data);
#define CB_PARAMS_NAMES source, engine_cfg, image_objects, locations, number_of_objects, user_data
PROXY_GROUP_NON_BLOCKING(mv_image_recognized_cb, void* source, void* engine_cfg, const void* image_objects, void* locations, unsigned int number_of_objects, void* user_data)
PROXY_GROUP_BLOCKING(mv_image_recognized_cb, void* source, void* engine_cfg, const void* image_objects, void* locations, unsigned int number_of_objects, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mv_image_tracked_cb)(void* source, void* image_tracking_model, void* engine_cfg, void* location, void* user_data);
#define CB_PARAMS_NAMES source, image_tracking_model, engine_cfg, location, user_data
PROXY_GROUP_NON_BLOCKING(mv_image_tracked_cb, void* source, void* image_tracking_model, void* engine_cfg, void* location, void* user_data)
PROXY_GROUP_BLOCKING(mv_image_tracked_cb, void* source, void* image_tracking_model, void* engine_cfg, void* location, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mv_inference_face_detected_cb)(void* source, int number_of_faces, const float* confidences, const void* locations, void* user_data);
#define CB_PARAMS_NAMES source, number_of_faces, confidences, locations, user_data
PROXY_GROUP_NON_BLOCKING(mv_inference_face_detected_cb, void* source, int number_of_faces, const float* confidences, const void* locations, void* user_data)
PROXY_GROUP_BLOCKING(mv_inference_face_detected_cb, void* source, int number_of_faces, const float* confidences, const void* locations, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mv_inference_facial_landmark_detected_cb)(void* source, int number_of_landmarks, const void* locations, void* user_data);
#define CB_PARAMS_NAMES source, number_of_landmarks, locations, user_data
PROXY_GROUP_NON_BLOCKING(mv_inference_facial_landmark_detected_cb, void* source, int number_of_landmarks, const void* locations, void* user_data)
PROXY_GROUP_BLOCKING(mv_inference_facial_landmark_detected_cb, void* source, int number_of_landmarks, const void* locations, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mv_inference_image_classified_cb)(void* source, int number_of_classes, const int* indices, const char** names, const float* confidences, void* user_data);
#define CB_PARAMS_NAMES source, number_of_classes, indices, names, confidences, user_data
PROXY_GROUP_NON_BLOCKING(mv_inference_image_classified_cb, void* source, int number_of_classes, const int* indices, const char** names, const float* confidences, void* user_data)
PROXY_GROUP_BLOCKING(mv_inference_image_classified_cb, void* source, int number_of_classes, const int* indices, const char** names, const float* confidences, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mv_inference_object_detected_cb)(void* source, int number_of_objects, const int* indices, const char** names, const float* confidences, const void* locations, void* user_data);
#define CB_PARAMS_NAMES source, number_of_objects, indices, names, confidences, locations, user_data
PROXY_GROUP_NON_BLOCKING(mv_inference_object_detected_cb, void* source, int number_of_objects, const int* indices, const char** names, const float* confidences, const void* locations, void* user_data)
PROXY_GROUP_BLOCKING(mv_inference_object_detected_cb, void* source, int number_of_objects, const int* indices, const char** names, const float* confidences, const void* locations, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mv_inference_pose_landmark_detected_cb)(void* source, void* locations, void* user_data);
#define CB_PARAMS_NAMES source, locations, user_data
PROXY_GROUP_NON_BLOCKING(mv_inference_pose_landmark_detected_cb, void* source, void* locations, void* user_data)
PROXY_GROUP_BLOCKING(mv_inference_pose_landmark_detected_cb, void* source, void* locations, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*mv_inference_supported_engine_cb)(const char* engine, bool supported, void* user_data);
#define CB_PARAMS_NAMES engine, supported, user_data
PROXY_GROUP_RETURN(mv_inference_supported_engine_cb, bool, const char* engine, bool supported, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mv_roi_tracker_tracked_cb)(void* source, mv_rectangle_s_copy roi, void* user_data);
#define CB_PARAMS_NAMES source, roi, user_data
PROXY_GROUP_NON_BLOCKING(mv_roi_tracker_tracked_cb, void* source, mv_rectangle_s_copy roi, void* user_data)
PROXY_GROUP_BLOCKING(mv_roi_tracker_tracked_cb, void* source, mv_rectangle_s_copy roi, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*mv_supported_attribute_cb)(some_enum attribute_type, const char* attribute_name, void* user_data);
#define CB_PARAMS_NAMES attribute_type, attribute_name, user_data
PROXY_GROUP_RETURN(mv_supported_attribute_cb, bool, some_enum attribute_type, const char* attribute_name, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*mv_surveillance_event_occurred_cb)(void* trigger, void* source, int video_stream_id, void* event_result, void* user_data);
#define CB_PARAMS_NAMES trigger, source, video_stream_id, event_result, user_data
PROXY_GROUP_NON_BLOCKING(mv_surveillance_event_occurred_cb, void* trigger, void* source, int video_stream_id, void* event_result, void* user_data)
PROXY_GROUP_BLOCKING(mv_surveillance_event_occurred_cb, void* trigger, void* source, int video_stream_id, void* event_result, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*mv_surveillance_event_result_name_cb)(const char* name, void* user_data);
#define CB_PARAMS_NAMES name, user_data
PROXY_GROUP_RETURN(mv_surveillance_event_result_name_cb, bool, const char* name, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*mv_surveillance_event_type_cb)(const char* event_type, void* user_data);
#define CB_PARAMS_NAMES event_type, user_data
PROXY_GROUP_RETURN(mv_surveillance_event_type_cb, bool, const char* event_type, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*package_manager_event_cb)(const char* type, const char* package, some_enum event_type, some_enum event_state, int progress, some_enum error, void* user_data);
#define CB_PARAMS_NAMES type, package, event_type, event_state, progress, error, user_data
PROXY_GROUP_NON_BLOCKING(package_manager_event_cb, const char* type, const char* package, some_enum event_type, some_enum event_state, int progress, some_enum error, void* user_data)
PROXY_GROUP_BLOCKING(package_manager_event_cb, const char* type, const char* package, some_enum event_type, some_enum event_state, int progress, some_enum error, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*package_manager_package_info_cb)(void* package_info, void* user_data);
#define CB_PARAMS_NAMES package_info, user_data
PROXY_GROUP_RETURN(package_manager_package_info_cb, bool, void* package_info, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*package_manager_request_event_cb)(int id, const char* type, const char* package, some_enum event_type, some_enum event_state, int progress, some_enum error, void* user_data);
#define CB_PARAMS_NAMES id, type, package, event_type, event_state, progress, error, user_data
PROXY_GROUP_NON_BLOCKING(package_manager_request_event_cb, int id, const char* type, const char* package, some_enum event_type, some_enum event_state, int progress, some_enum error, void* user_data)
PROXY_GROUP_BLOCKING(package_manager_request_event_cb, int id, const char* type, const char* package, some_enum event_type, some_enum event_state, int progress, some_enum error, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*package_manager_request_res_event_cb)(int req_id, const char* pkgid, some_enum event_type, some_enum event_state, void* handle, void* user_data);
#define CB_PARAMS_NAMES req_id, pkgid, event_type, event_state, handle, user_data
PROXY_GROUP_NON_BLOCKING(package_manager_request_res_event_cb, int req_id, const char* pkgid, some_enum event_type, some_enum event_state, void* handle, void* user_data)
PROXY_GROUP_BLOCKING(package_manager_request_res_event_cb, int req_id, const char* pkgid, some_enum event_type, some_enum event_state, void* handle, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*package_manager_res_event_cb)(const char* pkgid, some_enum event_type, some_enum event_state, void* handle, void* user_data);
#define CB_PARAMS_NAMES pkgid, event_type, event_state, handle, user_data
PROXY_GROUP_NON_BLOCKING(package_manager_res_event_cb, const char* pkgid, some_enum event_type, some_enum event_state, void* handle, void* user_data)
PROXY_GROUP_BLOCKING(package_manager_res_event_cb, const char* pkgid, some_enum event_type, some_enum event_state, void* handle, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*package_manager_res_event_path_cb)(const char* path, some_enum state, void* user_data);
#define CB_PARAMS_NAMES path, state, user_data
PROXY_GROUP_RETURN(package_manager_res_event_path_cb, bool, const char* path, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*package_manager_size_info_receive_cb)(const char* package_id, const void* size_info, void* user_data);
#define CB_PARAMS_NAMES package_id, size_info, user_data
PROXY_GROUP_NON_BLOCKING(package_manager_size_info_receive_cb, const char* package_id, const void* size_info, void* user_data)
PROXY_GROUP_BLOCKING(package_manager_size_info_receive_cb, const char* package_id, const void* size_info, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*package_manager_total_size_info_receive_cb)(const void* size_info, void* user_data);
#define CB_PARAMS_NAMES size_info, user_data
PROXY_GROUP_NON_BLOCKING(package_manager_total_size_info_receive_cb, const void* size_info, void* user_data)
PROXY_GROUP_BLOCKING(package_manager_total_size_info_receive_cb, const void* size_info, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*peripheral_gpio_interrupted_cb)(void* gpio, some_enum error, void* user_data);
#define CB_PARAMS_NAMES gpio, error, user_data
PROXY_GROUP_NON_BLOCKING(peripheral_gpio_interrupted_cb, void* gpio, some_enum error, void* user_data)
PROXY_GROUP_BLOCKING(peripheral_gpio_interrupted_cb, void* gpio, some_enum error, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*player_adaptive_variant_cb)(int bandwidth, int width, int height, void* user_data);
#define CB_PARAMS_NAMES bandwidth, width, height, user_data
PROXY_GROUP_NON_BLOCKING(player_adaptive_variant_cb, int bandwidth, int width, int height, void* user_data)
PROXY_GROUP_BLOCKING(player_adaptive_variant_cb, int bandwidth, int width, int height, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*player_buffering_cb)(int percent, void* user_data);
#define CB_PARAMS_NAMES percent, user_data
PROXY_GROUP_NON_BLOCKING(player_buffering_cb, int percent, void* user_data)
PROXY_GROUP_BLOCKING(player_buffering_cb, int percent, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*player_completed_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(player_completed_cb, void* user_data)
PROXY_GROUP_BLOCKING(player_completed_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*player_error_cb)(int error_code, void* user_data);
#define CB_PARAMS_NAMES error_code, user_data
PROXY_GROUP_NON_BLOCKING(player_error_cb, int error_code, void* user_data)
PROXY_GROUP_BLOCKING(player_error_cb, int error_code, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*player_interrupted_cb)(some_enum code, void* user_data);
#define CB_PARAMS_NAMES code, user_data
PROXY_GROUP_NON_BLOCKING(player_interrupted_cb, some_enum code, void* user_data)
PROXY_GROUP_BLOCKING(player_interrupted_cb, some_enum code, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*player_media_packet_audio_decoded_cb)(void* packet, void* user_data);
#define CB_PARAMS_NAMES packet, user_data
PROXY_GROUP_NON_BLOCKING(player_media_packet_audio_decoded_cb, void* packet, void* user_data)
PROXY_GROUP_BLOCKING(player_media_packet_audio_decoded_cb, void* packet, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*player_media_packet_video_decoded_cb)(void* packet, void* user_data);
#define CB_PARAMS_NAMES packet, user_data
PROXY_GROUP_NON_BLOCKING(player_media_packet_video_decoded_cb, void* packet, void* user_data)
PROXY_GROUP_BLOCKING(player_media_packet_video_decoded_cb, void* packet, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*player_media_stream_buffer_status_cb)(some_enum status, void* user_data);
#define CB_PARAMS_NAMES status, user_data
PROXY_GROUP_NON_BLOCKING(player_media_stream_buffer_status_cb, some_enum status, void* user_data)
PROXY_GROUP_BLOCKING(player_media_stream_buffer_status_cb, some_enum status, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*player_media_stream_seek_cb)(unsigned long long offset, void* user_data);
#define CB_PARAMS_NAMES offset, user_data
PROXY_GROUP_NON_BLOCKING(player_media_stream_seek_cb, unsigned long long offset, void* user_data)
PROXY_GROUP_BLOCKING(player_media_stream_seek_cb, unsigned long long offset, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*player_pd_message_cb)(some_enum type, void* user_data);
#define CB_PARAMS_NAMES type, user_data
PROXY_GROUP_NON_BLOCKING(player_pd_message_cb, some_enum type, void* user_data)
PROXY_GROUP_BLOCKING(player_pd_message_cb, some_enum type, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*player_prepared_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(player_prepared_cb, void* user_data)
PROXY_GROUP_BLOCKING(player_prepared_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*player_seek_completed_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(player_seek_completed_cb, void* user_data)
PROXY_GROUP_BLOCKING(player_seek_completed_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*player_subtitle_updated_cb)(unsigned long duration, char* text, void* user_data);
#define CB_PARAMS_NAMES duration, text, user_data
PROXY_GROUP_NON_BLOCKING(player_subtitle_updated_cb, unsigned long duration, char* text, void* user_data)
PROXY_GROUP_BLOCKING(player_subtitle_updated_cb, unsigned long duration, char* text, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*player_supported_media_format_cb)(some_enum format, void* user_data);
#define CB_PARAMS_NAMES format, user_data
PROXY_GROUP_RETURN(player_supported_media_format_cb, bool, some_enum format, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*player_video_captured_cb)(unsigned char* captured_data, int width, int height, unsigned int size, void* user_data);
#define CB_PARAMS_NAMES captured_data, width, height, size, user_data
PROXY_GROUP_NON_BLOCKING(player_video_captured_cb, unsigned char* captured_data, int width, int height, unsigned int size, void* user_data)
PROXY_GROUP_BLOCKING(player_video_captured_cb, unsigned char* captured_data, int width, int height, unsigned int size, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*player_video_stream_changed_cb)(int width, int height, int fps, int bit_rate, void* user_data);
#define CB_PARAMS_NAMES width, height, fps, bit_rate, user_data
PROXY_GROUP_NON_BLOCKING(player_video_stream_changed_cb, int width, int height, int fps, int bit_rate, void* user_data)
PROXY_GROUP_BLOCKING(player_video_stream_changed_cb, int width, int height, int fps, int bit_rate, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ppm_request_multiple_response_cb)(some_enum cause, const void* results, const char** privileges, size_t privileges_count, void* user_data);
#define CB_PARAMS_NAMES cause, results, privileges, privileges_count, user_data
PROXY_GROUP_NON_BLOCKING(ppm_request_multiple_response_cb, some_enum cause, const void* results, const char** privileges, size_t privileges_count, void* user_data)
PROXY_GROUP_BLOCKING(ppm_request_multiple_response_cb, some_enum cause, const void* results, const char** privileges, size_t privileges_count, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ppm_request_response_cb)(some_enum cause, some_enum result, const char* privilege, void* user_data);
#define CB_PARAMS_NAMES cause, result, privilege, user_data
PROXY_GROUP_NON_BLOCKING(ppm_request_response_cb, some_enum cause, some_enum result, const char* privilege, void* user_data)
PROXY_GROUP_BLOCKING(ppm_request_response_cb, some_enum cause, some_enum result, const char* privilege, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*preference_changed_cb)(const char* key, void* user_data);
#define CB_PARAMS_NAMES key, user_data
PROXY_GROUP_NON_BLOCKING(preference_changed_cb, const char* key, void* user_data)
PROXY_GROUP_BLOCKING(preference_changed_cb, const char* key, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*preference_item_cb)(const char* key, void* user_data);
#define CB_PARAMS_NAMES key, user_data
PROXY_GROUP_RETURN(preference_item_cb, bool, const char* key, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*provider_feature_cb)(char* app_id, char* key, void* user_data);
#define CB_PARAMS_NAMES app_id, key, user_data
PROXY_GROUP_RETURN(provider_feature_cb, bool, char* app_id, char* key, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*push_service_notify_cb)(void* noti, void* user_data);
#define CB_PARAMS_NAMES noti, user_data
PROXY_GROUP_NON_BLOCKING(push_service_notify_cb, void* noti, void* user_data)
PROXY_GROUP_BLOCKING(push_service_notify_cb, void* noti, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*push_service_result_cb)(some_enum result, const char* msg, void* user_data);
#define CB_PARAMS_NAMES result, msg, user_data
PROXY_GROUP_NON_BLOCKING(push_service_result_cb, some_enum result, const char* msg, void* user_data)
PROXY_GROUP_BLOCKING(push_service_result_cb, some_enum result, const char* msg, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*push_service_state_cb)(some_enum state, const char* err, void* user_data);
#define CB_PARAMS_NAMES state, err, user_data
PROXY_GROUP_NON_BLOCKING(push_service_state_cb, some_enum state, const char* err, void* user_data)
PROXY_GROUP_BLOCKING(push_service_state_cb, some_enum state, const char* err, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*radio_interrupted_cb)(some_enum code, void* user_data);
#define CB_PARAMS_NAMES code, user_data
PROXY_GROUP_NON_BLOCKING(radio_interrupted_cb, some_enum code, void* user_data)
PROXY_GROUP_BLOCKING(radio_interrupted_cb, some_enum code, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*radio_scan_completed_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(radio_scan_completed_cb, void* user_data)
PROXY_GROUP_BLOCKING(radio_scan_completed_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*radio_scan_stopped_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(radio_scan_stopped_cb, void* user_data)
PROXY_GROUP_BLOCKING(radio_scan_stopped_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*radio_scan_updated_cb)(int frequency, void* user_data);
#define CB_PARAMS_NAMES frequency, user_data
PROXY_GROUP_NON_BLOCKING(radio_scan_updated_cb, int frequency, void* user_data)
PROXY_GROUP_BLOCKING(radio_scan_updated_cb, int frequency, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*radio_seek_completed_cb)(int frequency, void* user_data);
#define CB_PARAMS_NAMES frequency, user_data
PROXY_GROUP_NON_BLOCKING(radio_seek_completed_cb, int frequency, void* user_data)
PROXY_GROUP_BLOCKING(radio_seek_completed_cb, int frequency, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*recorder_audio_stream_cb)(void* stream, int size, some_enum format, int channel, unsigned int timestamp, void* user_data);
#define CB_PARAMS_NAMES stream, size, format, channel, timestamp, user_data
PROXY_GROUP_NON_BLOCKING(recorder_audio_stream_cb, void* stream, int size, some_enum format, int channel, unsigned int timestamp, void* user_data)
PROXY_GROUP_BLOCKING(recorder_audio_stream_cb, void* stream, int size, some_enum format, int channel, unsigned int timestamp, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*recorder_device_state_changed_cb)(some_enum type, some_enum state, void* user_data);
#define CB_PARAMS_NAMES type, state, user_data
PROXY_GROUP_NON_BLOCKING(recorder_device_state_changed_cb, some_enum type, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(recorder_device_state_changed_cb, some_enum type, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*recorder_error_cb)(some_enum error, some_enum current_state, void* user_data);
#define CB_PARAMS_NAMES error, current_state, user_data
PROXY_GROUP_NON_BLOCKING(recorder_error_cb, some_enum error, some_enum current_state, void* user_data)
PROXY_GROUP_BLOCKING(recorder_error_cb, some_enum error, some_enum current_state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*recorder_interrupt_started_cb)(some_enum policy, some_enum state, void* user_data);
#define CB_PARAMS_NAMES policy, state, user_data
PROXY_GROUP_NON_BLOCKING(recorder_interrupt_started_cb, some_enum policy, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(recorder_interrupt_started_cb, some_enum policy, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*recorder_interrupted_cb)(some_enum policy, some_enum previous, some_enum current, void* user_data);
#define CB_PARAMS_NAMES policy, previous, current, user_data
PROXY_GROUP_NON_BLOCKING(recorder_interrupted_cb, some_enum policy, some_enum previous, some_enum current, void* user_data)
PROXY_GROUP_BLOCKING(recorder_interrupted_cb, some_enum policy, some_enum previous, some_enum current, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*recorder_muxed_stream_cb)(void* stream, int size, unsigned long long offset, void* user_data);
#define CB_PARAMS_NAMES stream, size, offset, user_data
PROXY_GROUP_NON_BLOCKING(recorder_muxed_stream_cb, void* stream, int size, unsigned long long offset, void* user_data)
PROXY_GROUP_BLOCKING(recorder_muxed_stream_cb, void* stream, int size, unsigned long long offset, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*recorder_recording_limit_reached_cb)(some_enum type, void* user_data);
#define CB_PARAMS_NAMES type, user_data
PROXY_GROUP_NON_BLOCKING(recorder_recording_limit_reached_cb, some_enum type, void* user_data)
PROXY_GROUP_BLOCKING(recorder_recording_limit_reached_cb, some_enum type, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*recorder_recording_status_cb)(unsigned long long elapsed_time, unsigned long long file_size, void* user_data);
#define CB_PARAMS_NAMES elapsed_time, file_size, user_data
PROXY_GROUP_NON_BLOCKING(recorder_recording_status_cb, unsigned long long elapsed_time, unsigned long long file_size, void* user_data)
PROXY_GROUP_BLOCKING(recorder_recording_status_cb, unsigned long long elapsed_time, unsigned long long file_size, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*recorder_state_changed_cb)(some_enum previous, some_enum current, bool by_policy, void* user_data);
#define CB_PARAMS_NAMES previous, current, by_policy, user_data
PROXY_GROUP_NON_BLOCKING(recorder_state_changed_cb, some_enum previous, some_enum current, bool by_policy, void* user_data)
PROXY_GROUP_BLOCKING(recorder_state_changed_cb, some_enum previous, some_enum current, bool by_policy, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*recorder_supported_audio_encoder_cb)(some_enum codec, void* user_data);
#define CB_PARAMS_NAMES codec, user_data
PROXY_GROUP_RETURN(recorder_supported_audio_encoder_cb, bool, some_enum codec, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*recorder_supported_file_format_cb)(some_enum format, void* user_data);
#define CB_PARAMS_NAMES format, user_data
PROXY_GROUP_RETURN(recorder_supported_file_format_cb, bool, some_enum format, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*recorder_supported_video_encoder_cb)(some_enum codec, void* user_data);
#define CB_PARAMS_NAMES codec, user_data
PROXY_GROUP_RETURN(recorder_supported_video_encoder_cb, bool, some_enum codec, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*recorder_supported_video_resolution_cb)(int width, int height, void* user_data);
#define CB_PARAMS_NAMES width, height, user_data
PROXY_GROUP_RETURN(recorder_supported_video_resolution_cb, bool, int width, int height, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*recorder_video_encode_decision_cb)(void* frame, void* user_data);
#define CB_PARAMS_NAMES frame, user_data
PROXY_GROUP_RETURN(recorder_video_encode_decision_cb, bool, void* frame, void* user_data)
#undef CB_PARAMS_NAMES

typedef int (*result_cb)(int ret, void* user_data);
#define CB_PARAMS_NAMES ret, user_data
PROXY_GROUP_RETURN(result_cb, int, int ret, void* user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_result_cb_t 5
typedef int (*result_cb_t)(int ret, void* data);
#define CB_PARAMS_NAMES ret, data
PROXY_GROUP_RETURN_NO_USER_DATA(result_cb_t, int, int ret, void* data)
#undef CB_PARAMS_NAMES

typedef void (*rpc_port_proxy_connected_event_cb)(const char* receiver, const char* port_name, void* port, void* user_data);
#define CB_PARAMS_NAMES receiver, port_name, port, user_data
PROXY_GROUP_NON_BLOCKING(rpc_port_proxy_connected_event_cb, const char* receiver, const char* port_name, void* port, void* user_data)
PROXY_GROUP_BLOCKING(rpc_port_proxy_connected_event_cb, const char* receiver, const char* port_name, void* port, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*rpc_port_proxy_disconnected_event_cb)(const char* receiver, const char* port_name, void* user_data);
#define CB_PARAMS_NAMES receiver, port_name, user_data
PROXY_GROUP_NON_BLOCKING(rpc_port_proxy_disconnected_event_cb, const char* receiver, const char* port_name, void* user_data)
PROXY_GROUP_BLOCKING(rpc_port_proxy_disconnected_event_cb, const char* receiver, const char* port_name, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*rpc_port_proxy_received_event_cb)(const char* receiver, const char* port_name, void* user_data);
#define CB_PARAMS_NAMES receiver, port_name, user_data
PROXY_GROUP_NON_BLOCKING(rpc_port_proxy_received_event_cb, const char* receiver, const char* port_name, void* user_data)
PROXY_GROUP_BLOCKING(rpc_port_proxy_received_event_cb, const char* receiver, const char* port_name, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*rpc_port_proxy_rejected_event_cb)(const char* receiver, const char* port_name, void* user_data);
#define CB_PARAMS_NAMES receiver, port_name, user_data
PROXY_GROUP_NON_BLOCKING(rpc_port_proxy_rejected_event_cb, const char* receiver, const char* port_name, void* user_data)
PROXY_GROUP_BLOCKING(rpc_port_proxy_rejected_event_cb, const char* receiver, const char* port_name, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*rpc_port_stub_connected_event_cb)(const char* sender, const char* instance, void* user_data);
#define CB_PARAMS_NAMES sender, instance, user_data
PROXY_GROUP_NON_BLOCKING(rpc_port_stub_connected_event_cb, const char* sender, const char* instance, void* user_data)
PROXY_GROUP_BLOCKING(rpc_port_stub_connected_event_cb, const char* sender, const char* instance, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*rpc_port_stub_disconnected_event_cb)(const char* sender, const char* instance, void* user_data);
#define CB_PARAMS_NAMES sender, instance, user_data
PROXY_GROUP_NON_BLOCKING(rpc_port_stub_disconnected_event_cb, const char* sender, const char* instance, void* user_data)
PROXY_GROUP_BLOCKING(rpc_port_stub_disconnected_event_cb, const char* sender, const char* instance, void* user_data)
#undef CB_PARAMS_NAMES

typedef int (*rpc_port_stub_received_event_cb)(const char* sender, const char* instance, void* port, void* user_data);
#define CB_PARAMS_NAMES sender, instance, port, user_data
PROXY_GROUP_RETURN(rpc_port_stub_received_event_cb, int, const char* sender, const char* instance, void* port, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*runtime_info_changed_cb)(some_enum key, void* user_data);
#define CB_PARAMS_NAMES key, user_data
PROXY_GROUP_NON_BLOCKING(runtime_info_changed_cb, some_enum key, void* user_data)
PROXY_GROUP_BLOCKING(runtime_info_changed_cb, some_enum key, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*sensor_accuracy_changed_cb)(void* sensor, unsigned long long timestamp, some_enum accuracy, void* user_data);
#define CB_PARAMS_NAMES sensor, timestamp, accuracy, user_data
PROXY_GROUP_NON_BLOCKING(sensor_accuracy_changed_cb, void* sensor, unsigned long long timestamp, some_enum accuracy, void* user_data)
PROXY_GROUP_BLOCKING(sensor_accuracy_changed_cb, void* sensor, unsigned long long timestamp, some_enum accuracy, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*sensor_added_cb)(const char* uri, void* user_data);
#define CB_PARAMS_NAMES uri, user_data
PROXY_GROUP_NON_BLOCKING(sensor_added_cb, const char* uri, void* user_data)
PROXY_GROUP_BLOCKING(sensor_added_cb, const char* uri, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*sensor_event_cb)(void* sensor, void* event, void* user_data);
#define CB_PARAMS_NAMES sensor, event, user_data
PROXY_GROUP_NON_BLOCKING(sensor_event_cb, void* sensor, void* event, void* user_data)
PROXY_GROUP_BLOCKING(sensor_event_cb, void* sensor, void* event, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*sensor_events_cb)(void* sensor, void* events, int events_count, void* user_data);
#define CB_PARAMS_NAMES sensor, events, events_count, user_data
PROXY_GROUP_NON_BLOCKING(sensor_events_cb, void* sensor, void* events, int events_count, void* user_data)
PROXY_GROUP_BLOCKING(sensor_events_cb, void* sensor, void* events, int events_count, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*sensor_provider_interval_changed_cb)(void* provider, unsigned int interval_ms, void* user_data);
#define CB_PARAMS_NAMES provider, interval_ms, user_data
PROXY_GROUP_NON_BLOCKING(sensor_provider_interval_changed_cb, void* provider, unsigned int interval_ms, void* user_data)
PROXY_GROUP_BLOCKING(sensor_provider_interval_changed_cb, void* provider, unsigned int interval_ms, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*sensor_provider_start_cb)(void* provider, void* user_data);
#define CB_PARAMS_NAMES provider, user_data
PROXY_GROUP_NON_BLOCKING(sensor_provider_start_cb, void* provider, void* user_data)
PROXY_GROUP_BLOCKING(sensor_provider_start_cb, void* provider, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*sensor_provider_stop_cb)(void* provider, void* user_data);
#define CB_PARAMS_NAMES provider, user_data
PROXY_GROUP_NON_BLOCKING(sensor_provider_stop_cb, void* provider, void* user_data)
PROXY_GROUP_BLOCKING(sensor_provider_stop_cb, void* provider, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*sensor_recorder_data_cb)(some_enum type, void* data, int remains, some_enum error, void* user_data);
#define CB_PARAMS_NAMES type, data, remains, error, user_data
PROXY_GROUP_RETURN(sensor_recorder_data_cb, bool, some_enum type, void* data, int remains, some_enum error, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*sensor_removed_cb)(const char* uri, void* user_data);
#define CB_PARAMS_NAMES uri, user_data
PROXY_GROUP_NON_BLOCKING(sensor_removed_cb, const char* uri, void* user_data)
PROXY_GROUP_BLOCKING(sensor_removed_cb, const char* uri, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*service_app_control_cb)(void* app_control, void* user_data);
#define CB_PARAMS_NAMES app_control, user_data
PROXY_GROUP_NON_BLOCKING(service_app_control_cb, void* app_control, void* user_data)
PROXY_GROUP_BLOCKING(service_app_control_cb, void* app_control, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*service_app_create_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_RETURN(service_app_create_cb, bool, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*service_app_terminate_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(service_app_terminate_cb, void* user_data)
PROXY_GROUP_BLOCKING(service_app_terminate_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef int (*shortcut_list_cb)(const char* package_name, const char* icon, const char* name, const char* extra_key, const char* extra_data, void* user_data);
#define CB_PARAMS_NAMES package_name, icon, name, extra_key, extra_data, user_data
PROXY_GROUP_RETURN(shortcut_list_cb, int, const char* package_name, const char* icon, const char* name, const char* extra_key, const char* extra_data, void* user_data)
#undef CB_PARAMS_NAMES

typedef int (*shortcut_remove_cb)(const char* package_name, const char* name, int sender_pid, void* user_data);
#define CB_PARAMS_NAMES package_name, name, sender_pid, user_data
PROXY_GROUP_RETURN(shortcut_remove_cb, int, const char* package_name, const char* name, int sender_pid, void* user_data)
#undef CB_PARAMS_NAMES

typedef int (*shortcut_request_cb)(const char* package_name, const char* name, int type, const char* content_info, const char* icon, int pid, double period, int allow_duplicate, void* user_data);
#define CB_PARAMS_NAMES package_name, name, type, content_info, icon, pid, period, allow_duplicate, user_data
PROXY_GROUP_RETURN(shortcut_request_cb, int, const char* package_name, const char* name, int type, const char* content_info, const char* icon, int pid, double period, int allow_duplicate, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*smartcard_reader_event_cb)(int reader, some_enum event_type, void* user_data);
#define CB_PARAMS_NAMES reader, event_type, user_data
PROXY_GROUP_NON_BLOCKING(smartcard_reader_event_cb, int reader, some_enum event_type, void* user_data)
PROXY_GROUP_BLOCKING(smartcard_reader_event_cb, int reader, some_enum event_type, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*softap_client_connection_state_changed_cb)(void* client, bool opened, void* user_data);
#define CB_PARAMS_NAMES client, opened, user_data
PROXY_GROUP_NON_BLOCKING(softap_client_connection_state_changed_cb, void* client, bool opened, void* user_data)
PROXY_GROUP_BLOCKING(softap_client_connection_state_changed_cb, void* client, bool opened, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*softap_connected_client_cb)(void* client, void* user_data);
#define CB_PARAMS_NAMES client, user_data
PROXY_GROUP_RETURN(softap_connected_client_cb, bool, void* client, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*softap_disabled_cb)(some_enum result, some_enum cause, void* user_data);
#define CB_PARAMS_NAMES result, cause, user_data
PROXY_GROUP_NON_BLOCKING(softap_disabled_cb, some_enum result, some_enum cause, void* user_data)
PROXY_GROUP_BLOCKING(softap_disabled_cb, some_enum result, some_enum cause, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*softap_enabled_cb)(some_enum result, bool is_requested, void* user_data);
#define CB_PARAMS_NAMES result, is_requested, user_data
PROXY_GROUP_NON_BLOCKING(softap_enabled_cb, some_enum result, bool is_requested, void* user_data)
PROXY_GROUP_BLOCKING(softap_enabled_cb, some_enum result, bool is_requested, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*softap_passphrase_changed_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(softap_passphrase_changed_cb, void* user_data)
PROXY_GROUP_BLOCKING(softap_passphrase_changed_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*softap_security_type_changed_cb)(some_enum changed_type, void* user_data);
#define CB_PARAMS_NAMES changed_type, user_data
PROXY_GROUP_NON_BLOCKING(softap_security_type_changed_cb, some_enum changed_type, void* user_data)
PROXY_GROUP_BLOCKING(softap_security_type_changed_cb, some_enum changed_type, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*softap_settings_reloaded_cb)(some_enum result, void* user_data);
#define CB_PARAMS_NAMES result, user_data
PROXY_GROUP_NON_BLOCKING(softap_settings_reloaded_cb, some_enum result, void* user_data)
PROXY_GROUP_BLOCKING(softap_settings_reloaded_cb, some_enum result, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*softap_ssid_visibility_changed_cb)(bool changed_visible, void* user_data);
#define CB_PARAMS_NAMES changed_visible, user_data
PROXY_GROUP_NON_BLOCKING(softap_ssid_visibility_changed_cb, bool changed_visible, void* user_data)
PROXY_GROUP_BLOCKING(softap_ssid_visibility_changed_cb, bool changed_visible, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*sound_device_connected_cb)(void* device, bool is_connected, void* user_data);
#define CB_PARAMS_NAMES device, is_connected, user_data
PROXY_GROUP_NON_BLOCKING(sound_device_connected_cb, void* device, bool is_connected, void* user_data)
PROXY_GROUP_BLOCKING(sound_device_connected_cb, void* device, bool is_connected, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*sound_device_connection_changed_cb)(void* device, bool is_connected, void* user_data);
#define CB_PARAMS_NAMES device, is_connected, user_data
PROXY_GROUP_NON_BLOCKING(sound_device_connection_changed_cb, void* device, bool is_connected, void* user_data)
PROXY_GROUP_BLOCKING(sound_device_connection_changed_cb, void* device, bool is_connected, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*sound_device_information_changed_cb)(void* device, some_enum changed_info, void* user_data);
#define CB_PARAMS_NAMES device, changed_info, user_data
PROXY_GROUP_NON_BLOCKING(sound_device_information_changed_cb, void* device, some_enum changed_info, void* user_data)
PROXY_GROUP_BLOCKING(sound_device_information_changed_cb, void* device, some_enum changed_info, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*sound_device_running_changed_cb)(void* device, bool is_running, void* user_data);
#define CB_PARAMS_NAMES device, is_running, user_data
PROXY_GROUP_NON_BLOCKING(sound_device_running_changed_cb, void* device, bool is_running, void* user_data)
PROXY_GROUP_BLOCKING(sound_device_running_changed_cb, void* device, bool is_running, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*sound_device_state_changed_cb)(void* device, some_enum state, void* user_data);
#define CB_PARAMS_NAMES device, state, user_data
PROXY_GROUP_NON_BLOCKING(sound_device_state_changed_cb, void* device, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(sound_device_state_changed_cb, void* device, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*sound_manager_volume_changed_cb)(some_enum type, unsigned int volume, void* user_data);
#define CB_PARAMS_NAMES type, volume, user_data
PROXY_GROUP_NON_BLOCKING(sound_manager_volume_changed_cb, some_enum type, unsigned int volume, void* user_data)
PROXY_GROUP_BLOCKING(sound_manager_volume_changed_cb, some_enum type, unsigned int volume, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*sound_pool_state_changed_cb)(void* pool, some_enum prev_state, some_enum cur_state, void* user_data);
#define CB_PARAMS_NAMES pool, prev_state, cur_state, user_data
PROXY_GROUP_NON_BLOCKING(sound_pool_state_changed_cb, void* pool, some_enum prev_state, some_enum cur_state, void* user_data)
PROXY_GROUP_BLOCKING(sound_pool_state_changed_cb, void* pool, some_enum prev_state, some_enum cur_state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*sound_pool_stream_state_changed_cb)(void* pool, unsigned id, some_enum prev_state, some_enum cur_state, void* user_data);
#define CB_PARAMS_NAMES pool, id, prev_state, cur_state, user_data
PROXY_GROUP_NON_BLOCKING(sound_pool_stream_state_changed_cb, void* pool, unsigned id, some_enum prev_state, some_enum cur_state, void* user_data)
PROXY_GROUP_BLOCKING(sound_pool_stream_state_changed_cb, void* pool, unsigned id, some_enum prev_state, some_enum cur_state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*sound_session_interrupted_cb)(some_enum code, void* user_data);
#define CB_PARAMS_NAMES code, user_data
PROXY_GROUP_NON_BLOCKING(sound_session_interrupted_cb, some_enum code, void* user_data)
PROXY_GROUP_BLOCKING(sound_session_interrupted_cb, some_enum code, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*sound_stream_ducking_state_changed_cb)(void* stream_ducking, bool is_ducked, void* user_data);
#define CB_PARAMS_NAMES stream_ducking, is_ducked, user_data
PROXY_GROUP_NON_BLOCKING(sound_stream_ducking_state_changed_cb, void* stream_ducking, bool is_ducked, void* user_data)
PROXY_GROUP_BLOCKING(sound_stream_ducking_state_changed_cb, void* stream_ducking, bool is_ducked, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*sound_stream_focus_state_changed_cb)(void* stream_info, some_enum focus_mask, some_enum focus_state, some_enum reason, int sound_behavior, const char* extra_info, void* user_data);
#define CB_PARAMS_NAMES stream_info, focus_mask, focus_state, reason, sound_behavior, extra_info, user_data
PROXY_GROUP_NON_BLOCKING(sound_stream_focus_state_changed_cb, void* stream_info, some_enum focus_mask, some_enum focus_state, some_enum reason, int sound_behavior, const char* extra_info, void* user_data)
PROXY_GROUP_BLOCKING(sound_stream_focus_state_changed_cb, void* stream_info, some_enum focus_mask, some_enum focus_state, some_enum reason, int sound_behavior, const char* extra_info, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*sound_stream_focus_state_watch_cb)(int id, some_enum focus_mask, some_enum focus_state, some_enum reason, const char* extra_info, void* user_data);
#define CB_PARAMS_NAMES id, focus_mask, focus_state, reason, extra_info, user_data
PROXY_GROUP_NON_BLOCKING(sound_stream_focus_state_watch_cb, int id, some_enum focus_mask, some_enum focus_state, some_enum reason, const char* extra_info, void* user_data)
PROXY_GROUP_BLOCKING(sound_stream_focus_state_watch_cb, int id, some_enum focus_mask, some_enum focus_state, some_enum reason, const char* extra_info, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ssdp_found_cb)(some_enum state, unsigned int ssdp_remote_service, void* user_data);
#define CB_PARAMS_NAMES state, ssdp_remote_service, user_data
PROXY_GROUP_NON_BLOCKING(ssdp_found_cb, some_enum state, unsigned int ssdp_remote_service, void* user_data)
PROXY_GROUP_BLOCKING(ssdp_found_cb, some_enum state, unsigned int ssdp_remote_service, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*ssdp_registered_cb)(some_enum result, unsigned int ssdp_local_service, void* user_data);
#define CB_PARAMS_NAMES result, ssdp_local_service, user_data
PROXY_GROUP_NON_BLOCKING(ssdp_registered_cb, some_enum result, unsigned int ssdp_local_service, void* user_data)
PROXY_GROUP_BLOCKING(ssdp_registered_cb, some_enum result, unsigned int ssdp_local_service, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*stc_get_all_stats_finished_cb)(some_enum result, void* info, void* user_data);
#define CB_PARAMS_NAMES result, info, user_data
PROXY_GROUP_NON_BLOCKING(stc_get_all_stats_finished_cb, some_enum result, void* info, void* user_data)
PROXY_GROUP_BLOCKING(stc_get_all_stats_finished_cb, some_enum result, void* info, void* user_data)
#undef CB_PARAMS_NAMES

typedef some_enum (*stc_stats_info_cb)(some_enum result, void* info, void* user_data);
#define CB_PARAMS_NAMES result, info, user_data
PROXY_GROUP_RETURN(stc_stats_info_cb, some_enum, some_enum result, void* info, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*streamrecorder_consume_completed_cb)(void* buffer, void* user_data);
#define CB_PARAMS_NAMES buffer, user_data
PROXY_GROUP_NON_BLOCKING(streamrecorder_consume_completed_cb, void* buffer, void* user_data)
PROXY_GROUP_BLOCKING(streamrecorder_consume_completed_cb, void* buffer, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*streamrecorder_error_cb)(some_enum error, some_enum current_state, void* user_data);
#define CB_PARAMS_NAMES error, current_state, user_data
PROXY_GROUP_NON_BLOCKING(streamrecorder_error_cb, some_enum error, some_enum current_state, void* user_data)
PROXY_GROUP_BLOCKING(streamrecorder_error_cb, some_enum error, some_enum current_state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*streamrecorder_notify_cb)(some_enum previous, some_enum current, some_enum notification, void* user_data);
#define CB_PARAMS_NAMES previous, current, notification, user_data
PROXY_GROUP_NON_BLOCKING(streamrecorder_notify_cb, some_enum previous, some_enum current, some_enum notification, void* user_data)
PROXY_GROUP_BLOCKING(streamrecorder_notify_cb, some_enum previous, some_enum current, some_enum notification, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*streamrecorder_recording_limit_reached_cb)(some_enum type, void* user_data);
#define CB_PARAMS_NAMES type, user_data
PROXY_GROUP_NON_BLOCKING(streamrecorder_recording_limit_reached_cb, some_enum type, void* user_data)
PROXY_GROUP_BLOCKING(streamrecorder_recording_limit_reached_cb, some_enum type, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*streamrecorder_recording_status_cb)(unsigned long long elapsed_time, unsigned long long file_size, void* user_data);
#define CB_PARAMS_NAMES elapsed_time, file_size, user_data
PROXY_GROUP_NON_BLOCKING(streamrecorder_recording_status_cb, unsigned long long elapsed_time, unsigned long long file_size, void* user_data)
PROXY_GROUP_BLOCKING(streamrecorder_recording_status_cb, unsigned long long elapsed_time, unsigned long long file_size, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*streamrecorder_supported_audio_encoder_cb)(some_enum codec, void* user_data);
#define CB_PARAMS_NAMES codec, user_data
PROXY_GROUP_RETURN(streamrecorder_supported_audio_encoder_cb, bool, some_enum codec, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*streamrecorder_supported_file_format_cb)(some_enum format, void* user_data);
#define CB_PARAMS_NAMES format, user_data
PROXY_GROUP_RETURN(streamrecorder_supported_file_format_cb, bool, some_enum format, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*streamrecorder_supported_video_encoder_cb)(some_enum codec, void* user_data);
#define CB_PARAMS_NAMES codec, user_data
PROXY_GROUP_RETURN(streamrecorder_supported_video_encoder_cb, bool, some_enum codec, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*streamrecorder_supported_video_resolution_cb)(int width, int height, void* user_data);
#define CB_PARAMS_NAMES width, height, user_data
PROXY_GROUP_RETURN(streamrecorder_supported_video_resolution_cb, bool, int width, int height, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*stt_default_language_changed_cb)(void* stt, const char* previous_language, const char* current_language, void* user_data);
#define CB_PARAMS_NAMES stt, previous_language, current_language, user_data
PROXY_GROUP_NON_BLOCKING(stt_default_language_changed_cb, void* stt, const char* previous_language, const char* current_language, void* user_data)
PROXY_GROUP_BLOCKING(stt_default_language_changed_cb, void* stt, const char* previous_language, const char* current_language, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*stt_engine_changed_cb)(void* stt, const char* engine_id, const char* language, bool support_silence, bool need_credential, void* user_data);
#define CB_PARAMS_NAMES stt, engine_id, language, support_silence, need_credential, user_data
PROXY_GROUP_NON_BLOCKING(stt_engine_changed_cb, void* stt, const char* engine_id, const char* language, bool support_silence, bool need_credential, void* user_data)
PROXY_GROUP_BLOCKING(stt_engine_changed_cb, void* stt, const char* engine_id, const char* language, bool support_silence, bool need_credential, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*stt_error_cb)(void* stt, some_enum reason, void* user_data);
#define CB_PARAMS_NAMES stt, reason, user_data
PROXY_GROUP_NON_BLOCKING(stt_error_cb, void* stt, some_enum reason, void* user_data)
PROXY_GROUP_BLOCKING(stt_error_cb, void* stt, some_enum reason, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*stt_recognition_result_cb)(void* stt, some_enum event, const char** data, int data_count, const char* msg, void* user_data);
#define CB_PARAMS_NAMES stt, event, data, data_count, msg, user_data
PROXY_GROUP_NON_BLOCKING(stt_recognition_result_cb, void* stt, some_enum event, const char** data, int data_count, const char* msg, void* user_data)
PROXY_GROUP_BLOCKING(stt_recognition_result_cb, void* stt, some_enum event, const char** data, int data_count, const char* msg, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*stt_result_time_cb)(void* stt, int index, some_enum event, const char* text, long start_time, long end_time, void* user_data);
#define CB_PARAMS_NAMES stt, index, event, text, start_time, end_time, user_data
PROXY_GROUP_RETURN(stt_result_time_cb, bool, void* stt, int index, some_enum event, const char* text, long start_time, long end_time, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*stt_speech_status_cb)(void* stt, some_enum status, void* user_data);
#define CB_PARAMS_NAMES stt, status, user_data
PROXY_GROUP_NON_BLOCKING(stt_speech_status_cb, void* stt, some_enum status, void* user_data)
PROXY_GROUP_BLOCKING(stt_speech_status_cb, void* stt, some_enum status, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*stt_state_changed_cb)(void* stt, some_enum previous, some_enum current, void* user_data);
#define CB_PARAMS_NAMES stt, previous, current, user_data
PROXY_GROUP_NON_BLOCKING(stt_state_changed_cb, void* stt, some_enum previous, some_enum current, void* user_data)
PROXY_GROUP_BLOCKING(stt_state_changed_cb, void* stt, some_enum previous, some_enum current, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*stt_supported_engine_cb)(void* stt, const char* engine_id, const char* engine_name, void* user_data);
#define CB_PARAMS_NAMES stt, engine_id, engine_name, user_data
PROXY_GROUP_RETURN(stt_supported_engine_cb, bool, void* stt, const char* engine_id, const char* engine_name, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*stt_supported_language_cb)(void* stt, const char* language, void* user_data);
#define CB_PARAMS_NAMES stt, language, user_data
PROXY_GROUP_RETURN(stt_supported_language_cb, bool, void* stt, const char* language, void* user_data)
#undef CB_PARAMS_NAMES

typedef int (*stte_audio_type_cb)(const char* audio_type, void* user_data);
#define CB_PARAMS_NAMES audio_type, user_data
PROXY_GROUP_RETURN(stte_audio_type_cb, int, const char* audio_type, void* user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_stte_cancel_cb 10
typedef int (*stte_cancel_cb)();
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(stte_cancel_cb, int)

#define BASE_CALLBACK_ID_stte_check_app_agreed_cb 15
typedef int (*stte_check_app_agreed_cb)(const char* appid, bool* is_agreed);
#define CB_PARAMS_NAMES appid, is_agreed
PROXY_GROUP_RETURN_NO_USER_DATA(stte_check_app_agreed_cb, int, const char* appid, bool* is_agreed)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_stte_deinitialize_cb 20
typedef int (*stte_deinitialize_cb)();
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(stte_deinitialize_cb, int)

typedef int (*stte_foreach_result_time_cb)(void* time_info, void* callback, void* user_data);
#define CB_PARAMS_NAMES time_info, callback, user_data
PROXY_GROUP_RETURN(stte_foreach_result_time_cb, int, void* time_info, void* callback, void* user_data)
#undef CB_PARAMS_NAMES

typedef int (*stte_foreach_supported_langs_cb)(void* callback, void* user_data);
#define CB_PARAMS_NAMES callback, user_data
PROXY_GROUP_RETURN(stte_foreach_supported_langs_cb, int, void* callback, void* user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_stte_get_info_cb 25
typedef int (*stte_get_info_cb)(char** engine_uuid, char** engine_name, char** engine_setting, bool* use_network);
#define CB_PARAMS_NAMES engine_uuid, engine_name, engine_setting, use_network
PROXY_GROUP_RETURN_NO_USER_DATA(stte_get_info_cb, int, char** engine_uuid, char** engine_name, char** engine_setting, bool* use_network)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_stte_get_recording_format_cb 30
typedef int (*stte_get_recording_format_cb)(void* types, int* rate, int* channels);
#define CB_PARAMS_NAMES types, rate, channels
PROXY_GROUP_RETURN_NO_USER_DATA(stte_get_recording_format_cb, int, void* types, int* rate, int* channels)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_stte_initialize_cb 35
typedef int (*stte_initialize_cb)();
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(stte_initialize_cb, int)

#define BASE_CALLBACK_ID_stte_is_valid_language_cb 40
typedef int (*stte_is_valid_language_cb)(const char* language, bool* is_valid);
#define CB_PARAMS_NAMES language, is_valid
PROXY_GROUP_RETURN_NO_USER_DATA(stte_is_valid_language_cb, int, const char* language, bool* is_valid)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_stte_need_app_credential_cb 45
typedef bool (*stte_need_app_credential_cb)();
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(stte_need_app_credential_cb, bool)

#define BASE_CALLBACK_ID_stte_private_data_requested_cb 50
typedef int (*stte_private_data_requested_cb)(const char* key, char** data);
#define CB_PARAMS_NAMES key, data
PROXY_GROUP_RETURN_NO_USER_DATA(stte_private_data_requested_cb, int, const char* key, char** data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_stte_private_data_set_cb 55
typedef int (*stte_private_data_set_cb)(const char* key, const char* data);
#define CB_PARAMS_NAMES key, data
PROXY_GROUP_RETURN_NO_USER_DATA(stte_private_data_set_cb, int, const char* key, const char* data)
#undef CB_PARAMS_NAMES

typedef bool (*stte_result_time_cb)(int index, some_enum event, const char* text, long start_time, long end_time, void* user_data);
#define CB_PARAMS_NAMES index, event, text, start_time, end_time, user_data
PROXY_GROUP_RETURN(stte_result_time_cb, bool, int index, some_enum event, const char* text, long start_time, long end_time, void* user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_stte_set_recording_data_cb 60
typedef int (*stte_set_recording_data_cb)(const void* data, unsigned int length);
#define CB_PARAMS_NAMES data, length
PROXY_GROUP_RETURN_NO_USER_DATA(stte_set_recording_data_cb, int, const void* data, unsigned int length)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_stte_set_silence_detection_cb 65
typedef int (*stte_set_silence_detection_cb)(bool is_set);
#define CB_PARAMS_NAMES is_set
PROXY_GROUP_RETURN_NO_USER_DATA(stte_set_silence_detection_cb, int, bool is_set)
#undef CB_PARAMS_NAMES

typedef int (*stte_start_cb)(const char* language, const char* type, const char* appid, const char* credential, void* user_data);
#define CB_PARAMS_NAMES language, type, appid, credential, user_data
PROXY_GROUP_RETURN(stte_start_cb, int, const char* language, const char* type, const char* appid, const char* credential, void* user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_stte_stop_cb 70
typedef int (*stte_stop_cb)();
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(stte_stop_cb, int)

#define BASE_CALLBACK_ID_stte_support_recognition_type_cb 75
typedef int (*stte_support_recognition_type_cb)(const char* type, bool* is_supported);
#define CB_PARAMS_NAMES type, is_supported
PROXY_GROUP_RETURN_NO_USER_DATA(stte_support_recognition_type_cb, int, const char* type, bool* is_supported)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_stte_support_silence_detection_cb 80
typedef bool (*stte_support_silence_detection_cb)();
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(stte_support_silence_detection_cb, bool)

typedef bool (*stte_supported_language_cb)(const char* language, void* user_data);
#define CB_PARAMS_NAMES language, user_data
PROXY_GROUP_RETURN(stte_supported_language_cb, bool, const char* language, void* user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_sync_adapter_cancel_sync_cb 85
typedef void (*sync_adapter_cancel_sync_cb)(void* account, const char* sync_job_name, const char* sync_capability, void* sync_job_user_data);
#define CB_PARAMS_NAMES account, sync_job_name, sync_capability, sync_job_user_data
PROXY_GROUP_NON_BLOCKING_NO_USER_DATA(sync_adapter_cancel_sync_cb, void* account, const char* sync_job_name, const char* sync_capability, void* sync_job_user_data)
PROXY_GROUP_BLOCKING_NO_USER_DATA(sync_adapter_cancel_sync_cb, void* account, const char* sync_job_name, const char* sync_capability, void* sync_job_user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_sync_adapter_start_sync_cb 90
typedef bool (*sync_adapter_start_sync_cb)(void* account, const char* sync_job_name, const char* sync_capability, void* sync_job_user_data);
#define CB_PARAMS_NAMES account, sync_job_name, sync_capability, sync_job_user_data
PROXY_GROUP_RETURN_NO_USER_DATA(sync_adapter_start_sync_cb, bool, void* account, const char* sync_job_name, const char* sync_capability, void* sync_job_user_data)
#undef CB_PARAMS_NAMES

typedef bool (*sync_manager_sync_job_cb)(void* account, const char* sync_job_name, const char* sync_capability, int sync_job_id, void* sync_job_user_data, void* user_data);
#define CB_PARAMS_NAMES account, sync_job_name, sync_capability, sync_job_id, sync_job_user_data, user_data
PROXY_GROUP_RETURN(sync_manager_sync_job_cb, bool, void* account, const char* sync_job_name, const char* sync_capability, int sync_job_id, void* sync_job_user_data, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*system_settings_changed_cb)(some_enum key, void* user_data);
#define CB_PARAMS_NAMES key, user_data
PROXY_GROUP_NON_BLOCKING(system_settings_changed_cb, some_enum key, void* user_data)
PROXY_GROUP_BLOCKING(system_settings_changed_cb, some_enum key, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*system_settings_iter_cb)(int index, const char* value, void* user_data);
#define CB_PARAMS_NAMES index, value, user_data
PROXY_GROUP_RETURN(system_settings_iter_cb, bool, int index, const char* value, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*tts_default_voice_changed_cb)(void* tts, const char* previous_language, int previous_voice_type, const char* current_language, int current_voice_type, void* user_data);
#define CB_PARAMS_NAMES tts, previous_language, previous_voice_type, current_language, current_voice_type, user_data
PROXY_GROUP_NON_BLOCKING(tts_default_voice_changed_cb, void* tts, const char* previous_language, int previous_voice_type, const char* current_language, int current_voice_type, void* user_data)
PROXY_GROUP_BLOCKING(tts_default_voice_changed_cb, void* tts, const char* previous_language, int previous_voice_type, const char* current_language, int current_voice_type, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*tts_engine_changed_cb)(void* tts, const char* engine_id, const char* language, int voice_type, bool need_credential, void* user_data);
#define CB_PARAMS_NAMES tts, engine_id, language, voice_type, need_credential, user_data
PROXY_GROUP_NON_BLOCKING(tts_engine_changed_cb, void* tts, const char* engine_id, const char* language, int voice_type, bool need_credential, void* user_data)
PROXY_GROUP_BLOCKING(tts_engine_changed_cb, void* tts, const char* engine_id, const char* language, int voice_type, bool need_credential, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*tts_error_cb)(void* tts, int utt_id, some_enum reason, void* user_data);
#define CB_PARAMS_NAMES tts, utt_id, reason, user_data
PROXY_GROUP_NON_BLOCKING(tts_error_cb, void* tts, int utt_id, some_enum reason, void* user_data)
PROXY_GROUP_BLOCKING(tts_error_cb, void* tts, int utt_id, some_enum reason, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*tts_screen_reader_changed_cb)(void* tts, bool is_on, void* user_data);
#define CB_PARAMS_NAMES tts, is_on, user_data
PROXY_GROUP_NON_BLOCKING(tts_screen_reader_changed_cb, void* tts, bool is_on, void* user_data)
PROXY_GROUP_BLOCKING(tts_screen_reader_changed_cb, void* tts, bool is_on, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*tts_service_state_changed_cb)(void* tts, some_enum previous, some_enum current, void* user_data);
#define CB_PARAMS_NAMES tts, previous, current, user_data
PROXY_GROUP_NON_BLOCKING(tts_service_state_changed_cb, void* tts, some_enum previous, some_enum current, void* user_data)
PROXY_GROUP_BLOCKING(tts_service_state_changed_cb, void* tts, some_enum previous, some_enum current, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*tts_state_changed_cb)(void* tts, some_enum previous, some_enum current, void* user_data);
#define CB_PARAMS_NAMES tts, previous, current, user_data
PROXY_GROUP_NON_BLOCKING(tts_state_changed_cb, void* tts, some_enum previous, some_enum current, void* user_data)
PROXY_GROUP_BLOCKING(tts_state_changed_cb, void* tts, some_enum previous, some_enum current, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*tts_supported_voice_cb)(void* tts, const char* language, int voice_type, void* user_data);
#define CB_PARAMS_NAMES tts, language, voice_type, user_data
PROXY_GROUP_RETURN(tts_supported_voice_cb, bool, void* tts, const char* language, int voice_type, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*tts_utterance_completed_cb)(void* tts, int utt_id, void* user_data);
#define CB_PARAMS_NAMES tts, utt_id, user_data
PROXY_GROUP_NON_BLOCKING(tts_utterance_completed_cb, void* tts, int utt_id, void* user_data)
PROXY_GROUP_BLOCKING(tts_utterance_completed_cb, void* tts, int utt_id, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*tts_utterance_started_cb)(void* tts, int utt_id, void* user_data);
#define CB_PARAMS_NAMES tts, utt_id, user_data
PROXY_GROUP_NON_BLOCKING(tts_utterance_started_cb, void* tts, int utt_id, void* user_data)
PROXY_GROUP_BLOCKING(tts_utterance_started_cb, void* tts, int utt_id, void* user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_ttse_activated_mode_changed_cb 95
typedef void (*ttse_activated_mode_changed_cb)(int activated_mode);
#define CB_PARAMS_NAMES activated_mode
PROXY_GROUP_NON_BLOCKING_NO_USER_DATA(ttse_activated_mode_changed_cb, int activated_mode)
PROXY_GROUP_BLOCKING_NO_USER_DATA(ttse_activated_mode_changed_cb, int activated_mode)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_ttse_cancel_synthesis_cb 100
typedef int (*ttse_cancel_synthesis_cb)();
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(ttse_cancel_synthesis_cb, int)

#define BASE_CALLBACK_ID_ttse_check_app_agreed_cb 105
typedef int (*ttse_check_app_agreed_cb)(const char* appid, bool* is_agreed);
#define CB_PARAMS_NAMES appid, is_agreed
PROXY_GROUP_RETURN_NO_USER_DATA(ttse_check_app_agreed_cb, int, const char* appid, bool* is_agreed)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_ttse_deinitialize_cb 110
typedef int (*ttse_deinitialize_cb)();
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(ttse_deinitialize_cb, int)

typedef int (*ttse_foreach_supported_voices_cb)(void* callback, void* user_data);
#define CB_PARAMS_NAMES callback, user_data
PROXY_GROUP_RETURN(ttse_foreach_supported_voices_cb, int, void* callback, void* user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_ttse_get_info_cb 115
typedef int (*ttse_get_info_cb)(char** engine_uuid, char** engine_name, char** engine_setting, bool* use_network);
#define CB_PARAMS_NAMES engine_uuid, engine_name, engine_setting, use_network
PROXY_GROUP_RETURN_NO_USER_DATA(ttse_get_info_cb, int, char** engine_uuid, char** engine_name, char** engine_setting, bool* use_network)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_ttse_initialize_cb 120
typedef int (*ttse_initialize_cb)();
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(ttse_initialize_cb, int)

#define BASE_CALLBACK_ID_ttse_is_valid_voice_cb 125
typedef int (*ttse_is_valid_voice_cb)(const char* language, int type, bool* is_valid);
#define CB_PARAMS_NAMES language, type, is_valid
PROXY_GROUP_RETURN_NO_USER_DATA(ttse_is_valid_voice_cb, int, const char* language, int type, bool* is_valid)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_ttse_load_voice_cb 130
typedef int (*ttse_load_voice_cb)(const char* language, int type);
#define CB_PARAMS_NAMES language, type
PROXY_GROUP_RETURN_NO_USER_DATA(ttse_load_voice_cb, int, const char* language, int type)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_ttse_need_app_credential_cb 135
typedef bool (*ttse_need_app_credential_cb)();
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(ttse_need_app_credential_cb, bool)

#define BASE_CALLBACK_ID_ttse_private_data_requested_cb 140
typedef int (*ttse_private_data_requested_cb)(const char* key, char** data);
#define CB_PARAMS_NAMES key, data
PROXY_GROUP_RETURN_NO_USER_DATA(ttse_private_data_requested_cb, int, const char* key, char** data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_ttse_private_data_set_cb 145
typedef int (*ttse_private_data_set_cb)(const char* key, const char* data);
#define CB_PARAMS_NAMES key, data
PROXY_GROUP_RETURN_NO_USER_DATA(ttse_private_data_set_cb, int, const char* key, const char* data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_ttse_set_pitch_cb 150
typedef int (*ttse_set_pitch_cb)(int pitch);
#define CB_PARAMS_NAMES pitch
PROXY_GROUP_RETURN_NO_USER_DATA(ttse_set_pitch_cb, int, int pitch)
#undef CB_PARAMS_NAMES

typedef int (*ttse_start_synthesis_cb)(const char* language, int type, const char* text, int speed, const char* appid, const char* credential, void* user_data);
#define CB_PARAMS_NAMES language, type, text, speed, appid, credential, user_data
PROXY_GROUP_RETURN(ttse_start_synthesis_cb, int, const char* language, int type, const char* text, int speed, const char* appid, const char* credential, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*ttse_supported_voice_cb)(const char* language, int type, void* user_data);
#define CB_PARAMS_NAMES language, type, user_data
PROXY_GROUP_RETURN(ttse_supported_voice_cb, bool, const char* language, int type, void* user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_ttse_unload_voice_cb 155
typedef int (*ttse_unload_voice_cb)(const char* language, int type);
#define CB_PARAMS_NAMES language, type
PROXY_GROUP_RETURN_NO_USER_DATA(ttse_unload_voice_cb, int, const char* language, int type)
#undef CB_PARAMS_NAMES

typedef void (*usb_host_hotplug_cb)(void* dev, void* user_data);
#define CB_PARAMS_NAMES dev, user_data
PROXY_GROUP_NON_BLOCKING(usb_host_hotplug_cb, void* dev, void* user_data)
PROXY_GROUP_BLOCKING(usb_host_hotplug_cb, void* dev, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*usb_host_transferred_cb)(void* transfer, void* user_data);
#define CB_PARAMS_NAMES transfer, user_data
PROXY_GROUP_NON_BLOCKING(usb_host_transferred_cb, void* transfer, void* user_data)
PROXY_GROUP_BLOCKING(usb_host_transferred_cb, void* transfer, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*vc_mgr_all_result_cb)(some_enum event, void* vc_cmd_list, const char* result, const char* msg, void* user_data);
#define CB_PARAMS_NAMES event, vc_cmd_list, result, msg, user_data
PROXY_GROUP_RETURN(vc_mgr_all_result_cb, bool, some_enum event, void* vc_cmd_list, const char* result, const char* msg, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*vc_mgr_begin_speech_detected_cb)(void* user_data);
#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(vc_mgr_begin_speech_detected_cb, void* user_data)
PROXY_GROUP_BLOCKING(vc_mgr_begin_speech_detected_cb, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*vc_mgr_dialog_request_cb)(int pid, const char* disp_text, const char* utt_text, bool continuous, void* user_data);
#define CB_PARAMS_NAMES pid, disp_text, utt_text, continuous, user_data
PROXY_GROUP_NON_BLOCKING(vc_mgr_dialog_request_cb, int pid, const char* disp_text, const char* utt_text, bool continuous, void* user_data)
PROXY_GROUP_BLOCKING(vc_mgr_dialog_request_cb, int pid, const char* disp_text, const char* utt_text, bool continuous, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*vc_mgr_feedback_audio_format_cb)(int rate, some_enum channel, some_enum audio_type, void* user_data);
#define CB_PARAMS_NAMES rate, channel, audio_type, user_data
PROXY_GROUP_NON_BLOCKING(vc_mgr_feedback_audio_format_cb, int rate, some_enum channel, some_enum audio_type, void* user_data)
PROXY_GROUP_BLOCKING(vc_mgr_feedback_audio_format_cb, int rate, some_enum channel, some_enum audio_type, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*vc_mgr_feedback_streaming_cb)(some_enum event, char* buffer, int len, void* user_data);
#define CB_PARAMS_NAMES event, buffer, len, user_data
PROXY_GROUP_NON_BLOCKING(vc_mgr_feedback_streaming_cb, some_enum event, char* buffer, int len, void* user_data)
PROXY_GROUP_BLOCKING(vc_mgr_feedback_streaming_cb, some_enum event, char* buffer, int len, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*vc_mgr_pre_result_cb)(some_enum event, const char* result, void* user_data);
#define CB_PARAMS_NAMES event, result, user_data
PROXY_GROUP_NON_BLOCKING(vc_mgr_pre_result_cb, some_enum event, const char* result, void* user_data)
PROXY_GROUP_BLOCKING(vc_mgr_pre_result_cb, some_enum event, const char* result, void* user_data)
#undef CB_PARAMS_NAMES

typedef int (*vc_mgr_private_data_requested_cb)(const char* key, char** data, void* user_data);
#define CB_PARAMS_NAMES key, data, user_data
PROXY_GROUP_RETURN(vc_mgr_private_data_requested_cb, int, const char* key, char** data, void* user_data)
#undef CB_PARAMS_NAMES

typedef int (*vc_mgr_private_data_set_cb)(const char* key, const char* data, void* user_data);
#define CB_PARAMS_NAMES key, data, user_data
PROXY_GROUP_RETURN(vc_mgr_private_data_set_cb, int, const char* key, const char* data, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*vc_mgr_specific_engine_result_cb)(const char* engine_app_id, const char* event, const char* result, void* user_data);
#define CB_PARAMS_NAMES engine_app_id, event, result, user_data
PROXY_GROUP_NON_BLOCKING(vc_mgr_specific_engine_result_cb, const char* engine_app_id, const char* event, const char* result, void* user_data)
PROXY_GROUP_BLOCKING(vc_mgr_specific_engine_result_cb, const char* engine_app_id, const char* event, const char* result, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*vc_mgr_vc_tts_streaming_cb)(int pid, int utt_id, some_enum event, char* buffer, int len, void* user_data);
#define CB_PARAMS_NAMES pid, utt_id, event, buffer, len, user_data
PROXY_GROUP_NON_BLOCKING(vc_mgr_vc_tts_streaming_cb, int pid, int utt_id, some_enum event, char* buffer, int len, void* user_data)
PROXY_GROUP_BLOCKING(vc_mgr_vc_tts_streaming_cb, int pid, int utt_id, some_enum event, char* buffer, int len, void* user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_cancel_cb 160
typedef int (*vce_cancel_cb)();
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(vce_cancel_cb, int)

typedef int (*vce_cancel_tts_cb)(int pid, int utt_id, void* user_data);
#define CB_PARAMS_NAMES pid, utt_id, user_data
PROXY_GROUP_RETURN(vce_cancel_tts_cb, int, int pid, int utt_id, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*vce_command_cb)(int id, int type, int format, const char* command, const char* param, int domain, void* user_data);
#define CB_PARAMS_NAMES id, type, format, command, param, domain, user_data
PROXY_GROUP_RETURN(vce_command_cb, bool, int id, int type, int format, const char* command, const char* param, int domain, void* user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_deinitialize_cb 165
typedef int (*vce_deinitialize_cb)();
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(vce_deinitialize_cb, int)

typedef int (*vce_foreach_supported_languages_cb)(void* callback, void* user_data);
#define CB_PARAMS_NAMES callback, user_data
PROXY_GROUP_RETURN(vce_foreach_supported_languages_cb, int, void* callback, void* user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_get_info_cb 170
typedef int (*vce_get_info_cb)(char** engine_uuid, char** engine_name, char** engine_settings_app_id, bool* use_network);
#define CB_PARAMS_NAMES engine_uuid, engine_name, engine_settings_app_id, use_network
PROXY_GROUP_RETURN_NO_USER_DATA(vce_get_info_cb, int, char** engine_uuid, char** engine_name, char** engine_settings_app_id, bool* use_network)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_get_recording_format_cb 175
typedef int (*vce_get_recording_format_cb)(const char* audio_id, void* types, int* rate, int* channels);
#define CB_PARAMS_NAMES audio_id, types, rate, channels
PROXY_GROUP_RETURN_NO_USER_DATA(vce_get_recording_format_cb, int, const char* audio_id, void* types, int* rate, int* channels)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_initialize_cb 180
typedef int (*vce_initialize_cb)();
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(vce_initialize_cb, int)

#define BASE_CALLBACK_ID_vce_is_language_supported_cb 185
typedef bool (*vce_is_language_supported_cb)(const char* language);
#define CB_PARAMS_NAMES language
PROXY_GROUP_RETURN_NO_USER_DATA(vce_is_language_supported_cb, bool, const char* language)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_nlu_base_info_requested_cb 190
typedef int (*vce_nlu_base_info_requested_cb)(const char* key, char** value);
#define CB_PARAMS_NAMES key, value
PROXY_GROUP_RETURN_NO_USER_DATA(vce_nlu_base_info_requested_cb, int, const char* key, char** value)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_private_data_requested_cb 195
typedef int (*vce_private_data_requested_cb)(const char* key, char** data);
#define CB_PARAMS_NAMES key, data
PROXY_GROUP_RETURN_NO_USER_DATA(vce_private_data_requested_cb, int, const char* key, char** data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_private_data_set_cb 200
typedef int (*vce_private_data_set_cb)(const char* key, const char* data);
#define CB_PARAMS_NAMES key, data
PROXY_GROUP_RETURN_NO_USER_DATA(vce_private_data_set_cb, int, const char* key, const char* data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_process_haptic_event_cb 205
typedef int (*vce_process_haptic_event_cb)(const char* event);
#define CB_PARAMS_NAMES event
PROXY_GROUP_RETURN_NO_USER_DATA(vce_process_haptic_event_cb, int, const char* event)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_process_list_event_cb 210
typedef int (*vce_process_list_event_cb)(const char* event);
#define CB_PARAMS_NAMES event
PROXY_GROUP_RETURN_NO_USER_DATA(vce_process_list_event_cb, int, const char* event)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_process_text_cb 215
typedef int (*vce_process_text_cb)(const char* text);
#define CB_PARAMS_NAMES text
PROXY_GROUP_RETURN_NO_USER_DATA(vce_process_text_cb, int, const char* text)
#undef CB_PARAMS_NAMES

typedef int (*vce_request_tts_cb)(int pid, int utt_id, const char* text, const char* language, void* user_data);
#define CB_PARAMS_NAMES pid, utt_id, text, language, user_data
PROXY_GROUP_RETURN(vce_request_tts_cb, int, int pid, int utt_id, const char* text, const char* language, void* user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_set_audio_type_cb 220
typedef int (*vce_set_audio_type_cb)(const char* audio_type);
#define CB_PARAMS_NAMES audio_type
PROXY_GROUP_RETURN_NO_USER_DATA(vce_set_audio_type_cb, int, const char* audio_type)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_set_commands_cb 225
typedef int (*vce_set_commands_cb)(void* vc_command);
#define CB_PARAMS_NAMES vc_command
PROXY_GROUP_RETURN_NO_USER_DATA(vce_set_commands_cb, int, void* vc_command)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_set_domain_cb 230
typedef int (*vce_set_domain_cb)(const char* domain);
#define CB_PARAMS_NAMES domain
PROXY_GROUP_RETURN_NO_USER_DATA(vce_set_domain_cb, int, const char* domain)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_set_language_cb 235
typedef int (*vce_set_language_cb)(const char* language);
#define CB_PARAMS_NAMES language
PROXY_GROUP_RETURN_NO_USER_DATA(vce_set_language_cb, int, const char* language)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_set_recording_data_cb 240
typedef int (*vce_set_recording_data_cb)(const void* data, unsigned int length, void* speech_detected);
#define CB_PARAMS_NAMES data, length, speech_detected
PROXY_GROUP_RETURN_NO_USER_DATA(vce_set_recording_data_cb, int, const void* data, unsigned int length, void* speech_detected)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_set_server_dialog_cb 245
typedef int (*vce_set_server_dialog_cb)(const char* app_id, const char* credential);
#define CB_PARAMS_NAMES app_id, credential
PROXY_GROUP_RETURN_NO_USER_DATA(vce_set_server_dialog_cb, int, const char* app_id, const char* credential)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_specific_engine_request_cb 250
typedef int (*vce_specific_engine_request_cb)(const char* engine_app_id, const char* event, const char* request);
#define CB_PARAMS_NAMES engine_app_id, event, request
PROXY_GROUP_RETURN_NO_USER_DATA(vce_specific_engine_request_cb, int, const char* engine_app_id, const char* event, const char* request)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_start_cb 255
typedef int (*vce_start_cb)(bool stop_by_silence);
#define CB_PARAMS_NAMES stop_by_silence
PROXY_GROUP_RETURN_NO_USER_DATA(vce_start_cb, int, bool stop_by_silence)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_stop_cb 260
typedef int (*vce_stop_cb)();
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(vce_stop_cb, int)

typedef bool (*vce_supported_language_cb)(const char* language, void* user_data);
#define CB_PARAMS_NAMES language, user_data
PROXY_GROUP_RETURN(vce_supported_language_cb, bool, const char* language, void* user_data)
#undef CB_PARAMS_NAMES

typedef int (*vce_tts_audio_format_request_cb)(int* rate, int* channel, int* audio_type, void* user_data);
#define CB_PARAMS_NAMES rate, channel, audio_type, user_data
PROXY_GROUP_RETURN(vce_tts_audio_format_request_cb, int, int* rate, int* channel, int* audio_type, void* user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_unset_commands_cb 265
typedef int (*vce_unset_commands_cb)();
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(vce_unset_commands_cb, int)

typedef void (*wav_player_playback_completed_cb)(int id, void* user_data);
#define CB_PARAMS_NAMES id, user_data
PROXY_GROUP_NON_BLOCKING(wav_player_playback_completed_cb, int id, void* user_data)
PROXY_GROUP_BLOCKING(wav_player_playback_completed_cb, int id, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*webrtc_data_channel_buffered_amount_low_cb)(void* channel, void* user_data);
#define CB_PARAMS_NAMES channel, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_data_channel_buffered_amount_low_cb, void* channel, void* user_data)
PROXY_GROUP_BLOCKING(webrtc_data_channel_buffered_amount_low_cb, void* channel, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*webrtc_data_channel_cb)(void* webrtc, void* channel, void* user_data);
#define CB_PARAMS_NAMES webrtc, channel, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_data_channel_cb, void* webrtc, void* channel, void* user_data)
PROXY_GROUP_BLOCKING(webrtc_data_channel_cb, void* webrtc, void* channel, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*webrtc_data_channel_close_cb)(void* channel, void* user_data);
#define CB_PARAMS_NAMES channel, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_data_channel_close_cb, void* channel, void* user_data)
PROXY_GROUP_BLOCKING(webrtc_data_channel_close_cb, void* channel, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*webrtc_data_channel_error_cb)(void* channel, some_enum error, void* user_data);
#define CB_PARAMS_NAMES channel, error, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_data_channel_error_cb, void* channel, some_enum error, void* user_data)
PROXY_GROUP_BLOCKING(webrtc_data_channel_error_cb, void* channel, some_enum error, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*webrtc_data_channel_message_cb)(void* channel, some_enum type, void* message, void* user_data);
#define CB_PARAMS_NAMES channel, type, message, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_data_channel_message_cb, void* channel, some_enum type, void* message, void* user_data)
PROXY_GROUP_BLOCKING(webrtc_data_channel_message_cb, void* channel, some_enum type, void* message, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*webrtc_data_channel_open_cb)(void* channel, void* user_data);
#define CB_PARAMS_NAMES channel, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_data_channel_open_cb, void* channel, void* user_data)
PROXY_GROUP_BLOCKING(webrtc_data_channel_open_cb, void* channel, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*webrtc_encoded_frame_cb)(void* webrtc, some_enum type, unsigned int track_id, void* packet, void* user_data);
#define CB_PARAMS_NAMES webrtc, type, track_id, packet, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_encoded_frame_cb, void* webrtc, some_enum type, unsigned int track_id, void* packet, void* user_data)
PROXY_GROUP_BLOCKING(webrtc_encoded_frame_cb, void* webrtc, some_enum type, unsigned int track_id, void* packet, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*webrtc_error_cb)(void* webrtc, some_enum error, some_enum state, void* user_data);
#define CB_PARAMS_NAMES webrtc, error, state, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_error_cb, void* webrtc, some_enum error, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(webrtc_error_cb, void* webrtc, some_enum error, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*webrtc_ice_candidate_cb)(void* webrtc, const char* candidate, void* user_data);
#define CB_PARAMS_NAMES webrtc, candidate, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_ice_candidate_cb, void* webrtc, const char* candidate, void* user_data)
PROXY_GROUP_BLOCKING(webrtc_ice_candidate_cb, void* webrtc, const char* candidate, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*webrtc_ice_connection_state_change_cb)(void* webrtc, some_enum state, void* user_data);
#define CB_PARAMS_NAMES webrtc, state, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_ice_connection_state_change_cb, void* webrtc, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(webrtc_ice_connection_state_change_cb, void* webrtc, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*webrtc_ice_gathering_state_change_cb)(void* webrtc, some_enum state, void* user_data);
#define CB_PARAMS_NAMES webrtc, state, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_ice_gathering_state_change_cb, void* webrtc, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(webrtc_ice_gathering_state_change_cb, void* webrtc, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*webrtc_media_packet_source_buffer_state_changed_cb)(unsigned int source_id, some_enum state, void* user_data);
#define CB_PARAMS_NAMES source_id, state, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_media_packet_source_buffer_state_changed_cb, unsigned int source_id, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(webrtc_media_packet_source_buffer_state_changed_cb, unsigned int source_id, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*webrtc_media_source_supported_transceiver_codec_cb)(some_enum codec, void* user_data);
#define CB_PARAMS_NAMES codec, user_data
PROXY_GROUP_RETURN(webrtc_media_source_supported_transceiver_codec_cb, bool, some_enum codec, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*webrtc_negotiation_needed_cb)(void* webrtc, void* user_data);
#define CB_PARAMS_NAMES webrtc, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_negotiation_needed_cb, void* webrtc, void* user_data)
PROXY_GROUP_BLOCKING(webrtc_negotiation_needed_cb, void* webrtc, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*webrtc_peer_connection_state_change_cb)(void* webrtc, some_enum state, void* user_data);
#define CB_PARAMS_NAMES webrtc, state, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_peer_connection_state_change_cb, void* webrtc, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(webrtc_peer_connection_state_change_cb, void* webrtc, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*webrtc_session_description_created_cb)(void* webrtc, const char* description, void* user_data);
#define CB_PARAMS_NAMES webrtc, description, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_session_description_created_cb, void* webrtc, const char* description, void* user_data)
PROXY_GROUP_BLOCKING(webrtc_session_description_created_cb, void* webrtc, const char* description, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*webrtc_signaling_state_change_cb)(void* webrtc, some_enum state, void* user_data);
#define CB_PARAMS_NAMES webrtc, state, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_signaling_state_change_cb, void* webrtc, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(webrtc_signaling_state_change_cb, void* webrtc, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*webrtc_state_changed_cb)(void* webrtc, some_enum previous, some_enum current, void* user_data);
#define CB_PARAMS_NAMES webrtc, previous, current, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_state_changed_cb, void* webrtc, some_enum previous, some_enum current, void* user_data)
PROXY_GROUP_BLOCKING(webrtc_state_changed_cb, void* webrtc, some_enum previous, some_enum current, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*webrtc_stats_cb)(some_enum type, const void* prop_info, void* user_data);
#define CB_PARAMS_NAMES type, prop_info, user_data
PROXY_GROUP_RETURN(webrtc_stats_cb, bool, some_enum type, const void* prop_info, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*webrtc_track_added_cb)(void* webrtc, some_enum type, unsigned int track_id, void* user_data);
#define CB_PARAMS_NAMES webrtc, type, track_id, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_track_added_cb, void* webrtc, some_enum type, unsigned int track_id, void* user_data)
PROXY_GROUP_BLOCKING(webrtc_track_added_cb, void* webrtc, some_enum type, unsigned int track_id, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*webrtc_turn_server_cb)(const char* turn_server, void* user_data);
#define CB_PARAMS_NAMES turn_server, user_data
PROXY_GROUP_RETURN(webrtc_turn_server_cb, bool, const char* turn_server, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_direct_client_ip_address_assigned_cb)(const char* mac_address, const char* ip_address, const char* interface_address, void* user_data);
#define CB_PARAMS_NAMES mac_address, ip_address, interface_address, user_data
PROXY_GROUP_NON_BLOCKING(wifi_direct_client_ip_address_assigned_cb, const char* mac_address, const char* ip_address, const char* interface_address, void* user_data)
PROXY_GROUP_BLOCKING(wifi_direct_client_ip_address_assigned_cb, const char* mac_address, const char* ip_address, const char* interface_address, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*wifi_direct_connected_peer_cb)(void* peer, void* user_data);
#define CB_PARAMS_NAMES peer, user_data
PROXY_GROUP_RETURN(wifi_direct_connected_peer_cb, bool, void* peer, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_direct_connection_state_changed_cb)(int error_code, some_enum connection_state, const char* mac_address, void* user_data);
#define CB_PARAMS_NAMES error_code, connection_state, mac_address, user_data
PROXY_GROUP_NON_BLOCKING(wifi_direct_connection_state_changed_cb, int error_code, some_enum connection_state, const char* mac_address, void* user_data)
PROXY_GROUP_BLOCKING(wifi_direct_connection_state_changed_cb, int error_code, some_enum connection_state, const char* mac_address, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_direct_device_state_changed_cb)(int error_code, some_enum device_state, void* user_data);
#define CB_PARAMS_NAMES error_code, device_state, user_data
PROXY_GROUP_NON_BLOCKING(wifi_direct_device_state_changed_cb, int error_code, some_enum device_state, void* user_data)
PROXY_GROUP_BLOCKING(wifi_direct_device_state_changed_cb, int error_code, some_enum device_state, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*wifi_direct_discovered_peer_cb)(void* peer, void* user_data);
#define CB_PARAMS_NAMES peer, user_data
PROXY_GROUP_RETURN(wifi_direct_discovered_peer_cb, bool, void* peer, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_direct_discovery_state_chagned_cb)(int error_code, some_enum discovery_state, void* user_data);
#define CB_PARAMS_NAMES error_code, discovery_state, user_data
PROXY_GROUP_NON_BLOCKING(wifi_direct_discovery_state_chagned_cb, int error_code, some_enum discovery_state, void* user_data)
PROXY_GROUP_BLOCKING(wifi_direct_discovery_state_chagned_cb, int error_code, some_enum discovery_state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_direct_peer_found_cb)(int error_code, some_enum discovery_state, const char* mac_address, void* user_data);
#define CB_PARAMS_NAMES error_code, discovery_state, mac_address, user_data
PROXY_GROUP_NON_BLOCKING(wifi_direct_peer_found_cb, int error_code, some_enum discovery_state, const char* mac_address, void* user_data)
PROXY_GROUP_BLOCKING(wifi_direct_peer_found_cb, int error_code, some_enum discovery_state, const char* mac_address, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_direct_peer_info_connection_state_changed_cb)(some_enum error_code, some_enum connection_state, wifi_direct_connection_state_cb_data_s_copy data_s, void* user_data);
#define CB_PARAMS_NAMES error_code, connection_state, data_s, user_data
PROXY_GROUP_NON_BLOCKING(wifi_direct_peer_info_connection_state_changed_cb, some_enum error_code, some_enum connection_state, wifi_direct_connection_state_cb_data_s_copy data_s, void* user_data)
PROXY_GROUP_BLOCKING(wifi_direct_peer_info_connection_state_changed_cb, some_enum error_code, some_enum connection_state, wifi_direct_connection_state_cb_data_s_copy data_s, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*wifi_direct_persistent_group_cb)(const char* mac_address, const char* ssid, void* user_data);
#define CB_PARAMS_NAMES mac_address, ssid, user_data
PROXY_GROUP_RETURN(wifi_direct_persistent_group_cb, bool, const char* mac_address, const char* ssid, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_direct_service_state_changed_cb)(int error_code, some_enum service_state, some_enum service_type, void* response_data, const char* mac_address, void* user_data);
#define CB_PARAMS_NAMES error_code, service_state, service_type, response_data, mac_address, user_data
PROXY_GROUP_NON_BLOCKING(wifi_direct_service_state_changed_cb, int error_code, some_enum service_state, some_enum service_type, void* response_data, const char* mac_address, void* user_data)
PROXY_GROUP_BLOCKING(wifi_direct_service_state_changed_cb, int error_code, some_enum service_state, some_enum service_type, void* response_data, const char* mac_address, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_direct_state_changed_cb)(some_enum state, void* user_data);
#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(wifi_direct_state_changed_cb, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(wifi_direct_state_changed_cb, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*wifi_direct_supported_wps_type_cb)(some_enum type, void* user_data);
#define CB_PARAMS_NAMES type, user_data
PROXY_GROUP_RETURN(wifi_direct_supported_wps_type_cb, bool, some_enum type, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_manager_activated_cb)(some_enum result, void* user_data);
#define CB_PARAMS_NAMES result, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_activated_cb, some_enum result, void* user_data)
PROXY_GROUP_BLOCKING(wifi_manager_activated_cb, some_enum result, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*wifi_manager_ap_ipv6_address_cb)(char* ipv6_address, void* user_data);
#define CB_PARAMS_NAMES ipv6_address, user_data
PROXY_GROUP_RETURN(wifi_manager_ap_ipv6_address_cb, bool, char* ipv6_address, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*wifi_manager_ap_vsie_cb)(unsigned char* vsie, int length, void* user_data);
#define CB_PARAMS_NAMES vsie, length, user_data
PROXY_GROUP_RETURN(wifi_manager_ap_vsie_cb, bool, unsigned char* vsie, int length, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_manager_bssid_scan_finished_cb)(some_enum error_code, void* user_data);
#define CB_PARAMS_NAMES error_code, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_bssid_scan_finished_cb, some_enum error_code, void* user_data)
PROXY_GROUP_BLOCKING(wifi_manager_bssid_scan_finished_cb, some_enum error_code, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*wifi_manager_config_list_cb)(const void* config, void* user_data);
#define CB_PARAMS_NAMES config, user_data
PROXY_GROUP_RETURN(wifi_manager_config_list_cb, bool, const void* config, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_manager_connected_cb)(some_enum result, void* user_data);
#define CB_PARAMS_NAMES result, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_connected_cb, some_enum result, void* user_data)
PROXY_GROUP_BLOCKING(wifi_manager_connected_cb, some_enum result, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_manager_connection_state_changed_cb)(some_enum state, void* ap, void* user_data);
#define CB_PARAMS_NAMES state, ap, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_connection_state_changed_cb, some_enum state, void* ap, void* user_data)
PROXY_GROUP_BLOCKING(wifi_manager_connection_state_changed_cb, some_enum state, void* ap, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_manager_deactivated_cb)(some_enum result, void* user_data);
#define CB_PARAMS_NAMES result, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_deactivated_cb, some_enum result, void* user_data)
PROXY_GROUP_BLOCKING(wifi_manager_deactivated_cb, some_enum result, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_manager_device_state_changed_cb)(some_enum state, void* user_data);
#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_device_state_changed_cb, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(wifi_manager_device_state_changed_cb, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_manager_disconnected_cb)(some_enum result, void* user_data);
#define CB_PARAMS_NAMES result, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_disconnected_cb, some_enum result, void* user_data)
PROXY_GROUP_BLOCKING(wifi_manager_disconnected_cb, some_enum result, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_manager_forget_ap_finished_cb)(some_enum result, void* user_data);
#define CB_PARAMS_NAMES result, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_forget_ap_finished_cb, some_enum result, void* user_data)
PROXY_GROUP_BLOCKING(wifi_manager_forget_ap_finished_cb, some_enum result, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*wifi_manager_found_ap_cb)(void* ap, void* user_data);
#define CB_PARAMS_NAMES ap, user_data
PROXY_GROUP_RETURN(wifi_manager_found_ap_cb, bool, void* ap, void* user_data)
#undef CB_PARAMS_NAMES

typedef bool (*wifi_manager_found_bssid_cb)(const char* bssid, int rssi, int freq, void* user_data);
#define CB_PARAMS_NAMES bssid, rssi, freq, user_data
PROXY_GROUP_RETURN(wifi_manager_found_bssid_cb, bool, const char* bssid, int rssi, int freq, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_manager_ip_conflict_cb)(char* mac, some_enum state, void* user_data);
#define CB_PARAMS_NAMES mac, state, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_ip_conflict_cb, char* mac, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(wifi_manager_ip_conflict_cb, char* mac, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_manager_module_state_changed_cb)(some_enum wifi_module_state, void* user_data);
#define CB_PARAMS_NAMES wifi_module_state, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_module_state_changed_cb, some_enum wifi_module_state, void* user_data)
PROXY_GROUP_BLOCKING(wifi_manager_module_state_changed_cb, some_enum wifi_module_state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_manager_rssi_level_changed_cb)(some_enum rssi_level, void* user_data);
#define CB_PARAMS_NAMES rssi_level, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_rssi_level_changed_cb, some_enum rssi_level, void* user_data)
PROXY_GROUP_BLOCKING(wifi_manager_rssi_level_changed_cb, some_enum rssi_level, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_manager_scan_finished_cb)(some_enum error_code, void* user_data);
#define CB_PARAMS_NAMES error_code, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_scan_finished_cb, some_enum error_code, void* user_data)
PROXY_GROUP_BLOCKING(wifi_manager_scan_finished_cb, some_enum error_code, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_manager_scan_state_changed_cb)(some_enum state, void* user_data);
#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_scan_state_changed_cb, some_enum state, void* user_data)
PROXY_GROUP_BLOCKING(wifi_manager_scan_state_changed_cb, some_enum state, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_manager_tdls_discovered_cb)(some_enum state, char* peer_mac_addr, void* user_data);
#define CB_PARAMS_NAMES state, peer_mac_addr, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_tdls_discovered_cb, some_enum state, char* peer_mac_addr, void* user_data)
PROXY_GROUP_BLOCKING(wifi_manager_tdls_discovered_cb, some_enum state, char* peer_mac_addr, void* user_data)
#undef CB_PARAMS_NAMES

typedef void (*wifi_manager_tdls_state_changed_cb)(some_enum state, char* peer_mac_addr, void* user_data);
#define CB_PARAMS_NAMES state, peer_mac_addr, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_tdls_state_changed_cb, some_enum state, char* peer_mac_addr, void* user_data)
PROXY_GROUP_BLOCKING(wifi_manager_tdls_state_changed_cb, some_enum state, char* peer_mac_addr, void* user_data)
#undef CB_PARAMS_NAMES


std::map<std::string, MultiProxyFunctionsContainer> multi_proxy_map = {
  MULTI_PROXY_MAP_ENTRY(platform_blocking_account_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_account_custom_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_account_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_account_label_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_account_type_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_activity_recognition_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_activity_recognition_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_alarm_registered_alarm_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_control_action_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_app_control_action_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_control_app_matched_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_control_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_app_control_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_control_extra_data_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_control_host_res_fn)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_control_reply_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_app_control_reply_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_control_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_app_control_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_control_uri_query_foreach_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_create_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_app_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_manager_app_context_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_manager_app_context_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_app_manager_app_context_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_manager_app_info_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_manager_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_app_manager_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_pause_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_app_pause_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_resume_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_app_resume_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_terminate_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_app_terminate_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_asp_advert_status_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_asp_advert_status_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_asp_seek_search_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_asp_seek_search_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_asp_session_config_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_asp_session_config_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_asp_session_connect_status_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_asp_session_connect_status_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_asp_session_port_status_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_asp_session_port_status_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_asp_session_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_asp_session_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_asp_session_status_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_asp_session_status_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_audio_in_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_audio_in_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_audio_in_stream_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_audio_in_stream_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_audio_io_interrupted_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_audio_io_interrupted_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_audio_out_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_audio_out_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_audio_out_stream_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_audio_out_stream_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_autofill_auth_info_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_autofill_auth_info_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_autofill_connection_status_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_autofill_connection_status_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_autofill_error_info_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_autofill_error_info_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_autofill_fill_response_group_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_autofill_fill_response_item_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_autofill_fill_response_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_autofill_fill_response_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_autofill_item_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_autofill_manager_autofill_service_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_autofill_manager_connection_status_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_autofill_manager_connection_status_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_autofill_save_item_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_autofill_service_auth_info_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_autofill_service_auth_info_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_autofill_service_cancel_fill_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_autofill_service_cancel_fill_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_autofill_service_committed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_autofill_service_committed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_autofill_service_fill_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_autofill_service_fill_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_autofill_service_terminate_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_autofill_service_terminate_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_badge_change_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_badge_change_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_badge_foreach_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bundle_iterator_t)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bundle_iterator_t)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_attr_hdr_progress_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_camera_attr_hdr_progress_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_attr_supported_af_mode_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_attr_supported_effect_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_attr_supported_exposure_mode_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_attr_supported_flash_mode_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_attr_supported_fps_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_attr_supported_iso_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_attr_supported_ptz_type_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_attr_supported_scene_mode_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_attr_supported_stream_flip_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_attr_supported_stream_rotation_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_attr_supported_theater_mode_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_attr_supported_whitebalance_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_capture_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_camera_capture_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_capturing_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_camera_capturing_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_device_connection_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_camera_device_connection_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_device_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_camera_device_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_camera_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_extra_preview_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_camera_extra_preview_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_face_detected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_camera_face_detected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_focus_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_camera_focus_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_interrupt_started_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_camera_interrupt_started_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_interrupted_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_camera_interrupted_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_media_packet_preview_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_camera_media_packet_preview_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_preview_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_camera_preview_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_camera_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_supported_capture_format_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_supported_capture_resolution_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_supported_device_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_supported_preview_format_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_supported_preview_resolution_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_capability_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cbhm_item_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_cbhm_item_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cbhm_monitor_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_cbhm_monitor_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cbhm_selected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cbhm_selection_data_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_connection_address_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_connection_address_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_connection_closed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_connection_closed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_connection_ethernet_cable_state_chaged_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_connection_ethernet_cable_state_chaged_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_connection_ethernet_cable_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_connection_ethernet_cable_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_connection_internet_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_connection_internet_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_connection_ipv6_address_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_connection_opened_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_connection_opened_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_connection_reset_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_connection_reset_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_connection_set_default_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_connection_set_default_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_connection_type_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_connection_type_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_csr_cs_cancelled_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_csr_cs_cancelled_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_csr_cs_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_csr_cs_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_csr_cs_detected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_csr_cs_detected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_csr_cs_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_csr_cs_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_csr_cs_file_scanned_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_csr_cs_file_scanned_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_device_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_device_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_diagnostics_notification_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_diagnostics_notification_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_diagnostics_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_diagnostics_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_dnssd_found_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_dnssd_found_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_dnssd_registered_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_dnssd_registered_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_dnssd_resolved_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_dnssd_resolved_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_download_progress_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_download_progress_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_download_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_download_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_dpm_policy_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_dpm_policy_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_dpm_signal_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_dpm_signal_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_dpm_zone_foreach_name_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_email_message_sent_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_email_message_sent_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_eom_attribute_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_eom_attribute_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_eom_mode_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_eom_mode_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_eom_output_added_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_eom_output_added_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_eom_output_removed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_eom_output_removed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_fido_attestation_type_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_fido_attestation_type_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_fido_authenticator_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_fido_authenticator_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_fido_uaf_response_message_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_fido_uaf_response_message_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_geofence_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_geofence_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_geofence_manager_fence_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_geofence_manager_place_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_geofence_proximity_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_geofence_proximity_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_geofence_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_geofence_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_gesture_recognition_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_gesture_recognition_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_gps_status_get_satellites_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_gps_status_satellite_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_gps_status_satellite_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_http_transaction_aborted_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_http_transaction_aborted_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_http_transaction_body_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_http_transaction_body_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_http_transaction_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_http_transaction_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_http_transaction_header_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_http_transaction_header_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_http_transaction_progress_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_http_transaction_progress_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_http_transaction_write_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_http_transaction_write_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_image_util_supported_colorspace_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_accessibility_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_accessibility_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_create_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_create_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_cursor_position_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_cursor_position_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_display_language_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_display_language_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_focus_in_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_focus_in_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_focus_out_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_focus_out_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_geometry_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_geometry_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_hide_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_hide_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_imdata_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_imdata_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_imdata_set_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_imdata_set_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_input_context_reset_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_input_context_reset_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_input_hint_set_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_input_hint_set_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_language_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_language_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_language_set_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_language_set_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_layout_set_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_layout_set_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_mime_type_set_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_mime_type_set_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_option_window_created_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_option_window_created_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_option_window_destroyed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_option_window_destroyed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_prediction_hint_data_set_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_prediction_hint_data_set_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_prediction_hint_set_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_prediction_hint_set_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_process_key_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_process_key_event_with_keycode_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_return_key_state_set_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_return_key_state_set_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_return_key_type_set_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_return_key_type_set_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_rotation_degree_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_rotation_degree_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_show_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_show_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_surrounding_text_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_surrounding_text_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ime_terminate_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ime_terminate_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_inm_arp_request_ip_found_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_inm_arp_request_ip_found_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_inm_cellular_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_inm_cellular_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_inm_channel_interference_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_inm_channel_interference_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_inm_congestion_level_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_inm_congestion_level_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_inm_default_dns_lookup_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_inm_default_dns_lookup_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_inm_default_gateway_found_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_inm_default_gateway_found_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_inm_ethernet_cable_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_inm_ethernet_cable_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_inm_ethernet_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_inm_ethernet_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_inm_ip_conflict_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_inm_ip_conflict_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_inm_link_address_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_inm_link_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_inm_link_route_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_inm_reachable_urls_check_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_inm_reachable_urls_check_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_inm_retry_tx_rate_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_inm_retry_tx_rate_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_inm_wifi_ap_vsie_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_inm_wifi_found_ap_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_inm_wifi_module_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_inm_wifi_module_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_inm_wifi_scan_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_inm_wifi_scan_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_inm_wifi_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_inm_wifi_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_generated_pin_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_iotcon_generated_pin_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_job_scheduler_foreach_job_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_job_service_start_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_job_service_start_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_job_service_stop_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_job_service_stop_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_location_batch_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_location_batch_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_location_batch_get_location_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_location_bounds_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_location_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_location_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_location_position_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_location_position_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_location_service_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_location_service_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_location_setting_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_location_setting_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_location_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_location_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_location_velocity_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_location_velocity_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_location_zone_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_location_zone_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ma_active_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ma_active_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ma_assistant_info_list_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ma_audio_streaming_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ma_audio_streaming_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ma_audio_streaming_data_section_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ma_audio_streaming_data_section_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ma_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ma_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ma_language_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ma_language_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ma_preprocessing_information_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ma_preprocessing_information_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ma_service_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ma_service_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ma_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ma_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ma_voice_key_status_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ma_voice_key_status_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ma_wakeup_engine_command_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ma_wakeup_engine_command_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_ability_support_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_ability_support_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_ability_supported_items_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_ability_supported_items_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_activated_client_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_activated_server_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_bool_attribute_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_bool_attribute_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_client_custom_event_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_client_custom_event_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_cmd_reply_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_cmd_reply_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_command_reply_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_command_reply_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_display_mode_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_display_mode_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_display_rotation_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_display_rotation_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_metadata_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_metadata_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_playback_ability_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_playback_ability_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_playback_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_playback_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_playlist_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_playlist_item_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_playlist_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_playlist_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_repeat_ability_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_repeat_ability_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_repeat_mode_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_repeat_mode_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_repeat_mode_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_repeat_mode_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_search_condition_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_server_custom_cmd_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_server_custom_cmd_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_server_custom_command_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_server_custom_command_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_server_display_mode_cmd_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_server_display_mode_cmd_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_server_display_rotation_cmd_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_server_display_rotation_cmd_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_server_enable_cmd_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_server_enable_cmd_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_server_event_reply_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_server_event_reply_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_server_playback_action_cmd_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_server_playback_action_cmd_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_server_playback_position_cmd_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_server_playback_position_cmd_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_server_playback_state_command_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_server_playback_state_command_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_server_playlist_cmd_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_server_playlist_cmd_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_server_repeat_mode_cmd_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_server_repeat_mode_cmd_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_server_search_cmd_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_server_search_cmd_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_server_shuffle_mode_cmd_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_server_shuffle_mode_cmd_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_server_state_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_server_state_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_shuffle_ability_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_shuffle_ability_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_shuffle_mode_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_shuffle_mode_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_shuffle_mode_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_shuffle_mode_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_subscribed_server_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_key_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_media_key_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_packet_dispose_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_media_packet_dispose_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_packet_finalize_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_streamer_custom_buffer_status_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_media_streamer_custom_buffer_status_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_streamer_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_media_streamer_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_streamer_interrupted_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_media_streamer_interrupted_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_streamer_node_decoded_ready_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_media_streamer_node_decoded_ready_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_streamer_position_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_media_streamer_position_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_streamer_sink_data_ready_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_media_streamer_sink_data_ready_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_streamer_sink_eos_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_media_streamer_sink_eos_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_streamer_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_media_streamer_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_streamer_webrtc_message_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_media_streamer_webrtc_message_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mediacodec_buffer_status_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mediacodec_buffer_status_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mediacodec_eos_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mediacodec_eos_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mediacodec_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mediacodec_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mediacodec_input_buffer_used_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mediacodec_input_buffer_used_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mediacodec_output_buffer_available_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mediacodec_output_buffer_available_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mediacodec_supported_codec_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mediademuxer_eos_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mediademuxer_eos_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mediademuxer_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mediademuxer_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mediaeditor_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mediaeditor_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mediaeditor_layer_priority_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mediaeditor_layer_priority_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mediaeditor_project_loaded_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mediaeditor_project_loaded_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mediaeditor_render_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mediaeditor_render_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mediaeditor_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mediaeditor_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mediamuxer_eos_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mediamuxer_eos_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mediamuxer_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mediamuxer_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_message_port_message_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_message_port_message_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_message_port_registration_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_message_port_registration_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_message_port_trusted_message_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_message_port_trusted_message_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ml_custom_easy_invoke_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ml_pipeline_if_custom_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ml_pipeline_sink_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ml_pipeline_sink_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ml_pipeline_state_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ml_pipeline_state_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mtp_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mtp_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_3d_depth_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mv_3d_depth_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_3d_pointcloud_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mv_3d_pointcloud_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_face_detected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mv_face_detected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_face_eye_condition_recognized_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mv_face_eye_condition_recognized_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_face_facial_expression_recognized_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mv_face_facial_expression_recognized_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_face_recognized_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mv_face_recognized_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_face_tracked_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mv_face_tracked_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_image_recognized_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mv_image_recognized_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_image_tracked_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mv_image_tracked_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_inference_face_detected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mv_inference_face_detected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_inference_facial_landmark_detected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mv_inference_facial_landmark_detected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_inference_image_classified_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mv_inference_image_classified_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_inference_object_detected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mv_inference_object_detected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_inference_pose_landmark_detected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mv_inference_pose_landmark_detected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_inference_supported_engine_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_roi_tracker_tracked_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mv_roi_tracker_tracked_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_supported_attribute_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_surveillance_event_occurred_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mv_surveillance_event_occurred_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_surveillance_event_result_name_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_surveillance_event_type_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_package_manager_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_package_manager_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_package_manager_package_info_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_package_manager_request_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_package_manager_request_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_package_manager_request_res_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_package_manager_request_res_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_package_manager_res_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_package_manager_res_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_package_manager_res_event_path_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_package_manager_size_info_receive_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_package_manager_size_info_receive_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_package_manager_total_size_info_receive_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_package_manager_total_size_info_receive_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_peripheral_gpio_interrupted_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_peripheral_gpio_interrupted_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_player_adaptive_variant_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_player_adaptive_variant_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_player_buffering_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_player_buffering_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_player_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_player_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_player_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_player_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_player_interrupted_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_player_interrupted_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_player_media_packet_audio_decoded_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_player_media_packet_audio_decoded_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_player_media_packet_video_decoded_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_player_media_packet_video_decoded_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_player_media_stream_buffer_status_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_player_media_stream_buffer_status_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_player_media_stream_seek_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_player_media_stream_seek_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_player_pd_message_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_player_pd_message_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_player_prepared_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_player_prepared_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_player_seek_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_player_seek_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_player_subtitle_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_player_subtitle_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_player_supported_media_format_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_player_video_captured_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_player_video_captured_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_player_video_stream_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_player_video_stream_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ppm_request_multiple_response_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ppm_request_multiple_response_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ppm_request_response_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ppm_request_response_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_preference_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_preference_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_preference_item_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_provider_feature_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_push_service_notify_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_push_service_notify_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_push_service_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_push_service_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_push_service_state_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_push_service_state_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_radio_interrupted_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_radio_interrupted_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_radio_scan_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_radio_scan_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_radio_scan_stopped_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_radio_scan_stopped_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_radio_scan_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_radio_scan_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_radio_seek_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_radio_seek_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_recorder_audio_stream_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_recorder_audio_stream_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_recorder_device_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_recorder_device_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_recorder_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_recorder_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_recorder_interrupt_started_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_recorder_interrupt_started_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_recorder_interrupted_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_recorder_interrupted_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_recorder_muxed_stream_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_recorder_muxed_stream_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_recorder_recording_limit_reached_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_recorder_recording_limit_reached_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_recorder_recording_status_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_recorder_recording_status_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_recorder_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_recorder_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_recorder_supported_audio_encoder_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_recorder_supported_file_format_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_recorder_supported_video_encoder_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_recorder_supported_video_resolution_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_recorder_video_encode_decision_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_result_cb_t)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_rpc_port_proxy_connected_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_rpc_port_proxy_connected_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_rpc_port_proxy_disconnected_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_rpc_port_proxy_disconnected_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_rpc_port_proxy_received_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_rpc_port_proxy_received_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_rpc_port_proxy_rejected_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_rpc_port_proxy_rejected_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_rpc_port_stub_connected_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_rpc_port_stub_connected_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_rpc_port_stub_disconnected_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_rpc_port_stub_disconnected_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_rpc_port_stub_received_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_runtime_info_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_runtime_info_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sensor_accuracy_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_sensor_accuracy_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sensor_added_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_sensor_added_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sensor_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_sensor_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sensor_events_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_sensor_events_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sensor_provider_interval_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_sensor_provider_interval_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sensor_provider_start_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_sensor_provider_start_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sensor_provider_stop_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_sensor_provider_stop_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sensor_recorder_data_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sensor_removed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_sensor_removed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_service_app_control_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_service_app_control_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_service_app_create_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_service_app_terminate_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_service_app_terminate_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_shortcut_list_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_shortcut_remove_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_shortcut_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_smartcard_reader_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_smartcard_reader_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_softap_client_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_softap_client_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_softap_connected_client_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_softap_disabled_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_softap_disabled_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_softap_enabled_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_softap_enabled_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_softap_passphrase_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_softap_passphrase_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_softap_security_type_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_softap_security_type_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_softap_settings_reloaded_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_softap_settings_reloaded_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_softap_ssid_visibility_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_softap_ssid_visibility_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sound_device_connected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_sound_device_connected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sound_device_connection_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_sound_device_connection_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sound_device_information_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_sound_device_information_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sound_device_running_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_sound_device_running_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sound_device_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_sound_device_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sound_manager_volume_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_sound_manager_volume_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sound_pool_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_sound_pool_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sound_pool_stream_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_sound_pool_stream_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sound_session_interrupted_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_sound_session_interrupted_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sound_stream_ducking_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_sound_stream_ducking_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sound_stream_focus_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_sound_stream_focus_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sound_stream_focus_state_watch_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_sound_stream_focus_state_watch_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ssdp_found_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ssdp_found_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ssdp_registered_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ssdp_registered_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stc_get_all_stats_finished_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_stc_get_all_stats_finished_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stc_stats_info_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_streamrecorder_consume_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_streamrecorder_consume_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_streamrecorder_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_streamrecorder_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_streamrecorder_notify_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_streamrecorder_notify_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_streamrecorder_recording_limit_reached_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_streamrecorder_recording_limit_reached_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_streamrecorder_recording_status_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_streamrecorder_recording_status_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_streamrecorder_supported_audio_encoder_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_streamrecorder_supported_file_format_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_streamrecorder_supported_video_encoder_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_streamrecorder_supported_video_resolution_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stt_default_language_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_stt_default_language_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stt_engine_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_stt_engine_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stt_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_stt_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stt_recognition_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_stt_recognition_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stt_result_time_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stt_speech_status_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_stt_speech_status_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stt_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_stt_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stt_supported_engine_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stt_supported_language_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stte_audio_type_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stte_cancel_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stte_check_app_agreed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stte_deinitialize_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stte_foreach_result_time_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stte_foreach_supported_langs_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stte_get_info_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stte_get_recording_format_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stte_initialize_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stte_is_valid_language_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stte_need_app_credential_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stte_private_data_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stte_private_data_set_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stte_result_time_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stte_set_recording_data_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stte_set_silence_detection_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stte_start_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stte_stop_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stte_support_recognition_type_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stte_support_silence_detection_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_stte_supported_language_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sync_adapter_cancel_sync_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_sync_adapter_cancel_sync_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sync_adapter_start_sync_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sync_manager_sync_job_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_system_settings_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_system_settings_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_system_settings_iter_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_tts_default_voice_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_tts_default_voice_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_tts_engine_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_tts_engine_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_tts_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_tts_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_tts_screen_reader_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_tts_screen_reader_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_tts_service_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_tts_service_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_tts_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_tts_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_tts_supported_voice_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_tts_utterance_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_tts_utterance_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_tts_utterance_started_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_tts_utterance_started_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ttse_activated_mode_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_ttse_activated_mode_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ttse_cancel_synthesis_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ttse_check_app_agreed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ttse_deinitialize_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ttse_foreach_supported_voices_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ttse_get_info_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ttse_initialize_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ttse_is_valid_voice_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ttse_load_voice_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ttse_need_app_credential_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ttse_private_data_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ttse_private_data_set_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ttse_set_pitch_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ttse_start_synthesis_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ttse_supported_voice_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ttse_unload_voice_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_usb_host_hotplug_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_usb_host_hotplug_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_usb_host_transferred_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_usb_host_transferred_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vc_mgr_all_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vc_mgr_begin_speech_detected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_vc_mgr_begin_speech_detected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vc_mgr_dialog_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_vc_mgr_dialog_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vc_mgr_feedback_audio_format_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_vc_mgr_feedback_audio_format_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vc_mgr_feedback_streaming_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_vc_mgr_feedback_streaming_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vc_mgr_pre_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_vc_mgr_pre_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vc_mgr_private_data_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vc_mgr_private_data_set_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vc_mgr_specific_engine_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_vc_mgr_specific_engine_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vc_mgr_vc_tts_streaming_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_vc_mgr_vc_tts_streaming_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_cancel_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_cancel_tts_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_command_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_deinitialize_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_foreach_supported_languages_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_get_info_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_get_recording_format_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_initialize_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_is_language_supported_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_nlu_base_info_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_private_data_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_private_data_set_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_process_haptic_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_process_list_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_process_text_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_request_tts_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_set_audio_type_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_set_commands_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_set_domain_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_set_language_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_set_recording_data_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_set_server_dialog_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_specific_engine_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_start_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_stop_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_supported_language_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_tts_audio_format_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_vce_unset_commands_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wav_player_playback_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wav_player_playback_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_data_channel_buffered_amount_low_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_webrtc_data_channel_buffered_amount_low_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_data_channel_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_webrtc_data_channel_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_data_channel_close_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_webrtc_data_channel_close_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_data_channel_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_webrtc_data_channel_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_data_channel_message_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_webrtc_data_channel_message_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_data_channel_open_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_webrtc_data_channel_open_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_encoded_frame_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_webrtc_encoded_frame_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_webrtc_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_ice_candidate_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_webrtc_ice_candidate_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_ice_connection_state_change_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_webrtc_ice_connection_state_change_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_ice_gathering_state_change_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_webrtc_ice_gathering_state_change_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_media_packet_source_buffer_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_webrtc_media_packet_source_buffer_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_media_source_supported_transceiver_codec_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_negotiation_needed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_webrtc_negotiation_needed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_peer_connection_state_change_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_webrtc_peer_connection_state_change_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_session_description_created_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_webrtc_session_description_created_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_signaling_state_change_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_webrtc_signaling_state_change_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_webrtc_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_stats_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_track_added_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_webrtc_track_added_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_turn_server_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_direct_client_ip_address_assigned_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_direct_client_ip_address_assigned_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_direct_connected_peer_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_direct_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_direct_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_direct_device_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_direct_device_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_direct_discovered_peer_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_direct_discovery_state_chagned_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_direct_discovery_state_chagned_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_direct_peer_found_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_direct_peer_found_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_direct_peer_info_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_direct_peer_info_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_direct_persistent_group_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_direct_service_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_direct_service_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_direct_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_direct_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_direct_supported_wps_type_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_manager_activated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_manager_activated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_manager_ap_ipv6_address_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_manager_ap_vsie_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_manager_bssid_scan_finished_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_manager_bssid_scan_finished_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_manager_config_list_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_manager_connected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_manager_connected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_manager_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_manager_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_manager_deactivated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_manager_deactivated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_manager_device_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_manager_device_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_manager_disconnected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_manager_disconnected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_manager_forget_ap_finished_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_manager_forget_ap_finished_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_manager_found_ap_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_manager_found_bssid_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_manager_ip_conflict_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_manager_ip_conflict_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_manager_module_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_manager_module_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_manager_rssi_level_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_manager_rssi_level_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_manager_scan_finished_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_manager_scan_finished_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_manager_scan_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_manager_scan_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_manager_tdls_discovered_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_manager_tdls_discovered_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_wifi_manager_tdls_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_wifi_manager_tdls_state_changed_cb)
};

std::map<std::string, int> reserved_base_id_map = {
  {"app_control_host_res_fn", BASE_CALLBACK_ID_app_control_host_res_fn},
  {"result_cb_t", BASE_CALLBACK_ID_result_cb_t},
  {"stte_cancel_cb", BASE_CALLBACK_ID_stte_cancel_cb},
  {"stte_check_app_agreed_cb", BASE_CALLBACK_ID_stte_check_app_agreed_cb},
  {"stte_deinitialize_cb", BASE_CALLBACK_ID_stte_deinitialize_cb},
  {"stte_get_info_cb", BASE_CALLBACK_ID_stte_get_info_cb},
  {"stte_get_recording_format_cb", BASE_CALLBACK_ID_stte_get_recording_format_cb},
  {"stte_initialize_cb", BASE_CALLBACK_ID_stte_initialize_cb},
  {"stte_is_valid_language_cb", BASE_CALLBACK_ID_stte_is_valid_language_cb},
  {"stte_need_app_credential_cb", BASE_CALLBACK_ID_stte_need_app_credential_cb},
  {"stte_private_data_requested_cb", BASE_CALLBACK_ID_stte_private_data_requested_cb},
  {"stte_private_data_set_cb", BASE_CALLBACK_ID_stte_private_data_set_cb},
  {"stte_set_recording_data_cb", BASE_CALLBACK_ID_stte_set_recording_data_cb},
  {"stte_set_silence_detection_cb", BASE_CALLBACK_ID_stte_set_silence_detection_cb},
  {"stte_stop_cb", BASE_CALLBACK_ID_stte_stop_cb},
  {"stte_support_recognition_type_cb", BASE_CALLBACK_ID_stte_support_recognition_type_cb},
  {"stte_support_silence_detection_cb", BASE_CALLBACK_ID_stte_support_silence_detection_cb},
  {"sync_adapter_cancel_sync_cb", BASE_CALLBACK_ID_sync_adapter_cancel_sync_cb},
  {"sync_adapter_start_sync_cb", BASE_CALLBACK_ID_sync_adapter_start_sync_cb},
  {"ttse_activated_mode_changed_cb", BASE_CALLBACK_ID_ttse_activated_mode_changed_cb},
  {"ttse_cancel_synthesis_cb", BASE_CALLBACK_ID_ttse_cancel_synthesis_cb},
  {"ttse_check_app_agreed_cb", BASE_CALLBACK_ID_ttse_check_app_agreed_cb},
  {"ttse_deinitialize_cb", BASE_CALLBACK_ID_ttse_deinitialize_cb},
  {"ttse_get_info_cb", BASE_CALLBACK_ID_ttse_get_info_cb},
  {"ttse_initialize_cb", BASE_CALLBACK_ID_ttse_initialize_cb},
  {"ttse_is_valid_voice_cb", BASE_CALLBACK_ID_ttse_is_valid_voice_cb},
  {"ttse_load_voice_cb", BASE_CALLBACK_ID_ttse_load_voice_cb},
  {"ttse_need_app_credential_cb", BASE_CALLBACK_ID_ttse_need_app_credential_cb},
  {"ttse_private_data_requested_cb", BASE_CALLBACK_ID_ttse_private_data_requested_cb},
  {"ttse_private_data_set_cb", BASE_CALLBACK_ID_ttse_private_data_set_cb},
  {"ttse_set_pitch_cb", BASE_CALLBACK_ID_ttse_set_pitch_cb},
  {"ttse_unload_voice_cb", BASE_CALLBACK_ID_ttse_unload_voice_cb},
  {"vce_cancel_cb", BASE_CALLBACK_ID_vce_cancel_cb},
  {"vce_deinitialize_cb", BASE_CALLBACK_ID_vce_deinitialize_cb},
  {"vce_get_info_cb", BASE_CALLBACK_ID_vce_get_info_cb},
  {"vce_get_recording_format_cb", BASE_CALLBACK_ID_vce_get_recording_format_cb},
  {"vce_initialize_cb", BASE_CALLBACK_ID_vce_initialize_cb},
  {"vce_is_language_supported_cb", BASE_CALLBACK_ID_vce_is_language_supported_cb},
  {"vce_nlu_base_info_requested_cb", BASE_CALLBACK_ID_vce_nlu_base_info_requested_cb},
  {"vce_private_data_requested_cb", BASE_CALLBACK_ID_vce_private_data_requested_cb},
  {"vce_private_data_set_cb", BASE_CALLBACK_ID_vce_private_data_set_cb},
  {"vce_process_haptic_event_cb", BASE_CALLBACK_ID_vce_process_haptic_event_cb},
  {"vce_process_list_event_cb", BASE_CALLBACK_ID_vce_process_list_event_cb},
  {"vce_process_text_cb", BASE_CALLBACK_ID_vce_process_text_cb},
  {"vce_set_audio_type_cb", BASE_CALLBACK_ID_vce_set_audio_type_cb},
  {"vce_set_commands_cb", BASE_CALLBACK_ID_vce_set_commands_cb},
  {"vce_set_domain_cb", BASE_CALLBACK_ID_vce_set_domain_cb},
  {"vce_set_language_cb", BASE_CALLBACK_ID_vce_set_language_cb},
  {"vce_set_recording_data_cb", BASE_CALLBACK_ID_vce_set_recording_data_cb},
  {"vce_set_server_dialog_cb", BASE_CALLBACK_ID_vce_set_server_dialog_cb},
  {"vce_specific_engine_request_cb", BASE_CALLBACK_ID_vce_specific_engine_request_cb},
  {"vce_start_cb", BASE_CALLBACK_ID_vce_start_cb},
  {"vce_stop_cb", BASE_CALLBACK_ID_vce_stop_cb},
  {"vce_unset_commands_cb", BASE_CALLBACK_ID_vce_unset_commands_cb},
};
