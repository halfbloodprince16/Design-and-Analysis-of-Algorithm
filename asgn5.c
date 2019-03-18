#include<stdio.h>
#define N 4

void printBoard(int board[N][N]) 
{
   for (int i = 0; i < N; i++) 
   {
      for (int j = 0; j < N; j++)
      {
      	printf("%d",board[i][j]);
      }
      printf("\n");
   }
}

_Bool isValid(int board[N][N], int row, int col) 
{
   for (int i = 0; i < col; i++)   
      if (board[row][i])
         return 0;
   for (int i=row, j=col; i>=0 && j>=0; i--, j--)
      if (board[i][j])      
         return 0;
   for (int i=row, j=col; j>=0 && i<N; i++, j--)
      if (board[i][j])   
         return 0;
   return 1;
}

_Bool solveNQueen(int board[N][N], int col)
{
   if (col >= N)          
      return 1;
   for (int i = 0; i < N; i++) 
   {    
      if (isValid(board, i, col)) 
      {
         board[i][col] = 1;     
         if ( solveNQueen(board, col + 1))  
            return 1;
                   
         board[i][col] = 0;      
      }
   }
   return 0;       
 }

_Bool checkSolution() 
{
   int board[N][N];
   for(int i = 0; i<N; i++)
      for(int j = 0; j<N; j++)
         board[i][j] = 0;      
               
   if (solveNQueen(board, 0) == 0) 
   {     
      printf("No Solution\n");
      return 0;
   }
   printBoard(board);
   return 1;
}

int main() 
{

   checkSolution();
}