#include "Header.h"


/********************************************************************************
								(void)car_init:
						  Initierar struktinstanser.

			self: Pekare till den struktinstans vi önskar initiera.
			make: Bilens märke.
			model: Bilens modelltyp.
			colour: Bilens färg.
			modelyear: Bilens modellår.
			transmission: Bilens växellådetyp.
********************************************************************************/
void car_init(car_t* self, 
			  char* make,
			  char* model, 
			  char* colour, 
			  unsigned int modelyear, 
			  transm_t transmission){

	self->make = make;
	self->model = model;
	self->colour = colour;
	self->modelyear = modelyear;
	self->transmission = transmission;

	self->change_colour = car_change_colour;
	self->change_transmission = car_change_transmission;
	self->print = car_print;
	//self->array_print = car_array_print;

	return;
}


/********************************************************************************
								(void)car_print_all:
					Skriver ut struktinstansernas information till
					både terminal och angiven fil.

			self: Pekare till den struktinstans vi önskar skriva ut.
			ostream: Önskad utström, antingen till terminal eller angiven fil.
********************************************************************************/
void car_print_all(car_t* self, FILE* ostream){

	car_print(self, 0);
	car_print(self, ostream);

	return;
}


/********************************************************************************
								(void)car_print:
					Skriver ut struktinstansernas information till 
					antingen terminal, eller angiven fil.

			self: Pekare till den struktinstans vi önskar skriva ut.
			ostream: Önskad utström, antingen till terminal eller angiven fil.
********************************************************************************/
void car_print(car_t* self, FILE* ostream) {

	if (!ostream) ostream = stdout;

	char* transm = "lorem ipsum";
	if (self->transmission == AUTOMATIC) transm = "Automatic";
	else if (self->transmission == MANUAL) transm = "Manual";
	else if (self->transmission == NDEF) transm = "(null)";

	fprintf(ostream, "------------------------------------------------------------\n");

	fprintf(ostream, "Make: %s\nModel: %s\nColour: %s\nModel Year: %d\nTransmission type: %s\n", self->make, self->model, self->colour, self->modelyear, transm);

	fprintf(ostream, "------------------------------------------------------------\n");

	return;
}

/********************************************************************************
								(void)car_clear:
					  Tömmer struktinstanser på information. 

			self: Pekare till den struktinstans vi önskar nollställa.

********************************************************************************/
void car_clear(car_t* self){

	self->make = NULL;
	self->model = NULL;
	self->colour = NULL;
	self->modelyear = 0;
	self->transmission = NDEF;

	self->print = NULL;
	self->change_colour = NULL;
	self->change_transmission = NULL;

	return;
};

/********************************************************************************
								(void)car_delete:
	Raderar struktinstansen helt och frigör det minnesutrymme den ockuperade.

			self: Pekare till den struktinstans vi önskar radera.

********************************************************************************/
void car_delete(car_t** self){

	free(*self);
	*self = NULL;

	return;
};

/********************************************************************************
							(void)car_change_colour:
					  Ändrar färg på angiven struktinstans.

			self: Pekare till den struktinstans vi önskar ändra.
			new_colour: Den nya färg vi önskar tillskriva struktinstansen.

********************************************************************************/
void car_change_colour(car_t* self, char* new_colour){

	self->colour = new_colour;

	return;
}


/********************************************************************************
						  (void)car_change_transmission:
					  Ändrar växellådetyp på angiven struktinstans.

			self: Pekare till den struktinstans vi önskar ändra.
			transmission_type: Den typ av växellåda vi önskar ändra till.

********************************************************************************/
void car_change_transmission(car_t* self, char* transmission_type){

	if (transmission_type == AUTOMATIC) self->transmission = AUTOMATIC;
	else if (transmission_type == MANUAL) self->transmission = MANUAL;
	else if (transmission_type == NDEF) self->transmission = NDEF;
	
	return;
}
