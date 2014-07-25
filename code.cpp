//#include "stdafx.h"
#include<iostream.h>
#include<fstream.h>
//#include<stdlib.h>
#include<cstring.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


//Con typedef y enum creamos un seudo bool
typedef enum {false=0, true} bool;

//usando reservacion de espacio para las funciones
//using namespace std;

//Prototipo de funciones
int ingreso();
int clientes();
int detalles();
int Buscar_Clientes();

//Estructura para la factura
struct
{
    int numFactura;
    char nombre[30];
    char apellido[30];
    char nit[30];
    char direccion[70];
    char telefono[20];
    char fecha[12];
    double total;
} Facturas;
//Estructura para el detalle
struct
{
    int numFactura;
    int cantidad;
    char nomProducto[70];
    char medida[30];
    double precioUnitario;
    double SubTotal;
} Detalle;

int main()
{
    int respuesta;
    do //ciclo repetir asta que
    {
		  //system("cls");//borrar pantalla
        clrscr();
//menu para que el usuario se guie.
        cout<<" =========================================\n";
        cout<<" || FACTURACION ||\n";
        cout<<" ||-------------------------------------||\n";
        cout<<" || 1.- Nueva Factura ||\n";
        cout<<" || 2.- Clientes ||\n";
        cout<<" || 3.- Buscar una Factura ||\n";
        cout<<" || 4.- Buscar un Cliente ||\n";
        cout<<" || 5.- Salir ||\n";
        cout<<" =========================================\n";
        cout<<endl;
        cout<<" -> INGRESE OPCION: ";//solicitud de su respues
        cin>>respuesta;//respuesta
		  //system("cls");//borrar pantalla
        clrscr();
        switch(respuesta)//seleccion de en caso que respuesta se
        {
        case 1:
            ingreso();
            break;//sea uno llama al procedimiento ingreso arriba
        case 2:
            clientes();
				//system("pause");
            getch();
            break;//llama ala funcion ver datos
        case 3:
            detalles();
				//system("pause");
            getch();
            break;//llama ala funcion ver datos
        case 4:
            Buscar_Clientes();
				//system("pause");
            getch();
				break;//llama ala funcion ver datos
        case 5:
				//system("cls");
            clrscr();
            cout<<"*/*/*/*/*/USTED salio correctamente del programa/*/*/*/*/*/\n\n\n";
            exit(1);;
            break;//cierra el programa
        default:
            cout<<"numero incorrecto intente nuevamente\n\n";
				//system("pause");
            getch();
            break;//lanza un mensaje y vuelve a mostrar los datos
        }
    }
    while(respuesta!=5);

	 //system("pause");
    getch();
	 //cout<<endl;
	 return 0;
}


