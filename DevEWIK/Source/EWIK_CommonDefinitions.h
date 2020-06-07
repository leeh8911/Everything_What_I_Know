#ifndef __EWIK_COMMON_DEFINITIONS_H__
#define __EWIK_COMMON_DEFINITIONS_H__

extern inline float EWIK_Abs(float a)
{
	return a > 0 ? a : -a;
}
extern inline float EWIK_Max(float a, float b)
{
	return ((a + b) + EWIK_Abs(a - b)) / 2;
}
extern inline float EWIK_Min(float a, float b)
{
	return ((a + b) - EWIK_Abs(a - b)) / 2;
}

#endif