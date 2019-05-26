#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include "avinfo.h"
AvInfo::AvInfo()
{
    size = 40000;
    data = (char *)malloc(size);

}

string AvInfo::GetVersionInfo(){
    string version = av_version_info();
    return version;
}

string AvInfo::GetLicense(){
    string license = avutil_license();
    return license;
}

unsigned AvInfo::GetVersionNumber(){
    return avutil_version();
}

string AvInfo::GetConfigInfo(){
    string config = avutil_configuration();
    return config;
}



void AvInfo::initData() {
    memset(data,0,size);
    return;
}
vector<string> AvInfo::GetUrlProtocolInfo(int type){
    vector<string> rest;
    if(type < 0 || type > 1) return rest;
    void *opaque = NULL;
    const char *protocol = avio_enum_protocols(&opaque, type);
    while (protocol!=NULL){
        rest.push_back(protocol);
        protocol = avio_enum_protocols(&opaque, type);
    }
    return rest;
}

vector<string> AvInfo::GetAvFormatInfo(int type) {
    vector<string> rest;
    if(type < 0 || type > 1) return rest;
    void *opaque = NULL;
    if(type ==0) {
        const AVInputFormat *inputFormat = av_demuxer_iterate(&opaque);
        while (inputFormat != NULL) {
            rest.push_back(inputFormat->name);
            inputFormat = av_demuxer_iterate(&opaque);
        }
        return rest;
    }
    const AVOutputFormat *outputFormat = av_muxer_iterate(&opaque);
    while(outputFormat != NULL) {
        rest.push_back(outputFormat->name);
        outputFormat = av_muxer_iterate(&opaque);
    }
    return rest;

}

AvInfo::~AvInfo(){
    delete data;
}