int ingreso()
{
	 //system("cls");//borrar pantalla
    clrscr();
    cout << " --------------------------- \n";
    cout << " ---INGRESO NUEVA FACTURA--- \n";
    cout << " --------------------------- \n";

// captura de campos
    cout << "Ingrese fecha(ej:31/12/2010 :";
    cin >> Facturas.fecha;
    cout << "Ingrese el numero de factura :";
    cin >> Facturas.numFactura;
    cout << "\n- - - - - - DATOS DEL CLIENTE - - - - - -\n";
	 cout << "Ingrese primer nombre :";
	 cin.getline(Facturas.nombre,50);
	 cout << "Ingrese apellido :";
	 cin >> Facturas.apellido;
	 cout << "Ingrese numero de Nit :";
	 cin >> Facturas.nit;
	 cout << "Ingrese direccion cliente :";
    cin.getline(Facturas.direccion,50);
    cout << "Ingrese telefono cliente :";
    cin >> Facturas.telefono;

// - - - - - - - DETALLE DE LA FACTURA - - - - - - -

    cout << "INGRESE LOS DATOS QUE SE LE SOLICITAN\n?";//instrucciones al usuario

	 //system("cls");
    clrscr();
//
    cout<<" NOMBRE DEL CLIENTE: "<<Facturas.nombre<<Facturas.apellido;
    cout<<"\n";
    cout<<" NIT CLIENTE: "<<Facturas.nit;
    cout<<"\n";
    cout<<" DIRECCION: "<<Facturas.direccion;
    cout<<"\n";
    cout<<" TELEFONO: "<<Facturas.telefono;
    cout<<"\n";
    cout<<" --------------------------- "<<endl;
    cout<<" -----DETALLE FACTURA------- "<<endl;
    cout<<" --------------------------- "<<endl;
    cout<<endl;

    cout<<"DETALLE DE LA FACTURA #: "<<Facturas.numFactura<<endl;
    Detalle.numFactura = Facturas.numFactura;
    cout<<" - - - -- INGRESE LO QUE SE LE PIDE -- - - -"<<endl;
    cout<<" - - - - (Detalle de la Facturacion) - - - -"<<endl;

    cout << "CANTIDAD: ";
    cin >> Detalle.cantidad;
	 cout << "DETALLE PRODUCTO: ";
    cin.getline(Detalle.nomProducto,50);
    cout << "MEDIDA(Kg, lbs,etc...: ";
    cin >> Detalle.medida;
    cout << "PRECIO POR UNIDAD: ";
    cin >> Detalle.precioUnitario;

    Detalle.SubTotal=Detalle.cantidad*Detalle.precioUnitario;

    Facturas.total=Facturas.total+Detalle.SubTotal;//acumulador que suma cada subtotal segun el detalle de la facturacion

    cout<<"SUBTOTAL CALCULADO: "<<Detalle.SubTotal<<endl;

//Grabamos a disco la estructura factura
	 FILE *archdisco_factura;
	 archdisco_factura = fopen("c:\\factura.txt","at+");
    fwrite(&Facturas,sizeof(Facturas),1,archdisco_factura);
    fclose(archdisco_factura);
//avisando usuario
    cout << "factura insertada" << endl;

//Grabamos a disco la estructura detalle
    FILE *archdisco_detalle;
    archdisco_detalle = fopen("c:\\detalle.txt","at+");
    fwrite(&Detalle,sizeof(Detalle),1,archdisco_detalle);
    fclose(archdisco_detalle);
//avisando usuario
    cout << "Detalle insertado" << endl;
	 //system("pause");
    getch();
    return 0;
}

int clientes()
{
    int cantidad = 0;
//abrimos el archivo que contiene la estructura
    FILE *archdisco_open_Facturas;
    archdisco_open_Facturas = fopen("c:\\factura.txt","r");
//verificamos el numero de elementos de la misma.
    while(fread(&Facturas,sizeof(Facturas),1,archdisco_open_Facturas)==1)
    {
        cantidad++;
    };
//Lo informamos al usuario
    printf("La base de datos contiene %d facturas realizadas!.\n", cantidad);
    cout << "--------------------------------------------------" << endl;
    getchar();

    rewind(archdisco_open_Facturas);
//volvemos a leer el archivo de datos e informamos
    while(fread(&Facturas,sizeof(Facturas),1,archdisco_open_Facturas)==1)
    {
        cout << "FECHA = " << Facturas.fecha << endl;
        cout << "FACTURA = " << Facturas.numFactura << endl;
        cout << "APELLIDO = " << Facturas.apellido << endl;
        cout << "NOMBRES = " << Facturas.nombre << endl;
        cout << "DIRECCION = " << Facturas.direccion << endl;
        cout << "TELEFONO = " << Facturas.telefono << endl;
        cout << "NIT = " << Facturas.nit << endl;
        cout << "TOTAL = " << Facturas.total << endl;
        cout << "--------------------------------------------------" << endl;
    };
//Cerramos el archivo.
    fclose(archdisco_open_Facturas);
    return 0;
}

