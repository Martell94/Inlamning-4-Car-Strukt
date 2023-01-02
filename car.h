#ifndef CAR_H_
#define CAR_H_

#include "Header.h"

/********************************************************************************
							  (ENUM) transm_t:
		Typdefinition av enumerationstyp, f�r bruk i v�r car-strukt.

							AUTOMATIC: Automatl�da
							MANUAL: Manuell l�da
							NDEF: Odefinierat.
********************************************************************************/
typedef enum transm {
	AUTOMATIC,
	MANUAL,
	NDEF,
} transm_t;


/*******************************************************************************
								(STRUCT) car_t:
 Typdefinition av strukttyp, inneh�llande all information om v�ra bil-instanser.

	make: Bilens m�rke.
	model: Bilens modelltyp.
	colour: Bilens f�rg.
	modelyear: Bilens modell�r.
	transmission: Bilens v�xell�detyp.
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


