# WebCam_MicrosoftMediaFoundation

- Original code is based on [Alejandro Rodriguez's blog](https://elcharolin.wordpress.com/2017/08/28/webcam-capture-with-the-media-foundation-sdk/), A very good introduction to accessing Webcams using Microsoft Media Foundation api calls.

- Modifications done by [HowardsPlayPen](https://github.com/HowardsPlayPen/WebCamMicrosoftFoundation):
    - Support for YUY2 and NV12 etc.
    - Modified Media::IsMediaTypeSupported.
    - Added an implementation of YUY2 to RGBA (TransformImage_YUY2) based on the Intel website https://software.intel.com/sites/landingpage/mmsf/documentation/preview_8cpp.html#af3d9de67be8e955b824d4b497bba4c96

- This fork is for reading 10 bit WebCam data. Few bit wise manipulation is done before Bayer Conversion is performed using OpenCV.