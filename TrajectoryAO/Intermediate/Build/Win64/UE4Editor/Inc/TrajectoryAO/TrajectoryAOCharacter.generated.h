// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TRAJECTORYAO_TrajectoryAOCharacter_generated_h
#error "TrajectoryAOCharacter.generated.h already included, missing '#pragma once' in TrajectoryAOCharacter.h"
#endif
#define TRAJECTORYAO_TrajectoryAOCharacter_generated_h

#define TrajectoryAO_Source_TrajectoryAO_TrajectoryAOCharacter_h_20_SPARSE_DATA
#define TrajectoryAO_Source_TrajectoryAO_TrajectoryAOCharacter_h_20_RPC_WRAPPERS
#define TrajectoryAO_Source_TrajectoryAO_TrajectoryAOCharacter_h_20_RPC_WRAPPERS_NO_PURE_DECLS
#define TrajectoryAO_Source_TrajectoryAO_TrajectoryAOCharacter_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATrajectoryAOCharacter(); \
	friend struct Z_Construct_UClass_ATrajectoryAOCharacter_Statics; \
public: \
	DECLARE_CLASS(ATrajectoryAOCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TrajectoryAO"), NO_API) \
	DECLARE_SERIALIZER(ATrajectoryAOCharacter)


#define TrajectoryAO_Source_TrajectoryAO_TrajectoryAOCharacter_h_20_INCLASS \
private: \
	static void StaticRegisterNativesATrajectoryAOCharacter(); \
	friend struct Z_Construct_UClass_ATrajectoryAOCharacter_Statics; \
public: \
	DECLARE_CLASS(ATrajectoryAOCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TrajectoryAO"), NO_API) \
	DECLARE_SERIALIZER(ATrajectoryAOCharacter)


#define TrajectoryAO_Source_TrajectoryAO_TrajectoryAOCharacter_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATrajectoryAOCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATrajectoryAOCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATrajectoryAOCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATrajectoryAOCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATrajectoryAOCharacter(ATrajectoryAOCharacter&&); \
	NO_API ATrajectoryAOCharacter(const ATrajectoryAOCharacter&); \
public:


#define TrajectoryAO_Source_TrajectoryAO_TrajectoryAOCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATrajectoryAOCharacter(ATrajectoryAOCharacter&&); \
	NO_API ATrajectoryAOCharacter(const ATrajectoryAOCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATrajectoryAOCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATrajectoryAOCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATrajectoryAOCharacter)


#define TrajectoryAO_Source_TrajectoryAO_TrajectoryAOCharacter_h_20_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh1P() { return STRUCT_OFFSET(ATrajectoryAOCharacter, Mesh1P); } \
	FORCEINLINE static uint32 __PPO__FP_Gun() { return STRUCT_OFFSET(ATrajectoryAOCharacter, FP_Gun); } \
	FORCEINLINE static uint32 __PPO__FP_MuzzleLocation() { return STRUCT_OFFSET(ATrajectoryAOCharacter, FP_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__VR_Gun() { return STRUCT_OFFSET(ATrajectoryAOCharacter, VR_Gun); } \
	FORCEINLINE static uint32 __PPO__VR_MuzzleLocation() { return STRUCT_OFFSET(ATrajectoryAOCharacter, VR_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__FirstPersonCameraComponent() { return STRUCT_OFFSET(ATrajectoryAOCharacter, FirstPersonCameraComponent); } \
	FORCEINLINE static uint32 __PPO__R_MotionController() { return STRUCT_OFFSET(ATrajectoryAOCharacter, R_MotionController); } \
	FORCEINLINE static uint32 __PPO__L_MotionController() { return STRUCT_OFFSET(ATrajectoryAOCharacter, L_MotionController); }


#define TrajectoryAO_Source_TrajectoryAO_TrajectoryAOCharacter_h_17_PROLOG
#define TrajectoryAO_Source_TrajectoryAO_TrajectoryAOCharacter_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TrajectoryAO_Source_TrajectoryAO_TrajectoryAOCharacter_h_20_PRIVATE_PROPERTY_OFFSET \
	TrajectoryAO_Source_TrajectoryAO_TrajectoryAOCharacter_h_20_SPARSE_DATA \
	TrajectoryAO_Source_TrajectoryAO_TrajectoryAOCharacter_h_20_RPC_WRAPPERS \
	TrajectoryAO_Source_TrajectoryAO_TrajectoryAOCharacter_h_20_INCLASS \
	TrajectoryAO_Source_TrajectoryAO_TrajectoryAOCharacter_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TrajectoryAO_Source_TrajectoryAO_TrajectoryAOCharacter_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TrajectoryAO_Source_TrajectoryAO_TrajectoryAOCharacter_h_20_PRIVATE_PROPERTY_OFFSET \
	TrajectoryAO_Source_TrajectoryAO_TrajectoryAOCharacter_h_20_SPARSE_DATA \
	TrajectoryAO_Source_TrajectoryAO_TrajectoryAOCharacter_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	TrajectoryAO_Source_TrajectoryAO_TrajectoryAOCharacter_h_20_INCLASS_NO_PURE_DECLS \
	TrajectoryAO_Source_TrajectoryAO_TrajectoryAOCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TRAJECTORYAO_API UClass* StaticClass<class ATrajectoryAOCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TrajectoryAO_Source_TrajectoryAO_TrajectoryAOCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
