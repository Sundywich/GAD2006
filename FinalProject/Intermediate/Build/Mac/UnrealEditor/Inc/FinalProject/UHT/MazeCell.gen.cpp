// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FinalProject/Public/MazeCell.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMazeCell() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
FINALPROJECT_API UClass* Z_Construct_UClass_AMazeCell();
FINALPROJECT_API UClass* Z_Construct_UClass_AMazeCell_NoRegister();
UPackage* Z_Construct_UPackage__Script_FinalProject();
// End Cross Module References

// Begin Class AMazeCell
void AMazeCell::StaticRegisterNativesAMazeCell()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMazeCell);
UClass* Z_Construct_UClass_AMazeCell_NoRegister()
{
	return AMazeCell::StaticClass();
}
struct Z_Construct_UClass_AMazeCell_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "MazeCell.h" },
		{ "ModuleRelativePath", "Public/MazeCell.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Floor_MetaData[] = {
		{ "Category", "MazeCell" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MazeCell.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TrapTrigger_MetaData[] = {
		{ "Category", "MazeCell" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MazeCell.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NorthWall_MetaData[] = {
		{ "Category", "MazeCell" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MazeCell.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SouthWall_MetaData[] = {
		{ "Category", "MazeCell" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MazeCell.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EastWall_MetaData[] = {
		{ "Category", "MazeCell" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MazeCell.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WestWall_MetaData[] = {
		{ "Category", "MazeCell" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MazeCell.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSize_MetaData[] = {
		{ "Category", "MazeCell" },
		{ "ModuleRelativePath", "Public/MazeCell.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WallHeight_MetaData[] = {
		{ "Category", "MazeCell" },
		{ "ModuleRelativePath", "Public/MazeCell.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bNorthWallAvailable_MetaData[] = {
		{ "Category", "MazeCell" },
		{ "ModuleRelativePath", "Public/MazeCell.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSouthWallAvailable_MetaData[] = {
		{ "Category", "MazeCell" },
		{ "ModuleRelativePath", "Public/MazeCell.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEastWallAvailable_MetaData[] = {
		{ "Category", "MazeCell" },
		{ "ModuleRelativePath", "Public/MazeCell.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bWestWallAvailable_MetaData[] = {
		{ "Category", "MazeCell" },
		{ "ModuleRelativePath", "Public/MazeCell.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Floor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TrapTrigger;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NorthWall;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SouthWall;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EastWall;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WestWall;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GridSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WallHeight;
	static void NewProp_bNorthWallAvailable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNorthWallAvailable;
	static void NewProp_bSouthWallAvailable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSouthWallAvailable;
	static void NewProp_bEastWallAvailable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEastWallAvailable;
	static void NewProp_bWestWallAvailable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWestWallAvailable;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMazeCell>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMazeCell_Statics::NewProp_Floor = { "Floor", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMazeCell, Floor), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Floor_MetaData), NewProp_Floor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMazeCell_Statics::NewProp_TrapTrigger = { "TrapTrigger", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMazeCell, TrapTrigger), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TrapTrigger_MetaData), NewProp_TrapTrigger_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMazeCell_Statics::NewProp_NorthWall = { "NorthWall", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMazeCell, NorthWall), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NorthWall_MetaData), NewProp_NorthWall_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMazeCell_Statics::NewProp_SouthWall = { "SouthWall", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMazeCell, SouthWall), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SouthWall_MetaData), NewProp_SouthWall_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMazeCell_Statics::NewProp_EastWall = { "EastWall", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMazeCell, EastWall), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EastWall_MetaData), NewProp_EastWall_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMazeCell_Statics::NewProp_WestWall = { "WestWall", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMazeCell, WestWall), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WestWall_MetaData), NewProp_WestWall_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMazeCell_Statics::NewProp_GridSize = { "GridSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMazeCell, GridSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridSize_MetaData), NewProp_GridSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMazeCell_Statics::NewProp_WallHeight = { "WallHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMazeCell, WallHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallHeight_MetaData), NewProp_WallHeight_MetaData) };
void Z_Construct_UClass_AMazeCell_Statics::NewProp_bNorthWallAvailable_SetBit(void* Obj)
{
	((AMazeCell*)Obj)->bNorthWallAvailable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMazeCell_Statics::NewProp_bNorthWallAvailable = { "bNorthWallAvailable", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMazeCell), &Z_Construct_UClass_AMazeCell_Statics::NewProp_bNorthWallAvailable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bNorthWallAvailable_MetaData), NewProp_bNorthWallAvailable_MetaData) };
void Z_Construct_UClass_AMazeCell_Statics::NewProp_bSouthWallAvailable_SetBit(void* Obj)
{
	((AMazeCell*)Obj)->bSouthWallAvailable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMazeCell_Statics::NewProp_bSouthWallAvailable = { "bSouthWallAvailable", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMazeCell), &Z_Construct_UClass_AMazeCell_Statics::NewProp_bSouthWallAvailable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSouthWallAvailable_MetaData), NewProp_bSouthWallAvailable_MetaData) };
void Z_Construct_UClass_AMazeCell_Statics::NewProp_bEastWallAvailable_SetBit(void* Obj)
{
	((AMazeCell*)Obj)->bEastWallAvailable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMazeCell_Statics::NewProp_bEastWallAvailable = { "bEastWallAvailable", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMazeCell), &Z_Construct_UClass_AMazeCell_Statics::NewProp_bEastWallAvailable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEastWallAvailable_MetaData), NewProp_bEastWallAvailable_MetaData) };
void Z_Construct_UClass_AMazeCell_Statics::NewProp_bWestWallAvailable_SetBit(void* Obj)
{
	((AMazeCell*)Obj)->bWestWallAvailable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMazeCell_Statics::NewProp_bWestWallAvailable = { "bWestWallAvailable", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMazeCell), &Z_Construct_UClass_AMazeCell_Statics::NewProp_bWestWallAvailable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bWestWallAvailable_MetaData), NewProp_bWestWallAvailable_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMazeCell_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMazeCell_Statics::NewProp_Floor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMazeCell_Statics::NewProp_TrapTrigger,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMazeCell_Statics::NewProp_NorthWall,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMazeCell_Statics::NewProp_SouthWall,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMazeCell_Statics::NewProp_EastWall,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMazeCell_Statics::NewProp_WestWall,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMazeCell_Statics::NewProp_GridSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMazeCell_Statics::NewProp_WallHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMazeCell_Statics::NewProp_bNorthWallAvailable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMazeCell_Statics::NewProp_bSouthWallAvailable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMazeCell_Statics::NewProp_bEastWallAvailable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMazeCell_Statics::NewProp_bWestWallAvailable,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMazeCell_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMazeCell_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_FinalProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMazeCell_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMazeCell_Statics::ClassParams = {
	&AMazeCell::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AMazeCell_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AMazeCell_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMazeCell_Statics::Class_MetaDataParams), Z_Construct_UClass_AMazeCell_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMazeCell()
{
	if (!Z_Registration_Info_UClass_AMazeCell.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMazeCell.OuterSingleton, Z_Construct_UClass_AMazeCell_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMazeCell.OuterSingleton;
}
template<> FINALPROJECT_API UClass* StaticClass<AMazeCell>()
{
	return AMazeCell::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMazeCell);
AMazeCell::~AMazeCell() {}
// End Class AMazeCell

// Begin Registration
struct Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_MazeCell_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMazeCell, AMazeCell::StaticClass, TEXT("AMazeCell"), &Z_Registration_Info_UClass_AMazeCell, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMazeCell), 259091021U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_MazeCell_h_4140085424(TEXT("/Script/FinalProject"),
	Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_MazeCell_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_MazeCell_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
