#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define CHAR_SIZE 15
#define SIZE 10

int main()
{
	SetConsoleTitle("Vote Manager-v0.7");
	system("color 04");
	
	FILE *fptr;
	char txt, filename[100];
	
	int option;
    char cat_name[CHAR_SIZE];
    char categories[SIZE][CHAR_SIZE];
    int cat_num;
    int i, j;
    int cat;
    int votes[SIZE] = {0};
    int vote_num = 0;
    int small, large, pos_small, pos_large;
	
	printf(" ============================================================");
    printf("\n ||                                                        ||");
    printf("\n ||                     VOTE MANAGER                       ||");
    printf("\n ||                   ver. 0.7  by pRx                     ||");
    printf("\n ||                                                        ||");
    printf("\n ============================================================");
    printf("\n\n");
	
	do
	{
		printf(" ********** MAIN MENU **********");
        printf("\n\n [1] Enter categories");
        printf("\n [2] Enter votes");
        printf("\n [3] Show results");
        printf("\n [4] Display statistics");
        printf("\n [5] Export the data");
        printf("\n [6] Exit");
		
		printf("\n\n Enter your choice: ");
        scanf("%d", &option);
        system("cls");
        
        switch(option)
        {
            case 1:
                printf(" Enter category name: ");
                scanf("%s", cat_name);
                
                printf("\n Enter number of categories: ");
                scanf("%d", &cat_num);
                
                printf("\n");
                
                for(i = 0; i < cat_num; i++)
                {
                    printf(" Enter category %d: ", i + 1);
                    scanf("%s", categories[i]);
                }
                
                system("cls");
                
                break;
                
            case 2:
                do
                {
                    vote_num++;
                    printf(" VOTE: %d", vote_num);
                    printf("\n\n What is your favorite %s?\n", cat_name);
                    
                    for(i = 0; i < cat_num; i++)
                    {
                        printf("\n [%d] %s", i + 1, categories[i]);
                    }
                    printf("\n [%d] Finish", cat_num + 1);
                    
                    printf("\n\n Enter your choice: ");
                    scanf("%d", &cat);
                    votes[cat - 1]++;
                    system("cls");
                } while(cat != (cat_num + 1));
                
                vote_num--;
                
                break;
                
            case 3:
                printf(" ****** Voting Results ******\n");
                printf("\n %15s \t Votes \t Histogram\n\n", cat_name);
                
                for(i = 0; i < cat_num; i++)
                {
                    printf(" %15s \t %d \t ", categories[i], votes[i]);
                    
                    for(j = 1; j <= votes[i]; j++)
                        printf("*");
                    
                    printf("\n");
                }
                
                printf("\n");
                
                break;
                
            case 4:
                small = votes[0];
                pos_small = 0;
                
                for(i = 1; i < cat_num; i++)
                {
                    if(votes[i] < small)
                    {
                        small = votes[i];
                        pos_small = i;
                    }
                }
                
                large = votes[0];
                pos_large = 0;
                
                for(i = 1; i < cat_num; i++)
                {
                    if(votes[i] > large)
                    {
                        large = votes[i];
                        pos_large = i;
                    }
                }
                
                printf(" Number of votes: %d", vote_num);
                printf("\n The most popular %s is: %s", cat_name, categories[pos_large]);
                printf("\n The least popular %s is: %s", cat_name, categories[pos_small]);
                printf("\n\n");
                
                break;
                
            case 5:
            	printf("--|NOTE| It will create the file in the folder where the program runs and set its name to (you will determine).\n\n-Do you want this data to be output as a file? -|Y|: YES |N|: NO(menu)-: ");
				scanf(" %c", &txt);
				
				if(txt == 'Y' || txt == 'y')
				{
					printf("\nEnter the filename to open (add .txt after name): ");
    				scanf("%s", filename);
					
					fptr = fopen(filename, "w");
					
					if (fptr == NULL)
				    {
				        printf("Could not open file");// add controller
				    }
				    else
					{
						fprintf(fptr, " ****** Voting Results ******\n\n %15s \t Votes \t Histogram\n\n", cat_name);
						
						for(i = 0; i < cat_num; i++)
		                {
		                    fprintf(fptr, " %15s \t %d \t ", categories[i], votes[i]);
		                    
		                    for(j = 1; j <= votes[i]; j++)
		                        fprintf(fptr, "*");
		                    
		                    fprintf(fptr, "\n");
		                }
		                
		                fprintf(fptr, "\n--------------------------------------------------\n");
		                fprintf(fptr, "\n Number of votes: %d", vote_num);
		                fprintf(fptr, "\n The most popular %s is: %s", cat_name, categories[pos_large]);
		                fprintf(fptr, "\n The least popular %s is: %s", cat_name, categories[pos_small]);
		                
		                fclose(fptr);
						
				        printf("\nThe file is created Successfully.\n\n");
				    }
				}
				else if(txt == 'N' || txt == 'n')
				{
					break;
				}
                
            case 6:
                break;
                
            default:
                printf(" ERROR: Invalid choice!\n");
        }
        
	} while(option != 6);
	
	return 0;
}
