#pragma once
#include "PilaNums.h"
using namespace System;

ref class Pila
{
public:
	Numero^ primera;
public:
	int peek();
	void MeterNumero(int valor);
	int SacarNumero();
	bool vacio();
	void MostrarPila();
};

