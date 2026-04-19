// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LabWork2/Private/GameSlot.h"
#include "Runtime/InputCore/Classes/InputCoreTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameSlot() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
LABWORK2_API UClass* Z_Construct_UClass_AGameSlot();
LABWORK2_API UClass* Z_Construct_UClass_AGameSlot_NoRegister();
LABWORK2_API UClass* Z_Construct_UClass_AUnitBase_NoRegister();
LABWORK2_API UEnum* Z_Construct_UEnum_LabWork2_EGridState();
LABWORK2_API UScriptStruct* Z_Construct_UScriptStruct_FSGridPosition();
UPackage* Z_Construct_UPackage__Script_LabWork2();
// End Cross Module References

// Begin ScriptStruct FSGridPosition
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SGridPosition;
class UScriptStruct* FSGridPosition::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SGridPosition.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SGridPosition.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSGridPosition, (UObject*)Z_Construct_UPackage__Script_LabWork2(), TEXT("SGridPosition"));
	}
	return Z_Registration_Info_UScriptStruct_SGridPosition.OuterSingleton;
}
template<> LABWORK2_API UScriptStruct* StaticStruct<FSGridPosition>()
{
	return FSGridPosition::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSGridPosition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Private/GameSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Col_MetaData[] = {
		{ "Category", "SGridPosition" },
		{ "ModuleRelativePath", "Private/GameSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Row_MetaData[] = {
		{ "Category", "SGridPosition" },
		{ "ModuleRelativePath", "Private/GameSlot.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Col;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Row;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSGridPosition>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FSGridPosition_Statics::NewProp_Col = { "Col", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSGridPosition, Col), nullptr, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Col_MetaData), NewProp_Col_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FSGridPosition_Statics::NewProp_Row = { "Row", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSGridPosition, Row), nullptr, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Row_MetaData), NewProp_Row_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSGridPosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSGridPosition_Statics::NewProp_Col,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSGridPosition_Statics::NewProp_Row,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSGridPosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSGridPosition_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_LabWork2,
	nullptr,
	&NewStructOps,
	"SGridPosition",
	Z_Construct_UScriptStruct_FSGridPosition_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSGridPosition_Statics::PropPointers),
	sizeof(FSGridPosition),
	alignof(FSGridPosition),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSGridPosition_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSGridPosition_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSGridPosition()
{
	if (!Z_Registration_Info_UScriptStruct_SGridPosition.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SGridPosition.InnerSingleton, Z_Construct_UScriptStruct_FSGridPosition_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SGridPosition.InnerSingleton;
}
// End ScriptStruct FSGridPosition

// Begin Enum EGridState
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EGridState;
static UEnum* EGridState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EGridState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EGridState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LabWork2_EGridState, (UObject*)Z_Construct_UPackage__Script_LabWork2(), TEXT("EGridState"));
	}
	return Z_Registration_Info_UEnum_EGridState.OuterSingleton;
}
template<> LABWORK2_API UEnum* StaticEnum<EGridState>()
{
	return EGridState_StaticEnum();
}
struct Z_Construct_UEnum_LabWork2_EGridState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "GS_Default.Name", "GS_Default" },
		{ "GS_Highlighted.Name", "GS_Highlighted" },
		{ "GS_Offensive.Name", "GS_Offensive" },
		{ "GS_Supportive.Name", "GS_Supportive" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Private/GameSlot.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "GS_Default", (int64)GS_Default },
		{ "GS_Highlighted", (int64)GS_Highlighted },
		{ "GS_Offensive", (int64)GS_Offensive },
		{ "GS_Supportive", (int64)GS_Supportive },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LabWork2_EGridState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_LabWork2,
	nullptr,
	"EGridState",
	"EGridState",
	Z_Construct_UEnum_LabWork2_EGridState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_LabWork2_EGridState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::Regular,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_LabWork2_EGridState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_LabWork2_EGridState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_LabWork2_EGridState()
{
	if (!Z_Registration_Info_UEnum_EGridState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EGridState.InnerSingleton, Z_Construct_UEnum_LabWork2_EGridState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EGridState.InnerSingleton;
}
// End Enum EGridState

// Begin Class AGameSlot Function OnGridClicked
struct Z_Construct_UFunction_AGameSlot_OnGridClicked_Statics
{
	struct GameSlot_eventOnGridClicked_Parms
	{
		AActor* TouchedActor;
		FKey ButtonPressed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/GameSlot.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TouchedActor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ButtonPressed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AGameSlot_OnGridClicked_Statics::NewProp_TouchedActor = { "TouchedActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameSlot_eventOnGridClicked_Parms, TouchedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGameSlot_OnGridClicked_Statics::NewProp_ButtonPressed = { "ButtonPressed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameSlot_eventOnGridClicked_Parms, ButtonPressed), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(0, nullptr) }; // 658672854
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGameSlot_OnGridClicked_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGameSlot_OnGridClicked_Statics::NewProp_TouchedActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGameSlot_OnGridClicked_Statics::NewProp_ButtonPressed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGameSlot_OnGridClicked_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGameSlot_OnGridClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGameSlot, nullptr, "OnGridClicked", nullptr, nullptr, Z_Construct_UFunction_AGameSlot_OnGridClicked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGameSlot_OnGridClicked_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGameSlot_OnGridClicked_Statics::GameSlot_eventOnGridClicked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGameSlot_OnGridClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGameSlot_OnGridClicked_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGameSlot_OnGridClicked_Statics::GameSlot_eventOnGridClicked_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGameSlot_OnGridClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGameSlot_OnGridClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGameSlot::execOnGridClicked)
{
	P_GET_OBJECT(AActor,Z_Param_TouchedActor);
	P_GET_STRUCT(FKey,Z_Param_ButtonPressed);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnGridClicked(Z_Param_TouchedActor,Z_Param_ButtonPressed);
	P_NATIVE_END;
}
// End Class AGameSlot Function OnGridClicked

// Begin Class AGameSlot Function SetState
struct Z_Construct_UFunction_AGameSlot_SetState_Statics
{
	struct GameSlot_eventSetState_Parms
	{
		TEnumAsByte<EGridState> NewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/GameSlot.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AGameSlot_SetState_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameSlot_eventSetState_Parms, NewState), Z_Construct_UEnum_LabWork2_EGridState, METADATA_PARAMS(0, nullptr) }; // 141584700
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGameSlot_SetState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGameSlot_SetState_Statics::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGameSlot_SetState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGameSlot_SetState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGameSlot, nullptr, "SetState", nullptr, nullptr, Z_Construct_UFunction_AGameSlot_SetState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGameSlot_SetState_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGameSlot_SetState_Statics::GameSlot_eventSetState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGameSlot_SetState_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGameSlot_SetState_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGameSlot_SetState_Statics::GameSlot_eventSetState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGameSlot_SetState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGameSlot_SetState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGameSlot::execSetState)
{
	P_GET_PROPERTY(FByteProperty,Z_Param_NewState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetState(EGridState(Z_Param_NewState));
	P_NATIVE_END;
}
// End Class AGameSlot Function SetState

// Begin Class AGameSlot
void AGameSlot::StaticRegisterNativesAGameSlot()
{
	UClass* Class = AGameSlot::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnGridClicked", &AGameSlot::execOnGridClicked },
		{ "SetState", &AGameSlot::execSetState },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGameSlot);
UClass* Z_Construct_UClass_AGameSlot_NoRegister()
{
	return AGameSlot::StaticClass();
}
struct Z_Construct_UClass_AGameSlot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "GameSlot.h" },
		{ "ModuleRelativePath", "Private/GameSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Box_MetaData[] = {
		{ "Category", "GameSlot" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Private/GameSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Plane_MetaData[] = {
		{ "Category", "GameSlot" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Private/GameSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Unit_MetaData[] = {
		{ "Category", "GameSlot" },
		{ "ModuleRelativePath", "Private/GameSlot.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Box;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Plane;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Unit;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AGameSlot_OnGridClicked, "OnGridClicked" }, // 3796922958
		{ &Z_Construct_UFunction_AGameSlot_SetState, "SetState" }, // 546969912
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGameSlot>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGameSlot_Statics::NewProp_Box = { "Box", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGameSlot, Box), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Box_MetaData), NewProp_Box_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGameSlot_Statics::NewProp_Plane = { "Plane", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGameSlot, Plane), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Plane_MetaData), NewProp_Plane_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGameSlot_Statics::NewProp_Unit = { "Unit", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGameSlot, Unit), Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Unit_MetaData), NewProp_Unit_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGameSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameSlot_Statics::NewProp_Box,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameSlot_Statics::NewProp_Plane,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameSlot_Statics::NewProp_Unit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGameSlot_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AGameSlot_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_LabWork2,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGameSlot_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGameSlot_Statics::ClassParams = {
	&AGameSlot::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AGameSlot_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AGameSlot_Statics::PropPointers),
	0,
	0x008000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGameSlot_Statics::Class_MetaDataParams), Z_Construct_UClass_AGameSlot_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGameSlot()
{
	if (!Z_Registration_Info_UClass_AGameSlot.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGameSlot.OuterSingleton, Z_Construct_UClass_AGameSlot_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGameSlot.OuterSingleton;
}
template<> LABWORK2_API UClass* StaticClass<AGameSlot>()
{
	return AGameSlot::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGameSlot);
AGameSlot::~AGameSlot() {}
// End Class AGameSlot

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_baris_Desktop_projeler_GAD2006_LabWork2_Source_LabWork2_Private_GameSlot_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EGridState_StaticEnum, TEXT("EGridState"), &Z_Registration_Info_UEnum_EGridState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 141584700U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FSGridPosition::StaticStruct, Z_Construct_UScriptStruct_FSGridPosition_Statics::NewStructOps, TEXT("SGridPosition"), &Z_Registration_Info_UScriptStruct_SGridPosition, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSGridPosition), 3248566072U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGameSlot, AGameSlot::StaticClass, TEXT("AGameSlot"), &Z_Registration_Info_UClass_AGameSlot, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGameSlot), 411485322U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_baris_Desktop_projeler_GAD2006_LabWork2_Source_LabWork2_Private_GameSlot_h_4189376021(TEXT("/Script/LabWork2"),
	Z_CompiledInDeferFile_FID_Users_baris_Desktop_projeler_GAD2006_LabWork2_Source_LabWork2_Private_GameSlot_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_baris_Desktop_projeler_GAD2006_LabWork2_Source_LabWork2_Private_GameSlot_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_baris_Desktop_projeler_GAD2006_LabWork2_Source_LabWork2_Private_GameSlot_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_baris_Desktop_projeler_GAD2006_LabWork2_Source_LabWork2_Private_GameSlot_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Users_baris_Desktop_projeler_GAD2006_LabWork2_Source_LabWork2_Private_GameSlot_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_baris_Desktop_projeler_GAD2006_LabWork2_Source_LabWork2_Private_GameSlot_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
