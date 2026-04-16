// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class COA : ModuleRules
{
	public COA(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"COA",
			"COA/Variant_Platforming",
			"COA/Variant_Platforming/Animation",
			"COA/Variant_Combat",
			"COA/Variant_Combat/AI",
			"COA/Variant_Combat/Animation",
			"COA/Variant_Combat/Gameplay",
			"COA/Variant_Combat/Interfaces",
			"COA/Variant_Combat/UI",
			"COA/Variant_SideScrolling",
			"COA/Variant_SideScrolling/AI",
			"COA/Variant_SideScrolling/Gameplay",
			"COA/Variant_SideScrolling/Interfaces",
			"COA/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
