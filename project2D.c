#include <stdio.h>
#include <stdlib.h>

typedef enum
{
   ADD,
   MULT,
   SUBTRACT,
   DIV,
   UNSUPPORTED
} MathOperation;

void IssueBadNumberError()
{
    printf("The string does not represent a floating point number.\n");
    exit(EXIT_FAILURE);
}
void IssueBadOperationError()
{
    printf("The string does not represent a valid operation.\n");
    exit(EXIT_FAILURE);
}

MathOperation GetOperation(char *op)
{
    /* Implement me! */
    if (*op == '+')
	    return  ADD;
    if (*op == 'x')
	    return  MULT;
    if (*op == '-')
	    return SUBTRACT;
    if (*op == '/')
	    return DIV;
    else {
	    return  UNSUPPORTED;
	    IssueBadOperationError();
	}
}

double CalculateFraction(char *str) {
	double tens = 10.0;
	double numpost = 0;
	int j = 0;
   do {
	  j++;
	  if ((str[j]-'0' >= 0 )&& (str[j]-'0' <= 9)) {
	  	numpost = numpost + ((double)str[j]-'0'/tens);
		tens = tens * 10;
		}
	}while(str[j] != '\0');
   return numpost;
}


double StringToDouble(char *str)
{
    /* Implement me! */
   int i = 0;
   double num = 0;
   double postnum = 0;
   int isnegative = 0;
   do {
	   if (str[i] == '-') {
		   isnegative = 1;
		   i += 1;
		   continue;
		}
	   else if (str[i]-'0' >= 0 && str[i]-'0' <= 9) {
		   num = (num * (double)10) + ((double)str[i]-'0');
		}
	   else if (str[i] == '.' ) {
		   postnum += CalculateFraction(str+i);
		   num += postnum;
	   	   break;
		}
	   else 
		  IssueBadNumberError();
	   i++;
	}while(str[i] != '\0');
   	if (isnegative == 1)
		num = num * (double)(-1); 
   return num;
}


int main(int argc, char *argv[])
{
	printf("%s\n", argv[1]);
    double v = StringToDouble(argv[1]);
    MathOperation op = GetOperation(argv[2]);
    double v2 = StringToDouble(argv[3]);
    double result = 0.;
    switch (op)
    {
       case ADD:
         result = v + v2;
         break;

       /* Implement more cases... */

       case MULT:
	 result = v * v2;
	 break;

       case SUBTRACT:
	 result = v - v2;
	 break;

       case DIV:
	 if (v2 == 0.0)
		EXIT_FAILURE;
	 else
	 	result = (double)v / (double)v2;
	 break;

       case UNSUPPORTED:
	 EXIT_FAILURE;
	 break;
    }
    printf("%d\n", (int) result);
 
    return 0;
}
