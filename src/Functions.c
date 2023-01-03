#include <stdio.h>
#include "State.h"
#include "Vehicle.h"

#define WITH_ENGINE_TEMP_CONTROLLER 1

void initialize(struct vehicle *ptr) {
	ptr->engineState = OFF;
	ptr->AC = OFF;
	ptr->speed = 0;
	ptr->roomTemperature = 35;
	ptr->engineTemperatureControllerState = OFF;
	ptr->engineTemperature = 90;
}

void sensorSetMenu() {
	printf("a. Turn off the engine.\n");
	printf("b. Set the traffic light color.\n");
	printf("c. Set the room temperature.\n");
#if WITH_ENGINE_TEMP_CONTROLLER == 1
	printf("d. Set the engine temperature.\n");
#endif
	fflush(stdout);
}

void display(struct vehicle v) {
	if (v.engineState == OFF) {
		printf("Engine is OFF.\n");
	} else {
		printf("Engine is ON.\n");
	}

	if (v.AC == OFF) {
		printf("AC is OFF.\n");
	} else {
		printf("AC is ON.\n");
	}

	printf("Speed = %d km/h.\n", v.speed);
	printf("Room temperature = %0.2f C.\n", v.roomTemperature);

#if WITH_ENGINE_TEMP_CONTROLLER == 1
	if (v.engineTemperatureControllerState == OFF) {
		printf("Engine temperature controller is OFF.\n");
	} else {
		printf("Engine temperature controller is ON.\n");
	}

	printf("Engine temperature = %0.2f C.\n", v.engineTemperature);
#endif
}

void setTrafficLight(struct vehicle *ptr) {
	printf("Enter the color.\n");
	fflush(stdout);

	char color;
	scanf(" %c", &color);
	if (color == 'G') {
		ptr->speed = 100;
	} else if (color == 'O') {
		ptr->speed = 30;
	} else {
		ptr->speed = 0;
	}
}

void setRoomTemperature(struct vehicle *ptr) {
	printf("Enter the temperature.\n");
	fflush(stdout);

	float temperature;
	scanf("%f", &temperature);

	if (temperature < 10 || temperature > 30) {
		ptr->AC = ON;
		ptr->roomTemperature = 20;
	} else {
		ptr->AC = OFF;
	}
}

void setEngineTemperature(struct vehicle *ptr) {
	printf("Enter the temperature.\n");
	fflush(stdout);

	float temperature;
	scanf("%f", &temperature);

	if (temperature < 100 || temperature > 150) {
		ptr->engineTemperatureControllerState = ON;
		ptr->engineTemperature = 125;
	} else {
		ptr->engineTemperatureControllerState = OFF;
	}
}
