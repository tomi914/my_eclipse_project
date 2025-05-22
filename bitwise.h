#ifndef BITWISE_H_
#define BITWISE_H_

#define BITSET(puerto, bit) (1<<(bit) | (puerto))
#define BITCLR(puerto, bit) (0<<(bit) & (puerto))
#define BITGET(puerto, bit) (1<<(bit) & (puerto)?1:0)
#define BITTOGGLE(puerto, bit) (1<<(bit) ^ (puerto))
#define MASKON(puerto, mascara) ((mascara) | (puerto))
#define MASKOFF(puerto, mascara) (~(mascara) & (puerto))
#define MASKTOGGLE(puerto, mascara) ((mascara) ^ (puerto))

typedef struct{
			int8_t puertoA;
		    int8_t puertoB;
		    int16_t puertoD;
	}puertos_t;

	void bitSet(char puerto, uint16_t bit); //Prende el bit deseado
	void bitClr(char puerto, uint16_t bit); //Apaga el bit deseado
	int bitGet(char puerto, uint16_t bit); //Lee el bit deseado
	void bitToggle(char puerto, uint16_t bit); //Conmuta el bit deseado
	void maskOn(char puerto, uint16_t mask); //Prende los bits indicados en la mascara
	void maskOff(char puerto, uint16_t mask); //Apaga los bits indicados en la mascara
	void maskToggle(char puerto, uint16_t mask); //Conmuta los bits indicados en la mascara

#endif /* BITWISE_H_ */
