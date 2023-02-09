// Copyright Francesco Camarlinghi. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

class FYesWeBrowseModule : public IModuleInterface
{
private:

	void RegisterButton();

	// IModuleInterface interface
public:
	void StartupModule() override;
	void ShutdownModule() override;
};
