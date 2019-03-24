# goalseek
Seek for missing value in linear math function where goal value is set, similar to Goalseek tool you see in spreadsheet application

# function declaration and arguments definition
goalseek function is declared as `double goalseek(double* pf, int argn, int warg, double goal, ...)`
1. `pf` is pointer to function (type double)
2. `argn` is arguments number function pf pointed to. eg `double add(double a, double b)` accepts 2 arguments
3. `warg` is index if which arguments you want to seek. eg, if function `add(500,300)` and you want to seek second value (currently is 300), the set `warg` value to `2`
4. `goal` is the end value that you wants
5. `...` is variadic variable where you set to initialize the function

# usage example
```C++
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

double avg(double a, double b, double c){
	return (a + b + c) / 3;
}

double sum(double a, double b, double c){
	return a + b + c;
}

double minu(double a, double b){
	return a - b;
}

double avg(double a, double b, double c){
	return (a + b + c) / 3;
}

double nliner(double x,double a, double b){
	return pow(a,2)+(a-6);
	// as for now, goalseek dont work with nonlinear function
}

int main() {
	double ans = 0;
	printf("average of is 234, 456 and 876 is %lf\n", avg(234,456,876));
	// i want goal for function average is 900. seek b value
	ans = goalseek(&avg,3,2,900.0,234.0,456.0,876.0);
	printf("If you want average to 900, C should be %lf\n", ans);
	gets(stdin);
	return (0);
}	
```
# screenshot
![](https://drive.google.com/uc?id=1Z8ViMu-dXUfV43ziaahHiRkh10kJbd2E)

# license
  Copyright (C) 2019 Mohd Kholid Yaacob (<http://mrharmonies.blogspot.com>)
  
  This source is free software; you can redistribute it and/or modify it under
  the terms of the GNU General Public License as published by the Free
  Software Foundation; either version 2 of the License, or (at your option)
  any later version.
  
  
  This code is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
  details.
  
  
  A copy of the GNU General Public License is available on the World Wide Web
  at <http://www.gnu.org/copyleft/gpl.html>. You can also obtain it by writing
  to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor,
  Boston, MA 02110-1335, USA. 
