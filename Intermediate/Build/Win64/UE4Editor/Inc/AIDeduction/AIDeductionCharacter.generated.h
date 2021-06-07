// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef AIDEDUCTION_AIDeductionCharacter_generated_h
#error "AIDeductionCharacter.generated.h already included, missing '#pragma once' in AIDeductionCharacter.h"
#endif
#define AIDEDUCTION_AIDeductionCharacter_generated_h

#define AIDeduction_Source_AIDeduction_AIDeductionCharacter_h_12_SPARSE_DATA
#define AIDeduction_Source_AIDeduction_AIDeductionCharacter_h_12_RPC_WRAPPERS
#define AIDeduction_Source_AIDeduction_AIDeductionCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define AIDeduction_Source_AIDeduction_AIDeductionCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAAIDeductionCharacter(); \
	friend struct Z_Construct_UClass_AAIDeductionCharacter_Statics; \
public: \
	DECLARE_CLASS(AAIDeductionCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AIDeduction"), NO_API) \
	DECLARE_SERIALIZER(AAIDeductionCharacter)


#define AIDeduction_Source_AIDeduction_AIDeductionCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAAIDeductionCharacter(); \
	friend struct Z_Construct_UClass_AAIDeductionCharacter_Statics; \
public: \
	DECLARE_CLASS(AAIDeductionCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AIDeduction"), NO_API) \
	DECLARE_SERIALIZER(AAIDeductionCharacter)


#define AIDeduction_Source_AIDeduction_AIDeductionCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AAIDeductionCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AAIDeductionCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAIDeductionCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAIDeductionCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAIDeductionCharacter(AAIDeductionCharacter&&); \
	NO_API AAIDeductionCharacter(const AAIDeductionCharacter&); \
public:


#define AIDeduction_Source_AIDeduction_AIDeductionCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAIDeductionCharacter(AAIDeductionCharacter&&); \
	NO_API AAIDeductionCharacter(const AAIDeductionCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAIDeductionCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAIDeductionCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AAIDeductionCharacter)


#define AIDeduction_Source_AIDeduction_AIDeductionCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AAIDeductionCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(AAIDeductionCharacter, FollowCamera); }


#define AIDeduction_Source_AIDeduction_AIDeductionCharacter_h_9_PROLOG
#define AIDeduction_Source_AIDeduction_AIDeductionCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AIDeduction_Source_AIDeduction_AIDeductionCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	AIDeduction_Source_AIDeduction_AIDeductionCharacter_h_12_SPARSE_DATA \
	AIDeduction_Source_AIDeduction_AIDeductionCharacter_h_12_RPC_WRAPPERS \
	AIDeduction_Source_AIDeduction_AIDeductionCharacter_h_12_INCLASS \
	AIDeduction_Source_AIDeduction_AIDeductionCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AIDeduction_Source_AIDeduction_AIDeductionCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AIDeduction_Source_AIDeduction_AIDeductionCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	AIDeduction_Source_AIDeduction_AIDeductionCharacter_h_12_SPARSE_DATA \
	AIDeduction_Source_AIDeduction_AIDeductionCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	AIDeduction_Source_AIDeduction_AIDeductionCharacter_h_12_INCLASS_NO_PURE_DECLS \
	AIDeduction_Source_AIDeduction_AIDeductionCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> AIDEDUCTION_API UClass* StaticClass<class AAIDeductionCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AIDeduction_Source_AIDeduction_AIDeductionCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
