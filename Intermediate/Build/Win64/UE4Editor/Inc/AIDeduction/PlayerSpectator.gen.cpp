// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AIDeduction/PlayerSpectator.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayerSpectator() {}
// Cross Module References
	AIDEDUCTION_API UClass* Z_Construct_UClass_APlayerSpectator_NoRegister();
	AIDEDUCTION_API UClass* Z_Construct_UClass_APlayerSpectator();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_AIDeduction();
// End Cross Module References
	void APlayerSpectator::StaticRegisterNativesAPlayerSpectator()
	{
	}
	UClass* Z_Construct_UClass_APlayerSpectator_NoRegister()
	{
		return APlayerSpectator::StaticClass();
	}
	struct Z_Construct_UClass_APlayerSpectator_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APlayerSpectator_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_AIDeduction,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerSpectator_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n* The pawn the player controls when spectating the simulation.\n*/" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "PlayerSpectator.h" },
		{ "ModuleRelativePath", "PlayerSpectator.h" },
		{ "ToolTip", "The pawn the player controls when spectating the simulation." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APlayerSpectator_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlayerSpectator>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APlayerSpectator_Statics::ClassParams = {
		&APlayerSpectator::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_APlayerSpectator_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APlayerSpectator_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APlayerSpectator()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APlayerSpectator_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APlayerSpectator, 2373065406);
	template<> AIDEDUCTION_API UClass* StaticClass<APlayerSpectator>()
	{
		return APlayerSpectator::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APlayerSpectator(Z_Construct_UClass_APlayerSpectator, &APlayerSpectator::StaticClass, TEXT("/Script/AIDeduction"), TEXT("APlayerSpectator"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APlayerSpectator);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
