// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "FinalGameInstance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FSPlayerInfo;
#ifdef FINALPROJECT_FinalGameInstance_generated_h
#error "FinalGameInstance.generated.h already included, missing '#pragma once' in FinalGameInstance.h"
#endif
#define FINALPROJECT_FinalGameInstance_generated_h

#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalGameInstance_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execJoin); \
	DECLARE_FUNCTION(execHost);


#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalGameInstance_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFinalGameInstance(); \
	friend struct Z_Construct_UClass_UFinalGameInstance_Statics; \
public: \
	DECLARE_CLASS(UFinalGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/FinalProject"), NO_API) \
	DECLARE_SERIALIZER(UFinalGameInstance)


#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalGameInstance_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFinalGameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UFinalGameInstance(UFinalGameInstance&&); \
	UFinalGameInstance(const UFinalGameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFinalGameInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFinalGameInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFinalGameInstance) \
	NO_API virtual ~UFinalGameInstance();


#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalGameInstance_h_13_PROLOG
#define FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalGameInstance_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalGameInstance_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalGameInstance_h_16_INCLASS_NO_PURE_DECLS \
	FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalGameInstance_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FINALPROJECT_API UClass* StaticClass<class UFinalGameInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_kaanyildirim_Documents_GAD2006_FinalProject_Source_FinalProject_Public_FinalGameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
