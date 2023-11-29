// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TrajectoryAO/TrajectoryAOGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTrajectoryAOGameMode() {}
// Cross Module References
	TRAJECTORYAO_API UClass* Z_Construct_UClass_ATrajectoryAOGameMode_NoRegister();
	TRAJECTORYAO_API UClass* Z_Construct_UClass_ATrajectoryAOGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_TrajectoryAO();
// End Cross Module References
	void ATrajectoryAOGameMode::StaticRegisterNativesATrajectoryAOGameMode()
	{
	}
	UClass* Z_Construct_UClass_ATrajectoryAOGameMode_NoRegister()
	{
		return ATrajectoryAOGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ATrajectoryAOGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATrajectoryAOGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_TrajectoryAO,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrajectoryAOGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "TrajectoryAOGameMode.h" },
		{ "ModuleRelativePath", "TrajectoryAOGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATrajectoryAOGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATrajectoryAOGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATrajectoryAOGameMode_Statics::ClassParams = {
		&ATrajectoryAOGameMode::StaticClass,
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
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ATrajectoryAOGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATrajectoryAOGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATrajectoryAOGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATrajectoryAOGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATrajectoryAOGameMode, 1263401062);
	template<> TRAJECTORYAO_API UClass* StaticClass<ATrajectoryAOGameMode>()
	{
		return ATrajectoryAOGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATrajectoryAOGameMode(Z_Construct_UClass_ATrajectoryAOGameMode, &ATrajectoryAOGameMode::StaticClass, TEXT("/Script/TrajectoryAO"), TEXT("ATrajectoryAOGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATrajectoryAOGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
