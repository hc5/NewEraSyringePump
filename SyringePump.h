#ifndef _SYRINGEPUMP
#define _SYRINGEPUMP

#include <string>
#include <vector>

#include "../../MMDevice/MMDevice.h"
#include "../../MMDevice/DeviceBase.h"
#include "../../MMDevice/DeviceUtils.h"
using namespace std;
class SyringePump : public CGenericBase<SyringePump>
{
public:
	SyringePump(void);
	~SyringePump(void);

	static int count;
	int Initialize();
	int Shutdown();

	void GetName(char* pszName) const;
	bool Busy();
private:
	bool initialized;
	int id;
	string buffer;
	void Read();
	void Send(string cmd);
	string query(string q);
};

#endif
