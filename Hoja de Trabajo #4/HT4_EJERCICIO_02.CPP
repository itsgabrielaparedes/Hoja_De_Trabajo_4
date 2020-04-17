/*Ejercicio#2
Una persona desea realizar un muestreo con un numero de personas para determinar el porcentaje de
niños, jóvenes, adultos y adultos mayores que existen en la zona en donde vive.
La categoría se determina en base a la siguiente tabla:
-----------------------------------
Categoría				Edad
-----------------------------------
Niños					0-12
Jóvenes					13-29
Adultos					30-59
Adultos Mayores			60 en adelante
--------------------------------------
Teniendo en cuenta que para el muestreo de personas no será mayor a 50, realice un programa que en
primer lugar reciba como dato el numero de personas del muestreo y luego por cada persona permita el
ingreso de su edad y grabar todo a un archivo. El programa deberá leer los datos del archivo y mostrar
como resultado el porcentaje de personas que hay por cada una de las categorías.*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
//creo mi estructura
struct edades{
	int numpersonas;
	int edad;
	float porcentaje;
};
//funciones que voy a utilizar
void eedad();
void reporte();
int main(){
	eedad();
	//reporte();
}
//grabar archivo
void eedad(){
	int numpersonas;
	int edad;
	//float porcentaje;
	int cn,cj,cad,cadm,sum=0,suma=0,r=0,res=0;
	int c;
	string n;
	
	cout<<"---------------EDADES---------------"<<endl;
	cout<<"Ingrese numero de personas 1-50: "<<endl;
	cin>>numpersonas;
	cout<<"Ingrese edades: "<<endl;
	while (c<numpersonas){
		c+=1;
		cin>>edad;
		
	/*for(int c=0; c<numpersonas && numpersonas<51; c++){
		int edad[numpersonas];
		cin>>edad[c];*/
		if (edad<=12){
			cn=1;
			sum+=cn;
			cout<<"Entra en categoria 'Ninos'"<<endl;
		}
		else if (edad<=29){
			cj=1;
			suma+=cj;
			cout<<"Entra en categoria 'Jovenes'"<<endl;
		}
		else if (edad<=59){
			cad=1;
			r+=cad;
			cout<<"Entra en categoria 'Adultos'"<<endl;
		}
		else if (edad>=60){
			cadm=1;
			res+=cadm;
			cout<<"Entra en categoria 'Adultos mayores'"<<endl;
		}
	}	
	cout<<"El numero de personas ingresadas son: "<<numpersonas<<"\t"<<"Cat nino: "<<sum<<"\t"<<"Cat joven: "<<suma<<"\t"<<"Cat adulto: "<<r<<"\t"<<"Cat adulto mayor: "<<res<<endl;
	ofstream grabarchivo;
	try{
		grabarchivo.open("HT4_EJERCICIO_02.txt",ios::app);
		grabarchivo<<numpersonas<<"\t"<<sum<<"\t"<<suma<<"\t"<<r<<"\t"<<res<<endl;
		grabarchivo.close();
	}
	catch(exception X){
		cout<<"Error al manipular archivo"<<endl;
	}
	cout<<"\n"<<"-----------Muestreo de edades---------"<<endl;
	cout<<"Numper Ninos Jovenes Adultos AdultM"<<endl;
	ifstream leerarchivo;
	try {
		leerarchivo.open("HT4_EJERCICIO_02.txt",ios::in);				
		while (getline(leerarchivo, n))
			cout<<n<<endl;		
		leerarchivo.close();
	}
	catch(exception X){
		cout<<"Error al manipular archivo"<<endl;
	}
	
}

	

	
