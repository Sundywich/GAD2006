// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BaseTrapTile.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef FINALPROJECT_BaseTrapTile_generated_h
#error "BaseTrapTile.generated.h already included, missing '#pragma once' in BaseTrapTile.h"
#endif
#define FINALPROJECT_BaseTrapTile_generated_h

#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_BaseTrapTile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Multicast_ActivateTrap_Implementation(); \
	virtual void Server_ActivateTrap_Implementation(); \
	DECLARE_FUNCTION(execMulticast_ActivateTrap); \
	DECLARE_FUNCTION(execServer_ActivateTrap); \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_BaseTrapTile_h_15_CALLBACK_WRAPPERS
#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_BaseTrapTile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABaseTrapTile(); \
	friend struct Z_Construct_UClass_ABaseTrapTile_Statics; \
public: \
	DECLARE_CLASS(ABaseTrapTile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FinalProject"), NO_API) \
	DECLARE_SERIALIZER(ABaseTrapTile)


#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_BaseTrapTile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ABaseTrapTile(ABaseTrapTile&&); \
	ABaseTrapTile(const ABaseTrapTile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABaseTrapTile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABaseTrapTile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABaseTrapTile) \
	NO_API virtual ~ABaseTrapTile();


#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_BaseTrapTile_h_12_PROLOG
#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_BaseTrapTile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_BaseTrapTile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_BaseTrapTile_h_15_CALLBACK_WRAPPERS \
	FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_BaseTrapTile_h_15_INCLASS_NO_PURE_DECLS \
	FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_BaseTrapTile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FINALPROJECT_API UClass* StaticClass<class ABaseTrapTile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_BaseTrapTile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
