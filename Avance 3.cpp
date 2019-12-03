/*
Leonardo Alvarado Menéndez A01705998

Este prugrama lo subi a github https://github.com/Leonardoalv201/Leo

En este programa ya junte los dos entregados en el avance anterior, más aparte que ahora tiene agregación entre flota y los aviones.
Nota: Hay ciertos comentarios extra en lo subido a github, pero no afectan en nada al programa.
*/
#include <iostream>
#include <iomanip>
using namespace std;

//Clase Avion, la cual tendra herencia de los distintos tipos de aviones 
class Avion
{
	private://Atributos privados
		int capacidad_peso;
		string identificador, motor;
	public://Metodos publicos
		Avion(int, string, string);//Constructor de la clase
		void set_capacidad_peso(int capacidad_peso);//getter y setter
		int get_capacidad_peso();
		string get_identificador();
		void set_motor(string motor);
		string get_motor();
};

Avion::Avion(int cap_pes, string id, string _motor)//constructor
{
    capacidad_peso=cap_pes;
	identificador=id;
	motor=_motor;
		
}

//Se declaran los getters y setters
void Avion::set_capacidad_peso(int cap_pes)
{
	capacidad_peso=cap_pes;
};

int Avion::get_capacidad_peso()
{
	return capacidad_peso;
};

string Avion::get_identificador()
{
	return identificador;
};

void Avion::set_motor(string _motor)
{
	motor=_motor;
};

string Avion::get_motor()
{
	return motor;
};

class Pasajeros : public Avion//Hereda las funciones publicas de Avion, con las cuales puede alterar las privadas
{
	private:
		int asientos;
	public:
		Pasajeros(int=0, string="1234C", string="Combustion", int=500);//Constructor de la clase Pasajeros donde ya se declaran valores estandares
		int get_asientos();//getters y setters
		void set_asientos(int asientos);
};

//Constructor de la clase con la herencia, lo que va despues de los ":" son los datos heredados 
Pasajeros::Pasajeros(int cap_pes, string id, string _motor, int _asientos) : Avion (cap_pes, id, _motor)
{
	asientos=_asientos;
}

int Pasajeros::get_asientos()
{
	return asientos;
};

void Pasajeros::set_asientos(int _asientos)
{
	asientos=_asientos;
};

class Privado : public Avion
{
	private:
		string duenio;
	public:
		Privado(int=250, string="263C7", string="Cohete", string="s.d.");
		string get_duenio();
		void set_duenio(string _nombre);
};

Privado::Privado(int cap_pes, string id, string _motor, string _duenio) : Avion (cap_pes, id, _motor)
{
	duenio=_duenio;
}

string Privado::get_duenio()
{
	return duenio;
};

void Privado::set_duenio(string _nombre)
{
	duenio=_nombre;
};

class Carga : public Avion
{
	private:
		int contenedores;
	public:
		Carga(int=1000, string="1256C8", string="Alternativo", int=234);
		int get_contenedores();
		void set_contenedores(int num_contene);
};

Carga::Carga(int cap_pes, string id, string _motor, int cont) : Avion (cap_pes, id, _motor)
{
	contenedores=cont;
}

int Carga::get_contenedores()
{
	return contenedores;
};

void Carga::set_contenedores(int num_contene)
{
	contenedores=num_contene;
};

//Se declara la case flota, la cual es una composicion de la clase Aeropuerto
class Flota
{
	private://atributos privadas
		string nombre;
	public://metodos publicos
		Flota(string="");//Constructor de la clase
		void set_nombre(string nombre);//getters y setters
		string get_nombre();
		void get_datos_pasajero(Pasajeros, Pasajeros);//Metodo para ver los datos de la clase pasajeros
		void get_datos_carga(Carga, Carga);//Metodo para ver los datos de la clase carga
		void get_datos_privado(Privado, Privado);//Metodo para ver los datos de la clase privado
};

Flota::Flota(string nom)
{
	nombre=nom;
}

void Flota::set_nombre(string nom)
{
	nombre=nom;
};

string Flota::get_nombre()
{
	return nombre;
};

void Flota::get_datos_pasajero(Pasajeros a, Pasajeros b)
{
	cout << "El avion a:" << endl;
	cout << "Tiene capacidad para cargar " << a.get_capacidad_peso() << "kg"<< endl;
	cout << "ID: " << a.get_identificador() << endl;
	cout << "Motor: " << a.get_motor() << endl;
	cout << "Numero de asientos: " << a.get_asientos() << endl;
	cout << endl;
	cout << "El avion b:" << endl;
	cout << "Tiene capacidad para cargar " << b.get_capacidad_peso() << "kg"<< endl;
	cout << "ID: " << b.get_identificador() << endl;
	cout << "Motor: " << b.get_motor() << endl;
	cout << "Numero de asientos: " << b.get_asientos() << endl;
};

