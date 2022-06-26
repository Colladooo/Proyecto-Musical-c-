#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cctype>
#include <cstdlib>

#define TAM 10

using namespace std;
//aqui agregamos una clase que seria "CANCION" y le ponemos atributos
class Cancion{
// le declaramos un "protected" son unica accesibles por funciones.
	protected:
		string nombre;
		string autor;
		string cancion;
		float duracion;
		int anio;
		int aceptacion;
		
	// aqui declaramos un public que significa "publico", que nos permitira acceso a tal miembro dentro
	// y fueras de las clases.			
	public:
		
		Cancion(string nombre, string autor, string cancion, float duracion, int anio, int aceptacion){
			//el this lo usamos como puntero al objetos:
			this ->nombre=nombre;
			this->autor = autor;
			this->cancion = cancion;
			this->duracion = duracion;
			this->anio = anio;
			this->aceptacion = aceptacion;
			
		}
		//aqui volvimos a utilizar las variables pero con un "get" que significa que leera una de cadena del teclado
		//hasta que encuentre el caracter "/n"
		string getnombre(){
			return nombre;
		}
		string getAutor(){
			
			return autor;
		}
		
		string getCancion(){
			
			return cancion;
		}
				
		float getDuracion(){
			
			return duracion;
		}
		
		int getAnio(){
			
			return anio;
		}
		
		int getAceptacion(){
			
			return aceptacion;
		}
		// aqui utilizamos la funcion virtual que es para definir una funcion con la misma cabecera en algunas subclases.
		virtual char getSexo() = 0;
				
		virtual string mostrar() = 0;
		
};
//aqui agregamos la class "pop" con un publico que anteriormente hicimos.
class Pop: public Cancion{

//aqui declaramos un "private" que sera ináccesible no sólo desde otras clases 
//y otras partes del programa, sino también desde sus clases derivadas que sera como ejemplo la variable "sexo".
	private:
		
		char sexo;
		
	public:
	
		Pop(string nombre, string autor, string cancion, float duracion, int anio, int aceptacion, char sexo): 
		Cancion(nombre,autor, cancion, duracion, anio, aceptacion){
			
			this->sexo = sexo;
			
		}
		
		char getSexo(){
			
			return sexo;
		}
		//aqui declaros la variable lectura que sera con "stringstream" para que no muestres las opciones.
		string mostrar(){
			
			stringstream lectura;
			lectura<<"Nombre de la cancion:"<<nombre<<endl;
			lectura<<"Autor: "<<autor<<endl;
			lectura<<"Cancion: "<<cancion<<endl;
			lectura<<"Duracion: "<<duracion<<endl;
			lectura<<"Anio: "<<anio<<endl;
			lectura<<"Aceptacion: "<<aceptacion<<endl;
			lectura<<"Sexo: "<<sexo<<endl;
			
			return lectura.str();
		}
};
//aqui agregamos la class "rock" con un publico que anteriormente hicimos.

class Rock: public Cancion{

//aqui declaramos un "private" que sera ináccesible no sólo desde otras clases 
//y otras partes del programa, sino también desde sus clases derivadas que sera como ejemplo la variable "inteprete".	
	
	private:
		
		string interprete;
		
	public:
	
		Rock(string nombre,string autor, string cancion, float duracion, int anio, int aceptacion, string interprete): 
		Cancion(nombre,autor, cancion, duracion, anio, aceptacion){
			//el this lo usamos como puntero al objetos que es interprete:
			this->interprete = interprete;
			
		}	
		
		char getSexo(){
			
		}
		//aqui hicimos un string de mostrar los datos:
		string mostrar(){
			
			stringstream lectura;
			lectura<<"nombre de la cancion:"<<nombre<<endl;
			lectura<<"Autor: "<<autor<<endl;
			lectura<<"Cancion: "<<cancion<<endl;
			lectura<<"Duracion: "<<duracion<<endl;
			lectura<<"Anio: "<<anio<<endl;
			lectura<<"Aceptacion: "<<aceptacion<<endl;
			lectura<<"Interprete: "<<interprete<<endl;
				
			return lectura.str();
		}
};

//aqui agregamos la class "Salsa" con un publico que anteriormente hicimos.


class Salsa: public Cancion{
	
//aqui declaramos un "private" que sera ináccesible no sólo desde otras clases 
//y otras partes del programa, sino también desde sus clases derivadas que sera como ejemplo la variable "inteprete".	
	
