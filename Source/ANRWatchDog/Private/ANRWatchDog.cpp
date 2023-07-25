//#define PLATFORM_ANDROID 1


#include "ANRWatchDog.h"
#include "Settings/Public/ISettingsModule.h"

#if PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"

static jmethodID GenerateANR;

static void CallVoidMethod(JNIEnv* Env, jmethodID Method, ...)
{
	// make sure the function exists
	jobject Object = FJavaWrapper::GameActivityThis;
	if (Method == NULL || Object == NULL || Env == NULL)
	{
		return;
	}

	va_list Args;
	va_start(Args, Method);
	Env->CallVoidMethodV(Object, Method, Args);
	va_end(Args);
}



#endif


void FANRWatchDogModule::StartupModule()  {}
void FANRWatchDogModule::ShutdownModule() {}

FANRWatchDogModule* FANRWatchDogModule::GetModule()
{
	return FModuleManager::Get().GetModulePtr<FANRWatchDogModule>("ANRWatchDog");
}

IMPLEMENT_MODULE(FANRWatchDogModule, ANRWatchDog)
 