void Flota::get_datos_carga(Carga c, Carga d)
{
	cout << "El avion c:" << endl;
	cout << "Tiene capacidad para cargar " << c.get_capacidad_peso() << "kg"<< endl;
	cout << "ID: " << c.get_identificador() << endl;
	cout << "Motor: " << c.get_motor() << endl;
	cout << "Numero de contenedores: " << c.get_contenedores() << endl;
	cout << endl;
	cout << "El avion d:" << endl;
	cout << "Tiene capacidad para cargar " << d.get_capacidad_peso() << "kg"<< endl;
	cout << "ID: " << d.get_identificador() << endl;
	cout << "Motor: " << d.get_motor() << endl;
	cout << "Numero de contenedores: " << d.get_contenedores() << endl;
};

void Flota::get_datos_privado(Privado e, Privado f)
{
	cout << "El avion e:" << endl;
	cout << "Tiene capacidad para cargar " << e.get_capacidad_peso() << "kg"<< endl;
	cout << "ID: " << e.get_identificador() << endl;
	cout << "Motor: " << e.get_motor() << endl;
	cout << "El dueño es: " << e.get_duenio() << endl;
	cout << endl;
	cout << "El avion f:" << endl;
	cout << "Tiene capacidad para cargar " << f.get_capacidad_peso() << "kg"<< endl;
	cout << "ID: " << f.get_identificador() << endl;
	cout << "Motor: " << f.get_motor() << endl;
	cout << "El dueño es: " << f.get_duenio() << endl;
};

//Clase aeropuerto, de la cual la clase flota es una composicion 
class Aeropuerto
{
	private:
		int num_flota;//Indice del arreglo donde se guardan las flotas
		string nombre;//Nombre del aeropuerto
		Flota flot[100];//Arreglo donde se guardan las flotas
	public:
		Aeropuerto(int=0, string="");//Constructor
		void get_flota();//Para ver los objetos del arreglo
		void set_flota(string nom);//Aqui se crean los objetos de la clase avion y se guardan en un arreglo
		void set_nombre(string _nombre);//Set nombre
		string get_nombre();//Get nombre
};

//Constructor
Aeropuerto::Aeropuerto(int num_flot, string _nombre)
{
	num_flota=num_flot;
	nombre=_nombre;
}

string Aeropuerto::get_nombre()//Get
{
	return nombre;
};

void Aeropuerto::set_nombre(string _nombre)//Set
{
	nombre=_nombre;
};

void Aeropuerto::set_flota(string nom)
{
	Flota f1(nom);//Se crea el nuevo objeto de la clase Flota
	flot[num_flota] = f1;//Se guarda en el arreglo
	num_flota++;//Aumenta el indice para poder guardar más
};

void Aeropuerto::get_flota()
{
	for (int i=0;i<num_flota;i++)
	{
		cout << "Flota" << i+1 << " " << flot[i].get_nombre() << endl;
	}
};

