#ifndef __DEEPSTREAM_MIDAS_H__
#define __DEEPSTREAM_MIDAS_H__

#include <cuda_runtime_api.h>

extern "C"{
#include <gst/gst.h>
}


namespace dsmidas {

class MidasPipeline
{
public:
    MidasPipeline();
    ~MidasPipeline();

    int setup();
    bool configure(std::string);
    bool start_stream();
    bool change_state();
    bool cleanup_stream();

private:

    std::string _uri;

    GstElement *_pipeline;
    GstElement *_source;    // uridecodebin
    GstElement *_nvmux;
    GstElement *_nvinfer
    GstElement *_queue;
    GstElement *_convert;
    GstElement *_appsink;
    GstElement *_caps;

    GstBus *_bus;
    GstMessage *_msg;

    GstElement * _create_uridecode_bin ()

}

}


#endif // __DEEPSTREAM_MIDAS_H__