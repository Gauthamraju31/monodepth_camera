#include <deepstream_midas.h>


dsmidas::MidasPipeline::MidasPipeline()
{

  int current_device = -1;
  cudaGetDevice(&current_device);
  struct cudaDeviceProp prop;
  cudaGetDeviceProperties(&prop, current_device);
  gst_init (NULL, NULL);

}

dsmidas::MidasPipeline::~MidasPipeline()
{

}

dsmidas::MidasPipeline::setup()
{
    // Initialize the elements
    _pipeline = gst_pipeline_new("Deepstream MiDAS");
    _nvmux = gst_element_factory_make ("nvstreammux", "stream-muxer");
    
    
    if (!_pipeline || !_nvmux) {
        g_printerr ("One element could not be created. Exiting.\n");
        return -1;
    }
    gst_bin_add (GST_BIN (pipeline), streammux);
    
    _source = gst_element_factory_make ("uridecodebin", "source-decoder");
    _nvinfer = gst_element_factory_make ("nvinfer", "nvinference-engine");
    _queue = gst_element_factory_make ("queue", "queue");
    _convert = gst_element_factory_make ("nvvideoconvert", "nvvideo-convert");
    _appsink = gst_element_factory_make ("appsink", "app-sink");
    

    if (!_source || !_nvmux || !_nvinfer || !_queue || !_convert || !_convert || !_appsink) {
        g_printerr ("One element could not be created. Exiting.\n");
    }
    // _nvinfer = gst_element_factory_make ("nvinfer", "nvinference-engine");
    _bus = gst_pipeline_get_bus (GST_PIPELINE (_pipeline));



}



