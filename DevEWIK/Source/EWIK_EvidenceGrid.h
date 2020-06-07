#ifndef __EWIK_EVIDENCE_GRID_H__
#define __EWIK_EVIDENCE_GRID_H__

#ifndef MAX_NUMBER_OF_DISCENRMENT
#define MAX_NUMBER_OF_DISCENRMENT	(4)
#define MAX_NUMBER_OF_HYPOTHESIS	(16)
#endif

#define MAX_LATERAL_POSITION (30.f)
#define MIN_LATERAL_POSITION (-30.f)
#define MAX_LONGITUDINAL_POSITION (30.f)
#define MIN_LONGITUDINAL_POSITION (-30.f)
#define CELL_SIZE (1.f)

#define NUNBER_OF_LATERAL_CELLS ((int)((MAX_LATERAL_POSITION - MIN_LATERAL_POSITION) / CELL_SIZE) + 1)
#define NUNBER_OF_LONGITUDINAL_CELLS ((int)((MAX_LONGITUDINAL_POSITION - MIN_LONGITUDINAL_POSITION) / CELL_SIZE) + 1)

typedef enum EWIK_EG_COMB
{
	EWIK_EG_COMB_CONJ,
	EWIK_EG_COMB_DEMP,
}EWIK_EG_COMB;

typedef struct Belief
{
	//hypothesis + 1, +1 is meaning of conflict mass
	float mass[MAX_NUMBER_OF_HYPOTHESIS+1];
}Belief;
typedef struct Map
{
	Belief cells[NUNBER_OF_LONGITUDINAL_CELLS][NUNBER_OF_LATERAL_CELLS];
}Map;
typedef struct EvidenceGridMap
{
	// public
	int		number_of_discernment;
	int		number_of_hypothesis;
	int		size_lat_grids;
	int		size_long_grids;
	float	cell_size;
	float	max_lat_pos;
	float	min_lat_pos;
	float	max_long_pos;
	float	min_long_pos;



	// private
	Map map;
	int activated_hypothesis[MAX_NUMBER_OF_HYPOTHESIS+1];

}EGM;

typedef Belief(*PropFunc)(Belief);

EGM CreateEvidenceGridMap(int num_of_discernment, int args, ...);

extern void SetBeliefMass(EGM* src, int long_index, int lat_index, Belief M);
extern Belief GetBeliefMass(EGM* src, int long_index, int lat_index);
extern EGM CombEvidenceSameMap(EGM* map1, EGM* map2, int flag);

extern EGM PropagateBeliefMass(EGM* map1, PropFunc func);


#endif