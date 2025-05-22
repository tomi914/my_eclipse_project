#include <stdint.h>
#include <stdio.h>

#include "bitwise.h"

static puertos_t puertos;

/*
El puerto D es la combinacion entre el puerto A y B, siendo A la parte alta y B la parte baja del mismo,
por lo tanto, cada vez que se modifica un puerto, se deben actualizar el resto para que funcionen de
manera conjunta
*/

void bitSet(char puerto, uint16_t bit){ //Prende el bit deseado
	switch(puerto){
	case 'A': 	puertos.puertoA = BITSET(puertos.puertoA, bit);
				puertos.puertoD = BITSET(puertos.puertoD, bit+8);
			break;
	case 'B': 	puertos.puertoB = BITSET(puertos.puertoB, bit);
				puertos.puertoD = BITSET(puertos.puertoD, bit);
			break;
	case 'D': 	puertos.puertoD = BITSET(puertos.puertoD, bit);
				if(bit>=8){
					puertos.puertoA = BITSET(puertos.puertoA, bit-8);
				}
				else{
					puertos.puertoB = BITSET(puertos.puertoB, bit);
				}
			break;
	default:	 printf("Ingrese un puerto existente.");
			break;
	}
}

void bitClr(char puerto, uint16_t bit){ //Apaga el bit deseado
	switch(puerto){
	case 'A': 	puertos.puertoA = BITCLR(puertos.puertoA, bit);
				puertos.puertoD = BITCLR(puertos.puertoD, bit+8);
			break;
	case 'B': 	puertos.puertoB = BITCLR(puertos.puertoB, bit);
				puertos.puertoD = BITCLR(puertos.puertoD, bit);
			break;
	case 'D': 	puertos.puertoD = BITCLR(puertos.puertoD, bit);
				if(bit>=8){
					puertos.puertoA = BITCLR(puertos.puertoA, bit-8);
				}
				else{
					puertos.puertoB = BITCLR(puertos.puertoB, bit);
				}
			break;
	default: 	printf("Ingrese un puerto existente.");
			break;
	}
}

int bitGet(char puerto, uint16_t bit){ //Lee el bit deseado
	switch(puerto){
	case 'A': 	return BITGET(puertos.puertoA , bit);
			break;
	case 'B': 	return BITGET(puertos.puertoB , bit);
			break;
	case 'D': 	return BITGET(puertos.puertoD , bit);
			break;
	default: 	printf("Ingrese un puerto existente.");
				return -1;
			break;
	}
}

void bitToggle(char puerto, uint16_t bit){ //Conmuta el bit deseado
	switch(puerto){
	case 'A': 	puertos.puertoA = BITTOGGLE(puertos.puertoA, bit);
				puertos.puertoD = BITTOGGLE(puertos.puertoD, bit+8);
			break;
	case 'B': 	puertos.puertoB = BITTOGGLE(puertos.puertoB, bit);
				puertos.puertoD = BITTOGGLE(puertos.puertoD, bit);
			break;
	case 'D': 	puertos.puertoD = BITTOGGLE(puertos.puertoD, bit);
				if(bit>=8){
					puertos.puertoA = BITTOGGLE(puertos.puertoA, bit-8);
				}
				else{
					puertos.puertoB = BITTOGGLE(puertos.puertoB, bit);
				}
			break;
	default: 	printf("Ingrese un puerto existente.");
			break;
	}
}

void maskOn(char puerto, uint16_t mask){ //Prende los bits indicados en la mascara
	switch(puerto){
	case 'A': 	puertos.puertoA = MASKON(puertos.puertoA, mask);
				puertos.puertoD = MASKON(puertos.puertoD, mask << 8);
			break;
	case 'B': 	puertos.puertoB = MASKON(puertos.puertoB, mask);
				puertos.puertoD = MASKON(puertos.puertoD, mask);
			break;
	case 'D': 	puertos.puertoD = MASKON(puertos.puertoD, mask);
				puertos.puertoA = MASKON(puertos.puertoA, mask>>8);
				puertos.puertoB = MASKON(puertos.puertoB, mask);
			break;
	default: 	printf("Ingrese un puerto existente.");
			break;
	}
}

void maskOff(char puerto, uint16_t mask){ //Apaga los bits indicados en la mascara
	switch(puerto){
	case 'A': 	puertos.puertoA = MASKOFF(puertos.puertoA, mask);
				puertos.puertoD = MASKOFF(puertos.puertoD, mask << 8);
			break;
	case 'B': 	puertos.puertoB = MASKOFF(puertos.puertoB, mask);
				puertos.puertoD = MASKOFF(puertos.puertoD, mask);
			break;
	case 'D': 	puertos.puertoD = MASKOFF(puertos.puertoD, mask);
				puertos.puertoA = MASKOFF(puertos.puertoA, mask>>8);
				puertos.puertoB = MASKOFF(puertos.puertoB, mask);
			break;
	default: 	printf("Ingrese un puerto existente.");
			break;
	}
}

void maskToggle(char puerto, uint16_t mask){ //Conmuta los bits indicados en la mascara
	switch(puerto){
	case 'A': 	puertos.puertoA = MASKTOGGLE(puertos.puertoA, mask);
				puertos.puertoD = MASKTOGGLE(puertos.puertoD, mask << 8);
			break;
	case 'B': 	puertos.puertoB = MASKTOGGLE(puertos.puertoB, mask);
				puertos.puertoD = MASKTOGGLE(puertos.puertoD, mask);
			break;
	case 'D': 	puertos.puertoD = MASKTOGGLE(puertos.puertoD, mask);
				puertos.puertoA = MASKTOGGLE(puertos.puertoA, mask>>8);
				puertos.puertoB = MASKTOGGLE(puertos.puertoB, mask);
			break;
	default: 	printf("Ingrese un puerto existente.");
			break;
	}
}

