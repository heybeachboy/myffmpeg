#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include "avinfo.h"
AvInfo::AvInfo()
{
    size = 4;
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

vector<string>AvInfo::GetAvDecode(){
    vector<string> rest;
    void *opaque = NULL;
    const AVCodec *deCodec = av_codec_iterate(&opaque);
    while (deCodec != NULL) {
        if(av_codec_is_decoder(deCodec)){
            rest.push_back(deCodec->name);
        }
        deCodec = av_codec_iterate(&opaque);
    }
    return rest;

}

vector<string>AvInfo::GetAvEncode(){
    vector<string> rest;
    void *opaque = NULL;
    const AVCodec *avCodec = av_codec_iterate(&opaque);
    while (avCodec != NULL) {
        if(av_codec_is_encoder(avCodec)){
            rest.push_back(avCodec->name);
        }
        avCodec = av_codec_iterate(&opaque);
    }
    return rest;

}

vector<string> AvInfo::GetAvStreamFilter(){
    vector<string> rest;
    void *opaque = NULL;

    const AVBitStreamFilter *bsf = av_bsf_iterate(&opaque);

    while (bsf != NULL) {
        rest.push_back(bsf->name);
        bsf = av_bsf_iterate(&opaque);
    }
    return rest;
}

AvInfo::~AvInfo(){
    delete data;
}
