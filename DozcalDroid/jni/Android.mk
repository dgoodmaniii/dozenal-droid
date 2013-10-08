LOCAL_PATH:=$(call ./)

include $(CLEAR_VARS)

LOCAL_MODULE := DozcalDroid
LOCAL_CFLAGS := -Werror

include $(BUILD_SHARED_LIBRARY)
