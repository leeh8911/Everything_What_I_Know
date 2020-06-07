#ifndef __TEST_PROC_TIME_H__
#define __TEST_PROC_TIME_H__

#define EWIK_PT_MAX_NAME_LENGTH (256)

typedef enum EWIK_PT_STATUS
{
	EWIK_PT_STATUS_DEFAULT = 0U,
	EWIK_PT_STATUS_INIT,
	EWIK_PT_STATUS_CALC,
}EWIK_PT_STATUS;

typedef struct ProcTimer
{
	char module_name[EWIK_PT_MAX_NAME_LENGTH];
	int count;
	float current;
	float mean;
	float max;
	float var;
	double sum_sqr;

	EWIK_PT_STATUS status;

}ProcTimer;




extern ProcTimer CreateProcTimer(char* names);
extern void BeginProcTimer(ProcTimer* pt);
extern void EndProcTimer(ProcTimer* pt);
extern void PrintProcTimer(ProcTimer* pt, int iter);
#endif