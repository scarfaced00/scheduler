#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"

#define MAX_TYPE		7

//strings for printing the name of each enum element
//enum type's name
char type_string[MAX_TYPE][20] = 
{
	"drama",
	"movie",
	"advertisement",
	"entertainment",
	"meeting",
	"fitness",
	"privacy"
};

//month's name
char month_string[13][4] = 
{
	"", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
};

//enum definitions
typedef enum scheduleType {
	drama=0, 		//드라마 
	movie, 			//영화 
	advertisement, 	//광고 
	entertainment, 	//예능 
	meeting,		//회의 
	fitness,		//운동 
	privacy			//개인사 
} scheduleType_e;



//structure definition for a schedule info.
typedef struct schedInfo
{
	char name[200];			//schedule name
	scheduleType_e type;	//schedule type
	int month;				//when : month
	int day;				//when : day
	char place[100];		//where
} schedInfo_t;


void sched_printTypes(void) 
{
	int i;
	
	for (i=0;i<MAX_TYPE;i++) {
		printf("- %s\n", i, type_string[i]);
	}
}

void sched_print(void* obj) 
{
	schedInfo_t* schedPtr = (schedInfo_t*)obj;
	
	if (schedPtr == NULL) {
		printf("[ERROR] failed to print the schedule Info! (object is NULL)\n");
	}
	
	printf("Schedule Name : %s (%s)\n", schedPtr->name, type_string[schedPtr->type]);
	printf("When : %s. %i\n", month_string[schedPtr->month], schedPtr->day);
	printf("Where : %s\n", schedPtr->place);
	
	return;
}









//generating a structure of scheduling information
void* sched_genSchedInfo(char* name, char* place, int type, int month, int day)
{
	schedInfo_t* schedPtr;
	
	if (schedPtr==NULL)
		printf("Error!\n");//error handler

	//allocate memory and set the member variables
	schedPtr=malloc((sizeof)(struct schedInfo));
	strcpy(schedPtr->name, name);
	schedPtr->type=type;
	schedPtr->month=month;
	schedPtr->day=day;
	strcpy(schedPtr->place, place);
	
	return (void*)schedPtr;
}



//get month information from the scheduler info structure
float sched_getMonth(void* obj)
{
	schedInfo_t* schedPtr = (schedInfo_t*)obj;
	return schedPtr->month;
}


//get type information from the scheduler info structure
int sched_getType(void* obj)
{
	schedInfo_t* schedPtr = (schedInfo_t*)obj;
	return schedPtr->type;
}
 


//get place string information from the scheduler info structure
char* sched_getPlace(void* obj)
{
	schedInfo_t* schedPtr = (schedInfo_t*)obj;
	return schedPtr->place;	
}

//convert the name of the type into the enum(integer) value
int sched_convertType(char* typeName)
{
	if (strcmp(typeName, "drama") == 0)
		return 0;
	else if (strcmp(typeName, "movie") == 0)
		return 1;
	else if (strcmp(typeName, "advertisement") == 0)
		return 2;
	else if (strcmp(typeName, "entertainment") == 0)
		return 3;
	else if (strcmp(typeName, "meeting") == 0)
		return 4;
	else if (strcmp(typeName, "fitness") == 0)
		return 5;
	else if (strcmp(typeName, "privacy") == 0)
		return 6;
	}

