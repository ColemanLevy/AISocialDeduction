// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AIDeduction : ModuleRules
{
	public AIDeduction(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "GameplayTasks", "UMG", "AIModule" });
	}
}
