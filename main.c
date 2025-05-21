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
#define maskOn(puerto, mascara) ((mascara) | (puerto))
#define maskOff(puerto, mascara) (~(mascara) & (puerto))
#define maskToggle(puerto, mascara) ((mascara) ^ (puerto))

/*
bitSet: Dado un puerto y un número de bit, debe cambiar su estado a 1.

bitClr: Dado un puerto y un número de bit, debe cambiar su estado a 0.

bitGet: Dado un puerto y un número de bit, debe devolver su valor.

bitToggle: Dado un puerto y un número de bit, debe cambiar al estado opuesto en el que está (si está en 0
pasar a 1, y si está en 1 pasar a 0).

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

typedef struct{
			int8_t puertoA;
		    int8_t puertoB;
		    int16_t puertoD;
	}puertos_t;

int main(void){
	static puertos_t puertos = {2, 4};
	printf("%d\n", bitSet(puertos.puertoA, 0));
	printf("%d\n", bitClr(puertos.puertoB, 2));
	printf("%d\n", bitGet(puertos.puertoA, 0));
	printf("%d\n", bitToggle(puertos.puertoA, 0));
	printf("%X\n", maskOn(0x01, 0x0A));
	printf("%X\n", maskOff(0x0A, 0x02));
	printf("%X\n", maskToggle(0x02, 0x03));
}



