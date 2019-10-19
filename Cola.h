#pragma once
#include "ColaNums.h"
using namespace System;

ref class Cola
{
public:
	Numero2^ primera;
	Numero2^ ultima;
public:
	void MeterNumero(int valor);
	int SacarNumero();
	int peek();
	bool vacio();
	void MostrarCola();
};

