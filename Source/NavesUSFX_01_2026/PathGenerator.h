#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lista.h"
#include "PathGenerator.generated.h"

UCLASS()
class NAVESUSFX_01_2026_API APathGenerator : public AActor
{
    GENERATED_BODY()

public:
    APathGenerator();

protected:
    virtual void BeginPlay() override;

private:
    
    UPROPERTY(VisibleAnywhere, Category = "Visual")
    UStaticMeshComponent* MiMeshVisual;
    

    
    Lista<AActor*> MiListaDeCamino;

    UPROPERTY(EditAnywhere, Category = "Configuracion")
    int32 NumeroDeBloques = 10;

    UPROPERTY(EditAnywhere, Category = "Configuracion")
    float Espaciado = 250.0f;

    void ConstruirCamino();
};
