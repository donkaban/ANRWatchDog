#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FANRWatchDogModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	static FANRWatchDogModule* GetModule();

#if PLATFORM_ANDROID


#endif
};

