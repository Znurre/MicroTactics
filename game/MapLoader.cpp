#include <tiled/mapreader.h>
#include <tiled/map.h>

#include "MapLoader.h"
#include "GroundTile.h"
#include "CoverTile.h"

class PlayerSpawnTile : public GroundTile
{
	public:
		PlayerSpawnTile(int x, int y)
			: GroundTile(x, y)
		{
		}
};

MapLoader::MapLoader()
{

}

IMapTile *resolveTile(int id, int x, int y)
{
	switch (id)
	{
		case 0:
		{
			return new GroundTile(x, y);
		}

		case 1:
		{
			return new PlayerSpawnTile(x, y);
		}

		case 4:
		{
			return new CoverTile(x, y);
		}
	}

	return nullptr;
}

Map *MapLoader::load(const QString &fileName) const
{
	Tiled::MapReader mapReader;
	Tiled::Map *tiledMap = mapReader.readMap(fileName);

	QList<IMapTile *> playerSpawns;
	QList<IMapTile *> tiles;

	if (tiledMap)
	{
		for (int i = 0; i < tiledMap->layerCount(); i++)
		{
			Tiled::Layer *layer = tiledMap->layerAt(i);
			Tiled::TileLayer *tileLayer = dynamic_cast<Tiled::TileLayer *>(layer);

			if (tileLayer)
			{
				for (int y = 0; y < tileLayer->height(); y++)
				{
					for (int x = 0; x < tileLayer->width(); x++)
					{
						const Tiled::Cell &cell = tileLayer->cellAt(x, y);
						const Tiled::Tile *tile = cell.tile();

						const int id = tile->id();

						IMapTile *mapTile = resolveTile(id, x, y);

						if (mapTile)
						{
							tiles << mapTile;
						}

						PlayerSpawnTile *playerSpawn = dynamic_cast<PlayerSpawnTile *>(mapTile);

						if (playerSpawn)
						{
							playerSpawns << playerSpawn;
						}
					}
				}
			}
		}
	}

	const int width = tiledMap->width();
	const int height = tiledMap->height();

	return new Map(tiles, playerSpawns, width, height);
}
