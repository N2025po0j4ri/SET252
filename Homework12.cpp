// --------------------------------------------------------------------------------
// Name:	Nirupama Poojari
// Class:	C Programming 2
// Abstract:	Homework 12 – Recursion – Part 1
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int AddNumbers1To100Recursively(int intIndex);
int AddNumbersInRange(int start, int stop);
long factorial(long intNumber);
long fibonacci(long intNumber);
// void swap(int arr[], int idxa, int idxb);
/* 
void magicSquare(int n);
void magicSquareValue(int num[3][3], int n);
void solve(int arr[], int pos);
void printArray(int arr[]);
bool checkArr(int arr[]); */
void magicSquareRecur(int num[3][3], int n);
void magicSquareRecurPrint(int num[3][3], int n);
void magicSquareRecur1(int num[6][6], int order, int xaxis, int yaxis);
void magicSquareRecurPrint1(int num[6][6], int n);
void swap(int arr[6][6], int idxa, int idyb, int idxc, int idyd);

#define SQUARE_SIZE 9 

int anyLine = 0;
int currLine = 0;
int numSolutions = 0;
// --------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// --------------------------------------------------------------------------------
int main()
{  /* 
    int intTotal = 0;
    long lngNum = 0;
    //Step 1 - 2)	5050 is Maximum number of times a procedure can be called recursively on my machine.
    //Memory on my computer is  12 GB
    intTotal = AddNumbers1To100Recursively(0);
    printf("AddNumbers1To100Recursively %d\n", intTotal);
    intTotal = AddNumbersInRange(1,3);
    printf("AddNumbersInRange 1 & 3 returns %d\n", intTotal);
    //Step 2 - 3)	 - Factorial of 12 is the largest factorial that can be computed with this method on my computer.  
     for (long intNum = 1; intNum < 11; intNum += 1)
      {
          printf(" %d  |", factorial(intNum));
          printf(" %d  \n ", factorial(intNum + 10));

      } 
      
    
     lngNum = fibonacci(45);
     // Step 3 - 2)	 - 45 is the number for which the largest Fibonacci value can be computed with this method on my computer. 
     printf("fibonacci of 45 is %d\n", lngNum);
     
     printf("magic square of 3x3 without recursion\n");
     magicSquare(3); */

   /*  int arr[SQUARE_SIZE] = {1,2,3,4,5,6,7,8,9};
    printArray(arr);
    solve(arr, 0); */

   /*  int arr[3][3];
    magicSquareRecur(arr, 3);
    magicSquareRecurPrint(arr, 3);
    */
    int arr[6][6];
    magicSquareRecur1(arr, 1,0,0);
    magicSquareRecurPrint1(arr, 6);
    return 1;

}

// --------------------------------------------------------------------------------
// Name: AddNumbers1To100Recursively
// Abstract: Adds numbers 1 to 100 Recursively
// --------------------------------------------------------------------------------

int AddNumbers1To100Recursively(int intIndex)
{
    int intTotal = 0;
    intIndex += 1;

    intTotal += intIndex;

    if (intIndex < 100)
    {
        intTotal += AddNumbers1To100Recursively(intIndex);
    }
    return intTotal;
}

// --------------------------------------------------------------------------------
// Name: AddNumbers1To100Recursively
// Abstract: AddNumbersInRange, that takes a starting value and a stop value as parameters.
// The procedure  recursively adds all the numbers (inclusive) in the range.
// --------------------------------------------------------------------------------

int AddNumbersInRange(int start , int stop)
{ 
    int intTotal = 0;
    intTotal += start;
    start += 1;

    

    if (start <= stop)
    {
        intTotal += AddNumbersInRange(start,stop);
    }
    return intTotal;

}

// --------------------------------------------------------------------------------
// Name: factorial
// Abstract: Returns factorial of given number recursively
// --------------------------------------------------------------------------------

long factorial(long intNumber)
{
    long intFactorial = intNumber;
  //  for (int intIndex = intNumber; intIndex > 1; intIndex -= 1)
 //   {
    if (intNumber > 1) {
        intFactorial = intFactorial * factorial(intNumber - 1);
    }
 //   }
    return intFactorial;
}

