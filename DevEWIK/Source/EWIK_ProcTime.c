#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdarg.h>
#include <time.h>
#include <math.h>

#include "EWIK_ProcTime.h"
#include "EWIK_CommonDefinitions.h"

ProcTimer CreateProcTimer(char* names);

void BeginProcTimer(ProcTimer* pt);
void EndProcTimer(ProcTimer* pt);
void PrintProcTimer(ProcTimer* pt, int iter);

ProcTimer CreateProcTimer(char* names)
{
	ProcTimer result;
	memset(&result, 0, sizeof(ProcTimer));
	memmove(result.module_name, names, sizeof(char) * EWIK_PT_MAX_NAME_LENGTH);
}

void BeginProcTimer(ProcTimer* pt)
{
	pt->status = EWIK_PT_STATUS_INIT;

	pt->count++;
	pt->current = (int)clock();
}

void EndProcTimer(ProcTimer* pt)
{
	if (pt->status == EWIK_PT_STATUS_INIT)
	{
		int prev = pt->current;
		pt->current = (int)clock() - prev;
		pt->sum_sqr += pt->current * pt->current;

		pt->max = EWIK_Max(pt->max, (float)pt->current);

		if (pt->count == 1)
		{
			pt->mean = pt->current;
			pt->var = pt->sum_sqr / pt->count - pt->mean * pt->mean;
		}
		else
		{
			pt->mean = (pt->mean * (pt->count - 1) + pt->current) / pt->count;
			pt->var = pt->sum_sqr / pt->count - pt->mean * pt->mean;
		}

		pt->status = EWIK_PT_STATUS_CALC;

	}

}

void PrintProcTimer(ProcTimer* pt, int iter)
{
	int count = pt->count;
	float current = (float)(pt->current / iter);
	float mean_var = pt->mean / iter;
	float max_var = pt->max / iter;
	float std_var = sqrtf(pt->var)/iter;

	if (pt->status == EWIK_PT_STATUS_CALC)
	{
		printf("/**** %s function process time calculate ****/\n", pt->module_name);
		printf("count   : %5.2d [ms]\n", count);
		printf("current : %5.2f [ms]\n", current);
		printf("mean    : %5.2f [ms]\n", mean_var);
		printf("max     : %5.2f [ms]\n", max_var);
		printf("std     : %5.2f [ms]\n", std_var);
	}

}