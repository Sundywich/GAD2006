// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FinalProject/Public/FinalAvatar.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFinalAvatar() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
FINALPROJECT_API UClass* Z_Construct_UClass_AFinalAvatar();
FINALPROJECT_API UClass* Z_Construct_UClass_AFinalAvatar_NoRegister();
FINALPROJECT_API UClass* Z_Construct_UClass_AFinalBaseCharacter();
UPackage* Z_Construct_UPackage__Script_FinalProject();
// End Cross Module References

// Begin Class AFinalAvatar Function OnRep_bIsRunning
struct Z_Construct_UFunction_AFinalAvatar_OnRep_bIsRunning_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/FinalAvatar.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFinalAvatar_OnRep_bIsRunning_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFinalAvatar, nullptr, "OnRep_bIsRunning", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFinalAvatar_OnRep_bIsRunning_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFinalAvatar_OnRep_bIsRunning_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AFinalAvatar_OnRep_bIsRunning()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFinalAvatar_OnRep_bIsRunning_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AFinalAvatar::execOnRep_bIsRunning)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_bIsRunning();
	P_NATIVE_END;
}
// End Class AFinalAvatar Function OnRep_bIsRunning

// Begin Class AFinalAvatar Function ServerSetRunState
struct FinalAvatar_eventServerSetRunState_Parms
{
	bool NewRunState;
};
static FName NAME_AFinalAvatar_ServerSetRunState = FName(TEXT("ServerSetRunState"));
void AFinalAvatar::ServerSetRunState(bool NewRunState)
{
	FinalAvatar_eventServerSetRunState_Parms Parms;
	Parms.NewRunState=NewRunState ? true : false;
	ProcessEvent(FindFunctionChecked(NAME_AFinalAvatar_ServerSetRunState),&Parms);
}
struct Z_Construct_UFunction_AFinalAvatar_ServerSetRunState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/FinalAvatar.h" },
	};
