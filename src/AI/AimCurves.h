#ifndef aimcurves_h
#define aimcurves_h

class AimCurves
{
private:
	const static int curveResolution = 100;

	// curve made by a twich shot
	float* fastTwitchCurve;

	// curve made from delibrate aim
	float* fastAimCurve;

	// curve with oscillating sweep motion over opponent
	// works in conjunction with a shot timer
	float* aimSweepCurve;
public:
	AimCurves()
	{
		fastTwitchCurve = new float[curveResolution];
		fastAimCurve = new float[curveResolution];
		aimSweepCurve = new float[curveResolution];

		calculateCurves();
	}

	void calculateCurves()
	{
		// sample curve functions to fill arrays
	}
};

#endif
