#ifdef WIN32
   #include <windows.h>
   #define snprintf _snprintf 
#endif
#include "../../MMDevice/MMDevice.h"
#include "SyringePump.h"
#include <string>
#include <math.h>
#include "../../MMDevice/ModuleInterface.h"
#include "../../MMDevice/DeviceUtils.h"
#include <sstream>


const char* g_ControllerName = "New Era Pump Systems Syringe Pump";

MODULE_API void InitializeModuleData()
{
   AddAvailableDeviceName(g_ControllerName, "New Era Pump Systems Syringe Pump");
   
}

MODULE_API MM::Device* CreateDevice(const char* deviceName)
{
   if (deviceName == 0)
      return 0;

   if (strcmp(deviceName, g_ControllerName) == 0)
   {
      SyringePump* p = new SyringePump;
      return p;
   }

   return 0;
}

MODULE_API void DeleteDevice(MM::Device* pDevice)
{
   delete pDevice;
}


SyringePump::SyringePump(void):
initialized(0)
{


}

bool SyringePump::Busy(){
	return false;
}
void SyringePump::GetName(char * name) const{

}
int SyringePump::Shutdown(){
	initialized = false;
	return 0;
}
int SyringePump::Initialize(){
	return 0;
}
SyringePump::~SyringePump(void)
{
}
