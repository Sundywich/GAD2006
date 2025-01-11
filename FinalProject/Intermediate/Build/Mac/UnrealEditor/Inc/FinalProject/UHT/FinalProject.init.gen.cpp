// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFinalProject_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_FinalProject;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_FinalProject()
	{
		if (!Z_Registration_Info_UPackage__Script_FinalProject.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/FinalProject",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x2139720E,
				0x17AF5AF4,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_FinalProject.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_FinalProject.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_FinalProject(Z_Construct_UPackage__Script_FinalProject, TEXT("/Script/FinalProject"), Z_Registration_Info_UPackage__Script_FinalProject, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x2139720E, 0x17AF5AF4));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
