#include "Header.h"

/*Deklareras för senare bruk.*/
car_t car1, car2, car3;
car_t* cars[];

/********************************************************************************
									(int)main:
 Programmets startpunkt. Här ligger både uppgift 1 och 2, där den utkommenterade
 for-loopen är uppgift ett, där vi itererar genom vårat cars-array.

			return: Returnerar 0 ifall programmet exekverats som det ska.
********************************************************************************/
int main (void){

	FILE* ostream = fopen("cars.txt", "a");

	car_init(&car1, "Volvo", "V70", "Black", 1995, MANUAL);
	car_init(&car2, "BMW", "Z3", "Blue", 2001, AUTOMATIC);
	car_init(&car3, "Skoda", "Octavia RS", "White", 2003, MANUAL);

	car_t* cars[3] = {&car1,&car2,&car3};

	/*for (int i = 0; i < sizeof(cars) / sizeof(cars[0]); i++)
	{
		car_print(cars[i], 0);
	}*/

	car1.print(&car1, ostream);
	car2.print(&car2, ostream);
	car3.print(&car3, ostream);

	car1.print(&car1, 0);
	car2.print(&car2, 0);
	car3.print(&car3, 0);


	car3.change_colour(&car3, "Green");
	car3.change_transmission(&car3, AUTOMATIC);
	car3.print(&car3, 0);


	fclose(ostream);
	file_read("cars.txt");

	return 0;
}