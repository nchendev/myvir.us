#pragma once
#include "LootBox.h"
#include "Actor.h"
#include "Player.h"
#include "Time.h"

#include <SDL/SDL_stdinc.h>


LootBox::LootBox(Game* game):Actor(game)
{

}
void LootBox::Update(float deltaTime)
{
	srand(time(NULL));
	int random = rand() % 4 + 1;

	if (open && mAnimTimer < 5.0f && (!mGame->Box2inProgress || !mGame->Box3inProgress))
	{
		opening = true;
		mAnimTimer += deltaTime;
		//std::cout << mAnimTimer << endl;
		mSprite->Update(deltaTime);
		mGame->Box1inProgress = true;
		currItem = random;
	}
	
	if (mAnimTimer > 0.5f && !displayItem  )
	{
		displayItem = new Item(mGame, "bread", 15, "A yummy snack, +15 coins!");
		SpriteComponent* temp = new SpriteComponent(this, 150);
		temp->SetTexture(mGame->GetTexture("Assets/bread.png"));
		displayItem->SetSprite(temp);
		displayItem->SetPosition(GetPosition());
		mGame->AddActor(displayItem);
	}
	
	if (mAnimTimer > 5.0f && opening)
	{
		mGame->GetPlayer()->updateBalance(15);
		opening = false;
		open = false;
		mAnimTimer = 0.0f;
		mGame->RemoveSprite(displayItem->GetSprite());
		displayItem = NULL;
		mGame->Box1inProgress = false;
	}
}
void LootBox::ProcessInput(const Uint8* keyState)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	bool mouseSpot = mCollis->Intersect(Vector2(x, y));

	
	
	if((SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)))
	{
		int playerBalance = GetGame()->GetPlayer()->getBalance();
		if (!opening && mouseSpot && playerBalance>=mCost)
		{
			GetGame()->GetPlayer()->updateBalance(-mCost);
			open = true;
		}
	}
	

}