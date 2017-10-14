#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1Scene.h"
#include "j1Scene2.h"
#include "j1Player.h"

j1Scene2::j1Scene2() : j1Module()
{
	name.create("scene2");

}

// Destructor
j1Scene2::~j1Scene2()
{}

// Called before render is available
bool j1Scene2::Awake(pugi::xml_node&)
{
	LOG("Loading Scene2");
	bool ret = true;

	if (App->scene->active == true)
	{
		active = false;
	}
	

	return ret;
}

// Called before the first frame
bool j1Scene2::Start()
{
	if (active) 
		App->map->Load("Map2.tmx");
	
	return true;
}

// Called each loop iteration
bool j1Scene2::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool j1Scene2::Update(float dt)
{

	App->player->position.y += GRAVITY;

	//-----CAMERA MOVEMENT----
	if (App->player->position.x > -App->render->camera.x + (3 * SCREEN_WIDTH / 5))
		App->player->camera_movement = true;

	else {
		App->player->camera_movement = false;
	}
	//-------------------------



		//FADE TO BLACK LEVEL 2
	

	//App->render->Blit(img, 0, 0);
	App->map->Draw();


	p2SString title("Map:%dx%d Tiles:%dx%d Tilesets:%d",
		App->map->data.width, App->map->data.height,
		App->map->data.tile_width, App->map->data.tile_height,
		App->map->data.tilesets.count());

	App->win->SetTitle(title.GetString());
	return true;
}

// Called each loop iteration
bool j1Scene2::PostUpdate()
{
	bool ret = true;

	if (App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool j1Scene2::CleanUp()
{
	LOG("Freeing scene2");

	App->scene->active = true;


	return true;
}