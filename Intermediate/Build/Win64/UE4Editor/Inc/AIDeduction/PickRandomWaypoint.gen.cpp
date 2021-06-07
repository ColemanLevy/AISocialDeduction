// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AIDeduction/PickRandomWaypoint.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePickRandomWaypoint() {}
// Cross Module References
	AIDEDUCTION_API UClass* Z_Construct_UClass_UPickRandomWaypoint_NoRegister();
	AIDEDUCTION_API UClass* Z_Construct_UClass_UPickRandomWaypoint();
	AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
	UPackage* Z_Construct_UPackage__Script_AIDeduction();
// End Cross Module References
	void UPickRandomWaypoint::StaticRegisterNativesUPickRandomWaypoint()
	{
	}
	UClass* Z_Construct_UClass_UPickRandomWaypoint_NoRegister()
	{
		return UPickRandomWaypoint::StaticClass();
	}
	struct Z_Construct_UClass_UPickRandomWaypoint_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPickRandomWaypoint_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
		(UObject* (*)())Z_Construct_UPackage__Script_AIDeduction,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPickRandomWaypoint_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Node for the crewmate's behavior tree which gets the crewmate a random waypoint to move to.\n */" },
		{ "IncludePath", "PickRandomWaypoint.h" },
		{ "ModuleRelativePath", "PickRandomWaypoint.h" },
		{ "ToolTip", "Node for the crewmate's behavior tree which gets the crewmate a random waypoint to move to." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPickRandomWaypoint_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPickRandomWaypoint>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPickRandomWaypoint_Statics::ClassParams = {
		&UPickRandomWaypoint::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UPickRandomWaypoint_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPickRandomWaypoint_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPickRandomWaypoint()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPickRandomWaypoint_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPickRandomWaypoint, 3826220451);
	template<> AIDEDUCTION_API UClass* StaticClass<UPickRandomWaypoint>()
	{
		return UPickRandomWaypoint::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPickRandomWaypoint(Z_Construct_UClass_UPickRandomWaypoint, &UPickRandomWaypoint::StaticClass, TEXT("/Script/AIDeduction"), TEXT("UPickRandomWaypoint"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPickRandomWaypoint);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
