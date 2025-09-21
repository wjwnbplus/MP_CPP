// Fill out your copyright notice in the Description page of Project Settings.


#include "MP_Armor.h"

#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"


// Sets default values
AMP_Armor::AMP_Armor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	SetReplicatingMovement(true);

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("Root"));

	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>("SphereMesh");
	SphereMesh->SetupAttachment(RootComponent);
	SphereMesh->SetIsReplicated(true);

	SphereCollision = CreateDefaultSubobject<USphereComponent>("SphereCollision");
	SphereCollision->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void AMP_Armor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMP_Armor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMP_Armor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	ACharacter* OverlapCharacter = Cast<ACharacter>(OtherActor);

	if (HasAuthority()&&IsValid(OverlapCharacter))
	{
		SphereMesh->AttachToComponent(OverlapCharacter->GetMesh(),FAttachmentTransformRules::SnapToTargetNotIncludingScale,"Head");
	}

}

