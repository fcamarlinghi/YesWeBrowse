// Copyright Francesco Camarlinghi. All Rights Reserved.

#include "YesWeBrowse.h"
#include "YesWeBrowseStyle.h"

#include "Framework/Docking/TabManager.h"
#include "Modules/ModuleManager.h"
#include "ToolMenus.h"

IMPLEMENT_MODULE(FYesWeBrowseModule, YesWeBrowse);

#define LOCTEXT_NAMESPACE "YesWeBrowseModule"

void FYesWeBrowseModule::RegisterButton()
{
	FToolMenuOwnerScoped OwnerScoped(this);

	UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu(TEXT("LevelEditor.LevelEditorToolBar.AssetsToolBar"));
	FToolMenuSection& Section = ToolbarMenu->FindOrAddSection(TEXT("Content"));

	Section.AddEntry(FToolMenuEntry::InitToolBarButton(
		TEXT("YesWeBrowse_OpenContentBrowserWindow"),
		FUIAction(
			FExecuteAction::CreateLambda([]()
			{
				static const FName TabID("ContentBrowserTab1");
				FGlobalTabmanager::Get()->TryInvokeTab(TabID);
			}),
			FCanExecuteAction::CreateLambda([]() { return true; })
		),
		LOCTEXT("ButtonLabel", "Open Content Browser Window"),
		LOCTEXT("ButtonTooltip", "Opens a Content Browser window"),
		FSlateIcon(FYesWeBrowseStyle::Get().GetStyleSetName(), TEXT("ContentBrowserNewWindowIcon"))
	));
}

void FYesWeBrowseModule::StartupModule()
{
	FYesWeBrowseStyle::Initialize();

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(
		this, &FYesWeBrowseModule::RegisterButton));
}

void FYesWeBrowseModule::ShutdownModule()
{
	UToolMenus::UnRegisterStartupCallback(this);
	UToolMenus::UnregisterOwner(this);

	FYesWeBrowseStyle::Shutdown();
}

#undef LOCTEXT_NAMESPACE
