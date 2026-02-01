#include<stdio.h>
char gameboard [3][3];
void reset() {
    char ch = '1';
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            gameboard[i][j] = ch++;
        }
    }
}
void tacdisplay()
{
     printf(" ---|---|---");printf("\n");
  for(int i=0;i<3;i++)
  {
     printf("|");
      for(int j=0;j<3;j++)
      {
          printf(" %c ",gameboard[i][j]);
          printf("|");
      }printf("\n");
      printf(" ---|---|---");
      printf("\n");
  }

}
int winchk()
{
    for(int i=0;i<3;i++) {
        if(gameboard[i][0]==gameboard[i][1] && gameboard[i][1]==gameboard[i][2])
            return 1;
        if(gameboard[0][i]==gameboard[1][i] && gameboard[1][i]==gameboard[2][i])
            return 1;
    }
    if(gameboard[0][0]==gameboard[1][1] && gameboard[1][1]==gameboard[2][2])
        return 1;
    if(gameboard[0][2]==gameboard[1][1] && gameboard[1][1]==gameboard[2][0])
        return 1;
        
        return 0;
}
int main()
{
    char again;
    do{
        reset();
    int who=1;
    int win=0;
    char track;
    for(int i=0;i<9;i++)
    {
        tacdisplay();
        if(who==1){
            track='X';
            printf("Player 1 turn(X):\nEnter Position:");
        }
        else{
            track='O';
            printf("Player 2 turn(O):\nEnter Position:");
        }
        int choice;
        scanf("%d",&choice);
        if(choice<1 || choice>9)
        {
            printf("Position invaild,Position must be(1-9)\n ");
            i--;continue;}
        int r=(choice-1)/3;
        int c=(choice-1)%3;
        if(gameboard[r][c]!='X'&& gameboard[r][c]!='O')
        {
            gameboard[r][c]=track;
        }
        else {
            printf("Error,Place already occupied");
            i--;continue;
    }
    if(winchk())
    {
        tacdisplay();
        printf("Player %d wins!!",who);win=1;
        break;
    }
    if(who==1)
    {who=2;}
    else {
    who=1;}
    
} 
if(win==0){tacdisplay();
printf("Game Draw");}
printf("Do you want to play again? (y/n): ");
        scanf(" %c", &again);

    } while(again == 'y' || again == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}
