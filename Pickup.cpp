#include "Pickup.h"
#include "TextureHolder.h"
Pickup::Pickup(int type)
{
	// Store the type of this pickup
	m_Type = type;
	// Associate the texture with the sprite
	if (m_Type == 1)
	{
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/health_pickup.png"));
		// How much is pickup worth
		m_Value = HEALTH_START_VALUE;
	}
	else
	{
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/ammo_pickup.png"));
		// How much is pickup worth
		m_Value = AMMO_START_VALUE;
	}
	m_Sprite.setOrigin(25, 25);
	m_SecondsToLive = START_SECONDS_TO_LIVE;
	m_SecondsToWait = START_WAIT_TIME;
}
