#ifndef KING_ENGINE
#define KING_ENGINE

//Include GLEW
#include <GL/glew.h>

//Include the standard C++ headers
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "timer.h"
#include "Mouse.h"
#include "SceneGame.h"

#define FIRST 0

using std::string;

class KEngine
{
public:
	static KEngine& getInstance()
	{
		static KEngine engine;
		return engine;
	}

	void Init(string config);
	void Run(void);
	void Exit(void);

	Mouse* getMouse(void);
	
	bool getKeyboardUpdate(void);
	bool getMouseUpdate(void);
	bool getRun(void);
	
	static bool isKeyPressed(unsigned short key);
private:
	KEngine();
	~KEngine();

	void Config(void);

	GLFWwindow* m_window;
	StopWatch m_timer;
	double m_dElapsedTime;
	double m_dAccumulatedTime_ThreadOne;
	double m_dAccumulatedTime_ThreadTwo;

	Branch engineBranch;
	Mouse* mouse;
	unsigned char FPS;
	unsigned int frameTime;
	int m_window_width;
	int m_window_height;
	string windowTitle;
	bool run;
	bool fullScreen;

	// The handler for the scene
	SceneGame* scene;
	string sceneConfig;
};

#endif