//Universidad Estatal a Distancia
//Escuela de Ciencias Sociales
//Cátedra de Tecnología de Sistemas
//000831 - Introducción a la Programación
//Prof. Johan Manuel Acosta Ibáñez
//Cuatrimestre II - 2020

//Tarea #2
//Encriptar y desencriptar un mensaje
//Estudiante: Dayron Antony Chaves Sandoval
//Cedula: 0305240018
//Fecha de Entrega: 02 de Agosto del año 2020

//Incluir las librerías
#include <iostream>
#include <cstring>

using namespace std;

//Prototipos de funciones
void Encriptar ( char* );
void Desencriptar ( char* );

//Función Principal
int main()
{
    //Declaración de variables y el arreglo
    bool en_bucle = true;
    int cantidad_mensajes = 1;
    char mensaje_usuario[100];
    char arreglo[500];

    //Presentación
    cout << "Este programa encriptara y desencriptara textos por usted." << endl;
    cout << "Considere lo siguiente: " << endl;
    cout << "Al encriptar..." << endl;
    cout << ">> Solo se encriptaran vocales simples, las tildes serán ignoradas." << endl;
    cout << "Al desencriptar..." << endl;
    cout << ">> Si su vocal era una mayúscula se convertirá en minúscula." << endl;
    cout << "\n";
    cout << "[5 MENSAJES DE 100 CARACTERES | 500 CARACTERES MÁXIMO]" << endl;


    do //Se entra en bucle
    {
        for ( cantidad_mensajes = 1; cantidad_mensajes < 6; cantidad_mensajes++ ) //Se establece un contador hasta 5.
        {
            cout << "\n";
            cout << "Digite el mensaje No°"<< cantidad_mensajes << ":" << endl; //Se solicitan los datos al usuario
            cin.getline ( mensaje_usuario, 101, '\n' ); //Se lee el mensaje y se establece un limite de 100 caracteres para la cadena (100 + '\0').
            Encriptar ( mensaje_usuario ); //Al obtener el mensaje se encripta inmediatamente llamando una función.


            //Método de llenado:
            if ( ( cantidad_mensajes == 1 ) )
            {
                strncpy ( arreglo, mensaje_usuario, 100 ); //Si es el primer mensaje, solo se copia al arreglo.
            }
            else
            {
                strncat ( arreglo, mensaje_usuario, 100 ); //De otro modo, se unirá esta frase a otra ya existente anteriormente.
            }


            if ( ( cantidad_mensajes == 5 ) )  //Si la cantidad de mensajes es 5, se sale del bucle.
            {
                en_bucle = false;
            }

        }
    }
    while ( en_bucle == true );

    //Método de despliegue:
    //Primero se muestra la información encriptada con propósitos comparativos.
    cout << "\n";
    cout << "El mensaje encriptado es:" << endl;
    cout << arreglo << endl;

    //Luego se desencripta el arreglo llamando una función.
    Desencriptar ( arreglo );

    //Y finalmente se despliega la información desencriptada del arreglo.
    cout << "\n";
    cout << "El mensaje desencriptado es:" << endl;
    cout << arreglo << endl;

    return 0;
}

//-------------------------------------------------------------------------------------------------------------------------//

//Función 1: Recibe por parámetro el mensaje y lo encripta.
void Encriptar ( char *Mensaje )
{
    while ( *Mensaje != '\0' ) //Se entra en bucle, se recorrerá toda la cadena hasta llegar al carácter nulo.
    {

        if ( *Mensaje == 'A' || *Mensaje == 'a' ) //Si el mensaje contiene "X" mayúscula o minúscula...
        {
            *Mensaje = '#'; //Se intercambia por un símbolo...
            Mensaje += 1;   //Y se pasa al siguiente carácter...
        }


        else if ( *Mensaje == 'E' || *Mensaje == 'e' )
        {
            *Mensaje = '$';
            Mensaje += 1;
        }


        else if ( *Mensaje == 'I' || *Mensaje == 'i' )
        {
            *Mensaje = '%';
            Mensaje += 1;
        }


        else if ( *Mensaje == 'O' || *Mensaje == 'o' )
        {
            *Mensaje = '*';
            Mensaje += 1;
        }


        else if ( *Mensaje == 'U' || *Mensaje == 'u' )
        {
            *Mensaje = '&';
            Mensaje += 1;
        }


		else
		{
            *Mensaje = *Mensaje; //Si una vocal no es detectada se conserva el texto original.
            Mensaje += 1;
		}


    }
}

//Función 2: Recibe el arreglo encriptado por parámetro y lo desencripta.
//Es el inverso de la función de encriptado: busca símbolos y los cambia por letras.
void Desencriptar ( char *Mensaje )
{
    while ( *Mensaje != '\0' )
    {

        if ( *Mensaje == '#' )
        {
            *Mensaje = 'a';
            Mensaje += 1;
        }


        else if ( *Mensaje == '$' )
        {
            *Mensaje = 'e';
            Mensaje += 1;
        }


        else if ( *Mensaje == '%' )
        {
            *Mensaje = 'i';
            Mensaje += 1;
        }


        else if ( *Mensaje == '*' )
        {
            *Mensaje = 'o';
            Mensaje += 1;
        }


        else if ( *Mensaje == '&' )
        {
            *Mensaje = 'u';
            Mensaje += 1;
        }


		else
		{
            *Mensaje = *Mensaje;
            Mensaje += 1;
		}


    }
}
