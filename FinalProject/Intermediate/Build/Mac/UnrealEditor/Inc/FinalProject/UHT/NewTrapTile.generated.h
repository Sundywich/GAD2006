// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "NewTrapTile.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef FINALPROJECT_NewTrapTile_generated_h
#error "NewTrapTile.generated.h already included, missing '#pragma once' in NewTrapTile.h"
#endif
#define FINALPROJECT_NewTrapTile_generated_h

#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_NewTrapTile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Multicast_ActivateTrap_Implementation(); \
	virtual void Server_ActivateTrap_Implementation(); \
	DECLARE_FUNCTION(execMulticast_ActivateTrap); \
	DECLARE_FUNCTION(execServer_ActivateTrap); \
	DECLARE_FUNCTION(execTriggerTrap);


#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_NewTrapTile_h_15_CALLBACK_WRAPPERS
#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_NewTrapTile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesANewTrapTile(); \
	friend struct Z_Construct_UClass_ANewTrapTile_Statics; \
public: \
	DECLARE_CLASS(ANewTrapTile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FinalProject"), NO_API) \
	DECLARE_SERIALIZER(ANewTrapTile)


#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_NewTrapTile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ANewTrapTile(ANewTrapTile&&); \
	ANewTrapTile(const ANewTrapTile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANewTrapTile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANewTrapTile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ANewTrapTile) \
	NO_API virtual ~ANewTrapTile();


#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_NewTrapTile_h_12_PROLOG
#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_NewTrapTile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_NewTrapTile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_NewTrapTile_h_15_CALLBACK_WRAPPERS \
	FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_NewTrapTile_h_15_INCLASS_NO_PURE_DECLS \
	FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_NewTrapTile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FINALPROJECT_API UClass* StaticClass<class ANewTrapTile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_NewTrapTile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
