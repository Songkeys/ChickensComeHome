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
		pSurface->drawRectangle(
			iStartPositionScreenX,
			iStartPositionScreenY,
			iStartPositionScreenX + getTileWidth() - 1,
			iStartPositionScreenY + getTileHeight() - 1,
			0xff0000);
		break;
	case 2: // thron
		pSurface->drawRectangle(
			iStartPositionScreenX,
			iStartPositionScreenY,
			iStartPositionScreenX + getTileWidth() - 1,
			iStartPositionScreenY + getTileHeight() - 1,
			0x00ffff);
		break;
	case 3: // door
		pSurface->drawRectangle(
			iStartPositionScreenX,
			iStartPositionScreenY,
			iStartPositionScreenX + getTileWidth() - 1,
			iStartPositionScreenY + getTileHeight() - 1,
			0xffffff);
		break;
	case 4: // egg
		break;
	default: // empty ground
		break;
	}
}