	private:
		
		string interpreta;
		
	public:	

		Salsa(string nombre, string autor, string cancion, float duracion, int anio, int aceptacion, string interpreta): 
		Cancion(nombre,autor, cancion, duracion, anio, aceptacion){
			//el this lo usamos como puntero al objetos:
			this->interpreta = interpreta;
			
		}
		
		char getSexo(){
			
		}
		//aqui usamos la variables string mostrar como anteriormente la usamos:
		string mostrar(){
			
			stringstream lectura;
			lectura<<"nombre de la cancion:"<<nombre<<endl;
			lectura<<"Autor: "<<autor<<endl;
			lectura<<"Autor: "<<autor<<endl;
			lectura<<"Cancion: "<<cancion<<endl;
			lectura<<"Duracion: "<<duracion<<endl;
			lectura<<"Anio: "<<anio<<endl;
			lectura<<"Aceptacion: "<<aceptacion<<endl;
			lectura<<"Interprete: "<<interpreta<<endl;
				
			return lectura.str();
		}
};
//aqui declaramos los void que es una funcion que se puede llamar desde cualquier punto del programa:
void agregarCancion(Cancion *[], int &);
void eliminarCancion(Cancion *[], int &, string );
int buscarCancion(Cancion *[], int , string );
int duracionMayor(Cancion *[], int );
int totalMujeres(Cancion *[], int );
void cancionRockMayorAceptacion(Cancion *[], int );
float sumaDuracion(Cancion *[], int );
void cancionMayorAceptacion(Cancion *[], int );
void listarMenorDuracion(Cancion *[], int, float );

