// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FinalProject/Public/BaseCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBaseCharacter() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
FINALPROJECT_API UClass* Z_Construct_UClass_ABaseCharacter();
FINALPROJECT_API UClass* Z_Construct_UClass_ABaseCharacter_NoRegister();
UPackage* Z_Construct_UPackage__Script_FinalProject();
// End Cross Module References

// Begin Class ABaseCharacter
void ABaseCharacter::StaticRegisterNativesABaseCharacter()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABaseCharacter);
UClass* Z_Construct_UClass_ABaseCharacter_NoRegister()
{
	return ABaseCharacter::StaticClass();
}
struct Z_Construct_UClass_ABaseCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "BaseCharacter.h" },
		{ "ModuleRelativePath", "Public/BaseCharacter.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABaseCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABaseCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_FinalProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABaseCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABaseCharacter_Statics::ClassParams = {
	&ABaseCharacter::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABaseCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_ABaseCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABaseCharacter()
{
	if (!Z_Registration_Info_UClass_ABaseCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABaseCharacter.OuterSingleton, Z_Construct_UClass_ABaseCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABaseCharacter.OuterSingleton;
}
template<> FINALPROJECT_API UClass* StaticClass<ABaseCharacter>()
{
	return ABaseCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABaseCharacter);
ABaseCharacter::~ABaseCharacter() {}
// End Class ABaseCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_BaseCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABaseCharacter, ABaseCharacter::StaticClass, TEXT("ABaseCharacter"), &Z_Registration_Info_UClass_ABaseCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABaseCharacter), 755307342U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_BaseCharacter_h_3017028883(TEXT("/Script/FinalProject"),
	Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_BaseCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_BaseCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
