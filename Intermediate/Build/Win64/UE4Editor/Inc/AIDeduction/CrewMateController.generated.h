// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef AIDEDUCTION_CrewMateController_generated_h
#error "CrewMateController.generated.h already included, missing '#pragma once' in CrewMateController.h"
#endif
#define AIDEDUCTION_CrewMateController_generated_h

#define AIDeduction_Source_AIDeduction_CrewMateController_h_15_SPARSE_DATA
#define AIDeduction_Source_AIDeduction_CrewMateController_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execResetAI); \
	DECLARE_FUNCTION(execStartAI);


#define AIDeduction_Source_AIDeduction_CrewMateController_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execResetAI); \
	DECLARE_FUNCTION(execStartAI);


#define AIDeduction_Source_AIDeduction_CrewMateController_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACrewMateController(); \
	friend struct Z_Construct_UClass_ACrewMateController_Statics; \
public: \
	DECLARE_CLASS(ACrewMateController, AAIController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AIDeduction"), NO_API) \
	DECLARE_SERIALIZER(ACrewMateController)


#define AIDeduction_Source_AIDeduction_CrewMateController_h_15_INCLASS \
private: \
	static void StaticRegisterNativesACrewMateController(); \
	friend struct Z_Construct_UClass_ACrewMateController_Statics; \
public: \
	DECLARE_CLASS(ACrewMateController, AAIController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AIDeduction"), NO_API) \
	DECLARE_SERIALIZER(ACrewMateController)


#define AIDeduction_Source_AIDeduction_CrewMateController_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACrewMateController(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACrewMateController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACrewMateController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACrewMateController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACrewMateController(ACrewMateController&&); \
	NO_API ACrewMateController(const ACrewMateController&); \
public:


#define AIDeduction_Source_AIDeduction_CrewMateController_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACrewMateController(ACrewMateController&&); \
	NO_API ACrewMateController(const ACrewMateController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACrewMateController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACrewMateController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACrewMateController)


#define AIDeduction_Source_AIDeduction_CrewMateController_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__LocationToGoKey() { return STRUCT_OFFSET(ACrewMateController, LocationToGoKey); }


#define AIDeduction_Source_AIDeduction_CrewMateController_h_12_PROLOG
#define AIDeduction_Source_AIDeduction_CrewMateController_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AIDeduction_Source_AIDeduction_CrewMateController_h_15_PRIVATE_PROPERTY_OFFSET \
	AIDeduction_Source_AIDeduction_CrewMateController_h_15_SPARSE_DATA \
	AIDeduction_Source_AIDeduction_CrewMateController_h_15_RPC_WRAPPERS \
	AIDeduction_Source_AIDeduction_CrewMateController_h_15_INCLASS \
	AIDeduction_Source_AIDeduction_CrewMateController_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AIDeduction_Source_AIDeduction_CrewMateController_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AIDeduction_Source_AIDeduction_CrewMateController_h_15_PRIVATE_PROPERTY_OFFSET \
	AIDeduction_Source_AIDeduction_CrewMateController_h_15_SPARSE_DATA \
	AIDeduction_Source_AIDeduction_CrewMateController_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	AIDeduction_Source_AIDeduction_CrewMateController_h_15_INCLASS_NO_PURE_DECLS \
	AIDeduction_Source_AIDeduction_CrewMateController_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> AIDEDUCTION_API UClass* StaticClass<class ACrewMateController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AIDeduction_Source_AIDeduction_CrewMateController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
