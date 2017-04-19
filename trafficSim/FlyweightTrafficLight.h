#include "traffic_light.h"

class FlyweightTrafficLight
{
	private:
		Traffic_light *m_tTrafficLight;

	public:
		FlyweightTrafficLight();
		~FlyweightTrafficLight();
		int getNSlight();
		int getEWlight();
		void update(int state);
};