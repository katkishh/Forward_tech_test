#pragma once
#if !defined(ProjectConstants)
#define ProjectConstants

namespace Constants {
	const int I = 10;
	const int ToH = 110;
	const double Hm = 0.01;
	const double Hv = 0.0001;
	const double C = 0.1;

	const double M[6]{ 20, 75, 100, 105, 75, 0 };
	const double V[6]{ 0, 75, 150, 200, 250, 300 };

	const double epsilon = 0.0001;
}

#endif