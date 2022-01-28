/*
 ============================================================================
 Name        : Project.c
 Author      : Belal_Badr

 Description : This Project is used to control & Display Vehicle parameters (engine state, Vehicle
                speed, room temperature, and engine temperature) based on given inputs.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#define ON 1
#define OFF 0

struct Vehicle{
	char engine_state ;
	char AC ;
	int vehicle_speed;
	float room_temp;
	char temp_controller_state ;
	float engine_temp ;
};
struct Vehicle vehicle_1;// declaring a global object from the structure so we can access it in any function
struct Vehicle *V1=&vehicle_1; // Saving the address of the object in a pointer to make at easier at accessing

void initialize_vehicle(void)
{
	V1->engine_state = OFF;
	V1->AC = OFF;
	V1->vehicle_speed=0;
	V1->room_temp=0;
	V1->temp_controller_state = OFF;
	V1->engine_temp = 0;
}

void traffic_light(void) // function to edit the speed of the vehicle based on the state of the traffic light
{
	printf("Enter the state of the traffic light \n");
	char state;
	scanf(" %c",&state);
	if((state=='G')||(state=='g'))
		V1->vehicle_speed=100;
	else if((state=='O')||(state=='o'))
		V1->vehicle_speed=30;
	else if((state=='R')||(state=='r'))
		V1->vehicle_speed=0;

	if(V1->vehicle_speed==30)
	{
		V1->AC = ON;
		V1->room_temp=(V1->room_temp)*(5.0/4)+1;
		V1->temp_controller_state = ON;
		V1->engine_temp=(V1->engine_temp)*(5.0/4)+1;
	}

}

void room_temp(void) // function to edit the room temperature & AC based on the temperature
{
	short temp;
	printf("Enter the room temperature !! \n");
	scanf("%d", &temp);
	if((temp<10)||(temp>30))
	{
		V1->AC = ON;
		V1->room_temp =20;
	}
	else V1->AC = OFF;
}

void engine_temp(void)  // function to edit the the temperature & AC based on the temperature
{
	short temp;
	printf("Enter the engine temperature ! \n");
	scanf("%d",&temp);
	if((temp<100)||(temp>150))
	{
		V1->temp_controller_state = ON;
		V1->engine_temp=125;
	}
	else V1->temp_controller_state = OFF;
}

void display_state(void)
 {
	 printf("\n \t THE CURRENT STATE OF THHE VEHICLE \n");
	 printf("Engine State                        :");
	 {
		 if(V1->engine_state) printf("ON \n");
	     else printf("OFF \n");
	 }
	 printf("AC                                  :");
	 {
		 if(V1->AC) printf("ON \n");
		 else printf("OFF \n");
	 }
	 printf("Vehicle Speed                       : %d Km\h \n",V1->vehicle_speed);
	 printf("Room Temperature                    : %f \n",V1->room_temp);
	 printf("Engine Temperature Controller State :");
	 {
		 if(V1->temp_controller_state) printf("ON \n");
		 else printf("OFF \n");
	 }
	 printf("Engine Temperature                  : %f \n",V1->engine_temp);

	 printf("\n \n");

 }

void choice_1(void)
{
	char choice;
	while(1)
	{
		printf("a.Turn OFF the Engine \nb.Set the traffic light color. \nc.Set the room temperature. \nd.Set the engine temperature  \n");
		scanf(" %c",&choice);
		switch(choice)
		{
        case 'a': V1->engine_state = OFF;
        	      display_state();
                  return;
        case 'b': traffic_light();
                  display_state();
                  break;
        case 'c': room_temp();
                  display_state();
                  break;
        case 'd': engine_temp();
                  display_state();
                  break;
        default : printf("Wrong Choice \n");
		}
	}
}

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	initialize_vehicle(); //Initializing our Vehicle
	char choice;
	while(1)
	{
		printf("a.Turn ON the Vehicle Engine \nb.Turn OFF the Vehicle Engine. \nc.Exit. \n \n");
		scanf(" %c",&choice);
		switch(choice)
		{
        case 'a': V1->engine_state = ON;
        	      display_state();
                  choice_1();
                  break;
        case 'b': display_state();
                  break;
        case 'c': display_state();
                  exit(1);
                  break;
        default : printf("Wrong Choice !! \n");
                  break;
		}
	}
}