int main(){
	system ("color fd");
	system ("title ---------Proyecto Musical--------");
	// declaramos Variables
	Cancion *cancion[TAM];
	
	ofstream music;
	string nombre, autor, canci;
	float duracion;
	int anio;
	char sexo;
	int opcion, opcion2;
	int total = -1, pos;
	
	
	//aqui declaramos un "do" que no permita repetir una instruccion que seria el menu
	do{
			
		cout<<"\n1. Adicionar cancion al programa\n2. Eliminar cancion al programa";
		cout<<"\n3. Mostrar los datos de la cancion mas larga\n4. Cuantas canciones Pop son interpretadas por mujeres";
		cout<<"\n5. Mostrar los datos de la cancion de Rock con mayor aceptacion";
		cout<<"\n6. Suma del tiempo de todas las canciones";
		cout<<"\n7. Conocer cuales son las canciones con mayor aceptacion\n8. Listar todas las canciones con tiempo menor a un valor dado";
		cout<<"\n9. Guardar estado del programa en fichero\n10. Salir"<<endl;
		cout<<"Elija una opcion: ";
		cin>>opcion;
		
		//aqui declaramos un switch que nos permitira ejecutar varios bloques sentencias si una variable o expresión
		// entera coincide 
		//con alguno de los valores proporcionados en una lista de constantes enteras (literales int o char , por ejemplo).
		switch(opcion){
			
			case 1: 
				
				agregarCancion(cancion, total);
									
				break;
						
			case 2: 
					
				cin.ignore();				
				cout<<"Ingrese la cancion a eliminar: ";
				getline(cin, canci);
				
				eliminarCancion(cancion, total, canci);
														
				break;
				
			case 3: 
				//aqui usamos las setencias if si es "es verdadero o lo contrario "else" 
				if(total == -1){
					
					cout<<"No hay canciones ingresadas";
					
				}else{
				
					pos = duracionMayor(cancion, total);
					
					cout<<"Cancion con mayor duracion: "<<endl;
					
					cout<<cancion[pos]->mostrar();
			
				}
			
				break;
				
			case 4:
				
				if(total == -1){
					
					cout<<"No hay canciones ingresadas";
					
				}else{
				
					cout<<"Total de canciones POP interpretadas por mujeres: "<<totalMujeres(cancion, total);
				
				}
				
				break;
			
			case 5: 
			
				if(total == -1){
					
					cout<<"No hay canciones registradas";
					
				}else{
					
					cancionRockMayorAceptacion(cancion, total);
				
				}
			
				break;
						
			case 6:
				
				if(total == -1){
					
					cout<<"No hay canciones ingresadas";
					
				}else{
				
					cout<<"El total de la suma de duracion de todas las canciones es de: "<<sumaDuracion(cancion, total);
					
				}
					
				break;
		
			case 7: 
			
				if(total == -1){
					
					cout<<"No hay canciones registradas";
					
				}else{
			
					cancionMayorAceptacion(cancion, total);
			
				}
			
				break;
			
			case 8: 
				
				if(total == -1){
					
					cout<<"No hay canciones registradas";
					
				}else{
				
					cout<<"Ingrese un numero de duracion: ";
					cin>>duracion;
				
					listarMenorDuracion(cancion, total, duracion);
					
				}
						
				break;
			
			case 9:
				
				if(total == -1){
					
					cout<<"No hay canciones ingresadas";
					
				}else{
				
				
					music.open("canciones.txt", ios::out);
				
					if(music.fail()){
					
						cout<<"No se pudo abrir el archivo"<<endl;
					
					}
				//aqui utilizamos un ciclos for de mostrar las canciones en el archivo guardado.
					for(int i = 0; i <= total; i++){
					
						music<<cancion[i]->mostrar();
					
					}
				//aqui cerramos el archivo 
					music.close();
				
				}
				
				break;
						
			case 10: 
							
				cout<<"Saliendo del programa..."; 
							
				break;
			
			case 11:
				//volvimos utilizar el ciclos for
				for(int i = 0; i <= total; i++){
					
					cout<<cancion[i]->mostrar();
					
				}
				
				break;
			
			default: 
						
				cout<<"Opcion invalida";
		}
		
		if(opcion != 10){
			
			cout<<endl;
			system("pause");
			system("cls");
			
		}
					
	}while(opcion != 10);
	
	if(total != -1){
	
		for(int i = 0; i <= total; i++){
			
			delete cancion[i];
			
		}
		
	}
	
	return 0;
}
//utlizamos un void que es para agregar las canciones al archivo
// que es una Función con tipo de retorno nulo
void agregarCancion(Cancion *cancion[], int &total){
	
	string nombre, autor, canci, interprete;
	float duracion;
	int anio, aceptacion;
	char sexo;
	int opcionCancion, opcionInterprete;
	
	if(total == TAM - 1){
					
		cout<<"Se lleno la memoria"<<endl;
					
	}else{
	//El ciclo do-while (Instrucción hacer  repetir mientras) es un tipo de estructura repetitiva eficiente. 
		do{
			
			cout<<"1. Pop\n2. Rock\n3. Salsa"<<endl;
			cout<<"Elija la cancion: ";
			cin>>opcionCancion;
			
			if(opcionCancion < 1 or opcionCancion > 3){
				
				cout<<"Ingrese la opcion del 1 - 3"<<endl;
				
			}
			
		}while(opcionCancion < 1 or opcionCancion > 3);
					
		cin.ignore();
		
		cout<<"nombre de la cancion:";
		getline(cin, nombre);
		
		cout<<"Autor: ";
		cin>>autor;
					
		cout<<"Duracion: ";
		cin>>duracion;
					
		cout<<"Anio: ";
		cin>>anio;
		//Los condicionales Switch, son una estructura de control condicional,
		// que permite definir múltiples casos que puede llegar a cumplir una variable cualquiera.		
		switch(opcionCancion){
			
			case 1:
				//aqui volvimos a utilizar el do como ciclo
				do{
				
				
					cout<<"Sexo [F-M]: ";
					cin>>sexo;
					
					sexo = toupper(sexo);
					
					if(sexo != 'F' and sexo != 'M'){
						
						cout<<"Ingrese correctamente el sexo"<<endl;
						
					}
				
				}while(sexo != 'F' and sexo != 'M');
						
				canci = "Pop";
				
				aceptacion = anio * 10;
				
				total++;
			
				cancion[total] = new Pop(nombre,autor, canci, duracion, anio, aceptacion, sexo);
								
				break;
			
			case 2:
				
				do{
					
					cout<<"1. Nacional\n2. Extranjero"<<endl;
					cout<<"Elija la opcion del interprete: ";
					cin>>opcionInterprete;
					
					if(opcionInterprete < 1 or opcionInterprete > 2){
						
						cout<<"Error...."<<endl;
						
					}
					
				}while(opcionInterprete < 1 or opcionInterprete > 2);
				
				switch(opcionInterprete){
					
					case 1: 
					
						interprete = "Nacional"; 
						
						aceptacion = (anio * 10) + 100;
							
						break;
					
					case 2: 
					
						interprete = "Extranjero"; 
						
						aceptacion = (anio * 10) + 200;

						break;
					
				}
				
				canci = "Rock";

				total++;
				
				cancion[total] = new Rock(nombre,autor, canci, duracion, anio, aceptacion, interprete);
				
				break;
				
			case 3:
				
				do{
					
					cout<<"1. Grupo\n2. Solista"<<endl;
					cout<<"Elija la opcion del interprete: ";
					cin>>opcionInterprete;
					
					if(opcionInterprete < 1 or opcionInterprete > 2){
						
						cout<<"Error...."<<endl;
						
					}
					
				}while(opcionInterprete < 1 or opcionInterprete > 2);
				
				switch(opcionInterprete){
					
					case 1: interprete = "Grupo"; break;
					case 2: interprete = "Solitas"; break;
					
				}
				
				aceptacion = anio * 10;

				canci = "Salsa";
				
				total++;
				
				cancion[total] = new Salsa(nombre,autor, canci, duracion, anio, aceptacion, interprete);
				
				break;
		}
			
		cout<<"Se ha ingresado cancion"<<endl;
						
	}
	
}


