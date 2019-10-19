#include "pch.h"
#include "Cola.h"

void Cola::MeterNumero(int valor)
{
	Numero2^ nuevoNumero = gcnew Numero2;
	nuevoNumero->valor = valor;
	nuevoNumero->siguiente = nullptr;

	if (vacio())
	{
		primera = nuevoNumero;
	}
	else
	{
		ultima->siguiente = nuevoNumero;
	}
	ultima = nuevoNumero;
}

int Cola::SacarNumero()
{
	if (vacio())
	{
		return 0;
	}
	else
	{
		int valorR = primera->valor;
		Numero2^ borrar = primera;
		primera = primera->siguiente;
		delete borrar;
		return valorR;
	}
}

bool Cola::vacio()
{
	return primera == nullptr;
}

int Cola::peek()
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

void Cola::MostrarCola()
{
	String^ texto = "";
	Numero2^ tmp = Cola::primera;
	while (tmp != nullptr)
	{
		texto = tmp->valor + "";
		tmp = tmp->siguiente;
		Console::WriteLine(texto);
	}
}

