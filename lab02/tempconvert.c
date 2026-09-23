#include <stdio.h>

void fahrenheit2celsius(float fFahrenheitIn)
{
  float fCelsiusOut = (fFahrenheitIn - 32) * 5 / 9;

  printf("%.2f degrees Celsius\n", fCelsiusOut);

  return;
}

void celsius2fahrenheit(float fCelsiusIn)
{
  float fFahrenheitOut = (fCelsiusIn * 9 / 5) + 32;

  printf("%.2f degrees Fahrenheit\n", fFahrenheitOut);

  return;
}

int main()
{

  int UserSelect = 0;

  do 
  {

        printf("Welcome to Temperature Converter!\n");
        printf("Please Select 1, 2, or 3!\n");
        printf("1. Convert from Fahrenheit to Celsius\n");
        printf("2. Convert from Celsius to Fahrenheit\n");
        printf("3. Exit the Application\n");

      
      scanf("%d", &UserSelect);

    if (UserSelect == 1)
      {
        float temperature = 0.0;

        printf("Please Enter your Fahrenheit Temperature: ");
        scanf("%f", &temperature);

        fahrenheit2celsius(temperature);
       }
    else if (UserSelect == 2)
      {
        float temperature = 0.0;

        printf("Please Enter your Celsius Temperature: ");
        scanf("%f", &temperature);

        celsius2fahrenheit(temperature);
      }
    else if (UserSelect == 3)
      {
        printf("Goodbye!\n");
        return 0;
      }
    else
      {
        printf("You did not Enter a Valid Selection!\n Please Try again!\n");
      }
  }
  while (UserSelect != 3);

  return 0;
}
