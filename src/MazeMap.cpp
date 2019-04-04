#include "header.h"
#include "MazeMap.h"


MazeMap::MazeMap(int iTileHeight, int iTileWidth, int iCountX, int iCountY)
	:TileManager(iTileHeight, iTileWidth, iCountX, iCountY)
{
}

MazeMap::MazeMap()
	//: TileManager(60, 60, 10, 10)
	: TileManager(20, 20, 10, 10)
{
}

MazeMap::~MazeMap()
{
}

void MazeMap::virtDrawTileAt(
	BaseEngine* pEngine,
	DrawingSurface* pSurface,
	int iMapX, int iMapY,
	int iStartPositionScreenX, int iStartPositionScreenY) const
{
	switch (getMapValue(iMapX, iMapY))
	{
	case 0: // empty ground
		break;
	case 1: // wall
	{
		SimpleImage image = ImageManager::loadImage("resources/images/wall.png", true).resizeTo(m_iTileWidth, m_iTileWidth);
		image.renderImage(pSurface,
			0,
			0,
			iStartPositionScreenX,
			iStartPositionScreenY,
			m_iTileWidth,
			m_iTileHeight);
	}
		break;
	case 2: // thorn
	{
		SimpleImage image = ImageManager::loadImage("resources/images/thorn.png", true).resizeTo(m_iTileWidth, m_iTileWidth);
		image.renderImageWithMask(pSurface,
			0,
			0,
			iStartPositionScreenX,
			iStartPositionScreenY,
			m_iTileWidth,
			m_iTileHeight);
	}
		break;
	case 3: // home
	{
		SimpleImage image = ImageManager::loadImage("resources/images/home.png", true).resizeTo(m_iTileWidth, m_iTileWidth);
		image.renderImageWithMask(pSurface,
			0,
			0,
			iStartPositionScreenX,
			iStartPositionScreenY,
			m_iTileWidth,
			m_iTileHeight);
	}
		break;
	case 4: // egg
	{
		SimpleImage image = ImageManager::loadImage("resources/images/egg.png", true).resizeTo(m_iTileWidth, m_iTileWidth);
		image.renderImageWithMask(pSurface,
			0,
			0,
			iStartPositionScreenX,
			iStartPositionScreenY,
			m_iTileWidth,
			m_iTileHeight);
	}
		break;
	case 9: // chicken (empty ground)
	{
		// remove or transparent?
		SimpleImage image = ImageManager::loadImage("resources/images/grass_bg.jpg", true);
		image.renderImage(pSurface,
			0,
			0,
			iStartPositionScreenX,
			iStartPositionScreenY,
			m_iTileWidth,
			m_iTileHeight);
	}
		break;
	default: // empty ground
		break;
	}
}