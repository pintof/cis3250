#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helperFunctions.h"
#include "largeFunctions.h"

FILE *help;

int main(int argc, char *argv[])
{
	float a, b, c;
	float r1, r2;
	char sym;
	int menu, rmenu, smenu;

	do
	{
		printf("\n======\n");
		printf("Menu\n");
		printf("======\n");
		printf("1.Regular Calculator\n");
		printf("2.Scientific Calculator\n");
		printf("3.Acountant Calculator\n");
		printf("4.Read Help and Notice\n");
		printf("0.Exit\n");
		menu = input("Select Menu: "); //input main menu
		system("clear");

		if (menu == 1)
		{

			do
			{
				printf("\n======================\n");
				printf("Regular Calculator Menu\n");
				printf("=======================\n");
				printf("1.PLUS\n");
				printf("2.MINUS\n");
				printf("3.MULTIPLY\n");
				printf("4.DIVIDE\n");
				printf("0.BACK\n");
				rmenu = input("Select Menu: "); //input regular  menu
				system("clear");

				if (rmenu == 1)
				{
					a = input("Enter value 1 st: ");
					b = input("Enter value 2 nd: ");
					c = plus(a, b);
					printf("\n");
					print("sum of", "plus", a, b, c);
				}

				if (rmenu == 2)
				{
					a = input("Enter value 1 st: ");
					b = input("Enter value 2 nd: ");
					c = minus(a, b);
					printf("\n");
					print("result of", "minus", a, b, c);
				}

				if (rmenu == 3)
				{
					a = input("Enter value 1 st: ");
					b = input("Enter value 2 nd: ");
					c = mult(a, b);
					printf("\n");
					print("result of", "x", a, b, c);
				}

				if (rmenu == 4)
				{
					a = input("Enter value 1 st: ");
					b = input("Enter value 2 nd: ");
					c = divind(a, b);
					printf("\n");
					print("result", "/", a, b, c);
				}

			} while (rmenu != 0);
		}

		if (menu == 2)
		{

			do
			{
				printf("\n===========================\n");
				printf("Scientific Calculator Menu\n");
				printf("===========================\n");
				printf("1.Power function (x^y)\n");
				printf("2.Factorial Series (x!)\n");
				printf("3.Fibonacci Series \n");
				printf("4.Sine (Sin x)\n");
				printf("5.Cosine (cos x)\n");
				printf("6.Tangent (Tan x)\n");
				printf("7.Cosec (cosec x)\n");
				printf("8.Sec (sec x)\n");
				printf("9.Cot (cot x)\n");
				printf("10.Matrix functions\n");
				printf("11.Conversion functions\n");
				printf("0.Back\n");
				smenu = input("Select Menu: ");
				system("clear");

				if (smenu == 1)
				{
					a = input("Enter base(x): ");
					b = input("Enter power(y): ");
					c = powerfn(a, b);
					printf("\n");
					print("result of", "^", a, b, c);
				}

				if (smenu == 2)
				{
					a = input("Enter numbers of term: ");
					c = fact(a);
					printf("\n");
					spprint("Factorial of", "!", a, c);
				}

				if (smenu == 3)
				{
					a = input("Enter numbers of term: ");
					c = fib(a);
					printf("\n");
					spprint("Fibonacci of", " ", a, c);
				}

				if (smenu == 4)
				{
					a = input("Enter your value: ");
					c = sine(a);
					printf("\n");
					spprintf("Sine of", " ", a, c);
				}

				if (smenu == 5)
				{
					a = input("Enter your value: ");
					c = cosine(a);
					printf("\n");
					spprintf("Cosine of", " ", a, c);
				}

				if (smenu == 6)
				{
					a = input("Enter your value: ");
					r1 = sine(a);
					r2 = cosine(a);
					c = r1 / r2;
					printf("\n");
					spprintf("Tangent of", " ", a, c);
				}

				if (smenu == 7)
				{
					a = input("Enter your value: ");
					c = sine(a);
					printf("\n");
					spprintf("Cosec of", " ", a, 1 / c);
				}

				if (smenu == 5)
				{
					a = input("Enter your value: ");
					c = cosine(a);
					printf("\n");
					spprintf("Sec of", " ", a, 1 / c);
				}

				if (smenu == 8)
				{
					a = input("Enter your value: ");
					r1 = sine(a);
					r2 = cosine(a);
					c = r1 / r2;
					printf("\n");
					spprintf("Cot of", " ", a, 1 / c);
				}

				if (smenu == 10)
				{
					int operation_number = 0;
					printf("\n\t\tSum of Matrices(1)\t\tTranspose(2)\t\tProduct of Matrices(3)");
					printf("\n\tEnter an operation command:");
					scanf("%d", &operation_number);

					switch (operation_number)
					{
					case 1:
						matrix_sum();
						break;
					case 2:
						matrix_transpose();
						break;
					case 3:
						matrix_product();
						break;
					}
				}

				if (smenu == 11)
				{
					int operation_number = 0;
					printf("\n\n\n\t\tTemperature(1)\t\tTime(2)");
					printf("\n\n\n\t\tPlease choose an operation number:");
					scanf("%d", &operation_number);

					switch (operation_number)
					{
					case 1:
						temp();
						break;
					case 2:
						time();
						break;
					}
					break;
				}

			} while (smenu != 0);
		}

		if (menu == 3)
		{

		warp:

			//system("clear");
			printf("\n===========================\n");
			printf("Accountant Calculator Menu\n");
			printf("===========================\n");
			printf("Please set value first\n");
			printf("\n");

			int n, i, j, amenu;
			float rest, max, min, x_bar = 0, sum = 0;
			float med, mod, count;
			int temp;

			n = input("Enter number of term: ");

			float set[n];
			int numtemp[n];

			for (i = 0; i < n; i++)
			{
				set[i] = inputAry("Enter value terms", i);
			}

			for (i = 0; i < n; i++)
			{
				for (j = 0; j <= i; j++)
				{
					if (set[j] > set[i])
					{
						rest = set[j];
						set[j] = set[i];
						set[i] = rest;
					}
				}
			}

			min = set[0];
			max = set[n - 1];

			for (i = 0; i < n; i++)
			{
				sum += set[i];
			}
			x_bar = (sum / n);

			if ((n % 2) != 0)
			{
				med = set[((n + 1) / 2) - 1];
			}
			else
			{
				med = (set[((n + 1) / 2)] + set[((n + 1) / 2) - 1]) / 2;
			}

			for (i = 0; i < n; i++)
			{
				numtemp[i] = 0;
			}
			for (i = 0; i < n; i++)
			{
				temp = set[i];
				for (j = i; j < n; j++)
				{
					if (set[j] == temp)
					{
						numtemp[i]++;
					}
				}
			}

			temp = numtemp[0];
			for (i = 1; i < n; i++)
			{
				if (numtemp[i] > temp)
				{
					temp = numtemp[i];
				}
			}

			if (i == 999)
			{ //Always False If

			warp1: //Warp form menu
				j = 0;

				for (i = 0; i < n; i++)
				{
					if (numtemp[i] == temp)
					{
						j++;
					}
				}

				if (j == 1)
				{
					for (i = 0; i < n; i++)
					{
						if (numtemp[i] == temp)
						{
							printf("%.4f\n", set[i]);
						}
					}
				}

				else
				{
					printf("Not have mode value\n");
				}
			}

			do
			{
				printf("\n===========================\n");
				printf("Accountant Calculator Menu\n");
				printf("===========================\n");
				printf("1.Show max\n");
				printf("2.Show min\n");
				printf("3.Show x-bar\n");
				printf("4.Show range\n");
				printf("5.Show Med\n");
				printf("6.Show Mode\n");
				printf("7.Show value(sort)\n");
				printf("8.Set new value\n");
				printf("0.Back\n");
				amenu = input("Select Menu: "); //input acountant  menu
				system("clear");

				if (amenu == 1)
				{
					printf("\n");
					Aryprint("Max is", max);
				}

				if (amenu == 2)
				{
					printf("\n");
					Aryprint("Min is", min);
				}

				if (amenu == 3)
				{
					printf("\n");
					Aryprint("X-bar is", x_bar);
				}

				if (amenu == 4)
				{
					printf("\n");
					Aryprint("Range is", max - min);
				}

				if (amenu == 5)
				{
					printf("\n");
					Aryprint("Med is", med);
				}

				if (amenu == 6)
				{
					printf("\n");
					printf("Mode is: ");
					goto warp1;
				}

				if (amenu == 7)
				{
					printf("\n");
					printf("Set of number is(sort): ");
					for (i = 0; i < n; i++)
					{
						printf("%.3f ", set[i]);
					}
				}

				if (amenu == 8)
				{
					goto warp;
				}

			} while (amenu != 0);
		}

		if (menu == 4)
		{
			char text;

			help = fopen("./resources/User_helping.txt", "r");

			while ((text = fgetc(help)) != EOF)
			{
				fprintf(stdout, "%c", text);
			}

			fclose(help);
		}
	} while (menu != 0);

	return 0;
}