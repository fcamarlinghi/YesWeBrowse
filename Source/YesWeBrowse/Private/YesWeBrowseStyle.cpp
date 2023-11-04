// Copyright Francesco Camarlinghi. All rights reserved.

#include "YesWeBrowseStyle.h"
#include "Brushes/SlateImageBrush.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/CoreStyle.h"
#include "Styling/SlateStyleRegistry.h"

#define IMAGE_PLUGIN_BRUSH_SVG(RelativePath, ...) FSlateVectorImageBrush(RootToPluginContentDir(RelativePath, TEXT(".svg")), __VA_ARGS__)

TSharedPtr<FSlateStyleSet> FYesWeBrowseStyle::StyleSet = nullptr;

FName FYesWeBrowseStyle::GetStyleSetName()
{
	static const FName StyleSetName(TEXT("YesWeBrowseStyle"));
	return StyleSetName;
}

void FYesWeBrowseStyle::Initialize()
{
	if (StyleSet.IsValid())
	{
		// Only register once
		return;
	}

	// Create style sheet
	StyleSet = MakeShared<FSlateStyleSet>(GetStyleSetName());
	StyleSet->SetContentRoot(FPaths::EngineContentDir() / TEXT("Editor/Slate"));
	StyleSet->SetCoreContentRoot(FPaths::EngineContentDir() / TEXT("Slate"));

	const FVector2D Icon16x16(16.0f, 16.0f);
	StyleSet->Set("ContentBrowserNewWindowIcon", new IMAGE_PLUGIN_BRUSH_SVG("ContentBrowserNewWindow", Icon16x16));

	FSlateStyleRegistry::RegisterSlateStyle(*StyleSet.Get());
}

void FYesWeBrowseStyle::Shutdown()
{
	if (StyleSet.IsValid())
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*StyleSet.Get());
		ensure(StyleSet.IsUnique());
		StyleSet.Reset();
	}
}

FString FYesWeBrowseStyle::RootToPluginContentDir(const FString& RelativePath, const TCHAR* Extension)
{
	static const FString ContentDir = IPluginManager::Get().FindPlugin(TEXT("YesWeBrowse"))->GetContentDir();
	return (ContentDir / RelativePath) + Extension;
}

#undef IMAGE_PLUGIN_BRUSH_SVG
