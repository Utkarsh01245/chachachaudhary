#include <stdio.h>
#include <time.h>
#include<unistd.h>
#include<stdlib.h> 

void fill_time(char*, int); // Function declaration
void fill_date(char*); // Function declaration
int input_format();
void clear_screen();

int main() {
    char time[50], date[100]; // Buffer to hold the formatted time
    int format= input_format();


    while (1)
    {
        fill_time(time, format); // Fill the time based on the chosen format
        fill_date(date); // Fill the Date based on the chosen format
        clear_screen();
        printf("Current Time Is: %s\n", time); // Print the formatted time
        printf("\nDate Is: %s\n", date); // Print the formatted time
        sleep(1);
    }
    
    
    // Handle default case
    if (format != 1 && format != 2) {
        printf("Invalid choice! Defaulting to 12 Hour Format.\n");
        format = 2; // Set to 12 Hour Format
    }

   
    return 0; // Exit the program
}

void clear_screen(){
    #ifdef _WIN32
        system("cls");

    #else
        system("clear");
    #endif
}


void fill_date(char* buffer){

    time_t rawtime;
    struct tm *current_time;

    time(&rawtime); // Get the current time
    current_time = localtime(&rawtime); // Convert it to local time structure
    strftime(buffer, 100, "%A %d %B %Y", current_time); 

}


int input_format(){
    int format;

    printf("\n Choose the Time Format");
    printf("\n 1. 24 Hour Format");
    printf("\n 2. 12 Hour Format (DEFAULT)");
    printf("\n Make a choice (1 for 24, 2 for 12): ");
    scanf("%d", &format);
    return format;
}




void fill_time(char* buffer, int format) {
    time_t rawtime;
    struct tm *current_time;

    time(&rawtime); // Get the current time
    current_time = localtime(&rawtime); // Convert it to local time structure

    // Use the correct size of the buffer for strftime
    if (format == 1) {
        strftime(buffer, 50, "%H:%M:%S", current_time); // 24 Hour Format
    } else {
        strftime(buffer, 50, "%I:%M:%S %p", current_time); // 12 Hour Format
    }
}
