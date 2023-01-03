#include <stdio.h>
#include <stdlib.h>
#include "Vehicle.h"
#include "State.h"
#include "Functions.h"

#define WITH_ENGINE_TEMP_CONTROLLER 1

int main(void) {

	// Create an instance of vehicle and give some initial values
	struct vehicle v;
	initialize(&v);

	char input;
	do {
		// Display the options to the user to choose from
		printf("a.  Turn on the vehicle engine.\n");
		printf("b.  Turn off the vehicle engine.\n");
		printf("c.  Quit the system.\n");
		fflush(stdout);

		scanf(" %c", &input);

		if (input == 'a') {
			// Set the engine state to ON
			v.engineState = ON;
			printf("The vehicle engine is on.\n");
			fflush(stdout);
			char in;
			do {
				// Display sensors set menu
				sensorSetMenu();
				scanf(" %c", &in);
				if (in == 'b') {
					// Set the traffic light
					setTrafficLight(&v);
					if (v.speed == 30) {
						v.AC = ON;
						v.roomTemperature = v.roomTemperature * (5.0 / 4.0) + 1;
						v.engineTemperatureControllerState = ON;
						v.engineTemperature = v.engineTemperature * (5.0 / 4.0)
								+ 1;
					}
				} else if (in == 'c') {
					// Set room temperature
					setRoomTemperature(&v);
#if WITH_ENGINE_TEMP_CONTROLLER == 1
				} else if (in == 'd') {
					// Set engine temperature
					setEngineTemperature(&v);
#endif
				} else {
					// Set the vehicle state back to initial values
					initialize(&v);
				}
				if (in != 'a') {
					// Display the vehicle state after every choice
					display(v);
				}
			} while (in != 'a');
		} else if (input == 'b') {
			printf("The vehicle engine is OFF.\n");
			fflush(stdout);
		} else {
			printf("You quit the system.\n");
			fflush(stdout);
		}
	} while (input != 'c');

	return EXIT_SUCCESS;
}
