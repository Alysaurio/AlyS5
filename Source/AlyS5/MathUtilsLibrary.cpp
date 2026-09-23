// Fill out your copyright notice in the Description page of Project Settings.


#include "MathUtilsLibrary.h"

// MathUtilsLibrary.cpp
float UMathUtilsLibrary::SumarNumeros(float A, float B) { return A + B; }
FVector UMathUtilsLibrary::SumarVectores(FVector A, FVector B) { return A + B; }
FVector UMathUtilsLibrary::ProductoCruz(FVector A, FVector B) { return FVector::CrossProduct(A, B); }
float UMathUtilsLibrary::DistanciaVectores(FVector A, FVector B) { return FVector::Dist(A, B); }