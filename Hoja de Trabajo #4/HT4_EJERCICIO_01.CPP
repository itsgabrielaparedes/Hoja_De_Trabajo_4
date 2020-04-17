/*Ejercicio 1: En la región de la sierra de los Cuchumatanes la compañía Xterminio s.a. , tiene las siguientes tarifas:
Tipo  Servicio      Costo  X Hectárea
1     Mala hierba         10.00
2     Langostas           20.00
3      Gusanos			  30.00
4   Todo lo anterior      50.00
Además del área a fumigar es mayor a 500.00 hectáreas se tiene un descuento del 5%. Adicionalmente,
si el total a pagar por el servicio es mayor a Q1500.00 se tiene un descuento adicional del 10% sobre el
excedente.
La compañía necesita las estadísticas de los servicios que ha ofrecido a un grupo de agricultores durante
un periodo de tiempo. Por cada servicio debe ingresar los datos siguientes: Tipo de Fumigación (1 a 4) y
el número de hectáreas, toda esta información deberá almacenarse en una base de datos (archivo plano).
Se le pide que realice un programa en C++ que solicite el ingreso de la información de cada servicio
realizado a un grupo de agricultores. El programa deberá de leer los datos del archivo que tiene la
información antes almacenada y mostrar la cantidad de servicios de cada tipo de fumigación, determinar
el tipo servicio con mayor demanda y el monto total pagado por los clientes.*/ 

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
//creo mi estructura
struct servicio{
	int tipofum;
	int numhectareas;
	float calcdescuento;
	float total;
};
//declaro las funciones que utilizaré
void tarifadesc();
void reporte(); 
int main(){
	tarifadesc();
	reporte();
}
//grabar archivo
void tarifadesc(){
	int tipofum;
	int numhectareas;
	float calcdescuento;
	float total;
	string n;
	cout<<"---------------Compania Xterminio S.A--------------"<<endl;
	cout<<"1     -     Mala Hierba       - CostoXHectarea Q10"<<endl;
	cout<<"2     -     Langostas         - CostoXHectarea Q20"<<endl;
	cout<<"3     -     Gusanos           - CostoXHectarea Q30"<<endl;
	cout<<"4     -     Todo lo anterior  - CostoXHectarea Q50"<<endl;
	cout<<"Ingrese tipo de fumigacion: "<<endl;
	cin>>tipofum;
	cout<<"Ingrese numero de hectareas que desea: "<<endl;
	cin>>numhectareas;
	if (numhectareas<500){
		if (tipofum==1){
			total=(numhectareas*10);		
		}
		else if (tipofum==2){
			total=(numhectareas*20);
		}
		else if (tipofum==3){
			total=(numhectareas*30);
		}	
		else if (tipofum==4){
			total=(numhectareas*50);
		}
	}
	if (numhectareas>500){
		if (tipofum==1){
			calcdescuento=(numhectareas*10);
			total=calcdescuento-(10*0.05);
		}
		else if (tipofum==2){
			calcdescuento=(numhectareas*20);
			total=calcdescuento-(20*0.05);
		}
		else if (tipofum==3){
			calcdescuento=(numhectareas*30);
			total=calcdescuento-(30*0.05);
		}
		else if (tipofum==4){
			calcdescuento=(numhectareas*50);
			total=calcdescuento-(50*0.05);
		}
	}
	if (total>1500){
		total=total-(total*0.10);
	}
	
			
	cout<<"Tipo de fumigacion: "<<tipofum<<"\t"<<"Numero de hectareas: "<<numhectareas<<"\t"<<"Total: "<<total<<endl;
	//grabar archivo
	ofstream grabaarchivo;
	try {
		grabaarchivo.open("HT4_EJERCICIO_01.txt", ios::app);
		grabaarchivo<<tipofum<<"\t"<<numhectareas<<"\t"<<total<<endl;
		grabaarchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	cout<<"\n"<<"-------Ventas de servicios actuales-------"<<endl;
	cout<<"TipoFum Num hect Total"<<endl;
	ifstream leerarchivo;
	try {
		leerarchivo.open("HT4_EJERCICIO_01.txt",ios::in);				
		while (getline(leerarchivo, n))
			cout<<n<<endl;		
		leerarchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
}
//leer archivo
void reporte(){
	ifstream xterm;
	float tfum,nh,totalv=0;
	float sumtotal=0;
	float tfum1=0;
	float tfum2=0;
	float tfum3=0;
	float tfum4=0;
	int s, lineas;
	try{
			xterm.open("HT4_EJERCICIO_01.txt",ios::in);
		
		while (xterm>>tfum>>nh>>totalv){
			sumtotal= totalv+sumtotal;
			if (tfum==1)
				tfum1+=totalv;
			else if (tfum==2)
				tfum2+=totalv;
			else if (tfum==3)
				tfum3+=totalv;
			else if (tfum==4)
				tfum4+=totalv;
		}
		xterm.close();
		//mostrar total de ventas de servicios
		cout<<setprecision(10)<<"Total de Ventas de Servicios: "<<sumtotal<<endl;
	}
	catch (exception X){		
			cout<<"Error para abrir archivo"<<endl;			
			exit(1);
	}		
		
		
 }



