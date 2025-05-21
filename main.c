/*
 * main.c
 *
 *  Created on: May 21, 2025
 *      Author: progra
 */

#include <stdint.h>
#define bitSet(puerto, bit) (1<<(bit) | (puerto))
#define bitClr(puerto, bit) (0<<(bit) & (puerto))
#define bitGet(puerto, bit) (1<<(bit) & (puerto)?1:0)
#define bitToggle(puerto, bit) (1<<(bit) ^ (puerto))
/*

maskOn: Dado un puerto y una máscara, debe prender todos aquellos bits que estén prendidos en la máscara,
sin cambiar el estado de los restantes. Por ejemplo, dado el puerto A, que originalmente se encuentra en el
estado 0x01, al aplicarle la máscara 0x0A, el resultado será 0xB.

maskOff: Dado un puerto y una máscara, debe apagar todos aquellos bits que estén prendidos en la máscara,
sin cambiar el estado de los restantes. Por ejemplo, dado el puerto A, que originalmente se encuentra en el
estado 0x0A, al aplicarle la máscara 0x02, el resultado será 0x08.

maskToggle: Dado un puerto y una máscara, debe cambiar el estado de todos aquellos bits que estén prendidos
en la máscara al opuesto, sin cambiar el estado de los restantes. Por ejemplo, dado el puerto A, que
 originalmente se encuentra en el estado 0x02, al aplicarle la máscara 0x03, el resultado será 0x01.
*/
int main(void){
	int8_t puertoA;
	int8_t puertoB;
	int16_t puertoD;
	puertoA = 2;
	puertoB = 4;
	printf("%d\n", bitSet(puertoA, 0));
	printf("%d\n", bitClr(puertoB, 2));
	printf("%d\n", bitGet(puertoA, 0));
	printf("%d\n", bitToggle(puertoA, 1));
}



