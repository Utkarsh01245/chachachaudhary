    #include<stdio.h>
    #include<stdlib.h>
    #include<time.h>
    int main(){
        int random, guess;
        int no_of_guess = 0;
        srand(time(NULL));

        printf("Welcome to Number Guessing Game:\n");
        random = rand() % 100 + 1; //Generating betwen number 0 to 1;
        do
        {
            printf("Guess A Number from 1 t0 100:#:\t   ");
            scanf("%d", &guess);
            no_of_guess++;

            if (guess < random)
            {
                printf("Guess a Larger Number\n");
            }else if (guess > random)
            {
                printf("Guess a Smaller Number\n");
                
            }else
            {
                printf("Answer is:================\t\t\t %d", random);
                printf("You have Successfully Guessed The Number!!!!!!! : )  !!!!!!!!!!!! ':-)\t in %d Attempts.", no_of_guess);
            }
            
            

        } while (guess != random);
        
        printf("\nBye \t Bye Thanks for Playing.");
        printf("\t Developed by Coder_ut.");

        system("pause");

    }