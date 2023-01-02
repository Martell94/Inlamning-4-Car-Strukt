#ifndef HEADER_H_
#define HEADER_H_

/* Div. inkluderingsdirektiv */
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "car.h"


/* Div. funktionshuvuden. */
void car_init(car_t* self, char* make, char* model, char* colour, unsigned int modelyear, transm_t transmission);
void car_print(car_t* self, FILE* ostream);
void car_clear(car_t* self);
void car_change_colour(car_t* self, char* new_colour);
void car_change_transmission(car_t* self, char* transmission_type);
void car_delete(car_t** self);
void file_read(const char* filepath);

#endif // HEADER_H_

