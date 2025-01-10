// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "FinalBaseCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EBodyPart : uint8;
struct FSPlayerInfo;
#ifdef FINALPROJECT_FinalBaseCharacter_generated_h
#error "FinalBaseCharacter.generated.h already included, missing '#pragma once' in FinalBaseCharacter.h"
#endif
#define FINALPROJECT_FinalBaseCharacter_generated_h

#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalBaseCharacter_h_26_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSMeshAssetList_Statics; \
	FINALPROJECT_API static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> FINALPROJECT_API UScriptStruct* StaticStruct<struct FSMeshAssetList>();

#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalBaseCharacter_h_38_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSBodyPartSelection_Statics; \
	FINALPROJECT_API static class UScriptStruct* StaticStruct();


template<> FINALPROJECT_API UScriptStruct* StaticStruct<struct FSBodyPartSelection>();

#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalBaseCharacter_h_50_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSPlayerInfo_Statics; \
	FINALPROJECT_API static class UScriptStruct* StaticStruct();


template<> FINALPROJECT_API UScriptStruct* StaticStruct<struct FSPlayerInfo>();

#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalBaseCharacter_h_64_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void SubmitPlayerInfoToServer_Implementation(FSPlayerInfo Info); \
	DECLARE_FUNCTION(execOnRep_PlayerInfoChanged); \
	DECLARE_FUNCTION(execSubmitPlayerInfoToServer); \
	DECLARE_FUNCTION(execChangeGender); \
	DECLARE_FUNCTION(execChangeBodyPart);


#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalBaseCharacter_h_64_CALLBACK_WRAPPERS
#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalBaseCharacter_h_64_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFinalBaseCharacter(); \
	friend struct Z_Construct_UClass_AFinalBaseCharacter_Statics; \
public: \
	DECLARE_CLASS(AFinalBaseCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FinalProject"), NO_API) \
	DECLARE_SERIALIZER(AFinalBaseCharacter) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		PartSelection=NETFIELD_REP_START, \
		NETFIELD_REP_END=PartSelection	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalBaseCharacter_h_64_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AFinalBaseCharacter(AFinalBaseCharacter&&); \
	AFinalBaseCharacter(const AFinalBaseCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFinalBaseCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFinalBaseCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFinalBaseCharacter) \
	NO_API virtual ~AFinalBaseCharacter();


#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalBaseCharacter_h_61_PROLOG
#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalBaseCharacter_h_64_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalBaseCharacter_h_64_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalBaseCharacter_h_64_CALLBACK_WRAPPERS \
	FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalBaseCharacter_h_64_INCLASS_NO_PURE_DECLS \
	FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalBaseCharacter_h_64_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FINALPROJECT_API UClass* StaticClass<class AFinalBaseCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalBaseCharacter_h


#define FOREACH_ENUM_EBODYPART(op) \
	op(EBodyPart::BP_Face) \
	op(EBodyPart::BP_Hair) \
	op(EBodyPart::BP_Chest) \
	op(EBodyPart::BP_Hands) \
	op(EBodyPart::BP_Legs) \
	op(EBodyPart::BP_Beard) \
	op(EBodyPart::BP_COUNT) 

enum class EBodyPart : uint8;
template<> struct TIsUEnumClass<EBodyPart> { enum { Value = true }; };
template<> FINALPROJECT_API UEnum* StaticEnum<EBodyPart>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
