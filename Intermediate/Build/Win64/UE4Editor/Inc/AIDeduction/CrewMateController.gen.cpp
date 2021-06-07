// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AIDeduction/CrewMateController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCrewMateController() {}
// Cross Module References
	AIDEDUCTION_API UClass* Z_Construct_UClass_ACrewMateController_NoRegister();
	AIDEDUCTION_API UClass* Z_Construct_UClass_ACrewMateController();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	UPackage* Z_Construct_UPackage__Script_AIDeduction();
	AIDEDUCTION_API UClass* Z_Construct_UClass_AAIDeductionGameMode_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	AIDEDUCTION_API UClass* Z_Construct_UClass_ACrewMateBase_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UBlackboardComponent_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTreeComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ACrewMateController::execResetAI)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ResetAI();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ACrewMateController::execStartAI)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StartAI();
		P_NATIVE_END;
	}
	void ACrewMateController::StaticRegisterNativesACrewMateController()
	{
		UClass* Class = ACrewMateController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ResetAI", &ACrewMateController::execResetAI },
			{ "StartAI", &ACrewMateController::execStartAI },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ACrewMateController_ResetAI_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACrewMateController_ResetAI_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/// <summary>\n/// Function to reset a crewmate to where it spawned, clear its memories, and stop its behavior tree\n/// </summary>\n" },
		{ "ModuleRelativePath", "CrewMateController.h" },
		{ "ToolTip", "<summary>\nFunction to reset a crewmate to where it spawned, clear its memories, and stop its behavior tree\n</summary>" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ACrewMateController_ResetAI_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACrewMateController, nullptr, "ResetAI", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ACrewMateController_ResetAI_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ACrewMateController_ResetAI_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ACrewMateController_ResetAI()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ACrewMateController_ResetAI_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ACrewMateController_StartAI_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACrewMateController_StartAI_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/// <summary>\n/// Function to start the crewmate's behavior tree.\n/// </summary>\n" },
		{ "ModuleRelativePath", "CrewMateController.h" },
		{ "ToolTip", "<summary>\nFunction to start the crewmate's behavior tree.\n</summary>" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ACrewMateController_StartAI_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACrewMateController, nullptr, "StartAI", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ACrewMateController_StartAI_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ACrewMateController_StartAI_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ACrewMateController_StartAI()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ACrewMateController_StartAI_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ACrewMateController_NoRegister()
	{
		return ACrewMateController::StaticClass();
	}
	struct Z_Construct_UClass_ACrewMateController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_gameMode_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_gameMode;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_startingTransform_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_startingTransform;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_crewmateNPC_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_crewmateNPC;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_blackboardComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_blackboardComp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_behaviorComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_behaviorComp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LocationToGoKey_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_LocationToGoKey;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACrewMateController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_AIDeduction,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ACrewMateController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ACrewMateController_ResetAI, "ResetAI" }, // 279950137
		{ &Z_Construct_UFunction_ACrewMateController_StartAI, "StartAI" }, // 1486570721
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACrewMateController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * The controller for the crewmates which determine how they will act.\n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "CrewMateController.h" },
		{ "ModuleRelativePath", "CrewMateController.h" },
		{ "ToolTip", "The controller for the crewmates which determine how they will act." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACrewMateController_Statics::NewProp_gameMode_MetaData[] = {
		{ "Category", "References" },
		{ "Comment", "/// <summary>\n/// The gamemode this controller resides in.\n/// </summary>\n" },
		{ "ModuleRelativePath", "CrewMateController.h" },
		{ "ToolTip", "<summary>\nThe gamemode this controller resides in.\n</summary>" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACrewMateController_Statics::NewProp_gameMode = { "gameMode", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACrewMateController, gameMode), Z_Construct_UClass_AAIDeductionGameMode_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACrewMateController_Statics::NewProp_gameMode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACrewMateController_Statics::NewProp_gameMode_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACrewMateController_Statics::NewProp_startingTransform_MetaData[] = {
		{ "Category", "AI" },
		{ "Comment", "/// <summary>\n/// The initial transform of the crewmate this controller is possessing.\n/// </summary>\n" },
		{ "ModuleRelativePath", "CrewMateController.h" },
		{ "ToolTip", "<summary>\nThe initial transform of the crewmate this controller is possessing.\n</summary>" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ACrewMateController_Statics::NewProp_startingTransform = { "startingTransform", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACrewMateController, startingTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(Z_Construct_UClass_ACrewMateController_Statics::NewProp_startingTransform_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACrewMateController_Statics::NewProp_startingTransform_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACrewMateController_Statics::NewProp_crewmateNPC_MetaData[] = {
		{ "Category", "AI" },
		{ "Comment", "/// <summary>\n/// The crewmate this controller is possessing\n/// </summary>\n" },
		{ "ModuleRelativePath", "CrewMateController.h" },
		{ "ToolTip", "<summary>\nThe crewmate this controller is possessing\n</summary>" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACrewMateController_Statics::NewProp_crewmateNPC = { "crewmateNPC", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACrewMateController, crewmateNPC), Z_Construct_UClass_ACrewMateBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACrewMateController_Statics::NewProp_crewmateNPC_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACrewMateController_Statics::NewProp_crewmateNPC_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACrewMateController_Statics::NewProp_blackboardComp_MetaData[] = {
		{ "Category", "AI" },
		{ "Comment", "/// <summary>\n/// The blackboard component attached to this crewmate.\n/// </summary>\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CrewMateController.h" },
		{ "ToolTip", "<summary>\nThe blackboard component attached to this crewmate.\n</summary>" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACrewMateController_Statics::NewProp_blackboardComp = { "blackboardComp", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACrewMateController, blackboardComp), Z_Construct_UClass_UBlackboardComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACrewMateController_Statics::NewProp_blackboardComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACrewMateController_Statics::NewProp_blackboardComp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACrewMateController_Statics::NewProp_behaviorComp_MetaData[] = {
		{ "Category", "AI" },
		{ "Comment", "/// <summary>\n/// The behavior tree this crewmate is controlled by.\n/// </summary>\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CrewMateController.h" },
		{ "ToolTip", "<summary>\nThe behavior tree this crewmate is controlled by.\n</summary>" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACrewMateController_Statics::NewProp_behaviorComp = { "behaviorComp", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACrewMateController, behaviorComp), Z_Construct_UClass_UBehaviorTreeComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACrewMateController_Statics::NewProp_behaviorComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACrewMateController_Statics::NewProp_behaviorComp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACrewMateController_Statics::NewProp_LocationToGoKey_MetaData[] = {
		{ "Category", "AI" },
		{ "Comment", "/// <summary>\n/// The blackboard key which defines where the AI should be moving to.\n/// </summary>\n" },
		{ "ModuleRelativePath", "CrewMateController.h" },
		{ "ToolTip", "<summary>\nThe blackboard key which defines where the AI should be moving to.\n</summary>" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_ACrewMateController_Statics::NewProp_LocationToGoKey = { "LocationToGoKey", nullptr, (EPropertyFlags)0x0040000000010001, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACrewMateController, LocationToGoKey), METADATA_PARAMS(Z_Construct_UClass_ACrewMateController_Statics::NewProp_LocationToGoKey_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACrewMateController_Statics::NewProp_LocationToGoKey_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACrewMateController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrewMateController_Statics::NewProp_gameMode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrewMateController_Statics::NewProp_startingTransform,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrewMateController_Statics::NewProp_crewmateNPC,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrewMateController_Statics::NewProp_blackboardComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrewMateController_Statics::NewProp_behaviorComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrewMateController_Statics::NewProp_LocationToGoKey,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACrewMateController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACrewMateController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACrewMateController_Statics::ClassParams = {
		&ACrewMateController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ACrewMateController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ACrewMateController_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACrewMateController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACrewMateController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACrewMateController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACrewMateController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACrewMateController, 3461418167);
	template<> AIDEDUCTION_API UClass* StaticClass<ACrewMateController>()
	{
		return ACrewMateController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACrewMateController(Z_Construct_UClass_ACrewMateController, &ACrewMateController::StaticClass, TEXT("/Script/AIDeduction"), TEXT("ACrewMateController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACrewMateController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
