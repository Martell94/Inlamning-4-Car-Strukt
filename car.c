#include "Header.h"


/********************************************************************************
								(void)car_init:
						  Initierar struktinstanser.

			self: Pekare till den struktinstans vi �nskar initiera.
			make: Bilens m�rke.
			model: Bilens modelltyp.
			colour: Bilens f�rg.
			modelyear: Bilens modell�r.
			transmission: Bilens v�xell�detyp.
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
					b�de terminal och angiven fil.

			self: Pekare till den struktinstans vi �nskar skriva ut.
			ostream: �nskad utstr�m, antingen till terminal eller angiven fil.
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

			self: Pekare till den struktinstans vi �nskar skriva ut.
			ostream: �nskad utstr�m, antingen till terminal eller angiven fil.
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
					  T�mmer struktinstanser p� information. 

			self: Pekare till den struktinstans vi �nskar nollst�lla.

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
	Raderar struktinstansen helt och frig�r det minnesutrymme den ockuperade.

			self: Pekare till den struktinstans vi �nskar radera.

********************************************************************************/
void car_delete(car_t** self){

	free(*self);
	*self = NULL;

	return;
};

/********************************************************************************
							(void)car_change_colour:
					  �ndrar f�rg p� angiven struktinstans.

			self: Pekare till den struktinstans vi �nskar �ndra.
			new_colour: Den nya f�rg vi �nskar tillskriva struktinstansen.

********************************************************************************/
void car_change_colour(car_t* self, char* new_colour){

	self->colour = new_colour;

	return;
}


/********************************************************************************
						  (void)car_change_transmission:
					  �ndrar v�xell�detyp p� angiven struktinstans.

			self: Pekare till den struktinstans vi �nskar �ndra.
			transmission_type: Den typ av v�xell�da vi �nskar �ndra till.

********************************************************************************/
void car_change_transmission(car_t* self, char* transmission_type){

	if (transmission_type == AUTOMATIC) self->transmission = AUTOMATIC;
	else if (transmission_type == MANUAL) self->transmission = MANUAL;
	else if (transmission_type == NDEF) self->transmission = NDEF;
	
	return;
}
