#include "tizen_interop_callbacks_plugin.h"
#include "macros.h"

#include <mutex>
#include <condition_variable>

#define PROXY_INSTANCES_COUNT 5
int __reserved_cb_id_array[265] = {};
#include <account.h>

#define CB_PARAMS_NAMES account, user_data
PROXY_GROUP_RETURN(account_cb, bool, account_h account, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES key, value, user_data
PROXY_GROUP_RETURN(account_custom_cb, bool, char * key, char * value, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES event_type, account_id, user_data
PROXY_GROUP_RETURN(account_event_cb, bool, const char * event_type, int account_id, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES app_id, label, locale, user_data
PROXY_GROUP_RETURN(account_label_cb, bool, char * app_id, char * label, char * locale, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES account_type, user_data
PROXY_GROUP_RETURN(account_type_cb, bool, account_type_h account_type, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES capability_type, capability_state, user_data
PROXY_GROUP_RETURN(capability_cb, bool, const char * capability_type, account_capability_state_e capability_state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES app_id, key, user_data
PROXY_GROUP_RETURN(provider_feature_cb, bool, char * app_id, char * key, void * user_data)
#undef CB_PARAMS_NAMES


#include <appcore-agent/service_app.h>

#define CB_PARAMS_NAMES app_control, user_data
PROXY_GROUP_NON_BLOCKING(service_app_control_cb, app_control_h app_control, void * user_data)
PROXY_GROUP_BLOCKING(service_app_control_cb, app_control_h app_control, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_RETURN(service_app_create_cb, bool, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(service_app_terminate_cb, void * user_data)
PROXY_GROUP_BLOCKING(service_app_terminate_cb, void * user_data)
#undef CB_PARAMS_NAMES


#include <appfw/app.h>

#include <appfw/app_alarm.h>

#include <appfw/app_common.h>

#include <appfw/app_context.h>

#include <appfw/app_control.h>

#include <appfw/app_control_uri.h>

#include <appfw/app_event.h>

#include <appfw/app_i18n.h>

#include <appfw/app_info.h>

#include <appfw/app_manager.h>

#include <appfw/app_preference.h>

#include <appfw/app_resource_manager.h>

#include <appfw/app_types.h>

#include <appfw/component_context.h>

#include <appfw/component_info.h>

#include <appfw/component_manager.h>

#include <appfw/data_control.h>

#include <appfw/data_control_bulk.h>

#include <appfw/data_control_map.h>

#include <appfw/data_control_noti.h>

#include <appfw/data_control_provider.h>

#include <appfw/data_control_sql.h>

#include <appfw/data_control_sql_cursor.h>

#include <appfw/data_control_types.h>

#include <appfw/job_error.h>

#include <appfw/job_info.h>

#include <appfw/job_scheduler.h>

#include <appfw/message_port.h>

#include <appfw/package_archive_info.h>

#include <appfw/package_info.h>

#include <appfw/package_manager.h>

#include <appfw/widget_app.h>

#include <appfw/widget_app_efl.h>

#define CB_PARAMS_NAMES alarm_id, user_data
PROXY_GROUP_RETURN(alarm_registered_alarm_cb, bool, int alarm_id, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES action, app_control, user_data
PROXY_GROUP_NON_BLOCKING(app_control_action_cb, const char * action, app_control_h app_control, void * user_data)
PROXY_GROUP_BLOCKING(app_control_action_cb, const char * action, app_control_h app_control, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES app_control, appid, user_data
PROXY_GROUP_RETURN(app_control_app_matched_cb, bool, app_control_h app_control, const char * appid, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES app_control, user_data
PROXY_GROUP_NON_BLOCKING(app_control_cb, app_control_h app_control, void * user_data)
PROXY_GROUP_BLOCKING(app_control_cb, app_control_h app_control, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES app_control, key, user_data
PROXY_GROUP_RETURN(app_control_extra_data_cb, bool, app_control_h app_control, const char * key, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES request, reply, result, user_data
PROXY_GROUP_NON_BLOCKING(app_control_reply_cb, app_control_h request, app_control_h reply, app_control_result_e result, void * user_data)
PROXY_GROUP_BLOCKING(app_control_reply_cb, app_control_h request, app_control_h reply, app_control_result_e result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES request, result, user_data
PROXY_GROUP_NON_BLOCKING(app_control_result_cb, app_control_h request, app_control_error_e result, void * user_data)
PROXY_GROUP_BLOCKING(app_control_result_cb, app_control_h request, app_control_error_e result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES key, val, user_data
PROXY_GROUP_RETURN(app_control_uri_query_foreach_cb, bool, const char * key, const char * val, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_RETURN(app_create_cb, bool, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES event_info, user_data
PROXY_GROUP_NON_BLOCKING(app_event_cb, app_event_info_h event_info, void * user_data)
PROXY_GROUP_BLOCKING(app_event_cb, app_event_info_h event_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES category, user_data
PROXY_GROUP_RETURN(app_info_category_cb, bool, const char * category, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES app_info, user_data
PROXY_GROUP_RETURN(app_info_filter_cb, bool, app_info_h app_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES metadata_key, metadata_value, user_data
PROXY_GROUP_RETURN(app_info_metadata_cb, bool, const char * metadata_key, const char * metadata_value, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES res_type, min_res_version, max_res_version, auto_close, user_data
PROXY_GROUP_RETURN(app_info_res_control_cb, bool, const char * res_type, const char * min_res_version, const char * max_res_version, const char * auto_close, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES app_context, user_data
PROXY_GROUP_RETURN(app_manager_app_context_cb, bool, app_context_h app_context, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES app_context, event, user_data
PROXY_GROUP_NON_BLOCKING(app_manager_app_context_event_cb, app_context_h app_context, app_context_event_e event, void * user_data)
PROXY_GROUP_BLOCKING(app_manager_app_context_event_cb, app_context_h app_context, app_context_event_e event, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES app_info, user_data
PROXY_GROUP_RETURN(app_manager_app_info_cb, bool, app_info_h app_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES type, app_id, event_type, event_state, handle, user_data
PROXY_GROUP_NON_BLOCKING(app_manager_event_cb, const char * type, const char * app_id, app_manager_event_type_e event_type, app_manager_event_state_e event_state, app_manager_event_h handle, void * user_data)
PROXY_GROUP_BLOCKING(app_manager_event_cb, const char * type, const char * app_id, app_manager_event_type_e event_type, app_manager_event_state_e event_state, app_manager_event_h handle, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(app_pause_cb, void * user_data)
PROXY_GROUP_BLOCKING(app_pause_cb, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(app_resume_cb, void * user_data)
PROXY_GROUP_BLOCKING(app_resume_cb, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(app_terminate_cb, void * user_data)
PROXY_GROUP_BLOCKING(app_terminate_cb, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES handle, user_data
PROXY_GROUP_RETURN(component_manager_component_context_cb, bool, component_context_h handle, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES handle, user_data
PROXY_GROUP_RETURN(component_manager_component_info_cb, bool, component_info_h handle, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES provider, result, callback_id, user_data
PROXY_GROUP_NON_BLOCKING(data_control_add_callback_result_cb, data_control_h provider, data_control_error_e result, int callback_id, void * user_data)
PROXY_GROUP_BLOCKING(data_control_add_callback_result_cb, data_control_h provider, data_control_error_e result, int callback_id, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES request_id, provider, bulk_results, provider_result, error, user_data
PROXY_GROUP_NON_BLOCKING(data_control_bulk_cb, int request_id, data_control_h provider, data_control_bulk_result_data_h bulk_results, bool provider_result, const char * error, void * user_data)
PROXY_GROUP_BLOCKING(data_control_bulk_cb, int request_id, data_control_h provider, data_control_bulk_result_data_h bulk_results, bool provider_result, const char * error, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES provider, type, data, user_data
PROXY_GROUP_NON_BLOCKING(data_control_data_change_cb, data_control_h provider, data_control_data_change_type_e type, bundle * data, void * user_data)
PROXY_GROUP_BLOCKING(data_control_data_change_cb, data_control_h provider, data_control_data_change_type_e type, bundle * data, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES request_id, provider, provider_result, error, user_data
PROXY_GROUP_NON_BLOCKING(data_control_map_add_response_cb, int request_id, data_control_h provider, bool provider_result, const char * error, void * user_data)
PROXY_GROUP_BLOCKING(data_control_map_add_response_cb, int request_id, data_control_h provider, bool provider_result, const char * error, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES request_id, provider, result_value_list, result_value_count, provider_result, error, user_data
PROXY_GROUP_NON_BLOCKING(data_control_map_get_response_cb, int request_id, data_control_h provider, char ** result_value_list, int result_value_count, bool provider_result, const char * error, void * user_data)
PROXY_GROUP_BLOCKING(data_control_map_get_response_cb, int request_id, data_control_h provider, char ** result_value_list, int result_value_count, bool provider_result, const char * error, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES request_id, provider, provider_result, error, user_data
PROXY_GROUP_NON_BLOCKING(data_control_map_remove_response_cb, int request_id, data_control_h provider, bool provider_result, const char * error, void * user_data)
PROXY_GROUP_BLOCKING(data_control_map_remove_response_cb, int request_id, data_control_h provider, bool provider_result, const char * error, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES request_id, provider, provider_result, error, user_data
PROXY_GROUP_NON_BLOCKING(data_control_map_set_response_cb, int request_id, data_control_h provider, bool provider_result, const char * error, void * user_data)
PROXY_GROUP_BLOCKING(data_control_map_set_response_cb, int request_id, data_control_h provider, bool provider_result, const char * error, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES request_id, provider, bulk_data, user_data
PROXY_GROUP_NON_BLOCKING(data_control_provider_bulk_cb, int request_id, data_control_h provider, data_control_bulk_data_h bulk_data, void * user_data)
PROXY_GROUP_BLOCKING(data_control_provider_bulk_cb, int request_id, data_control_h provider, data_control_bulk_data_h bulk_data, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES provider, consumer_appid, user_data
PROXY_GROUP_RETURN(data_control_provider_data_change_consumer_cb, bool, data_control_h provider, char * consumer_appid, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES provider, consumer_appid, user_data
PROXY_GROUP_RETURN(data_control_provider_data_change_consumer_filter_cb, bool, data_control_h provider, char * consumer_appid, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES request_id, provider, key, value, user_data
PROXY_GROUP_NON_BLOCKING(data_control_provider_map_add_value_request_cb, int request_id, data_control_h provider, const char * key, const char * value, void * user_data)
PROXY_GROUP_BLOCKING(data_control_provider_map_add_value_request_cb, int request_id, data_control_h provider, const char * key, const char * value, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES request_id, provider, key, user_data
PROXY_GROUP_NON_BLOCKING(data_control_provider_map_get_value_request_cb, int request_id, data_control_h provider, const char * key, void * user_data)
PROXY_GROUP_BLOCKING(data_control_provider_map_get_value_request_cb, int request_id, data_control_h provider, const char * key, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES request_id, provider, key, value, user_data
PROXY_GROUP_NON_BLOCKING(data_control_provider_map_remove_value_request_cb, int request_id, data_control_h provider, const char * key, const char * value, void * user_data)
PROXY_GROUP_BLOCKING(data_control_provider_map_remove_value_request_cb, int request_id, data_control_h provider, const char * key, const char * value, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES request_id, provider, key, old_value, new_value, user_data
PROXY_GROUP_NON_BLOCKING(data_control_provider_map_set_value_request_cb, int request_id, data_control_h provider, const char * key, const char * old_value, const char * new_value, void * user_data)
PROXY_GROUP_BLOCKING(data_control_provider_map_set_value_request_cb, int request_id, data_control_h provider, const char * key, const char * old_value, const char * new_value, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES request_id, provider, where, user_data
PROXY_GROUP_NON_BLOCKING(data_control_provider_sql_delete_request_cb, int request_id, data_control_h provider, const char * where, void * user_data)
PROXY_GROUP_BLOCKING(data_control_provider_sql_delete_request_cb, int request_id, data_control_h provider, const char * where, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES request_id, provider, insert_data, user_data
PROXY_GROUP_NON_BLOCKING(data_control_provider_sql_insert_request_cb, int request_id, data_control_h provider, bundle * insert_data, void * user_data)
PROXY_GROUP_BLOCKING(data_control_provider_sql_insert_request_cb, int request_id, data_control_h provider, bundle * insert_data, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES request_id, provider, column_list, column_count, where, order, user_data
PROXY_GROUP_NON_BLOCKING(data_control_provider_sql_select_request_cb, int request_id, data_control_h provider, const char ** column_list, int column_count, const char * where, const char * order, void * user_data)
PROXY_GROUP_BLOCKING(data_control_provider_sql_select_request_cb, int request_id, data_control_h provider, const char ** column_list, int column_count, const char * where, const char * order, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES request_id, provider, update_data, where, user_data
PROXY_GROUP_NON_BLOCKING(data_control_provider_sql_update_request_cb, int request_id, data_control_h provider, bundle * update_data, const char * where, void * user_data)
PROXY_GROUP_BLOCKING(data_control_provider_sql_update_request_cb, int request_id, data_control_h provider, bundle * update_data, const char * where, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES request_id, provider, provider_result, error, user_data
PROXY_GROUP_NON_BLOCKING(data_control_sql_delete_response_cb, int request_id, data_control_h provider, bool provider_result, const char * error, void * user_data)
PROXY_GROUP_BLOCKING(data_control_sql_delete_response_cb, int request_id, data_control_h provider, bool provider_result, const char * error, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES request_id, provider, inserted_row_id, provider_result, error, user_data
PROXY_GROUP_NON_BLOCKING(data_control_sql_insert_response_cb, int request_id, data_control_h provider, long long inserted_row_id, bool provider_result, const char * error, void * user_data)
PROXY_GROUP_BLOCKING(data_control_sql_insert_response_cb, int request_id, data_control_h provider, long long inserted_row_id, bool provider_result, const char * error, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES request_id, provider, enumerator, provider_result, error, user_data
PROXY_GROUP_NON_BLOCKING(data_control_sql_select_response_cb, int request_id, data_control_h provider, result_set_cursor enumerator, bool provider_result, const char * error, void * user_data)
PROXY_GROUP_BLOCKING(data_control_sql_select_response_cb, int request_id, data_control_h provider, result_set_cursor enumerator, bool provider_result, const char * error, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES request_id, provider, provider_result, error, user_data
PROXY_GROUP_NON_BLOCKING(data_control_sql_update_response_cb, int request_id, data_control_h provider, bool provider_result, const char * error, void * user_data)
PROXY_GROUP_BLOCKING(data_control_sql_update_response_cb, int request_id, data_control_h provider, bool provider_result, const char * error, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES event_name, event_data, user_data
PROXY_GROUP_NON_BLOCKING(event_cb, const char * event_name, bundle * event_data, void * user_data)
PROXY_GROUP_BLOCKING(event_cb, const char * event_name, bundle * event_data, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES job_info, user_data
PROXY_GROUP_RETURN(job_scheduler_foreach_job_cb, bool, job_info_h job_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES job_info, user_data
PROXY_GROUP_NON_BLOCKING(job_service_start_cb, job_info_h job_info, void * user_data)
PROXY_GROUP_BLOCKING(job_service_start_cb, job_info_h job_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES job_info, user_data
PROXY_GROUP_NON_BLOCKING(job_service_stop_cb, job_info_h job_info, void * user_data)
PROXY_GROUP_BLOCKING(job_service_stop_cb, job_info_h job_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES local_port_id, remote_app_id, remote_port, trusted_remote_port, message, user_data
PROXY_GROUP_NON_BLOCKING(message_port_message_cb, int local_port_id, const char * remote_app_id, const char * remote_port, bool trusted_remote_port, bundle * message, void * user_data)
PROXY_GROUP_BLOCKING(message_port_message_cb, int local_port_id, const char * remote_app_id, const char * remote_port, bool trusted_remote_port, bundle * message, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES remote_app_id, remote_port, trusted_remote_port, user_data
PROXY_GROUP_NON_BLOCKING(message_port_registration_event_cb, const char * remote_app_id, const char * remote_port, bool trusted_remote_port, void * user_data)
PROXY_GROUP_BLOCKING(message_port_registration_event_cb, const char * remote_app_id, const char * remote_port, bool trusted_remote_port, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES trusted_local_port_id, remote_app_id, remote_port, trusted_remote_port, message, user_data
PROXY_GROUP_NON_BLOCKING(message_port_trusted_message_cb, int trusted_local_port_id, const char * remote_app_id, const char * remote_port, bool trusted_remote_port, bundle * message, void * user_data)
PROXY_GROUP_BLOCKING(message_port_trusted_message_cb, int trusted_local_port_id, const char * remote_app_id, const char * remote_port, bool trusted_remote_port, bundle * message, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES comp_type, app_id, user_data
PROXY_GROUP_RETURN(package_info_app_cb, bool, package_info_app_component_type_e comp_type, const char * app_id, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES handle, cert_type, cert_value, user_data
PROXY_GROUP_RETURN(package_info_cert_info_cb, bool, package_info_h handle, package_cert_type_e cert_type, const char * cert_value, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES from, to, type, required_version, user_data
PROXY_GROUP_RETURN(package_info_dependency_info_cb, bool, const char * from, const char * to, const char * type, const char * required_version, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES privilege_name, user_data
PROXY_GROUP_RETURN(package_info_privilege_info_cb, bool, const char * privilege_name, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES allowed_package, privilege_handle, user_data
PROXY_GROUP_RETURN(package_info_res_allowed_package_cb, bool, const char * allowed_package, allowed_package_required_privilege_h privilege_handle, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES info, user_data
PROXY_GROUP_RETURN(package_info_updateinfo_cb, bool, package_updateinfo_h info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES type, package, event_type, event_state, progress, error, user_data
PROXY_GROUP_NON_BLOCKING(package_manager_event_cb, const char * type, const char * package, package_manager_event_type_e event_type, package_manager_event_state_e event_state, int progress, package_manager_error_e error, void * user_data)
PROXY_GROUP_BLOCKING(package_manager_event_cb, const char * type, const char * package, package_manager_event_type_e event_type, package_manager_event_state_e event_state, int progress, package_manager_error_e error, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES package_info, user_data
PROXY_GROUP_RETURN(package_manager_package_info_cb, bool, package_info_h package_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES id, type, package, event_type, event_state, progress, error, user_data
PROXY_GROUP_NON_BLOCKING(package_manager_request_event_cb, int id, const char * type, const char * package, package_manager_event_type_e event_type, package_manager_event_state_e event_state, int progress, package_manager_error_e error, void * user_data)
PROXY_GROUP_BLOCKING(package_manager_request_event_cb, int id, const char * type, const char * package, package_manager_event_type_e event_type, package_manager_event_state_e event_state, int progress, package_manager_error_e error, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES req_id, pkgid, event_type, event_state, handle, user_data
PROXY_GROUP_NON_BLOCKING(package_manager_request_res_event_cb, int req_id, const char * pkgid, package_manager_event_type_e event_type, package_manager_event_state_e event_state, package_manager_res_event_info_h handle, void * user_data)
PROXY_GROUP_BLOCKING(package_manager_request_res_event_cb, int req_id, const char * pkgid, package_manager_event_type_e event_type, package_manager_event_state_e event_state, package_manager_res_event_info_h handle, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES pkgid, event_type, event_state, handle, user_data
PROXY_GROUP_NON_BLOCKING(package_manager_res_event_cb, const char * pkgid, package_manager_event_type_e event_type, package_manager_event_state_e event_state, package_manager_res_event_info_h handle, void * user_data)
PROXY_GROUP_BLOCKING(package_manager_res_event_cb, const char * pkgid, package_manager_event_type_e event_type, package_manager_event_state_e event_state, package_manager_res_event_info_h handle, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES path, state, user_data
PROXY_GROUP_RETURN(package_manager_res_event_path_cb, bool, const char * path, package_manager_res_event_path_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES package_id, size_info, user_data
PROXY_GROUP_NON_BLOCKING(package_manager_size_info_receive_cb, const char * package_id, const package_size_info_h size_info, void * user_data)
PROXY_GROUP_BLOCKING(package_manager_size_info_receive_cb, const char * package_id, const package_size_info_h size_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES size_info, user_data
PROXY_GROUP_NON_BLOCKING(package_manager_total_size_info_receive_cb, const package_size_info_h size_info, void * user_data)
PROXY_GROUP_BLOCKING(package_manager_total_size_info_receive_cb, const package_size_info_h size_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES key, user_data
PROXY_GROUP_NON_BLOCKING(preference_changed_cb, const char * key, void * user_data)
PROXY_GROUP_BLOCKING(preference_changed_cb, const char * key, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES key, user_data
PROXY_GROUP_RETURN(preference_item_cb, bool, const char * key, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_RETURN(widget_app_create_cb, widget_class_h, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(widget_app_terminate_cb, void * user_data)
PROXY_GROUP_BLOCKING(widget_app_terminate_cb, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES context, user_data
PROXY_GROUP_RETURN(widget_context_cb, bool, widget_context_h context, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES context, content, w, h, user_data
PROXY_GROUP_RETURN(widget_instance_create_cb, int, widget_context_h context, bundle * content, int w, int h, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES context, reason, content, user_data
PROXY_GROUP_RETURN(widget_instance_destroy_cb, int, widget_context_h context, widget_app_destroy_type_e reason, bundle * content, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES context, user_data
PROXY_GROUP_RETURN(widget_instance_pause_cb, int, widget_context_h context, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES context, w, h, user_data
PROXY_GROUP_RETURN(widget_instance_resize_cb, int, widget_context_h context, int w, int h, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES context, user_data
PROXY_GROUP_RETURN(widget_instance_resume_cb, int, widget_context_h context, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES context, content, force, user_data
PROXY_GROUP_RETURN(widget_instance_update_cb, int, widget_context_h context, bundle * content, int force, void * user_data)
#undef CB_PARAMS_NAMES


#include <asp/asp.h>

#define CB_PARAMS_NAMES adv_service, status, reason, user_data
PROXY_GROUP_NON_BLOCKING(asp_advert_status_changed_cb, asp_advert_service_h adv_service, asp_service_status_e status, asp_advert_status_reason_e reason, void * user_data)
PROXY_GROUP_BLOCKING(asp_advert_status_changed_cb, asp_advert_service_h adv_service, asp_service_status_e status, asp_advert_status_reason_e reason, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error_code, seek_service, service_mac, adv_id, config_method, instance_name, service_info, info_size, status, user_data
PROXY_GROUP_NON_BLOCKING(asp_seek_search_result_cb, int error_code, asp_seek_service_h seek_service, const char * service_mac, unsigned int adv_id, asp_wps_type_e config_method, const char * instance_name, const char * service_info, int info_size, unsigned char status, void * user_data)
PROXY_GROUP_BLOCKING(asp_seek_search_result_cb, int error_code, asp_seek_service_h seek_service, const char * service_mac, unsigned int adv_id, asp_wps_type_e config_method, const char * instance_name, const char * service_info, int info_size, unsigned char status, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error_code, session, get_pin, config_pin, user_data
PROXY_GROUP_NON_BLOCKING(asp_session_config_request_cb, int error_code, asp_session_h session, bool get_pin, const char * config_pin, void * user_data)
PROXY_GROUP_BLOCKING(asp_session_config_request_cb, int error_code, asp_session_h session, bool get_pin, const char * config_pin, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error_code, session, status, deferred_resp, resp_size, user_data
PROXY_GROUP_NON_BLOCKING(asp_session_connect_status_cb, int error_code, asp_session_h session, asp_connect_status_e status, const char * deferred_resp, int resp_size, void * user_data)
PROXY_GROUP_BLOCKING(asp_session_connect_status_cb, int error_code, asp_session_h session, asp_connect_status_e status, const char * deferred_resp, int resp_size, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error_code, session, ip_address, port, proto, status, user_data
PROXY_GROUP_NON_BLOCKING(asp_session_port_status_cb, int error_code, asp_session_h session, const char * ip_address, int port, int proto, asp_port_status_e status, void * user_data)
PROXY_GROUP_BLOCKING(asp_session_port_status_cb, int error_code, asp_session_h session, const char * ip_address, int port, int proto, asp_port_status_e status, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error_code, adv_service, session, device_name, info, info_size, get_network_config_pin, network_config_pin, user_data
PROXY_GROUP_NON_BLOCKING(asp_session_request_cb, int error_code, asp_advert_service_h adv_service, asp_session_h session, const char * device_name, const char * info, int info_size, bool get_network_config_pin, const char * network_config_pin, void * user_data)
PROXY_GROUP_BLOCKING(asp_session_request_cb, int error_code, asp_advert_service_h adv_service, asp_session_h session, const char * device_name, const char * info, int info_size, bool get_network_config_pin, const char * network_config_pin, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error_code, session, state, additional_info, user_data
PROXY_GROUP_NON_BLOCKING(asp_session_status_cb, int error_code, asp_session_h session, asp_session_state_e state, const char * additional_info, void * user_data)
PROXY_GROUP_BLOCKING(asp_session_status_cb, int error_code, asp_session_h session, asp_session_state_e state, const char * additional_info, void * user_data)
#undef CB_PARAMS_NAMES


#include <autofill.h>

#define CB_PARAMS_NAMES ah, auth_info, user_data
PROXY_GROUP_NON_BLOCKING(autofill_auth_info_received_cb, autofill_h ah, autofill_auth_info_h auth_info, void * user_data)
PROXY_GROUP_BLOCKING(autofill_auth_info_received_cb, autofill_h ah, autofill_auth_info_h auth_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES ah, status, user_data
PROXY_GROUP_NON_BLOCKING(autofill_connection_status_changed_cb, autofill_h ah, autofill_connection_status_e status, void * user_data)
PROXY_GROUP_BLOCKING(autofill_connection_status_changed_cb, autofill_h ah, autofill_connection_status_e status, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES ah, error_info, user_data
PROXY_GROUP_NON_BLOCKING(autofill_error_info_received_cb, autofill_h ah, autofill_error_info_h error_info, void * user_data)
PROXY_GROUP_BLOCKING(autofill_error_info_received_cb, autofill_h ah, autofill_error_info_h error_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES ah, fill_response_h, user_data
PROXY_GROUP_NON_BLOCKING(autofill_fill_response_received_cb, autofill_h ah, autofill_fill_response_h fill_response_h, void * user_data)
PROXY_GROUP_BLOCKING(autofill_fill_response_received_cb, autofill_h ah, autofill_fill_response_h fill_response_h, void * user_data)
#undef CB_PARAMS_NAMES


#include <autofill_common.h>

#define CB_PARAMS_NAMES item, user_data
PROXY_GROUP_RETURN(autofill_fill_response_group_cb, bool, autofill_fill_response_group_h item, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES item, user_data
PROXY_GROUP_RETURN(autofill_fill_response_item_cb, bool, autofill_fill_response_item_h item, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES item, user_data
PROXY_GROUP_RETURN(autofill_item_cb, bool, autofill_item_h item, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES item, user_data
PROXY_GROUP_RETURN(autofill_save_item_cb, bool, autofill_save_item_h item, void * user_data)
#undef CB_PARAMS_NAMES


#include <autofill_manager.h>

#define CB_PARAMS_NAMES app_id, user_data
PROXY_GROUP_RETURN(autofill_manager_autofill_service_cb, bool, const char * app_id, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES amh, status, user_data
PROXY_GROUP_NON_BLOCKING(autofill_manager_connection_status_changed_cb, autofill_manager_h amh, autofill_manager_connection_status_e status, void * user_data)
PROXY_GROUP_BLOCKING(autofill_manager_connection_status_changed_cb, autofill_manager_h amh, autofill_manager_connection_status_e status, void * user_data)
#undef CB_PARAMS_NAMES


#include <autofill_service.h>

#define CB_PARAMS_NAMES context_id, vi, user_data
PROXY_GROUP_NON_BLOCKING(autofill_service_auth_info_requested_cb, int context_id, autofill_view_info_h vi, void * user_data)
PROXY_GROUP_BLOCKING(autofill_service_auth_info_requested_cb, int context_id, autofill_view_info_h vi, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES context_id, vi, user_data
PROXY_GROUP_NON_BLOCKING(autofill_service_cancel_fill_requested_cb, int context_id, autofill_view_info_h vi, void * user_data)
PROXY_GROUP_BLOCKING(autofill_service_cancel_fill_requested_cb, int context_id, autofill_view_info_h vi, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES context_id, vi, user_data
PROXY_GROUP_NON_BLOCKING(autofill_service_committed_cb, int context_id, autofill_save_view_info_h vi, void * user_data)
PROXY_GROUP_BLOCKING(autofill_service_committed_cb, int context_id, autofill_save_view_info_h vi, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES context_id, vi, user_data
PROXY_GROUP_NON_BLOCKING(autofill_service_fill_requested_cb, int context_id, autofill_view_info_h vi, void * user_data)
PROXY_GROUP_BLOCKING(autofill_service_fill_requested_cb, int context_id, autofill_view_info_h vi, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(autofill_service_terminate_received_cb, void * user_data)
PROXY_GROUP_BLOCKING(autofill_service_terminate_received_cb, void * user_data)
#undef CB_PARAMS_NAMES


#include <badge/badge.h>

#include <badge/badge_error.h>

#define CB_PARAMS_NAMES action, app_id, count, user_data
PROXY_GROUP_NON_BLOCKING(badge_change_cb, unsigned int action, const char * app_id, unsigned int count, void * user_data)
PROXY_GROUP_BLOCKING(badge_change_cb, unsigned int action, const char * app_id, unsigned int count, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES app_id, count, user_data
PROXY_GROUP_RETURN(badge_foreach_cb, bool, const char * app_id, unsigned int count, void * user_data)
#undef CB_PARAMS_NAMES


#include <bundle.h>

#define CB_PARAMS_NAMES key, type, kv, user_data
PROXY_GROUP_NON_BLOCKING(bundle_iterator_t, const char * key, const int type, const bundle_keyval_t * kv, void * user_data)
PROXY_GROUP_BLOCKING(bundle_iterator_t, const char * key, const int type, const bundle_keyval_t * kv, void * user_data)
#undef CB_PARAMS_NAMES


#include <cbhm/cbhm.h>

#include <cbhm/cbhm_constant.h>

#include <cbhm/cbhm_error.h>

#define CB_PARAMS_NAMES cbhm_handle, item_count, user_data
PROXY_GROUP_NON_BLOCKING(cbhm_item_changed_cb, cbhm_h cbhm_handle, int item_count, void * user_data)
PROXY_GROUP_BLOCKING(cbhm_item_changed_cb, cbhm_h cbhm_handle, int item_count, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES cbhm_handle, active_state, user_data
PROXY_GROUP_NON_BLOCKING(cbhm_monitor_cb, cbhm_h cbhm_handle, bool active_state, void * user_data)
PROXY_GROUP_BLOCKING(cbhm_monitor_cb, cbhm_h cbhm_handle, bool active_state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES cbhm_handle, user_data
PROXY_GROUP_RETURN(cbhm_selected_cb, int, cbhm_h cbhm_handle, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES cbhm_handle, buf, len, user_data
PROXY_GROUP_RETURN(cbhm_selection_data_cb, int, cbhm_h cbhm_handle, const char * buf, size_t len, void * user_data)
#undef CB_PARAMS_NAMES


#include <cion/cion.h>

#include <cion/cion_client.h>

#include <cion/cion_connection_result.h>

#include <cion/cion_error.h>

#include <cion/cion_group.h>

#include <cion/cion_payload.h>

#include <cion/cion_payload_async_result.h>

#include <cion/cion_peer_info.h>

#include <cion/cion_security.h>

#include <cion/cion_server.h>

#define CB_PARAMS_NAMES service_name, peer_info, result, user_data
PROXY_GROUP_NON_BLOCKING(cion_client_connection_result_cb, const char * service_name, const cion_peer_info_h peer_info, const cion_connection_result_h result, void * user_data)
PROXY_GROUP_BLOCKING(cion_client_connection_result_cb, const char * service_name, const cion_peer_info_h peer_info, const cion_connection_result_h result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES service_name, peer_info, user_data
PROXY_GROUP_NON_BLOCKING(cion_client_disconnected_cb, const char * service_name, const cion_peer_info_h peer_info, void * user_data)
PROXY_GROUP_BLOCKING(cion_client_disconnected_cb, const char * service_name, const cion_peer_info_h peer_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, user_data
PROXY_GROUP_NON_BLOCKING(cion_client_payload_async_result_cb, const cion_payload_async_result_h result, void * user_data)
PROXY_GROUP_BLOCKING(cion_client_payload_async_result_cb, const cion_payload_async_result_h result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES service_name, peer_info, payload, status, user_data
PROXY_GROUP_NON_BLOCKING(cion_client_payload_received_cb, const char * service_name, const cion_peer_info_h peer_info, const cion_payload_h payload, cion_payload_transfer_status_e status, void * user_data)
PROXY_GROUP_BLOCKING(cion_client_payload_received_cb, const char * service_name, const cion_peer_info_h peer_info, const cion_payload_h payload, cion_payload_transfer_status_e status, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES service_name, peer_info, user_data
PROXY_GROUP_NON_BLOCKING(cion_client_server_discovered_cb, const char * service_name, const cion_peer_info_h peer_info, void * user_data)
PROXY_GROUP_BLOCKING(cion_client_server_discovered_cb, const char * service_name, const cion_peer_info_h peer_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES topic_name, peer_info, user_data
PROXY_GROUP_NON_BLOCKING(cion_group_joined_cb, const char * topic_name, const cion_peer_info_h peer_info, void * user_data)
PROXY_GROUP_BLOCKING(cion_group_joined_cb, const char * topic_name, const cion_peer_info_h peer_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES topic_name, peer_info, user_data
PROXY_GROUP_NON_BLOCKING(cion_group_left_cb, const char * topic_name, const cion_peer_info_h peer_info, void * user_data)
PROXY_GROUP_BLOCKING(cion_group_left_cb, const char * topic_name, const cion_peer_info_h peer_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES topic_name, peer_info, payload, user_data
PROXY_GROUP_NON_BLOCKING(cion_group_payload_received_cb, const char * topic_name, const cion_peer_info_h peer_info, cion_payload_h payload, void * user_data)
PROXY_GROUP_BLOCKING(cion_group_payload_received_cb, const char * topic_name, const cion_peer_info_h peer_info, cion_payload_h payload, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES peer_info, user_data
PROXY_GROUP_RETURN(cion_server_connected_peer_info_cb, bool, const cion_peer_info_h peer_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES service_name, peer_info, user_data
PROXY_GROUP_NON_BLOCKING(cion_server_connection_request_cb, const char * service_name, const cion_peer_info_h peer_info, void * user_data)
PROXY_GROUP_BLOCKING(cion_server_connection_request_cb, const char * service_name, const cion_peer_info_h peer_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES service_name, peer_info, result, user_data
PROXY_GROUP_NON_BLOCKING(cion_server_connection_result_cb, const char * service_name, const cion_peer_info_h peer_info, const cion_connection_result_h result, void * user_data)
PROXY_GROUP_BLOCKING(cion_server_connection_result_cb, const char * service_name, const cion_peer_info_h peer_info, const cion_connection_result_h result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES service_name, peer_info, data, data_size, return_data, return_data_size, user_data
PROXY_GROUP_NON_BLOCKING(cion_server_data_received_cb, const char * service_name, const cion_peer_info_h peer_info, const unsigned char * data, unsigned int data_size, unsigned char ** return_data, unsigned int * return_data_size, void * user_data)
PROXY_GROUP_BLOCKING(cion_server_data_received_cb, const char * service_name, const cion_peer_info_h peer_info, const unsigned char * data, unsigned int data_size, unsigned char ** return_data, unsigned int * return_data_size, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES service_name, peer_info, user_data
PROXY_GROUP_NON_BLOCKING(cion_server_disconnected_cb, const char * service_name, const cion_peer_info_h peer_info, void * user_data)
PROXY_GROUP_BLOCKING(cion_server_disconnected_cb, const char * service_name, const cion_peer_info_h peer_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, user_data
PROXY_GROUP_NON_BLOCKING(cion_server_payload_async_result_cb, const cion_payload_async_result_h result, void * user_data)
PROXY_GROUP_BLOCKING(cion_server_payload_async_result_cb, const cion_payload_async_result_h result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES service_name, peer_info, payload, status, user_data
PROXY_GROUP_NON_BLOCKING(cion_server_payload_received_cb, const char * service_name, const cion_peer_info_h peer_info, const cion_payload_h payload, cion_payload_transfer_status_e status, void * user_data)
PROXY_GROUP_BLOCKING(cion_server_payload_received_cb, const char * service_name, const cion_peer_info_h peer_info, const cion_payload_h payload, cion_payload_transfer_status_e status, void * user_data)
#undef CB_PARAMS_NAMES




#include <context-service/activity_recognition.h>

#include <context-service/context_history.h>

#include <context-service/context_trigger.h>

#include <context-service/gesture_recognition.h>

#define CB_PARAMS_NAMES activity, data, timestamp, error, user_data
PROXY_GROUP_NON_BLOCKING(activity_recognition_cb, activity_type_e activity, const activity_data_h data, double timestamp, activity_error_e error, void * user_data)
PROXY_GROUP_BLOCKING(activity_recognition_cb, activity_type_e activity, const activity_data_h data, double timestamp, activity_error_e error, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES gesture, data, timestamp, error, user_data
PROXY_GROUP_NON_BLOCKING(gesture_recognition_cb, gesture_type_e gesture, const gesture_data_h data, double timestamp, gesture_error_e error, void * user_data)
PROXY_GROUP_BLOCKING(gesture_recognition_cb, gesture_type_e gesture, const gesture_data_h data, double timestamp, gesture_error_e error, void * user_data)
#undef CB_PARAMS_NAMES


#include <csr/csr-content-screening-types.h>

#include <csr/csr-content-screening.h>

#include <csr/csr-engine-manager.h>

#include <csr/csr-error.h>

#include <csr/csr-web-protection-types.h>

#include <csr/csr-web-protection.h>

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(csr_cs_cancelled_cb, void * user_data)
PROXY_GROUP_BLOCKING(csr_cs_cancelled_cb, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(csr_cs_completed_cb, void * user_data)
PROXY_GROUP_BLOCKING(csr_cs_completed_cb, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES malware, user_data
PROXY_GROUP_NON_BLOCKING(csr_cs_detected_cb, csr_cs_malware_h malware, void * user_data)
PROXY_GROUP_BLOCKING(csr_cs_detected_cb, csr_cs_malware_h malware, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error_code, user_data
PROXY_GROUP_NON_BLOCKING(csr_cs_error_cb, int error_code, void * user_data)
PROXY_GROUP_BLOCKING(csr_cs_error_cb, int error_code, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES file_path, user_data
PROXY_GROUP_NON_BLOCKING(csr_cs_file_scanned_cb, const char * file_path, void * user_data)
PROXY_GROUP_BLOCKING(csr_cs_file_scanned_cb, const char * file_path, void * user_data)
#undef CB_PARAMS_NAMES



#include <device/battery.h>

#include <device/callback.h>

#include <device/device-error.h>

#include <device/display-enum.h>

#include <device/display.h>

#include <device/haptic.h>

#include <device/ir.h>

#include <device/led.h>

#include <device/power.h>

#include <device/temperature.h>

#define CB_PARAMS_NAMES type, value, user_data
PROXY_GROUP_NON_BLOCKING(device_changed_cb, device_callback_e type, void * value, void * user_data)
PROXY_GROUP_BLOCKING(device_changed_cb, device_callback_e type, void * value, void * user_data)
#undef CB_PARAMS_NAMES


#include <diagnostics.h>

#define CB_PARAMS_NAMES ctx, user_data
PROXY_GROUP_NON_BLOCKING(diagnostics_notification_cb, diagnostics_ctx_h ctx, void * user_data)
PROXY_GROUP_BLOCKING(diagnostics_notification_cb, diagnostics_ctx_h ctx, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES data, params, params_size, ctx, user_data
PROXY_GROUP_NON_BLOCKING(diagnostics_request_cb, diagnostics_data_h data, char ** params, int params_size, diagnostics_ctx_h ctx, void * user_data)
PROXY_GROUP_BLOCKING(diagnostics_request_cb, diagnostics_data_h data, char ** params, int params_size, diagnostics_ctx_h ctx, void * user_data)
#undef CB_PARAMS_NAMES



#include <dpm/device-policy-manager.h>

#include <dpm/password.h>

#include <dpm/restriction.h>

#include <dpm/security.h>

#include <dpm/zone.h>

#define CB_PARAMS_NAMES name, state, user_data
PROXY_GROUP_NON_BLOCKING(dpm_policy_changed_cb, const char * name, const char * state, void * user_data)
PROXY_GROUP_BLOCKING(dpm_policy_changed_cb, const char * name, const char * state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES name, object, user_data
PROXY_GROUP_NON_BLOCKING(dpm_signal_cb, const char * name, const char * object, void * user_data)
PROXY_GROUP_BLOCKING(dpm_signal_cb, const char * name, const char * object, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES name, user_data
PROXY_GROUP_RETURN(dpm_zone_foreach_name_cb, bool, const char * name, void * user_data)
#undef CB_PARAMS_NAMES


#include <eom/eom.h>

#define CB_PARAMS_NAMES output_id, user_data
PROXY_GROUP_NON_BLOCKING(eom_attribute_changed_cb, eom_output_id output_id, void * user_data)
PROXY_GROUP_BLOCKING(eom_attribute_changed_cb, eom_output_id output_id, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES output_id, user_data
PROXY_GROUP_NON_BLOCKING(eom_mode_changed_cb, eom_output_id output_id, void * user_data)
PROXY_GROUP_BLOCKING(eom_mode_changed_cb, eom_output_id output_id, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES output_id, user_data
PROXY_GROUP_NON_BLOCKING(eom_output_added_cb, eom_output_id output_id, void * user_data)
PROXY_GROUP_BLOCKING(eom_output_added_cb, eom_output_id output_id, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES output_id, user_data
PROXY_GROUP_NON_BLOCKING(eom_output_removed_cb, eom_output_id output_id, void * user_data)
PROXY_GROUP_BLOCKING(eom_output_removed_cb, eom_output_id output_id, void * user_data)
#undef CB_PARAMS_NAMES




#include <fido_uaf_authenticator.h>

#define CB_PARAMS_NAMES att_type, user_data
PROXY_GROUP_NON_BLOCKING(fido_attestation_type_cb, fido_auth_attestation_type_e att_type, void * user_data)
PROXY_GROUP_BLOCKING(fido_attestation_type_cb, fido_auth_attestation_type_e att_type, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES auth_info, user_data
PROXY_GROUP_NON_BLOCKING(fido_authenticator_cb, const fido_authenticator_h auth_info, void * user_data)
PROXY_GROUP_BLOCKING(fido_authenticator_cb, const fido_authenticator_h auth_info, void * user_data)
#undef CB_PARAMS_NAMES


#include <fido_uaf_client.h>

#define CB_PARAMS_NAMES tizen_error_code, uaf_response_json, user_data
PROXY_GROUP_NON_BLOCKING(fido_uaf_response_message_cb, fido_error_e tizen_error_code, const char * uaf_response_json, void * user_data)
PROXY_GROUP_BLOCKING(fido_uaf_response_message_cb, fido_error_e tizen_error_code, const char * uaf_response_json, void * user_data)
#undef CB_PARAMS_NAMES


#include <geofence/geofence_manager.h>

#include <geofence/geofence_type.h>

#define CB_PARAMS_NAMES place_id, geofence_id, error, manage, user_data
PROXY_GROUP_NON_BLOCKING(geofence_event_cb, int place_id, int geofence_id, geofence_manager_error_e error, geofence_manage_e manage, void * user_data)
PROXY_GROUP_BLOCKING(geofence_event_cb, int place_id, int geofence_id, geofence_manager_error_e error, geofence_manage_e manage, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES geofence_id, fence, fence_index, fence_cnt, user_data
PROXY_GROUP_RETURN(geofence_manager_fence_cb, bool, int geofence_id, geofence_h fence, int fence_index, int fence_cnt, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES place_id, place_name, place_index, place_cnt, user_data
PROXY_GROUP_RETURN(geofence_manager_place_cb, bool, int place_id, const char * place_name, int place_index, int place_cnt, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES geofence_id, state, provider, user_data
PROXY_GROUP_NON_BLOCKING(geofence_proximity_state_changed_cb, int geofence_id, geofence_proximity_state_e state, geofence_proximity_provider_e provider, void * user_data)
PROXY_GROUP_BLOCKING(geofence_proximity_state_changed_cb, int geofence_id, geofence_proximity_state_e state, geofence_proximity_provider_e provider, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES geofence_id, state, user_data
PROXY_GROUP_NON_BLOCKING(geofence_state_changed_cb, int geofence_id, geofence_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(geofence_state_changed_cb, int geofence_id, geofence_state_e state, void * user_data)
#undef CB_PARAMS_NAMES


#include <inputmethod.h>

#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(ime_accessibility_state_changed_cb, bool state, void * user_data)
PROXY_GROUP_BLOCKING(ime_accessibility_state_changed_cb, bool state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(ime_create_cb, void * user_data)
PROXY_GROUP_BLOCKING(ime_create_cb, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES cursor_pos, user_data
PROXY_GROUP_NON_BLOCKING(ime_cursor_position_updated_cb, int cursor_pos, void * user_data)
PROXY_GROUP_BLOCKING(ime_cursor_position_updated_cb, int cursor_pos, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES language, user_data
PROXY_GROUP_NON_BLOCKING(ime_display_language_changed_cb, const char * language, void * user_data)
PROXY_GROUP_BLOCKING(ime_display_language_changed_cb, const char * language, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES context_id, user_data
PROXY_GROUP_NON_BLOCKING(ime_focus_in_cb, int context_id, void * user_data)
PROXY_GROUP_BLOCKING(ime_focus_in_cb, int context_id, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES context_id, user_data
PROXY_GROUP_NON_BLOCKING(ime_focus_out_cb, int context_id, void * user_data)
PROXY_GROUP_BLOCKING(ime_focus_out_cb, int context_id, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data, x, y, w, h
PROXY_GROUP_NON_BLOCKING(ime_geometry_requested_cb, void * user_data, int * x, int * y, int * w, int * h)
PROXY_GROUP_BLOCKING(ime_geometry_requested_cb, void * user_data, int * x, int * y, int * w, int * h)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES context_id, user_data
PROXY_GROUP_NON_BLOCKING(ime_hide_cb, int context_id, void * user_data)
PROXY_GROUP_BLOCKING(ime_hide_cb, int context_id, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data, data, data_length
PROXY_GROUP_NON_BLOCKING(ime_imdata_requested_cb, void * user_data, void ** data, unsigned int * data_length)
PROXY_GROUP_BLOCKING(ime_imdata_requested_cb, void * user_data, void ** data, unsigned int * data_length)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES data, data_length, user_data
PROXY_GROUP_NON_BLOCKING(ime_imdata_set_cb, void * data, unsigned int data_length, void * user_data)
PROXY_GROUP_BLOCKING(ime_imdata_set_cb, void * data, unsigned int data_length, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(ime_input_context_reset_cb, void * user_data)
PROXY_GROUP_BLOCKING(ime_input_context_reset_cb, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES input_hint, user_data
PROXY_GROUP_NON_BLOCKING(ime_input_hint_set_cb, Ecore_IMF_Input_Hints input_hint, void * user_data)
PROXY_GROUP_BLOCKING(ime_input_hint_set_cb, Ecore_IMF_Input_Hints input_hint, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data, lang_code
PROXY_GROUP_NON_BLOCKING(ime_language_requested_cb, void * user_data, char ** lang_code)
PROXY_GROUP_BLOCKING(ime_language_requested_cb, void * user_data, char ** lang_code)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES language, user_data
PROXY_GROUP_NON_BLOCKING(ime_language_set_cb, Ecore_IMF_Input_Panel_Lang language, void * user_data)
PROXY_GROUP_BLOCKING(ime_language_set_cb, Ecore_IMF_Input_Panel_Lang language, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES layout, user_data
PROXY_GROUP_NON_BLOCKING(ime_layout_set_cb, Ecore_IMF_Input_Panel_Layout layout, void * user_data)
PROXY_GROUP_BLOCKING(ime_layout_set_cb, Ecore_IMF_Input_Panel_Layout layout, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES mime_type, user_data
PROXY_GROUP_NON_BLOCKING(ime_mime_type_set_request_cb, const char * mime_type, void * user_data)
PROXY_GROUP_BLOCKING(ime_mime_type_set_request_cb, const char * mime_type, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES window, type, user_data
PROXY_GROUP_NON_BLOCKING(ime_option_window_created_cb, Evas_Object * window, ime_option_window_type_e type, void * user_data)
PROXY_GROUP_BLOCKING(ime_option_window_created_cb, Evas_Object * window, ime_option_window_type_e type, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES window, user_data
PROXY_GROUP_NON_BLOCKING(ime_option_window_destroyed_cb, Evas_Object * window, void * user_data)
PROXY_GROUP_BLOCKING(ime_option_window_destroyed_cb, Evas_Object * window, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES key, value, user_data
PROXY_GROUP_NON_BLOCKING(ime_prediction_hint_data_set_cb, const char * key, const char * value, void * user_data)
PROXY_GROUP_BLOCKING(ime_prediction_hint_data_set_cb, const char * key, const char * value, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES prediction_hint, user_data
PROXY_GROUP_NON_BLOCKING(ime_prediction_hint_set_cb, const char * prediction_hint, void * user_data)
PROXY_GROUP_BLOCKING(ime_prediction_hint_set_cb, const char * prediction_hint, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES key_code, key_mask, dev_info, user_data
PROXY_GROUP_RETURN(ime_process_key_event_cb, bool, ime_key_code_e key_code, ime_key_mask_e key_mask, ime_device_info_h dev_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES key_code, key_sym, key_mask, dev_info, user_data
PROXY_GROUP_RETURN(ime_process_key_event_with_keycode_cb, bool, unsigned int key_code, ime_key_code_e key_sym, ime_key_mask_e key_mask, ime_device_info_h dev_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES disabled, user_data
PROXY_GROUP_NON_BLOCKING(ime_return_key_state_set_cb, bool disabled, void * user_data)
PROXY_GROUP_BLOCKING(ime_return_key_state_set_cb, bool disabled, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES type, user_data
PROXY_GROUP_NON_BLOCKING(ime_return_key_type_set_cb, Ecore_IMF_Input_Panel_Return_Key_Type type, void * user_data)
PROXY_GROUP_BLOCKING(ime_return_key_type_set_cb, Ecore_IMF_Input_Panel_Return_Key_Type type, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES degree, user_data
PROXY_GROUP_NON_BLOCKING(ime_rotation_degree_changed_cb, int degree, void * user_data)
PROXY_GROUP_BLOCKING(ime_rotation_degree_changed_cb, int degree, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES context_id, context, user_data
PROXY_GROUP_NON_BLOCKING(ime_show_cb, int context_id, ime_context_h context, void * user_data)
PROXY_GROUP_BLOCKING(ime_show_cb, int context_id, ime_context_h context, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES context_id, text, cursor_pos, user_data
PROXY_GROUP_NON_BLOCKING(ime_surrounding_text_updated_cb, int context_id, const char * text, int cursor_pos, void * user_data)
PROXY_GROUP_BLOCKING(ime_surrounding_text_updated_cb, int context_id, const char * text, int cursor_pos, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(ime_terminate_cb, void * user_data)
PROXY_GROUP_BLOCKING(ime_terminate_cb, void * user_data)
#undef CB_PARAMS_NAMES


#include <iotcon/iotcon.h>

#define CB_PARAMS_NAMES attributes, key, user_data
PROXY_GROUP_RETURN(iotcon_attributes_cb, bool, iotcon_attributes_h attributes, const char * key, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES child, user_data
PROXY_GROUP_RETURN(iotcon_children_cb, bool, iotcon_representation_h child, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES device_info, result, user_data
PROXY_GROUP_RETURN(iotcon_device_info_cb, bool, iotcon_device_info_h device_info, iotcon_error_e result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES resource, result, user_data
PROXY_GROUP_RETURN(iotcon_found_resource_cb, bool, iotcon_remote_resource_h resource, iotcon_error_e result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES pin, user_data
PROXY_GROUP_NON_BLOCKING(iotcon_generated_pin_cb, const char * pin, void * user_data)
PROXY_GROUP_BLOCKING(iotcon_generated_pin_cb, const char * pin, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES pos, value, user_data
PROXY_GROUP_RETURN(iotcon_list_attributes_cb, bool, int pos, iotcon_attributes_h value, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES pos, value, user_data
PROXY_GROUP_RETURN(iotcon_list_bool_cb, bool, int pos, bool value, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES pos, value, len, user_data
PROXY_GROUP_RETURN(iotcon_list_byte_str_cb, bool, int pos, const unsigned char * value, int len, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES pos, value, user_data
PROXY_GROUP_RETURN(iotcon_list_double_cb, bool, int pos, double value, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES pos, value, user_data
PROXY_GROUP_RETURN(iotcon_list_int_cb, bool, int pos, int value, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES pos, value, user_data
PROXY_GROUP_RETURN(iotcon_list_list_cb, bool, int pos, iotcon_list_h value, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES pos, value, user_data
PROXY_GROUP_RETURN(iotcon_list_str_cb, bool, int pos, const char * value, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES resource, attributes, user_data
PROXY_GROUP_RETURN(iotcon_lite_resource_post_request_cb, bool, iotcon_lite_resource_h resource, iotcon_attributes_h attributes, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES id, data, user_data
PROXY_GROUP_RETURN(iotcon_options_foreach_cb, bool, unsigned short id, const char * data, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES platform_info, result, user_data
PROXY_GROUP_RETURN(iotcon_platform_info_cb, bool, iotcon_platform_info_h platform_info, iotcon_error_e result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES presence, err, response, user_data
PROXY_GROUP_NON_BLOCKING(iotcon_presence_cb, iotcon_presence_h presence, iotcon_error_e err, iotcon_presence_response_h response, void * user_data)
PROXY_GROUP_BLOCKING(iotcon_presence_cb, iotcon_presence_h presence, iotcon_error_e err, iotcon_presence_response_h response, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES key, value, user_data
PROXY_GROUP_RETURN(iotcon_query_foreach_cb, bool, const char * key, const char * value, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES resource, representation, user_data
PROXY_GROUP_NON_BLOCKING(iotcon_remote_resource_cached_representation_changed_cb, iotcon_remote_resource_h resource, iotcon_representation_h representation, void * user_data)
PROXY_GROUP_BLOCKING(iotcon_remote_resource_cached_representation_changed_cb, iotcon_remote_resource_h resource, iotcon_representation_h representation, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES resource, err, sequence_number, response, user_data
PROXY_GROUP_NON_BLOCKING(iotcon_remote_resource_observe_cb, iotcon_remote_resource_h resource, iotcon_error_e err, int sequence_number, iotcon_response_h response, void * user_data)
PROXY_GROUP_BLOCKING(iotcon_remote_resource_observe_cb, iotcon_remote_resource_h resource, iotcon_error_e err, int sequence_number, iotcon_response_h response, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES resource, err, request_type, response, user_data
PROXY_GROUP_NON_BLOCKING(iotcon_remote_resource_response_cb, iotcon_remote_resource_h resource, iotcon_error_e err, iotcon_request_type_e request_type, iotcon_response_h response, void * user_data)
PROXY_GROUP_BLOCKING(iotcon_remote_resource_response_cb, iotcon_remote_resource_h resource, iotcon_error_e err, iotcon_request_type_e request_type, iotcon_response_h response, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES resource, state, user_data
PROXY_GROUP_NON_BLOCKING(iotcon_remote_resource_state_changed_cb, iotcon_remote_resource_h resource, iotcon_remote_resource_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(iotcon_remote_resource_state_changed_cb, iotcon_remote_resource_h resource, iotcon_remote_resource_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES resource, request, user_data
PROXY_GROUP_NON_BLOCKING(iotcon_request_handler_cb, iotcon_resource_h resource, iotcon_request_h request, void * user_data)
PROXY_GROUP_BLOCKING(iotcon_request_handler_cb, iotcon_resource_h resource, iotcon_request_h request, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES iface, user_data
PROXY_GROUP_RETURN(iotcon_resource_interfaces_foreach_cb, bool, const char * iface, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES type, user_data
PROXY_GROUP_RETURN(iotcon_resource_types_foreach_cb, bool, const char * type, void * user_data)
#undef CB_PARAMS_NAMES


#include <location/location_bounds.h>

#include <location/locations.h>

#define CB_PARAMS_NAMES azimuth, elevation, prn, snr, is_active, user_data
PROXY_GROUP_RETURN(gps_status_get_satellites_cb, bool, unsigned int azimuth, unsigned int elevation, unsigned int prn, int snr, bool is_active, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES num_of_active, num_of_inview, timestamp, user_data
PROXY_GROUP_NON_BLOCKING(gps_status_satellite_updated_cb, int num_of_active, int num_of_inview, time_t timestamp, void * user_data)
PROXY_GROUP_BLOCKING(gps_status_satellite_updated_cb, int num_of_active, int num_of_inview, time_t timestamp, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES num_of_location, user_data
PROXY_GROUP_NON_BLOCKING(location_batch_cb, int num_of_location, void * user_data)
PROXY_GROUP_BLOCKING(location_batch_cb, int num_of_location, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES latitude, longitude, altitude, speed, direction, horizontal, vertical, timestamp, user_data
PROXY_GROUP_RETURN(location_batch_get_location_cb, bool, double latitude, double longitude, double altitude, double speed, double direction, double horizontal, double vertical, time_t timestamp, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES bounds, user_data
PROXY_GROUP_RETURN(location_bounds_cb, bool, location_bounds_h bounds, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(location_bounds_state_changed_cb, location_boundary_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(location_bounds_state_changed_cb, location_boundary_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES latitude, longitude, altitude, speed, direction, horizontal_accuracy, timestamp, user_data
PROXY_GROUP_NON_BLOCKING(location_changed_cb, double latitude, double longitude, double altitude, double speed, double direction, double horizontal_accuracy, time_t timestamp, void * user_data)
PROXY_GROUP_BLOCKING(location_changed_cb, double latitude, double longitude, double altitude, double speed, double direction, double horizontal_accuracy, time_t timestamp, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES latitude, longitude, altitude, timestamp, user_data
PROXY_GROUP_NON_BLOCKING(location_position_updated_cb, double latitude, double longitude, double altitude, time_t timestamp, void * user_data)
PROXY_GROUP_BLOCKING(location_position_updated_cb, double latitude, double longitude, double altitude, time_t timestamp, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(location_service_state_changed_cb, location_service_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(location_service_state_changed_cb, location_service_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES method, enable, user_data
PROXY_GROUP_NON_BLOCKING(location_setting_changed_cb, location_method_e method, bool enable, void * user_data)
PROXY_GROUP_BLOCKING(location_setting_changed_cb, location_method_e method, bool enable, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error, latitude, longitude, altitude, timestamp, speed, direction, climb, user_data
PROXY_GROUP_NON_BLOCKING(location_updated_cb, location_error_e error, double latitude, double longitude, double altitude, time_t timestamp, double speed, double direction, double climb, void * user_data)
PROXY_GROUP_BLOCKING(location_updated_cb, location_error_e error, double latitude, double longitude, double altitude, time_t timestamp, double speed, double direction, double climb, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES speed, direction, climb, timestamp, user_data
PROXY_GROUP_NON_BLOCKING(location_velocity_updated_cb, double speed, double direction, double climb, time_t timestamp, void * user_data)
PROXY_GROUP_BLOCKING(location_velocity_updated_cb, double speed, double direction, double climb, time_t timestamp, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, latitude, longitude, altitude, timestamp, user_data
PROXY_GROUP_NON_BLOCKING(location_zone_changed_cb, location_boundary_state_e state, double latitude, double longitude, double altitude, time_t timestamp, void * user_data)
PROXY_GROUP_BLOCKING(location_zone_changed_cb, location_boundary_state_e state, double latitude, double longitude, double altitude, time_t timestamp, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES coords, user_data
PROXY_GROUP_RETURN(polygon_coords_cb, bool, location_coords_s coords, void * user_data)
#undef CB_PARAMS_NAMES


#include <media-content/media_audio.h>

#include <media-content/media_book.h>

#include <media-content/media_bookmark.h>

#include <media-content/media_content.h>

#include <media-content/media_content_type.h>

#include <media-content/media_face.h>

#include <media-content/media_filter.h>

#include <media-content/media_folder.h>

#include <media-content/media_group.h>

#include <media-content/media_image.h>

#include <media-content/media_info.h>

#include <media-content/media_playlist.h>

#include <media-content/media_storage.h>

#include <media-content/media_tag.h>

#include <media-content/media_video.h>

#define CB_PARAMS_NAMES album, user_data
PROXY_GROUP_RETURN(media_album_cb, bool, media_album_h album, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES bookmark, user_data
PROXY_GROUP_RETURN(media_bookmark_cb, bool, media_bookmark_h bookmark, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error, pid, update_item, update_type, media_type, uuid, path, mime_type, user_data
PROXY_GROUP_NON_BLOCKING(media_content_db_update_cb, media_content_error_e error, int pid, media_content_db_update_item_type_e update_item, media_content_db_update_type_e update_type, media_content_type_e media_type, char * uuid, char * path, char * mime_type, void * user_data)
PROXY_GROUP_BLOCKING(media_content_db_update_cb, media_content_error_e error, int pid, media_content_db_update_item_type_e update_item, media_content_db_update_type_e update_type, media_content_type_e media_type, char * uuid, char * path, char * mime_type, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES face, user_data
PROXY_GROUP_RETURN(media_face_cb, bool, media_face_h face, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error, face_count, user_data
PROXY_GROUP_NON_BLOCKING(media_face_detection_completed_cb, media_content_error_e error, const int face_count, void * user_data)
PROXY_GROUP_BLOCKING(media_face_detection_completed_cb, media_content_error_e error, const int face_count, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES folder, user_data
PROXY_GROUP_RETURN(media_folder_cb, bool, media_folder_h folder, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES group_name, user_data
PROXY_GROUP_RETURN(media_group_cb, bool, const char * group_name, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES media, user_data
PROXY_GROUP_RETURN(media_info_cb, bool, media_info_h media, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error, user_data
PROXY_GROUP_NON_BLOCKING(media_insert_completed_cb, media_content_error_e error, void * user_data)
PROXY_GROUP_BLOCKING(media_insert_completed_cb, media_content_error_e error, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES playlist, user_data
PROXY_GROUP_RETURN(media_playlist_cb, bool, media_playlist_h playlist, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error, user_data
PROXY_GROUP_NON_BLOCKING(media_scan_completed_cb, media_content_error_e error, void * user_data)
PROXY_GROUP_BLOCKING(media_scan_completed_cb, media_content_error_e error, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES storage, user_data
PROXY_GROUP_RETURN(media_storage_cb, bool, media_storage_h storage, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES tag, user_data
PROXY_GROUP_RETURN(media_tag_cb, bool, media_tag_h tag, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error, path, user_data
PROXY_GROUP_NON_BLOCKING(media_thumbnail_completed_cb, media_content_error_e error, const char * path, void * user_data)
PROXY_GROUP_BLOCKING(media_thumbnail_completed_cb, media_content_error_e error, const char * path, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES playlist_member_id, media, user_data
PROXY_GROUP_RETURN(playlist_member_cb, bool, int playlist_member_id, media_info_h media, void * user_data)
#undef CB_PARAMS_NAMES


#include <media/audio_io.h>

#include <media/camera.h>

#include <media/image_util.h>

#include <media/image_util_decode.h>

#include <media/image_util_encode.h>

#include <media/image_util_type.h>

#include <media/media_codec.h>

#include <media/media_controller_client.h>

#include <media/media_controller_metadata.h>

#include <media/media_controller_playlist.h>

#include <media/media_controller_server.h>

#include <media/media_controller_type.h>

#include <media/media_format.h>

#include <media/media_packet.h>

#include <media/media_packet_pool.h>

#include <media/media_streamer.h>

#include <media/mediademuxer.h>

#include <media/mediamuxer.h>

#include <media/metadata_extractor.h>

#include <media/metadata_extractor_type.h>

#include <media/mv_barcode.h>

#include <media/mv_barcode_detect.h>

#include <media/mv_barcode_generate.h>

#include <media/mv_barcode_type.h>

#include <media/mv_common.h>

#include <media/mv_face.h>

#include <media/mv_face_type.h>

#include <media/mv_image.h>

#include <media/mv_image_type.h>

#include <media/mv_inference.h>

#include <media/mv_inference_type.h>

#include <media/mv_surveillance.h>

#include <media/player.h>

#include <media/radio.h>

#include <media/recorder.h>

#include <media/scmirroring_sink.h>

#include <media/scmirroring_type.h>

#include <media/sound_manager.h>

#include <media/sound_pool.h>

#include <media/sound_pool_type.h>

#include <media/streamrecorder.h>

#include <media/thumbnail_util.h>

#include <media/thumbnail_util_type.h>

#include <media/tone_player.h>

#include <media/wav_player.h>

#include <media/webrtc.h>

#define CB_PARAMS_NAMES handle, previous, current, by_policy, user_data
PROXY_GROUP_NON_BLOCKING(audio_in_state_changed_cb, audio_in_h handle, audio_io_state_e previous, audio_io_state_e current, bool by_policy, void * user_data)
PROXY_GROUP_BLOCKING(audio_in_state_changed_cb, audio_in_h handle, audio_io_state_e previous, audio_io_state_e current, bool by_policy, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES handle, nbytes, user_data
PROXY_GROUP_NON_BLOCKING(audio_in_stream_cb, audio_in_h handle, size_t nbytes, void * user_data)
PROXY_GROUP_BLOCKING(audio_in_stream_cb, audio_in_h handle, size_t nbytes, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES handle, previous, current, by_policy, user_data
PROXY_GROUP_NON_BLOCKING(audio_out_state_changed_cb, audio_out_h handle, audio_io_state_e previous, audio_io_state_e current, bool by_policy, void * user_data)
PROXY_GROUP_BLOCKING(audio_out_state_changed_cb, audio_out_h handle, audio_io_state_e previous, audio_io_state_e current, bool by_policy, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES handle, nbytes, user_data
PROXY_GROUP_NON_BLOCKING(audio_out_stream_cb, audio_out_h handle, size_t nbytes, void * user_data)
PROXY_GROUP_BLOCKING(audio_out_stream_cb, audio_out_h handle, size_t nbytes, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES percent, user_data
PROXY_GROUP_NON_BLOCKING(camera_attr_hdr_progress_cb, int percent, void * user_data)
PROXY_GROUP_BLOCKING(camera_attr_hdr_progress_cb, int percent, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES mode, user_data
PROXY_GROUP_RETURN(camera_attr_supported_af_mode_cb, bool, camera_attr_af_mode_e mode, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES effect, user_data
PROXY_GROUP_RETURN(camera_attr_supported_effect_cb, bool, camera_attr_effect_mode_e effect, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES mode, user_data
PROXY_GROUP_RETURN(camera_attr_supported_exposure_mode_cb, bool, camera_attr_exposure_mode_e mode, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES mode, user_data
PROXY_GROUP_RETURN(camera_attr_supported_flash_mode_cb, bool, camera_attr_flash_mode_e mode, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES fps, user_data
PROXY_GROUP_RETURN(camera_attr_supported_fps_cb, bool, camera_attr_fps_e fps, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES iso, user_data
PROXY_GROUP_RETURN(camera_attr_supported_iso_cb, bool, camera_attr_iso_e iso, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES type, user_data
PROXY_GROUP_RETURN(camera_attr_supported_ptz_type_cb, bool, camera_attr_ptz_type_e type, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES mode, user_data
PROXY_GROUP_RETURN(camera_attr_supported_scene_mode_cb, bool, camera_attr_scene_mode_e mode, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES flip, user_data
PROXY_GROUP_RETURN(camera_attr_supported_stream_flip_cb, bool, camera_flip_e flip, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES rotation, user_data
PROXY_GROUP_RETURN(camera_attr_supported_stream_rotation_cb, bool, camera_rotation_e rotation, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES mode, user_data
PROXY_GROUP_RETURN(camera_attr_supported_theater_mode_cb, bool, camera_attr_theater_mode_e mode, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES wb, user_data
PROXY_GROUP_RETURN(camera_attr_supported_whitebalance_cb, bool, camera_attr_whitebalance_e wb, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(camera_capture_completed_cb, void * user_data)
PROXY_GROUP_BLOCKING(camera_capture_completed_cb, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES image, postview, thumbnail, user_data
PROXY_GROUP_NON_BLOCKING(camera_capturing_cb, camera_image_data_s * image, camera_image_data_s * postview, camera_image_data_s * thumbnail, void * user_data)
PROXY_GROUP_BLOCKING(camera_capturing_cb, camera_image_data_s * image, camera_image_data_s * postview, camera_image_data_s * thumbnail, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES device, state, user_data
PROXY_GROUP_NON_BLOCKING(camera_device_state_changed_cb, camera_device_e device, camera_device_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(camera_device_state_changed_cb, camera_device_e device, camera_device_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error, current_state, user_data
PROXY_GROUP_NON_BLOCKING(camera_error_cb, camera_error_e error, camera_state_e current_state, void * user_data)
PROXY_GROUP_BLOCKING(camera_error_cb, camera_error_e error, camera_state_e current_state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES faces, count, user_data
PROXY_GROUP_NON_BLOCKING(camera_face_detected_cb, camera_detected_face_s * faces, int count, void * user_data)
PROXY_GROUP_BLOCKING(camera_face_detected_cb, camera_detected_face_s * faces, int count, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(camera_focus_changed_cb, camera_focus_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(camera_focus_changed_cb, camera_focus_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES policy, state, user_data
PROXY_GROUP_NON_BLOCKING(camera_interrupt_started_cb, camera_policy_e policy, camera_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(camera_interrupt_started_cb, camera_policy_e policy, camera_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES policy, previous, current, user_data
PROXY_GROUP_NON_BLOCKING(camera_interrupted_cb, camera_policy_e policy, camera_state_e previous, camera_state_e current, void * user_data)
PROXY_GROUP_BLOCKING(camera_interrupted_cb, camera_policy_e policy, camera_state_e previous, camera_state_e current, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES pkt, user_data
PROXY_GROUP_NON_BLOCKING(camera_media_packet_preview_cb, media_packet_h pkt, void * user_data)
PROXY_GROUP_BLOCKING(camera_media_packet_preview_cb, media_packet_h pkt, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES frame, user_data
PROXY_GROUP_NON_BLOCKING(camera_preview_cb, camera_preview_data_s * frame, void * user_data)
PROXY_GROUP_BLOCKING(camera_preview_cb, camera_preview_data_s * frame, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES previous, current, by_policy, user_data
PROXY_GROUP_NON_BLOCKING(camera_state_changed_cb, camera_state_e previous, camera_state_e current, bool by_policy, void * user_data)
PROXY_GROUP_BLOCKING(camera_state_changed_cb, camera_state_e previous, camera_state_e current, bool by_policy, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES format, user_data
PROXY_GROUP_RETURN(camera_supported_capture_format_cb, bool, camera_pixel_format_e format, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES width, height, user_data
PROXY_GROUP_RETURN(camera_supported_capture_resolution_cb, bool, int width, int height, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES format, user_data
PROXY_GROUP_RETURN(camera_supported_preview_format_cb, bool, camera_pixel_format_e format, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES width, height, user_data
PROXY_GROUP_RETURN(camera_supported_preview_resolution_cb, bool, int width, int height, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error_code, image, user_data
PROXY_GROUP_NON_BLOCKING(image_util_decode_completed2_cb, int error_code, image_util_image_h image, void * user_data)
PROXY_GROUP_BLOCKING(image_util_decode_completed2_cb, int error_code, image_util_image_h image, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error_code, user_data, width, height, size
PROXY_GROUP_NON_BLOCKING(image_util_decode_completed_cb, int error_code, void * user_data, unsigned long width, unsigned long height, unsigned long long size)
PROXY_GROUP_BLOCKING(image_util_decode_completed_cb, int error_code, void * user_data, unsigned long width, unsigned long height, unsigned long long size)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error_code, user_data, size
PROXY_GROUP_NON_BLOCKING(image_util_encode_completed_cb, int error_code, void * user_data, unsigned long long size)
PROXY_GROUP_BLOCKING(image_util_encode_completed_cb, int error_code, void * user_data, unsigned long long size)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error_code, buffer, buffer_size, user_data
PROXY_GROUP_NON_BLOCKING(image_util_encode_to_buffer_completed_cb, image_util_error_e error_code, unsigned char * buffer, size_t buffer_size, void * user_data)
PROXY_GROUP_BLOCKING(image_util_encode_to_buffer_completed_cb, image_util_error_e error_code, unsigned char * buffer, size_t buffer_size, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error_code, user_data
PROXY_GROUP_NON_BLOCKING(image_util_encode_to_file_completed_cb, image_util_error_e error_code, void * user_data)
PROXY_GROUP_BLOCKING(image_util_encode_to_file_completed_cb, image_util_error_e error_code, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES colorspace, user_data
PROXY_GROUP_RETURN(image_util_supported_colorspace_cb, bool, image_util_colorspace_e colorspace, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES dst, error_code, user_data
PROXY_GROUP_NON_BLOCKING(image_util_transform_completed2_cb, image_util_image_h dst, int error_code, void * user_data)
PROXY_GROUP_BLOCKING(image_util_transform_completed2_cb, image_util_image_h dst, int error_code, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES dst, error_code, user_data
PROXY_GROUP_NON_BLOCKING(image_util_transform_completed_cb, media_packet_h * dst, int error_code, void * user_data)
PROXY_GROUP_BLOCKING(image_util_transform_completed_cb, media_packet_h * dst, int error_code, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES server_name, ability, support, user_data
PROXY_GROUP_NON_BLOCKING(mc_ability_support_updated_cb, const char * server_name, mc_ability_e ability, mc_ability_support_e support, void * user_data)
PROXY_GROUP_BLOCKING(mc_ability_support_updated_cb, const char * server_name, mc_ability_e ability, mc_ability_support_e support, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES server_name, supported_items, user_data
PROXY_GROUP_NON_BLOCKING(mc_ability_supported_items_updated_cb, const char * server_name, unsigned int supported_items, void * user_data)
PROXY_GROUP_BLOCKING(mc_ability_supported_items_updated_cb, const char * server_name, unsigned int supported_items, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES client_name, user_data
PROXY_GROUP_RETURN(mc_activated_client_cb, bool, const char * client_name, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES server_name, user_data
PROXY_GROUP_RETURN(mc_activated_server_cb, bool, const char * server_name, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES server_name, enabled, user_data
PROXY_GROUP_NON_BLOCKING(mc_bool_attribute_updated_cb, const char * server_name, bool enabled, void * user_data)
PROXY_GROUP_BLOCKING(mc_bool_attribute_updated_cb, const char * server_name, bool enabled, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES server_name, request_id, event, data, user_data
PROXY_GROUP_NON_BLOCKING(mc_client_custom_event_received_cb, const char * server_name, const char * request_id, const char * event, bundle * data, void * user_data)
PROXY_GROUP_BLOCKING(mc_client_custom_event_received_cb, const char * server_name, const char * request_id, const char * event, bundle * data, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES server_name, request_id, result_code, data, user_data
PROXY_GROUP_NON_BLOCKING(mc_cmd_reply_received_cb, const char * server_name, const char * request_id, int result_code, bundle * data, void * user_data)
PROXY_GROUP_BLOCKING(mc_cmd_reply_received_cb, const char * server_name, const char * request_id, int result_code, bundle * data, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES server_name, mode, user_data
PROXY_GROUP_NON_BLOCKING(mc_display_mode_updated_cb, const char * server_name, mc_display_mode_e mode, void * user_data)
PROXY_GROUP_BLOCKING(mc_display_mode_updated_cb, const char * server_name, mc_display_mode_e mode, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES server_name, rotation, user_data
PROXY_GROUP_NON_BLOCKING(mc_display_rotation_updated_cb, const char * server_name, mc_display_rotation_e rotation, void * user_data)
PROXY_GROUP_BLOCKING(mc_display_rotation_updated_cb, const char * server_name, mc_display_rotation_e rotation, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES server_name, metadata, user_data
PROXY_GROUP_NON_BLOCKING(mc_metadata_updated_cb, const char * server_name, mc_metadata_h metadata, void * user_data)
PROXY_GROUP_BLOCKING(mc_metadata_updated_cb, const char * server_name, mc_metadata_h metadata, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES server_name, ability, user_data
PROXY_GROUP_NON_BLOCKING(mc_playback_ability_updated_cb, const char * server_name, mc_playback_ability_h ability, void * user_data)
PROXY_GROUP_BLOCKING(mc_playback_ability_updated_cb, const char * server_name, mc_playback_ability_h ability, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES server_name, playback, user_data
PROXY_GROUP_NON_BLOCKING(mc_playback_updated_cb, const char * server_name, mc_playback_h playback, void * user_data)
PROXY_GROUP_BLOCKING(mc_playback_updated_cb, const char * server_name, mc_playback_h playback, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES playlist, user_data
PROXY_GROUP_RETURN(mc_playlist_cb, bool, mc_playlist_h playlist, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES index, metadata, user_data
PROXY_GROUP_RETURN(mc_playlist_item_cb, bool, const char * index, mc_metadata_h metadata, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES server_name, mode, playlist_name, playlist, user_data
PROXY_GROUP_NON_BLOCKING(mc_playlist_updated_cb, const char * server_name, mc_playlist_update_mode_e mode, const char * playlist_name, mc_playlist_h playlist, void * user_data)
PROXY_GROUP_BLOCKING(mc_playlist_updated_cb, const char * server_name, mc_playlist_update_mode_e mode, const char * playlist_name, mc_playlist_h playlist, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES server_name, support, user_data
PROXY_GROUP_NON_BLOCKING(mc_repeat_ability_updated_cb, const char * server_name, mc_ability_support_e support, void * user_data)
PROXY_GROUP_BLOCKING(mc_repeat_ability_updated_cb, const char * server_name, mc_ability_support_e support, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES server_name, mode, user_data
PROXY_GROUP_NON_BLOCKING(mc_repeat_mode_updated_cb, const char * server_name, mc_repeat_mode_e mode, void * user_data)
PROXY_GROUP_BLOCKING(mc_repeat_mode_updated_cb, const char * server_name, mc_repeat_mode_e mode, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES content_type, category, search_keyword, data, user_data
PROXY_GROUP_RETURN(mc_search_condition_cb, bool, mc_content_type_e content_type, mc_search_category_e category, const char * search_keyword, bundle * data, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES client_name, request_id, command, data, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_custom_cmd_received_cb, const char * client_name, const char * request_id, const char * command, bundle * data, void * user_data)
PROXY_GROUP_BLOCKING(mc_server_custom_cmd_received_cb, const char * client_name, const char * request_id, const char * command, bundle * data, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES client_name, request_id, mode, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_display_mode_cmd_received_cb, const char * client_name, const char * request_id, mc_display_mode_e mode, void * user_data)
PROXY_GROUP_BLOCKING(mc_server_display_mode_cmd_received_cb, const char * client_name, const char * request_id, mc_display_mode_e mode, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES client_name, request_id, rotation, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_display_rotation_cmd_received_cb, const char * client_name, const char * request_id, mc_display_rotation_e rotation, void * user_data)
PROXY_GROUP_BLOCKING(mc_server_display_rotation_cmd_received_cb, const char * client_name, const char * request_id, mc_display_rotation_e rotation, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES client_name, request_id, enabled, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_enable_cmd_received_cb, const char * client_name, const char * request_id, bool enabled, void * user_data)
PROXY_GROUP_BLOCKING(mc_server_enable_cmd_received_cb, const char * client_name, const char * request_id, bool enabled, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES client_name, request_id, result_code, data, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_event_reply_received_cb, const char * client_name, const char * request_id, int result_code, bundle * data, void * user_data)
PROXY_GROUP_BLOCKING(mc_server_event_reply_received_cb, const char * client_name, const char * request_id, int result_code, bundle * data, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES client_name, request_id, action, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_playback_action_cmd_received_cb, const char * client_name, const char * request_id, mc_playback_action_e action, void * user_data)
PROXY_GROUP_BLOCKING(mc_server_playback_action_cmd_received_cb, const char * client_name, const char * request_id, mc_playback_action_e action, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES client_name, request_id, position, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_playback_position_cmd_received_cb, const char * client_name, const char * request_id, unsigned long long position, void * user_data)
PROXY_GROUP_BLOCKING(mc_server_playback_position_cmd_received_cb, const char * client_name, const char * request_id, unsigned long long position, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES client_name, request_id, playlist_name, index, action, position, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_playlist_cmd_received_cb, const char * client_name, const char * request_id, const char * playlist_name, const char * index, mc_playback_action_e action, unsigned long long position, void * user_data)
PROXY_GROUP_BLOCKING(mc_server_playlist_cmd_received_cb, const char * client_name, const char * request_id, const char * playlist_name, const char * index, mc_playback_action_e action, unsigned long long position, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES client_name, request_id, repeat_mode, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_repeat_mode_cmd_received_cb, const char * client_name, const char * request_id, mc_repeat_mode_e repeat_mode, void * user_data)
PROXY_GROUP_BLOCKING(mc_server_repeat_mode_cmd_received_cb, const char * client_name, const char * request_id, mc_repeat_mode_e repeat_mode, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES client_name, request_id, search, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_search_cmd_received_cb, const char * client_name, const char * request_id, mc_search_h search, void * user_data)
PROXY_GROUP_BLOCKING(mc_server_search_cmd_received_cb, const char * client_name, const char * request_id, mc_search_h search, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES client_name, request_id, shuffle_mode, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_shuffle_mode_cmd_received_cb, const char * client_name, const char * request_id, mc_shuffle_mode_e shuffle_mode, void * user_data)
PROXY_GROUP_BLOCKING(mc_server_shuffle_mode_cmd_received_cb, const char * client_name, const char * request_id, mc_shuffle_mode_e shuffle_mode, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES server_name, state, user_data
PROXY_GROUP_NON_BLOCKING(mc_server_state_updated_cb, const char * server_name, mc_server_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(mc_server_state_updated_cb, const char * server_name, mc_server_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES server_name, support, user_data
PROXY_GROUP_NON_BLOCKING(mc_shuffle_ability_updated_cb, const char * server_name, mc_ability_support_e support, void * user_data)
PROXY_GROUP_BLOCKING(mc_shuffle_ability_updated_cb, const char * server_name, mc_ability_support_e support, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES server_name, mode, user_data
PROXY_GROUP_NON_BLOCKING(mc_shuffle_mode_updated_cb, const char * server_name, mc_shuffle_mode_e mode, void * user_data)
PROXY_GROUP_BLOCKING(mc_shuffle_mode_updated_cb, const char * server_name, mc_shuffle_mode_e mode, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES server_name, user_data
PROXY_GROUP_RETURN(mc_subscribed_server_cb, bool, const char * server_name, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES packet, user_data
PROXY_GROUP_NON_BLOCKING(media_packet_dispose_cb, media_packet_h packet, void * user_data)
PROXY_GROUP_BLOCKING(media_packet_dispose_cb, media_packet_h packet, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES packet, error_code, user_data
PROXY_GROUP_RETURN(media_packet_finalize_cb, int, media_packet_h packet, int error_code, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES src, status, user_data
PROXY_GROUP_NON_BLOCKING(media_streamer_custom_buffer_status_cb, media_streamer_node_h src, media_streamer_custom_buffer_status_e status, void * user_data)
PROXY_GROUP_BLOCKING(media_streamer_custom_buffer_status_cb, media_streamer_node_h src, media_streamer_custom_buffer_status_e status, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES streamer, error, user_data
PROXY_GROUP_NON_BLOCKING(media_streamer_error_cb, media_streamer_h streamer, media_streamer_error_e error, void * user_data)
PROXY_GROUP_BLOCKING(media_streamer_error_cb, media_streamer_h streamer, media_streamer_error_e error, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES code, user_data
PROXY_GROUP_NON_BLOCKING(media_streamer_interrupted_cb, media_streamer_interrupted_code_e code, void * user_data)
PROXY_GROUP_BLOCKING(media_streamer_interrupted_cb, media_streamer_interrupted_code_e code, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES node, src_pad_name, media_type, user_data
PROXY_GROUP_NON_BLOCKING(media_streamer_node_decoded_ready_cb, media_streamer_node_h node, const char * src_pad_name, const char * media_type, void * user_data)
PROXY_GROUP_BLOCKING(media_streamer_node_decoded_ready_cb, media_streamer_node_h node, const char * src_pad_name, const char * media_type, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(media_streamer_position_changed_cb, void * user_data)
PROXY_GROUP_BLOCKING(media_streamer_position_changed_cb, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES sink, user_data
PROXY_GROUP_NON_BLOCKING(media_streamer_sink_data_ready_cb, media_streamer_node_h sink, void * user_data)
PROXY_GROUP_BLOCKING(media_streamer_sink_data_ready_cb, media_streamer_node_h sink, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES sink, user_data
PROXY_GROUP_NON_BLOCKING(media_streamer_sink_eos_cb, media_streamer_node_h sink, void * user_data)
PROXY_GROUP_BLOCKING(media_streamer_sink_eos_cb, media_streamer_node_h sink, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES streamer, previous_state, current_state, user_data
PROXY_GROUP_NON_BLOCKING(media_streamer_state_changed_cb, media_streamer_h streamer, media_streamer_state_e previous_state, media_streamer_state_e current_state, void * user_data)
PROXY_GROUP_BLOCKING(media_streamer_state_changed_cb, media_streamer_h streamer, media_streamer_state_e previous_state, media_streamer_state_e current_state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES webrtc, message, user_data
PROXY_GROUP_NON_BLOCKING(media_streamer_webrtc_message_cb, media_streamer_node_h webrtc, const char * message, void * user_data)
PROXY_GROUP_BLOCKING(media_streamer_webrtc_message_cb, media_streamer_node_h webrtc, const char * message, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES status, user_data
PROXY_GROUP_NON_BLOCKING(mediacodec_buffer_status_cb, mediacodec_status_e status, void * user_data)
PROXY_GROUP_BLOCKING(mediacodec_buffer_status_cb, mediacodec_status_e status, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(mediacodec_eos_cb, void * user_data)
PROXY_GROUP_BLOCKING(mediacodec_eos_cb, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error, user_data
PROXY_GROUP_NON_BLOCKING(mediacodec_error_cb, mediacodec_error_e error, void * user_data)
PROXY_GROUP_BLOCKING(mediacodec_error_cb, mediacodec_error_e error, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES packet, user_data
PROXY_GROUP_NON_BLOCKING(mediacodec_input_buffer_used_cb, media_packet_h packet, void * user_data)
PROXY_GROUP_BLOCKING(mediacodec_input_buffer_used_cb, media_packet_h packet, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES packet, user_data
PROXY_GROUP_NON_BLOCKING(mediacodec_output_buffer_available_cb, media_packet_h packet, void * user_data)
PROXY_GROUP_BLOCKING(mediacodec_output_buffer_available_cb, media_packet_h packet, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES codec_type, user_data
PROXY_GROUP_RETURN(mediacodec_supported_codec_cb, bool, mediacodec_codec_type_e codec_type, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES track_num, user_data
PROXY_GROUP_NON_BLOCKING(mediademuxer_eos_cb, int track_num, void * user_data)
PROXY_GROUP_BLOCKING(mediademuxer_eos_cb, int track_num, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error, user_data
PROXY_GROUP_NON_BLOCKING(mediademuxer_error_cb, mediademuxer_error_e error, void * user_data)
PROXY_GROUP_BLOCKING(mediademuxer_error_cb, mediademuxer_error_e error, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(mediamuxer_eos_cb, void * user_data)
PROXY_GROUP_BLOCKING(mediamuxer_eos_cb, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error, user_data
PROXY_GROUP_NON_BLOCKING(mediamuxer_error_cb, mediamuxer_error_e error, void * user_data)
PROXY_GROUP_BLOCKING(mediamuxer_error_cb, mediamuxer_error_e error, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES source, engine_cfg, barcode_locations, messages, types, number_of_barcodes, user_data
PROXY_GROUP_NON_BLOCKING(mv_barcode_detected_cb, mv_source_h source, mv_engine_config_h engine_cfg, const mv_quadrangle_s * barcode_locations, const char** messages, const mv_barcode_type_e * types, int number_of_barcodes, void * user_data)
PROXY_GROUP_BLOCKING(mv_barcode_detected_cb, mv_source_h source, mv_engine_config_h engine_cfg, const mv_quadrangle_s * barcode_locations, const char** messages, const mv_barcode_type_e * types, int number_of_barcodes, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES source, engine_cfg, faces_locations, number_of_faces, user_data
PROXY_GROUP_NON_BLOCKING(mv_face_detected_cb, mv_source_h source, mv_engine_config_h engine_cfg, mv_rectangle_s * faces_locations, int number_of_faces, void * user_data)
PROXY_GROUP_BLOCKING(mv_face_detected_cb, mv_source_h source, mv_engine_config_h engine_cfg, mv_rectangle_s * faces_locations, int number_of_faces, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES source, engine_cfg, face_location, eye_condition, user_data
PROXY_GROUP_NON_BLOCKING(mv_face_eye_condition_recognized_cb, mv_source_h source, mv_engine_config_h engine_cfg, mv_rectangle_s face_location, mv_face_eye_condition_e eye_condition, void * user_data)
PROXY_GROUP_BLOCKING(mv_face_eye_condition_recognized_cb, mv_source_h source, mv_engine_config_h engine_cfg, mv_rectangle_s face_location, mv_face_eye_condition_e eye_condition, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES source, engine_cfg, face_location, facial_expression, user_data
PROXY_GROUP_NON_BLOCKING(mv_face_facial_expression_recognized_cb, mv_source_h source, mv_engine_config_h engine_cfg, mv_rectangle_s face_location, mv_face_facial_expression_e facial_expression, void * user_data)
PROXY_GROUP_BLOCKING(mv_face_facial_expression_recognized_cb, mv_source_h source, mv_engine_config_h engine_cfg, mv_rectangle_s face_location, mv_face_facial_expression_e facial_expression, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES source, recognition_model, engine_cfg, face_location, face_label, confidence, user_data
PROXY_GROUP_NON_BLOCKING(mv_face_recognized_cb, mv_source_h source, mv_face_recognition_model_h recognition_model, mv_engine_config_h engine_cfg, mv_rectangle_s * face_location, const int * face_label, double confidence, void * user_data)
PROXY_GROUP_BLOCKING(mv_face_recognized_cb, mv_source_h source, mv_face_recognition_model_h recognition_model, mv_engine_config_h engine_cfg, mv_rectangle_s * face_location, const int * face_label, double confidence, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES source, tracking_model, engine_cfg, location, confidence, user_data
PROXY_GROUP_NON_BLOCKING(mv_face_tracked_cb, mv_source_h source, mv_face_tracking_model_h tracking_model, mv_engine_config_h engine_cfg, mv_quadrangle_s * location, double confidence, void * user_data)
PROXY_GROUP_BLOCKING(mv_face_tracked_cb, mv_source_h source, mv_face_tracking_model_h tracking_model, mv_engine_config_h engine_cfg, mv_quadrangle_s * location, double confidence, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES source, engine_cfg, image_objects, locations, number_of_objects, user_data
PROXY_GROUP_NON_BLOCKING(mv_image_recognized_cb, mv_source_h source, mv_engine_config_h engine_cfg, const mv_image_object_h * image_objects, mv_quadrangle_s ** locations, unsigned int number_of_objects, void * user_data)
PROXY_GROUP_BLOCKING(mv_image_recognized_cb, mv_source_h source, mv_engine_config_h engine_cfg, const mv_image_object_h * image_objects, mv_quadrangle_s ** locations, unsigned int number_of_objects, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES source, image_tracking_model, engine_cfg, location, user_data
PROXY_GROUP_NON_BLOCKING(mv_image_tracked_cb, mv_source_h source, mv_image_tracking_model_h image_tracking_model, mv_engine_config_h engine_cfg, mv_quadrangle_s * location, void * user_data)
PROXY_GROUP_BLOCKING(mv_image_tracked_cb, mv_source_h source, mv_image_tracking_model_h image_tracking_model, mv_engine_config_h engine_cfg, mv_quadrangle_s * location, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES source, number_of_faces, confidences, locations, user_data
PROXY_GROUP_NON_BLOCKING(mv_inference_face_detected_cb, mv_source_h source, int number_of_faces, const float * confidences, const mv_rectangle_s * locations, void * user_data)
PROXY_GROUP_BLOCKING(mv_inference_face_detected_cb, mv_source_h source, int number_of_faces, const float * confidences, const mv_rectangle_s * locations, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES source, number_of_landmarks, locations, user_data
PROXY_GROUP_NON_BLOCKING(mv_inference_facial_landmark_detected_cb, mv_source_h source, int number_of_landmarks, const mv_point_s * locations, void * user_data)
PROXY_GROUP_BLOCKING(mv_inference_facial_landmark_detected_cb, mv_source_h source, int number_of_landmarks, const mv_point_s * locations, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES source, number_of_classes, indices, names, confidences, user_data
PROXY_GROUP_NON_BLOCKING(mv_inference_image_classified_cb, mv_source_h source, int number_of_classes, const int * indices, const char ** names, const float * confidences, void * user_data)
PROXY_GROUP_BLOCKING(mv_inference_image_classified_cb, mv_source_h source, int number_of_classes, const int * indices, const char ** names, const float * confidences, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES source, number_of_objects, indices, names, confidences, locations, user_data
PROXY_GROUP_NON_BLOCKING(mv_inference_object_detected_cb, mv_source_h source, int number_of_objects, const int * indices, const char ** names, const float * confidences, const mv_rectangle_s * locations, void * user_data)
PROXY_GROUP_BLOCKING(mv_inference_object_detected_cb, mv_source_h source, int number_of_objects, const int * indices, const char ** names, const float * confidences, const mv_rectangle_s * locations, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES source, locations, user_data
PROXY_GROUP_NON_BLOCKING(mv_inference_pose_landmark_detected_cb, mv_source_h source, mv_inference_pose_result_h locations, void * user_data)
PROXY_GROUP_BLOCKING(mv_inference_pose_landmark_detected_cb, mv_source_h source, mv_inference_pose_result_h locations, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES engine, supported, user_data
PROXY_GROUP_RETURN(mv_inference_supported_engine_cb, bool, const char * engine, bool supported, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES attribute_type, attribute_name, user_data
PROXY_GROUP_RETURN(mv_supported_attribute_cb, bool, mv_config_attribute_type_e attribute_type, const char * attribute_name, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES trigger, source, video_stream_id, event_result, user_data
PROXY_GROUP_NON_BLOCKING(mv_surveillance_event_occurred_cb, mv_surveillance_event_trigger_h trigger, mv_source_h source, int video_stream_id, mv_surveillance_result_h event_result, void * user_data)
PROXY_GROUP_BLOCKING(mv_surveillance_event_occurred_cb, mv_surveillance_event_trigger_h trigger, mv_source_h source, int video_stream_id, mv_surveillance_result_h event_result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES name, user_data
PROXY_GROUP_RETURN(mv_surveillance_event_result_name_cb, bool, const char * name, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES event_type, user_data
PROXY_GROUP_RETURN(mv_surveillance_event_type_cb, bool, const char * event_type, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES bandwidth, width, height, user_data
PROXY_GROUP_NON_BLOCKING(player_adaptive_variant_cb, int bandwidth, int width, int height, void * user_data)
PROXY_GROUP_BLOCKING(player_adaptive_variant_cb, int bandwidth, int width, int height, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES percent, user_data
PROXY_GROUP_NON_BLOCKING(player_buffering_cb, int percent, void * user_data)
PROXY_GROUP_BLOCKING(player_buffering_cb, int percent, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(player_completed_cb, void * user_data)
PROXY_GROUP_BLOCKING(player_completed_cb, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error_code, user_data
PROXY_GROUP_NON_BLOCKING(player_error_cb, int error_code, void * user_data)
PROXY_GROUP_BLOCKING(player_error_cb, int error_code, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES code, user_data
PROXY_GROUP_NON_BLOCKING(player_interrupted_cb, player_interrupted_code_e code, void * user_data)
PROXY_GROUP_BLOCKING(player_interrupted_cb, player_interrupted_code_e code, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES packet, user_data
PROXY_GROUP_NON_BLOCKING(player_media_packet_audio_decoded_cb, media_packet_h packet, void * user_data)
PROXY_GROUP_BLOCKING(player_media_packet_audio_decoded_cb, media_packet_h packet, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES packet, user_data
PROXY_GROUP_NON_BLOCKING(player_media_packet_video_decoded_cb, media_packet_h packet, void * user_data)
PROXY_GROUP_BLOCKING(player_media_packet_video_decoded_cb, media_packet_h packet, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES status, user_data
PROXY_GROUP_NON_BLOCKING(player_media_stream_buffer_status_cb, player_media_stream_buffer_status_e status, void * user_data)
PROXY_GROUP_BLOCKING(player_media_stream_buffer_status_cb, player_media_stream_buffer_status_e status, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES offset, user_data
PROXY_GROUP_NON_BLOCKING(player_media_stream_seek_cb, unsigned long long offset, void * user_data)
PROXY_GROUP_BLOCKING(player_media_stream_seek_cb, unsigned long long offset, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(player_prepared_cb, void * user_data)
PROXY_GROUP_BLOCKING(player_prepared_cb, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(player_seek_completed_cb, void * user_data)
PROXY_GROUP_BLOCKING(player_seek_completed_cb, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES duration, text, user_data
PROXY_GROUP_NON_BLOCKING(player_subtitle_updated_cb, unsigned long duration, char * text, void * user_data)
PROXY_GROUP_BLOCKING(player_subtitle_updated_cb, unsigned long duration, char * text, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES format, user_data
PROXY_GROUP_RETURN(player_supported_media_format_cb, bool, media_format_mimetype_e format, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES captured_data, width, height, size, user_data
PROXY_GROUP_NON_BLOCKING(player_video_captured_cb, unsigned char * captured_data, int width, int height, unsigned int size, void * user_data)
PROXY_GROUP_BLOCKING(player_video_captured_cb, unsigned char * captured_data, int width, int height, unsigned int size, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES width, height, fps, bit_rate, user_data
PROXY_GROUP_NON_BLOCKING(player_video_stream_changed_cb, int width, int height, int fps, int bit_rate, void * user_data)
PROXY_GROUP_BLOCKING(player_video_stream_changed_cb, int width, int height, int fps, int bit_rate, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES code, user_data
PROXY_GROUP_NON_BLOCKING(radio_interrupted_cb, radio_interrupted_code_e code, void * user_data)
PROXY_GROUP_BLOCKING(radio_interrupted_cb, radio_interrupted_code_e code, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(radio_scan_completed_cb, void * user_data)
PROXY_GROUP_BLOCKING(radio_scan_completed_cb, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(radio_scan_stopped_cb, void * user_data)
PROXY_GROUP_BLOCKING(radio_scan_stopped_cb, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES frequency, user_data
PROXY_GROUP_NON_BLOCKING(radio_scan_updated_cb, int frequency, void * user_data)
PROXY_GROUP_BLOCKING(radio_scan_updated_cb, int frequency, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES frequency, user_data
PROXY_GROUP_NON_BLOCKING(radio_seek_completed_cb, int frequency, void * user_data)
PROXY_GROUP_BLOCKING(radio_seek_completed_cb, int frequency, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES stream, size, format, channel, timestamp, user_data
PROXY_GROUP_NON_BLOCKING(recorder_audio_stream_cb, void * stream, int size, audio_sample_type_e format, int channel, unsigned int timestamp, void * user_data)
PROXY_GROUP_BLOCKING(recorder_audio_stream_cb, void * stream, int size, audio_sample_type_e format, int channel, unsigned int timestamp, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES type, state, user_data
PROXY_GROUP_NON_BLOCKING(recorder_device_state_changed_cb, recorder_type_e type, recorder_device_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(recorder_device_state_changed_cb, recorder_type_e type, recorder_device_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error, current_state, user_data
PROXY_GROUP_NON_BLOCKING(recorder_error_cb, recorder_error_e error, recorder_state_e current_state, void * user_data)
PROXY_GROUP_BLOCKING(recorder_error_cb, recorder_error_e error, recorder_state_e current_state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES policy, state, user_data
PROXY_GROUP_NON_BLOCKING(recorder_interrupt_started_cb, recorder_policy_e policy, recorder_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(recorder_interrupt_started_cb, recorder_policy_e policy, recorder_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES policy, previous, current, user_data
PROXY_GROUP_NON_BLOCKING(recorder_interrupted_cb, recorder_policy_e policy, recorder_state_e previous, recorder_state_e current, void * user_data)
PROXY_GROUP_BLOCKING(recorder_interrupted_cb, recorder_policy_e policy, recorder_state_e previous, recorder_state_e current, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES stream, size, offset, user_data
PROXY_GROUP_NON_BLOCKING(recorder_muxed_stream_cb, void * stream, int size, unsigned long long offset, void * user_data)
PROXY_GROUP_BLOCKING(recorder_muxed_stream_cb, void * stream, int size, unsigned long long offset, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES type, user_data
PROXY_GROUP_NON_BLOCKING(recorder_recording_limit_reached_cb, recorder_recording_limit_type_e type, void * user_data)
PROXY_GROUP_BLOCKING(recorder_recording_limit_reached_cb, recorder_recording_limit_type_e type, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES elapsed_time, file_size, user_data
PROXY_GROUP_NON_BLOCKING(recorder_recording_status_cb, unsigned long long elapsed_time, unsigned long long file_size, void * user_data)
PROXY_GROUP_BLOCKING(recorder_recording_status_cb, unsigned long long elapsed_time, unsigned long long file_size, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES previous, current, by_policy, user_data
PROXY_GROUP_NON_BLOCKING(recorder_state_changed_cb, recorder_state_e previous, recorder_state_e current, bool by_policy, void * user_data)
PROXY_GROUP_BLOCKING(recorder_state_changed_cb, recorder_state_e previous, recorder_state_e current, bool by_policy, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES codec, user_data
PROXY_GROUP_RETURN(recorder_supported_audio_encoder_cb, bool, recorder_audio_codec_e codec, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES format, user_data
PROXY_GROUP_RETURN(recorder_supported_file_format_cb, bool, recorder_file_format_e format, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES codec, user_data
PROXY_GROUP_RETURN(recorder_supported_video_encoder_cb, bool, recorder_video_codec_e codec, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES width, height, user_data
PROXY_GROUP_RETURN(recorder_supported_video_resolution_cb, bool, int width, int height, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES frame, user_data
PROXY_GROUP_RETURN(recorder_video_encode_decision_cb, bool, recorder_video_data_s * frame, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error, state, user_data
PROXY_GROUP_NON_BLOCKING(scmirroring_sink_state_cb, scmirroring_error_e error, scmirroring_sink_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(scmirroring_sink_state_cb, scmirroring_error_e error, scmirroring_sink_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES device, is_connected, user_data
PROXY_GROUP_NON_BLOCKING(sound_device_connection_changed_cb, sound_device_h device, bool is_connected, void * user_data)
PROXY_GROUP_BLOCKING(sound_device_connection_changed_cb, sound_device_h device, bool is_connected, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES device, is_running, user_data
PROXY_GROUP_NON_BLOCKING(sound_device_running_changed_cb, sound_device_h device, bool is_running, void * user_data)
PROXY_GROUP_BLOCKING(sound_device_running_changed_cb, sound_device_h device, bool is_running, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES device, state, user_data
PROXY_GROUP_NON_BLOCKING(sound_device_state_changed_cb, sound_device_h device, sound_device_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(sound_device_state_changed_cb, sound_device_h device, sound_device_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES type, volume, user_data
PROXY_GROUP_NON_BLOCKING(sound_manager_volume_changed_cb, sound_type_e type, unsigned int volume, void * user_data)
PROXY_GROUP_BLOCKING(sound_manager_volume_changed_cb, sound_type_e type, unsigned int volume, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES pool, prev_state, cur_state, user_data
PROXY_GROUP_NON_BLOCKING(sound_pool_state_changed_cb, sound_pool_h pool, sound_pool_state_e prev_state, sound_pool_state_e cur_state, void * user_data)
PROXY_GROUP_BLOCKING(sound_pool_state_changed_cb, sound_pool_h pool, sound_pool_state_e prev_state, sound_pool_state_e cur_state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES pool, id, prev_state, cur_state, user_data
PROXY_GROUP_NON_BLOCKING(sound_pool_stream_state_changed_cb, sound_pool_h pool, unsigned id, sound_pool_stream_state_e prev_state, sound_pool_stream_state_e cur_state, void * user_data)
PROXY_GROUP_BLOCKING(sound_pool_stream_state_changed_cb, sound_pool_h pool, unsigned id, sound_pool_stream_state_e prev_state, sound_pool_stream_state_e cur_state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES stream_ducking, is_ducked, user_data
PROXY_GROUP_NON_BLOCKING(sound_stream_ducking_state_changed_cb, sound_stream_ducking_h stream_ducking, bool is_ducked, void * user_data)
PROXY_GROUP_BLOCKING(sound_stream_ducking_state_changed_cb, sound_stream_ducking_h stream_ducking, bool is_ducked, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES stream_info, focus_mask, focus_state, reason, sound_behavior, extra_info, user_data
PROXY_GROUP_NON_BLOCKING(sound_stream_focus_state_changed_cb, sound_stream_info_h stream_info, sound_stream_focus_mask_e focus_mask, sound_stream_focus_state_e focus_state, sound_stream_focus_change_reason_e reason, int sound_behavior, const char * extra_info, void * user_data)
PROXY_GROUP_BLOCKING(sound_stream_focus_state_changed_cb, sound_stream_info_h stream_info, sound_stream_focus_mask_e focus_mask, sound_stream_focus_state_e focus_state, sound_stream_focus_change_reason_e reason, int sound_behavior, const char * extra_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES id, focus_mask, focus_state, reason, extra_info, user_data
PROXY_GROUP_NON_BLOCKING(sound_stream_focus_state_watch_cb, int id, sound_stream_focus_mask_e focus_mask, sound_stream_focus_state_e focus_state, sound_stream_focus_change_reason_e reason, const char * extra_info, void * user_data)
PROXY_GROUP_BLOCKING(sound_stream_focus_state_watch_cb, int id, sound_stream_focus_mask_e focus_mask, sound_stream_focus_state_e focus_state, sound_stream_focus_change_reason_e reason, const char * extra_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES buffer, user_data
PROXY_GROUP_NON_BLOCKING(streamrecorder_consume_completed_cb, void * buffer, void * user_data)
PROXY_GROUP_BLOCKING(streamrecorder_consume_completed_cb, void * buffer, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error, current_state, user_data
PROXY_GROUP_NON_BLOCKING(streamrecorder_error_cb, streamrecorder_error_e error, streamrecorder_state_e current_state, void * user_data)
PROXY_GROUP_BLOCKING(streamrecorder_error_cb, streamrecorder_error_e error, streamrecorder_state_e current_state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES previous, current, notification, user_data
PROXY_GROUP_NON_BLOCKING(streamrecorder_notify_cb, streamrecorder_state_e previous, streamrecorder_state_e current, streamrecorder_notify_e notification, void * user_data)
PROXY_GROUP_BLOCKING(streamrecorder_notify_cb, streamrecorder_state_e previous, streamrecorder_state_e current, streamrecorder_notify_e notification, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES type, user_data
PROXY_GROUP_NON_BLOCKING(streamrecorder_recording_limit_reached_cb, streamrecorder_recording_limit_type_e type, void * user_data)
PROXY_GROUP_BLOCKING(streamrecorder_recording_limit_reached_cb, streamrecorder_recording_limit_type_e type, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES elapsed_time, file_size, user_data
PROXY_GROUP_NON_BLOCKING(streamrecorder_recording_status_cb, unsigned long long elapsed_time, unsigned long long file_size, void * user_data)
PROXY_GROUP_BLOCKING(streamrecorder_recording_status_cb, unsigned long long elapsed_time, unsigned long long file_size, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES codec, user_data
PROXY_GROUP_RETURN(streamrecorder_supported_audio_encoder_cb, bool, streamrecorder_audio_codec_e codec, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES format, user_data
PROXY_GROUP_RETURN(streamrecorder_supported_file_format_cb, bool, streamrecorder_file_format_e format, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES codec, user_data
PROXY_GROUP_RETURN(streamrecorder_supported_video_encoder_cb, bool, streamrecorder_video_codec_e codec, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES width, height, user_data
PROXY_GROUP_RETURN(streamrecorder_supported_video_resolution_cb, bool, int width, int height, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error, request_id, thumb_width, thumb_height, thumb_data, thumb_size, user_data
PROXY_GROUP_NON_BLOCKING(thumbnail_extracted_cb, thumbnail_util_error_e error, const char * request_id, int thumb_width, int thumb_height, unsigned char * thumb_data, int thumb_size, void * user_data)
PROXY_GROUP_BLOCKING(thumbnail_extracted_cb, thumbnail_util_error_e error, const char * request_id, int thumb_width, int thumb_height, unsigned char * thumb_data, int thumb_size, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES id, user_data
PROXY_GROUP_NON_BLOCKING(wav_player_playback_completed_cb, int id, void * user_data)
PROXY_GROUP_BLOCKING(wav_player_playback_completed_cb, int id, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES webrtc, channel, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_data_channel_cb, webrtc_h webrtc, webrtc_data_channel_h channel, void * user_data)
PROXY_GROUP_BLOCKING(webrtc_data_channel_cb, webrtc_h webrtc, webrtc_data_channel_h channel, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES channel, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_data_channel_close_cb, webrtc_data_channel_h channel, void * user_data)
PROXY_GROUP_BLOCKING(webrtc_data_channel_close_cb, webrtc_data_channel_h channel, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES channel, error, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_data_channel_error_cb, webrtc_data_channel_h channel, webrtc_error_e error, void * user_data)
PROXY_GROUP_BLOCKING(webrtc_data_channel_error_cb, webrtc_data_channel_h channel, webrtc_error_e error, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES channel, type, message, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_data_channel_message_cb, webrtc_data_channel_h channel, webrtc_data_channel_type_e type, void * message, void * user_data)
PROXY_GROUP_BLOCKING(webrtc_data_channel_message_cb, webrtc_data_channel_h channel, webrtc_data_channel_type_e type, void * message, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES channel, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_data_channel_open_cb, webrtc_data_channel_h channel, void * user_data)
PROXY_GROUP_BLOCKING(webrtc_data_channel_open_cb, webrtc_data_channel_h channel, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES webrtc, type, track_id, packet, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_encoded_frame_cb, webrtc_h webrtc, webrtc_media_type_e type, unsigned int track_id, media_packet_h packet, void * user_data)
PROXY_GROUP_BLOCKING(webrtc_encoded_frame_cb, webrtc_h webrtc, webrtc_media_type_e type, unsigned int track_id, media_packet_h packet, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES webrtc, error, state, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_error_cb, webrtc_h webrtc, webrtc_error_e error, webrtc_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(webrtc_error_cb, webrtc_h webrtc, webrtc_error_e error, webrtc_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES webrtc, candidate, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_ice_candidate_cb, webrtc_h webrtc, const char * candidate, void * user_data)
PROXY_GROUP_BLOCKING(webrtc_ice_candidate_cb, webrtc_h webrtc, const char * candidate, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES webrtc, state, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_ice_connection_state_change_cb, webrtc_h webrtc, webrtc_ice_connection_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(webrtc_ice_connection_state_change_cb, webrtc_h webrtc, webrtc_ice_connection_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES webrtc, state, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_ice_gathering_state_change_cb, webrtc_h webrtc, webrtc_ice_gathering_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(webrtc_ice_gathering_state_change_cb, webrtc_h webrtc, webrtc_ice_gathering_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES source_id, state, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_media_packet_source_buffer_state_changed_cb, unsigned int source_id, webrtc_media_packet_source_buffer_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(webrtc_media_packet_source_buffer_state_changed_cb, unsigned int source_id, webrtc_media_packet_source_buffer_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES webrtc, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_negotiation_needed_cb, webrtc_h webrtc, void * user_data)
PROXY_GROUP_BLOCKING(webrtc_negotiation_needed_cb, webrtc_h webrtc, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES webrtc, state, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_peer_connection_state_change_cb, webrtc_h webrtc, webrtc_peer_connection_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(webrtc_peer_connection_state_change_cb, webrtc_h webrtc, webrtc_peer_connection_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES webrtc, description, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_session_description_created_cb, webrtc_h webrtc, const char * description, void * user_data)
PROXY_GROUP_BLOCKING(webrtc_session_description_created_cb, webrtc_h webrtc, const char * description, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES webrtc, state, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_signaling_state_change_cb, webrtc_h webrtc, webrtc_signaling_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(webrtc_signaling_state_change_cb, webrtc_h webrtc, webrtc_signaling_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES webrtc, previous, current, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_state_changed_cb, webrtc_h webrtc, webrtc_state_e previous, webrtc_state_e current, void * user_data)
PROXY_GROUP_BLOCKING(webrtc_state_changed_cb, webrtc_h webrtc, webrtc_state_e previous, webrtc_state_e current, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES webrtc, type, track_id, user_data
PROXY_GROUP_NON_BLOCKING(webrtc_track_added_cb, webrtc_h webrtc, webrtc_media_type_e type, unsigned int track_id, void * user_data)
PROXY_GROUP_BLOCKING(webrtc_track_added_cb, webrtc_h webrtc, webrtc_media_type_e type, unsigned int track_id, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES turn_server, user_data
PROXY_GROUP_RETURN(webrtc_turn_server_cb, bool, const char * turn_server, void * user_data)
#undef CB_PARAMS_NAMES


#include <messaging/email.h>

#include <messaging/email_error.h>

#include <messaging/email_types.h>

#define CB_PARAMS_NAMES email, result, user_data
PROXY_GROUP_NON_BLOCKING(email_message_sent_cb, email_h email, email_sending_e result, void * user_data)
PROXY_GROUP_BLOCKING(email_message_sent_cb, email_h email, email_sending_e result, void * user_data)
#undef CB_PARAMS_NAMES




#include <multi_assistant_common.h>

#define CB_PARAMS_NAMES previous, current, user_data
PROXY_GROUP_NON_BLOCKING(ma_active_state_changed_cb, ma_active_state_e previous, ma_active_state_e current, void * user_data)
PROXY_GROUP_BLOCKING(ma_active_state_changed_cb, ma_active_state_e previous, ma_active_state_e current, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES handle, user_data
PROXY_GROUP_RETURN(ma_assistant_info_list_cb, int, ma_assistant_info_h handle, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES event, buffer, len, user_data
PROXY_GROUP_NON_BLOCKING(ma_audio_streaming_cb, ma_audio_streaming_event_e event, char * buffer, int len, void * user_data)
PROXY_GROUP_BLOCKING(ma_audio_streaming_cb, ma_audio_streaming_event_e event, char * buffer, int len, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES section, user_data
PROXY_GROUP_NON_BLOCKING(ma_audio_streaming_data_section_changed_cb, ma_audio_streaming_data_section_e section, void * user_data)
PROXY_GROUP_BLOCKING(ma_audio_streaming_data_section_changed_cb, ma_audio_streaming_data_section_e section, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES reason, user_data
PROXY_GROUP_NON_BLOCKING(ma_error_cb, ma_error_e reason, void * user_data)
PROXY_GROUP_BLOCKING(ma_error_cb, ma_error_e reason, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES previous, current, user_data
PROXY_GROUP_NON_BLOCKING(ma_language_changed_cb, const char * previous, const char * current, void * user_data)
PROXY_GROUP_BLOCKING(ma_language_changed_cb, const char * previous, const char * current, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES app_id, user_data
PROXY_GROUP_NON_BLOCKING(ma_preprocessing_information_changed_cb, const char * app_id, void * user_data)
PROXY_GROUP_BLOCKING(ma_preprocessing_information_changed_cb, const char * app_id, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES previous, current, user_data
PROXY_GROUP_NON_BLOCKING(ma_service_state_changed_cb, ma_service_state_e previous, ma_service_state_e current, void * user_data)
PROXY_GROUP_BLOCKING(ma_service_state_changed_cb, ma_service_state_e previous, ma_service_state_e current, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES previous, current, user_data
PROXY_GROUP_NON_BLOCKING(ma_state_changed_cb, ma_state_e previous, ma_state_e current, void * user_data)
PROXY_GROUP_BLOCKING(ma_state_changed_cb, ma_state_e previous, ma_state_e current, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES status, user_data
PROXY_GROUP_NON_BLOCKING(ma_voice_key_status_changed_cb, ma_voice_key_status_e status, void * user_data)
PROXY_GROUP_BLOCKING(ma_voice_key_status_changed_cb, ma_voice_key_status_e status, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES command, user_data
PROXY_GROUP_NON_BLOCKING(ma_wakeup_engine_command_cb, const char * command, void * user_data)
PROXY_GROUP_BLOCKING(ma_wakeup_engine_command_cb, const char * command, void * user_data)
#undef CB_PARAMS_NAMES


#include <network/bluetooth.h>

#include <network/bluetooth_type.h>

#include <network/connection_profile.h>

#include <network/http.h>

#include <network/inm.h>

#include <network/net_connection.h>

#include <network/softap.h>

#include <network/stc.h>

#include <network/wifi-manager.h>

#define CB_PARAMS_NAMES device_info, user_data
PROXY_GROUP_RETURN(bt_adapter_bonded_device_cb, bool, bt_device_info_s * device_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, discovery_state, discovery_info, user_data
PROXY_GROUP_NON_BLOCKING(bt_adapter_device_discovery_state_changed_cb, int result, bt_adapter_device_discovery_state_e discovery_state, bt_adapter_device_discovery_info_s * discovery_info, void * user_data)
PROXY_GROUP_BLOCKING(bt_adapter_device_discovery_state_changed_cb, int result, bt_adapter_device_discovery_state_e discovery_state, bt_adapter_device_discovery_info_s * discovery_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, advertiser, adv_state, user_data
PROXY_GROUP_NON_BLOCKING(bt_adapter_le_advertising_state_changed_cb, int result, bt_advertiser_h advertiser, bt_adapter_le_advertising_state_e adv_state, void * user_data)
PROXY_GROUP_BLOCKING(bt_adapter_le_advertising_state_changed_cb, int result, bt_advertiser_h advertiser, bt_adapter_le_advertising_state_e adv_state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, info, user_data
PROXY_GROUP_NON_BLOCKING(bt_adapter_le_scan_result_cb, int result, bt_adapter_le_device_scan_result_info_s * info, void * user_data)
PROXY_GROUP_BLOCKING(bt_adapter_le_scan_result_cb, int result, bt_adapter_le_device_scan_result_info_s * info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES device_name, user_data
PROXY_GROUP_NON_BLOCKING(bt_adapter_name_changed_cb, char * device_name, void * user_data)
PROXY_GROUP_BLOCKING(bt_adapter_name_changed_cb, char * device_name, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, adapter_state, user_data
PROXY_GROUP_NON_BLOCKING(bt_adapter_state_changed_cb, int result, bt_adapter_state_e adapter_state, void * user_data)
PROXY_GROUP_BLOCKING(bt_adapter_state_changed_cb, int result, bt_adapter_state_e adapter_state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES duration, user_data
PROXY_GROUP_NON_BLOCKING(bt_adapter_visibility_duration_changed_cb, int duration, void * user_data)
PROXY_GROUP_BLOCKING(bt_adapter_visibility_duration_changed_cb, int duration, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, visibility_mode, user_data
PROXY_GROUP_NON_BLOCKING(bt_adapter_visibility_mode_changed_cb, int result, bt_adapter_visibility_mode_e visibility_mode, void * user_data)
PROXY_GROUP_BLOCKING(bt_adapter_visibility_mode_changed_cb, int result, bt_adapter_visibility_mode_e visibility_mode, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES event, call_id, user_data
PROXY_GROUP_NON_BLOCKING(bt_ag_call_handling_event_cb, bt_ag_call_handling_event_e event, unsigned int call_id, void * user_data)
PROXY_GROUP_BLOCKING(bt_ag_call_handling_event_cb, bt_ag_call_handling_event_e event, unsigned int call_id, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES dtmf, user_data
PROXY_GROUP_NON_BLOCKING(bt_ag_dtmf_transmitted_cb, const char * dtmf, void * user_data)
PROXY_GROUP_BLOCKING(bt_ag_dtmf_transmitted_cb, const char * dtmf, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES gain, user_data
PROXY_GROUP_NON_BLOCKING(bt_ag_microphone_gain_changed_cb, int gain, void * user_data)
PROXY_GROUP_BLOCKING(bt_ag_microphone_gain_changed_cb, int gain, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES event, user_data
PROXY_GROUP_NON_BLOCKING(bt_ag_multi_call_handling_event_cb, bt_ag_multi_call_handling_event_e event, void * user_data)
PROXY_GROUP_BLOCKING(bt_ag_multi_call_handling_event_cb, bt_ag_multi_call_handling_event_e event, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES gain, user_data
PROXY_GROUP_NON_BLOCKING(bt_ag_speaker_gain_changed_cb, int gain, void * user_data)
PROXY_GROUP_BLOCKING(bt_ag_speaker_gain_changed_cb, int gain, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, connected, remote_address, type, user_data
PROXY_GROUP_NON_BLOCKING(bt_audio_connection_state_changed_cb, int result, bool connected, const char * remote_address, bt_audio_profile_type_e type, void * user_data)
PROXY_GROUP_BLOCKING(bt_audio_connection_state_changed_cb, int result, bool connected, const char * remote_address, bt_audio_profile_type_e type, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES connected, remote_address, user_data
PROXY_GROUP_NON_BLOCKING(bt_avrcp_control_connection_state_changed_cb, bool connected, const char * remote_address, void * user_data)
PROXY_GROUP_BLOCKING(bt_avrcp_control_connection_state_changed_cb, bool connected, const char * remote_address, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES equalizer, user_data
PROXY_GROUP_NON_BLOCKING(bt_avrcp_equalizer_state_changed_cb, bt_avrcp_equalizer_state_e equalizer, void * user_data)
PROXY_GROUP_BLOCKING(bt_avrcp_equalizer_state_changed_cb, bt_avrcp_equalizer_state_e equalizer, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES play_state, user_data
PROXY_GROUP_NON_BLOCKING(bt_avrcp_play_status_changed_cb, bt_avrcp_player_state_e play_state, void * user_data)
PROXY_GROUP_BLOCKING(bt_avrcp_play_status_changed_cb, bt_avrcp_player_state_e play_state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES position, user_data
PROXY_GROUP_NON_BLOCKING(bt_avrcp_position_changed_cb, unsigned int position, void * user_data)
PROXY_GROUP_BLOCKING(bt_avrcp_position_changed_cb, unsigned int position, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES repeat, user_data
PROXY_GROUP_NON_BLOCKING(bt_avrcp_repeat_mode_changed_cb, bt_avrcp_repeat_mode_e repeat, void * user_data)
PROXY_GROUP_BLOCKING(bt_avrcp_repeat_mode_changed_cb, bt_avrcp_repeat_mode_e repeat, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES scan, user_data
PROXY_GROUP_NON_BLOCKING(bt_avrcp_scan_mode_changed_cb, bt_avrcp_scan_mode_e scan, void * user_data)
PROXY_GROUP_BLOCKING(bt_avrcp_scan_mode_changed_cb, bt_avrcp_scan_mode_e scan, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES shuffle, user_data
PROXY_GROUP_NON_BLOCKING(bt_avrcp_shuffle_mode_changed_cb, bt_avrcp_shuffle_mode_e shuffle, void * user_data)
PROXY_GROUP_BLOCKING(bt_avrcp_shuffle_mode_changed_cb, bt_avrcp_shuffle_mode_e shuffle, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES connected, remote_address, user_data
PROXY_GROUP_NON_BLOCKING(bt_avrcp_target_connection_state_changed_cb, bool connected, const char * remote_address, void * user_data)
PROXY_GROUP_BLOCKING(bt_avrcp_target_connection_state_changed_cb, bool connected, const char * remote_address, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES track, user_data
PROXY_GROUP_NON_BLOCKING(bt_avrcp_track_info_changed_cb, bt_avrcp_metadata_attributes_info_s * track, void * user_data)
PROXY_GROUP_BLOCKING(bt_avrcp_track_info_changed_cb, bt_avrcp_metadata_attributes_info_s * track, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES authorization, remote_address, user_data
PROXY_GROUP_NON_BLOCKING(bt_device_authorization_changed_cb, bt_device_authorization_e authorization, char * remote_address, void * user_data)
PROXY_GROUP_BLOCKING(bt_device_authorization_changed_cb, bt_device_authorization_e authorization, char * remote_address, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, device_info, user_data
PROXY_GROUP_NON_BLOCKING(bt_device_bond_created_cb, int result, bt_device_info_s * device_info, void * user_data)
PROXY_GROUP_BLOCKING(bt_device_bond_created_cb, int result, bt_device_info_s * device_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, remote_address, user_data
PROXY_GROUP_NON_BLOCKING(bt_device_bond_destroyed_cb, int result, char * remote_address, void * user_data)
PROXY_GROUP_BLOCKING(bt_device_bond_destroyed_cb, int result, char * remote_address, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES profile, user_data
PROXY_GROUP_RETURN(bt_device_connected_profile, bool, bt_profile_e profile, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES connected, conn_info, user_data
PROXY_GROUP_NON_BLOCKING(bt_device_connection_state_changed_cb, bool connected, bt_device_connection_info_s * conn_info, void * user_data)
PROXY_GROUP_BLOCKING(bt_device_connection_state_changed_cb, bool connected, bt_device_connection_info_s * conn_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, sdp_info, user_data
PROXY_GROUP_NON_BLOCKING(bt_device_service_searched_cb, int result, bt_device_sdp_info_s * sdp_info, void * user_data)
PROXY_GROUP_BLOCKING(bt_device_service_searched_cb, int result, bt_device_sdp_info_s * sdp_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES client, mtu_info, user_data
PROXY_GROUP_NON_BLOCKING(bt_gatt_client_att_mtu_changed_cb, bt_gatt_client_h client, const bt_gatt_client_att_mtu_info_s * mtu_info, void * user_data)
PROXY_GROUP_BLOCKING(bt_gatt_client_att_mtu_changed_cb, bt_gatt_client_h client, const bt_gatt_client_att_mtu_info_s * mtu_info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES characteristic, value, len, user_data
PROXY_GROUP_NON_BLOCKING(bt_gatt_client_characteristic_value_changed_cb, bt_gatt_h characteristic, char * value, int len, void * user_data)
PROXY_GROUP_BLOCKING(bt_gatt_client_characteristic_value_changed_cb, bt_gatt_h characteristic, char * value, int len, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, request_handle, user_data
PROXY_GROUP_NON_BLOCKING(bt_gatt_client_request_completed_cb, int result, bt_gatt_h request_handle, void * user_data)
PROXY_GROUP_BLOCKING(bt_gatt_client_request_completed_cb, int result, bt_gatt_h request_handle, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES client, change_type, service_uuid, user_data
PROXY_GROUP_NON_BLOCKING(bt_gatt_client_service_changed_cb, bt_gatt_client_h client, bt_gatt_client_service_change_type_e change_type, const char * service_uuid, void * user_data)
PROXY_GROUP_BLOCKING(bt_gatt_client_service_changed_cb, bt_gatt_client_h client, bt_gatt_client_service_change_type_e change_type, const char * service_uuid, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, connected, remote_address, user_data
PROXY_GROUP_NON_BLOCKING(bt_gatt_connection_state_changed_cb, int result, bool connected, const char * remote_address, void * user_data)
PROXY_GROUP_BLOCKING(bt_gatt_connection_state_changed_cb, int result, bool connected, const char * remote_address, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES total, index, gatt_handle, user_data
PROXY_GROUP_RETURN(bt_gatt_foreach_cb, bool, int total, int index, bt_gatt_h gatt_handle, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES notify, server, gatt_handle, user_data
PROXY_GROUP_NON_BLOCKING(bt_gatt_server_characteristic_notification_state_changed_cb, bool notify, bt_gatt_server_h server, bt_gatt_h gatt_handle, void * user_data)
PROXY_GROUP_BLOCKING(bt_gatt_server_characteristic_notification_state_changed_cb, bool notify, bt_gatt_server_h server, bt_gatt_h gatt_handle, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, remote_address, server, characteristic, completed, user_data
PROXY_GROUP_NON_BLOCKING(bt_gatt_server_notification_sent_cb, int result, const char * remote_address, bt_gatt_server_h server, bt_gatt_h characteristic, bool completed, void * user_data)
PROXY_GROUP_BLOCKING(bt_gatt_server_notification_sent_cb, int result, const char * remote_address, bt_gatt_server_h server, bt_gatt_h characteristic, bool completed, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES remote_address, request_id, server, gatt_handle, offset, user_data
PROXY_GROUP_NON_BLOCKING(bt_gatt_server_read_value_requested_cb, const char * remote_address, int request_id, bt_gatt_server_h server, bt_gatt_h gatt_handle, int offset, void * user_data)
PROXY_GROUP_BLOCKING(bt_gatt_server_read_value_requested_cb, const char * remote_address, int request_id, bt_gatt_server_h server, bt_gatt_h gatt_handle, int offset, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES remote_address, request_id, server, gatt_handle, response_needed, offset, value, len, user_data
PROXY_GROUP_NON_BLOCKING(bt_gatt_server_write_value_requested_cb, const char * remote_address, int request_id, bt_gatt_server_h server, bt_gatt_h gatt_handle, bool response_needed, int offset, const char * value, int len, void * user_data)
PROXY_GROUP_BLOCKING(bt_gatt_server_write_value_requested_cb, const char * remote_address, int request_id, bt_gatt_server_h server, bt_gatt_h gatt_handle, bool response_needed, int offset, const char * value, int len, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, remote_address, app_id, type, channel, user_data
PROXY_GROUP_NON_BLOCKING(bt_hdp_connected_cb, int result, const char * remote_address, const char * app_id, bt_hdp_channel_type_e type, unsigned int channel, void * user_data)
PROXY_GROUP_BLOCKING(bt_hdp_connected_cb, int result, const char * remote_address, const char * app_id, bt_hdp_channel_type_e type, unsigned int channel, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES channel, data, size, user_data
PROXY_GROUP_NON_BLOCKING(bt_hdp_data_received_cb, unsigned int channel, const char * data, unsigned int size, void * user_data)
PROXY_GROUP_BLOCKING(bt_hdp_data_received_cb, unsigned int channel, const char * data, unsigned int size, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, remote_address, channel, user_data
PROXY_GROUP_NON_BLOCKING(bt_hdp_disconnected_cb, int result, const char * remote_address, unsigned int channel, void * user_data)
PROXY_GROUP_BLOCKING(bt_hdp_disconnected_cb, int result, const char * remote_address, unsigned int channel, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, connected, remote_address, user_data
PROXY_GROUP_NON_BLOCKING(bt_hid_device_connection_state_changed_cb, int result, bool connected, const char * remote_address, void * user_data)
PROXY_GROUP_BLOCKING(bt_hid_device_connection_state_changed_cb, int result, bool connected, const char * remote_address, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES data, user_data
PROXY_GROUP_NON_BLOCKING(bt_hid_device_data_received_cb, const bt_hid_device_received_data_s * data, void * user_data)
PROXY_GROUP_BLOCKING(bt_hid_device_data_received_cb, const bt_hid_device_received_data_s * data, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, connected, remote_address, user_data
PROXY_GROUP_NON_BLOCKING(bt_hid_host_connection_state_changed_cb, int result, bool connected, const char * remote_address, void * user_data)
PROXY_GROUP_BLOCKING(bt_hid_host_connection_state_changed_cb, int result, bool connected, const char * remote_address, void * user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_bt_hrp_connection_state_changed_cb 5
#define CB_PARAMS_NAMES result, connected, remote_address
PROXY_GROUP_NON_BLOCKING_NO_USER_DATA(bt_hrp_connection_state_changed_cb, int result, bool connected, const char * remote_address)
PROXY_GROUP_BLOCKING_NO_USER_DATA(bt_hrp_connection_state_changed_cb, int result, bool connected, const char * remote_address)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES notify, server, gatt_handle, user_data
PROXY_GROUP_NON_BLOCKING(bt_hrp_sensor_characteristic_notification_state_changed_cb, bool notify, bt_gatt_server_h server, bt_gatt_h gatt_handle, void * user_data)
PROXY_GROUP_BLOCKING(bt_hrp_sensor_characteristic_notification_state_changed_cb, bool notify, bt_gatt_server_h server, bt_gatt_h gatt_handle, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, connected, remote_address, iface_name, user_data
PROXY_GROUP_NON_BLOCKING(bt_ipsp_connection_state_changed_cb, int result, bool connected, const char * remote_address, const char * iface_name, void * user_data)
PROXY_GROUP_BLOCKING(bt_ipsp_connection_state_changed_cb, int result, bool connected, const char * remote_address, const char * iface_name, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, ipsp_initialized, user_data
PROXY_GROUP_NON_BLOCKING(bt_ipsp_init_state_changed_cb, int result, bool ipsp_initialized, void * user_data)
PROXY_GROUP_BLOCKING(bt_ipsp_init_state_changed_cb, int result, bool ipsp_initialized, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES connected, remote_address, interface_name, user_data
PROXY_GROUP_NON_BLOCKING(bt_nap_connection_state_changed_cb, bool connected, const char * remote_address, const char * interface_name, void * user_data)
PROXY_GROUP_BLOCKING(bt_nap_connection_state_changed_cb, bool connected, const char * remote_address, const char * interface_name, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, remote_address, user_data
PROXY_GROUP_NON_BLOCKING(bt_opp_client_push_finished_cb, int result, const char * remote_address, void * user_data)
PROXY_GROUP_BLOCKING(bt_opp_client_push_finished_cb, int result, const char * remote_address, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES file, size, percent, user_data
PROXY_GROUP_NON_BLOCKING(bt_opp_client_push_progress_cb, const char * file, long long size, int percent, void * user_data)
PROXY_GROUP_BLOCKING(bt_opp_client_push_progress_cb, const char * file, long long size, int percent, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, remote_address, user_data
PROXY_GROUP_NON_BLOCKING(bt_opp_client_push_responded_cb, int result, const char * remote_address, void * user_data)
PROXY_GROUP_BLOCKING(bt_opp_client_push_responded_cb, int result, const char * remote_address, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES remote_address, user_data
PROXY_GROUP_NON_BLOCKING(bt_opp_server_connection_requested_cb, const char * remote_address, void * user_data)
PROXY_GROUP_BLOCKING(bt_opp_server_connection_requested_cb, const char * remote_address, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, file, size, user_data
PROXY_GROUP_NON_BLOCKING(bt_opp_server_transfer_finished_cb, int result, const char * file, long long size, void * user_data)
PROXY_GROUP_BLOCKING(bt_opp_server_transfer_finished_cb, int result, const char * file, long long size, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES file, size, percent, user_data
PROXY_GROUP_NON_BLOCKING(bt_opp_server_transfer_progress_cb, const char * file, long long size, int percent, void * user_data)
PROXY_GROUP_BLOCKING(bt_opp_server_transfer_progress_cb, const char * file, long long size, int percent, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, connected, remote_address, type, user_data
PROXY_GROUP_NON_BLOCKING(bt_panu_connection_state_changed_cb, int result, bool connected, const char * remote_address, bt_panu_service_type_e type, void * user_data)
PROXY_GROUP_BLOCKING(bt_panu_connection_state_changed_cb, int result, bool connected, const char * remote_address, bt_panu_service_type_e type, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, connected, remote_address, user_data
PROXY_GROUP_NON_BLOCKING(bt_pbap_connection_state_changed_cb, int result, bool connected, const char * remote_address, void * user_data)
PROXY_GROUP_BLOCKING(bt_pbap_connection_state_changed_cb, int result, bool connected, const char * remote_address, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, remote_address, vcard_info, count, user_data
PROXY_GROUP_NON_BLOCKING(bt_pbap_list_vcards_cb, int result, const char * remote_address, const bt_pbap_vcard_info_s * vcard_info, int count, void * user_data)
PROXY_GROUP_BLOCKING(bt_pbap_list_vcards_cb, int result, const char * remote_address, const bt_pbap_vcard_info_s * vcard_info, int count, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, remote_address, vcf_file, user_data
PROXY_GROUP_NON_BLOCKING(bt_pbap_phone_book_received_cb, int result, const char * remote_address, const char * vcf_file, void * user_data)
PROXY_GROUP_BLOCKING(bt_pbap_phone_book_received_cb, int result, const char * remote_address, const char * vcf_file, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, remote_address, size, user_data
PROXY_GROUP_NON_BLOCKING(bt_pbap_phone_book_size_cb, int result, const char * remote_address, int size, void * user_data)
PROXY_GROUP_BLOCKING(bt_pbap_phone_book_size_cb, int result, const char * remote_address, int size, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES socket_fd, remote_address, user_data
PROXY_GROUP_NON_BLOCKING(bt_socket_connection_requested_cb, int socket_fd, const char * remote_address, void * user_data)
PROXY_GROUP_BLOCKING(bt_socket_connection_requested_cb, int socket_fd, const char * remote_address, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, connection_state, connection, user_data
PROXY_GROUP_NON_BLOCKING(bt_socket_connection_state_changed_cb, int result, bt_socket_connection_state_e connection_state, bt_socket_connection_s * connection, void * user_data)
PROXY_GROUP_BLOCKING(bt_socket_connection_state_changed_cb, int result, bt_socket_connection_state_e connection_state, bt_socket_connection_s * connection, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES data, user_data
PROXY_GROUP_NON_BLOCKING(bt_socket_data_received_cb, bt_socket_received_data_s * data, void * user_data)
PROXY_GROUP_BLOCKING(bt_socket_data_received_cb, bt_socket_received_data_s * data, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES ipv4_address, ipv6_address, user_data
PROXY_GROUP_NON_BLOCKING(connection_address_changed_cb, const char * ipv4_address, const char * ipv6_address, void * user_data)
PROXY_GROUP_BLOCKING(connection_address_changed_cb, const char * ipv4_address, const char * ipv6_address, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, user_data
PROXY_GROUP_NON_BLOCKING(connection_closed_cb, connection_error_e result, void * user_data)
PROXY_GROUP_BLOCKING(connection_closed_cb, connection_error_e result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(connection_ethernet_cable_state_chaged_cb, connection_ethernet_cable_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(connection_ethernet_cable_state_chaged_cb, connection_ethernet_cable_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(connection_ethernet_cable_state_changed_cb, connection_ethernet_cable_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(connection_ethernet_cable_state_changed_cb, connection_ethernet_cable_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(connection_internet_state_changed_cb, connection_internet_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(connection_internet_state_changed_cb, connection_internet_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES ipv6_address, user_data
PROXY_GROUP_RETURN(connection_ipv6_address_cb, bool, char * ipv6_address, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, user_data
PROXY_GROUP_NON_BLOCKING(connection_opened_cb, connection_error_e result, void * user_data)
PROXY_GROUP_BLOCKING(connection_opened_cb, connection_error_e result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(connection_profile_state_changed_cb, connection_profile_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(connection_profile_state_changed_cb, connection_profile_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, user_data
PROXY_GROUP_NON_BLOCKING(connection_reset_cb, connection_error_e result, void * user_data)
PROXY_GROUP_BLOCKING(connection_reset_cb, connection_error_e result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, user_data
PROXY_GROUP_NON_BLOCKING(connection_set_default_cb, connection_error_e result, void * user_data)
PROXY_GROUP_BLOCKING(connection_set_default_cb, connection_error_e result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(connection_state_changed_cb, inm_connection_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(connection_state_changed_cb, inm_connection_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES type, user_data
PROXY_GROUP_NON_BLOCKING(connection_type_changed_cb, connection_type_e type, void * user_data)
PROXY_GROUP_BLOCKING(connection_type_changed_cb, connection_type_e type, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES http_transaction, error, user_data
PROXY_GROUP_NON_BLOCKING(http_transaction_aborted_cb, http_transaction_h http_transaction, http_error_code_e error, void * user_data)
PROXY_GROUP_BLOCKING(http_transaction_aborted_cb, http_transaction_h http_transaction, http_error_code_e error, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES http_transaction, body, size, count, user_data
PROXY_GROUP_NON_BLOCKING(http_transaction_body_cb, http_transaction_h http_transaction, char * body, size_t size, size_t count, void * user_data)
PROXY_GROUP_BLOCKING(http_transaction_body_cb, http_transaction_h http_transaction, char * body, size_t size, size_t count, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES http_transaction, user_data
PROXY_GROUP_NON_BLOCKING(http_transaction_completed_cb, http_transaction_h http_transaction, void * user_data)
PROXY_GROUP_BLOCKING(http_transaction_completed_cb, http_transaction_h http_transaction, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES http_transaction, header, header_len, user_data
PROXY_GROUP_NON_BLOCKING(http_transaction_header_cb, http_transaction_h http_transaction, char * header, size_t header_len, void * user_data)
PROXY_GROUP_BLOCKING(http_transaction_header_cb, http_transaction_h http_transaction, char * header, size_t header_len, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES http_transaction, download_total, download_now, upload_total, upload_now, user_data
PROXY_GROUP_NON_BLOCKING(http_transaction_progress_cb, http_transaction_h http_transaction, double download_total, double download_now, double upload_total, double upload_now, void * user_data)
PROXY_GROUP_BLOCKING(http_transaction_progress_cb, http_transaction_h http_transaction, double download_total, double download_now, double upload_total, double upload_now, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES http_transaction, recommended_chunk_size, user_data
PROXY_GROUP_NON_BLOCKING(http_transaction_write_cb, http_transaction_h http_transaction, int recommended_chunk_size, void * user_data)
PROXY_GROUP_BLOCKING(http_transaction_write_cb, http_transaction_h http_transaction, int recommended_chunk_size, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES found, ip, user_data
PROXY_GROUP_NON_BLOCKING(inm_arp_request_ip_found_cb, bool found, const char * ip, void * user_data)
PROXY_GROUP_BLOCKING(inm_arp_request_ip_found_cb, bool found, const char * ip, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(inm_cellular_state_changed_cb, inm_cellular_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(inm_cellular_state_changed_cb, inm_cellular_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES freq, channel_intf, user_data
PROXY_GROUP_NON_BLOCKING(inm_channel_interference_cb, int freq, double channel_intf, void * user_data)
PROXY_GROUP_BLOCKING(inm_channel_interference_cb, int freq, double channel_intf, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES level, user_data
PROXY_GROUP_NON_BLOCKING(inm_congestion_level_cb, inm_congestion_level_e level, void * user_data)
PROXY_GROUP_BLOCKING(inm_congestion_level_cb, inm_congestion_level_e level, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES found, user_data
PROXY_GROUP_NON_BLOCKING(inm_default_dns_lookup_result_cb, bool found, void * user_data)
PROXY_GROUP_BLOCKING(inm_default_dns_lookup_result_cb, bool found, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES found, gateway_ip, user_data
PROXY_GROUP_NON_BLOCKING(inm_default_gateway_found_cb, bool found, const char * gateway_ip, void * user_data)
PROXY_GROUP_BLOCKING(inm_default_gateway_found_cb, bool found, const char * gateway_ip, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(inm_ethernet_cable_state_changed_cb, inm_ethernet_cable_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(inm_ethernet_cable_state_changed_cb, inm_ethernet_cable_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(inm_ethernet_state_changed_cb, inm_ethernet_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(inm_ethernet_state_changed_cb, inm_ethernet_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES if_name, ip, state, user_data
PROXY_GROUP_NON_BLOCKING(inm_ip_conflict_cb, char * if_name, char * ip, inm_ip_conflict_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(inm_ip_conflict_cb, char * if_name, char * ip, inm_ip_conflict_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES address, user_data
PROXY_GROUP_RETURN(inm_link_address_cb, bool, inm_link_address_h address, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES link, user_data
PROXY_GROUP_RETURN(inm_link_cb, bool, inm_link_h link, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES route, user_data
PROXY_GROUP_RETURN(inm_link_route_cb, bool, inm_link_route_h route, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, url, user_data
PROXY_GROUP_NON_BLOCKING(inm_reachable_urls_check_result_cb, inm_reachable_urls_check_result_e result, const char * url, void * user_data)
PROXY_GROUP_BLOCKING(inm_reachable_urls_check_result_cb, inm_reachable_urls_check_result_e result, const char * url, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES rate, user_data
PROXY_GROUP_NON_BLOCKING(inm_retry_tx_rate_cb, int rate, void * user_data)
PROXY_GROUP_BLOCKING(inm_retry_tx_rate_cb, int rate, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES vsie, length, user_data
PROXY_GROUP_RETURN(inm_wifi_ap_vsie_cb, bool, unsigned char * vsie, int length, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES ap, user_data
PROXY_GROUP_RETURN(inm_wifi_found_ap_cb, bool, inm_connection_h ap, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(inm_wifi_module_state_changed_cb, inm_wifi_module_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(inm_wifi_module_state_changed_cb, inm_wifi_module_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(inm_wifi_scan_state_changed_cb, inm_wifi_scan_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(inm_wifi_scan_state_changed_cb, inm_wifi_scan_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(inm_wifi_state_changed_cb, inm_wifi_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(inm_wifi_state_changed_cb, inm_wifi_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES client, opened, user_data
PROXY_GROUP_NON_BLOCKING(softap_client_connection_state_changed_cb, softap_client_h client, bool opened, void * user_data)
PROXY_GROUP_BLOCKING(softap_client_connection_state_changed_cb, softap_client_h client, bool opened, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES client, user_data
PROXY_GROUP_RETURN(softap_connected_client_cb, bool, softap_client_h client, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, cause, user_data
PROXY_GROUP_NON_BLOCKING(softap_disabled_cb, softap_error_e result, softap_disabled_cause_e cause, void * user_data)
PROXY_GROUP_BLOCKING(softap_disabled_cb, softap_error_e result, softap_disabled_cause_e cause, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, is_requested, user_data
PROXY_GROUP_NON_BLOCKING(softap_enabled_cb, softap_error_e result, bool is_requested, void * user_data)
PROXY_GROUP_BLOCKING(softap_enabled_cb, softap_error_e result, bool is_requested, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(softap_passphrase_changed_cb, void * user_data)
PROXY_GROUP_BLOCKING(softap_passphrase_changed_cb, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES changed_type, user_data
PROXY_GROUP_NON_BLOCKING(softap_security_type_changed_cb, softap_security_type_e changed_type, void * user_data)
PROXY_GROUP_BLOCKING(softap_security_type_changed_cb, softap_security_type_e changed_type, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, user_data
PROXY_GROUP_NON_BLOCKING(softap_settings_reloaded_cb, softap_error_e result, void * user_data)
PROXY_GROUP_BLOCKING(softap_settings_reloaded_cb, softap_error_e result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES changed_visible, user_data
PROXY_GROUP_NON_BLOCKING(softap_ssid_visibility_changed_cb, bool changed_visible, void * user_data)
PROXY_GROUP_BLOCKING(softap_ssid_visibility_changed_cb, bool changed_visible, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, info, user_data
PROXY_GROUP_NON_BLOCKING(stc_get_all_stats_finished_cb, stc_error_e result, stc_all_stats_info_h info, void * user_data)
PROXY_GROUP_BLOCKING(stc_get_all_stats_finished_cb, stc_error_e result, stc_all_stats_info_h info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, info, user_data
PROXY_GROUP_RETURN(stc_stats_info_cb, stc_callback_ret_e, stc_error_e result, stc_stats_info_h info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_activated_cb, wifi_manager_error_e result, void * user_data)
PROXY_GROUP_BLOCKING(wifi_manager_activated_cb, wifi_manager_error_e result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES ipv6_address, user_data
PROXY_GROUP_RETURN(wifi_manager_ap_ipv6_address_cb, bool, char * ipv6_address, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES vsie, length, user_data
PROXY_GROUP_RETURN(wifi_manager_ap_vsie_cb, bool, unsigned char * vsie, int length, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error_code, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_bssid_scan_finished_cb, wifi_manager_error_e error_code, void * user_data)
PROXY_GROUP_BLOCKING(wifi_manager_bssid_scan_finished_cb, wifi_manager_error_e error_code, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES config, user_data
PROXY_GROUP_RETURN(wifi_manager_config_list_cb, bool, const wifi_manager_config_h config, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_connected_cb, wifi_manager_error_e result, void * user_data)
PROXY_GROUP_BLOCKING(wifi_manager_connected_cb, wifi_manager_error_e result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, ap, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_connection_state_changed_cb, wifi_manager_connection_state_e state, wifi_manager_ap_h ap, void * user_data)
PROXY_GROUP_BLOCKING(wifi_manager_connection_state_changed_cb, wifi_manager_connection_state_e state, wifi_manager_ap_h ap, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_deactivated_cb, wifi_manager_error_e result, void * user_data)
PROXY_GROUP_BLOCKING(wifi_manager_deactivated_cb, wifi_manager_error_e result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_device_state_changed_cb, wifi_manager_device_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(wifi_manager_device_state_changed_cb, wifi_manager_device_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_disconnected_cb, wifi_manager_error_e result, void * user_data)
PROXY_GROUP_BLOCKING(wifi_manager_disconnected_cb, wifi_manager_error_e result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_forget_ap_finished_cb, wifi_manager_error_e result, void * user_data)
PROXY_GROUP_BLOCKING(wifi_manager_forget_ap_finished_cb, wifi_manager_error_e result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES ap, user_data
PROXY_GROUP_RETURN(wifi_manager_found_ap_cb, bool, wifi_manager_ap_h ap, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES bssid, rssi, freq, user_data
PROXY_GROUP_RETURN(wifi_manager_found_bssid_cb, bool, const char * bssid, int rssi, int freq, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES mac, state, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_ip_conflict_cb, char * mac, wifi_manager_ip_conflict_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(wifi_manager_ip_conflict_cb, char * mac, wifi_manager_ip_conflict_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES wifi_module_state, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_module_state_changed_cb, wifi_manager_module_state_e wifi_module_state, void * user_data)
PROXY_GROUP_BLOCKING(wifi_manager_module_state_changed_cb, wifi_manager_module_state_e wifi_module_state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES rssi_level, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_rssi_level_changed_cb, wifi_manager_rssi_level_e rssi_level, void * user_data)
PROXY_GROUP_BLOCKING(wifi_manager_rssi_level_changed_cb, wifi_manager_rssi_level_e rssi_level, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error_code, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_scan_finished_cb, wifi_manager_error_e error_code, void * user_data)
PROXY_GROUP_BLOCKING(wifi_manager_scan_finished_cb, wifi_manager_error_e error_code, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_scan_state_changed_cb, wifi_manager_scan_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(wifi_manager_scan_state_changed_cb, wifi_manager_scan_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, peer_mac_addr, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_tdls_discovered_cb, wifi_manager_tdls_discovery_state_e state, char * peer_mac_addr, void * user_data)
PROXY_GROUP_BLOCKING(wifi_manager_tdls_discovered_cb, wifi_manager_tdls_discovery_state_e state, char * peer_mac_addr, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, peer_mac_addr, user_data
PROXY_GROUP_NON_BLOCKING(wifi_manager_tdls_state_changed_cb, wifi_manager_tdls_state_e state, char * peer_mac_addr, void * user_data)
PROXY_GROUP_BLOCKING(wifi_manager_tdls_state_changed_cb, wifi_manager_tdls_state_e state, char * peer_mac_addr, void * user_data)
#undef CB_PARAMS_NAMES


#include <nnstreamer/ml-api-common.h>

#include <nnstreamer/nnstreamer-single.h>

#include <nnstreamer/nnstreamer.h>

#define CB_PARAMS_NAMES in, out, user_data
PROXY_GROUP_RETURN(ml_custom_easy_invoke_cb, int, const ml_tensors_data_h in, ml_tensors_data_h out, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES data, info, result, user_data
PROXY_GROUP_RETURN(ml_pipeline_if_custom_cb, int, const ml_tensors_data_h data, const ml_tensors_info_h info, int * result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES data, info, user_data
PROXY_GROUP_NON_BLOCKING(ml_pipeline_sink_cb, const ml_tensors_data_h data, const ml_tensors_info_h info, void * user_data)
PROXY_GROUP_BLOCKING(ml_pipeline_sink_cb, const ml_tensors_data_h data, const ml_tensors_info_h info, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(ml_pipeline_state_cb, ml_pipeline_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(ml_pipeline_state_cb, ml_pipeline_state_e state, void * user_data)
#undef CB_PARAMS_NAMES


#include <nntrainer/nntrainer-api-common.h>

#include <nntrainer/nntrainer.h>

#define CB_PARAMS_NAMES input, label, last, user_data
PROXY_GROUP_RETURN(ml_train_datagen_cb, int, float ** input, float ** label, bool * last, void * user_data)
#undef CB_PARAMS_NAMES


#include <notification-ex/api/notification_ex.h>

#include <notification-ex/api/notification_ex_app_control_action.h>

#include <notification-ex/api/notification_ex_button.h>

#include <notification-ex/api/notification_ex_chat_message.h>

#include <notification-ex/api/notification_ex_checkbox.h>

#include <notification-ex/api/notification_ex_entry.h>

#include <notification-ex/api/notification_ex_error.h>

#include <notification-ex/api/notification_ex_event_info.h>

#include <notification-ex/api/notification_ex_group.h>

#include <notification-ex/api/notification_ex_image.h>

#include <notification-ex/api/notification_ex_input_selector.h>

#include <notification-ex/api/notification_ex_item.h>

#include <notification-ex/api/notification_ex_manager.h>

#include <notification-ex/api/notification_ex_multi_language.h>

#include <notification-ex/api/notification_ex_progress.h>

#include <notification-ex/api/notification_ex_reporter.h>

#include <notification-ex/api/notification_ex_text.h>

#include <notification-ex/api/notification_ex_time.h>

#include <notification-ex/api/notification_ex_visibility_action.h>

#define CB_PARAMS_NAMES handle, user_data
PROXY_GROUP_RETURN(noti_ex_item_group_foreach_child_cb, int, noti_ex_item_h handle, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES handle, info, added_items, count, user_data
PROXY_GROUP_NON_BLOCKING(noti_ex_manager_events_add_cb, noti_ex_manager_h handle, noti_ex_event_info_h info, noti_ex_item_h * added_items, int count, void * user_data)
PROXY_GROUP_BLOCKING(noti_ex_manager_events_add_cb, noti_ex_manager_h handle, noti_ex_event_info_h info, noti_ex_item_h * added_items, int count, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES handle, info, deleted_item, user_data
PROXY_GROUP_NON_BLOCKING(noti_ex_manager_events_delete_cb, noti_ex_manager_h handle, noti_ex_event_info_h info, noti_ex_item_h deleted_item, void * user_data)
PROXY_GROUP_BLOCKING(noti_ex_manager_events_delete_cb, noti_ex_manager_h handle, noti_ex_event_info_h info, noti_ex_item_h deleted_item, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES handle, error, request_id, user_data
PROXY_GROUP_NON_BLOCKING(noti_ex_manager_events_error_cb, noti_ex_manager_h handle, noti_ex_error_e error, int request_id, void * user_data)
PROXY_GROUP_BLOCKING(noti_ex_manager_events_error_cb, noti_ex_manager_h handle, noti_ex_error_e error, int request_id, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES handle, info, updated_item, user_data
PROXY_GROUP_NON_BLOCKING(noti_ex_manager_events_update_cb, noti_ex_manager_h handle, noti_ex_event_info_h info, noti_ex_item_h updated_item, void * user_data)
PROXY_GROUP_BLOCKING(noti_ex_manager_events_update_cb, noti_ex_manager_h handle, noti_ex_event_info_h info, noti_ex_item_h updated_item, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES handle, error, request_id, user_data
PROXY_GROUP_NON_BLOCKING(noti_ex_reporter_events_error_cb, noti_ex_reporter_h handle, noti_ex_error_e error, int request_id, void * user_data)
PROXY_GROUP_BLOCKING(noti_ex_reporter_events_error_cb, noti_ex_reporter_h handle, noti_ex_error_e error, int request_id, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES handle, info, items, count, user_data
PROXY_GROUP_NON_BLOCKING(noti_ex_reporter_events_event_cb, noti_ex_reporter_h handle, noti_ex_event_info_h info, noti_ex_item_h * items, int count, void * user_data)
PROXY_GROUP_BLOCKING(noti_ex_reporter_events_event_cb, noti_ex_reporter_h handle, noti_ex_event_info_h info, noti_ex_item_h * items, int count, void * user_data)
#undef CB_PARAMS_NAMES



#include <nsd/dns-sd.h>

#include <nsd/ssdp.h>

#define CB_PARAMS_NAMES service_state, remote_service, user_data
PROXY_GROUP_NON_BLOCKING(dnssd_found_cb, dnssd_service_state_e service_state, dnssd_service_h remote_service, void * user_data)
PROXY_GROUP_BLOCKING(dnssd_found_cb, dnssd_service_state_e service_state, dnssd_service_h remote_service, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, local_service, user_data
PROXY_GROUP_NON_BLOCKING(dnssd_registered_cb, dnssd_error_e result, dnssd_service_h local_service, void * user_data)
PROXY_GROUP_BLOCKING(dnssd_registered_cb, dnssd_error_e result, dnssd_service_h local_service, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, ssdp_remote_service, user_data
PROXY_GROUP_NON_BLOCKING(ssdp_found_cb, ssdp_service_state_e state, ssdp_service_h ssdp_remote_service, void * user_data)
PROXY_GROUP_BLOCKING(ssdp_found_cb, ssdp_service_state_e state, ssdp_service_h ssdp_remote_service, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, ssdp_local_service, user_data
PROXY_GROUP_NON_BLOCKING(ssdp_registered_cb, ssdp_error_e result, ssdp_service_h ssdp_local_service, void * user_data)
PROXY_GROUP_BLOCKING(ssdp_registered_cb, ssdp_error_e result, ssdp_service_h ssdp_local_service, void * user_data)
#undef CB_PARAMS_NAMES



#include <privacy-privilege-manager/ppm_error.h>

#include <privacy-privilege-manager/privacy_privilege_manager.h>

#define CB_PARAMS_NAMES cause, results, privileges, privileges_count, user_data
PROXY_GROUP_NON_BLOCKING(ppm_request_multiple_response_cb, ppm_call_cause_e cause, const ppm_request_result_e * results, const char ** privileges, size_t privileges_count, void * user_data)
PROXY_GROUP_BLOCKING(ppm_request_multiple_response_cb, ppm_call_cause_e cause, const ppm_request_result_e * results, const char ** privileges, size_t privileges_count, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES cause, result, privilege, user_data
PROXY_GROUP_NON_BLOCKING(ppm_request_response_cb, ppm_call_cause_e cause, ppm_request_result_e result, const char * privilege, void * user_data)
PROXY_GROUP_BLOCKING(ppm_request_response_cb, ppm_call_cause_e cause, ppm_request_result_e result, const char * privilege, void * user_data)
#undef CB_PARAMS_NAMES



#include <push-service.h>

#define CB_PARAMS_NAMES noti, user_data
PROXY_GROUP_NON_BLOCKING(push_service_notify_cb, push_service_notification_h noti, void * user_data)
PROXY_GROUP_BLOCKING(push_service_notify_cb, push_service_notification_h noti, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES result, msg, user_data
PROXY_GROUP_NON_BLOCKING(push_service_result_cb, push_service_result_e result, const char * msg, void * user_data)
PROXY_GROUP_BLOCKING(push_service_result_cb, push_service_result_e result, const char * msg, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, err, user_data
PROXY_GROUP_NON_BLOCKING(push_service_state_cb, push_service_state_e state, const char * err, void * user_data)
PROXY_GROUP_BLOCKING(push_service_state_cb, push_service_state_e state, const char * err, void * user_data)
#undef CB_PARAMS_NAMES


#include <rpc-port/rpc-port-parcel.h>

#include <rpc-port/rpc-port.h>

#define CB_PARAMS_NAMES receiver, port_name, port, user_data
PROXY_GROUP_NON_BLOCKING(rpc_port_proxy_connected_event_cb, const char * receiver, const char * port_name, rpc_port_h port, void * user_data)
PROXY_GROUP_BLOCKING(rpc_port_proxy_connected_event_cb, const char * receiver, const char * port_name, rpc_port_h port, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES receiver, port_name, user_data
PROXY_GROUP_NON_BLOCKING(rpc_port_proxy_disconnected_event_cb, const char * receiver, const char * port_name, void * user_data)
PROXY_GROUP_BLOCKING(rpc_port_proxy_disconnected_event_cb, const char * receiver, const char * port_name, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES receiver, port_name, user_data
PROXY_GROUP_NON_BLOCKING(rpc_port_proxy_received_event_cb, const char * receiver, const char * port_name, void * user_data)
PROXY_GROUP_BLOCKING(rpc_port_proxy_received_event_cb, const char * receiver, const char * port_name, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES receiver, port_name, user_data
PROXY_GROUP_NON_BLOCKING(rpc_port_proxy_rejected_event_cb, const char * receiver, const char * port_name, void * user_data)
PROXY_GROUP_BLOCKING(rpc_port_proxy_rejected_event_cb, const char * receiver, const char * port_name, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES sender, instance, user_data
PROXY_GROUP_NON_BLOCKING(rpc_port_stub_connected_event_cb, const char * sender, const char * instance, void * user_data)
PROXY_GROUP_BLOCKING(rpc_port_stub_connected_event_cb, const char * sender, const char * instance, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES sender, instance, user_data
PROXY_GROUP_NON_BLOCKING(rpc_port_stub_disconnected_event_cb, const char * sender, const char * instance, void * user_data)
PROXY_GROUP_BLOCKING(rpc_port_stub_disconnected_event_cb, const char * sender, const char * instance, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES sender, instance, port, user_data
PROXY_GROUP_RETURN(rpc_port_stub_received_event_cb, int, const char * sender, const char * instance, rpc_port_h port, void * user_data)
#undef CB_PARAMS_NAMES


#include <sensor/sensor.h>

#define CB_PARAMS_NAMES sensor, timestamp, accuracy, user_data
PROXY_GROUP_NON_BLOCKING(sensor_accuracy_changed_cb, sensor_h sensor, unsigned long long timestamp, sensor_data_accuracy_e accuracy, void * user_data)
PROXY_GROUP_BLOCKING(sensor_accuracy_changed_cb, sensor_h sensor, unsigned long long timestamp, sensor_data_accuracy_e accuracy, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES uri, user_data
PROXY_GROUP_NON_BLOCKING(sensor_added_cb, const char * uri, void * user_data)
PROXY_GROUP_BLOCKING(sensor_added_cb, const char * uri, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES sensor, event, user_data
PROXY_GROUP_NON_BLOCKING(sensor_event_cb, sensor_h sensor, sensor_event_s * event, void * user_data)
PROXY_GROUP_BLOCKING(sensor_event_cb, sensor_h sensor, sensor_event_s * event, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES sensor, events, events_count, user_data
PROXY_GROUP_NON_BLOCKING(sensor_events_cb, sensor_h sensor, sensor_event_s* events, int events_count, void * user_data)
PROXY_GROUP_BLOCKING(sensor_events_cb, sensor_h sensor, sensor_event_s* events, int events_count, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES provider, interval_ms, user_data
PROXY_GROUP_NON_BLOCKING(sensor_provider_interval_changed_cb, sensor_provider_h provider, unsigned int interval_ms, void * user_data)
PROXY_GROUP_BLOCKING(sensor_provider_interval_changed_cb, sensor_provider_h provider, unsigned int interval_ms, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES provider, user_data
PROXY_GROUP_NON_BLOCKING(sensor_provider_start_cb, sensor_provider_h provider, void * user_data)
PROXY_GROUP_BLOCKING(sensor_provider_start_cb, sensor_provider_h provider, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES provider, user_data
PROXY_GROUP_NON_BLOCKING(sensor_provider_stop_cb, sensor_provider_h provider, void * user_data)
PROXY_GROUP_BLOCKING(sensor_provider_stop_cb, sensor_provider_h provider, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES type, data, remains, error, user_data
PROXY_GROUP_RETURN(sensor_recorder_data_cb, bool, sensor_type_e type, sensor_recorder_data_h data, int remains, sensor_error_e error, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES uri, user_data
PROXY_GROUP_NON_BLOCKING(sensor_removed_cb, const char * uri, void * user_data)
PROXY_GROUP_BLOCKING(sensor_removed_cb, const char * uri, void * user_data)
#undef CB_PARAMS_NAMES


#include <shortcut/shortcut_error.h>

#include <shortcut/shortcut_manager.h>

#define CB_PARAMS_NAMES ret, user_data
PROXY_GROUP_RETURN(result_cb, int, int ret, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES package_name, icon, name, extra_key, extra_data, user_data
PROXY_GROUP_RETURN(shortcut_list_cb, int, const char * package_name, const char * icon, const char * name, const char * extra_key, const char * extra_data, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES package_name, name, sender_pid, user_data
PROXY_GROUP_RETURN(shortcut_remove_cb, int, const char * package_name, const char * name, int sender_pid, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES package_name, name, type, content_info, icon, pid, period, allow_duplicate, user_data
PROXY_GROUP_RETURN(shortcut_request_cb, int, const char * package_name, const char * name, int type, const char * content_info, const char * icon, int pid, double period, int allow_duplicate, void * user_data)
#undef CB_PARAMS_NAMES


#include <storage/storage-expand.h>

#include <storage/storage.h>

#define CB_PARAMS_NAMES storage_id, dev, state, fstype, fsuuid, mountpath, primary, flags, user_data
PROXY_GROUP_NON_BLOCKING(storage_changed_cb, int storage_id, storage_dev_e dev, storage_state_e state, const char * fstype, const char * fsuuid, const char * mountpath, bool primary, int flags, void * user_data)
PROXY_GROUP_BLOCKING(storage_changed_cb, int storage_id, storage_dev_e dev, storage_state_e state, const char * fstype, const char * fsuuid, const char * mountpath, bool primary, int flags, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES storage_id, type, state, path, user_data
PROXY_GROUP_RETURN(storage_device_supported_cb, bool, int storage_id, storage_type_e type, storage_state_e state, const char * path, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES storage_id, state, user_data
PROXY_GROUP_NON_BLOCKING(storage_state_changed_cb, int storage_id, storage_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(storage_state_changed_cb, int storage_id, storage_state_e state, void * user_data)
#undef CB_PARAMS_NAMES


#include <stt.h>

#define CB_PARAMS_NAMES stt, previous_language, current_language, user_data
PROXY_GROUP_NON_BLOCKING(stt_default_language_changed_cb, stt_h stt, const char * previous_language, const char * current_language, void * user_data)
PROXY_GROUP_BLOCKING(stt_default_language_changed_cb, stt_h stt, const char * previous_language, const char * current_language, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES stt, engine_id, language, support_silence, need_credential, user_data
PROXY_GROUP_NON_BLOCKING(stt_engine_changed_cb, stt_h stt, const char * engine_id, const char * language, bool support_silence, bool need_credential, void * user_data)
PROXY_GROUP_BLOCKING(stt_engine_changed_cb, stt_h stt, const char * engine_id, const char * language, bool support_silence, bool need_credential, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES stt, reason, user_data
PROXY_GROUP_NON_BLOCKING(stt_error_cb, stt_h stt, stt_error_e reason, void * user_data)
PROXY_GROUP_BLOCKING(stt_error_cb, stt_h stt, stt_error_e reason, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES stt, event, data, data_count, msg, user_data
PROXY_GROUP_NON_BLOCKING(stt_recognition_result_cb, stt_h stt, stt_result_event_e event, const char ** data, int data_count, const char * msg, void * user_data)
PROXY_GROUP_BLOCKING(stt_recognition_result_cb, stt_h stt, stt_result_event_e event, const char ** data, int data_count, const char * msg, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES stt, index, event, text, start_time, end_time, user_data
PROXY_GROUP_RETURN(stt_result_time_cb, bool, stt_h stt, int index, stt_result_time_event_e event, const char * text, long start_time, long end_time, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES stt, status, user_data
PROXY_GROUP_NON_BLOCKING(stt_speech_status_cb, stt_h stt, stt_speech_status_e status, void * user_data)
PROXY_GROUP_BLOCKING(stt_speech_status_cb, stt_h stt, stt_speech_status_e status, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES stt, previous, current, user_data
PROXY_GROUP_NON_BLOCKING(stt_state_changed_cb, stt_h stt, stt_state_e previous, stt_state_e current, void * user_data)
PROXY_GROUP_BLOCKING(stt_state_changed_cb, stt_h stt, stt_state_e previous, stt_state_e current, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES stt, engine_id, engine_name, user_data
PROXY_GROUP_RETURN(stt_supported_engine_cb, bool, stt_h stt, const char * engine_id, const char * engine_name, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES stt, language, user_data
PROXY_GROUP_RETURN(stt_supported_language_cb, bool, stt_h stt, const char * language, void * user_data)
#undef CB_PARAMS_NAMES


#include <stte.h>

#define CB_PARAMS_NAMES audio_type, user_data
PROXY_GROUP_RETURN(stte_audio_type_cb, int, const char * audio_type, void * user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_stte_cancel_cb 10
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(stte_cancel_cb, int)

#define BASE_CALLBACK_ID_stte_check_app_agreed_cb 15
#define CB_PARAMS_NAMES appid, is_agreed
PROXY_GROUP_RETURN_NO_USER_DATA(stte_check_app_agreed_cb, int, const char * appid, bool * is_agreed)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_stte_deinitialize_cb 20
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(stte_deinitialize_cb, int)

#define CB_PARAMS_NAMES time_info, callback, user_data
PROXY_GROUP_RETURN(stte_foreach_result_time_cb, int, void * time_info, stte_result_time_cb callback, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES callback, user_data
PROXY_GROUP_RETURN(stte_foreach_supported_langs_cb, int, stte_supported_language_cb callback, void * user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_stte_get_info_cb 25
#define CB_PARAMS_NAMES engine_uuid, engine_name, engine_setting, use_network
PROXY_GROUP_RETURN_NO_USER_DATA(stte_get_info_cb, int, char ** engine_uuid, char ** engine_name, char ** engine_setting, bool * use_network)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_stte_get_recording_format_cb 30
#define CB_PARAMS_NAMES types, rate, channels
PROXY_GROUP_RETURN_NO_USER_DATA(stte_get_recording_format_cb, int, stte_audio_type_e * types, int * rate, int * channels)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_stte_initialize_cb 35
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(stte_initialize_cb, int)

#define BASE_CALLBACK_ID_stte_is_valid_language_cb 40
#define CB_PARAMS_NAMES language, is_valid
PROXY_GROUP_RETURN_NO_USER_DATA(stte_is_valid_language_cb, int, const char * language, bool * is_valid)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_stte_need_app_credential_cb 45
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(stte_need_app_credential_cb, bool)

#define BASE_CALLBACK_ID_stte_private_data_requested_cb 50
#define CB_PARAMS_NAMES key, data
PROXY_GROUP_RETURN_NO_USER_DATA(stte_private_data_requested_cb, int, const char * key, char ** data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_stte_private_data_set_cb 55
#define CB_PARAMS_NAMES key, data
PROXY_GROUP_RETURN_NO_USER_DATA(stte_private_data_set_cb, int, const char * key, const char * data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES index, event, text, start_time, end_time, user_data
PROXY_GROUP_RETURN(stte_result_time_cb, bool, int index, stte_result_time_event_e event, const char * text, long start_time, long end_time, void * user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_stte_set_recording_data_cb 60
#define CB_PARAMS_NAMES data, length
PROXY_GROUP_RETURN_NO_USER_DATA(stte_set_recording_data_cb, int, const void * data, unsigned int length)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_stte_set_silence_detection_cb 65
#define CB_PARAMS_NAMES is_set
PROXY_GROUP_RETURN_NO_USER_DATA(stte_set_silence_detection_cb, int, bool is_set)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES language, type, appid, credential, user_data
PROXY_GROUP_RETURN(stte_start_cb, int, const char * language, const char * type, const char * appid, const char * credential, void * user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_stte_stop_cb 70
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(stte_stop_cb, int)

#define BASE_CALLBACK_ID_stte_support_recognition_type_cb 75
#define CB_PARAMS_NAMES type, is_supported
PROXY_GROUP_RETURN_NO_USER_DATA(stte_support_recognition_type_cb, int, const char * type, bool * is_supported)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_stte_support_silence_detection_cb 80
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(stte_support_silence_detection_cb, bool)

#define CB_PARAMS_NAMES language, user_data
PROXY_GROUP_RETURN(stte_supported_language_cb, bool, const char * language, void * user_data)
#undef CB_PARAMS_NAMES


#include <sync_adapter.h>

#define BASE_CALLBACK_ID_sync_adapter_cancel_sync_cb 85
#define CB_PARAMS_NAMES account, sync_job_name, sync_capability, sync_job_user_data
PROXY_GROUP_NON_BLOCKING_NO_USER_DATA(sync_adapter_cancel_sync_cb, account_h account, const char * sync_job_name, const char * sync_capability, bundle * sync_job_user_data)
PROXY_GROUP_BLOCKING_NO_USER_DATA(sync_adapter_cancel_sync_cb, account_h account, const char * sync_job_name, const char * sync_capability, bundle * sync_job_user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_sync_adapter_start_sync_cb 90
#define CB_PARAMS_NAMES account, sync_job_name, sync_capability, sync_job_user_data
PROXY_GROUP_RETURN_NO_USER_DATA(sync_adapter_start_sync_cb, bool, account_h account, const char * sync_job_name, const char * sync_capability, bundle * sync_job_user_data)
#undef CB_PARAMS_NAMES


#include <sync_manager.h>

#define CB_PARAMS_NAMES account, sync_job_name, sync_capability, sync_job_id, sync_job_user_data, user_data
PROXY_GROUP_RETURN(sync_manager_sync_job_cb, bool, account_h account, const char * sync_job_name, const char * sync_capability, int sync_job_id, bundle * sync_job_user_data, void * user_data)
#undef CB_PARAMS_NAMES


#include <system/media_key.h>

#include <system/runtime_info.h>

#include <system/system_info.h>

#include <system/system_info_type.h>

#include <system/system_settings.h>

#define CB_PARAMS_NAMES key, status, user_data
PROXY_GROUP_NON_BLOCKING(media_key_event_cb, media_key_e key, media_key_event_e status, void * user_data)
PROXY_GROUP_BLOCKING(media_key_event_cb, media_key_e key, media_key_event_e status, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES key, user_data
PROXY_GROUP_NON_BLOCKING(runtime_info_changed_cb, runtime_info_key_e key, void * user_data)
PROXY_GROUP_BLOCKING(runtime_info_changed_cb, runtime_info_key_e key, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES key, user_data
PROXY_GROUP_NON_BLOCKING(system_settings_changed_cb, system_settings_key_e key, void * user_data)
PROXY_GROUP_BLOCKING(system_settings_changed_cb, system_settings_key_e key, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES index, value, user_data
PROXY_GROUP_RETURN(system_settings_iter_cb, bool, int index, const char * value, void * user_data)
#undef CB_PARAMS_NAMES






#include <tts.h>

#define CB_PARAMS_NAMES tts, previous_language, previous_voice_type, current_language, current_voice_type, user_data
PROXY_GROUP_NON_BLOCKING(tts_default_voice_changed_cb, tts_h tts, const char * previous_language, int previous_voice_type, const char * current_language, int current_voice_type, void * user_data)
PROXY_GROUP_BLOCKING(tts_default_voice_changed_cb, tts_h tts, const char * previous_language, int previous_voice_type, const char * current_language, int current_voice_type, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES tts, engine_id, language, voice_type, need_credential, user_data
PROXY_GROUP_NON_BLOCKING(tts_engine_changed_cb, tts_h tts, const char * engine_id, const char * language, int voice_type, bool need_credential, void * user_data)
PROXY_GROUP_BLOCKING(tts_engine_changed_cb, tts_h tts, const char * engine_id, const char * language, int voice_type, bool need_credential, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES tts, utt_id, reason, user_data
PROXY_GROUP_NON_BLOCKING(tts_error_cb, tts_h tts, int utt_id, tts_error_e reason, void * user_data)
PROXY_GROUP_BLOCKING(tts_error_cb, tts_h tts, int utt_id, tts_error_e reason, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES tts, is_on, user_data
PROXY_GROUP_NON_BLOCKING(tts_screen_reader_changed_cb, tts_h tts, bool is_on, void * user_data)
PROXY_GROUP_BLOCKING(tts_screen_reader_changed_cb, tts_h tts, bool is_on, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES tts, previous, current, user_data
PROXY_GROUP_NON_BLOCKING(tts_state_changed_cb, tts_h tts, tts_state_e previous, tts_state_e current, void * user_data)
PROXY_GROUP_BLOCKING(tts_state_changed_cb, tts_h tts, tts_state_e previous, tts_state_e current, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES tts, language, voice_type, user_data
PROXY_GROUP_RETURN(tts_supported_voice_cb, bool, tts_h tts, const char * language, int voice_type, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES tts, utt_id, user_data
PROXY_GROUP_NON_BLOCKING(tts_utterance_completed_cb, tts_h tts, int utt_id, void * user_data)
PROXY_GROUP_BLOCKING(tts_utterance_completed_cb, tts_h tts, int utt_id, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES tts, utt_id, user_data
PROXY_GROUP_NON_BLOCKING(tts_utterance_started_cb, tts_h tts, int utt_id, void * user_data)
PROXY_GROUP_BLOCKING(tts_utterance_started_cb, tts_h tts, int utt_id, void * user_data)
#undef CB_PARAMS_NAMES


#include <ttse.h>

#define BASE_CALLBACK_ID_ttse_cancel_synthesis_cb 95
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(ttse_cancel_synthesis_cb, int)

#define BASE_CALLBACK_ID_ttse_check_app_agreed_cb 100
#define CB_PARAMS_NAMES appid, is_agreed
PROXY_GROUP_RETURN_NO_USER_DATA(ttse_check_app_agreed_cb, int, const char * appid, bool * is_agreed)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_ttse_deinitialize_cb 105
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(ttse_deinitialize_cb, int)

#define CB_PARAMS_NAMES callback, user_data
PROXY_GROUP_RETURN(ttse_foreach_supported_voices_cb, int, ttse_supported_voice_cb callback, void * user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_ttse_get_info_cb 110
#define CB_PARAMS_NAMES engine_uuid, engine_name, engine_setting, use_network
PROXY_GROUP_RETURN_NO_USER_DATA(ttse_get_info_cb, int, char ** engine_uuid, char ** engine_name, char ** engine_setting, bool * use_network)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_ttse_initialize_cb 115
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(ttse_initialize_cb, int)

#define BASE_CALLBACK_ID_ttse_is_valid_voice_cb 120
#define CB_PARAMS_NAMES language, type, is_valid
PROXY_GROUP_RETURN_NO_USER_DATA(ttse_is_valid_voice_cb, int, const char * language, int type, bool * is_valid)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_ttse_load_voice_cb 125
#define CB_PARAMS_NAMES language, type
PROXY_GROUP_RETURN_NO_USER_DATA(ttse_load_voice_cb, int, const char * language, int type)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_ttse_need_app_credential_cb 130
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(ttse_need_app_credential_cb, bool)

#define BASE_CALLBACK_ID_ttse_private_data_requested_cb 135
#define CB_PARAMS_NAMES key, data
PROXY_GROUP_RETURN_NO_USER_DATA(ttse_private_data_requested_cb, int, const char * key, char ** data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_ttse_private_data_set_cb 140
#define CB_PARAMS_NAMES key, data
PROXY_GROUP_RETURN_NO_USER_DATA(ttse_private_data_set_cb, int, const char * key, const char * data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_ttse_set_pitch_cb 145
#define CB_PARAMS_NAMES pitch
PROXY_GROUP_RETURN_NO_USER_DATA(ttse_set_pitch_cb, int, int pitch)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES language, type, text, speed, appid, credential, user_data
PROXY_GROUP_RETURN(ttse_start_synthesis_cb, int, const char * language, int type, const char * text, int speed, const char * appid, const char * credential, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES language, type, user_data
PROXY_GROUP_RETURN(ttse_supported_voice_cb, bool, const char * language, int type, void * user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_ttse_unload_voice_cb 150
#define CB_PARAMS_NAMES language, type
PROXY_GROUP_RETURN_NO_USER_DATA(ttse_unload_voice_cb, int, const char * language, int type)
#undef CB_PARAMS_NAMES


#include <usb_host.h>

#define CB_PARAMS_NAMES dev, user_data
PROXY_GROUP_NON_BLOCKING(usb_host_hotplug_cb, usb_host_device_h dev, void * user_data)
PROXY_GROUP_BLOCKING(usb_host_hotplug_cb, usb_host_device_h dev, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES transfer, user_data
PROXY_GROUP_NON_BLOCKING(usb_host_transferred_cb, usb_host_transfer_h transfer, void * user_data)
PROXY_GROUP_BLOCKING(usb_host_transferred_cb, usb_host_transfer_h transfer, void * user_data)
#undef CB_PARAMS_NAMES


#include <vce.h>

#define BASE_CALLBACK_ID_vce_cancel_cb 155
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(vce_cancel_cb, int)

#define CB_PARAMS_NAMES pid, utt_id, user_data
PROXY_GROUP_RETURN(vce_cancel_tts_cb, int, int pid, int utt_id, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES id, type, format, command, param, domain, user_data
PROXY_GROUP_RETURN(vce_command_cb, bool, int id, int type, int format, const char * command, const char * param, int domain, void * user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_deinitialize_cb 160
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(vce_deinitialize_cb, int)

#define CB_PARAMS_NAMES callback, user_data
PROXY_GROUP_RETURN(vce_foreach_supported_languages_cb, int, vce_supported_language_cb callback, void * user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_get_info_cb 165
#define CB_PARAMS_NAMES engine_uuid, engine_name, engine_settings_app_id, use_network
PROXY_GROUP_RETURN_NO_USER_DATA(vce_get_info_cb, int, char ** engine_uuid, char ** engine_name, char ** engine_settings_app_id, bool * use_network)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_get_recording_format_cb 170
#define CB_PARAMS_NAMES audio_id, types, rate, channels
PROXY_GROUP_RETURN_NO_USER_DATA(vce_get_recording_format_cb, int, const char * audio_id, vce_audio_type_e * types, int * rate, int * channels)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_initialize_cb 175
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(vce_initialize_cb, int)

#define BASE_CALLBACK_ID_vce_is_language_supported_cb 180
#define CB_PARAMS_NAMES language
PROXY_GROUP_RETURN_NO_USER_DATA(vce_is_language_supported_cb, bool, const char * language)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_nlu_base_info_requested_cb 185
#define CB_PARAMS_NAMES key, value
PROXY_GROUP_RETURN_NO_USER_DATA(vce_nlu_base_info_requested_cb, int, const char * key, char ** value)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_private_data_requested_cb 190
#define CB_PARAMS_NAMES key, data
PROXY_GROUP_RETURN_NO_USER_DATA(vce_private_data_requested_cb, int, const char * key, char ** data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_private_data_set_cb 195
#define CB_PARAMS_NAMES key, data
PROXY_GROUP_RETURN_NO_USER_DATA(vce_private_data_set_cb, int, const char * key, const char * data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_process_haptic_event_cb 200
#define CB_PARAMS_NAMES event
PROXY_GROUP_RETURN_NO_USER_DATA(vce_process_haptic_event_cb, int, const char * event)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_process_list_event_cb 205
#define CB_PARAMS_NAMES event
PROXY_GROUP_RETURN_NO_USER_DATA(vce_process_list_event_cb, int, const char * event)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_process_text_cb 210
#define CB_PARAMS_NAMES text
PROXY_GROUP_RETURN_NO_USER_DATA(vce_process_text_cb, int, const char * text)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES pid, utt_id, text, language, user_data
PROXY_GROUP_RETURN(vce_request_tts_cb, int, int pid, int utt_id, const char * text, const char * language, void * user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_set_audio_type_cb 215
#define CB_PARAMS_NAMES audio_type
PROXY_GROUP_RETURN_NO_USER_DATA(vce_set_audio_type_cb, int, const char * audio_type)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_set_commands_cb 220
#define CB_PARAMS_NAMES vc_command
PROXY_GROUP_RETURN_NO_USER_DATA(vce_set_commands_cb, int, vce_cmd_h vc_command)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_set_domain_cb 225
#define CB_PARAMS_NAMES domain
PROXY_GROUP_RETURN_NO_USER_DATA(vce_set_domain_cb, int, const char * domain)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_set_language_cb 230
#define CB_PARAMS_NAMES language
PROXY_GROUP_RETURN_NO_USER_DATA(vce_set_language_cb, int, const char * language)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_set_recording_data_cb 235
#define CB_PARAMS_NAMES data, length, speech_detected
PROXY_GROUP_RETURN_NO_USER_DATA(vce_set_recording_data_cb, int, const void * data, unsigned int length, vce_speech_detect_e * speech_detected)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_set_server_dialog_cb 240
#define CB_PARAMS_NAMES app_id, credential
PROXY_GROUP_RETURN_NO_USER_DATA(vce_set_server_dialog_cb, int, const char * app_id, const char * credential)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_specific_engine_request_cb 245
#define CB_PARAMS_NAMES engine_app_id, event, request
PROXY_GROUP_RETURN_NO_USER_DATA(vce_specific_engine_request_cb, int, const char * engine_app_id, const char * event, const char * request)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_start_cb 250
#define CB_PARAMS_NAMES stop_by_silence
PROXY_GROUP_RETURN_NO_USER_DATA(vce_start_cb, int, bool stop_by_silence)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_stop_cb 255
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(vce_stop_cb, int)

#define CB_PARAMS_NAMES language, user_data
PROXY_GROUP_RETURN(vce_supported_language_cb, bool, const char * language, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES rate, channel, audio_type, user_data
PROXY_GROUP_RETURN(vce_tts_audio_format_request_cb, int, int * rate, int * channel, int * audio_type, void * user_data)
#undef CB_PARAMS_NAMES

#define BASE_CALLBACK_ID_vce_unset_commands_cb 260
PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(vce_unset_commands_cb, int)



#include <voice_control_manager.h>

#define CB_PARAMS_NAMES event, vc_cmd_list, result, msg, user_data
PROXY_GROUP_RETURN(vc_mgr_all_result_cb, bool, vc_result_event_e event, vc_cmd_list_h vc_cmd_list, const char * result, const char * msg, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES user_data
PROXY_GROUP_NON_BLOCKING(vc_mgr_begin_speech_detected_cb, void * user_data)
PROXY_GROUP_BLOCKING(vc_mgr_begin_speech_detected_cb, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES pid, disp_text, utt_text, continuous, user_data
PROXY_GROUP_NON_BLOCKING(vc_mgr_dialog_request_cb, int pid, const char * disp_text, const char * utt_text, bool continuous, void * user_data)
PROXY_GROUP_BLOCKING(vc_mgr_dialog_request_cb, int pid, const char * disp_text, const char * utt_text, bool continuous, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES rate, channel, audio_type, user_data
PROXY_GROUP_NON_BLOCKING(vc_mgr_feedback_audio_format_cb, int rate, vc_audio_channel_e channel, vc_audio_type_e audio_type, void * user_data)
PROXY_GROUP_BLOCKING(vc_mgr_feedback_audio_format_cb, int rate, vc_audio_channel_e channel, vc_audio_type_e audio_type, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES event, buffer, len, user_data
PROXY_GROUP_NON_BLOCKING(vc_mgr_feedback_streaming_cb, vc_feedback_event_e event, char * buffer, int len, void * user_data)
PROXY_GROUP_BLOCKING(vc_mgr_feedback_streaming_cb, vc_feedback_event_e event, char * buffer, int len, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES event, result, user_data
PROXY_GROUP_NON_BLOCKING(vc_mgr_pre_result_cb, vc_pre_result_event_e event, const char * result, void * user_data)
PROXY_GROUP_BLOCKING(vc_mgr_pre_result_cb, vc_pre_result_event_e event, const char * result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES key, data, user_data
PROXY_GROUP_RETURN(vc_mgr_private_data_requested_cb, int, const char * key, char ** data, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES key, data, user_data
PROXY_GROUP_RETURN(vc_mgr_private_data_set_cb, int, const char * key, const char * data, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES engine_app_id, event, result, user_data
PROXY_GROUP_NON_BLOCKING(vc_mgr_specific_engine_result_cb, const char * engine_app_id, const char * event, const char * result, void * user_data)
PROXY_GROUP_BLOCKING(vc_mgr_specific_engine_result_cb, const char * engine_app_id, const char * event, const char * result, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES pid, utt_id, event, buffer, len, user_data
PROXY_GROUP_NON_BLOCKING(vc_mgr_vc_tts_streaming_cb, int pid, int utt_id, vc_feedback_event_e event, char * buffer, int len, void * user_data)
PROXY_GROUP_BLOCKING(vc_mgr_vc_tts_streaming_cb, int pid, int utt_id, vc_feedback_event_e event, char * buffer, int len, void * user_data)
#undef CB_PARAMS_NAMES



#include <web/download.h>

#define CB_PARAMS_NAMES download_id, received, user_data
PROXY_GROUP_NON_BLOCKING(download_progress_cb, int download_id, unsigned long long received, void * user_data)
PROXY_GROUP_BLOCKING(download_progress_cb, int download_id, unsigned long long received, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES download_id, state, user_data
PROXY_GROUP_NON_BLOCKING(download_state_changed_cb, int download_id, download_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(download_state_changed_cb, int download_id, download_state_e state, void * user_data)
#undef CB_PARAMS_NAMES


#include <wifi-direct/wifi-direct.h>

#define CB_PARAMS_NAMES mac_address, ip_address, interface_address, user_data
PROXY_GROUP_NON_BLOCKING(wifi_direct_client_ip_address_assigned_cb, const char * mac_address, const char * ip_address, const char * interface_address, void * user_data)
PROXY_GROUP_BLOCKING(wifi_direct_client_ip_address_assigned_cb, const char * mac_address, const char * ip_address, const char * interface_address, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES peer, user_data
PROXY_GROUP_RETURN(wifi_direct_connected_peer_cb, bool, wifi_direct_connected_peer_info_s * peer, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error_code, connection_state, mac_address, user_data
PROXY_GROUP_NON_BLOCKING(wifi_direct_connection_state_changed_cb, int error_code, wifi_direct_connection_state_e connection_state, const char * mac_address, void * user_data)
PROXY_GROUP_BLOCKING(wifi_direct_connection_state_changed_cb, int error_code, wifi_direct_connection_state_e connection_state, const char * mac_address, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error_code, device_state, user_data
PROXY_GROUP_NON_BLOCKING(wifi_direct_device_state_changed_cb, int error_code, wifi_direct_device_state_e device_state, void * user_data)
PROXY_GROUP_BLOCKING(wifi_direct_device_state_changed_cb, int error_code, wifi_direct_device_state_e device_state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES peer, user_data
PROXY_GROUP_RETURN(wifi_direct_discovered_peer_cb, bool, wifi_direct_discovered_peer_info_s * peer, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error_code, discovery_state, user_data
PROXY_GROUP_NON_BLOCKING(wifi_direct_discovery_state_chagned_cb, int error_code, wifi_direct_discovery_state_e discovery_state, void * user_data)
PROXY_GROUP_BLOCKING(wifi_direct_discovery_state_chagned_cb, int error_code, wifi_direct_discovery_state_e discovery_state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error_code, discovery_state, mac_address, user_data
PROXY_GROUP_NON_BLOCKING(wifi_direct_peer_found_cb, int error_code, wifi_direct_discovery_state_e discovery_state, const char * mac_address, void * user_data)
PROXY_GROUP_BLOCKING(wifi_direct_peer_found_cb, int error_code, wifi_direct_discovery_state_e discovery_state, const char * mac_address, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error_code, connection_state, data_s, user_data
PROXY_GROUP_NON_BLOCKING(wifi_direct_peer_info_connection_state_changed_cb, wifi_direct_error_e error_code, wifi_direct_connection_state_e connection_state, wifi_direct_connection_state_cb_data_s data_s, void * user_data)
PROXY_GROUP_BLOCKING(wifi_direct_peer_info_connection_state_changed_cb, wifi_direct_error_e error_code, wifi_direct_connection_state_e connection_state, wifi_direct_connection_state_cb_data_s data_s, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES mac_address, ssid, user_data
PROXY_GROUP_RETURN(wifi_direct_persistent_group_cb, bool, const char * mac_address, const char * ssid, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES error_code, service_state, service_type, response_data, mac_address, user_data
PROXY_GROUP_NON_BLOCKING(wifi_direct_service_state_changed_cb, int error_code, wifi_direct_service_discovery_state_e service_state, wifi_direct_service_type_e service_type, void * response_data, const char * mac_address, void * user_data)
PROXY_GROUP_BLOCKING(wifi_direct_service_state_changed_cb, int error_code, wifi_direct_service_discovery_state_e service_state, wifi_direct_service_type_e service_type, void * response_data, const char * mac_address, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES state, user_data
PROXY_GROUP_NON_BLOCKING(wifi_direct_state_changed_cb, wifi_direct_state_e state, void * user_data)
PROXY_GROUP_BLOCKING(wifi_direct_state_changed_cb, wifi_direct_state_e state, void * user_data)
#undef CB_PARAMS_NAMES

#define CB_PARAMS_NAMES type, user_data
PROXY_GROUP_RETURN(wifi_direct_supported_wps_type_cb, bool, wifi_direct_wps_type_e type, void * user_data)
#undef CB_PARAMS_NAMES




std::map<std::string, MultiProxyFunctionsContainer> __multi_proxy_name_to_ptr_map = {
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
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_control_reply_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_app_control_reply_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_control_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_app_control_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_control_uri_query_foreach_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_create_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_app_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_info_category_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_info_filter_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_info_metadata_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_app_info_res_control_cb)
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
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_adapter_bonded_device_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_adapter_device_discovery_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_adapter_device_discovery_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_adapter_le_advertising_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_adapter_le_advertising_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_adapter_le_scan_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_adapter_le_scan_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_adapter_name_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_adapter_name_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_adapter_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_adapter_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_adapter_visibility_duration_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_adapter_visibility_duration_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_adapter_visibility_mode_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_adapter_visibility_mode_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_ag_call_handling_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_ag_call_handling_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_ag_dtmf_transmitted_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_ag_dtmf_transmitted_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_ag_microphone_gain_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_ag_microphone_gain_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_ag_multi_call_handling_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_ag_multi_call_handling_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_ag_speaker_gain_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_ag_speaker_gain_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_audio_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_audio_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_avrcp_control_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_avrcp_control_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_avrcp_equalizer_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_avrcp_equalizer_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_avrcp_play_status_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_avrcp_play_status_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_avrcp_position_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_avrcp_position_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_avrcp_repeat_mode_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_avrcp_repeat_mode_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_avrcp_scan_mode_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_avrcp_scan_mode_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_avrcp_shuffle_mode_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_avrcp_shuffle_mode_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_avrcp_target_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_avrcp_target_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_avrcp_track_info_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_avrcp_track_info_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_device_authorization_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_device_authorization_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_device_bond_created_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_device_bond_created_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_device_bond_destroyed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_device_bond_destroyed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_device_connected_profile)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_device_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_device_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_device_service_searched_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_device_service_searched_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_gatt_client_att_mtu_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_gatt_client_att_mtu_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_gatt_client_characteristic_value_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_gatt_client_characteristic_value_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_gatt_client_request_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_gatt_client_request_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_gatt_client_service_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_gatt_client_service_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_gatt_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_gatt_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_gatt_foreach_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_gatt_server_characteristic_notification_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_gatt_server_characteristic_notification_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_gatt_server_notification_sent_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_gatt_server_notification_sent_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_gatt_server_read_value_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_gatt_server_read_value_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_gatt_server_write_value_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_gatt_server_write_value_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_hdp_connected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_hdp_connected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_hdp_data_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_hdp_data_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_hdp_disconnected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_hdp_disconnected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_hid_device_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_hid_device_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_hid_device_data_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_hid_device_data_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_hid_host_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_hid_host_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_hrp_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_hrp_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_hrp_sensor_characteristic_notification_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_hrp_sensor_characteristic_notification_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_ipsp_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_ipsp_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_ipsp_init_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_ipsp_init_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_nap_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_nap_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_opp_client_push_finished_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_opp_client_push_finished_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_opp_client_push_progress_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_opp_client_push_progress_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_opp_client_push_responded_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_opp_client_push_responded_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_opp_server_connection_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_opp_server_connection_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_opp_server_transfer_finished_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_opp_server_transfer_finished_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_opp_server_transfer_progress_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_opp_server_transfer_progress_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_panu_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_panu_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_pbap_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_pbap_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_pbap_list_vcards_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_pbap_list_vcards_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_pbap_phone_book_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_pbap_phone_book_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_pbap_phone_book_size_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_pbap_phone_book_size_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_socket_connection_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_socket_connection_requested_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_socket_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_socket_connection_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_bt_socket_data_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_bt_socket_data_received_cb)
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
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_device_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_camera_device_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_camera_error_cb)
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
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_supported_preview_format_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_supported_preview_resolution_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_capability_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cbhm_item_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_cbhm_item_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cbhm_monitor_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_cbhm_monitor_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cbhm_selected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cbhm_selection_data_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cion_client_connection_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_cion_client_connection_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cion_client_disconnected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_cion_client_disconnected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cion_client_payload_async_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_cion_client_payload_async_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cion_client_payload_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_cion_client_payload_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cion_client_server_discovered_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_cion_client_server_discovered_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cion_group_joined_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_cion_group_joined_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cion_group_left_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_cion_group_left_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cion_group_payload_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_cion_group_payload_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cion_server_connected_peer_info_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cion_server_connection_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_cion_server_connection_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cion_server_connection_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_cion_server_connection_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cion_server_data_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_cion_server_data_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cion_server_disconnected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_cion_server_disconnected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cion_server_payload_async_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_cion_server_payload_async_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_cion_server_payload_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_cion_server_payload_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_component_manager_component_context_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_component_manager_component_info_cb)
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
  MULTI_PROXY_MAP_ENTRY(platform_blocking_connection_profile_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_connection_profile_state_changed_cb)
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
  MULTI_PROXY_MAP_ENTRY(platform_blocking_data_control_add_callback_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_data_control_add_callback_result_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_data_control_bulk_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_data_control_bulk_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_data_control_data_change_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_data_control_data_change_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_data_control_map_add_response_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_data_control_map_add_response_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_data_control_map_get_response_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_data_control_map_get_response_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_data_control_map_remove_response_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_data_control_map_remove_response_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_data_control_map_set_response_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_data_control_map_set_response_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_data_control_provider_bulk_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_data_control_provider_bulk_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_data_control_provider_data_change_consumer_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_data_control_provider_data_change_consumer_filter_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_data_control_provider_map_add_value_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_data_control_provider_map_add_value_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_data_control_provider_map_get_value_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_data_control_provider_map_get_value_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_data_control_provider_map_remove_value_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_data_control_provider_map_remove_value_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_data_control_provider_map_set_value_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_data_control_provider_map_set_value_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_data_control_provider_sql_delete_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_data_control_provider_sql_delete_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_data_control_provider_sql_insert_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_data_control_provider_sql_insert_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_data_control_provider_sql_select_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_data_control_provider_sql_select_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_data_control_provider_sql_update_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_data_control_provider_sql_update_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_data_control_sql_delete_response_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_data_control_sql_delete_response_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_data_control_sql_insert_response_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_data_control_sql_insert_response_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_data_control_sql_select_response_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_data_control_sql_select_response_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_data_control_sql_update_response_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_data_control_sql_update_response_cb)
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
  MULTI_PROXY_MAP_ENTRY(platform_blocking_image_util_decode_completed2_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_image_util_decode_completed2_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_image_util_decode_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_image_util_decode_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_image_util_encode_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_image_util_encode_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_image_util_encode_to_buffer_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_image_util_encode_to_buffer_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_image_util_encode_to_file_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_image_util_encode_to_file_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_image_util_supported_colorspace_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_image_util_transform_completed2_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_image_util_transform_completed2_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_image_util_transform_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_image_util_transform_completed_cb)
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
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_attributes_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_children_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_device_info_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_found_resource_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_generated_pin_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_iotcon_generated_pin_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_list_attributes_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_list_bool_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_list_byte_str_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_list_double_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_list_int_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_list_list_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_list_str_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_lite_resource_post_request_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_options_foreach_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_platform_info_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_presence_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_iotcon_presence_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_query_foreach_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_remote_resource_cached_representation_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_iotcon_remote_resource_cached_representation_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_remote_resource_observe_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_iotcon_remote_resource_observe_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_remote_resource_response_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_iotcon_remote_resource_response_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_remote_resource_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_iotcon_remote_resource_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_request_handler_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_iotcon_request_handler_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_resource_interfaces_foreach_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_iotcon_resource_types_foreach_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_job_scheduler_foreach_job_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_job_service_start_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_job_service_start_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_job_service_stop_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_job_service_stop_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_location_batch_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_location_batch_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_location_batch_get_location_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_location_bounds_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_location_bounds_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_location_bounds_state_changed_cb)
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
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_repeat_mode_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_repeat_mode_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_search_condition_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_server_custom_cmd_received_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_server_custom_cmd_received_cb)
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
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_shuffle_mode_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mc_shuffle_mode_updated_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mc_subscribed_server_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_album_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_bookmark_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_content_db_update_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_media_content_db_update_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_face_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_face_detection_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_media_face_detection_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_folder_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_group_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_info_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_insert_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_media_insert_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_key_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_media_key_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_packet_dispose_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_media_packet_dispose_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_packet_finalize_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_playlist_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_scan_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_media_scan_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_storage_cb)
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
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_tag_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_media_thumbnail_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_media_thumbnail_completed_cb)
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
  MULTI_PROXY_MAP_ENTRY(platform_blocking_ml_train_datagen_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_barcode_detected_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mv_barcode_detected_cb)
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
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_supported_attribute_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_surveillance_event_occurred_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_mv_surveillance_event_occurred_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_surveillance_event_result_name_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_mv_surveillance_event_type_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_noti_ex_item_group_foreach_child_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_noti_ex_manager_events_add_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_noti_ex_manager_events_add_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_noti_ex_manager_events_delete_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_noti_ex_manager_events_delete_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_noti_ex_manager_events_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_noti_ex_manager_events_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_noti_ex_manager_events_update_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_noti_ex_manager_events_update_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_noti_ex_reporter_events_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_noti_ex_reporter_events_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_noti_ex_reporter_events_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_noti_ex_reporter_events_event_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_package_info_app_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_package_info_cert_info_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_package_info_dependency_info_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_package_info_privilege_info_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_package_info_res_allowed_package_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_package_info_updateinfo_cb)
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
  MULTI_PROXY_MAP_ENTRY(platform_blocking_playlist_member_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_polygon_coords_cb)
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
  MULTI_PROXY_MAP_ENTRY(platform_blocking_scmirroring_sink_state_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_scmirroring_sink_state_cb)
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
  MULTI_PROXY_MAP_ENTRY(platform_blocking_sound_device_connection_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_sound_device_connection_changed_cb)
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
  MULTI_PROXY_MAP_ENTRY(platform_blocking_storage_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_storage_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_storage_device_supported_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_storage_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_storage_state_changed_cb)
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
  MULTI_PROXY_MAP_ENTRY(platform_blocking_thumbnail_extracted_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_thumbnail_extracted_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_tts_default_voice_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_tts_default_voice_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_tts_engine_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_tts_engine_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_tts_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_tts_error_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_tts_screen_reader_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_tts_screen_reader_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_tts_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_tts_state_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_tts_supported_voice_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_tts_utterance_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_tts_utterance_completed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_tts_utterance_started_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_tts_utterance_started_cb)
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
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_track_added_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_webrtc_track_added_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_webrtc_turn_server_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_widget_app_create_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_widget_app_terminate_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_widget_app_terminate_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_widget_context_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_widget_instance_create_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_widget_instance_destroy_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_widget_instance_pause_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_widget_instance_resize_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_widget_instance_resume_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_widget_instance_update_cb)
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

std::map<std::string, int> __reserved_base_id_map = {
  {std::string("bt_hrp_connection_state_changed_cb"), BASE_CALLBACK_ID_bt_hrp_connection_state_changed_cb},
  {std::string("stte_cancel_cb"), BASE_CALLBACK_ID_stte_cancel_cb},
  {std::string("stte_check_app_agreed_cb"), BASE_CALLBACK_ID_stte_check_app_agreed_cb},
  {std::string("stte_deinitialize_cb"), BASE_CALLBACK_ID_stte_deinitialize_cb},
  {std::string("stte_get_info_cb"), BASE_CALLBACK_ID_stte_get_info_cb},
  {std::string("stte_get_recording_format_cb"), BASE_CALLBACK_ID_stte_get_recording_format_cb},
  {std::string("stte_initialize_cb"), BASE_CALLBACK_ID_stte_initialize_cb},
  {std::string("stte_is_valid_language_cb"), BASE_CALLBACK_ID_stte_is_valid_language_cb},
  {std::string("stte_need_app_credential_cb"), BASE_CALLBACK_ID_stte_need_app_credential_cb},
  {std::string("stte_private_data_requested_cb"), BASE_CALLBACK_ID_stte_private_data_requested_cb},
  {std::string("stte_private_data_set_cb"), BASE_CALLBACK_ID_stte_private_data_set_cb},
  {std::string("stte_set_recording_data_cb"), BASE_CALLBACK_ID_stte_set_recording_data_cb},
  {std::string("stte_set_silence_detection_cb"), BASE_CALLBACK_ID_stte_set_silence_detection_cb},
  {std::string("stte_stop_cb"), BASE_CALLBACK_ID_stte_stop_cb},
  {std::string("stte_support_recognition_type_cb"), BASE_CALLBACK_ID_stte_support_recognition_type_cb},
  {std::string("stte_support_silence_detection_cb"), BASE_CALLBACK_ID_stte_support_silence_detection_cb},
  {std::string("sync_adapter_cancel_sync_cb"), BASE_CALLBACK_ID_sync_adapter_cancel_sync_cb},
  {std::string("sync_adapter_start_sync_cb"), BASE_CALLBACK_ID_sync_adapter_start_sync_cb},
  {std::string("ttse_cancel_synthesis_cb"), BASE_CALLBACK_ID_ttse_cancel_synthesis_cb},
  {std::string("ttse_check_app_agreed_cb"), BASE_CALLBACK_ID_ttse_check_app_agreed_cb},
  {std::string("ttse_deinitialize_cb"), BASE_CALLBACK_ID_ttse_deinitialize_cb},
  {std::string("ttse_get_info_cb"), BASE_CALLBACK_ID_ttse_get_info_cb},
  {std::string("ttse_initialize_cb"), BASE_CALLBACK_ID_ttse_initialize_cb},
  {std::string("ttse_is_valid_voice_cb"), BASE_CALLBACK_ID_ttse_is_valid_voice_cb},
  {std::string("ttse_load_voice_cb"), BASE_CALLBACK_ID_ttse_load_voice_cb},
  {std::string("ttse_need_app_credential_cb"), BASE_CALLBACK_ID_ttse_need_app_credential_cb},
  {std::string("ttse_private_data_requested_cb"), BASE_CALLBACK_ID_ttse_private_data_requested_cb},
  {std::string("ttse_private_data_set_cb"), BASE_CALLBACK_ID_ttse_private_data_set_cb},
  {std::string("ttse_set_pitch_cb"), BASE_CALLBACK_ID_ttse_set_pitch_cb},
  {std::string("ttse_unload_voice_cb"), BASE_CALLBACK_ID_ttse_unload_voice_cb},
  {std::string("vce_cancel_cb"), BASE_CALLBACK_ID_vce_cancel_cb},
  {std::string("vce_deinitialize_cb"), BASE_CALLBACK_ID_vce_deinitialize_cb},
  {std::string("vce_get_info_cb"), BASE_CALLBACK_ID_vce_get_info_cb},
  {std::string("vce_get_recording_format_cb"), BASE_CALLBACK_ID_vce_get_recording_format_cb},
  {std::string("vce_initialize_cb"), BASE_CALLBACK_ID_vce_initialize_cb},
  {std::string("vce_is_language_supported_cb"), BASE_CALLBACK_ID_vce_is_language_supported_cb},
  {std::string("vce_nlu_base_info_requested_cb"), BASE_CALLBACK_ID_vce_nlu_base_info_requested_cb},
  {std::string("vce_private_data_requested_cb"), BASE_CALLBACK_ID_vce_private_data_requested_cb},
  {std::string("vce_private_data_set_cb"), BASE_CALLBACK_ID_vce_private_data_set_cb},
  {std::string("vce_process_haptic_event_cb"), BASE_CALLBACK_ID_vce_process_haptic_event_cb},
  {std::string("vce_process_list_event_cb"), BASE_CALLBACK_ID_vce_process_list_event_cb},
  {std::string("vce_process_text_cb"), BASE_CALLBACK_ID_vce_process_text_cb},
  {std::string("vce_set_audio_type_cb"), BASE_CALLBACK_ID_vce_set_audio_type_cb},
  {std::string("vce_set_commands_cb"), BASE_CALLBACK_ID_vce_set_commands_cb},
  {std::string("vce_set_domain_cb"), BASE_CALLBACK_ID_vce_set_domain_cb},
  {std::string("vce_set_language_cb"), BASE_CALLBACK_ID_vce_set_language_cb},
  {std::string("vce_set_recording_data_cb"), BASE_CALLBACK_ID_vce_set_recording_data_cb},
  {std::string("vce_set_server_dialog_cb"), BASE_CALLBACK_ID_vce_set_server_dialog_cb},
  {std::string("vce_specific_engine_request_cb"), BASE_CALLBACK_ID_vce_specific_engine_request_cb},
  {std::string("vce_start_cb"), BASE_CALLBACK_ID_vce_start_cb},
  {std::string("vce_stop_cb"), BASE_CALLBACK_ID_vce_stop_cb},
  {std::string("vce_unset_commands_cb"), BASE_CALLBACK_ID_vce_unset_commands_cb},
};
