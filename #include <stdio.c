#include <stdio.h>

void checkWater(float ph, float turbidity,
                float tds, float oxygen)
{
    int problems = 0;

    printf("\n--- WATER QUALITY REPORT ---\n");

    if (ph >= 6.5 && ph <= 8.5)
        printf("pH: Acceptable\n");
    else {
        printf("pH: Outside selected range\n");
        problems++;
    }

    if (turbidity >= 0 && turbidity <= 5)
        printf("Turbidity: Acceptable\n");
    else {
        printf("Turbidity: Outside selected range\n");
        problems++;
    }

    if (tds >= 0 && tds <= 500)
        printf("TDS: Acceptable\n");
    else {
        printf("TDS: Outside selected range\n");
        problems++;
    }

    if (oxygen >= 5)
        printf("Dissolved Oxygen: Acceptable\n");
    else {
        printf("Dissolved Oxygen: Low\n");
        problems++;
    }

    printf("\nOverall Assessment: ");

    if (problems == 0)
        printf("All parameters are within the selected ranges.\n");
    else
        printf("%d parameter(s) outside selected ranges.\n",
               problems);

    printf("This assessment is not a drinking-water safety test.\n");
}

int main()
{
    float ph, turbidity, tds, oxygen;

    printf("WATER QUALITY MONITORING SYSTEM\n");

    printf("Enter pH value: ");
    scanf("%f", &ph);

    printf("Enter turbidity (NTU): ");
    scanf("%f", &turbidity);

    printf("Enter TDS (mg/L): ");
    scanf("%f", &tds);

    printf("Enter dissolved oxygen (mg/L): ");
    scanf("%f", &oxygen);

    if (ph < 0 || ph > 14 ||
        turbidity < 0 || tds < 0 ||
        oxygen < 0)
    {
        printf("\nInvalid input. Please enter valid readings.\n");
    }
    else
    {
        checkWater(ph, turbidity, tds, oxygen);
    }

    return 0;
}