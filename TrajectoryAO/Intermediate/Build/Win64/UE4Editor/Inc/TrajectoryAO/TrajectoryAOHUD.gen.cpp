// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TrajectoryAO/TrajectoryAOHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTrajectoryAOHUD() {}
// Cross Module References
	TRAJECTORYAO_API UClass* Z_Construct_UClass_ATrajectoryAOHUD_NoRegister();
	TRAJECTORYAO_API UClass* Z_Construct_UClass_ATrajectoryAOHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_TrajectoryAO();
// End Cross Module References
	void ATrajectoryAOHUD::StaticRegisterNativesATrajectoryAOHUD()
	{
	}
	UClass* Z_Construct_UClass_ATrajectoryAOHUD_NoRegister()
	{
		return ATrajectoryAOHUD::StaticClass();
	}
	struct Z_Construct_UClass_ATrajectoryAOHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATrajectoryAOHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_TrajectoryAO,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrajectoryAOHUD_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "TrajectoryAOHUD.h" },
		{ "ModuleRelativePath", "TrajectoryAOHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATrajectoryAOHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATrajectoryAOHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATrajectoryAOHUD_Statics::ClassParams = {
		&ATrajectoryAOHUD::StaticClass,
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
		0x008002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ATrajectoryAOHUD_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATrajectoryAOHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATrajectoryAOHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATrajectoryAOHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATrajectoryAOHUD, 2354433704);
	template<> TRAJECTORYAO_API UClass* StaticClass<ATrajectoryAOHUD>()
	{
		return ATrajectoryAOHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATrajectoryAOHUD(Z_Construct_UClass_ATrajectoryAOHUD, &ATrajectoryAOHUD::StaticClass, TEXT("/Script/TrajectoryAO"), TEXT("ATrajectoryAOHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATrajectoryAOHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