#endif // WITH_METADATA
	static void NewProp_NewRunState_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_NewRunState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AFinalAvatar_ServerSetRunState_Statics::NewProp_NewRunState_SetBit(void* Obj)
{
	((FinalAvatar_eventServerSetRunState_Parms*)Obj)->NewRunState = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AFinalAvatar_ServerSetRunState_Statics::NewProp_NewRunState = { "NewRunState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FinalAvatar_eventServerSetRunState_Parms), &Z_Construct_UFunction_AFinalAvatar_ServerSetRunState_Statics::NewProp_NewRunState_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFinalAvatar_ServerSetRunState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFinalAvatar_ServerSetRunState_Statics::NewProp_NewRunState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AFinalAvatar_ServerSetRunState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFinalAvatar_ServerSetRunState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFinalAvatar, nullptr, "ServerSetRunState", nullptr, nullptr, Z_Construct_UFunction_AFinalAvatar_ServerSetRunState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFinalAvatar_ServerSetRunState_Statics::PropPointers), sizeof(FinalAvatar_eventServerSetRunState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFinalAvatar_ServerSetRunState_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFinalAvatar_ServerSetRunState_Statics::Function_MetaDataParams) };
static_assert(sizeof(FinalAvatar_eventServerSetRunState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AFinalAvatar_ServerSetRunState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFinalAvatar_ServerSetRunState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AFinalAvatar::execServerSetRunState)
{
	P_GET_UBOOL(Z_Param_NewRunState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerSetRunState_Implementation(Z_Param_NewRunState);
	P_NATIVE_END;
}
// End Class AFinalAvatar Function ServerSetRunState

// Begin Class AFinalAvatar
void AFinalAvatar::StaticRegisterNativesAFinalAvatar()
{
	UClass* Class = AFinalAvatar::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnRep_bIsRunning", &AFinalAvatar::execOnRep_bIsRunning },
		{ "ServerSetRunState", &AFinalAvatar::execServerSetRunState },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFinalAvatar);
UClass* Z_Construct_UClass_AFinalAvatar_NoRegister()
{
	return AFinalAvatar::StaticClass();
}
struct Z_Construct_UClass_AFinalAvatar_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "FinalAvatar.h" },
		{ "ModuleRelativePath", "Public/FinalAvatar.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[] = {
		{ "Category", "FinalAvatar" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/FinalAvatar.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[] = {
		{ "Category", "FinalAvatar" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/FinalAvatar.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RunSpeed_MetaData[] = {
		{ "Category", "FinalAvatar" },
		{ "ModuleRelativePath", "Public/FinalAvatar.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalkSpeed_MetaData[] = {
		{ "Category", "FinalAvatar" },
		{ "ModuleRelativePath", "Public/FinalAvatar.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsRunning_MetaData[] = {
		{ "Category", "FinalAvatar" },
		{ "ModuleRelativePath", "Public/FinalAvatar.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RunSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WalkSpeed;
	static void NewProp_bIsRunning_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsRunning;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AFinalAvatar_OnRep_bIsRunning, "OnRep_bIsRunning" }, // 1752930836
		{ &Z_Construct_UFunction_AFinalAvatar_ServerSetRunState, "ServerSetRunState" }, // 1692349196
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFinalAvatar>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFinalAvatar_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFinalAvatar, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Camera_MetaData), NewProp_Camera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFinalAvatar_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFinalAvatar, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringArm_MetaData), NewProp_SpringArm_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFinalAvatar_Statics::NewProp_RunSpeed = { "RunSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFinalAvatar, RunSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RunSpeed_MetaData), NewProp_RunSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFinalAvatar_Statics::NewProp_WalkSpeed = { "WalkSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFinalAvatar, WalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalkSpeed_MetaData), NewProp_WalkSpeed_MetaData) };
void Z_Construct_UClass_AFinalAvatar_Statics::NewProp_bIsRunning_SetBit(void* Obj)
{
	((AFinalAvatar*)Obj)->bIsRunning = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AFinalAvatar_Statics::NewProp_bIsRunning = { "bIsRunning", "OnRep_bIsRunning", (EPropertyFlags)0x0010000100020021, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AFinalAvatar), &Z_Construct_UClass_AFinalAvatar_Statics::NewProp_bIsRunning_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsRunning_MetaData), NewProp_bIsRunning_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFinalAvatar_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFinalAvatar_Statics::NewProp_Camera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFinalAvatar_Statics::NewProp_SpringArm,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFinalAvatar_Statics::NewProp_RunSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFinalAvatar_Statics::NewProp_WalkSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFinalAvatar_Statics::NewProp_bIsRunning,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFinalAvatar_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AFinalAvatar_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AFinalBaseCharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_FinalProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFinalAvatar_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AFinalAvatar_Statics::ClassParams = {
	&AFinalAvatar::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AFinalAvatar_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AFinalAvatar_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFinalAvatar_Statics::Class_MetaDataParams), Z_Construct_UClass_AFinalAvatar_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AFinalAvatar()
{
	if (!Z_Registration_Info_UClass_AFinalAvatar.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFinalAvatar.OuterSingleton, Z_Construct_UClass_AFinalAvatar_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AFinalAvatar.OuterSingleton;
}
template<> FINALPROJECT_API UClass* StaticClass<AFinalAvatar>()
{
	return AFinalAvatar::StaticClass();
}
void AFinalAvatar::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static const FName Name_bIsRunning(TEXT("bIsRunning"));
	const bool bIsValid = true
		&& Name_bIsRunning == ClassReps[(int32)ENetFields_Private::bIsRunning].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AFinalAvatar"));
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AFinalAvatar);
AFinalAvatar::~AFinalAvatar() {}
// End Class AFinalAvatar

// Begin Registration
struct Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalAvatar_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFinalAvatar, AFinalAvatar::StaticClass, TEXT("AFinalAvatar"), &Z_Registration_Info_UClass_AFinalAvatar, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFinalAvatar), 2901715543U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalAvatar_h_3410004664(TEXT("/Script/FinalProject"),
	Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalAvatar_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalAvatar_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
