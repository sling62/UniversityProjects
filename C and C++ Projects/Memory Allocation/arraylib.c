	 /*
 * Author: Samantha Ling
 * Student number: 160720604
 */
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylib.h"

/* error message format for fatalerror */
static const char *ERR_FMT = "%s:%d - %s, errno %d: %s\n";

/***************************************************************************/
/***** ARRAYLIB.H IMPLEMENTATIONS ******************************************/
/***************************************************************************/

/* newarray function dynamically allocates an array struct and assigns fields to the array struct*/
array *newarray(int len) {
    /*condition to check if len > 0*/ 
    
    if(len >0) 
    {
		/*if len > 0 then an array struct arr is dynamically allocated */
		array *arr = (array *) malloc(sizeof(array));
        
		/*check to see if arr is null*/
		if(!arr)
		{
			/*if arr is null then free the allocated array struct arr*/
			free(arr);
			/*set errno to ENOMEM to indicate memory allocation fail */
			errno = ENOMEM;
			/*return null */
			return NULL;
		}
		
		/*the input length is assigned to array length */
		arr->len = len; 
        
		/*if arr is not null then dynamically allocate a pointer to arr called ptr_one*/
		int *ptr_one = (int*)calloc(len,sizeof(int));
	
		/*similar to arr null check above, ptr_one is checked*/
		if(!ptr_one)
		{
			free(ptr_one);
			errno = ENOMEM;
			return NULL;
		}
		/*ptr_one is assigned to array ai pointer */
		arr->ai = ptr_one;
		/*arr is then returned */ 
		return arr;
    }
	else
	{
		/*if len < 1 then set errno to EINVAL to indicate incorrect input value*/ 
        errno = EINVAL;
		/*return null */
        return NULL;
    }
    
}

/* get function get's the value at index position idx from the int array arr->ai*/
int get(array *arr, int idx) {

    /* check to see if arr and the arr pointer ai is not null and that the idx is within bounds*/
    if((arr != NULL) && (0 <= idx) && (idx < arr->len) && (arr->ai != NULL))
    {
		/*if the condition above is correct then the element in arr at position idx is returned*/
		return arr->ai[idx];

    }
    else
	{
		/*the condition above is not met then errno is set to EINVAL and as default return's INT_MIN */
		errno = EINVAL;
		return INT_MIN;
    }

}
                
/*set function set's the element at index position idx in the int array arr->ai to the given value*/
void set(array *arr, int idx, int value) {
    
	/* check to see if arr and the arr pointer ai is not null and that the idx is within bounds*/
    if((arr != NULL) && (0 <= idx) && (idx < arr->len) && (arr->ai != NULL))
    {
		/*if the condition above is correct then in arr at position idx it is set to the input value*/
		arr->ai[idx] = value;
    }
    else
	{
		/*the condition above is not met then errno is set to EINVAL*/
		errno = EINVAL;
    }
}

/*for the foreach function, for each element of the array contained in the array struct pointed to by arr apply the function applyf */
void foreach(array *arr, applyfunction applyf) { 
	/*check is carried for null field, pointer and function*/
    if((!arr) || (!arr->ai) || (!applyf))
    {
		/*if condition above is passed then returns nothing and exits out of function*/
		return;
    } 
    /*otherwise interate through arr using ai applying the function applyf to the element at index i*/
    for(int i =0; i< arr->len ; i++)
    {
		arr->ai[i] = applyf(arr,i);
    }
}

/*print function prints the contents of the array contained in the arr pointer to an array struct to the given file stream*/
void print(FILE *stream, array *arr) {
    /*prints open bracket to the file stream */
    fprintf(stream,"[ ");
	/* check to see if arr or the arr pointer ai is null or that len is not within bounds*/
    if((arr == NULL) || (arr->ai == NULL)|| (arr->len < 1))
    {
		/*if any of the condition's above are correct then do nothing*/
    }
    else
	{
        /*otherwise iterate through array struct arr using ai and print out each element in arr to file stream */
		for(int n=0;n< arr->len;n++) 
		{
		    fprintf(stream,"%d, ",arr->ai[n]);
		}
    }
    /*prints closing bracket to the file stream */
	fprintf(stream,"]");
}
        
/***************************************************************************/
/***** THE FOLLOWING FUNCTIONS ARE IMPLEMENTED FOR YOU - DO NOT CHANGE *****/
/***************************************************************************/

/* see println comments in arraylib.h */
void println(FILE *stream, array *arr) {
    print(stream, arr);
    fprintf(stream, "\n");
}

/* see delearray comments in arraylib.h */
void delarray(array *arr) {
    if (arr) { 
        if (arr->ai) 
            free(arr->ai);
        free(arr);
    }
}

/* see fatalerror comments in arraylib.h */
void fatalerror(int line, char *msg) {
    fprintf(stderr, ERR_FMT, __FILE__, line, msg, errno, strerror(errno));
    exit(EXIT_FAILURE);
}

/* see newarray_e comments in arraylib.h */
array *newarray_e(int len) {
    array *arr = newarray(len);
    
    if (!arr)
        fatalerror(__LINE__, "array allocation failed");
        
    return arr;
}

/* see get_e comments in arraylib.h */
int get_e(array *arr, int idx) {
    int val = get(arr, idx);
    
    if (val == INT_MIN && errno == EINVAL)
        fatalerror(__LINE__, "null array or index out of bounds");
    
    return val;
}
        
        
/* see set_e comments in arraylib.h */
void set_e(array *arr, int idx, int value) {
    set(arr, idx, value);
    
    if (errno == EINVAL)
        fatalerror(__LINE__, "null array or index out of bounds");
}

/***************************************************************************/

