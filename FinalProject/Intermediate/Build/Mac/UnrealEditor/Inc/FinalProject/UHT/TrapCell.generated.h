// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TrapCell.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef FINALPROJECT_TrapCell_generated_h
#error "TrapCell.generated.h already included, missing '#pragma once' in TrapCell.h"
#endif
#define FINALPROJECT_TrapCell_generated_h

#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_TrapCell_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnRep_IsActivated); \
	DECLARE_FUNCTION(execOnOverlap);


#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_TrapCell_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATrapCell(); \
	friend struct Z_Construct_UClass_ATrapCell_Statics; \
public: \
	DECLARE_CLASS(ATrapCell, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FinalProject"), NO_API) \
	DECLARE_SERIALIZER(ATrapCell) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		bIsActivated=NETFIELD_REP_START, \
		NETFIELD_REP_END=bIsActivated	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_TrapCell_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ATrapCell(ATrapCell&&); \
	ATrapCell(const ATrapCell&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATrapCell); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATrapCell); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATrapCell) \
	NO_API virtual ~ATrapCell();


#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_TrapCell_h_11_PROLOG
#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_TrapCell_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_TrapCell_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_TrapCell_h_14_INCLASS_NO_PURE_DECLS \
	FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_TrapCell_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FINALPROJECT_API UClass* StaticClass<class ATrapCell>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_TrapCell_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
