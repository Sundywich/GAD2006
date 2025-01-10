// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FinalProject/Public/FinalBaseGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFinalBaseGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
FINALPROJECT_API UClass* Z_Construct_UClass_AFinalBaseGameMode();
FINALPROJECT_API UClass* Z_Construct_UClass_AFinalBaseGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_FinalProject();
// End Cross Module References

// Begin Class AFinalBaseGameMode
void AFinalBaseGameMode::StaticRegisterNativesAFinalBaseGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFinalBaseGameMode);
UClass* Z_Construct_UClass_AFinalBaseGameMode_NoRegister()
{
	return AFinalBaseGameMode::StaticClass();
}
struct Z_Construct_UClass_AFinalBaseGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "FinalBaseGameMode.h" },
		{ "ModuleRelativePath", "Public/FinalBaseGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFinalBaseGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AFinalBaseGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_FinalProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFinalBaseGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AFinalBaseGameMode_Statics::ClassParams = {
	&AFinalBaseGameMode::StaticClass,
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
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFinalBaseGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AFinalBaseGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AFinalBaseGameMode()
{
	if (!Z_Registration_Info_UClass_AFinalBaseGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFinalBaseGameMode.OuterSingleton, Z_Construct_UClass_AFinalBaseGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AFinalBaseGameMode.OuterSingleton;
}
template<> FINALPROJECT_API UClass* StaticClass<AFinalBaseGameMode>()
{
	return AFinalBaseGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AFinalBaseGameMode);
AFinalBaseGameMode::~AFinalBaseGameMode() {}
// End Class AFinalBaseGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalBaseGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFinalBaseGameMode, AFinalBaseGameMode::StaticClass, TEXT("AFinalBaseGameMode"), &Z_Registration_Info_UClass_AFinalBaseGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFinalBaseGameMode), 2843459904U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalBaseGameMode_h_268415989(TEXT("/Script/FinalProject"),
	Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalBaseGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalBaseGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
