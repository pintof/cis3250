#ifndef _HELPERFUNCTIONS_H
#define _HELPERFUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "largeFunctions.h"

#define PI 3.1415926535897932384626433832795

/** 
 * Function explanation... What it does.
 * @param: What Parameters does the function take?
 * @return: What value, if any, does the function return.
 **/
float input(char *inname);

/** 
 * Function explanation... What it does.
 * @param: What Parameters does the function take?
 * @return: What value, if any, does the function return.
 **/
float inputAry(char *inname, int num);

/** 
 * Function explanation... What it does.
 * @param: What Parameters does the function take?
 * @return: What value, if any, does the function return.
 **/
float plus(float adder, float addin);

/** 
 * Function explanation... What it does.
 * @param: What Parameters does the function take?
 * @return: What value, if any, does the function return.
 **/
float minus(float miner, float minin);

/** 
 * Function explanation... What it does.
 * @param: What Parameters does the function take?
 * @return: What value, if any, does the function return.
 **/
float mult(float multer, float multin);

/** 
 * Function explanation... What it does.
 * @param: What Parameters does the function take?
 * @return: What value, if any, does the function return.
 **/
float divind(float divider, float dividin);

/** 
 * Function explanation... What it does.
 * @param: What Parameters does the function take?
 * @return: What value, if any, does the function return.
 **/
int factorial(int term);

/** 
 * Function explanation... What it does.
 * @param: What Parameters does the function take?
 * @return: What value, if any, does the function return.
 **/
int fib(int term);

/** 
 * Function explanation... What it does.
 * @param: What Parameters does the function take?
 * @return: What value, if any, does the function return.
 **/
float power(float base, int pow);

/** 
 * Function explanation... What it does.
 * @param: What Parameters does the function take?
 * @return: What value, if any, does the function return.
 **/
float sine(float radius);

/** 
 * Function explanation... What it does.
 * @param: What Parameters does the function take?
 * @return: What value, if any, does the function return.
 **/
float cosine(float radius);

/** 
 * Function explanation... What it does.
 * @param: What Parameters does the function take?
 * @return: What value, if any, does the function return.
 **/
int spprint(char *screen, char *sym, int ini, int res);

/** 
 * Function explanation... What it does.
 * @param: What Parameters does the function take?
 * @return: What value, if any, does the function return.
 **/
float spprintf(char *screen, char *sym, float ini, float res);

/** 
 * Function explanation... What it does.
 * @param: What Parameters does the function take?
 * @return: What value, if any, does the function return.
 **/
float print(char *screen, char *sym, float ini, float upt, float res);

/** 
 * Function explanation... What it does.
 * @param: What Parameters does the function take?
 * @return: What value, if any, does the function return.
 **/
float Aryprint(char *screen, float ans);

#endif