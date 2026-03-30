#include "PathGenerator.h"
#include "BloqueCamino.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

APathGenerator::APathGenerator()
{
    PrimaryActorTick.bCanEverTick = false;

    MiMeshVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshPropio"));
    RootComponent = MiMeshVisual;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CuboAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
    if (CuboAsset.Succeeded())
    {
        MiMeshVisual->SetStaticMesh(CuboAsset.Object);
    }
}

void APathGenerator::BeginPlay()
{
    Super::BeginPlay();
    ConstruirCamino();
}

void APathGenerator::ConstruirCamino()
{
    FVector UbicacionActual = GetActorLocation() + (GetActorForwardVector() * Espaciado);
    FRotator RotacionActual = GetActorRotation();

    MiListaDeCamino.InsertarAlFinal(this);

    for (int32 i = 1; i < NumeroDeBloques; i++)
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        ABloqueCamino* BloqueNuevo = GetWorld()->SpawnActor<ABloqueCamino>(
            ABloqueCamino::StaticClass(),
            UbicacionActual,
            RotacionActual,
            SpawnParams
        );

        if (BloqueNuevo)
        {
            MiListaDeCamino.InsertarAlFinal(BloqueNuevo);

            UE_LOG(LogTemp, Log, TEXT("Bloque %d en: %s"), i, *UbicacionActual.ToString());

            UbicacionActual += GetActorForwardVector() * Espaciado;
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("No se pudo spawnear bloque %d"), i);
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("TOTAL LISTA: %d"), MiListaDeCamino.GetTamano());
}

