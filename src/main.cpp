#include <iostream>
#include <opencv2/opencv.hpp>
#include "Media.h"
#include <Windows.h>
using namespace std;
using namespace cv;

void FormBayer(BYTE* dest, BYTE* rawData, int width, int height, int BytesPerPixel){
	for(int i =0; i< (width*height*BytesPerPixel); i+=2){
		uint16_t l = rawData[i];
		uint16_t h = rawData[i+1];
		uint16_t data = h*256 + l;
		dest[i/2] = BYTE((data & 0x3FF)>>2);
	}
}

int main(int argc, char** argv )
{
    namedWindow("Display");

    Media* m = new Media(1);
	m->CreateCaptureDevice();
    
	std::cout<<"Device Count = "<<m->deviceCount<<std::endl;
    std::cout<<"Device name = "<<m->deviceNameString<<std::endl;
	std::cout<<"w = "<<m->width<<" h = "<<m->height<<" bpp = "<<m->bytesPerPixel<<std::endl;
	
	BYTE* buffer = new BYTE[m->width*m->height*sizeof(BYTE)];
	MSG msg{ 0 };
	
	while (msg.message != WM_QUIT)
	{
            if (m->videoFormat == MFVideoFormat_YUY2)
		{
			
			FormBayer(buffer, m->rawData, m->width, m->height, m->bytesPerPixel);
		}

        Mat newImg = Mat(m->height, m->width, CV_8UC1, buffer);
		cvtColor(newImg, newImg, COLOR_BayerBG2RGB);
        imshow("Display", newImg);
        if(waitKey(5) == 'q')
        {
            destroyAllWindows();
            break;
        }
        while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
				continue;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
    }
	m->Release();
	delete buffer;

    return 0;
}