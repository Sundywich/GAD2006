// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FinalProject/Public/FinalGameInstance.h"
#include "FinalProject/Public/FinalBaseCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFinalGameInstance() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
FINALPROJECT_API UClass* Z_Construct_UClass_UFinalGameInstance();
FINALPROJECT_API UClass* Z_Construct_UClass_UFinalGameInstance_NoRegister();
FINALPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSPlayerInfo();
UPackage* Z_Construct_UPackage__Script_FinalProject();
// End Cross Module References

// Begin Class UFinalGameInstance Function Host
struct Z_Construct_UFunction_UFinalGameInstance_Host_Statics
{
	struct FinalGameInstance_eventHost_Parms
	{
		FString MapName;
		FSPlayerInfo PlayerInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/FinalGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_MapName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PlayerInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFinalGameInstance_Host_Statics::NewProp_MapName = { "MapName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FinalGameInstance_eventHost_Parms, MapName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFinalGameInstance_Host_Statics::NewProp_PlayerInfo = { "PlayerInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FinalGameInstance_eventHost_Parms, PlayerInfo), Z_Construct_UScriptStruct_FSPlayerInfo, METADATA_PARAMS(0, nullptr) }; // 526334736
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFinalGameInstance_Host_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFinalGameInstance_Host_Statics::NewProp_MapName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFinalGameInstance_Host_Statics::NewProp_PlayerInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFinalGameInstance_Host_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFinalGameInstance_Host_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFinalGameInstance, nullptr, "Host", nullptr, nullptr, Z_Construct_UFunction_UFinalGameInstance_Host_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFinalGameInstance_Host_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFinalGameInstance_Host_Statics::FinalGameInstance_eventHost_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFinalGameInstance_Host_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFinalGameInstance_Host_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFinalGameInstance_Host_Statics::FinalGameInstance_eventHost_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFinalGameInstance_Host()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFinalGameInstance_Host_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFinalGameInstance::execHost)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_MapName);
	P_GET_STRUCT(FSPlayerInfo,Z_Param_PlayerInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Host(Z_Param_MapName,Z_Param_PlayerInfo);
	P_NATIVE_END;
}
// End Class UFinalGameInstance Function Host

// Begin Class UFinalGameInstance Function Join
struct Z_Construct_UFunction_UFinalGameInstance_Join_Statics
{
	struct FinalGameInstance_eventJoin_Parms
	{
		FString Address;
		FSPlayerInfo PlayerInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/FinalGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Address;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PlayerInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFinalGameInstance_Join_Statics::NewProp_Address = { "Address", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FinalGameInstance_eventJoin_Parms, Address), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFinalGameInstance_Join_Statics::NewProp_PlayerInfo = { "PlayerInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FinalGameInstance_eventJoin_Parms, PlayerInfo), Z_Construct_UScriptStruct_FSPlayerInfo, METADATA_PARAMS(0, nullptr) }; // 526334736
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFinalGameInstance_Join_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFinalGameInstance_Join_Statics::NewProp_Address,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFinalGameInstance_Join_Statics::NewProp_PlayerInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFinalGameInstance_Join_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFinalGameInstance_Join_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFinalGameInstance, nullptr, "Join", nullptr, nullptr, Z_Construct_UFunction_UFinalGameInstance_Join_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFinalGameInstance_Join_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFinalGameInstance_Join_Statics::FinalGameInstance_eventJoin_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFinalGameInstance_Join_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFinalGameInstance_Join_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFinalGameInstance_Join_Statics::FinalGameInstance_eventJoin_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFinalGameInstance_Join()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFinalGameInstance_Join_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFinalGameInstance::execJoin)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Address);
	P_GET_STRUCT(FSPlayerInfo,Z_Param_PlayerInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Join(Z_Param_Address,Z_Param_PlayerInfo);
	P_NATIVE_END;
}
// End Class UFinalGameInstance Function Join

// Begin Class UFinalGameInstance
void UFinalGameInstance::StaticRegisterNativesUFinalGameInstance()
{
	UClass* Class = UFinalGameInstance::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Host", &UFinalGameInstance::execHost },
		{ "Join", &UFinalGameInstance::execJoin },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UFinalGameInstance);
UClass* Z_Construct_UClass_UFinalGameInstance_NoRegister()
{
	return UFinalGameInstance::StaticClass();
}
struct Z_Construct_UClass_UFinalGameInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "FinalGameInstance.h" },
		{ "ModuleRelativePath", "Public/FinalGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerInfo_MetaData[] = {
		{ "Category", "FinalGameInstance" },
		{ "ModuleRelativePath", "Public/FinalGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_PlayerInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UFinalGameInstance_Host, "Host" }, // 1510984584
		{ &Z_Construct_UFunction_UFinalGameInstance_Join, "Join" }, // 2025169420
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFinalGameInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UFinalGameInstance_Statics::NewProp_PlayerInfo = { "PlayerInfo", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFinalGameInstance, PlayerInfo), Z_Construct_UScriptStruct_FSPlayerInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerInfo_MetaData), NewProp_PlayerInfo_MetaData) }; // 526334736
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFinalGameInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFinalGameInstance_Statics::NewProp_PlayerInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFinalGameInstance_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UFinalGameInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_FinalProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFinalGameInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UFinalGameInstance_Statics::ClassParams = {
	&UFinalGameInstance::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UFinalGameInstance_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UFinalGameInstance_Statics::PropPointers),
	0,
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFinalGameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UFinalGameInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UFinalGameInstance()
{
	if (!Z_Registration_Info_UClass_UFinalGameInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UFinalGameInstance.OuterSingleton, Z_Construct_UClass_UFinalGameInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UFinalGameInstance.OuterSingleton;
}
template<> FINALPROJECT_API UClass* StaticClass<UFinalGameInstance>()
{
	return UFinalGameInstance::StaticClass();
}
UFinalGameInstance::UFinalGameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UFinalGameInstance);
UFinalGameInstance::~UFinalGameInstance() {}
// End Class UFinalGameInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalGameInstance_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UFinalGameInstance, UFinalGameInstance::StaticClass, TEXT("UFinalGameInstance"), &Z_Registration_Info_UClass_UFinalGameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UFinalGameInstance), 4186313319U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalGameInstance_h_2138615529(TEXT("/Script/FinalProject"),
	Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalGameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalGameInstance_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
