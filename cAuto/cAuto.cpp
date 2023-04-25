#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

class cMotor
{
public:
	cMotor();
	void imprimir();
private:
	int iCilindros;
	int cilindrada;
};

cMotor::cMotor()
{
	iCilindros = 4;
}

void cMotor::imprimir()
{
	cout << "el motor tiene:" << iCilindros << " cilindros" << endl;
}

class cAuto
{
public:
	cAuto();
	void acelerar();
	void frenar();
	void imprimir();

protected:
	cMotor motor;
	float velocidad;
};

cAuto::cAuto()
{
	velocidad = 0;
}

void cAuto::acelerar()
{
	if (velocidad <= 200)
		velocidad++;
}

void cAuto::frenar()
{
	if (velocidad > 0)
		velocidad--;
}

void cAuto::imprimir()
{
	if (velocidad > 0)
	{
		motor.imprimir();
		cout << "el auto va a una velocidad de: " << velocidad << "kmh" << endl;
		
	}
	else
		cout << "usted no se esta moviendo" << endl;
}

class cPatrulla : public cAuto
{
public:
	cPatrulla();
	void acelerar();
	void encender_sirena(bool);
	void imprimir();
private:
	bool sirena;
};

cPatrulla::cPatrulla()
{
	sirena = false;
}



void cPatrulla::acelerar()
{
	if (velocidad <= 200)
		velocidad += 2;
}

void cPatrulla::encender_sirena(bool encender)
{
	if (encender == true)
		sirena = true;
}

void cPatrulla::imprimir()
{
	
	if (velocidad > 0)
	{
		motor.imprimir();
		cout << "la patrulla va a una velocidad de: " << velocidad << "kmh" << endl;
	}
	else
		cout << "usted no se esta moviendo" << endl;
	if (sirena == true)
		cout << "la sirena esta encendida" << endl;
	else
		cout << "la sirena esta apagada" << endl;
}

class cPatrullablin : public cAuto
{
public:
	cPatrullablin();
	void acelerar();
	void encender_sirena(bool);
	void disparo();
	void imprimir();
private:
	bool sirena;
	int blin;
};

cPatrullablin::cPatrullablin()
{
	sirena = false;
	blin = 100;
}

void cPatrullablin::acelerar()
{
	if (velocidad <= 200)
		velocidad +=1.5;
}

void cPatrullablin::encender_sirena(bool encender)
{
	if (encender == true)
		sirena = true;
}

void cPatrullablin::imprimir()
{

	if (velocidad > 0)
	{
		motor.imprimir();
		cout << "la patrulla blindada va a una velocidad de: " << velocidad << "kmh" << endl;
		cout << "tiene un blindaje de:" << blin << "%"<< endl;
	}
	else
		cout << "usted no se esta moviendo" << endl;
	if (sirena == true)
		cout << "la sirena esta encendida" << endl;
	else
		cout << "la sirena esta apagada" << endl;
}

void cPatrullablin::disparo()
{
	blin -= 5;
}

class cToreto: public cAuto
{
public:
    cToreto();
	void acelerar();
	void imprimir();
	void nitro(bool);
private:
	int nit;
};

cToreto::cToreto()
{
	nit = 100;
}

void cToreto::imprimir()
{
	if (velocidad > 0)
	{
		motor.imprimir();
		cout << "el auto va a una velocidad de: " << velocidad << "kmh" << endl;
		cout << "y le queda:" << nit << "% de nitro" << endl;

	}
	else
		cout << "usted no se esta moviendo" << endl;
}
void cToreto::acelerar()
{
	velocidad += 3;
}

void cToreto::nitro(bool boton_rojo)
{
	if (boton_rojo == true)
	{
		velocidad += 10;
		nit -= 10;
	}
}

class cTaxi :public cAuto
{
public:
	void acelerar();
};

