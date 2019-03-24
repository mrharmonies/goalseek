#include <stdio.h>
#include <stdarg.h>
#include <math.h>


double goalseek(double* pf, int argn, int warg, double goal, ...)
{
    double (*gn)(double, ...) = pf;
    double a[5], t1=0, t2=0, op=0;
    int i;
    va_list ap;
    va_start(ap, goal);
    for(i = 0; i < argn; i++) a[i] = va_arg(ap, double);
  
#define FARG (*gn)(a[0], a[1], a[2], a[3], a[4], a[5])

    t1 = FARG;
    a[warg] = a[warg] + 1;
    t2 = FARG;
    op = (t2 > t1) ? 0.001 : -0.001;
    while(1) {
		if(FARG > goal) a[warg] = a[warg] - op;
		if(FARG < goal) a[warg] = a[warg] + op;
		if(fabs(FARG - goal) < 0.0001) return a[warg];
    }
}

double sum(double a, double b, double c)
{
    return a + b + c;
}

double minu(double a, double b)
{
    return a - b;
}

double avg(double a, double b, double c)
{
    return (a + b + c) / 3;
}

double nliner(double x,double a, double b){
  return pow(a,2)+(a-6);
}

int main()
{
    //double goalseek(double* pf, int argn, int warg, double goal, ...);
    double ans = 0;
    printf("average of is 234, 456 and 876 is %lf\n", avg(234,456,876));
    ans = goalseek(&avg,3,2,900.0,234.0,456.0,876.0);
    printf("If you want average to 900, C should be %lf\n", ans);
    gets(stdin);
    return (0);
}
