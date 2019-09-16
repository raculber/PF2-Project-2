#include <cstdlib>
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;
//------------------------------------------------------------------
// Initialize data array with random values
//------------------------------------------------------------------
void createRandomData(int data[], int count, int range)
{
   // Put specified count of random numbers into data array
   for (int index = 0; index < count; index++)
      data[index] = rand() % range;
}

//------------------------------------------------------------------
// Initialize data array with mostly sorted values
//------------------------------------------------------------------
void createMostlySortedData(int data[], int count, int swaps)
{
   // Put sorted data values into array
   for (int index = 0; index < count; index++)
      data[index] = index;

   // Shuffle data by swapping random pairs of values
   for (int index = 0; index < swaps; index++)
   {
      int pos1 = rand() % count;
      int pos2 = rand() % count;
      int temp = data[pos1];
      data[pos1] = data[pos2];
      data[pos2] = temp;
   }
}

//------------------------------------------------------------------
// Write data array to output file
//------------------------------------------------------------------
void writeData(string name, int data[], int count)
{
   // Open output file
   ofstream dout;
   dout.open(name.c_str());
   if (dout.fail())
      cout << "Error: could not open output file\n";

   // Write the data
   dout << count;
   for (int i = 0; i < count; i++)
   {
      if (i % 20 == 0)
	 dout << endl;
      dout << data[i] << " ";
   }

   // Close the file
   dout.close();
}
//------------------------------------------------------------------
// Bubble sort algorithm
// Best case O(N) - sorted data
// Worst case O(N^2) - reverse sorted data
// Average case O(N^2) - random data
//------------------------------------------------------------------
void bubbleSort(int data[], int low, int high)
{
  // Get start time
  clock_t time1=clock();
   // Bubble largest value to the right N times
   int pass = 1;
   int exchange = 1;
   int count = high - low + 1;
   while ((pass < count) && (exchange > 0))
   {
      // Scan unsorted part of data array
      exchange = 0;
      for (int index = low; index <= high - pass; index++)
      {
	 // Swap two data values if out of order
	 if (data[index] > data[index + 1])
	 {
	    int temp = data[index];
	    data[index] = data[index + 1];
	    data[index + 1] = temp;
	    exchange++;
	 }
      }
      pass++;
   }
   // Get end time
   clock_t time2=clock();
   double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
   cout << "Run time: " << run_time << " seconds\n";
}
/*Goes through the array from left to right and then right to left,
swapping adjacent numbers until they're all sorted*/
void cornSort(int data[], int low, int high)
{
  // Get start time
  clock_t time1=clock();
  //Count number of swaps
  int numSwaps = 1;
  //Count number of passes through the array
  int numPass = 1;
  //Number of values in the array
  int numValues = high - low + 1;
  /*Loops until no numbers are swapped and the numbers
  of passes is less than the number of values*/
  while ((numPass < numValues) && numSwaps > 0)
  {
    numSwaps = 0;
    //Goes from left to right
    for (int i = low; i <= high - numPass; i++)
    {
      //Swaps values
      if (data[i] > data[i+1])
      {
        int temp = data[i];
        data[i] = data[i+1];
        data[i+1] = temp;
        numSwaps++;
      }
    }
    numPass++;
    //Check if array is sorted
    if (numSwaps > 0)
    {
      //Goes from right to left
      for (int i = high; i >= low + numPass; i--)
      {
        //Swaps values
        if (data[i] < data[i-1])
        {
          int temp = data[i];
          data[i] = data[i-1];
          data[i-1] = temp;
          numSwaps++;
        }
      }
      numPass++;
    }
  }
  //Get end time
  clock_t time2=clock();
  double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
  cout << "Corn run time: " << run_time << " seconds\n";
}
//------------------------------------------------------------------
// Selection sort algorithm
// Best case O(N^2) - random data
// Worst case O(N^2)  - random data
// Average case O(N^2) - random data
//------------------------------------------------------------------
void selectionSort(int data[], int low, int high)
{
    // Get start time
    clock_t time1=clock();
   // Put largest unsorted value at end of sorted list
   for (int last = high; last > low; last--)
   {
      // Find index of largest value in unsorted array
      int largest = low;
      for (int index = low + 1; index <= last; index++)
	 if (data[index] > data[largest])
	    largest = index;

      // Swap with last element in unsorted array
      int temp = data[last];
      data[last] = data[largest];
      data[largest] = temp;
   }
   // Get end time
   clock_t time2=clock();
   double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
   cout << "Run time: " << run_time << " seconds\n";
}
/*Finds the highest and lowest values in an unsorted array and
places them at the left and right of a sorted arraw*/
void highLowSort(int data[], int low, int high)
{
  // Get start time
  clock_t time1=clock();
  int largestIndex;
  int smallestIndex;
  int last = high;
  int first = low;
  //Loops until sorted array is full
  while (last > first)
  {
    largestIndex = first;
    smallestIndex = first;
    //Finds index of smallet and largest values
    for (int i = first + 1; i <= last; i++)
    {
      if (data[i] > data[largestIndex])
        largestIndex = i;
      else if (data[i] < data[smallestIndex])
        smallestIndex = i;
    }
    if (smallestIndex == last)
      smallestIndex = largestIndex;
    //Swaps largest value
    int tempLast = data[last];
    data[last] = data[largestIndex];
    data[largestIndex] = tempLast;
    //Swaps smallest valye
    int tempFirst = data[first];
    data[first] = data[smallestIndex];
    data[smallestIndex] = tempFirst;
    last--;
    first++;
  }
  //Get end time
  clock_t time2=clock();
  double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
  cout << "High Low run time: " << run_time << " seconds\n";
}
int main()
{
  int sortChoice = 0;
  int numValues = 0;
  int range = 1;
  int orderChoice = 0;
  do
  {
    cout << "Enter which sorting algorithm you want to test: (1-4) " << endl;
    cout << "1. Bubble Sort 2. Corn Sort 3. Selection Sort 4. High Low Sort" << endl;
    cin >> sortChoice;
  }
  while(sortChoice < 1 || sortChoice > 4);
  do
  {
    cout << "Do you want the values to be (1-3)" << endl;
    cout << "1. Random 2. Mostly Sorted 3. Sorted " << endl;
    cin >> orderChoice;
  }
  while(orderChoice < 1 || orderChoice > 3);
  do
  {
    cout << "Enter the number of values you want to sort: " << endl;
    cin >> numValues;
    if (orderChoice == 1)
    {
      cout << "Enter the range of the numbers: " << endl;
      cin >> range;
    }
  }
  while(numValues < 1 || range < 0);
  int data[numValues];
  //User chose random values
  if (orderChoice == 1)
    createRandomData(data, numValues, range);
  //User chose mostly sorted values
  else if (orderChoice == 2)
    createMostlySortedData(data, numValues, numValues/10);
  //User chose compeltely sorted values
  else
    createMostlySortedData(data, numValues, 0);
  writeData("unsortedOutput.txt", data, numValues);
  //User Chose Bubble Sort
  if (sortChoice == 1)
  {
    writeData("unsortedOutput.txt", data, numValues);
    bubbleSort(data, 0, numValues-1);
    writeData("sortedOutput.txt", data, numValues);
  }
  //User Chose Corn Sort
  else if (sortChoice == 2)
  {
    writeData("cornUnsortedOutput.txt", data, numValues);
    cornSort(data, 0, numValues-1);
    writeData("cornSortedOutput.txt", data, numValues);
  }
  //User Chose Selection Sort
  else if (sortChoice == 3)
  {
    writeData("unsortedOutput.txt", data, numValues);    
    selectionSort(data, 0, numValues-1);
    writeData("sortedOutput.txt", data, numValues);
  }
  //User Chose High Low Sort
  else
  {
    writeData("highLowUnsortedOutput.txt", data, numValues);
    highLowSort(data, 0, numValues-1);
    writeData("highLowSortedOutput.txt", data, numValues);
  }
}
