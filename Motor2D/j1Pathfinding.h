#ifndef __j1PATHFINDING_H__
#define __j1PATHFINDING_H__

#include "j1Module.h"
#include "p2Point.h"
#include "p2DynArray.h"
#include "j1App.h"
#include "p2PQueue.h"

#define INVALID_WALK_CODE 255
#define DEFAULT_PATH_LENGTH 70
#define MAX_PATHS 50
struct SDL_Texture;

enum EntityTypes;
enum MoveTo {
	NO_MOVE,
	M_UP = 1,
	M_DOWN,
	M_LEFT,
	M_RIGHT
};

struct Pathfinding {
	p2DynArray<iPoint>	path;
	p2PQueue<iPoint>	frontier;
	p2List<iPoint>		visited;
	p2List<iPoint>		breadcrumbs;

	void Clear();

};


class j1Pathfinding : public j1Module
{
public:
	j1Pathfinding();
	~j1Pathfinding();

	bool Start();

	bool CleanUp();

	//Draws the path 
	void DrawPath(const Pathfinding& path)const ;

	// Main function to request a path from A to B
	void CreatePath(const iPoint& origin, const iPoint& destination, Pathfinding* path, EntityTypes type);		
	
	MoveTo CheckDirection(Pathfinding& _path)const;

	Pathfinding* FindPath(const iPoint& origin,const iPoint& destination, EntityTypes type);

	// Sets up the walkability map
	void SetMap(uint width, uint height, uchar* data, EntityTypes type);
private:

	// Utility: return the walkability value of a tile
	uchar GetTileAt(const iPoint& pos, EntityTypes type) const;



	//Resets the path list
	void ResetPath();

	// Utility: return true if pos is inside the map boundaries
	bool CheckBoundaries(const iPoint& pos) const;

	bool CheckIsWalkable(const iPoint& pos, EntityTypes type) const;

	void Path(iPoint goal, Pathfinding& path);

	// size of the map
	uint				 width;
	uint				height;
	// all map walkability values [0..255]
	uchar*				fly_map;
	uchar*				ground_map;

	SDL_Texture*		PathStep = nullptr;
	
	
	Pathfinding*		path_root = nullptr;

	
};



#endif // __j1PATHFINDING_H__