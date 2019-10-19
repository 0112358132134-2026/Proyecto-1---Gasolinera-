#include "pch.h"
#include "Pila.h"
#include "Cola.h"
#include "cstdlib"
#include <exception>
using namespace std;
using namespace System;

void MostrarPilaCola(Pila^ pila)
{
	pila->MostrarPila();
	//cola->MostrarCola();
}
int static DividirEnteros(int n)
{
	String^ num = n.ToString();
	String^ num1 = num->Substring(0, 2);
	int numero = Int32::Parse(num1);
	return numero;
}
int static DividirDecimales(int n)
{
	String^ num = n.ToString();
	String^ num1 = num->Substring(2, 2);
	int numero = Int32::Parse(num1);
	return numero;
}
//
class NodoLista
{
public:
	int valor;
	NodoLista* next;
	NodoLista* prev;
};

class LinkedList
{
private:
	NodoLista* header;
	NodoLista* trailer;
public:
	LinkedList();
	~LinkedList();
	int getFront() const;
	int getback() const;
	void addFront(int n);
	void addBack(int n);
	void removeFront();
	void removeBack();
	void printReverse();
	void printForeward();
};

LinkedList::LinkedList()
{
	header = new NodoLista;
	trailer = new NodoLista;
	header->next = trailer;
	trailer->prev = nullptr;
	trailer->next = nullptr;
}
int LinkedList::getFront() const
{
	return header->next->valor;
}
int LinkedList::getback() const
{
	return trailer->prev->valor;
}
void LinkedList::addFront(int n)
{
	NodoLista* nd = new NodoLista;
	nd->valor = n;
	nd->prev = header;
	nd->next = header->next;

	header->next->prev = nd;
	header->next = nd;
}
void LinkedList::addBack(int n)
{
	NodoLista* nd = new NodoLista;
	nd->valor = n;
	nd->prev = trailer->prev;
	nd->next = trailer;

	trailer->prev->next = nd;
	trailer->prev = nd;
}
void LinkedList::removeFront()
{
	NodoLista* nd = header->next->next;
	delete header->next;
	header->next = nd;
	nd->prev = header;
}
void LinkedList::removeBack()
{
	NodoLista* nd = trailer->prev->prev;
	delete trailer->prev;
	trailer->prev = nd;
	nd->next = trailer;
}
void LinkedList::printReverse()
{
	NodoLista* nd = trailer->prev;
	while (nd!=header)
	{
		Console::WriteLine(nd->valor + " ");
		nd = nd->prev;
	}
}
void LinkedList::printForeward()
{
	NodoLista* nd = header->next;
	while (nd != trailer)
	{
		Console::WriteLine(nd->valor + " ");
		nd = nd->next;
	}
}
LinkedList::~LinkedList()
{
	while (header->next != trailer)
	{
		removeFront();
	}
	delete header;
	delete trailer;
}

