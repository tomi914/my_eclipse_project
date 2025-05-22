#include <stdio.h>

#include "bitwise.h"

int main(void){

	char instruccion;
	printf("Ingrese un numero del 0 al 7 si desea encender ese led.\n");
	printf("Ingrese una 't' si desea conmutar el estado de los leds.\n");
	printf("Ingrese una 'c' si desea apagar todos los leds.\n");
	printf("Ingrese una 's' si desea prender todos los leds.\n");
	printf("Ingrese una 'q' si desea salir del programa.\n");

	do{
		instruccion = getchar();
		switch(instruccion){
			case '0':	bitSet('A' , 0);
				break;
			case '1':	bitSet('A' , 1);
				break;
			case '2':	bitSet('A' , 2);
				break;
			case '3':	bitSet('A' , 3);
				break;
			case '4':	bitSet('A' , 4);
				break;
			case '5':	bitSet('A' , 5);
				break;
			case '6':	bitSet('A' , 6);
				break;
			case '7':	bitSet('A' , 7);
				break;
			case 't': 	maskToggle('A', 0xFF);
				break;
			case 'c':	maskOff('A', 0xFF);
				break;
			case 's':	maskOn('A', 0xFF);
				break;
			case 'q':
				break;
			case '\n':
				break;
			default:	printf("El caracter ingresado no es valido. \n");
				break;
		}
	}while(instruccion!='q');
	return 0;
}



