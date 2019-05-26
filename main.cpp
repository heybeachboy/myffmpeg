#include <iostream>
#include "avcore/mymath.h"
#include "avcore/avinfo.h"
#ifdef __cplusplus
extern "C" {
#include "libavformat/avformat.h"
#include "libavutil/log.h"
}
#endif
using namespace std;

int main()
{
    MyMath m;
    AvInfo info;
    cout << "version :" << info.GetVersionInfo() << endl;
    cout << "version number:" << info.GetVersionNumber() << endl;
    cout << "License:" << info.GetLicense() << endl;
    cout << "Configure:" << info.GetConfigInfo() << endl;

    vector<string> in = info.GetAvFormatInfo(1);
    for(auto val : in)cout << val << " ";
    cout << "\n" <<endl;
   // cout << "SUM :" << m.Sum(100, 600) << endl;
  //  av_register_all();
  //  av_log(NULL, AV_LOG_ERROR, "runing !!! service is death");
  //  cout << "Hello World!" << endl;
    return 0;
}
