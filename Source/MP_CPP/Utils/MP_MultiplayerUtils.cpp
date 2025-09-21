// Fill out your copyright notice in the Description page of Project Settings.


#include "MP_MultiplayerUtils.h"

void UMP_MultiplayerUtils::PrintLocalNetRole(AActor* Actor)
{
	if (Actor->HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor [%s] has Authority"), *Actor->GetName());	
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor [%s] does not has Authority"), *Actor->GetName());	
	}

	switch (Actor->GetLocalRole())
	{
	case ROLE_None:
		UE_LOG(LogTemp, Warning, TEXT("Actor [%s] Local Role: ROLE_None"), *Actor->GetName());
		break;
	case ROLE_SimulatedProxy:
		UE_LOG(LogTemp, Warning, TEXT("Actor [%s] Local Role: ROLE_SimulatedProxy"), *Actor->GetName());
		break;
	case ROLE_AutonomousProxy:
		UE_LOG(LogTemp, Warning, TEXT("Actor [%s] Local Role: ROLE_AutonomousProxy"), *Actor->GetName());
		break;
	case ROLE_Authority:
		UE_LOG(LogTemp, Warning, TEXT("Actor [%s] Local Role: ROLE_Authority"), *Actor->GetName());
		break;
	default:
		UE_LOG(LogTemp, Warning, TEXT("Actor [%s] Local Role: Unknown"), *Actor->GetName());
		break;
	}

}

void UMP_MultiplayerUtils::PrintRemoteNetRole(AActor* Actor)
{
	switch (Actor->GetRemoteRole())
	{
	case ROLE_None:
		UE_LOG(LogTemp, Warning, TEXT("Actor [%s] Remote Role: ROLE_None"), *Actor->GetName());
		break;
	case ROLE_SimulatedProxy:
		UE_LOG(LogTemp, Warning, TEXT("Actor [%s] Remote Role: ROLE_SimulatedProxy"), *Actor->GetName());
		break;
	case ROLE_AutonomousProxy:
		UE_LOG(LogTemp, Warning, TEXT("Actor [%s] Remote Role: ROLE_AutonomousProxy"), *Actor->GetName());
		break;
	case ROLE_Authority:
		UE_LOG(LogTemp, Warning, TEXT("Actor [%s] Remote Role: ROLE_Authority"), *Actor->GetName());
		break;
	default:
		UE_LOG(LogTemp, Warning, TEXT("Actor [%s] Remote Role: Unknown"), *Actor->GetName());
		break;
	}
}

