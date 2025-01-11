// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FinalProject/Public/TrapCell.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTrapCell() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
FINALPROJECT_API UClass* Z_Construct_UClass_ATrapCell();
FINALPROJECT_API UClass* Z_Construct_UClass_ATrapCell_NoRegister();
UPackage* Z_Construct_UPackage__Script_FinalProject();
// End Cross Module References

// Begin Class ATrapCell
void ATrapCell::StaticRegisterNativesATrapCell()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATrapCell);
UClass* Z_Construct_UClass_ATrapCell_NoRegister()
{
	return ATrapCell::StaticClass();
}
struct Z_Construct_UClass_ATrapCell_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "TrapCell.h" },
		{ "ModuleRelativePath", "Public/TrapCell.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATrapCell>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ATrapCell_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_FinalProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATrapCell_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATrapCell_Statics::ClassParams = {
	&ATrapCell::StaticClass,
	"Engine",
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATrapCell_Statics::Class_MetaDataParams), Z_Construct_UClass_ATrapCell_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATrapCell()
{
	if (!Z_Registration_Info_UClass_ATrapCell.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATrapCell.OuterSingleton, Z_Construct_UClass_ATrapCell_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATrapCell.OuterSingleton;
}
template<> FINALPROJECT_API UClass* StaticClass<ATrapCell>()
{
	return ATrapCell::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATrapCell);
ATrapCell::~ATrapCell() {}
// End Class ATrapCell

// Begin Registration
struct Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_TrapCell_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATrapCell, ATrapCell::StaticClass, TEXT("ATrapCell"), &Z_Registration_Info_UClass_ATrapCell, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATrapCell), 863962346U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_TrapCell_h_2996108291(TEXT("/Script/FinalProject"),
	Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_TrapCell_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_TrapCell_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
