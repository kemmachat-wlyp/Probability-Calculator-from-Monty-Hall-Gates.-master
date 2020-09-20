#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define repeat 500000

struct UsersData{
    int win;
    int lose;
    int bobo;
    int gate;
    int slove;
    int comp1;
    int comp2;
}user1;

void UseTheory(ut){
    int i,j,k;
    int chart[repeat];
    user1.bobo = user1.gate-(user1.slove+1);

    if(user1.slove>user1.gate-2){
            printf("fail. Do not in rule of host laws");
    }


    for (i = 0; i < repeat; i++) {
        int winDoor = rand()%user1.gate;

        int firstPick = rand()%user1.gate;

        if (winDoor == firstPick) {
            user1.lose++;
            chart[i] = 0;
        }
        else {
            user1.win++;
            chart[i] = 1;
        }
    }
        printf("\t Switch by Theory");
        printf("\n\n\t Result from the 200 first of all");
        printf("\t\t 1 = game win");
        printf("\t 0 = game lose");
        printf("\n\n\n\n");
        k=0;
        for(i=0;i<20;i++){
            for(j = 0; j<10; j++){
                printf("\t");
                printf(" %d\t",chart[k]);
                k++;
            }
            printf("\n");
        }
            user1.comp1 = user1.win/user1.bobo;
            printf("\n\n\n");
            printf("\n\t %f percent win rate\n", (((float)user1.win/user1.bobo)/(float)repeat)*100.00);
            printf("\t we win %d and we lose %d\n\n\n",user1.win/user1.bobo,repeat-(user1.win/user1.bobo));

    }

void NoTheory(nt){
    int i,j,k;
    int winDoor = 0;
    int firstpick =0;
    user1.win=0;
    user1.lose=0;
    int chart[repeat];


    for (i = 0; i < repeat; i++) {
        int winDoor = rand()%user1.gate;

        int firstPick = rand()%user1.gate;

        if (winDoor == firstPick) {
            user1.win++;
            chart[i] = 1;

        } else {
            user1.lose++;
            chart[i] = 0;

        }
    }
        printf("\t Without Theory");
        printf("\n\n\t Result from the 200 first of all");
        printf("\t\t 1 = game win");
        printf("\t 0 = game lose");
        printf("\n\n\n");

        k=0;
        for(i=0;i<20;i++){
            for(j = 0; j<10; j++){
                printf("\t");
                printf(" %d\t",chart[k]);
                k++;
            }printf("\n");
        }
            user1.comp2 = user1.win;
            printf("\n\n\n");
            printf("\n\t %f percent win rate\n", (((float)user1.win)/(float)repeat)*100.00);
            printf("\t we win %d and we lose %d\n\n",user1.win,user1.lose);

}

void Comparison(cp){
    printf("\t Win by Theory %d game\n",user1.comp1);
    printf("\t Win by without Theory %d game\n\n",user1.comp2);
    if(user1.comp1>user1.comp2){
        printf("\t %d game win is result of comparison test between probability with situation probability. \n\t we know that a chance at change will give us more win\n\n",user1.comp1-user1.comp2);
    }
    else{
        printf("\t probability not following by the theory ");
    }

}

void InputData(ak){
    printf("\t How many your gate ? (recommend 3-4) : ");
    scanf("%d",&user1.gate);
    printf("\n\n");
    printf("\t How many door was slove ?  : ");
    scanf("%d",&user1.slove);
    printf("\n\n");
}

int main(){
    int i;
    char start;
    FILE *fptr;
    user1;
    fptr=fopen("datascore.txt","w");

    if (!fptr){
        printf("Could not open file to write.");
        return 1;
    }
    else{

        printf("---------------------------------------------------------------------------------------------------------------------------------\n\n");
        printf(" This program create for solve monty hall gate\n\n");
        printf(" The Monty Hall problem is a brain teaser, in the form of a probability puzzle,\n loosely based on the American television game show\n\n");
        printf(" Suppose you're on a game show, and you're given the choice of three doors: Behind one door is a car; behind the other is goats.\n At first you     pick some door of all \n Second the host who knows what's behind the doors will open some door of goats \n Then the host give the question to you (You have a chance Do you wanna change your choice ?)\n\n");
        printf("----------------------------------------------------------------------------------------------------------------------------------\n\n");
        printf("\n\t Start the program (y/n): ");
        scanf("%c",&start);
        printf("\n\n");

        if(start=='y'){

            InputData(user1);

            printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
            UseTheory(user1);
            printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
            printf("\n\n");

            printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
            NoTheory(user1);
            printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
            printf("\n\n");

            printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
            Comparison(user1);
            printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");

            fprintf (fptr,"Switch by Theory %d game win\n",user1.comp1);
            fprintf (fptr,"Without Theory %d game win",user1.comp2);

        }
        else {
            printf("Program was exit");
        }
    }
}

