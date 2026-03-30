#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BloqueCamino.generated.h"

UCLASS()
class NAVESUSFX_01_2026_API ABloqueCamino : public AActor
{
    GENERATED_BODY()

public:
    ABloqueCamino();

private:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* Mesh;
};
