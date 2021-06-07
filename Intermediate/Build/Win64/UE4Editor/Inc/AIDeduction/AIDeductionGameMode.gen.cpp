// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AIDeduction/AIDeductionGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAIDeductionGameMode() {}
// Cross Module References
	AIDEDUCTION_API UClass* Z_Construct_UClass_AAIDeductionGameMode_NoRegister();
	AIDEDUCTION_API UClass* Z_Construct_UClass_AAIDeductionGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_AIDeduction();
	AIDEDUCTION_API UClass* Z_Construct_UClass_APlayerSpectator_NoRegister();
	AIDEDUCTION_API UClass* Z_Construct_UClass_ACrewMateBase_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AAIDeductionGameMode::execSetPlayerSpectator)
	{
		P_GET_OBJECT(APlayerSpectator,Z_Param_newPlayerCamera);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPlayerSpectator(Z_Param_newPlayerCamera);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AAIDeductionGameMode::execResetGame)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ResetGame();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AAIDeductionGameMode::execStartGame)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StartGame();
		P_NATIVE_END;
	}
	void AAIDeductionGameMode::StaticRegisterNativesAAIDeductionGameMode()
	{
		UClass* Class = AAIDeductionGameMode::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ResetGame", &AAIDeductionGameMode::execResetGame },
			{ "SetPlayerSpectator", &AAIDeductionGameMode::execSetPlayerSpectator },
			{ "StartGame", &AAIDeductionGameMode::execStartGame },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AAIDeductionGameMode_ResetGame_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AAIDeductionGameMode_ResetGame_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/// <summary>\n/// Function to return all of the crewmates and the player camera to their initial positions, and wipe all of the crewmates memories.\n/// </summary>\n" },
		{ "ModuleRelativePath", "AIDeductionGameMode.h" },
		{ "ToolTip", "<summary>\nFunction to return all of the crewmates and the player camera to their initial positions, and wipe all of the crewmates memories.\n</summary>" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AAIDeductionGameMode_ResetGame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AAIDeductionGameMode, nullptr, "ResetGame", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AAIDeductionGameMode_ResetGame_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AAIDeductionGameMode_ResetGame_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AAIDeductionGameMode_ResetGame()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AAIDeductionGameMode_ResetGame_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AAIDeductionGameMode_SetPlayerSpectator_Statics
	{
		struct AIDeductionGameMode_eventSetPlayerSpectator_Parms
		{
			APlayerSpectator* newPlayerCamera;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_newPlayerCamera;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AAIDeductionGameMode_SetPlayerSpectator_Statics::NewProp_newPlayerCamera = { "newPlayerCamera", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AIDeductionGameMode_eventSetPlayerSpectator_Parms, newPlayerCamera), Z_Construct_UClass_APlayerSpectator_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AAIDeductionGameMode_SetPlayerSpectator_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAIDeductionGameMode_SetPlayerSpectator_Statics::NewProp_newPlayerCamera,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AAIDeductionGameMode_SetPlayerSpectator_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/// <summary>\n/// Sets the reference to the PlayerSpectator for the game mode.\n/// </summary>\n/// <param name=\"newPlayerCamera\">The new PlayerSpectator to refer to.</param>\n" },
		{ "ModuleRelativePath", "AIDeductionGameMode.h" },
		{ "ToolTip", "<summary>\nSets the reference to the PlayerSpectator for the game mode.\n</summary>\n<param name=\"newPlayerCamera\">The new PlayerSpectator to refer to.</param>" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AAIDeductionGameMode_SetPlayerSpectator_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AAIDeductionGameMode, nullptr, "SetPlayerSpectator", nullptr, nullptr, sizeof(AIDeductionGameMode_eventSetPlayerSpectator_Parms), Z_Construct_UFunction_AAIDeductionGameMode_SetPlayerSpectator_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AAIDeductionGameMode_SetPlayerSpectator_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AAIDeductionGameMode_SetPlayerSpectator_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AAIDeductionGameMode_SetPlayerSpectator_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AAIDeductionGameMode_SetPlayerSpectator()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AAIDeductionGameMode_SetPlayerSpectator_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AAIDeductionGameMode_StartGame_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AAIDeductionGameMode_StartGame_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/// <summary>\n/// Function to indicate to all crewmatesa and the player spectator that the simulation has begun.\n/// </summary>\n" },
		{ "ModuleRelativePath", "AIDeductionGameMode.h" },
		{ "ToolTip", "<summary>\nFunction to indicate to all crewmatesa and the player spectator that the simulation has begun.\n</summary>" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AAIDeductionGameMode_StartGame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AAIDeductionGameMode, nullptr, "StartGame", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AAIDeductionGameMode_StartGame_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AAIDeductionGameMode_StartGame_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AAIDeductionGameMode_StartGame()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AAIDeductionGameMode_StartGame_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AAIDeductionGameMode_NoRegister()
	{
		return AAIDeductionGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AAIDeductionGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_crewMates_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_crewMates;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_crewMates_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_mainMenuClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_mainMenuClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_wayPointsClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_wayPointsClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_wayPoints_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_wayPoints;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_wayPoints_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAIDeductionGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_AIDeduction,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AAIDeductionGameMode_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AAIDeductionGameMode_ResetGame, "ResetGame" }, // 4177185275
		{ &Z_Construct_UFunction_AAIDeductionGameMode_SetPlayerSpectator, "SetPlayerSpectator" }, // 776572447
		{ &Z_Construct_UFunction_AAIDeductionGameMode_StartGame, "StartGame" }, // 2193378931
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAIDeductionGameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * The game mode used in the simulation.\n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "AIDeductionGameMode.h" },
		{ "ModuleRelativePath", "AIDeductionGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
		{ "ToolTip", "The game mode used in the simulation." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_crewMates_MetaData[] = {
		{ "Category", "AI" },
		{ "Comment", "/// <summary>\n/// List of all the crewmates in the game.\n/// </summary>\n" },
		{ "ModuleRelativePath", "AIDeductionGameMode.h" },
		{ "ToolTip", "<summary>\nList of all the crewmates in the game.\n</summary>" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_crewMates = { "crewMates", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAIDeductionGameMode, crewMates), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_crewMates_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_crewMates_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_crewMates_Inner = { "crewMates", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_ACrewMateBase_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_mainMenuClass_MetaData[] = {
		{ "Category", "UI" },
		{ "Comment", "/// <summary>\n/// The class type of the main menu, used to indicate what type of UI should be created for the main menu.\n/// </summary>\n" },
		{ "ModuleRelativePath", "AIDeductionGameMode.h" },
		{ "ToolTip", "<summary>\nThe class type of the main menu, used to indicate what type of UI should be created for the main menu.\n</summary>" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_mainMenuClass = { "mainMenuClass", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAIDeductionGameMode, mainMenuClass), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_mainMenuClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_mainMenuClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_wayPointsClass_MetaData[] = {
		{ "Category", "Map" },
		{ "Comment", "/// <summary>\n/// The class of what the waypoints are. This is set in the game mode's blueprint and indicates to what the \n/// game mode should be looking for when filling the list of waypoint references.\n/// </summary>\n" },
		{ "ModuleRelativePath", "AIDeductionGameMode.h" },
		{ "ToolTip", "<summary>\nThe class of what the waypoints are. This is set in the game mode's blueprint and indicates to what the\ngame mode should be looking for when filling the list of waypoint references.\n</summary>" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_wayPointsClass = { "wayPointsClass", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAIDeductionGameMode, wayPointsClass), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_wayPointsClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_wayPointsClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_wayPoints_MetaData[] = {
		{ "Category", "Map" },
		{ "Comment", "/// <summary>\n/// The list of all waypoints in the simulation.\n/// </summary>\n" },
		{ "ModuleRelativePath", "AIDeductionGameMode.h" },
		{ "ToolTip", "<summary>\nThe list of all waypoints in the simulation.\n</summary>" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_wayPoints = { "wayPoints", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAIDeductionGameMode, wayPoints), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_wayPoints_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_wayPoints_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_wayPoints_Inner = { "wayPoints", nullptr, (EPropertyFlags)0x0000000000020000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AAIDeductionGameMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_crewMates,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_crewMates_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_mainMenuClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_wayPointsClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_wayPoints,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAIDeductionGameMode_Statics::NewProp_wayPoints_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAIDeductionGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAIDeductionGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AAIDeductionGameMode_Statics::ClassParams = {
		&AAIDeductionGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AAIDeductionGameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AAIDeductionGameMode_Statics::PropPointers),
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AAIDeductionGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AAIDeductionGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAIDeductionGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AAIDeductionGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AAIDeductionGameMode, 2057172558);
	template<> AIDEDUCTION_API UClass* StaticClass<AAIDeductionGameMode>()
	{
		return AAIDeductionGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AAIDeductionGameMode(Z_Construct_UClass_AAIDeductionGameMode, &AAIDeductionGameMode::StaticClass, TEXT("/Script/AIDeduction"), TEXT("AAIDeductionGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAIDeductionGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
