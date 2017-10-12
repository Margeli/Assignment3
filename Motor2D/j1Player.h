#ifndef __j1PLAYER_H__
#define __j1PLAYER_H__

#include "j1Module.h"
#include "p2Point.h"
#include "j1Animation.h"
#include "j1Collisions.h"

struct SDL_Texture;

class j1Player : public j1Module
{
public:

	j1Player();

	// Destructor
	virtual ~j1Player();

	

	bool Start();

	// Called each loop iteration
	bool Update();

	// Called before quitting
	bool CleanUp();

public:

	iPoint position;

	SDL_Texture* graphics = nullptr;

	Animation* current_animation = nullptr;
	Animation idle;
	Animation walk;
	Animation jump;

	//Collider * player_collider;
};


#endif // __j1PLAYER_H__