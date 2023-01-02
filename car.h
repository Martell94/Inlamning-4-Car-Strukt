#ifndef CAR_H_
#define CAR_H_

#include "Header.h"

/********************************************************************************
							  (ENUM) transm_t:
		Typdefinition av enumerationstyp, för bruk i vår car-strukt.

							AUTOMATIC: Automatlåda
							MANUAL: Manuell låda
							NDEF: Odefinierat.
********************************************************************************/
typedef enum transm {
	AUTOMATIC,
	MANUAL,
	NDEF,
} transm_t;


/*******************************************************************************
								(STRUCT) car_t:
 Typdefinition av strukttyp, innehållande all information om våra bil-instanser.

	make: Bilens märke.
	model: Bilens modelltyp.
	colour: Bilens färg.
	modelyear: Bilens modellår.
	transmission: Bilens växellådetyp.
	void (*change_colour): Funktionspekare till car_change_colour.
	void (*change_transmission): Funktionspekare till car_change_transmission.
	void (*print): Funktionspekare till car_print.

********************************************************************************/
typedef struct {
	char* make;
	char* model;
	char* colour;
	unsigned int modelyear;
	transm_t transmission;

	void (*change_colour)(struct car_t* self, char* new_color);
	void (*change_transmission)(struct car_t* self, transm_t new_transmission);
	void (*print)(struct car_t* self, FILE* ostream);

}car_t;


#endif // !CAR_H_


