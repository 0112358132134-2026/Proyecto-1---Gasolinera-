#include "pch.h"
#include "Pila.h"

void Pila::MeterNumero(int valor)
{
	Numero^ nuevoNumero = gcnew Numero;
	nuevoNumero->valor = valor;
	nuevoNumero->siguiente = primera;
	primera = nuevoNumero;
}

int Pila::SacarNumero()
{
	if (vacio())
	{
		return 0;
	}
	else
	{
		int valorR = primera->valor;
		Numero^ borrar = primera;
		primera = primera->siguiente;
		delete borrar;
		return valorR;
	}
}

bool Pila::vacio()
{
	return primera == nullptr;
}

int Pila::peek()
{
	if (!vacio())
	{
		return primera->valor;
	}
	else
	{
		return 0;
	}
}

void Pila::MostrarPila()
{
	String^ texto = "";
	Numero^ tmp = Pila::primera;
	while (tmp != nullptr)
	{
		texto = tmp->valor + "";
		tmp = tmp->siguiente;
		Console::WriteLine(texto);
	}
}