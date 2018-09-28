#include <stdio.h>
#include <stdlib.h>
#include "twoD.h"

/** Make a 2D array of integers (this is an example)
 *
 * @param nrows Number of rows
 * @param ncolumns Number of columns
 * @return Pointer to the array of pointers to the rows.
 * 	  or null pointer if unable to allocate memory.
 * 	  Note: Will not free partially-allocated memory.
 *
 * @author Mike Ciaraldi
 */

Organism** make2DOrganism(int nrows, int ncolumns) {

	Organism **a; // Array of pointers to rows
	unsigned int i; // Loop counter

	// First allocate the array of pointers to rows
	a = new Organism**[nrows];
	if (!a) { // Unable to allocate the array
		return (Organism **) NULL;
	}

	// Now allocate array for each row
	for (i = 0; i < nrows; i++) {
		// i is the row we are about to allocate
		a[i] = new Organism**[ncolumns];
		if (!a[i]) {
			return (Organism **) NULL;
		}
	}
	// sets every pointer in the array to Null
	for(int r = 0; r < nrows; r++){
		for(int c = 0; c < ncolumns; c++){
			a[r][c] = (Organism*)NULL;
		}
	}

	return a;
}

/**
 * Make a 2D array of characters
 *
 * @param nrows Number of rows
 * @param ncolumns Number of columns
 * @return Pointer to the array of pointers to the rows,
 *         or null pointer if cannot allocate memory.
 */
char** make2Dchar(int nrows, int ncolumns) {

	char **a; // Array of pointers to rows
	unsigned int i; // Loop counter

	// Allocate array of pointers to rows
	a = new char**[nrows];

	// Unable to allocate array
	if (!a)
		return (char **) NULL;

	// Allocate array for each row
	for (i = 0; i < nrows; i++) {
		// Allocate enough memory for ncolumns
		a[i] = new char[ncolumns];
		if (!a[i]) {
			return (char **) NULL;
		}
	}
	return a;
}