int detalles()
{
    int factura;
    cout << "Ingrese numero de factura a buscar:\t";
    while (!(cin >> factura) ) //Hacemos mientras no obtengamos el nmero de carnet
    {
        cout << "\nLa factura debe contener solamente numeros!." //Informamos el error
             << "\nRe-ingrese numero de Factura por favor!: ";
        cin.ignore(255,'\n'); //Control de errores de cin
        cin.clear(); //Control de errores de cin
	 }

    int cantidad = 0;
//abrimos el archivo que contiene la estructura
	 FILE *archdisco_open_detalles;
    archdisco_open_detalles = fopen("c:\\detalle.txt","r");
//verificamos el numero de elementos de la misma.
    while(fread(&Detalle,sizeof(Detalle),1,archdisco_open_detalles)==1)
    {
        cantidad++;
    };
//Lo informamos al usuario
    printf("La base de datos contiene %d facturas realizadas!.\n", cantidad);
    cout << "--------------------------------------------------" << endl;
    getchar();
//Rebobinamos el archivo abierto al inicio.
    rewind(archdisco_open_detalles);
//volvemos a leer el archivo de datos
	 bool hallado = false;
    while(fread(&Detalle,sizeof(Detalle),1,archdisco_open_detalles)==1)
    {
        if (factura == Detalle.numFactura)
        {
            cout << "FACTURA NUMERO = " << Detalle.numFactura << endl;
            cout << "CANTIDAD = " << Detalle.cantidad << endl;
            cout << "PRODUCTO = " << Detalle.nomProducto << endl;
            cout << "MEDIDA = " << Detalle.medida << endl;
            cout << "PRECIO UNITARIO = " << Detalle.precioUnitario << endl;
            cout << "SUB TOTAL = " << Detalle.SubTotal << endl;
            cout << "--------------------------------------------------" << endl;
            hallado = true;
        }
    };
    if (hallado==false)
    {
        cout <<"La factura: " << factura << " no fue hallada" << endl;
    }
//Cerramos el archivo.
    fclose(archdisco_open_detalles);
    return 0;
}


int Buscar_Clientes()
{
    int cantidad = 0;
    char apellido_a_buscar[30];
    char * pch;
    int caracter;
    bool hallado = false;

    char texto_a_buscar[30];
    cout << "Ingrese texto que recuerde del Apellido del cliente a buscar:\t";
    while (!(cin >> texto_a_buscar) ) //Hacemos mientras no obtengamos el nmero de carnet
    {
        cout << "\nNo ha ingresado texto en forma correcta!." << endl; //Informamos el error
        cin.ignore(255,'\n'); //Control de errores de cin
        cin.clear(); //Control de errores de cin
        fflush(stdin); //Limpiamos las entradas del teclado
    }


//abrimos el archivo que contiene la estructura
    FILE *archdisco_open_Facturas;
	 archdisco_open_Facturas = fopen("c:\\factura.txt","r");
//verificamos el numero de elementos de la misma.
    while(fread(&Facturas,sizeof(Facturas),1,archdisco_open_Facturas)==1)
    {
        cantidad++;
    };
//Lo informamos al usuario
	 printf("La base de datos contiene %d facturas realizadas!.\n", cantidad);
    cout << "--------------------------------------------------" << endl;
	 getchar();

	 rewind(archdisco_open_Facturas);
//volvemos a leer el archivo de datos e informamos
    while(fread(&Facturas,sizeof(Facturas),1,archdisco_open_Facturas)==1)
    {
        strcpy (apellido_a_buscar, Facturas.apellido);
		  pch = strstr (apellido_a_buscar, texto_a_buscar);
		  caracter = pch - apellido_a_buscar + 1;
		  if (caracter >= 0)
		  {
            cout << texto_a_buscar << " fue hallado..." << endl;
				cout << "--------------------------------------------------" << endl;
            cout << "FECHA = " << Facturas.fecha << endl;
            cout << "FACTURA = " << Facturas.numFactura << endl;
            cout << "APELLIDO = " << Facturas.apellido << endl;
            cout << "NOMBRES = " << Facturas.nombre << endl;
            cout << "DIRECCION = " << Facturas.direccion << endl;
            cout << "TELEFONO = " << Facturas.telefono << endl;
            cout << "NIT = " << Facturas.nit << endl;
            cout << "TOTAL = " << Facturas.total << endl;
				cout << "--------------------------------------------------" << endl;
            hallado=true;
        }
    };
    if (hallado==false)
    {
        cout <<"El texto buscado: " << texto_a_buscar << " no fue hallado" << endl;
    }
//Cerramos el archivo.
    fclose(archdisco_open_Facturas);
    return 0;
}


