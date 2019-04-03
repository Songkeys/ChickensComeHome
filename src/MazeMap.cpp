#include "header.h"
#include "MazeMap.h"


MazeMap::MazeMap(int iTileHeight, int iTileWidth, int iCountX, int iCountY)
	:TileManager(iTileHeight, iTileWidth, iCountX, iCountY)
{
}

MazeMap::MazeMap()
	: TileManager(60, 60, 10, 10)
{
}

MazeMap::~MazeMap()
{
}

void MazeMap::virtDrawTileAt(
	BaseEngine* pEngine,
	DrawingSurface* pSurface,
	int iMapX, int iMapY,
	int iStartPositionScreenX, int iStartPositionScreenY)
{
	switch (getMapValue(iMapX, iMapY))
	{
	case 0: // floor
		pSurface->drawRectangle(
			iStartPositionScreenX,
			iStartPositionScreenY,
			iStartPositionScreenX + getTileWidth() - 1,
			iStartPositionScreenY + getTileHeight() - 1,
			pEngine->getColour(getMapValue(iMapX, iMapY)));
		break;
	case 1: // wall
		pSurface->drawRectangle(
			iStartPositionScreenX,
			iStartPositionScreenY,
			iStartPositionScreenX + getTileWidth() - 1,
			iStartPositionScreenY + getTileHeight() - 1,
			pEngine->getColour(getMapValue(iMapX, iMapY)));
		break;
	case 2: // thron
		pSurface->drawRectangle(
			iStartPositionScreenX,
			iStartPositionScreenY,
			iStartPositionScreenX + getTileWidth() - 1,
			iStartPositionScreenY + getTileHeight() - 1,
			pEngine->getColour(getMapValue(iMapX, iMapY)));
		break;
	}
}