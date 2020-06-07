#include "EWIK_EvidenceGrid.h"

#include <math.h>
#include <assert.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <memory.h>


EGM CreateEvidenceGridMap(int num_of_discernment, int args, ...);

void SetBeliefMass(EGM* src, int long_index, int lat_index, Belief M);
Belief GetBeliefMass(EGM* src, int long_index, int lat_index);

EGM CombEvidenceSameMap(EGM* map1, EGM* map2, int flag);
EGM PropagateBeliefMass(EGM* map1, Belief(*func)(Belief));


EGM CreateEvidenceGridMap(int num_of_discernment, int args, ...)
{
	EGM res;
	if (MAX_NUMBER_OF_HYPOTHESIS != pow(2, MAX_NUMBER_OF_DISCENRMENT))
	{
		assert(MAX_NUMBER_OF_HYPOTHESIS == pow(2, MAX_NUMBER_OF_DISCENRMENT));
	}
	if (num_of_discernment >= MAX_NUMBER_OF_DISCENRMENT)
	{
		assert(num_of_discernment < MAX_NUMBER_OF_DISCENRMENT);
	}

	res.number_of_discernment = num_of_discernment;
	res.number_of_hypothesis = (int)pow((double)2, (double)num_of_discernment);

	res.size_lat_grids = NUNBER_OF_LATERAL_CELLS;
	res.size_long_grids = NUNBER_OF_LONGITUDINAL_CELLS;

	res.cell_size = CELL_SIZE;

	res.max_lat_pos = MAX_LATERAL_POSITION;
	res.min_lat_pos = MIN_LATERAL_POSITION;
	res.max_long_pos = MAX_LONGITUDINAL_POSITION;
	res.min_long_pos = MIN_LONGITUDINAL_POSITION;

	// every cells set unknown state;
	Belief temp = { 0 };
	temp.mass[res.number_of_hypothesis - 1] = 1.f;
	for (int x = 0; x < res.size_long_grids; ++x)
	{
		for (int y = 0; y < res.size_lat_grids; ++y)
		{
			res.map.cells[x][y] = temp;
		}
	}

	va_list ap;
	va_start(ap, args);
	memset(res.activated_hypothesis, 1, sizeof(int) * res.number_of_hypothesis);
	for (int i = 0; i < args; ++i)
	{
		int unuse_index = va_arg(ap, int);
		res.activated_hypothesis[unuse_index] = 0;
	}
	va_end(ap);



	return res;
}

Belief GetBeliefMass(EGM* src, int long_index, int lat_index)
{
	if (long_index >= src->size_long_grids)
	{
		assert(long_index < src->size_long_grids);
	}
	else if (lat_index >= src->size_lat_grids)
	{
		assert(lat_index < src->size_lat_grids);
	}

	return src->map.cells[long_index][lat_index];
}

void SetBeliefMass(EGM* src, int long_index, int lat_index, Belief M)
{
	if (long_index >= src->size_long_grids)
	{
		assert(long_index < src->size_long_grids);
	}
	else if (lat_index >= src->size_lat_grids)
	{
		assert(lat_index < src->size_lat_grids);
	}

	memmove(&src->map.cells[long_index][lat_index], &M, sizeof(Belief));
}

EGM CombEvidenceSameMap(EGM* map1, EGM* map2, EWIK_EG_COMB flag)
{
	EGM result;
	memmove(&result, map1, sizeof(EGM));
	memset(&result.map, 0, sizeof(Map));

	unsigned int total_grid_size = result.size_lat_grids * result.size_long_grids;
	int hp, hp1, hp2;
	int lat_index, long_index;
	Belief* M1, * M2, * M;

	for (int hp = result.number_of_hypothesis; hp >= 0; --hp)
	{
		if (result.activated_hypothesis[hp] == 0) continue;

		for (int hp1 = 0; hp1 < map1->number_of_hypothesis; ++hp1)
		{
			if (map1->activated_hypothesis[hp1] == 0) continue;

			for (int hp2 = 0; hp2 < map2->number_of_hypothesis; ++hp2)
			{
				if (map2->activated_hypothesis[hp2] == 0) continue;

				for (unsigned int index = 0; index < total_grid_size; ++index)
				{
					long_index = (int)(index / result.size_lat_grids);
					lat_index = (int)(index % result.size_lat_grids);
					if (hp == result.number_of_hypothesis)
					{
						//calc conflict mass
						if ((hp1 & hp2) == 0)
						{
							{
								M1 = &map1->map.cells[long_index][lat_index];
								M2 = &map2->map.cells[long_index][lat_index];
								M = &result.map.cells[long_index][lat_index];

								M->mass[hp] += M1->mass[hp1] * M2->mass[hp2];
							}
						}
					}
					else
					{
						// comb conjunctive
						if ((hp1 & hp2) == hp)
						{
							{
								M1 = &map1->map.cells[long_index][lat_index];
								M2 = &map2->map.cells[long_index][lat_index];
								M = &result.map.cells[long_index][lat_index];
								if (flag == EWIK_EG_COMB_CONJ)
								{
									M->mass[hp] += M1->mass[hp1] * M2->mass[hp2];
								}
								else if (flag == EWIK_EG_COMB_DEMP)
								{
									M->mass[hp] += (M1->mass[hp1] * M2->mass[hp2]) / (1 - M->mass[result.number_of_hypothesis]);
								}
								else
								{
									M->mass[hp] = 0;
								}
							}
						}
					}
				}

			}
		}
	}

	return result;
}

EGM PropagateBeliefMass(EGM* map1, PropFunc func)
{
	EGM result;
	Belief M1, Mr;
	memmove(&result, map1, sizeof(EGM));
	memset(&result.map, 0, sizeof(Map));

	unsigned int total_grid_size = result.size_lat_grids * result.size_long_grids;
	int lat_index, long_index;
	for (unsigned int index = 0; index < total_grid_size; ++index)
	{
		long_index = (int)(index / result.size_lat_grids);
		lat_index = (int)(index % result.size_lat_grids);

		M1 = map1->map.cells[long_index][lat_index];
		result.map.cells[long_index][lat_index] = func(M1);
	}

	return result;
}