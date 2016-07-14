#include "stdafx.h"
#include "Exercise25.h"
#include <iostream>
#include <cmath>

void Exercise25::mySolution()
{
	const long startingPopulationA = 50000000;
	const float growthPerYearA	   = 0.03;
	const long startingPopulationB = 70000000;
	const float growthPerYearB	   = 0.02;

	long finalPopulationA, finalPopulationB;
	const int numYears = calculateTimeWhenAExceedsB(startingPopulationA, growthPerYearA, startingPopulationB, growthPerYearB, finalPopulationA, finalPopulationB);
	const int numYearsCalc = calculateTimeWhenAExceedsB_logCalc(startingPopulationA, growthPerYearA, startingPopulationB, growthPerYearB);

	char buff[200];
	std::snprintf(buff, sizeof(buff), "After %d years, A has more inhabitants (%d) than B (%d)", numYears, finalPopulationA, finalPopulationB);
	std::cout << buff << std::endl;
	std::cout << "The alternative calculation came up with " << numYearsCalc << " years\n";

	system("pause");
}

int Exercise25::calculateTimeWhenAExceedsB(const long i_initialValueA, const float i_percentGrowthA, const long i_initialValueB, const float i_percentGrowthB, long &o_finalValueA, long &o_finalValueB)
{
	int numYears = 0;
	long currentValueA = i_initialValueA;
	long currentValueB = i_initialValueB;

	const float growthFactorA = (1 + i_percentGrowthA);
	const float growthFactorB = (1 + i_percentGrowthB);

	while (currentValueA < currentValueB)
	{
		numYears++;

		// round down each year
		currentValueA = (long) (currentValueA * growthFactorA);
		currentValueB = (long) (currentValueB * growthFactorB);
	}

	o_finalValueA = currentValueA;
	o_finalValueB = currentValueB;

	return numYears;
}

int Exercise25::calculateTimeWhenAExceedsB_logCalc(const long i_initialValueA, const float i_percentGrowthA, const long i_initialValueB, const float i_percentGrowthB)
{
	// a(0) = Ka
	// a(1) = Ka * pa
	// a(2) = Ka * pa^2
	// ...
	// I.  a(n) = Ka * pa^n
	// II. b(n) = Kb * pb^n
	// => a(n) > b(n)
	// => Ka * pa^n > Kb * pb^n | : pb^n | : Ka
	// => pa^n / pb^n > Kb / Ka
	// => (pa/pb)^n > Kb/Ka
	// => log ((pa/pb)^n) > log (Kb / Ka)
	// => n * log (pa / pb) > log (Kb / Ka) | : log(pa/pb)
	// => n > log (Kb / Ka) / log (pa / pb)

	const double initialQuotient = (double)i_initialValueB / i_initialValueA;
	const double growthQuotient  = (1+i_percentGrowthA) / (1+i_percentGrowthB);
	const double logInitial = std::log(initialQuotient);
	const double logGrowth  = std::log(growthQuotient);
	const double quotient = logInitial / logGrowth;

	return std::ceil(quotient);
}

long Exercise25::calculateExponentialGrowth(const long i_initialNumber, const float i_growthPercentage, const int i_years)
{
	// round down
	return (int) (i_initialNumber * calculateExponential(1 + i_growthPercentage, i_years));
}

float Exercise25::calculateExponential(const float i_base, const float i_exponential)
{
	float result = i_base;
	for (int k = 1; k < i_exponential; k++)
	{
		result *= i_base;
	}
	return result;
}

