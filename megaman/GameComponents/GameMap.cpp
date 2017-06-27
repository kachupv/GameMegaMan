#include "GameMap.h"


GameMap::GameMap(char *fileMap)
{
	// Get data from file map editor
	mMap = new Tmx::Map();
	mMap->ParseFile(fileMap);

#pragma region Load data from a file *.txt
	for (size_t i = 0; i < mMap->GetNumTilesets(); i++)
	{
		const Tmx::Tileset *tileset = mMap->GetTileset(i);
		Sprite *sprite = new Sprite(tileset->GetImage()->GetSource().c_str());
		mTiles.insert(std::pair<int, Sprite*>(i, sprite));
	}
#pragma endregion
}


GameMap::~GameMap()
{
	if (!mMap)
	{
		delete mMap;
		mMap = NULL;
	}
}

void GameMap::Draw()
{
	/*for (int i = 0; i < mHeight; i++)
    {
        for (int j = 0; j < mWidth; j++)
        {
			int id = mMap[i].at(j);

            mTileSet->SetIndex(id);
			D3DXVECTOR2 pos = D3DXVECTOR2(j * 16, i * 16);
            mTileSet->Render(D3DXVECTOR2(1.0f, 1.0f), 0.0f, pos);
        }
    }*/
}