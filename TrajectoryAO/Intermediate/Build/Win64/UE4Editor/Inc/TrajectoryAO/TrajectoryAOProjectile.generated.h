// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef TRAJECTORYAO_TrajectoryAOProjectile_generated_h
#error "TrajectoryAOProjectile.generated.h already included, missing '#pragma once' in TrajectoryAOProjectile.h"
#endif
#define TRAJECTORYAO_TrajectoryAOProjectile_generated_h

#define TrajectoryAO_Source_TrajectoryAO_TrajectoryAOProjectile_h_16_SPARSE_DATA
#define TrajectoryAO_Source_TrajectoryAO_TrajectoryAOProjectile_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define TrajectoryAO_Source_TrajectoryAO_TrajectoryAOProjectile_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define TrajectoryAO_Source_TrajectoryAO_TrajectoryAOProjectile_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATrajectoryAOProjectile(); \
	friend struct Z_Construct_UClass_ATrajectoryAOProjectile_Statics; \
public: \
	DECLARE_CLASS(ATrajectoryAOProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TrajectoryAO"), NO_API) \
	DECLARE_SERIALIZER(ATrajectoryAOProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define TrajectoryAO_Source_TrajectoryAO_TrajectoryAOProjectile_h_16_INCLASS \
private: \
	static void StaticRegisterNativesATrajectoryAOProjectile(); \
	friend struct Z_Construct_UClass_ATrajectoryAOProjectile_Statics; \
public: \
	DECLARE_CLASS(ATrajectoryAOProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TrajectoryAO"), NO_API) \
	DECLARE_SERIALIZER(ATrajectoryAOProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define TrajectoryAO_Source_TrajectoryAO_TrajectoryAOProjectile_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATrajectoryAOProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATrajectoryAOProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATrajectoryAOProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATrajectoryAOProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATrajectoryAOProjectile(ATrajectoryAOProjectile&&); \
	NO_API ATrajectoryAOProjectile(const ATrajectoryAOProjectile&); \
public:


#define TrajectoryAO_Source_TrajectoryAO_TrajectoryAOProjectile_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATrajectoryAOProjectile(ATrajectoryAOProjectile&&); \
	NO_API ATrajectoryAOProjectile(const ATrajectoryAOProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATrajectoryAOProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATrajectoryAOProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATrajectoryAOProjectile)


#define TrajectoryAO_Source_TrajectoryAO_TrajectoryAOProjectile_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComp() { return STRUCT_OFFSET(ATrajectoryAOProjectile, CollisionComp); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(ATrajectoryAOProjectile, ProjectileMovement); }


#define TrajectoryAO_Source_TrajectoryAO_TrajectoryAOProjectile_h_13_PROLOG
#define TrajectoryAO_Source_TrajectoryAO_TrajectoryAOProjectile_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TrajectoryAO_Source_TrajectoryAO_TrajectoryAOProjectile_h_16_PRIVATE_PROPERTY_OFFSET \
	TrajectoryAO_Source_TrajectoryAO_TrajectoryAOProjectile_h_16_SPARSE_DATA \
	TrajectoryAO_Source_TrajectoryAO_TrajectoryAOProjectile_h_16_RPC_WRAPPERS \
	TrajectoryAO_Source_TrajectoryAO_TrajectoryAOProjectile_h_16_INCLASS \
	TrajectoryAO_Source_TrajectoryAO_TrajectoryAOProjectile_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TrajectoryAO_Source_TrajectoryAO_TrajectoryAOProjectile_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TrajectoryAO_Source_TrajectoryAO_TrajectoryAOProjectile_h_16_PRIVATE_PROPERTY_OFFSET \
	TrajectoryAO_Source_TrajectoryAO_TrajectoryAOProjectile_h_16_SPARSE_DATA \
	TrajectoryAO_Source_TrajectoryAO_TrajectoryAOProjectile_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	TrajectoryAO_Source_TrajectoryAO_TrajectoryAOProjectile_h_16_INCLASS_NO_PURE_DECLS \
	TrajectoryAO_Source_TrajectoryAO_TrajectoryAOProjectile_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TRAJECTORYAO_API UClass* StaticClass<class ATrajectoryAOProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TrajectoryAO_Source_TrajectoryAO_TrajectoryAOProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
