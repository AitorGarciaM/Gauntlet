#include "Map.h"
#include "Vendor/tinyxml2.h"


void Map::init()
{

	_resManager = ResourceManager::getInstance();

	_spriteId = _resManager->getTextureID("./Resources/Images/backgrounds.png");

	tinyxml2::XMLDocument xmlDoc;

	xmlDoc.LoadFile("./Resources/Levels/XML/mazmorra1.tmx");
	
	tinyxml2::XMLNode* mapRoot = xmlDoc.FirstChild();

	tinyxml2::XMLElement* mapElement = xmlDoc.FirstChildElement("map");
	tinyxml2::XMLElement* tilesetElement = mapElement->FirstChildElement("tileset");
	tinyxml2::XMLElement* layerElement = mapElement->FirstChildElement("layer");
	tinyxml2::XMLElement* dataElement = layerElement->FirstChildElement("data");

	_width = std::stoi(mapElement->Attribute("width"));
	_height = std::stoi(mapElement->Attribute("height"));

	_tileHeight = std::stoi(mapElement->Attribute("tileheight"));
	_tileWidth = std::stoi(mapElement->Attribute("tilewidth"));
	
	_firsgid = std::stoi(tilesetElement->Attribute("firstgid"));

	_data = dataElement->GetText();

	int posComa = 0;
	int i = 0;
	int counter = 0;
	while (counter < (_width * _height))
	{
		
		i = posComa;
		posComa = _data.find(',', posComa + 1);
		_idData.push_back(std::stoi(_data.substr(i+1,posComa-1)));

		counter++;
	}
}

void Map::render(Scuare cameraBounds)
{
	for (int y = 0; y < 50; y++)
	{
		for (int x = 0; x < 50; x++)
		{
			int xTrg = _tileWidth * x - cameraBounds.x;
			int yTrg = _tileHeight * y - cameraBounds.y;

			int id = _idData[y * _width + x];
			
			if (id < _firsgid)
			{
				continue;
			}

			int xTile = (id - 1) % 16;
			int yTile = (id - 1) / 16;

			Scuare bounds;
			bounds.x = xTile * _tileWidth;
			bounds.y = yTile * _tileHeight;
			bounds.w = _tileWidth;
			bounds.h = _tileHeight;
			Vector pos = { xTrg, yTrg};

			_resManager->DrawInWindow(_spriteId, bounds, pos);
		}
	}
}

Map::Map()
{
}


Map::~Map()
{
}
