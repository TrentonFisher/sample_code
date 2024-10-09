#include <stdio.h>

int main() {
   
   int seats[24] = {0};  //Initalizing array with empty seat

    while (1) { //infinite loop
        
        int option; //Variable for user to make seat option

        printf("\nFor First Class, type 1, For Economy, type 2: ");
        
        scanf("%d", &option); //Taking input from user to pick seat

        int seatNum;
        if (option == 1) {
  
            for (seatNum = 0; seatNum < 5; seatNum++) { //For loop to assign first class seat if available
                if (seats[seatNum] == 0) {
                    seats[seatNum] = 1;  // Mark seat as taken
                    break;
                }
            }
            if (seatNum == 5) {
                
                // Asking if user would like seat in economy or not if first class is full
                printf("\nNo more seats left in first class, would you like a seat in economy? (y/n) ");
                
                char choice;

                scanf(" %c", &choice); //Input from user for choice

                if (choice == 'y') 
                    option = 2;

                else {
                    
                    printf("\nNext flight leaves in 3 hours."); //If user chooses 'n' or any other input, program exits
                    break;

                }
            }
        }


        if (option == 2) {
           
            for (seatNum = 5; seatNum < 24; seatNum++) { //For loop to assign economy seat if available
                
                if (seats[seatNum] == 0) {
                    seats[seatNum] = 1;  //Marking assigned seat as taken
                    break; //Ending seat selection loop

                }
            }

            if (seatNum == 24) { //checking if seats are all taken
                
                // if all the seats are taken, message is displayed showing so
                printf("\nunfortunately all seats on this flight are taken, the next flight will leave in 3 hours\n");
                break; //Ending the infinite loop

            }
        }

        // Printing boarding pass
        
        printf("\n-----------------\n");
        printf("Boarding pass:\n");
        printf("Seat number: %d", seatNum + 1); //Showing seat number depending on class 


        if (option == 1) { //If statement to display proper class on boarding pass

            printf("\nClass: First Class"); 
            printf("\n-----------------\n\n"); //Adding first class to boarding pass if option = 1

        }
         
         else if (option == 2) {
            
            printf("\nClass: Economy");
            printf("\n-----------------\n\n"); //Adding first class to boarding pass if option = 2

        }
    
    }

    return 0;

}
