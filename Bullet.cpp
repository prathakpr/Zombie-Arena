#include "bullet.h"
// The constructor
Bullet::Bullet()
{
	m_BulletShape.setSize(sf::Vector2f(2, 2));
}
void Bullet::shoot(float startX, float startY,
	float targetX, float targetY)
{
	// Keep track of the bullet
	m_InFlight = true;
	m_Position.x = startX;
	m_Position.y = startY;
	// Calculate the gradient of the flight path
	float gradient = (startX - targetX) / (startY - targetY);
	// Any gradient less than 1 needs to be negative
	if (gradient < 0)
	{
		gradient *= -1;
	}
	// Calculate the ratio between x and y
	float ratioXY = m_BulletSpeed / (1 + gradient);
	// Set the "speed" horizontally and vertically
	m_BulletDistanceY = ratioXY;
	m_BulletDistanceX = ratioXY * gradient;

	// Point the bullet in the right direction
	if (targetX < startX)
	{
		m_BulletDistanceX *= -1;
	}
	if (targetY < startY)
	{
		m_BulletDistanceY *= -1;
	}

	// Set a max range of 1000 pixels
	float range = 1000;
	m_MinX = startX - range;
	m_MaxX = startX + range;
	m_MinY = startY - range;
	m_MaxY = startY + range;

	// Position the bullet ready to be drawn
	m_BulletShape.setPosition(m_Position);
}