void eliminarCancion(Cancion *cancion[], int &total, string buscarAutor){
	
	int posicion;
	
	if(total == -1){
		
		cout<<"No hay canciones ingresadas"<<endl;
		
	}else{
		
		posicion = buscarCancion(cancion, total, buscarAutor);
				
		if(posicion != -1){
			
			delete cancion[posicion];
			
			for(int i = posicion; i <= total - 1; i++){
				
				cancion[i] = cancion[i + 1];
				
			}
			
			total--;
			
			cout<<"Cancion "<<buscarAutor<<" ha sido eliminada"<<endl;
				
		}else{
			
			cout<<"Cancion no encontrada"<<endl;
			
		}
		
	}
	
}

int buscarCancion(Cancion *cancion[], int total, string buscarAutor){
	
	int i = 0;
	bool encontrado = false;
	
	while(! encontrado and i <= total){
				
		if(buscarAutor == cancion[i]->getAutor()){
			
			encontrado = true;
			
		}
		
		i++;
	}
	
	if(encontrado){
		
		return i - 1;
		
	}else{
		
		return -1;
		
	}
}

int duracionMayor(Cancion *cancion[], int total){
	
	float mayor = cancion[0]->getDuracion();
	
	int pos = 0;
	
	for(int i = 0; i <= total; i++){
		
		if(cancion[i]->getDuracion() > mayor){
			
			pos = i;
			
		}
		
	}
	
	return pos;
	
}

int totalMujeres(Cancion *cancion[], int total){
	
	int mujeres = 0;
	
	for(int i = 0; i <= total; i++){

		if(cancion[i]->getSexo() == 'F'){
			
			mujeres++;
			
		}

	}
	
	return mujeres;
}

void cancionRockMayorAceptacion(Cancion *cancion[], int total){
	
	bool encontrado = false;
	
	for(int i = 0; i <= total; i++){
		
		if(cancion[i]->getCancion() == "Rock"){
			
			if(cancion[i]->getAceptacion() >= 20050){
				
				encontrado = true;
				
				cout<<cancion[i]->mostrar();
				
			}
			
		}
		
	}
	
	if(! encontrado){
		
		cout<<"No hay canciones de Rock ingresadas por el momento"<<endl;
		
	}
	
}
//aqui declaramos un float que su significado sirve para declarar una variable tipo decimal o entero.
float sumaDuracion(Cancion *cancion[], int total){
	
	float suma = 0.0;
	
	for(int i = 0; i <= total; i++){
		
		suma += cancion[i]->getDuracion();
				
	}
	
	return suma;
}

void cancionMayorAceptacion(Cancion *cancion[], int total){
	
	bool encontrado = false;
	
	for(int i = 0; i <= total; i++){
		
		if(cancion[i]->getAceptacion() >= 20155){
			
			encontrado = true;
			
			cout<<cancion[i]->mostrar();
			
		}
		
	}
	
	if(! encontrado){
		
		cout<<"No hay canciones con ese rango de aceptacion"<<endl;
		
	}
	
}
//aqui utilizamos la funcion de tipo nulos "void"
void listarMenorDuracion(Cancion *cancion[], int total, float duracion){
	
	for(int i = 0; i <= total; i++){
		
		if(cancion[i]->getDuracion() <= duracion){
			
			cout<<cancion[i]->mostrar();
			
		}
		
	}
	
}
