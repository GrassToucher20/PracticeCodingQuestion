#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "review.h"

int main(void)
{
	int menuSelection;
	struct ProductInfo products[NUM_PRODUCTS] = {
		{"Horse Brush", 20, 20, 2025, 10 },
		{"Horse Brush", 20, 20, 2025, 10 },
		{"Horse Brush", 20, 20, 2025, 10 },
		{ "Cow Cash", 70, 20, 2020, 6 }
	};

	do
	{
		menuSelection = getUserInput();

		switch (menuSelection)
		{
		case 1:
			enterData(products, NUM_PRODUCTS);
			break;
		case 2:
			displayProductData(products, NUM_PRODUCTS, NULL);
		break;
		case 3:
			searchProductData(products, NUM_PRODUCTS);
			break;
		}
	} while (menuSelection != 0);


	return 0;
}

/* Some Product Data Inputs (copy and paste when ready to run the program):

1
Horse Hair
23.43
54
2020-10
Camel Hair
54.34
73
2023-11
Goat Hair
82.34
28
2024-03
Squirrel Hair
19.25
24
2025-01
Horse Brush
99.25
20
2025-02
Bison Hair
67.55
24
2025-03
Horse Saddle
527.53
20
2025-04
quit

*/