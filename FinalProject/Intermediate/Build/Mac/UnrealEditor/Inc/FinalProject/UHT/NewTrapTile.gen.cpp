// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FinalProject/Public/NewTrapTile.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNewTrapTile() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
FINALPROJECT_API UClass* Z_Construct_UClass_ANewTrapTile();
FINALPROJECT_API UClass* Z_Construct_UClass_ANewTrapTile_NoRegister();
UPackage* Z_Construct_UPackage__Script_FinalProject();
// End Cross Module References

// Begin Class ANewTrapTile Function Multicast_ActivateTrap
static FName NAME_ANewTrapTile_Multicast_ActivateTrap = FName(TEXT("Multicast_ActivateTrap"));
void ANewTrapTile::Multicast_ActivateTrap()
{
	ProcessEvent(FindFunctionChecked(NAME_ANewTrapTile_Multicast_ActivateTrap),NULL);
}
struct Z_Construct_UFunction_ANewTrapTile_Multicast_ActivateTrap_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/NewTrapTile.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewTrapTile_Multicast_ActivateTrap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewTrapTile, nullptr, "Multicast_ActivateTrap", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00024CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewTrapTile_Multicast_ActivateTrap_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewTrapTile_Multicast_ActivateTrap_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ANewTrapTile_Multicast_ActivateTrap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewTrapTile_Multicast_ActivateTrap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANewTrapTile::execMulticast_ActivateTrap)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Multicast_ActivateTrap_Implementation();
	P_NATIVE_END;
}
// End Class ANewTrapTile Function Multicast_ActivateTrap

// Begin Class ANewTrapTile Function Server_ActivateTrap
static FName NAME_ANewTrapTile_Server_ActivateTrap = FName(TEXT("Server_ActivateTrap"));
void ANewTrapTile::Server_ActivateTrap()
{
	ProcessEvent(FindFunctionChecked(NAME_ANewTrapTile_Server_ActivateTrap),NULL);
}
struct Z_Construct_UFunction_ANewTrapTile_Server_ActivateTrap_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/NewTrapTile.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewTrapTile_Server_ActivateTrap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewTrapTile, nullptr, "Server_ActivateTrap", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewTrapTile_Server_ActivateTrap_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewTrapTile_Server_ActivateTrap_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ANewTrapTile_Server_ActivateTrap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewTrapTile_Server_ActivateTrap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANewTrapTile::execServer_ActivateTrap)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_ActivateTrap_Implementation();
	P_NATIVE_END;
}
// End Class ANewTrapTile Function Server_ActivateTrap

// Begin Class ANewTrapTile Function TriggerTrap
struct Z_Construct_UFunction_ANewTrapTile_TriggerTrap_Statics
{
	struct NewTrapTile_eventTriggerTrap_Parms
	{
		AActor* OtherActor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/NewTrapTile.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANewTrapTile_TriggerTrap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NewTrapTile_eventTriggerTrap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANewTrapTile_TriggerTrap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANewTrapTile_TriggerTrap_Statics::NewProp_OtherActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewTrapTile_TriggerTrap_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANewTrapTile_TriggerTrap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANewTrapTile, nullptr, "TriggerTrap", nullptr, nullptr, Z_Construct_UFunction_ANewTrapTile_TriggerTrap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANewTrapTile_TriggerTrap_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANewTrapTile_TriggerTrap_Statics::NewTrapTile_eventTriggerTrap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANewTrapTile_TriggerTrap_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANewTrapTile_TriggerTrap_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ANewTrapTile_TriggerTrap_Statics::NewTrapTile_eventTriggerTrap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ANewTrapTile_TriggerTrap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANewTrapTile_TriggerTrap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANewTrapTile::execTriggerTrap)
{
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TriggerTrap(Z_Param_OtherActor);
	P_NATIVE_END;
}
// End Class ANewTrapTile Function TriggerTrap

// Begin Class ANewTrapTile
void ANewTrapTile::StaticRegisterNativesANewTrapTile()
{
	UClass* Class = ANewTrapTile::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Multicast_ActivateTrap", &ANewTrapTile::execMulticast_ActivateTrap },
		{ "Server_ActivateTrap", &ANewTrapTile::execServer_ActivateTrap },
		{ "TriggerTrap", &ANewTrapTile::execTriggerTrap },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANewTrapTile);
UClass* Z_Construct_UClass_ANewTrapTile_NoRegister()
{
	return ANewTrapTile::StaticClass();
}
struct Z_Construct_UClass_ANewTrapTile_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "NewTrapTile.h" },
		{ "ModuleRelativePath", "Public/NewTrapTile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TriggerBox_MetaData[] = {
		{ "Category", "NewTrapTile" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/NewTrapTile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[] = {
		{ "Category", "NewTrapTile" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/NewTrapTile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsActivated_MetaData[] = {
		{ "Category", "NewTrapTile" },
		{ "ModuleRelativePath", "Public/NewTrapTile.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TriggerBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
	static void NewProp_bIsActivated_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsActivated;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ANewTrapTile_Multicast_ActivateTrap, "Multicast_ActivateTrap" }, // 3163072944
		{ &Z_Construct_UFunction_ANewTrapTile_Server_ActivateTrap, "Server_ActivateTrap" }, // 1138078130
		{ &Z_Construct_UFunction_ANewTrapTile_TriggerTrap, "TriggerTrap" }, // 1670655511
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANewTrapTile>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANewTrapTile_Statics::NewProp_TriggerBox = { "TriggerBox", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANewTrapTile, TriggerBox), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TriggerBox_MetaData), NewProp_TriggerBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANewTrapTile_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANewTrapTile, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mesh_MetaData), NewProp_Mesh_MetaData) };
void Z_Construct_UClass_ANewTrapTile_Statics::NewProp_bIsActivated_SetBit(void* Obj)
{
	((ANewTrapTile*)Obj)->bIsActivated = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ANewTrapTile_Statics::NewProp_bIsActivated = { "bIsActivated", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ANewTrapTile), &Z_Construct_UClass_ANewTrapTile_Statics::NewProp_bIsActivated_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsActivated_MetaData), NewProp_bIsActivated_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANewTrapTile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANewTrapTile_Statics::NewProp_TriggerBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANewTrapTile_Statics::NewProp_Mesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANewTrapTile_Statics::NewProp_bIsActivated,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANewTrapTile_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ANewTrapTile_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_FinalProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANewTrapTile_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ANewTrapTile_Statics::ClassParams = {
	&ANewTrapTile::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ANewTrapTile_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ANewTrapTile_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANewTrapTile_Statics::Class_MetaDataParams), Z_Construct_UClass_ANewTrapTile_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ANewTrapTile()
{
	if (!Z_Registration_Info_UClass_ANewTrapTile.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANewTrapTile.OuterSingleton, Z_Construct_UClass_ANewTrapTile_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ANewTrapTile.OuterSingleton;
}
template<> FINALPROJECT_API UClass* StaticClass<ANewTrapTile>()
{
	return ANewTrapTile::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ANewTrapTile);
ANewTrapTile::~ANewTrapTile() {}
// End Class ANewTrapTile

// Begin Registration
struct Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_NewTrapTile_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ANewTrapTile, ANewTrapTile::StaticClass, TEXT("ANewTrapTile"), &Z_Registration_Info_UClass_ANewTrapTile, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANewTrapTile), 99583015U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_NewTrapTile_h_2502773831(TEXT("/Script/FinalProject"),
	Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_NewTrapTile_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_NewTrapTile_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
