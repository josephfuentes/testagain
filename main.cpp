#include "Evaluador.h"
#include <fstream>
#include <math.h>
#include <iostream>
#include <cstring>
using namespace std;

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo de texto
void escribirNumeroTexto(string nombre_archivo, int num)
{
    ofstream out(nombre_archivo.c_str());
  // while(!out.eof()) {
     out<<num;
   //}

    out.close();


}
int leerNumeroTexto(string nombre_archivo)
{
 ifstream in(nombre_archivo.c_str());

    int num;
    while((in>>num) != NULL)
    {
        return num;

    }
    in.close();
    return -1;

}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo de texto
void escribirStringTexto(string nombre_archivo, string str)
{
     ofstream out(nombre_archivo.c_str());
     out<<str;
}
string leerStringTexto(string nombre_archivo)
{
   ifstream in(nombre_archivo.c_str());

    string num;
    while(in>>num)
    {
        in>>num;
        return num;

    }
    in.close();
    return "";
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo binario
void escribirNumeroBinario(string nombre_archivo, int num)
{
     ofstream out(nombre_archivo.c_str());
      out.write((char*)&num,4);
      out.close();

}
int leerNumeroBinario(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str(),ios::ate);
    int tamano = in.tellg();
    in.seekg(0);
    while(in.tellg()<tamano)
    {
        int num;
        in.read((char*)&num,4);
        return num;
    }
    in.close();
    return -1;
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo binario
void escribirStringBinario(string nombre_archivo, string str)
{
    ofstream out(nombre_archivo.c_str());
      out.write(str.c_str(),10);
      out.close();
}
string leerStringBinario(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str(),ios::ate);
    int tamano = in.tellg();
    in.seekg(0);
    while(in.tellg()<tamano)
    {
        char nombre[10];
        in.read(nombre,10);
        return nombre;
    }
    in.close();
    return "";
}

//Devuelve true si encuentra str (dada) en un archivo dado el nombre
bool existe(string nombre_archivo, string str)
{
    ifstream in(nombre_archivo.c_str(),ios::ate);
    int tamano = in.tellg();
    in.seekg(0);
    while(in.tellg()<tamano)
    {
        char nombre[50];
        in.getline(nombre,50);
       // in.read(nombre,50);
//        if(nombre==str.c_str()){
//        return true;
//        }else{
//            return false;
//        }
        if(strcmp(nombre,str.c_str())==0){
        return true;
        }else{
            return false;
        }
    }

    in.close();
 return false;
}

//Devuelve el numero mayor dado el nombre de un archivo binario
int obtenerMayor(string nombre)
{
    ifstream in(nombre.c_str(),ios::ate);
    int tamano = in.tellg();
    in.seekg(0);
    int mayor=0;
    while(in.tellg()<tamano)
    {
        int score;
        in.read((char*)&score,sizeof(int));

        if(mayor<score)
        {
            mayor = score;
        }

    }
     return mayor;
    in.close();

    return -1;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
