//
// Review source file
// ===========================================
// - Function definitions for managing product data
//

// Include System libraries
// TODO:

#define _CRT_SECURE_NO_WARNINGS
#include "review.h"
#include <stdio.h>
#include <string.h>

// Clear's the input buffer
// TODO:


// Enter user input product data information
// TODO:

void clearBuffer(void)
{
	while (getchar() != '\n');
}

void displayProductData(const struct ProductInfo products[], int arrSize, const char* filter)
{
	int i;
	double total = 0;
	int productsFound = 0;

	if (filter == NULL)
	{
		printf("Product Data:\n");

		printf("Description		Cost	Quantity	Date Manufactured\n");
		for (i = 0; i < arrSize; i++)
		{
			printf("8%s, $%8.2lf, %d, %d-%d\n", products[i].description, products[i].price, products[i].quantity, products[i].date.year, products[i].date.month);
			total += products[i].price * products[i].quantity;
			productsFound = 1;
		}
	}
	else
	{
		printf("Product Data:\n");

		for (i = 0; i < arrSize; i++)
		{
			printf("Description                    Cost	   Quantity	Date Manufactured\n");
			if (strstr(products[i].description, filter) != NULL)
			{
				printf("%s, $%.2lf, %d, %d-%d\n", products[i].description, products[i].price, products[i].quantity, products[i].date.year, products[i].date.month);
				total += products[i].price * products[i].quantity;
				productsFound = 1;
			}
		}
	}

	if (productsFound)
	{
		printf("Total: $%.2lf\n", total);
	}
}

void searchProductData(const struct ProductInfo products[], int arrSize)
{
	char filter[MAX_STRING + 2];
	int filterLength = 0;

	printf("Enter a filter: ");
	scanf("%21[^\n]", filter);
	filterLength = strlen(filter);

	if (filterLength > 20 || filter[0] == '\0')
	{
		printf("The filter must be between 5-20 characters long\n");
	}
	else
	{
		displayProductData(products, arrSize, filter);
	}
}

void enterData(struct ProductInfo products[], int arrSize)
{
	int i = 0;
	char description[MAX_STRING + 2];
	int valid;
	int stringLength;

	while (i < arrSize)
	{
		printf("Description (quit to stop): ");
		scanf("%21[^\n]", description);
		clearBuffer();

		if (strcmp(description, "quit") == 0)
			break;

		stringLength = strlen(description);
		if (stringLength < 5 || stringLength > 20)
		{
			printf("The description has to be between 5-20 characters\n");
			continue; // ask again, don't increment i
		}

		strcpy(products[i].description, description);

		// Price
		do
		{
			printf("Price: ");
			scanf("%lf", &products[i].price);
			clearBuffer();

			valid = products[i].price >= 0.01 && products[i].price <= 999.99;

			if (!valid)
				printf("The price must be between 0.01 and 999.99\n");

		} while (!valid);

		// Quantity
		do
		{
			printf("Quantity: ");
			scanf("%d", &products[i].quantity);
			clearBuffer();

			valid = products[i].quantity >= 20;

			if (!valid)
				printf("The quantity must be at least 20\n");

		} while (!valid);

		// Date
		do
		{
			printf("Date manufactured (YYYY-MM): ");
			scanf("%d-%d", &products[i].date.year, &products[i].date.month);
			clearBuffer();

			valid = products[i].date.year >= 2010 &&
				(products[i].date.month >= 1 && products[i].date.month <= 12);

			if (!valid)
				printf("The year has to be at least 2010 and the month 1-12\n");

		} while (!valid);

		i++; // only increment when all data is valid
	}
}

// Displays product data and optionally filters by description if filter pointer is not NULL
// TODO:

// Gets user input for filtering product data by the description field and displays the results
// TODO:

int getUserInput(void)
{
	int menuSelection;
	int valid;

	do
	{
		printf(
			"Menu Options\n"
			"=======================\n"
			"1. Enter Product Data\n"
			"2. Display Product Data\n"
			"3. Search Product Data\n"
			"0. Quit\n"
			"-----------------------\n"
			"Selection: "
		);

		scanf("%d", &menuSelection);
		clearBuffer();
		valid = menuSelection >= 0 && menuSelection <= 3;

		if (!valid)
		{
			printf("The option is invalid\n");
		}

	} while (!valid);

	return menuSelection;
}

// Presents a menu option list for the user to make a selection and returns the number option entered.
// TODO: