#pragma once
class Scene
{
protected:
	bool _restart;
	virtual void init() = 0;
	virtual void reinit() = 0;
public:
	Scene();	
	virtual void update() = 0;
	virtual void render() = 0;
	void setRestart(bool restart) { _restart = restart; init(); }
	bool getRestart() { return _restart; }
	~Scene();
};

