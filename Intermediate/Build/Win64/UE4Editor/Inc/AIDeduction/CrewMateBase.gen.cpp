// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AIDeduction/CrewMateBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCrewMateBase() {}
// Cross Module References
	AIDEDUCTION_API UClass* Z_Construct_UClass_ACrewMateBase_NoRegister();
	AIDEDUCTION_API UClass* Z_Construct_UClass_ACrewMateBase();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_AIDeduction();
	AIDEDUCTION_API UClass* Z_Construct_UClass_AAIDeductionGameMode_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UAIPerceptionComponent_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
// End Cross Module References
	void ACrewMateBase::StaticRegisterNativesACrewMateBase()
	{
	}
	UClass* Z_Construct_UClass_ACrewMateBase_NoRegister()
	{
		return ACrewMateBase::StaticClass();
	}
	struct Z_Construct_UClass_ACrewMateBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_aiDeductionGameMode_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_aiDeductionGameMode;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_perceptionComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_perceptionComp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_behaviorTree_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_behaviorTree;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACrewMateBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_AIDeduction,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACrewMateBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * The class for the AI which will be playing out a game of \"Among AI\" for the simulation\n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "CrewMateBase.h" },
		{ "ModuleRelativePath", "CrewMateBase.h" },
		{ "ToolTip", "The class for the AI which will be playing out a game of \"Among AI\" for the simulation" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACrewMateBase_Statics::NewProp_aiDeductionGameMode_MetaData[] = {
		{ "Category", "References" },
		{ "Comment", "/// <summary>\n/// The game mode this crewmate resides in\n/// </summary>\n" },
		{ "ModuleRelativePath", "CrewMateBase.h" },
		{ "ToolTip", "<summary>\nThe game mode this crewmate resides in\n</summary>" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACrewMateBase_Statics::NewProp_aiDeductionGameMode = { "aiDeductionGameMode", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACrewMateBase, aiDeductionGameMode), Z_Construct_UClass_AAIDeductionGameMode_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACrewMateBase_Statics::NewProp_aiDeductionGameMode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACrewMateBase_Statics::NewProp_aiDeductionGameMode_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACrewMateBase_Statics::NewProp_perceptionComp_MetaData[] = {
		{ "Category", "AI" },
		{ "Comment", "/// <summary>\n/// The component which will handle the sight sense for the crewmates\n/// </summary>\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CrewMateBase.h" },
		{ "ToolTip", "<summary>\nThe component which will handle the sight sense for the crewmates\n</summary>" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACrewMateBase_Statics::NewProp_perceptionComp = { "perceptionComp", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACrewMateBase, perceptionComp), Z_Construct_UClass_UAIPerceptionComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACrewMateBase_Statics::NewProp_perceptionComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACrewMateBase_Statics::NewProp_perceptionComp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACrewMateBase_Statics::NewProp_behaviorTree_MetaData[] = {
		{ "Category", "AI" },
		{ "Comment", "/// <summary>\n/// The behavior tree controlling the crewmates' actions\n/// </summary>\n" },
		{ "ModuleRelativePath", "CrewMateBase.h" },
		{ "ToolTip", "<summary>\nThe behavior tree controlling the crewmates' actions\n</summary>" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACrewMateBase_Statics::NewProp_behaviorTree = { "behaviorTree", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACrewMateBase, behaviorTree), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACrewMateBase_Statics::NewProp_behaviorTree_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACrewMateBase_Statics::NewProp_behaviorTree_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACrewMateBase_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrewMateBase_Statics::NewProp_aiDeductionGameMode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrewMateBase_Statics::NewProp_perceptionComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACrewMateBase_Statics::NewProp_behaviorTree,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACrewMateBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACrewMateBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACrewMateBase_Statics::ClassParams = {
		&ACrewMateBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ACrewMateBase_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ACrewMateBase_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACrewMateBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACrewMateBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACrewMateBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACrewMateBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACrewMateBase, 305039295);
	template<> AIDEDUCTION_API UClass* StaticClass<ACrewMateBase>()
	{
		return ACrewMateBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACrewMateBase(Z_Construct_UClass_ACrewMateBase, &ACrewMateBase::StaticClass, TEXT("/Script/AIDeduction"), TEXT("ACrewMateBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACrewMateBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
