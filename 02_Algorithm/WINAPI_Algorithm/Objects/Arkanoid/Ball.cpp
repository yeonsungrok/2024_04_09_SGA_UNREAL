#include "pch.h"
#include "Ball.h"
#include "Objects/Arkanoid/Ball.h"
#include "Objects/Arkanoid/Player_Rectangle.h"

Ball::Ball()
{
	_circle = make_shared<CircleCollider>(Vector2(-1000,0), 10.0f);   //CENTER
	//_circle->SetBlack(); 
	
}

Ball::~Ball()
{
}

void Ball::Update()
{
	Move();
	
	_circle->Update();

	// �����¿� �ݻ�
	if (_circle->_center._x < leftTop._x || _circle->_center._x > rightBottom._x)
	{
		_dir._x *= -1;
	}
	if (_circle->_center._y < leftTop._y /*|| _circle->_center._y > rightBottom._y*/)
	{
		_dir._y *= -1;
	}

	
	
}

void Ball::Render(HDC hdc)
{
	
	_circle->Render(hdc);

}

void Ball::Move()
{
	_circle->_center += _dir * _speed;
}

