// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "FinalAvatar.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FINALPROJECT_FinalAvatar_generated_h
#error "FinalAvatar.generated.h already included, missing '#pragma once' in FinalAvatar.h"
#endif
#define FINALPROJECT_FinalAvatar_generated_h

#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalAvatar_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void ServerSetRunState_Implementation(bool NewRunState); \
	DECLARE_FUNCTION(execOnRep_bIsRunning); \
	DECLARE_FUNCTION(execServerSetRunState);


#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalAvatar_h_17_CALLBACK_WRAPPERS
#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalAvatar_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFinalAvatar(); \
	friend struct Z_Construct_UClass_AFinalAvatar_Statics; \
public: \
	DECLARE_CLASS(AFinalAvatar, AFinalBaseCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FinalProject"), NO_API) \
	DECLARE_SERIALIZER(AFinalAvatar) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		bIsRunning=NETFIELD_REP_START, \
		NETFIELD_REP_END=bIsRunning	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalAvatar_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AFinalAvatar(AFinalAvatar&&); \
	AFinalAvatar(const AFinalAvatar&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFinalAvatar); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFinalAvatar); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFinalAvatar) \
	NO_API virtual ~AFinalAvatar();


#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalAvatar_h_14_PROLOG
#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalAvatar_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalAvatar_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalAvatar_h_17_CALLBACK_WRAPPERS \
	FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalAvatar_h_17_INCLASS_NO_PURE_DECLS \
	FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalAvatar_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FINALPROJECT_API UClass* StaticClass<class AFinalAvatar>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalAvatar_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