// --------------------------------------------------------------------------------
// Name: fibonacci
// Abstract: Returns fibonacci of given number recursively
// --------------------------------------------------------------------------------
long fibonacci(long intNumber)
{
    long intFib = intNumber;
    //  for (int intIndex = intNumber; intIndex > 1; intIndex -= 1)
   //   {
    if (intNumber > 2) {
        intFib = fibonacci(intNumber - 2) + fibonacci(intNumber - 1);
    }
    else 
    {
        intFib = 1;
    }
    
    //   }
    return intFib;
}
void magicSquareRecur1(int num[6][6], int order, int xaxis, int yaxis)
{
    int x = 0;
    int med = 0;
    if (order == 1)
    {
        x = 5;
        med = 15;
    }
    else if (order == 2)
    {
        x = 14;
        med = 42;
    }
    else if (order == 3)
    {
        x = 23;
        med = 69;
    }
    else {
        x = 32;
        med = 96;
    }
    
    int n = xaxis + 3;
    int m = yaxis + 3;
    for (int i = xaxis; i < n; i++)
    {
        for (int j = yaxis; j < m; j++)
        {

            if (i == xaxis + 1 && j == yaxis + 1) {
                num[i][j] = x;
            }
            else if (i == xaxis + 0 && j == yaxis + 0) {
                num[i][j] = x + 3; //x + 1;
            }
            else if (i == xaxis + 0 && j == yaxis + 2) {
                num[i][j] = x + 1; //x + 3;
            }
            else if (i == xaxis + 2 && j == yaxis + 0) {
                num[i][j] = x - 1;//x - 3;
            }
            else if (i == xaxis + 2 && j == yaxis + 2) {
                num[i][j] = x - 3; // x - 1;
            }

        }
    }

    for (int i = xaxis; i < n; i++)
    {
        for (int j = yaxis; j < m; j++)
        {

            if (i == xaxis + 0 && j == yaxis + 1) {
                num[i][j] = 0;
                num[i][j] = med - num[xaxis +0][yaxis+0] - num[xaxis+0][yaxis+2];
            }
            else if (i == xaxis + 1 && j == yaxis + 0) {
                num[i][j] = 0;
                num[i][j] = med - num[xaxis+0][yaxis+0] - num[xaxis+2][yaxis+0];
            }
            else if (i == xaxis + 2 && j == yaxis + 1) {
                num[i][j] = 0;
                num[i][j] = med - num[xaxis+2][yaxis+0] - num[xaxis+2][yaxis+2];
            }
            else if (i == xaxis + 1 && j == yaxis + 2) {
                num[i][j] = 0;
                num[i][j] = med - num[xaxis+1][yaxis+0] - num[xaxis+1][yaxis+1];
            }
        }
    }
    if (order ==1)
    { 
        magicSquareRecur1(num, 2, xaxis +3, yaxis +3);
    }
    else if (order == 2) {
         magicSquareRecur1(num, 3, xaxis-3 , yaxis );
    }
    else if (order == 3) {
        magicSquareRecur1(num, 4, xaxis + 3, yaxis-3);
        swap(num, 0, 0, 3, 0);
       // swap(num, 1, 0, 4, 0);
        swap(num, 2, 0, 5, 0);
        swap(num, 1, 1, 4, 1);
    }
}
void magicSquareRecur(int num[3][3], int n)
{
    int x = 5;
    int med = 15;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            
            if (i == 1 && j == 1) {
                num[i][j] = x;
            }
            else if (i == 0 && j == 0) {
                num[i][j] = x + 1;
            }
            else if (i == 0 && j == 2) {
                num[i][j] = x + 3;
            }
            else if (i == 2 && j == 0) {
                num[i][j] = x - 3;
            }
            else if (i == 2 && j == 2) {
                num[i][j] = x - 1;
            }

        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (i == 0 && j == 1) {
                num[i][j] = 0;
                num[i][j] = 15 - num[0][0] - num[0][2];
            }
            else if (i == 1 && j == 0) {
                num[i][j] = 0;
                num[i][j] = 15 - num[0][0] - num[2][0];
            }
            else if (i == 2 && j == 1) {
                num[i][j] = 0;
                num[i][j] = 15 - num[2][0] - num[2][2];
            }
            else if (i == 1 && j == 2) {
                num[i][j] = 0;
                num[i][j] = 15 - num[1][0] - num[1][1];
            }
        }
    }
}
    void magicSquareRecurPrint(int arr[3][3], int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cout << arr[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    void magicSquareRecurPrint1(int arr[6][6], int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cout << arr[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    void swap(int arr[6][6], int idxa, int idyb, int idxc, int idyd)
    {
        int tmp = arr[idxa][idyb];
        arr[idxa][idyb] = arr[idxc][idyd];
        arr[idxc][idyd] = tmp;
    }
 /* 
// --------------------------------------------------------------------------------
// Name: magicSquare
// Abstract: Returns magicSquare of 3 x3
// --------------------------------------------------------------------------------
void magicSquare(int n) {
    int arr[3][3];
  //  for (int i = 0; i < n; i++)
  //  {
   //     for (int j = 0; j < n; j++)
   //     {
   //         arr[i][j] = n * i + j+ 1 ;
    //    }
   // } 
    magicSquareValue(arr,3);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
 
void magicSquareValue(int num[3][3], int n)
{
    
    for (int i = 1; i< n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            num[i][j] = n * n + 1 - num[i][j];
        }
    }

    int x, r = 0, c = n / 2;
    for (x = 1; x <= n * n; x++) {
        num[r][c] = x;
        if (x % n == 0) {
            r++;
        }
        else
        {
            r--; c--;
            if (r < 0)
                r += n;
            if (c < 0)
                c += n;
        }
    }
} */   
/* 
void solve(int arr[], int pos)
{
     if (pos >8)
    {
        if (checkArr(arr))
        {
            printArray(arr);
            numSolutions++;
        }
    }
    else
    { 
         for (int i = pos; i < 9; i++)
         {
             swap(arr, pos, i);
         }
            solve(arr, pos + 1);
          //  swap(arr, pos, pos + 1);
       // }
    }
} 
// swap two values in the square.
void swap(int arr[], int idxa, int idxb)
{
    int tmp = arr[idxa];
    arr[idxa] = arr[idxb];
    arr[idxb] = tmp;
} 
void printArray(int arr[])
{
    for (int i = 0; i < SQUARE_SIZE; i++)
    {
        std::cout << arr[i] << " ";
        if ((i + 1) % 3 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}
// this function tests to see if we have a "good" arrangement of numbers            
// i.e the sum of each row, column and diagonal is equal

bool checkArr(int arr[])
{
    anyLine = arr[0] + arr[1] + arr[2];
    currLine = 0;
    for (int i = 0; i < SQUARE_SIZE; i++)
    {
        currLine += arr[i];
        if ((i + 1) % 3 == 0)
        {
            if (currLine != anyLine)
                return false;
            currLine = 0;
        }
    }

    // check vertically
    for (int col = 0; col < 3; col++)
    {
        for (int row = 0; row < 3; row++)
        {
            currLine += arr[col + 3 * row];
        }

        if (currLine != anyLine)
            return false;

        currLine = 0;
    }

    // check the diagonals
    if ((arr[2] + arr[4] + arr[6]) != anyLine)
        return false;

    if ((arr[0] + arr[4] + arr[8]) != anyLine)
        return false;

    return true;
} */
/////
/* 
// C++ program to generate odd sized magic squares
#include <bits/stdc++.h>
using namespace std;

// A function to generate odd sized magic squares
void generateSquare(int n)
{
    int magicSquare[n][n];

    // set all slots as 0
    memset(magicSquare, 0, sizeof(magicSquare));

    // Initialize position for 1
    int i = n / 2;
    int j = n - 1;

    // One by one put all values in magic square
    for (int num = 1; num <= n * n;) {
        if (i == -1 && j == n) // 3rd condition
        {
            j = n - 2;
            i = 0;
        }
        else {
            // 1st condition helper if next number
            // goes to out of square's right side
            if (j == n)
                j = 0;

            // 1st condition helper if next number
            // is goes to out of square's upper side
            if (i < 0)
                i = n - 1;
        }
        if (magicSquare[i][j]) // 2nd condition
        {
            j -= 2;
            i++;
            continue;
        }
        else
            magicSquare[i][j] = num++; // set number

        j++;
        i--; // 1st condition
    }

    // Print magic square
    cout << "The Magic Square for n=" << n
        << ":\nSum of "
        "each row or column "
        << n * (n * n + 1) / 2 << ":\n\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)

            // setw(7) is used so that the matrix gets
            // printed in a proper square fashion.
            cout << setw(4) << magicSquare[i][j] << " ";
        cout << endl;
    }
}

// Driver code
int main()
{

    // Works only when n is odd
    int n = 7;
    generateSquare(n);
    return 0;
}
*/
