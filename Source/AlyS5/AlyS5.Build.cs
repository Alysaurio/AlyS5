// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AlyS5 : ModuleRules
{
	public AlyS5(ReadOnlyTargetRules Target) : base(Target)
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
			"AlyS5",
			"AlyS5/Variant_Platforming",
			"AlyS5/Variant_Platforming/Animation",
			"AlyS5/Variant_Combat",
			"AlyS5/Variant_Combat/AI",
			"AlyS5/Variant_Combat/Animation",
			"AlyS5/Variant_Combat/Gameplay",
			"AlyS5/Variant_Combat/Interfaces",
			"AlyS5/Variant_Combat/UI",
			"AlyS5/Variant_SideScrolling",
			"AlyS5/Variant_SideScrolling/AI",
			"AlyS5/Variant_SideScrolling/Gameplay",
			"AlyS5/Variant_SideScrolling/Interfaces",
			"AlyS5/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
