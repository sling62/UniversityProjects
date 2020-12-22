/*****************************************************/
/*** Purpose: To implement and compare sorting algorithms ***/
/***                                               ***/
/***     Initial Author: Jason Steggles 20/09/17   ***/
/***     Extended by: Samantha Ling    Date 27/10/17 ***/
/*****************************************************/

import java.io.*;
import java.text.*;
import java.util.*;

public class Sort {

/** Array of integers to sort **/
private int[] A;
	
/** Size of the array **/
private int size;

/** Number of elements actually used in array **/
private int usedSize;

/** Global variables for counting sort comparisons **/
public int compIS; /** Global comparison count for Insertion Sort **/
public int compQS; /** Global comparison count for Quicksort **/
public int compNewS; /** Global comparison count for new sort **/

/*****************/
/** Constructor **/
/*****************/
Sort(int max)
{
    /** Initialiase global sort count variables **/
    compIS = 0;
    compQS = 0;
    compNewS = 0;
    
    /** Initialise size variables **/
    usedSize = 0;
    size = max;
    
    /** Create Array of Integers **/
    A = new int[size];
}

/*********************************************/
/*** Read a file of integers into an array ***/
/*********************************************/
public void readIn(String file)
{
   try
   {
       /** Initialise loop variable **/
       usedSize = 0;
       
       /** Set up file for reading **/
       FileReader reader = new FileReader(file);
       Scanner in = new Scanner(reader);
       
       /** Loop round reading in data while array not full **/
       while(in.hasNextInt() && (usedSize < size))
       {
           A[usedSize] = in.nextInt();
           usedSize++;
       }
       
    }
    catch (IOException e)
    {
       System.out.println("Error processing file " + file);
    }
}

/**********************/
/*** Display array  ***/
/**********************/
public void display(int line, String header)
{
    /*** Integer Formatter - three digits ***/
    NumberFormat FI = NumberFormat.getInstance();
    FI.setMinimumIntegerDigits(3);

    /** Print header string **/
    System.out.print("\n"+header);

    /** Display array data **/
    for (int i=0;i<usedSize;i++)
    {
        /** Check if new line is needed **/
        if (i%line == 0) 
        { 
            System.out.println(); 
        }
        
        /** Display an array element **/
        System.out.print(FI.format(A[i])+" ");
    }
}

/** insertion sort method **/
public void insertion()
{
	/**loops through the array**/
	for(int i =1; i<A.length; i++)
	{
	    /**key stores the next value to insert, j is going to refer to the current index to try**/
		int key = A[i];
		int j = i;
		
		/** while loop finds the correct position to insert the key(by comparing if key<A[j-1]), j>0 prevents a out of bounds exception**/
		while(j>0 && key<A[j-1])
		{
			/** comparison is made as elements in the array are compared to one another each time the while loop is carried out**/
			compIS = compIS +1;
			A[j] = A[j-1];
			/**shift's current index/space to left**/
			j = j-1;
			
		}
		/** a comparison is done for each element in the array**/
		compIS = compIS +1;
		/** insert key into space **/
		A[j] = key;
	}
	
	
}

/** method to do a Quicksort, L and R represent the left and right array pointers **/
public void quick(int L, int R)
{
	/** p is declared to hold the value of the location of the pivot after partition**/
	int p;
	/**stops if there is only one value left in array **/
	if(R>L)
	{
		/** calls the partition method of which splits the array in 2 **/
		p = partition(A,L,R);
		/** recursively calls quick method to sort the left half of the array **/
		quick(L,p-1);
		/** recursively calls quick method to sort the right half of the array **/
		quick(p+1,R);
	}
	
}

/** method in order to partition the array A **/
public int partition(int[] A, int pL, int pR)
{
 
 /**initialising pointers**/
 int left = pL;
 int right = pR;
 /** v is assigned the pivot value **/
 int v = A[right];
 pL = left;
 pR = right;
 
 /**while loop to find values in the array that need to be swapped, stops when the pointers cross **/
 while(pL<pR) {

	/** while loop to loop if the value found in the array is less than the pivot  **/
 	while(A[pL]< v) {
 		/**comparison is made to the pivot each time the while loops round**/
 		compQS = compQS+1;
 		/** keep moving/incrementing the pointer to the right if the value is less than the pivot **/
 		pL =  pL +1;
 	}
 	/**comparison is made to the pivot**/
 	compQS = compQS+1;
 	
 	/**while loop to loop if the value found in the array is greater than or equal to the pivot, pR>left condition makes sure the pointer dosen't drop off the beginning of the array**/
 	while(A[pR] >= v && pR>left)
 	{
 		/**comparison is made to the pivot each time the while loops round**/
 		compQS = compQS+1;
 		/** keep moving/incrementing the pointer to the left if the value is greater than or equal to the pivot **/
 		pR = pR -1;
 	}
 	/**comparison is made to the pivot**/
 	compQS = compQS+1; 
 	
 	/** if condition to make sure a swap is not carried out on the last iteration **/
 	if(pL <pR) {
 		/** once one value is found that less than the pivot as well as another that is greater than or equal to the pivot then they the values are swapped**/
 		swap(A, pL,pR);
 		
 	}
 	
 }
 
 /** a swap is done to sort the pivot into the correct position**/
 swap(A,pL,right);
 /** pivot is returned**/
 return pL;
}

/** method of which swaps the values in the array if not in the correct position **/
public void swap(int []A, int i, int j) {
	/** the value of which is at index i in the array A is stored temporarily in temp **/
    int temp = A[i];
    /** the value of which is at index i in the array A is replaced by the value of which is in index j**/
    A[i] = A[j];
    /** the value of which is at index j in the array A is replaced by the value of temp**/
    A[j] = temp;
}

/** newSort algorithm AKA bingo sort algorithm **/
public void newSort()
{
	/**pointer pos starts at index 0 in the array A**/
	int pos = 0;
	
	/** while loop sorts through all elements in the array **/
	while(pos<A.length)
	{
	    /**minimum stores the next minimum value found from the current position by calling the findMinFrom  method to search through the array**/
		int min = findMinFrom(A,pos);
		/** for loop searches through the remaining elements to sort the minimum value **/
		for(int i = pos; i<A.length;i++)
		{
			/** if the minimum value found is equal to the value the current index position is pointing at then the value at index i is swapped with the current value index position is pointing and then the position in the array is updated **/
			if(A[i] == min)
			{
				/** updating the comparison counter for each comparison that an array element is made against the minimum **/
				compNewS = compNewS +1;
				swap(A,i,pos);
				pos = pos + 1;
			}
			else {
		    /** updating the comparison counter for each comparison that an array element is made against the minimum **/
			compNewS = compNewS +1;
			}
		}
	
	}
}

/**method to find/search for the minimum from a given position in the array **/
public int findMinFrom(int [] A, int pos)
{
	/** the minimum is set as the value at the current position in the array A**/
	int min = A[pos];
	/** from there a for loop loops round the remaining elements in the array A searching for the next minimum **/
	for(int i = pos+1; i<A.length; i++)
	{
		/** if the current element at index i in the array is less than the minimum value then it becomes the next minimum**/
		if(A[i]<min)
		{
			/** updating the comparison counter for each comparison that an array element is made against the minimum **/
			compNewS = compNewS +1;
			min = A[i];
		}
		else {
	    /** updating the comparison counter for each comparison that an array element is made against the minimum **/
		compNewS = compNewS +1;
	    }
	
     }   
	/**returns minimum value found**/
	return min;
}

} /** End of Sort Class **/

