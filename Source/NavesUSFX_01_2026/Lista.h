#pragma once

#include "CoreMinimal.h"

template <typename T>
class Nodo {
public:
    T Dato;
    Nodo<T>* Siguiente;

    Nodo(T _Dato) : Dato(_Dato), Siguiente(nullptr) {}
};

template <typename T>
class Lista {
private:
    Nodo<T>* Cabeza;
    Nodo<T>* Cola;
    int32 Tamano;

public:
    Lista() : Cabeza(nullptr), Cola(nullptr), Tamano(0) {}

    ~Lista() { Limpiar(); }

    void InsertarAlFinal(T _Dato) {
        Nodo<T>* Nuevo = new Nodo<T>(_Dato);
        if (!Cabeza) {
            Cabeza = Cola = Nuevo;
        }
        else {
            Cola->Siguiente = Nuevo;
            Cola = Nuevo;
        }
        Tamano++;
    }

    void Limpiar() {
        while (Cabeza != nullptr) {
            Nodo<T>* Temp = Cabeza;
            Cabeza = Cabeza->Siguiente;
            delete Temp;
        }
        Cola = nullptr;
        Tamano = 0;
    }

    int32 GetTamano() const { return Tamano; }

    
    Nodo<T>* GetCabeza() const { return Cabeza; }
};