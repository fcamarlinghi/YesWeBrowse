// Copyright Francesco Camarlinghi. All Rights Reserved.

using UnrealBuildTool;

public class YesWeBrowse : ModuleRules
{
	public YesWeBrowse(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		ShadowVariableWarningLevel = WarningLevel.Error;

		PrivateIncludePaths.Add("YesWeBrowse");

		PrivateDependencyModuleNames.AddRange(new[]
		{
			"Core",
			"Slate",
			"SlateCore",
			"ToolMenus",
		});
	}
}
