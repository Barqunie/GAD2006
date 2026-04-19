// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LabWork2/Private/GameGrid.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameGrid() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UChildActorComponent_NoRegister();
LABWORK2_API UClass* Z_Construct_UClass_AGameGrid();
LABWORK2_API UClass* Z_Construct_UClass_AGameGrid_NoRegister();
LABWORK2_API UClass* Z_Construct_UClass_AGameSlot_NoRegister();
UPackage* Z_Construct_UPackage__Script_LabWork2();
// End Cross Module References

// Begin Class AGameGrid
void AGameGrid::StaticRegisterNativesAGameGrid()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGameGrid);
UClass* Z_Construct_UClass_AGameGrid_NoRegister()
{
	return AGameGrid::StaticClass();
}
struct Z_Construct_UClass_AGameGrid_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "GameGrid.h" },
		{ "ModuleRelativePath", "Private/GameGrid.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridClass_MetaData[] = {
		{ "Category", "GameGrid" },
		{ "ModuleRelativePath", "Private/GameGrid.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NumRows_MetaData[] = {
		{ "Category", "GameGrid" },
		{ "ModuleRelativePath", "Private/GameGrid.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NumCols_MetaData[] = {
		{ "Category", "GameGrid" },
		{ "ModuleRelativePath", "Private/GameGrid.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridActors_MetaData[] = {
		{ "Category", "GameGrid" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Private/GameGrid.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_GridClass;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumRows;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumCols;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GridActors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_GridActors;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGameGrid>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AGameGrid_Statics::NewProp_GridClass = { "GridClass", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGameGrid, GridClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AGameSlot_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridClass_MetaData), NewProp_GridClass_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGameGrid_Statics::NewProp_NumRows = { "NumRows", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGameGrid, NumRows), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NumRows_MetaData), NewProp_NumRows_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGameGrid_Statics::NewProp_NumCols = { "NumCols", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGameGrid, NumCols), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NumCols_MetaData), NewProp_NumCols_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGameGrid_Statics::NewProp_GridActors_Inner = { "GridActors", nullptr, (EPropertyFlags)0x00000000000a0008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UChildActorComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AGameGrid_Statics::NewProp_GridActors = { "GridActors", nullptr, (EPropertyFlags)0x0010008000020009, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGameGrid, GridActors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridActors_MetaData), NewProp_GridActors_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGameGrid_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameGrid_Statics::NewProp_GridClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameGrid_Statics::NewProp_NumRows,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameGrid_Statics::NewProp_NumCols,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameGrid_Statics::NewProp_GridActors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameGrid_Statics::NewProp_GridActors,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGameGrid_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AGameGrid_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_LabWork2,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGameGrid_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGameGrid_Statics::ClassParams = {
	&AGameGrid::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AGameGrid_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AGameGrid_Statics::PropPointers),
	0,
	0x008000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGameGrid_Statics::Class_MetaDataParams), Z_Construct_UClass_AGameGrid_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGameGrid()
{
	if (!Z_Registration_Info_UClass_AGameGrid.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGameGrid.OuterSingleton, Z_Construct_UClass_AGameGrid_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGameGrid.OuterSingleton;
}
template<> LABWORK2_API UClass* StaticClass<AGameGrid>()
{
	return AGameGrid::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGameGrid);
AGameGrid::~AGameGrid() {}
// End Class AGameGrid

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_baris_Desktop_projeler_GAD2006_LabWork2_Source_LabWork2_Private_GameGrid_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGameGrid, AGameGrid::StaticClass, TEXT("AGameGrid"), &Z_Registration_Info_UClass_AGameGrid, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGameGrid), 1838143632U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_baris_Desktop_projeler_GAD2006_LabWork2_Source_LabWork2_Private_GameGrid_h_383688217(TEXT("/Script/LabWork2"),
	Z_CompiledInDeferFile_FID_Users_baris_Desktop_projeler_GAD2006_LabWork2_Source_LabWork2_Private_GameGrid_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_baris_Desktop_projeler_GAD2006_LabWork2_Source_LabWork2_Private_GameGrid_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
