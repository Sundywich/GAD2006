// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FinalProject/Public/HealingCollectible.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHealingCollectible() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
FINALPROJECT_API UClass* Z_Construct_UClass_AHealingCollectible();
FINALPROJECT_API UClass* Z_Construct_UClass_AHealingCollectible_NoRegister();
UPackage* Z_Construct_UPackage__Script_FinalProject();
// End Cross Module References

// Begin Class AHealingCollectible Function MulticastDestroy
static FName NAME_AHealingCollectible_MulticastDestroy = FName(TEXT("MulticastDestroy"));
void AHealingCollectible::MulticastDestroy()
{
	ProcessEvent(FindFunctionChecked(NAME_AHealingCollectible_MulticastDestroy),NULL);
}
struct Z_Construct_UFunction_AHealingCollectible_MulticastDestroy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/HealingCollectible.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AHealingCollectible_MulticastDestroy_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHealingCollectible, nullptr, "MulticastDestroy", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00024CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AHealingCollectible_MulticastDestroy_Statics::Function_MetaDataParams), Z_Construct_UFunction_AHealingCollectible_MulticastDestroy_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AHealingCollectible_MulticastDestroy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AHealingCollectible_MulticastDestroy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AHealingCollectible::execMulticastDestroy)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->MulticastDestroy_Implementation();
	P_NATIVE_END;
}
// End Class AHealingCollectible Function MulticastDestroy

// Begin Class AHealingCollectible
void AHealingCollectible::StaticRegisterNativesAHealingCollectible()
{
	UClass* Class = AHealingCollectible::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "MulticastDestroy", &AHealingCollectible::execMulticastDestroy },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AHealingCollectible);
UClass* Z_Construct_UClass_AHealingCollectible_NoRegister()
{
	return AHealingCollectible::StaticClass();
}
struct Z_Construct_UClass_AHealingCollectible_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "HealingCollectible.h" },
		{ "ModuleRelativePath", "Public/HealingCollectible.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealingAmount_MetaData[] = {
		{ "Category", "HealingCollectible" },
		{ "ModuleRelativePath", "Public/HealingCollectible.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealMesh_MetaData[] = {
		{ "Category", "HealingCollectible" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HealingCollectible.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_HealingAmount;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HealMesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AHealingCollectible_MulticastDestroy, "MulticastDestroy" }, // 763109265
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHealingCollectible>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AHealingCollectible_Statics::NewProp_HealingAmount = { "HealingAmount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHealingCollectible, HealingAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealingAmount_MetaData), NewProp_HealingAmount_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHealingCollectible_Statics::NewProp_HealMesh = { "HealMesh", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHealingCollectible, HealMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealMesh_MetaData), NewProp_HealMesh_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHealingCollectible_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHealingCollectible_Statics::NewProp_HealingAmount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHealingCollectible_Statics::NewProp_HealMesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHealingCollectible_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AHealingCollectible_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_FinalProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHealingCollectible_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AHealingCollectible_Statics::ClassParams = {
	&AHealingCollectible::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AHealingCollectible_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AHealingCollectible_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHealingCollectible_Statics::Class_MetaDataParams), Z_Construct_UClass_AHealingCollectible_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AHealingCollectible()
{
	if (!Z_Registration_Info_UClass_AHealingCollectible.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AHealingCollectible.OuterSingleton, Z_Construct_UClass_AHealingCollectible_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AHealingCollectible.OuterSingleton;
}
template<> FINALPROJECT_API UClass* StaticClass<AHealingCollectible>()
{
	return AHealingCollectible::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AHealingCollectible);
AHealingCollectible::~AHealingCollectible() {}
// End Class AHealingCollectible

// Begin Registration
struct Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_HealingCollectible_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AHealingCollectible, AHealingCollectible::StaticClass, TEXT("AHealingCollectible"), &Z_Registration_Info_UClass_AHealingCollectible, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AHealingCollectible), 257018328U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_HealingCollectible_h_4202436847(TEXT("/Script/FinalProject"),
	Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_HealingCollectible_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_HealingCollectible_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
