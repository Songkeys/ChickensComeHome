#pragma once
#include "TileManager.h"
class MazeMap :
	public TileManager
{
public:
	MazeMap(int iTileHeight, int iTileWidth, int iCountX, int iCountY);
	MazeMap();
	~MazeMap();

	void virtDrawTileAt(
		BaseEngine* pEngine,
		DrawingSurface* pSurface,
		int iMapX, int iMapY,
		int iStartPositionScreenX, int iStartPositionScreenY) const override;

	int getScreenXForMapX(int iMapX) const
	{
		return iMapX * getTileWidth() + m_iBaseScreenX;
	}

	int getScreenYForMapY(int iMapY) const
	{
		return iMapY * getTileHeight() + m_iBaseScreenY;
	}
};

