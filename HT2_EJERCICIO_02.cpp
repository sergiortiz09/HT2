/*
EJERCICIO #2
El director de un colegio desea realizar un programa que procese un archivo de registros correspondiente a los diferentes 
alumnos del centro a fin de obtener los siguientes datos:

    Nota más alta y número de identificación del alumno correspondiente.
    Nota media del colegio.

Datos de Estudiantes:

    Identificación
    Nombre    
    Nota
*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include <regex>
#include <iomanip> 

using namespace std;
void insert_data_db();
void mp();
void leer_data_db();
/*struct estudiante {
	int id;
	string nombre;
	float nota;	
};*/

int main(){	
	mp();
	//return 0;	
}
void mp(){
	int resp;
	//string nombrearchivo;
	//cout<<"Indique nombre de archivo: ";
	//getline(cin,nombrearchivo);
	
	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar Estudiantes "<<"\n";
		cout<<" 2 - Reporte "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			insert_data_db();			
		}
		else if (resp==2){		
			system("CLS");
			leer_data_db();
		}			
		else if (resp==3)
			break;
		else 
			break;
		
	} while(resp!=3);	
}

void insert_data_db(){
	//declaracion de variables
	int iid;
	string inombre;
	float inota;
	ofstream db;

	system("CLS");
	//Ingreso de datos
	cout<<"*** Ingreso de Datos de Estudiantes ***\n\n";
	cout<<"Indique identificacion del estudiante: "<<endl;
	cin>>iid;
	//cin.ignore();
	fflush(stdin);
	cout<<"Indique Nombre del Estudiante:         "<<endl;
	getline(cin,inombre);
	fflush(stdin);	
	cout<<"Indique Nota del Estudiante:         "<<endl;
	cin>>inota;
	//reemplaca espacios en blanco " " con "_"	
	const auto obj = regex{ " " };
    const auto repl = string{ "_" };
    const auto valor = inombre;
 	//
	//Insercion de datos a un archivo
	try {
		db.open("Estudiante.txt",ios::app);
		db<<iid<<"\t"<<regex_replace(valor, obj, repl)<<"\t"<<inota<<endl;   //"|"
		db.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		system("Pause");
	}	
}
void leer_data_db(){
	//declaracion de variables
	int oid,i,mayorid;
	string onombre;
	float onota;	
	string linea;
	float suma= 0;
	int mayornota = -1;
	
	ifstream db;	
	try{
		db.open("Estudiante.txt",ios::in);	

		cout<<"Datos del archivo:"<<endl;
		cout<<" Id|"<<"      Nombre      |"<<"Nota|"<<endl;		
		while (db>>oid>>onombre>>onota){
			//reemplaca "_" con " "	<-espacios en blanco
			const auto obj = regex{ "_" };
    		const auto repl = string{ " " };
    		const auto valor = onombre;
			//
			cout<<setw(3)<<oid<<"|"<<setw(18)<<regex_replace(valor, obj, repl)<<"|"<<setw(4)<<onota<<"|"<<endl;
			i++;					
			suma+=onota;
//			system("Pause");
			if (onota>mayornota){
				mayornota=onota;
				mayorid =oid;
			}
		}	
		db.close();	
		
		cout<<"\nPromedio Global: "<<suma/i<<endl;
		cout<<"ID de Nota Mas Alta: "<<setw(3)<<mayorid<<" - Nota Mas alta: "<<setw(3)<<mayornota<<endl;
		system("Pause");
	}
	catch(exception& X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		cout<<"Error: "<<X.what()<<endl;
		system("Pause");
	}
	
}