void cTaxi::acelerar()
{
	velocidad += 5;
}
int main()
{
	int iO=0,iO2=0;
	cAuto a;
	cPatrulla p;
	cPatrullablin pb;
	cTaxi t;
	cToreto at;
	bool band , band2 = true;
	while (band2 == true)
	{
		band = true;
		cout <<endl<< "desea usar un:" << endl << "1) auto" << endl << "2) patrulla" << endl << "3) patrulla blindada" << endl << "4) auto de toreto" << endl << "5) taxi" << endl << "6) salir" << endl;
		cin >> iO;
		switch (iO)
		{
		case 1:
			while (band == true)
			{
				cout << endl << "auto:" << endl;
				cout <<endl<< "que desea hacer:" << endl << "1) acelerar" << endl << "2) frenar" << endl << "3) imprimir" << endl << "4) salir" << endl;
				cin >> iO2;
				switch (iO2)
				{
				case 1:
					cout << "acelerando" << endl;
					a.acelerar();
					break;
				case 2:
					cout << "frenando" << endl;
					a.frenar();
					break;
				case 3:
					cout << endl << "auto:" << endl;
					a.imprimir();
					break;
				case 4:
					band = false;
					break;
				default:
					cout << "opcion no validad" << endl;
					break;
				}
			}
			break;
		case 2:
			while (band == true)
			{
				cout << endl << "patrulla:"<<endl;
				cout <<endl<< "que desea hacer:" << endl << "1) acelerar" << endl << "2) frenar" << endl << "3) encender sirena" << endl << "4) imprimir" << endl << "5) salir" << endl;
				cin >> iO2;
				switch (iO2)
				{
				case 1:
					cout << "acelerando" << endl;
					p.acelerar();
					break;
				case 2:
					cout << "frenando" << endl;
					p.frenar();
					break;
				case 3:
					cout << "encendiendo sirena" << endl;
					p.encender_sirena(true);
					break;
				case 4:
					cout << endl << "patrulla:" << endl;
					p.imprimir();
					break;
				case 5:
					band = false;
					break;
				default:
					cout << "opcion no validad" << endl;
					break;
				}
			}
			break;
		case 3:
			while (band == true)
			{
				cout << endl << "patrulla blindada" << endl;
				cout <<endl<< "que desea hacer:" << endl << "1) acelerar" << endl << "2) frenar" << endl << "3) encender sirena" << endl << "4) recibir un disparo" << endl << "5) imprimir" << endl << "6) salir" << endl;
				cin >> iO2;
				switch (iO2)
				{
				case 1:
					cout << "acelerando" << endl;
					pb.acelerar();
					break;
				case 2:
					cout << "frenando" << endl;
					pb.frenar();
					break;
				case 3:
					cout << "encendiendo sirena" << endl;
					pb.encender_sirena(true);
					break;
				case 4:
					cout << "disparo recibido" << endl;
					pb.disparo();
					break;
				case 5:
					cout << endl << "patrulla blindada" << endl;
					pb.imprimir();
					break;
				case 6:
					band = false;
					break;
				default:
					cout << "opcion no validad" << endl;
					break;
				}
			}
			break;
		case 4:
			while (band == true)
			{
				cout << endl << "auto de toreto" << endl;
				cout <<endl<< "que desea hacer:" << endl << "1) acelerar" << endl << "2) frenar" << endl << "3) encender nitro" << endl << "4) imprimir" << endl << "5) salir" << endl;
				cin >> iO2;
				switch (iO2)
				{
				case 1:
					cout << "acelerando" << endl;
					at.acelerar();
					break;
				case 2:
					cout << "frenando" << endl;
					break;
				case 3:
					cout << "encendiendo el nitro";
					at.nitro(true);
				case 4:
					cout << endl << "auto de toreto:" << endl;
					at.imprimir();
					break;
				case 5:
					band = false;
					break;
				default:
					cout << "opcion no validad" << endl;
					break;
				}
			}
			break;
		case 5:
			while (band == true)
			{
				cout << endl << "taxi:" << endl;
				cout <<endl<< "que desea hacer:" << endl << "1) acelerar" << endl << "2) frenar" << endl << "3) imprimir" << endl << "4) salir" << endl;
				cin >> iO2;
				switch (iO2)
				{
				case 1:
					cout << "acelerando" << endl;
					t.acelerar();
					break;
				case 2:
					cout << "frenando" << endl;
					t.frenar();
					break;
				case 3:
					cout << endl << "taxi:" << endl;
					t.imprimir();
					break;
				case 4:
					band = false;
					break;
				default:
					cout << "opcion no validad" << endl;
					break;
				}
			}
			break;
		case 6:
			band2 = false;
			break;
		default:
			cout << "opcion no validad";
			break;
		}
	}
}