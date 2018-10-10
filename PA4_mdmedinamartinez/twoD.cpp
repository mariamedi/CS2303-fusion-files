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
 * @author mdmeidnamartinez
 * @authro agarza
 */

Organism*** make2DOrganism(int nrows, int ncolumns) {

	Organism ***a; // Array of pointers to rows
	unsigned int i; // Loop counter

	// Allocate array of pointers to rows
	a = new Organism**[nrows];
	//a = (Organism***) malloc(nrows * sizeof(Organism **));

	// Unable to allocate array
	if (!a)
		return (Organism ***) NULL;

	// Allocate array for each row
	for (i = 0; i < nrows; i++) {
		// Allocate enough memory for ncolumns
		//a[i] = malloc(ncolumns * sizeof(Organism*));
		a[i] = new Organism*[ncolumns];
		if (!a[i]) {
			return (Organism***) NULL;
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
	a = new char*[nrows];

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
