// Copyright Francesco Camarlinghi. All rights reserved.

#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateStyle.h"

class FYesWeBrowseStyle final
{
public:

	static void Initialize();
	static void Shutdown();

	static ISlateStyle& Get()
	{
		return *StyleSet.Get();
	}

	static FName GetStyleSetName();

private:

	static FString RootToPluginContentDir(const FString& RelativePath, const TCHAR* Extension);

private:

	static TSharedPtr<FSlateStyleSet> StyleSet;
};