int main(array<System::String ^> ^args)
{
	Console::BackgroundColor = ConsoleColor::Red;
	Console::ForegroundColor = ConsoleColor::Cyan;
	Console::Clear();

	int contadorPrecio = 0;
	int numeroDeRepeticion = 0;
	bool encontrado = false;

	Pila NuevaPila1;
	Cola NuevaCola1;

	//Primer Precio
	Pila AuxPila1;
	Pila AuxPila2;
	Cola AuxCola1;
	Cola AuxCola2;
	//Segundo Precio
	Pila AuxPila5;
	Pila AuxPila6;
	Cola AuxCola5;
	Cola AuxCola6;
	//Tercer Precio
	Pila AuxPila7;
	Pila AuxPila8;
	Cola AuxCola7;
	Cola AuxCola8;

	//Para precio 1
	LinkedList ListaNums;
	LinkedList ListaNums2;

	//Para precio 2
	LinkedList ListaNums1;
	LinkedList ListaNums22;

	//Para precio 3
	LinkedList ListaNums11;
	LinkedList ListaNums222;
	
	for (int i = 0; i <= 9; i++)
	{
		NuevaPila1.MeterNumero(i);
		NuevaCola1.MeterNumero(i);
	}

	bool terminar = false;
	while (terminar == false)
	{
		bool confirmar = false, valido = false;
		int n1, n2, n3 = 10, n4 = 10;
		String^ letra;

		while (valido == false)
		{
			Console::WriteLine("Ingrese un precio de 4 dígitos:");
			try
			{
				n1 = int::Parse(Console::ReadLine());
				if (n1 > 1000 && n1 < 10000)
				{
					valido = true;
				}
				else
				{
					Console::WriteLine("Ingrese un precio de los dígitos correctos.");
					valido = false;
				}
			}
			catch (...)
			{
				Console::WriteLine("Ingrese un dígito.");
				valido = false;
			}
		}

		int P = DividirEnteros(n1);
		int P1 = DividirDecimales(n1);
		for (int i = 0; i < 2; i++)
		{
			n2 = P / n3;
			P = P % n3;
			n3 = n3 / 10;
			//
			switch (contadorPrecio)
			{
			case 0:
				ListaNums.addFront(n2);
				break;
			case 1:
				ListaNums1.addFront(n2);
				break;
			case 2:
				ListaNums11.addFront(n2);
				break;
			default:
				break;
			}
			//
		}
		for (int i = 0; i < 2; i++)
		{
			n2 = P1 / n4;
			P1 = P1 % n4;
			n4 = n4 / 10;
			//
			switch (contadorPrecio)
			{
			case 0:
				ListaNums2.addFront(n2);
				break;
			case 1:
				ListaNums22.addFront(n2);
				break;
			case 2:
				ListaNums222.addFront(n2);
				break;
			default:
				break;
			}
			//
		}
		Console::WriteLine("Precio valido ingresado.");
		Console::ReadKey();
		Console::Clear();

		//Primero van las variables
		//Aca va el llenado de la PILA y la COLA

		Console::WriteLine("Pila:");
		NuevaPila1.MostrarPila();
		Console::WriteLine("Cola:");
		NuevaCola1.MostrarCola();
		Console::ReadKey();
		Console::Clear();

		
		//Primer Numero
		int valor;
		switch (contadorPrecio)
		{
		case 0:
			valor = ListaNums.getback();
			break;
		case 1:
			valor = ListaNums1.getback();
			break;
		case 2:
			valor = ListaNums11.getback();
			break;
		default:
			break;
		}
		while (encontrado == false)
		{
			//Va a ver si lo encuentra en la pila
			while (NuevaPila1.vacio() == false)
			{
				if (NuevaPila1.primera->valor == valor)
				{
					switch (contadorPrecio)
					{
					case 0:
						AuxPila1.MeterNumero(NuevaPila1.SacarNumero());
						break;
					case 1:
						AuxPila5.MeterNumero(NuevaPila1.SacarNumero());
						break;
					case 2:
						AuxPila7.MeterNumero(NuevaPila1.SacarNumero());
						break;
					default:
						break;
					}
					encontrado = true;
				}
				else
				{
					if (NuevaPila1.primera->valor != valor)
					{
						switch (contadorPrecio)
						{
						case 0:
							AuxPila2.MeterNumero(NuevaPila1.SacarNumero());
							break;
						case 1:
							AuxPila6.MeterNumero(NuevaPila1.SacarNumero());
							break;
						case 2:
							AuxPila8.MeterNumero(NuevaPila1.SacarNumero());
							break;
						default:
							break;
						}
					}
				}
			}
			//Devuelve los numeros a la PILA
			switch (contadorPrecio)
			{
			case 0:
				if (AuxPila2.vacio() == false)
				{
					while (AuxPila2.vacio() == false)
					{
						NuevaPila1.MeterNumero(AuxPila2.SacarNumero());
					}
				}
				break;
			case 1:
				if (AuxPila6.vacio() == false)
				{
					while (AuxPila6.vacio() == false)
					{
						NuevaPila1.MeterNumero(AuxPila6.SacarNumero());
					}
				}
				break;
			case 2:
				if (AuxPila8.vacio() == false)
				{
					while (AuxPila8.vacio() == false)
					{
						NuevaPila1.MeterNumero(AuxPila8.SacarNumero());
					}
				}
				break;
			default:
				break;
			}
			
			//Si no lo encontro en la pila, vera si lo encuentra en la COLA
			if (encontrado == false)
			{
				while (NuevaCola1.vacio() == false)
				{
					if (NuevaCola1.primera->valor == valor)
					{
						switch (contadorPrecio)
						{
						case 0:
							AuxCola1.MeterNumero(NuevaCola1.SacarNumero());
							break;
						case 1:
							AuxCola5.MeterNumero(NuevaCola1.SacarNumero());
							break;
						case 2:
							AuxCola7.MeterNumero(NuevaCola1.SacarNumero());
							break;
						default:
							break;
						}
						encontrado = true;
					}
					else
					{
						if (NuevaCola1.primera->valor != valor)
						{
							switch (contadorPrecio)
							{
							case 0:
								AuxCola2.MeterNumero(NuevaCola1.SacarNumero());
								break;
							case 1:
								AuxCola6.MeterNumero(NuevaCola1.SacarNumero());
								break;
							case 2:
								AuxCola8.MeterNumero(NuevaCola1.SacarNumero());
								break;
							default:
								break;
							}
							
						}
					}
				}
				//Devuelve los numeros a la COLA
				switch (contadorPrecio)
				{
				case 0:
					if (AuxCola2.vacio() == false)
					{
						while (AuxCola2.vacio() == false)
						{
							NuevaCola1.MeterNumero(AuxCola2.SacarNumero());
						}
					}
					break;
				case 1:
					if (AuxCola6.vacio() == false)
					{
						while (AuxCola6.vacio() == false)
						{
							NuevaCola1.MeterNumero(AuxCola6.SacarNumero());
						}
					}
					break;
				case 2:
					if (AuxCola8.vacio() == false)
					{
						while (AuxCola8.vacio() == false)
						{
							NuevaCola1.MeterNumero(AuxCola8.SacarNumero());
						}
					}
					break;
				default:
					break;
				}
				
			}
			//Si no lo encuenta ni en la PILA, ni en la COLA
			if (encontrado == false)
			{
				if (valor == 9)
				{
					encontrado = true;
					//////NO SE PUEDE FORMAR EL PRECIO
				}
				if (valor >= 0 || valor < 9)
				{
					valor++;
				}
			}
		}
		encontrado = false;
		NuevaPila1.MostrarPila();
		Console::ReadLine();
		NuevaCola1.MostrarCola();
		Console::ReadKey();
		Console::Clear();

		//Segundo Numero
		int valor1;
		switch (contadorPrecio)
		{
		case 0:
			valor1 = ListaNums.getFront();
			break;
		case 1:
			valor1 = ListaNums1.getFront();
			break;
		case 2:
			valor1 = ListaNums11.getFront();
			break;
		default:
			break;
		}
		while (encontrado == false)
		{
			//Va a ver si lo encuentra en la pila
			while (NuevaPila1.vacio() == false)
			{
				if (NuevaPila1.primera->valor == valor1)
				{
					switch (contadorPrecio)
					{
					case 0:
						AuxPila1.MeterNumero(NuevaPila1.SacarNumero());
						break;
					case 1:
						AuxPila5.MeterNumero(NuevaPila1.SacarNumero());
						break;
					case 2:
						AuxPila7.MeterNumero(NuevaPila1.SacarNumero());
						break;
					default:
						break;
					}
					encontrado = true;
				}
				else
				{
					if (NuevaPila1.primera->valor != valor1)
					{
						switch (contadorPrecio)
						{
						case 0:
							AuxPila2.MeterNumero(NuevaPila1.SacarNumero());
							break;
						case 1:
							AuxPila6.MeterNumero(NuevaPila1.SacarNumero());
							break;
						case 2:
							AuxPila8.MeterNumero(NuevaPila1.SacarNumero());
							break;
						default:
							break;
						}
					}
				}
			}
			//Devuelve los numeros a la PILA
			switch (contadorPrecio)
			{
			case 0:
				if (AuxPila2.vacio() == false)
				{
					while (AuxPila2.vacio() == false)
					{
						NuevaPila1.MeterNumero(AuxPila2.SacarNumero());
					}
				}			
				break;
			case 1:
				if (AuxPila6.vacio() == false)
				{
					while (AuxPila6.vacio() == false)
					{
						NuevaPila1.MeterNumero(AuxPila6.SacarNumero());
					}
				}
				break;
			case 2:
				if (AuxPila8.vacio() == false)
				{
					while (AuxPila8.vacio() == false)
					{
						NuevaPila1.MeterNumero(AuxPila8.SacarNumero());
					}
				}				
				break;
			default:
				break;
			}
			//Si no lo encontro en la pila, vera si lo encuentra en la COLA
			if (encontrado == false)
			{
				while (NuevaCola1.vacio() == false)
				{
					if (NuevaCola1.primera->valor == valor1)
					{
						switch (contadorPrecio)
						{
						case 0:
							AuxCola1.MeterNumero(NuevaCola1.SacarNumero());
							break;
						case 1:
							AuxCola5.MeterNumero(NuevaCola1.SacarNumero());
							break;
						case 2:
							AuxCola7.MeterNumero(NuevaCola1.SacarNumero());
							break;
						default:
							break;
						}
						encontrado = true;
					}
					else
					{
						if (NuevaCola1.primera->valor != valor1)
						{
							switch (contadorPrecio)
							{
							case 0:
								AuxCola2.MeterNumero(NuevaCola1.SacarNumero());
								break;
							case 1:
								AuxCola6.MeterNumero(NuevaCola1.SacarNumero());
								break;
							case 2:
								AuxCola8.MeterNumero(NuevaCola1.SacarNumero());
								break;
							default:
								break;
							}
						}
					}
				}
				//Devuelve los numeros a la COLA
				switch (contadorPrecio)
				{
				case 0:
					if (AuxCola2.vacio() == false)
					{
						while (AuxCola2.vacio() == false)
						{
							NuevaCola1.MeterNumero(AuxCola2.SacarNumero());
						}
					}					
					break;
				case 1:
					if (AuxCola6.vacio() == false)
					{
						while (AuxCola6.vacio() == false)
						{
							NuevaCola1.MeterNumero(AuxCola6.SacarNumero());
						}
					}					
					break;
				case 2:
					if (AuxCola8.vacio() == false)
					{
						while (AuxCola8.vacio() == false)
						{
							NuevaCola1.MeterNumero(AuxCola8.SacarNumero());
						}
					}					
					break;
				default:
					break;
				}	
			}
			//Si no lo encuenta ni en la PILA, ni en la COLA
			if (encontrado == false)
			{
				if (valor1 == 9)
				{
					encontrado = true;
					//////NO SE PUEDE FORMAR EL PRECIO
				}
				if (valor1 >= 0 || valor1 < 9)
				{
					valor1++;
				}
			}
		}
		encontrado = false;
		NuevaPila1.MostrarPila();
		Console::ReadLine();
		NuevaCola1.MostrarCola();
		Console::ReadKey();
		Console::Clear();

		//Tercer Numero
		int valor2;
		switch (contadorPrecio)
		{
		case 0:
			valor2 = ListaNums2.getback();
			break;
		case 1:
			valor2 = ListaNums22.getback();
			break;
		case 2:
			valor2 = ListaNums222.getback();
			break;
		default:
			break;
		}
		while (encontrado == false)
		{
			//Va a ver si lo encuentra en la pila
			while (NuevaPila1.vacio() == false)
			{
				if (NuevaPila1.primera->valor == valor2)
				{
					switch (contadorPrecio)
					{
					case 0:
						AuxPila1.MeterNumero(NuevaPila1.SacarNumero());
						break;
					case 1:
						AuxPila5.MeterNumero(NuevaPila1.SacarNumero());
						break;
					case 2:
						AuxPila7.MeterNumero(NuevaPila1.SacarNumero());
						break;
					default:
						break;
					}
					encontrado = true;
				}
				else
				{
					if (NuevaPila1.primera->valor != valor2)
					{
						switch (contadorPrecio)
						{
						case 0:
							AuxPila2.MeterNumero(NuevaPila1.SacarNumero());
							break;
						case 1:
							AuxPila6.MeterNumero(NuevaPila1.SacarNumero());
							break;
						case 2:
							AuxPila8.MeterNumero(NuevaPila1.SacarNumero());
							break;
						default:
							break;
						}
					}
				}
			}
			//Devuelve los numeros a la PILA
			switch (contadorPrecio)
			{
			case 0:
				if (AuxPila2.vacio() == false)
				{
					while (AuxPila2.vacio() == false)
					{
						NuevaPila1.MeterNumero(AuxPila2.SacarNumero());
					}
				}
				break;
			case 1:
				if (AuxPila6.vacio() == false)
				{
					while (AuxPila6.vacio() == false)
					{
						NuevaPila1.MeterNumero(AuxPila6.SacarNumero());
					}
				}				
				break;
			case 2:
				if (AuxPila8.vacio() == false)
				{
					while (AuxPila8.vacio() == false)
					{
						NuevaPila1.MeterNumero(AuxPila8.SacarNumero());
					}
				}
				break;
			default:
				break;
			}
			
			//Si no lo encontro en la pila, vera si lo encuentra en la COLA
			if (encontrado == false)
			{
				while (NuevaCola1.vacio() == false)
				{
					if (NuevaCola1.primera->valor == valor2)
					{
						switch (contadorPrecio)
						{
						case 0:
							AuxCola1.MeterNumero(NuevaCola1.SacarNumero());
							break;
						case 1:
							AuxCola5.MeterNumero(NuevaCola1.SacarNumero());
							break;
						case 2:
							AuxCola7.MeterNumero(NuevaCola1.SacarNumero());
							break;
						default:
							break;
						}
						encontrado = true;
					}
					else
					{
						if (NuevaCola1.primera->valor != valor2)
						{
							switch (contadorPrecio)
							{
							case 0:
								AuxCola2.MeterNumero(NuevaCola1.SacarNumero());
								break;
							case 1:
								AuxCola6.MeterNumero(NuevaCola1.SacarNumero());
								break;
							case 2:
								AuxCola8.MeterNumero(NuevaCola1.SacarNumero());
								break;
							default:
								break;
							}
						}
					}
				}
				//Devuelve los numeros a la COLA
				switch (contadorPrecio)
				{
				case 0:
					if (AuxCola2.vacio() == false)
					{
						while (AuxCola2.vacio() == false)
						{
							NuevaCola1.MeterNumero(AuxCola2.SacarNumero());
						}
					}
					break;
				case 1:
					if (AuxCola6.vacio() == false)
					{
						while (AuxCola6.vacio() == false)
						{
							NuevaCola1.MeterNumero(AuxCola6.SacarNumero());
						}
					}
					break;
				case 2:
					if (AuxCola8.vacio() == false)
					{
						while (AuxCola8.vacio() == false)
						{
							NuevaCola1.MeterNumero(AuxCola8.SacarNumero());
						}
					}
					break;
				default:
					break;
				}
				
			}
			//Si no lo encuenta ni en la PILA, ni en la COLA
			if (encontrado == false)
			{
				if (valor2 == 9)
				{
					encontrado = true;
					//////NO SE PUEDE FORMAR EL PRECIO
				}
				if (valor2 >= 0 || valor2 < 9)
				{
					valor2++;
				}
			}
		}
		encontrado = false;
		NuevaPila1.MostrarPila();
		Console::ReadLine();
		NuevaCola1.MostrarCola();
		Console::ReadKey();
		Console::Clear();

		//Cuarto Numero
		int valor3;
		switch (contadorPrecio)
		{
		case 0:
			valor3 = ListaNums2.getFront();
			break;
		case 1:
			valor3 = ListaNums22.getFront();
			break;
		case 2:
			valor3 = ListaNums222.getFront();
			break;
		default:
			break;
		}
		while (encontrado == false)
		{
			//Va a ver si lo encuentra en la pila
			while (NuevaPila1.vacio() == false)
			{
				if (NuevaPila1.primera->valor == valor3)
				{
					switch (contadorPrecio)
					{
					case 0:
						AuxPila1.MeterNumero(NuevaPila1.SacarNumero());
						break;
					case 1:
						AuxPila5.MeterNumero(NuevaPila1.SacarNumero());
						break;
					case 2:
						AuxPila7.MeterNumero(NuevaPila1.SacarNumero());
						break;
					default:
						break;
					}
					encontrado = true;
				}
				else
				{
					if (NuevaPila1.primera->valor != valor3)
					{
						switch (contadorPrecio)
						{
						case 0:
							AuxPila2.MeterNumero(NuevaPila1.SacarNumero());
							break;
						case 1:
							AuxPila6.MeterNumero(NuevaPila1.SacarNumero());
							break;
						case 2:
							AuxPila8.MeterNumero(NuevaPila1.SacarNumero());
							break;
						default:
							break;
						}
					}
				}
			}
			//Devuelve los numeros a la PILA
			switch (contadorPrecio)
			{
			case 0:
				if (AuxPila2.vacio() == false)
				{
					while (AuxPila2.vacio() == false)
					{
						NuevaPila1.MeterNumero(AuxPila2.SacarNumero());
					}
				}
				break;
			case 1:
				if (AuxPila6.vacio() == false)
				{
					while (AuxPila6.vacio() == false)
					{
						NuevaPila1.MeterNumero(AuxPila6.SacarNumero());
					}
				}				break;
			case 2:
				if (AuxPila8.vacio() == false)
				{
					while (AuxPila8.vacio() == false)
					{
						NuevaPila1.MeterNumero(AuxPila8.SacarNumero());
					}
				}
				break;
			default:
				break;
			}
			
			//Si no lo encontro en la pila, vera si lo encuentra en la COLA
			if (encontrado == false)
			{
				while (NuevaCola1.vacio() == false)
				{
					if (NuevaCola1.primera->valor == valor3)
					{
						switch (contadorPrecio)
						{
						case 0:
							AuxCola1.MeterNumero(NuevaCola1.SacarNumero());
							break;
						case 1:
							AuxCola5.MeterNumero(NuevaCola1.SacarNumero());
							break;
						case 2:
							AuxCola7.MeterNumero(NuevaCola1.SacarNumero());
							break;
						default:
							break;
						}
						encontrado = true;
					}
					else
					{
						if (NuevaCola1.primera->valor != valor3)
						{
							switch (contadorPrecio)
							{
							case 0:
								AuxCola2.MeterNumero(NuevaCola1.SacarNumero());
								break;
							case 1:
								AuxCola6.MeterNumero(NuevaCola1.SacarNumero());
								break;
							case 2:
								AuxCola8.MeterNumero(NuevaCola1.SacarNumero());
								break;
							default:
								break;
							}
						}
					}
				}
				//Devuelve los numeros a la COLA
				switch (contadorPrecio)
				{
				case 0:
					if (AuxCola2.vacio() == false)
					{
						while (AuxCola2.vacio() == false)
						{
							NuevaCola1.MeterNumero(AuxCola2.SacarNumero());
						}
					}
					break;
				case 1:
					if (AuxCola6.vacio() == false)
					{
						while (AuxCola6.vacio() == false)
						{
							NuevaCola1.MeterNumero(AuxCola6.SacarNumero());
						}
					}
					break;
				case 2:
					if (AuxCola8.vacio() == false)
					{
						while (AuxCola8.vacio() == false)
						{
							NuevaCola1.MeterNumero(AuxCola8.SacarNumero());
						}
					}
					break;
				default:
					break;
				}
				
			}
			//Si no lo encuenta ni en la PILA, ni en la COLA
			if (encontrado == false)
			{
				if (valor3 == 9)
				{
					encontrado = true;
					//////NO SE PUEDE FORMAR EL PRECIO
				}
				if (valor3 >= 0 || valor3 < 9)
				{
					valor3++;
				}
			}
		}
		encontrado = false;
		NuevaPila1.MostrarPila();
		Console::ReadLine();
		NuevaCola1.MostrarCola();
		Console::ReadKey();
		Console::Clear();

		/*
		//ORDENAR PILA	
		Pila ordenar1;
		Pila ordenar2;
		int contador = 9;
		if (NuevaPila1.vacio() == false)
		{
			while (contador > 0)
			{
				if (NuevaPila1.primera->valor == contador)
				{
					ordenar2.MeterNumero(NuevaPila1.SacarNumero());
					contador--;
					if (ordenar1.vacio() == false)
					{
						while (ordenar1.vacio() == false)
						{
							NuevaPila1.MeterNumero(ordenar1.SacarNumero());
						}
					}
				}
				else
				{
					if (NuevaPila1.primera->valor != contador)
					{
						ordenar1.MeterNumero(NuevaPila1.SacarNumero());
					}
				}
			}
		}
		while (ordenar2.vacio() == false)
		{
			NuevaPila1.MeterNumero(ordenar2.SacarNumero());
		}
		//FIN DE ORDENAR PILA

		//ORDENAR COLA	
		Cola ordenar3;
		Cola ordenar4;
		int contador1 = 0;
		if (NuevaCola1.vacio() == false)
		{
			while (contador1 < 9)
			{
				if (NuevaCola1.primera->valor == contador1)
				{
					ordenar4.MeterNumero(NuevaCola1.SacarNumero());						
					contador1++;
					if (ordenar3.vacio() == false)
					{
						while (ordenar3.vacio() == false)
						{
							NuevaPila1.MeterNumero(ordenar3.SacarNumero());
						}
					}
				}
				else
				{
					if (NuevaCola1.primera->valor != contador1)
					{
						ordenar3.MeterNumero(NuevaCola1.SacarNumero());
					}
				}
			}								
		}
		if (ordenar4.vacio() == false)
		{
			while (ordenar4.vacio() == false)
			{
				NuevaCola1.MeterNumero(ordenar4.SacarNumero());
			}
		}
		//FIN DE ORDENAR COLA
		*/

		String^ otroPrecio = "";
		String^ salir = "";
		String^ borrarPrecio = "";
		String^ ordenarPilaCola = "";
		
		if (contadorPrecio < 2)
		{
			Console::WriteLine("¿Desea ingresar otro precio? (Si/No)");
			otroPrecio = Console::ReadLine();
			if (otroPrecio == "Si" || otroPrecio == "si")
			{
				contadorPrecio++;	
			}
			else
			{
				if (otroPrecio == "No" || otroPrecio == "no")
				{
					Console::WriteLine("¿Desea terminar la simulación? (Si/No)");
					salir = Console::ReadLine();
					if (salir == "Si" || salir == "si")
					{
						terminar = true;
					}
					else
					{
						if (salir == "No" || salir == "no")
						{
							Console::WriteLine("¿Quiere borrar algún precio?");
							borrarPrecio = Console::ReadLine();
							if (borrarPrecio == "Si" || borrarPrecio == "si")
							{
								String^ borrarPrecio = "";
								switch (contadorPrecio)
								{
								case 0:
									Console::WriteLine("El precio que se tiene es: ");
									ListaNums.printReverse();
									ListaNums2.printReverse();
									Console::WriteLine("¿Quiere borrar todo el precio o solo el último dígito? (Todo/Ultimo)");
									borrarPrecio = Console::ReadLine();
									
									if (borrarPrecio == "Todo" || borrarPrecio == "todo")
									{
										if (AuxPila1.vacio() == false)
										{
											while (AuxPila1.vacio() == false)
											{
												NuevaPila1.MeterNumero(AuxPila1.SacarNumero());
											}
										}
										if (AuxCola1.vacio() == false)
										{
											while (AuxCola1.vacio() == false)
											{
												NuevaCola1.MeterNumero(AuxCola1.SacarNumero());
											}
										}
										Console::WriteLine("Pila");
										NuevaPila1.MostrarPila();
										Console::WriteLine("Cola");
										NuevaCola1.MostrarCola();
									}
									else
									{
										if (borrarPrecio == "Ultimo" || borrarPrecio == "ultimo")
										{
											//En la listanum2 , borrar el frente
											bool encontrado1 = false;
											Pila AuxPila3;
											Pila AuxPila4;
											Cola AuxCola3;
											Cola AuxCola4;
											int valor = ListaNums2.getFront();
											while (encontrado1 == false)
											{
												//Va a ver si lo encuentra en la pila
												while (AuxPila1.vacio() == false)
												{
													if (AuxPila1.primera->valor == valor)
													{
														AuxPila3.MeterNumero(AuxPila1.SacarNumero());
														encontrado1 = true;
													}
													else
													{
														if (AuxPila1.primera->valor != valor)
														{
															AuxPila4.MeterNumero(AuxPila1.SacarNumero());
														}
													}
												}
												//Devuelve los numeros a la PILA
												if (AuxPila4.vacio() == false)
												{
													while (AuxPila4.vacio() == false)
													{
														AuxPila1.MeterNumero(AuxPila4.SacarNumero());
													}
												}
												//Si no lo encontro en la pila, vera si lo encuentra en la COLA
												if (encontrado1 == false)
												{
													while (AuxCola1.vacio() == false)
													{
														if (AuxCola1.primera->valor == valor)
														{
															AuxCola3.MeterNumero(AuxCola1.SacarNumero());
															encontrado1 = true;
														}
														else
														{
															if (AuxCola1.primera->valor != valor)
															{
																AuxCola4.MeterNumero(AuxCola1.SacarNumero());
															}
														}
													}
													//Devuelve los numeros a la COLA
													if (AuxCola4.vacio() == false)
													{
														while (AuxCola4.vacio() == false)
														{
															AuxCola1.MeterNumero(AuxCola4.SacarNumero());
														}
													}
												}
											}
											encontrado1 = false;
											if (AuxPila3.vacio() == false)
											{
												NuevaPila1.MeterNumero(AuxPila3.SacarNumero());
											}
											if (AuxCola3.vacio() == false)
											{
												NuevaCola1.MeterNumero(AuxCola3.SacarNumero());
											}										
											Console::WriteLine("Pila");
											NuevaPila1.MostrarPila();
											Console::WriteLine("Cola");
											NuevaCola1.MostrarCola();
										}
									}
									//Borrar Todo
									Console::ReadLine();
									terminar = true;
									break;
								case 1:	
									Console::WriteLine("Los precios que se tienen son: ");
									Console::WriteLine("Primer precio: ");
									ListaNums.printReverse();
									ListaNums2.printReverse();
									Console::WriteLine("Segundo precio: ");
									ListaNums1.printReverse();
									ListaNums22.printReverse();
									
									int elegirPrecio;
									Console::WriteLine("¿Cuál precio desea borrar? (1/2)");
									elegirPrecio = int::Parse(Console::ReadLine());
									if (elegirPrecio == 1)
									{
										Console::WriteLine("¿Quiere borrar todo el precio 1 o solo el último dígito? (Todo/Ultimo)");
										borrarPrecio = Console::ReadLine();

										if (borrarPrecio == "Todo" || borrarPrecio == "todo")
										{
											if (AuxPila1.vacio() == false)
											{
												while (AuxPila1.vacio() == false)
												{
													NuevaPila1.MeterNumero(AuxPila1.SacarNumero());
												}
											}
											if (AuxCola1.vacio() == false)
											{
												while (AuxCola1.vacio() == false)
												{
													NuevaCola1.MeterNumero(AuxCola1.SacarNumero());
												}
											}
											Console::WriteLine("Pila");
											NuevaPila1.MostrarPila();
											Console::WriteLine("Cola");
											NuevaCola1.MostrarCola();
										}
										else
										{
											if (borrarPrecio == "Ultimo" || borrarPrecio == "ultimo")
											{
												//En la listanum2 , borrar el frente
												bool encontrado1 = false;
												Pila AuxPila3;
												Pila AuxPila4;
												Cola AuxCola3;
												Cola AuxCola4;
												int valor = ListaNums2.getFront();
												while (encontrado1 == false)
												{
													//Va a ver si lo encuentra en la pila
													while (AuxPila1.vacio() == false)
													{
														if (AuxPila1.primera->valor == valor)
														{
															AuxPila3.MeterNumero(AuxPila1.SacarNumero());
															encontrado1 = true;
														}
														else
														{
															if (AuxPila1.primera->valor != valor)
															{
																AuxPila4.MeterNumero(AuxPila1.SacarNumero());
															}
														}
													}
													//Devuelve los numeros a la PILA
													if (AuxPila4.vacio() == false)
													{
														while (AuxPila4.vacio() == false)
														{
															AuxPila1.MeterNumero(AuxPila4.SacarNumero());
														}
													}
													//Si no lo encontro en la pila, vera si lo encuentra en la COLA
													if (encontrado1 == false)
													{
														while (AuxCola1.vacio() == false)
														{
															if (AuxCola1.primera->valor == valor)
															{
																AuxCola3.MeterNumero(AuxCola1.SacarNumero());
																encontrado1 = true;
															}
															else
															{
																if (AuxCola1.primera->valor != valor)
																{
																	AuxCola4.MeterNumero(AuxCola1.SacarNumero());
																}
															}
														}
														//Devuelve los numeros a la COLA
														if (AuxCola4.vacio() == false)
														{
															while (AuxCola4.vacio() == false)
															{
																AuxCola1.MeterNumero(AuxCola4.SacarNumero());
															}
														}
													}
												}
												encontrado1 = false;
												if (AuxPila3.vacio() == false)
												{
													NuevaPila1.MeterNumero(AuxPila3.SacarNumero());
												}
												if (AuxCola3.vacio() == false)
												{
													NuevaCola1.MeterNumero(AuxCola3.SacarNumero());
												}
												Console::WriteLine("Pila");
												NuevaPila1.MostrarPila();
												Console::WriteLine("Cola");
												NuevaCola1.MostrarCola();
											}
										}
									}
									if (elegirPrecio == 2)
									{
										Console::WriteLine("¿Quiere borrar todo el precio 2 o solo el último dígito? (Todo/Ultimo)");
										borrarPrecio = Console::ReadLine();

										if (borrarPrecio == "Todo" || borrarPrecio == "todo")
										{
											if (AuxPila5.vacio() == false)
											{
												while (AuxPila5.vacio() == false)
												{
													NuevaPila1.MeterNumero(AuxPila5.SacarNumero());
												}
											}
											if (AuxCola5.vacio() == false)
											{
												while (AuxCola5.vacio() == false)
												{
													NuevaCola1.MeterNumero(AuxCola5.SacarNumero());
												}
											}
											Console::WriteLine("Pila");
											NuevaPila1.MostrarPila();
											Console::WriteLine("Cola");
											NuevaCola1.MostrarCola();
										}
										else
										{
											if (borrarPrecio == "Ultimo" || borrarPrecio == "ultimo")
											{
												//En la listanum2 , borrar el frente
												bool encontrado1 = false;
												Pila AuxPila9;
												Pila AuxPila10;
												Cola AuxCola9;
												Cola AuxCola10;
												int valor = ListaNums22.getFront();
												while (encontrado1 == false)
												{
													//Va a ver si lo encuentra en la pila
													while (AuxPila5.vacio() == false)
													{
														if (AuxPila5.primera->valor == valor)
														{
															AuxPila9.MeterNumero(AuxPila5.SacarNumero());
															encontrado1 = true;
														}
														else
														{
															if (AuxPila5.primera->valor != valor)
															{
																AuxPila10.MeterNumero(AuxPila5.SacarNumero());
															}
														}
													}
													//Devuelve los numeros a la PILA
													if (AuxPila10.vacio() == false)
													{
														while (AuxPila10.vacio() == false)
														{
															AuxPila5.MeterNumero(AuxPila10.SacarNumero());
														}
													}
													//Si no lo encontro en la pila, vera si lo encuentra en la COLA
													if (encontrado1 == false)
													{
														while (AuxCola5.vacio() == false)
														{
															if (AuxCola5.primera->valor == valor)
															{
																AuxCola9.MeterNumero(AuxCola5.SacarNumero());
																encontrado1 = true;
															}
															else
															{
																if (AuxCola5.primera->valor != valor)
																{
																	AuxCola10.MeterNumero(AuxCola5.SacarNumero());
																}
															}
														}
														//Devuelve los numeros a la COLA
														if (AuxCola10.vacio() == false)
														{
															while (AuxCola10.vacio() == false)
															{
																AuxCola5.MeterNumero(AuxCola10.SacarNumero());
															}
														}
													}
												}
												encontrado1 = false;
												if (AuxPila9.vacio() == false)
												{
													NuevaPila1.MeterNumero(AuxPila9.SacarNumero());
												}
												if (AuxCola9.vacio() == false)
												{
													NuevaCola1.MeterNumero(AuxCola9.SacarNumero());
												}
												Console::WriteLine("Pila");
												NuevaPila1.MostrarPila();
												Console::WriteLine("Cola");
												NuevaCola1.MostrarCola();
											}
										}
									}
									//Borrar Todo
									Console::ReadLine();
									terminar = true;
									break;
								case 2:
									Console::WriteLine("Los precios que se tienen son: ");
									Console::WriteLine("Primer precio: ");
									ListaNums.printReverse();
									ListaNums2.printReverse();
									Console::WriteLine("Segundo precio: ");
									ListaNums1.printReverse();
									ListaNums22.printReverse();
									Console::WriteLine("Tercer precio: ");
									ListaNums11.printReverse();
									ListaNums222.printReverse();

									int elegirPrecio1 = 0;
									Console::WriteLine("¿Cuál precio desea borrar? (1/2/3)");
									elegirPrecio1 = int::Parse(Console::ReadLine());
									if (elegirPrecio1 == 1)
									{
										Console::WriteLine("¿Quiere borrar todo el precio 1 o solo el último dígito? (Todo/Ultimo)");
										borrarPrecio = Console::ReadLine();

										if (borrarPrecio == "Todo" || borrarPrecio == "todo")
										{
											if (AuxPila1.vacio() == false)
											{
												while (AuxPila1.vacio() == false)
												{
													NuevaPila1.MeterNumero(AuxPila1.SacarNumero());
												}
											}
											if (AuxCola1.vacio() == false)
											{
												while (AuxCola1.vacio() == false)
												{
													NuevaCola1.MeterNumero(AuxCola1.SacarNumero());
												}
											}
											Console::WriteLine("Pila");
											NuevaPila1.MostrarPila();
											Console::WriteLine("Cola");
											NuevaCola1.MostrarCola();
										}
										else
										{
											if (borrarPrecio == "Ultimo" || borrarPrecio == "ultimo")
											{
												//En la listanum2 , borrar el frente
												bool encontrado1 = false;
												Pila AuxPila3;
												Pila AuxPila4;
												Cola AuxCola3;
												Cola AuxCola4;
												int valor = ListaNums2.getFront();
												while (encontrado1 == false)
												{
													//Va a ver si lo encuentra en la pila
													while (AuxPila1.vacio() == false)
													{
														if (AuxPila1.primera->valor == valor)
														{
															AuxPila3.MeterNumero(AuxPila1.SacarNumero());
															encontrado1 = true;
														}
														else
														{
															if (AuxPila1.primera->valor != valor)
															{
																AuxPila4.MeterNumero(AuxPila1.SacarNumero());
															}
														}
													}
													//Devuelve los numeros a la PILA
													if (AuxPila4.vacio() == false)
													{
														while (AuxPila4.vacio() == false)
														{
															AuxPila1.MeterNumero(AuxPila4.SacarNumero());
														}
													}
													//Si no lo encontro en la pila, vera si lo encuentra en la COLA
													if (encontrado1 == false)
													{
														while (AuxCola1.vacio() == false)
														{
															if (AuxCola1.primera->valor == valor)
															{
																AuxCola3.MeterNumero(AuxCola1.SacarNumero());
																encontrado1 = true;
															}
															else
															{
																if (AuxCola1.primera->valor != valor)
																{
																	AuxCola4.MeterNumero(AuxCola1.SacarNumero());
																}
															}
														}
														//Devuelve los numeros a la COLA
														if (AuxCola4.vacio() == false)
														{
															while (AuxCola4.vacio() == false)
															{
																AuxCola1.MeterNumero(AuxCola4.SacarNumero());
															}
														}
													}
												}
												encontrado1 = false;
												if (AuxPila3.vacio() == false)
												{
													NuevaPila1.MeterNumero(AuxPila3.SacarNumero());
												}
												if (AuxCola3.vacio() == false)
												{
													NuevaCola1.MeterNumero(AuxCola3.SacarNumero());
												}
												Console::WriteLine("Pila");
												NuevaPila1.MostrarPila();
												Console::WriteLine("Cola");
												NuevaCola1.MostrarCola();
											}
										}
									}
									if (elegirPrecio1 == 2)
									{
										Console::WriteLine("¿Quiere borrar todo el precio 2 o solo el último dígito? (Todo/Ultimo)");
										borrarPrecio = Console::ReadLine();

										if (borrarPrecio == "Todo" || borrarPrecio == "todo")
										{
											if (AuxPila5.vacio() == false)
											{
												while (AuxPila5.vacio() == false)
												{
													NuevaPila1.MeterNumero(AuxPila5.SacarNumero());
												}
											}
											if (AuxCola5.vacio() == false)
											{
												while (AuxCola5.vacio() == false)
												{
													NuevaCola1.MeterNumero(AuxCola5.SacarNumero());
												}
											}
											Console::WriteLine("Pila");
											NuevaPila1.MostrarPila();
											Console::WriteLine("Cola");
											NuevaCola1.MostrarCola();
										}
										else
										{
											if (borrarPrecio == "Ultimo" || borrarPrecio == "ultimo")
											{
												//En la listanum2 , borrar el frente
												bool encontrado1 = false;
												Pila AuxPila9;
												Pila AuxPila10;
												Cola AuxCola9;
												Cola AuxCola10;
												int valor = ListaNums22.getFront();
												while (encontrado1 == false)
												{
													//Va a ver si lo encuentra en la pila
													while (AuxPila5.vacio() == false)
													{
														if (AuxPila5.primera->valor == valor)
														{
															AuxPila9.MeterNumero(AuxPila5.SacarNumero());
															encontrado1 = true;
														}
														else
														{
															if (AuxPila5.primera->valor != valor)
															{
																AuxPila10.MeterNumero(AuxPila5.SacarNumero());
															}
														}
													}
													//Devuelve los numeros a la PILA
													if (AuxPila10.vacio() == false)
													{
														while (AuxPila10.vacio() == false)
														{
															AuxPila5.MeterNumero(AuxPila10.SacarNumero());
														}
													}
													//Si no lo encontro en la pila, vera si lo encuentra en la COLA
													if (encontrado1 == false)
													{
														while (AuxCola5.vacio() == false)
														{
															if (AuxCola5.primera->valor == valor)
															{
																AuxCola9.MeterNumero(AuxCola5.SacarNumero());
																encontrado1 = true;
															}
															else
															{
																if (AuxCola5.primera->valor != valor)
																{
																	AuxCola10.MeterNumero(AuxCola5.SacarNumero());
																}
															}
														}
														//Devuelve los numeros a la COLA
														if (AuxCola10.vacio() == false)
														{
															while (AuxCola10.vacio() == false)
															{
																AuxCola5.MeterNumero(AuxCola10.SacarNumero());
															}
														}
													}
												}
												encontrado1 = false;
												if (AuxPila9.vacio() == false)
												{
													NuevaPila1.MeterNumero(AuxPila9.SacarNumero());
												}
												if (AuxCola9.vacio() == false)
												{
													NuevaCola1.MeterNumero(AuxCola9.SacarNumero());
												}
												Console::WriteLine("Pila");
												NuevaPila1.MostrarPila();
												Console::WriteLine("Cola");
												NuevaCola1.MostrarCola();
											}
										}
									}
									if (elegirPrecio1 == 3)
									{
										Console::WriteLine("¿Quiere borrar todo el precio 3 o solo el último dígito? (Todo/Ultimo)");
										borrarPrecio = Console::ReadLine();

										if (borrarPrecio == "Todo" || borrarPrecio == "todo")
										{
											if (AuxPila7.vacio() == false)
											{
												while (AuxPila7.vacio() == false)
												{
													NuevaPila1.MeterNumero(AuxPila7.SacarNumero());
												}
											}
											if (AuxCola7.vacio() == false)
											{
												while (AuxCola7.vacio() == false)
												{
													NuevaCola1.MeterNumero(AuxCola7.SacarNumero());
												}
											}
											Console::WriteLine("Pila");
											NuevaPila1.MostrarPila();
											Console::WriteLine("Cola");
											NuevaCola1.MostrarCola();
										}
										else
										{
											if (borrarPrecio == "Ultimo" || borrarPrecio == "ultimo")
											{
												//En la listanum2 , borrar el frente
												bool encontrado1 = false;
												Pila AuxPila11;
												Pila AuxPila12;
												Cola AuxCola11;
												Cola AuxCola12;
												int valor = ListaNums222.getFront();
												while (encontrado1 == false)
												{
													//Va a ver si lo encuentra en la pila
													while (AuxPila7.vacio() == false)
													{
														if (AuxPila7.primera->valor == valor)
														{
															AuxPila11.MeterNumero(AuxPila7.SacarNumero());
															encontrado1 = true;
														}
														else
														{
															if (AuxPila7.primera->valor != valor)
															{
																AuxPila12.MeterNumero(AuxPila7.SacarNumero());
															}
														}
													}
													//Devuelve los numeros a la PILA
													if (AuxPila12.vacio() == false)
													{
														while (AuxPila12.vacio() == false)
														{
															AuxPila7.MeterNumero(AuxPila12.SacarNumero());
														}
													}
													//Si no lo encontro en la pila, vera si lo encuentra en la COLA
													if (encontrado1 == false)
													{
														while (AuxCola7.vacio() == false)
														{
															if (AuxCola7.primera->valor == valor)
															{
																AuxCola11.MeterNumero(AuxCola7.SacarNumero());
																encontrado1 = true;
															}
															else
															{
																if (AuxCola7.primera->valor != valor)
																{
																	AuxCola12.MeterNumero(AuxCola7.SacarNumero());
																}
															}
														}
														//Devuelve los numeros a la COLA
														if (AuxCola12.vacio() == false)
														{
															while (AuxCola12.vacio() == false)
															{
																AuxCola7.MeterNumero(AuxCola12.SacarNumero());
															}
														}
													}
												}
												encontrado1 = false;
												if (AuxPila11.vacio() == false)
												{
													NuevaPila1.MeterNumero(AuxPila11.SacarNumero());
												}
												if (AuxCola11.vacio() == false)
												{
													NuevaCola1.MeterNumero(AuxCola11.SacarNumero());
												}
												Console::WriteLine("Pila");
												NuevaPila1.MostrarPila();
												Console::WriteLine("Cola");
												NuevaCola1.MostrarCola();
											}
										}
									}
									//Borrar Todo
									Console::ReadLine();
									terminar = true;
									break;
								}
							}
							else
							{
								if (borrarPrecio == "No" || borrarPrecio == "No")
								{
									switch (contadorPrecio)
									{
									case 0:
										if (AuxPila1.vacio() == false)
										{
											while (AuxPila1.vacio() == false)
											{
												NuevaPila1.MeterNumero(AuxPila1.SacarNumero());
											}
										}
										if (AuxCola1.vacio() == false)
										{
											while (AuxCola1.vacio() == false)
											{
												NuevaCola1.MeterNumero(AuxCola1.SacarNumero());
											}
										}	

										ListaNums.removeBack();
										ListaNums.removeFront();
										ListaNums2.removeBack();
										ListaNums2.removeFront();

										break;
									case 1:
										if (AuxPila1.vacio() == false)
										{
											while (AuxPila1.vacio() == false)
											{
												NuevaPila1.MeterNumero(AuxPila1.SacarNumero());
											}
										}
										if (AuxCola1.vacio() == false)
										{
											while (AuxCola1.vacio() == false)
											{
												NuevaCola1.MeterNumero(AuxCola1.SacarNumero());
											}
										}
										if (AuxPila5.vacio() == false)
										{
											while (AuxPila5.vacio() == false)
											{
												NuevaPila1.MeterNumero(AuxPila5.SacarNumero());
											}
										}
										if (AuxCola5.vacio() == false)
										{
											while (AuxCola5.vacio() == false)
											{
												NuevaCola1.MeterNumero(AuxCola5.SacarNumero());
											}
										}

										ListaNums.removeBack();
										ListaNums.removeFront();
										ListaNums2.removeBack();
										ListaNums2.removeFront();
										ListaNums1.removeBack();
										ListaNums1.removeFront();
										ListaNums22.removeBack();
										ListaNums22.removeFront();

										break;
									case 2:
										if (AuxPila1.vacio() == false)
										{
											while (AuxPila1.vacio() == false)
											{
												NuevaPila1.MeterNumero(AuxPila1.SacarNumero());
											}
										}
										if (AuxCola1.vacio() == false)
										{
											while (AuxCola1.vacio() == false)
											{
												NuevaCola1.MeterNumero(AuxCola1.SacarNumero());
											}
										}
										if (AuxPila5.vacio() == false)
										{
											while (AuxPila5.vacio() == false)
											{
												NuevaPila1.MeterNumero(AuxPila5.SacarNumero());
											}
										}
										if (AuxCola5.vacio() == false)
										{
											while (AuxCola5.vacio() == false)
											{
												NuevaCola1.MeterNumero(AuxCola5.SacarNumero());
											}
										}
										if (AuxPila7.vacio() == false)
										{
											while (AuxPila7.vacio() == false)
											{
												NuevaPila1.MeterNumero(AuxPila7.SacarNumero());
											}
										}
										if (AuxCola7.vacio() == false)
										{
											while (AuxCola7.vacio() == false)
											{
												NuevaCola1.MeterNumero(AuxCola7.SacarNumero());
											}
										}

										ListaNums.removeBack();
										ListaNums.removeFront();
										ListaNums2.removeBack();
										ListaNums2.removeFront();
										ListaNums1.removeBack();
										ListaNums1.removeFront();
										ListaNums22.removeBack();
										ListaNums22.removeFront();
										ListaNums11.removeBack();
										ListaNums11.removeFront();
										ListaNums222.removeBack();
										ListaNums222.removeFront();
										contadorPrecio = 0;

										break;
									default:
										break;
									}
									
									Console::WriteLine("¿Quiere ordenar la Pila y la Cola antes de comenzar denuevo? (Si/No)");
									ordenarPilaCola = Console::ReadLine();
									if (ordenarPilaCola == "Si" || ordenarPilaCola == "si")
									{
										//ORDENAR PILA	
										Pila ordenar1;
										Pila ordenar2;
										int contador = 9;
										if (NuevaPila1.vacio() == false)
										{
											while (contador > 0)
											{
												if (NuevaPila1.primera->valor == contador)
												{
													ordenar2.MeterNumero(NuevaPila1.SacarNumero());
													contador--;
													if (ordenar1.vacio() == false)
													{
														while (ordenar1.vacio() == false)
														{
															NuevaPila1.MeterNumero(ordenar1.SacarNumero());
														}
													}
												}
												else
												{
													if (NuevaPila1.primera->valor != contador)
													{
														ordenar1.MeterNumero(NuevaPila1.SacarNumero());
													}
												}
											}
										}
										while (ordenar2.vacio() == false)
										{
											NuevaPila1.MeterNumero(ordenar2.SacarNumero());
										}
										//FIN DE ORDENAR PILA

										Cola BorrarCola;
										if (NuevaCola1.vacio() == false)
										{
											while (NuevaCola1.vacio() == false)
											{
												BorrarCola.MeterNumero(NuevaCola1.SacarNumero());
											}
										}
										for (int i = 0; i <= 9; i++)
										{
											NuevaCola1.MeterNumero(i);
										}

										/*
										//ORDENAR COLA	
										Cola ordenar3;
										Cola ordenar4;
										int contador1 = 0;
										if (NuevaCola1.vacio() == false)
										{
											while (contador1 < 9)
											{
												if (NuevaCola1.primera->valor == contador1)
												{
													ordenar4.MeterNumero(NuevaCola1.SacarNumero());
													contador1++;
													if (ordenar3.vacio() == false)
													{
														while (ordenar3.vacio() == false)
														{
															NuevaPila1.MeterNumero(ordenar3.SacarNumero());
														}
													}
												}
												else
												{
													if (NuevaCola1.primera->valor != contador1)
													{
														ordenar3.MeterNumero(NuevaCola1.SacarNumero());
													}
												}
											}
										}
										if (ordenar4.vacio() == false)
										{
											while (ordenar4.vacio() == false)
											{
												NuevaCola1.MeterNumero(ordenar4.SacarNumero());
											}
										}
										//FIN DE ORDENAR COLA
										*/
										terminar = false;
									}
									else
									{
										if (ordenarPilaCola == "No" || ordenarPilaCola == "no")
										{
											terminar = false;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		else
		{
			if (contadorPrecio >= 2)
			{
				//Aca debe de decirle si quiere terminar o comenzar
				Console::WriteLine("Ya no puede ingresar más precios...");
				Console::WriteLine("¿Quiere borrar algún precio? (Si/No)");
				borrarPrecio = Console::ReadLine();
				if (borrarPrecio == "Si" || borrarPrecio == "si")
				{
					Console::WriteLine("Los precios que se tienen son: ");
					Console::WriteLine("Primer precio: ");
					ListaNums.printReverse();
					ListaNums2.printReverse();
					Console::WriteLine("Segundo precio: ");
					ListaNums1.printReverse();
					ListaNums22.printReverse();
					Console::WriteLine("Tercer precio: ");
					ListaNums11.printReverse();
					ListaNums222.printReverse();

					int elegirPrecio3 = 0;
					Console::WriteLine("¿Cuál precio desea borrar? (1/2/3)");
					elegirPrecio3 = int::Parse(Console::ReadLine());
					if (elegirPrecio3 == 1)
					{
						Console::WriteLine("¿Quiere borrar todo el precio 1 o solo el último dígito? (Todo/Ultimo)");
						borrarPrecio = Console::ReadLine();

						if (borrarPrecio == "Todo" || borrarPrecio == "todo")
						{
							if (AuxPila1.vacio() == false)
							{
								while (AuxPila1.vacio() == false)
								{
									NuevaPila1.MeterNumero(AuxPila1.SacarNumero());
								}
							}
							if (AuxCola1.vacio() == false)
							{
								while (AuxCola1.vacio() == false)
								{
									NuevaCola1.MeterNumero(AuxCola1.SacarNumero());
								}
							}
							Console::WriteLine("Pila");
							NuevaPila1.MostrarPila();
							Console::WriteLine("Cola");
							NuevaCola1.MostrarCola();
						}
						else
						{
							if (borrarPrecio == "Ultimo" || borrarPrecio == "ultimo")
							{
								//En la listanum2 , borrar el frente
								bool encontrado1 = false;
								Pila AuxPila3;
								Pila AuxPila4;
								Cola AuxCola3;
								Cola AuxCola4;
								int valor = ListaNums2.getFront();
								while (encontrado1 == false)
								{
									//Va a ver si lo encuentra en la pila
									while (AuxPila1.vacio() == false)
									{
										if (AuxPila1.primera->valor == valor)
										{
											AuxPila3.MeterNumero(AuxPila1.SacarNumero());
											encontrado1 = true;
										}
										else
										{
											if (AuxPila1.primera->valor != valor)
											{
												AuxPila4.MeterNumero(AuxPila1.SacarNumero());
											}
										}
									}
									//Devuelve los numeros a la PILA
									if (AuxPila4.vacio() == false)
									{
										while (AuxPila4.vacio() == false)
										{
											AuxPila1.MeterNumero(AuxPila4.SacarNumero());
										}
									}
									//Si no lo encontro en la pila, vera si lo encuentra en la COLA
									if (encontrado1 == false)
									{
										while (AuxCola1.vacio() == false)
										{
											if (AuxCola1.primera->valor == valor)
											{
												AuxCola3.MeterNumero(AuxCola1.SacarNumero());
												encontrado1 = true;
											}
											else
											{
												if (AuxCola1.primera->valor != valor)
												{
													AuxCola4.MeterNumero(AuxCola1.SacarNumero());
												}
											}
										}
										//Devuelve los numeros a la COLA
										if (AuxCola4.vacio() == false)
										{
											while (AuxCola4.vacio() == false)
											{
												AuxCola1.MeterNumero(AuxCola4.SacarNumero());
											}
										}
									}
								}
								encontrado1 = false;
								if (AuxPila3.vacio() == false)
								{
									NuevaPila1.MeterNumero(AuxPila3.SacarNumero());
								}
								if (AuxCola3.vacio() == false)
								{
									NuevaCola1.MeterNumero(AuxCola3.SacarNumero());
								}
								Console::WriteLine("Pila");
								NuevaPila1.MostrarPila();
								Console::WriteLine("Cola");
								NuevaCola1.MostrarCola();
							}
						}
					}
					if (elegirPrecio3 == 2)
					{
						Console::WriteLine("¿Quiere borrar todo el precio 2 o solo el último dígito? (Todo/Ultimo)");
						borrarPrecio = Console::ReadLine();

						if (borrarPrecio == "Todo" || borrarPrecio == "todo")
						{
							if (AuxPila5.vacio() == false)
							{
								while (AuxPila5.vacio() == false)
								{
									NuevaPila1.MeterNumero(AuxPila5.SacarNumero());
								}
							}
							if (AuxCola5.vacio() == false)
							{
								while (AuxCola5.vacio() == false)
								{
									NuevaCola1.MeterNumero(AuxCola5.SacarNumero());
								}
							}
							Console::WriteLine("Pila");
							NuevaPila1.MostrarPila();
							Console::WriteLine("Cola");
							NuevaCola1.MostrarCola();
						}
						else
						{
							if (borrarPrecio == "Ultimo" || borrarPrecio == "ultimo")
							{
								//En la listanum2 , borrar el frente
								bool encontrado1 = false;
								Pila AuxPila9;
								Pila AuxPila10;
								Cola AuxCola9;
								Cola AuxCola10;
								int valor = ListaNums22.getFront();
								while (encontrado1 == false)
								{
									//Va a ver si lo encuentra en la pila
									while (AuxPila5.vacio() == false)
									{
										if (AuxPila5.primera->valor == valor)
										{
											AuxPila9.MeterNumero(AuxPila5.SacarNumero());
											encontrado1 = true;
										}
										else
										{
											if (AuxPila5.primera->valor != valor)
											{
												AuxPila10.MeterNumero(AuxPila5.SacarNumero());
											}
										}
									}
									//Devuelve los numeros a la PILA
									if (AuxPila10.vacio() == false)
									{
										while (AuxPila10.vacio() == false)
										{
											AuxPila5.MeterNumero(AuxPila10.SacarNumero());
										}
									}
									//Si no lo encontro en la pila, vera si lo encuentra en la COLA
									if (encontrado1 == false)
									{
										while (AuxCola5.vacio() == false)
										{
											if (AuxCola5.primera->valor == valor)
											{
												AuxCola9.MeterNumero(AuxCola5.SacarNumero());
												encontrado1 = true;
											}
											else
											{
												if (AuxCola5.primera->valor != valor)
												{
													AuxCola10.MeterNumero(AuxCola5.SacarNumero());
												}
											}
										}
										//Devuelve los numeros a la COLA
										if (AuxCola10.vacio() == false)
										{
											while (AuxCola10.vacio() == false)
											{
												AuxCola5.MeterNumero(AuxCola10.SacarNumero());
											}
										}
									}
								}
								encontrado1 = false;
								if (AuxPila9.vacio() == false)
								{
									NuevaPila1.MeterNumero(AuxPila9.SacarNumero());
								}
								if (AuxCola9.vacio() == false)
								{
									NuevaCola1.MeterNumero(AuxCola9.SacarNumero());
								}
								Console::WriteLine("Pila");
								NuevaPila1.MostrarPila();
								Console::WriteLine("Cola");
								NuevaCola1.MostrarCola();
							}
						}
					}
					if (elegirPrecio3 == 3)
					{
						Console::WriteLine("¿Quiere borrar todo el precio 3 o solo el último dígito? (Todo/Ultimo)");
						borrarPrecio = Console::ReadLine();

						if (borrarPrecio == "Todo" || borrarPrecio == "todo")
						{
							if (AuxPila7.vacio() == false)
							{
								while (AuxPila7.vacio() == false)
								{
									NuevaPila1.MeterNumero(AuxPila7.SacarNumero());
								}
							}
							if (AuxCola7.vacio() == false)
							{
								while (AuxCola7.vacio() == false)
								{
									NuevaCola1.MeterNumero(AuxCola7.SacarNumero());
								}
							}
							Console::WriteLine("Pila");
							NuevaPila1.MostrarPila();
							Console::WriteLine("Cola");
							NuevaCola1.MostrarCola();
						}
						else
						{
							if (borrarPrecio == "Ultimo" || borrarPrecio == "ultimo")
							{
								//En la listanum2 , borrar el frente
								bool encontrado1 = false;
								Pila AuxPila11;
								Pila AuxPila12;
								Cola AuxCola11;
								Cola AuxCola12;
								int valor = ListaNums222.getFront();
								while (encontrado1 == false)
								{
									//Va a ver si lo encuentra en la pila
									while (AuxPila7.vacio() == false)
									{
										if (AuxPila7.primera->valor == valor)
										{
											AuxPila11.MeterNumero(AuxPila7.SacarNumero());
											encontrado1 = true;
										}
										else
										{
											if (AuxPila7.primera->valor != valor)
											{
												AuxPila12.MeterNumero(AuxPila7.SacarNumero());
											}
										}
									}
									//Devuelve los numeros a la PILA
									if (AuxPila12.vacio() == false)
									{
										while (AuxPila12.vacio() == false)
										{
											AuxPila7.MeterNumero(AuxPila12.SacarNumero());
										}
									}
									//Si no lo encontro en la pila, vera si lo encuentra en la COLA
									if (encontrado1 == false)
									{
										while (AuxCola7.vacio() == false)
										{
											if (AuxCola7.primera->valor == valor)
											{
												AuxCola11.MeterNumero(AuxCola7.SacarNumero());
												encontrado1 = true;
											}
											else
											{
												if (AuxCola7.primera->valor != valor)
												{
													AuxCola12.MeterNumero(AuxCola7.SacarNumero());
												}
											}
										}
										//Devuelve los numeros a la COLA
										if (AuxCola12.vacio() == false)
										{
											while (AuxCola12.vacio() == false)
											{
												AuxCola7.MeterNumero(AuxCola12.SacarNumero());
											}
										}
									}
								}
								encontrado1 = false;
								if (AuxPila11.vacio() == false)
								{
									NuevaPila1.MeterNumero(AuxPila11.SacarNumero());
								}
								if (AuxCola11.vacio() == false)
								{
									NuevaCola1.MeterNumero(AuxCola11.SacarNumero());
								}
								Console::WriteLine("Pila");
								NuevaPila1.MostrarPila();
								Console::WriteLine("Cola");
								NuevaCola1.MostrarCola();
							}
						}
					}
					//Borrar Todo
					Console::ReadLine();
					terminar = true;
	
				}
				else
				{
					if (borrarPrecio == "No" || borrarPrecio == "No")
					{
						
						if (AuxPila1.vacio() == false)
							{
								while (AuxPila1.vacio() == false)
								{
									NuevaPila1.MeterNumero(AuxPila1.SacarNumero());
								}
							}
						if (AuxCola1.vacio() == false)
							{
								while (AuxCola1.vacio() == false)
								{
									NuevaCola1.MeterNumero(AuxCola1.SacarNumero());
								}
							}
						if (AuxPila5.vacio() == false)
							{
								while (AuxPila5.vacio() == false)
								{
									NuevaPila1.MeterNumero(AuxPila5.SacarNumero());
								}
							}
						if (AuxCola5.vacio() == false)
							{
								while (AuxCola5.vacio() == false)
								{
									NuevaCola1.MeterNumero(AuxCola5.SacarNumero());
								}
							}
						if (AuxPila7.vacio() == false)
							{
								while (AuxPila7.vacio() == false)
								{
									NuevaPila1.MeterNumero(AuxPila7.SacarNumero());
								}
							}
						if (AuxCola7.vacio() == false)
							{
								while (AuxCola7.vacio() == false)
								{
									NuevaCola1.MeterNumero(AuxCola7.SacarNumero());
								}
							}
						ListaNums.removeBack();
						ListaNums.removeFront();
						ListaNums2.removeBack();
						ListaNums2.removeFront();
						ListaNums1.removeBack();
						ListaNums1.removeFront();
						ListaNums22.removeBack();
						ListaNums22.removeFront();
						ListaNums11.removeBack();
						ListaNums11.removeFront();
						ListaNums222.removeBack();
						ListaNums222.removeFront();
						contadorPrecio = 0;

						Console::WriteLine("¿Quiere ordenar la Pila y la Cola antes de comenzar denuevo? (Si/No)");
						ordenarPilaCola = Console::ReadLine();
						if (ordenarPilaCola == "Si" || ordenarPilaCola == "si")
						{
							//ORDENAR PILA	
							Pila ordenar1;
							Pila ordenar2;
							int contador = 9;
							if (NuevaPila1.vacio() == false)
							{
								while (contador > 0)
								{
									if (NuevaPila1.primera->valor == contador)
									{
										ordenar2.MeterNumero(NuevaPila1.SacarNumero());
										contador--;
										if (ordenar1.vacio() == false)
										{
											while (ordenar1.vacio() == false)
											{
												NuevaPila1.MeterNumero(ordenar1.SacarNumero());
											}
										}
									}
									else
									{
										if (NuevaPila1.primera->valor != contador)
										{
											ordenar1.MeterNumero(NuevaPila1.SacarNumero());
										}
									}
								}
							}
							while (ordenar2.vacio() == false)
							{
								NuevaPila1.MeterNumero(ordenar2.SacarNumero());
							}
							//FIN DE ORDENAR PILA

							Cola BorrarCola1;
							if (NuevaCola1.vacio() == false)
							{
								while (NuevaCola1.vacio() == false)
								{
									BorrarCola1.MeterNumero(NuevaCola1.SacarNumero());
								}
							}
							for (int i = 0; i <= 9; i++)
							{
								NuevaCola1.MeterNumero(i);
							}

							/*
							//ORDENAR COLA	
							Cola ordenar3;
							Cola ordenar4;
							int contador1 = 0;
							if (NuevaCola1.vacio() == false)
							{
								while (contador1 < 9)
								{
									if (NuevaCola1.primera->valor == contador1)
									{
										ordenar4.MeterNumero(NuevaCola1.SacarNumero());
										contador1++;
										if (ordenar3.vacio() == false)
										{
											while (ordenar3.vacio() == false)
											{
												NuevaPila1.MeterNumero(ordenar3.SacarNumero());
											}
										}
									}
									else
									{
										if (NuevaCola1.primera->valor != contador1)
										{
											ordenar3.MeterNumero(NuevaCola1.SacarNumero());
										}
									}
								}
							}
							if (ordenar4.vacio() == false)
							{
								while (ordenar4.vacio() == false)
								{
									NuevaCola1.MeterNumero(ordenar4.SacarNumero());
								}
							}
							//FIN DE ORDENAR COLA
							*/
							terminar = false;
						}
						else
						{
							if (ordenarPilaCola == "No" || ordenarPilaCola == "no")
							{
								terminar = false;
							}
						}
					}
				}
			}
		}		
	}
}