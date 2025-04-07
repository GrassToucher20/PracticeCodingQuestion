#pragma once

#define MAX_STRING 20
#define MIN_STRING 5
#define MIN_PRICE 0.01
#define MAX_PRICE 999.99
#define MIN_QUANTITY 20
#define MIN_YEAR 2010
#define NUM_PRODUCTS 5

struct Date
{
	int year;
	int month;
};

struct ProductInfo
{
	char description[MAX_STRING + 1];
	double price;
	int quantity;
	struct Date date;
};

int getUserInput(void);
void clearBuffer(void);
void enterData(struct ProductInfo products[], int arrSize);
void displayProductData(const struct ProductInfo products[], int arrSize, const char* filter);
void searchProductData(const struct ProductInfo products[], int arrSize);