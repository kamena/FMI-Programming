#include <iostream>
#include "Car.h"

using namespace std;

int main()
{
	Engine e(70, 1400, DIESEL);
	Tank ta(100);
	Transmission tr(MANUAL, 5);

	Car c(5, 2003, e, ta, tr);

	cout << "Emissions: " << c.calculateEmissions() << endl;

	cout << "Tax: " << c.calculateTax() << endl;

	cout << "Fuel Consumption: " << c.fuelConsumption() << endl;

	cout << "Max Available Path: " << c.maxAvailablePath() << endl;

	cout << "Calc gear 202: " << c.calcGear(202) << endl;

    return 0;
}
