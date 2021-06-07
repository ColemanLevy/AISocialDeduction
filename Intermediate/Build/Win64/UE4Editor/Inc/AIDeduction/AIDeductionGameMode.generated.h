// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APlayerSpectator;
#ifdef AIDEDUCTION_AIDeductionGameMode_generated_h
#error "AIDeductionGameMode.generated.h already included, missing '#pragma once' in AIDeductionGameMode.h"
#endif
#define AIDEDUCTION_AIDeductionGameMode_generated_h

#define AIDeduction_Source_AIDeduction_AIDeductionGameMode_h_17_SPARSE_DATA
#define AIDeduction_Source_AIDeduction_AIDeductionGameMode_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetPlayerSpectator); \
	DECLARE_FUNCTION(execResetGame); \
	DECLARE_FUNCTION(execStartGame);


#define AIDeduction_Source_AIDeduction_AIDeductionGameMode_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetPlayerSpectator); \
	DECLARE_FUNCTION(execResetGame); \
	DECLARE_FUNCTION(execStartGame);


#define AIDeduction_Source_AIDeduction_AIDeductionGameMode_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAAIDeductionGameMode(); \
	friend struct Z_Construct_UClass_AAIDeductionGameMode_Statics; \
public: \
	DECLARE_CLASS(AAIDeductionGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/AIDeduction"), AIDEDUCTION_API) \
	DECLARE_SERIALIZER(AAIDeductionGameMode)


#define AIDeduction_Source_AIDeduction_AIDeductionGameMode_h_17_INCLASS \
private: \
	static void StaticRegisterNativesAAIDeductionGameMode(); \
	friend struct Z_Construct_UClass_AAIDeductionGameMode_Statics; \
public: \
	DECLARE_CLASS(AAIDeductionGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/AIDeduction"), AIDEDUCTION_API) \
	DECLARE_SERIALIZER(AAIDeductionGameMode)


#define AIDeduction_Source_AIDeduction_AIDeductionGameMode_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	AIDEDUCTION_API AAIDeductionGameMode(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AAIDeductionGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(AIDEDUCTION_API, AAIDeductionGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAIDeductionGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AIDEDUCTION_API AAIDeductionGameMode(AAIDeductionGameMode&&); \
	AIDEDUCTION_API AAIDeductionGameMode(const AAIDeductionGameMode&); \
public:


#define AIDeduction_Source_AIDeduction_AIDeductionGameMode_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AIDEDUCTION_API AAIDeductionGameMode(AAIDeductionGameMode&&); \
	AIDEDUCTION_API AAIDeductionGameMode(const AAIDeductionGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(AIDEDUCTION_API, AAIDeductionGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAIDeductionGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AAIDeductionGameMode)


#define AIDeduction_Source_AIDeduction_AIDeductionGameMode_h_17_PRIVATE_PROPERTY_OFFSET
#define AIDeduction_Source_AIDeduction_AIDeductionGameMode_h_14_PROLOG
#define AIDeduction_Source_AIDeduction_AIDeductionGameMode_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AIDeduction_Source_AIDeduction_AIDeductionGameMode_h_17_PRIVATE_PROPERTY_OFFSET \
	AIDeduction_Source_AIDeduction_AIDeductionGameMode_h_17_SPARSE_DATA \
	AIDeduction_Source_AIDeduction_AIDeductionGameMode_h_17_RPC_WRAPPERS \
	AIDeduction_Source_AIDeduction_AIDeductionGameMode_h_17_INCLASS \
	AIDeduction_Source_AIDeduction_AIDeductionGameMode_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AIDeduction_Source_AIDeduction_AIDeductionGameMode_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AIDeduction_Source_AIDeduction_AIDeductionGameMode_h_17_PRIVATE_PROPERTY_OFFSET \
	AIDeduction_Source_AIDeduction_AIDeductionGameMode_h_17_SPARSE_DATA \
	AIDeduction_Source_AIDeduction_AIDeductionGameMode_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	AIDeduction_Source_AIDeduction_AIDeductionGameMode_h_17_INCLASS_NO_PURE_DECLS \
	AIDeduction_Source_AIDeduction_AIDeductionGameMode_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> AIDEDUCTION_API UClass* StaticClass<class AAIDeductionGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AIDeduction_Source_AIDeduction_AIDeductionGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