int main(){
	//Se crean los objetos
	Pasajeros a, b(1000,"24c43","alternativo",253);
	Carga c, d(500,"12G7","reaccion",200);
	Privado e, f(250,"18263GF","cohete","Jose");
	Aeropuerto a1(0,"Aeropuerto Internacional de Mexico");//Se crea el objeto de aeropuerto
	Flota f2("Interjet");//Se crea un objeto flota
	//se declaran las variables que se usaran despues en el programa
	int accion=0;
	int gas=0;
	int desicion=0;
	float _combustible;
	int cap_pes, _asientos, num_contenedores;
	string _motor, _nombre, nom;
	while (desicion!=3)
	{
		cout << "1-Ver datos Aeropuerto" << endl;
		cout << "2-Ver o modificar datos de aviones" << endl;
		cout << "3-Salir" << endl;
		cin >> desicion;
		if (desicion==1)
		{
			int des_aero=0;
			while (des_aero!=3)
			{
				cout << "1-Insertar nueva flota" << endl;
				cout << "2-Ver datos de aerolinea" << endl;
				cout << "3-Salir" << endl;
				cin >> des_aero;
				if (des_aero==1)
				{
					cout << "Nombre de la flota: ";
					cin >> nom;
					a1.set_flota(nom);//Se crea el objeto de la flota dentro de el objero aeropuerto
				}
				if (des_aero==2)
				{
					cout << "El aeropuerto " << "'" << a1.get_nombre() << "'" << " cuenta con las flotas: " << endl;
					a1.get_flota();
				}
				if (des_aero==3)
				{
					cout << "Bye" << endl;
				}
				if (des_aero < 1 || 3 < des_aero)
				{
					cout << "Opcion no disponible" << endl;
				}
				
			}			
		}
		if (desicion==2)
		{
			while (accion!=3)
			{
				//Menú para insertar datos, ver o salir
				cout << "1-Insertar datos a aviones" << endl;
				cout << "2-Ver datos" << endl;
				cout << "3-Salir" << endl;
				cin >> accion;
				if (accion==1)
				{
					int insertar=0;
					while(insertar!=4)
					{
						//Menú para elegir a que tipo de avion se le quieren insertar datos 
						cout << "1-Insertar datos de avion tipo pasajero" << endl;
						cout << "2-Insertar datos de avion tipo carga" << endl;
						cout << "3-Insertar datos de avion tipo privado" << endl;
						cout << "4-Salir" << endl;
						cin >> insertar;
						if (insertar==1)
						{
							//Todos los metodos para agregar datos de la clase Avion que eredo a pasajeros se usan y el metodo propio de la clase Pasajeros
							cout << "Pasajeros a" << endl;
							cout << "Insertar peso del avion: ";
							cin >> cap_pes;
							a.set_capacidad_peso(cap_pes);
							cout <<"Tipo de motor: ";
							cin >> _motor;
							a.set_motor(_motor);
							cout <<"Numero de asientos: ";
							cin >> _asientos;
							a.set_asientos(_asientos);
							cout << endl;
							cout << "Pasajeros b" << endl;
							cout << "Insertar peso del avion: ";
							cin >> cap_pes;
							b.set_capacidad_peso(cap_pes);
							cout <<"Tipo de motor: ";
							cin >> _motor;
							b.set_motor(_motor);
							cout <<"Numero de asientos: ";
							cin >> _asientos;
							b.set_asientos(_asientos);							
						}
						if (insertar==2)
						{
							//Se hace lo mosmo que para los aviones de Pasajeros
							cout << "Carga c" << endl;
							cout << "Insertar peso del avion: ";
							cin >> cap_pes;
							c.set_capacidad_peso(cap_pes);
							cout <<"Tipo de motor: ";
							cin >> _motor;
							c.set_motor(_motor);
							cout <<"Numero de contenedores: ";
							cin >> num_contenedores;
							d.set_contenedores(num_contenedores);
							cout << endl;
							cout << "Carga d" << endl;
							cout << "Insertar peso del avion: ";
							cin >> cap_pes;
							d.set_capacidad_peso(cap_pes);
							cout <<"Tipo de motor: ";
							cin >> _motor;
							d.set_motor(_motor);
							cout <<"Numero de contenedores: ";
							cin >> num_contenedores;
							d.set_contenedores(num_contenedores);															
						}
						if (insertar==3)
						{
							//Se hace lo mismo para los aviones de Pasajeros	
							cout << "Privado e" << endl;
							cout << "Insertar peso del avion: ";
							cin >> cap_pes;
							e.set_capacidad_peso(cap_pes);
							cout <<"Tipo de motor: ";
							cin >> _motor;
							e.set_motor(_motor);
							cout <<"Nombre del dueño: ";
							cin >> _nombre;
							e.set_duenio(_nombre);
							cout << endl;
							cout << "Privado f" << endl;
							cout << "Insertar peso del avion: ";
							cin >> cap_pes;
							f.set_capacidad_peso(cap_pes);
							cout <<"Tipo de motor: ";
							cin >> _motor;
							f.set_motor(_motor);
							cout <<"Nombre dueño: ";
							cin >> _nombre;
							f.set_duenio(_nombre);															
						}
						if (insertar==4)
						{
							cout << "Bye" << endl;
						}
						if (insertar < 1 || 4 < insertar)
						{
							cout <<"Opcion no disponible" << endl;
						}
					}
				}
				if (accion==2)
				{
					int consultar=0;
					while (consultar!=4)
					{
						//Menú para elegir de cual avion le quieres ver sus datos
						cout << "1-Consultar datos de avion tipo pasajero" << endl;
						cout << "2-Consultar datos de avion tipo carga" << endl;
						cout << "3-Consultar datos de avion tipo privado" << endl;
						cout << "4-Salir" << endl;
						cin >> consultar;
						//Se usan los getters para leer los datos de los aviones
						if (consultar==1)
						{
							f2.get_datos_pasajero(a, b);
						}
						if (consultar==2)
						{
							f2.get_datos_carga(c, d);
						}
						if (consultar==3)
						{
							f2.get_datos_privado(e, f);
						}
						if (consultar==4)
						{
							cout << "Bye" << endl;
						}
						if (consultar < 1 || 4 < consultar)
						{
							cout <<"Opcion no disponible" << endl;
						}
				    }
				}
				if (accion==3)
				{
					cout << "Bye" << endl;
				}
				if (accion < 1 || 3 < accion)
				{
					cout <<"Opcion no disponible" << endl;
				}
			}
		}
		if (desicion==3)
		{
			cout << "Bye" << endl;
		}
		if (desicion < 1 || 3 < desicion)
		{
			cout <<"Opcion no disponible" << endl;
		}
	}
}
