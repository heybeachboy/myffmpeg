#ifndef AVINFO_H
#define AVINFO_H
#include <string>
#include <vector>
#ifdef _WIN32
//Windows
extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libavfilter/avfilter.h"
};
#else
//Linux...
#ifdef __cplusplus
extern "C"
{
#endif
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavfilter/avfilter.h>
#ifdef __cplusplus
};
#endif
#endif
using namespace std;
class AvInfo
{
public:
    AvInfo();
    virtual ~AvInfo();
    /**
      * @brief GetUrlProtocolInfo
      * @param type 0.in protocol  2.out protocol
      * @return
      */
     vector<string> GetUrlProtocolInfo(int type);
     vector<string> GetAvFormatInfo(int type);
     string GetVersionInfo(void);
     string GetConfigInfo(void);
     unsigned GetVersionNumber(void);
     string GetLicense(void);
private:
   char *data;
   int size;
   void initData();
   struct URLProtocol;


};

#endif // AVINFO_H
