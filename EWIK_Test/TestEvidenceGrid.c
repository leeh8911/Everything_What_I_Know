#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "TestMatrix.h"

int test_evidence_grid(void);

int test_evidence_grid(void)
{

	EGM map1 = CreateEvidenceGridMap(3, 0);
	EGM map2 = CreateEvidenceGridMap(3, 0);

	Mass m1 = { 0, 0.9, 0.1, 0. };
	Mass m2 = { 0, 0, 0.1, 0.9 };

	SetBeliefMass(&map1, 0, 0, m1);
	SetBeliefMass(&map2, 0, 0, m2);

	EGM map = CombEvidenceSameMap(&map1, &map2, 1);
	Mass m = GetBeliefMass(&map, 0, 0);

	return 1;
}