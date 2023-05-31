#ifndef __LOG_H__
#define __LOG_H__

#include <dlog.h>

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "TizenInteropCallbacksPlugin"

#ifndef __MODULE__
#define __MODULE__ strrchr("/" __FILE__, '/') + 1
#endif

#define LOG(prio, fmt, arg...)                                         \
  dlog_print(prio, LOG_TAG, "%s: %s(%d) > " fmt, __MODULE__, __func__, \
             __LINE__, ##arg)

#define LOG_DEBUG(fmt, args...) LOG(DLOG_DEBUG, fmt, ##args)
#define LOG_INFO(fmt, args...) LOG(DLOG_INFO, fmt, ##args)
#define LOG_WARN(fmt, args...) LOG(DLOG_WARN, fmt, ##args)
#define LOG_ERROR(fmt, args...) LOG(DLOG_ERROR, fmt, ##args)

// You can switch detailed debugging here: 0 - disabled
#if 0
#define LDEBUG(...) LOG_DEBUG(__VA_ARGS__)
#else
#define LDEBUG(...)
#endif

#endif  // __LOG_H__
