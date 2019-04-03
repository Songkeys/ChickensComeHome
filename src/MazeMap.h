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
};

