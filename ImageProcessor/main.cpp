//#include <iostream>
//#include <SDL.h>
//#include <math.h>
//#include <stdio.h>
//#include <string.h>

//bool leftMouseButtonDown = false;
//bool quit = false;
//SDL_Event event;


//SDL_Window * window;
//int drawingWindowId;
//int ToolsWindowId;

//SDL_Renderer * renderer;
////SDL_Renderer * renderer2;
//SDL_Texture * texture;

//Uint32 * pixels = new Uint32[640 * 480];
////void * pixels2;

//Uint32 * backbufferPixels=NULL;
//int sizeofbackbufferPixels;

//Uint8 tmpColor;


////ToolBox Booleans
//typedef enum {FALSE,TRUE} boolean;
//boolean drawRectangle =FALSE;
//boolean drawPointLine =FALSE;
//boolean drawPointCircle =FALSE;
//boolean drawPointPencil =FALSE;
//boolean drawPointBrush =FALSE;
//boolean drawPointBucketFill =FALSE;
//boolean drawPointRedColor =FALSE;
//boolean drawPointBlackColor =FALSE;
//boolean drawPointEraser =FALSE;

//boolean NOWDRAWING =FALSE;

//boolean executedOnce =FALSE;

//SDL_Color colorpicked;

/////////////////////////////////////////////////////////////////////
///// \brief loadedSurface
//const char * path="toolbox.png";
//SDL_Surface* loadedSurface;
//SDL_Surface * surf;

//SDL_Surface* formattedSurface;
//SDL_Surface* formattedSurface;

//SDL_Texture * texture2;


//typedef struct Point
//{
//    Point(){;}
//    Point(int _x,int _y){x=_x;y=_y;}
//    ~Point(){}
//    Point(const Point &_p){x=_p.x;y=_p.y;}
//    void operator=(const Point &_p){x=_p.x;y=_p.y;}

//    int x,y;
//}p;


//Point lineStart;
//Point lineEnd;

//void drawBresenhamLine(int x,int y,int x2,int y2)
//{
//     if (x<0) {x=0;};
//     if (x>640) {x=639;}
//     if (y<0) {y=0;}
//     if (y>480) {y=479;}

//     if (x2<0) {x2=0;};
//     if (x2>640) {x2=639;}
//     if (y2<0) {y2=0;}
//     if (y2>480) {y2=479;}

//      Point * lineArray=NULL;
//      lineArray=(Point*)malloc(1*sizeof(Point));


//      //http://tech-algorithm.com/articles/drawing-line-using-bresenham-algorithm/
//      int w = x2 - x ;
//      int h = y2 - y ;
//      int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0 ;
//      if (w<0) dx1 = -1 ; else if (w>0) dx1 = 1 ;
//      if (h<0) dy1 = -1 ; else if (h>0) dy1 = 1 ;
//      if (w<0) dx2 = -1 ; else if (w>0) dx2 = 1 ;

//      int longest = abs(w) ;
//      int shortest = abs(h) ;

//      if (!(longest>shortest))
//      {
//          longest = abs(h) ;
//          shortest = abs(w) ;
//          if (h<0) dy2 = -1 ;
//          else if (h>0) dy2 = 1 ;
//          dx2 = 0 ;
//      }
//      int numerator = longest >> 1 ;
//      for (int i=0;i<=longest;i++)
//      {
//          SDL_RenderDrawPoint(renderer,x,y);

//          lineArray=(Point*)realloc(lineArray,(i+1)*sizeof(Point));
//          lineArray[i]=Point(x,y);


//    //          std::cout<<"lineArray="<<lineArray[i].x<<","<<lineArray[i].y<<std::endl;

//          numerator += shortest ;
//          if (!(numerator<longest))
//          {
//              numerator -= longest ;
//              x += dx1 ;
//              y += dy1 ;
//          } else {
//              x += dx2 ;
//              y += dy2 ;
//          }
//      }

//    //clear our buffer constantly so as to end up with only 1 line

//    //Now create the backbuffercopy of the original pixel array (our board)
//    memcpy(backbufferPixels, pixels,  640 * 480 * sizeof(Uint32));

//    for(int i=0;i<=longest;i++)
//    {

//        Uint32 tmpPixel=SDL_MapRGB(formattedSurface->format, colorpicked.r,colorpicked.g,colorpicked.b);
//        backbufferPixels[lineArray[i].y * 640 + lineArray[i].x]=tmpPixel;
//    }

//    free(lineArray);
//}


//int main(int argc, char ** argv)
//{

//    SDL_Init(SDL_INIT_VIDEO);

//    SDL_Window * window = SDL_CreateWindow("SDL2 Turtle Graphics / Spirolateral Drawing",
//        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

//    renderer = SDL_CreateRenderer(window, -1, 0);
//    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, 640, 480);

//    surf = SDL_CreateRGBSurface(0,640,480,32,0,0,0,0);
//    formattedSurface = SDL_ConvertSurfaceFormat( surf, SDL_PIXELFORMAT_ARGB8888, NULL );
//    if( formattedSurface == NULL )
//    {
//        printf( "Unable to convert loaded surface to display format! SDL Error: %s\n", SDL_GetError() );
//    }
//    else
//    {
//            int pitch;
//            void *pxs=(void*)pixels;
//            //Lock texture for manipulation
//            SDL_LockTexture( texture, NULL, &pxs, &pitch );

//            //Copy loaded/formatted surface pixels
//            memcpy( pixels, formattedSurface->pixels, 640 *480 );

//            //Unlock texture to update
//            SDL_UnlockTexture( texture );

//    }
//    //Get rid of old loaded surface
//    SDL_FreeSurface( surf );


//    memset(pixels, 255, 640 * 480 * sizeof(Uint32));


//    while (!quit)
//    {
//        SDL_UpdateTexture(texture, NULL, pixels, 640 * sizeof(Uint32));
//        SDL_PollEvent(&event);

//        SDL_Rect DestR;
//        DestR.x = 100;
//        DestR.y = 100;
//        DestR.w = 100;
//        DestR.h = 100;

//        switch (event.type)
//        {
//        case SDL_KEYDOWN:

//            if (event.key.keysym.sym==SDLK_SPACE)
//            {
//                memset(pixels,255,640*480*sizeof(Uint32));
//                executedOnce=FALSE;
//            }
//            break;


//        case SDL_MOUSEBUTTONUP:
//            if (event.button.button == SDL_BUTTON_LEFT)
//            {
//                leftMouseButtonDown = false;

//                //Decision made- Now mouse is up, so copy to original 'pixel' data the buffered data.
//                std::cout<<"drawPointLine="<<drawPointLine<<std::endl;

//                 if (drawPointLine && backbufferPixels!=NULL)
//                {
//                    memcpy(pixels,backbufferPixels,640*480*sizeof(Uint32));

//                    delete backbufferPixels;
//                    backbufferPixels=NULL;
//                    drawPointLine=FALSE;


//                }

//                if (drawPointCircle && backbufferPixels!=NULL)
//                {
//                    memcpy(pixels,backbufferPixels,640*480*sizeof(Uint32));

//                    delete backbufferPixels;
//                    backbufferPixels=NULL;
//                }

//                NOWDRAWING=FALSE;

//            }
//            break;
//        case SDL_MOUSEBUTTONDOWN:
//            {
//                if (event.button.button == SDL_BUTTON_LEFT)
//                {
//                    leftMouseButtonDown = true;
//                    drawPointLine=TRUE;
//                }

//            }
//            break;

//        case SDL_MOUSEMOTION:
//            if (leftMouseButtonDown)
//            {



//            }
//            break;
//        case SDL_QUIT:
//            quit = true;
//            break;
//        }


//int mouseX = event.motion.x;
//int mouseY = event.motion.y;

//if (drawPointLine==TRUE && !executedOnce)
//{
//        //avoid multiple executions
//        executedOnce=TRUE;

//        //Line Drawing
//        //Make sure we draw the texture and THEN..we draw on the top of it for the backbuffer lines,points (for circle,rectangle)
//        SDL_RenderCopy(renderer, texture, NULL, NULL);

//        Point currentmousePos(mouseX,mouseY);
//        //start line point initialized just once
//        if (!NOWDRAWING)
//        {
//            NOWDRAWING=TRUE;
//            lineStart=currentmousePos;
//        }

//        std::cout<<"lineStart="<<lineStart.x<<","<<lineStart.y<<std::endl;

//        //end line point
//        lineEnd=currentmousePos;

//        //Allocate some memory for the backbufferPixels
//        if (backbufferPixels==NULL)
//        {
//            backbufferPixels=(Uint32*)malloc(640*480* sizeof(Uint32));
//        }
//        else
//        {
//            memset(backbufferPixels,0,640*480* sizeof(Uint32));
//        }

//        //Now create the backbuffercopy of the original pixel array (our main drawing board)
//        memcpy(backbufferPixels, pixels,  640 * 480 * sizeof(Uint32));

//        //Draw Simple Spirolateral (angle 90. initial segment 1, order 2, repetitions/recursion 2)

//        int initialangle=0;
//        int initialSegment=20;
//        int order=6;
//        int repetitionRecursion=2;

//        printf ("Enter angle (ex. 60):  ");
//        scanf("%d",&initialangle);

//        printf ("Enter initialSegment length (ex. 5): ");
//        scanf("%d",&initialSegment);

//        printf ("Enter fractal order (ex. 7): ");
//        scanf("%d",&order);

//        printf ("Enter repetitionRecursion (ex. 80): ");
//        scanf("%d",&repetitionRecursion);


//        Point end=lineStart;

//        int segment=0;
//        int angle=initialangle;
//        for (int i=0; i<repetitionRecursion;i++)
//        {
//            segment=initialSegment;
////            angle=initialangle;

//            //draw lines sequentially based on the order of the spirolateral (in. example 2= times= 2 segments need to be drawn for the spirolateral to be completed)
//            for (int j=0; j<order;j++)
//            {
//                SDL_RenderPresent(renderer);

//                end.x=lineStart.x+segment*sin(angle*M_PI/180.0f);
//                end.y=lineStart.y+segment*cos(angle*M_PI/180.0f);

//                drawBresenhamLine(lineStart.x,lineStart.y, end.x,end.y);
//                memcpy(pixels,backbufferPixels,640*480*sizeof(Uint32));

//                lineStart=end;
//                segment+=initialSegment;
//                angle-=initialangle;
//                angle=fmod(angle,360.0);

//                printf ("Draw with angle %d\n:", angle);

//            }
//            SDL_RenderPresent(renderer);
//        }

//        drawPointLine=FALSE;
//}





//        // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
//        if(!leftMouseButtonDown)
//        {
//            SDL_RenderCopy(renderer, texture, NULL, NULL);
//        }

//        //update the rendered image
//        SDL_RenderPresent(renderer);

//    }

//    SDL_FreeSurface( formattedSurface );

//    delete[] pixels;
//    SDL_DestroyTexture(texture);
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();

//    return 0;
//}




#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <stdio.h>

#include <math.h>

bool quit = false;
SDL_Event event;

SDL_Window * window;
SDL_Renderer * renderer;
SDL_Surface * image;
SDL_Surface * formattedSurface;


SDL_Texture * texture;

Uint32 * pixels;
Uint32 * backbufferpixels;
Uint32 * originalImagepixels;

SDL_Surface * imageSRCCOLORGRADE;
SDL_Surface * formattedSurfaceSRC;
SDL_Texture * texture2;

typedef struct XYZ
{
    double x,y,z;
}XYZ;

XYZ xyz;


typedef struct Lab
{
    double L,a,b;
}Lab;

Lab lab;

Uint32 * srcImagePixels;

float sharpenCoefficient=1;
void sharpen(Uint32 ** pixels, float sharpenCoefficient)
{
    //Filter matrix 3x3
    float sharpMat[3][3]={{-1,-2,-1},{-2,19,-2},{-1,-2,-1}};
    for (int jj=0; jj <3 ; ++jj)
        for (int ii=0; ii <3 ; ++ii)
            sharpMat[jj][ii]*=(float)1/7;


    for (int y = 0; y < formattedSurface->h; y++)
    {
        for (int x = 0; x < formattedSurface->w; x++)
        {
            //leave out the edges of the image
            if(y!=0 && y!=formattedSurface->h-1 && x!=0 && x!=formattedSurface->w-1)
            {
                float sumR=0;
                float sumG=0;
                float sumB=0;

                for (int i = -1; i <= 1; i++)
                {
                    for (int j = -1; j <= 1; j++)
                    {
                        int tmpIndex = (y+i) * formattedSurface->w + x+j;

                        Uint8  red=0;
                        Uint8  green=0;
                        Uint8  blue=0;

                        //multiply with 9
                        if(i==0 && j==0)
                        {
                            SDL_GetRGB((*pixels)[tmpIndex], formattedSurface->format, &red, &green, &blue);
                            float r=(float)red*sharpenCoefficient*sharpMat[i+1][j+1];
                            float g=(float)green*sharpenCoefficient*sharpMat[i+1][j+1];
                            float b=(float)blue*sharpenCoefficient*sharpMat[i+1][j+1];

                            sumR+=r;
                            sumG+=g;
                            sumB+=b;
                        }
                        else if (abs(i)==abs(j) && i!=0) //but not the central element
                        {
                            SDL_GetRGB((*pixels)[tmpIndex], formattedSurface->format, &red, &green, &blue);
                            float r=(float)red*sharpMat[i+1][j+1];
                            float g=(float)green*sharpMat[i+1][j+1];
                            float b=(float)blue*sharpMat[i+1][j+1];

                            sumR+=r;
                            sumG+=g;
                            sumB+=b;
                        }
                        else
                        {
                            SDL_GetRGB((*pixels)[tmpIndex], formattedSurface->format, &red, &green, &blue);
                            float r=(float)red*sharpMat[i+1][j+1];
                            float g=(float)green*sharpMat[i+1][j+1];
                            float b=(float)blue*sharpMat[i+1][j+1];

                            sumR+=r;
                            sumG+=g;
                            sumB+=b;
                        }

                    }
                }

                if(sumR <0) sumR=0;  if(sumR >255) sumR=255;
                if(sumG <0) sumG=0;  if(sumG >255) sumG=255;
                if(sumB <0) sumB=0;  if(sumB >255) sumB=255;

                SDL_Color c;
                c.r=sumR;
                c.g=sumG;
                c.b=sumB;
                Uint32 tmpPixel=SDL_MapRGB(formattedSurface->format, c.r, c.g, c.b);
                (*pixels)[ y * formattedSurface->w + x] = tmpPixel;

            }
        }
    }

}


void blur(Uint32 ** pixels)
{
    //Filter matrix 3x3
    float blurMat[3][3]={{1.0/9,1.0/9,1.0/9},{1.0/9,1.0/9,1.0/9},{1.0/9,1.0/9,1.0/9}};



    for (int y = 0; y < formattedSurface->h; y++)
    {
        for (int x = 0; x < formattedSurface->w; x++)
        {
            int sumR=0;int sumG=0;int sumB=0;

            //leave out the edges of the image
            if(y!=0 && y!=formattedSurface->h-1 && x!=0 && x!=formattedSurface->w-1)
            {
                float sumR=0;
                float sumG=0;
                float sumB=0;

                for (int i = -1; i <= 1; i++)
                {
                    for (int j = -1; j <= 1; j++)
                    {
                        int tmpIndex = (y+i) * formattedSurface->w + x+j;

                        Uint8  red=0;
                        Uint8  green=0;
                        Uint8  blue=0;

                        SDL_GetRGB((*pixels)[tmpIndex], formattedSurface->format, &red, &green, &blue);
                        float r=(float)red*blurMat[i+1][j+1];
                        float g=(float)green*blurMat[i+1][j+1];
                        float b=(float)blue*blurMat[i+1][j+1];

                        sumR+=r;
                        sumG+=g;
                        sumB+=b;
                    }
                }

                if(sumR <0) sumR=0;  if(sumR >255) sumR=255;
                if(sumG <0) sumG=0;  if(sumG >255) sumG=255;
                if(sumB <0) sumB=0;  if(sumB >255) sumB=255;

                SDL_Color c;
                c.r=sumR;
                c.g=sumG;
                c.b=sumB;
                Uint32 tmpPixel=SDL_MapRGB(formattedSurface->format, c.r, c.g, c.b);
                (*pixels)[ y * formattedSurface->w + x] = tmpPixel;

            }
        }
    }
}


void processHighlights(Uint32 **pixels)
{
int RGBr, RGBg, RGBb = 0;
int Hr, Hg, Hb = 0;
int Gr, Gg, Gb = 0;
const int ConstantV = 50;

Uint32 newPixel;


for (int y = 0; y < formattedSurface->h; y++)
{
    for (int x = 0; x < formattedSurface->w; x++)
    {

        Uint8  red=0;
        Uint8  green=0;
        Uint8  blue=0;

        SDL_GetRGB((*pixels)[y * formattedSurface->w + x], formattedSurface->format, &red, &green, &blue);



        Hr = red - ConstantV;
        Hg = green - ConstantV;
        Hb = blue - ConstantV;

        //clamp
        if (Hr < 0){ Hr = 0; }
        if (Hg < 0){ Hg = 0; }
        if (Hb < 0){ Hb = 0; }

        RGBr = Hr;
        RGBg = Hg;
        RGBb = Hb;

        //add glare
//        Gr = red + Hr;
//        Gg = green + Hg;
//        Gb = blue + Hb;

        RGBr = red + RGBr;
        RGBg = green + RGBg;
        RGBb = blue + RGBb;


        Gr=RGBr;
        Gg=RGBg;
        Gb=RGBb;


        //clamp
        if (Gr > 255){ Gr = 255; }
        if (Gg > 255){ Gg = 255; }
        if (Gb > 255){ Gb = 255; }

        RGBr = Gr;
        RGBg = Gg;
        RGBb = Gb;


        newPixel = SDL_MapRGB(image->format,RGBr,RGBg,RGBb);//maps the pixel values and then assigns to the variable
        (*pixels)[y * formattedSurface->w + x]=newPixel;
}
}
}



static float brightness=0;
void brighten(Uint32 **pixels, int brightness)
{
    for (int y = 0; y < formattedSurface->h; y++)
    {
        for (int x = 0; x < formattedSurface->w; x++)
        {
            int tmpIndex = y * formattedSurface->w + x;

            Uint8  red=0;
            Uint8  green=0;
            Uint8  blue=0;

            SDL_GetRGB((*pixels)[tmpIndex], formattedSurface->format, &red, &green, &blue);
            float r=(float)red+brightness;
            float g=(float)green+brightness;
            float b=(float)blue+brightness;

            if(r <0) r=0;  if(r >255) r=255;
            if(g <0) g=0;  if(g >255) g=255;
            if(b <0) b=0;  if(b >255) b=255;


            SDL_Color c;
            c.r=r;
            c.g=g;
            c.b=b;
            Uint32 tmpPixel=SDL_MapRGB(formattedSurface->format, c.r, c.g, c.b);
            (*pixels)[ y * formattedSurface->w + x] = tmpPixel;

        }
    }
}


int clamp(int n)
{
    if ((unsigned) n <= 255) {
        return n;
    }
    return (n < 0) ? 0 : 255;
}
static float contrastFactor=0;
void contrast(Uint32 **pixels, float contrastFactor)
{
    int maxPixelintensity=0;
    int minPixelintensity=255;
    for (int y = 0; y < formattedSurface->h; y++)
    {
        for (int x = 0; x < formattedSurface->w; x++)
        {
            int tmpIndex = y * formattedSurface->w + x;

            Uint8  red=0;
            Uint8  green=0;
            Uint8  blue=0;

            float factor = (259 * (contrastFactor + 255)) / (255 * (259 - contrastFactor));

            SDL_GetRGB((*pixels)[tmpIndex], formattedSurface->format, &red, &green, &blue);
            float r=(float)red;
            float g=(float)green;
            float b=(float)blue;

            float newRed   = clamp((factor * (r)   - 128) + 128);
            float newGreen = clamp((factor * (g)   - 128) + 128);
            float newBlue  = clamp((factor * (b)   - 128) + 128);

            SDL_Color c;
            c.r=newRed;
            c.g=newGreen;
            c.b=newBlue;
            Uint32 tmpPixel=SDL_MapRGB(formattedSurface->format, c.r, c.g, c.b);
            (*pixels)[ y * formattedSurface->w + x] = tmpPixel;

//            int currentpixelIntensity=(r+g+b) /3;
//            if(currentpixelIntensity > maxPixelintensity)
//                maxPixelintensity=currentpixelIntensity;

//            if(currentpixelIntensity < minPixelintensity)
//                minPixelintensity=currentpixelIntensity;
        }
    }

}




/// <summary>
/// XYZ to L*a*b* transformation function.
/// </summary>
double Fxyz(double t)
{
    return ((t > 0.008856)? pow(t, (1.0/3.0)) : (7.787*t + 16.0/116.0));
}

/// <summary>
/// Converts CIEXYZ to CIELab.
/// </summary>
void XYZtoLab(XYZ *XYZpixel, Lab *Labpixel, double X, double Y, double Z)
{
    double CIEXYZ [] = {0.9505, 1.0, 1.0890};

//    double L = 116.0 * Fxyz( y/CIEXYZ[1] ) -16;
//    double A = 500.0 * (Fxyz( x/CIEXYZ[0] ) - Fxyz( y/CIEXYZ[1] ) );
//    double B = 200.0 * (Fxyz( y/CIEXYZ[1] ) - Fxyz( z/CIEXYZ[2]) );

    double ref_X=CIEXYZ[0];double ref_Y=CIEXYZ[1];double ref_Z=CIEXYZ[2];
    double var_X = X / ref_X ;         //ref_X =  95.047   Observer= 2°, Illuminant= D65
    double var_Y = Y / ref_Y ;         //ref_Y = 100.000
    double var_Z = Z / ref_Z ;         //ref_Z = 108.883

    if ( var_X > 0.008856 )
        var_X = pow(var_X , ( 1/3 ));
    else
        var_X = ( 7.787 * var_X ) + ( 16 / 116 );

    if ( var_Y > 0.008856 )
        var_Y = pow(var_Y , ( 1/3 ));
    else
        var_Y = ( 7.787 * var_Y ) + ( 16 / 116 );

    if ( var_Z > 0.008856 )
        var_Z = pow(var_Z , ( 1/3 ));
    else
        var_Z = ( 7.787 * var_Z ) + ( 16 / 116 );

//    CIE-L* = ( 116 * var_Y ) - 16
//    CIE-a* = 500 * ( var_X - var_Y )
//    CIE-b* = 200 * ( var_Y - var_Z )



    lab.L=( 116 * var_Y ) - 16;
    lab.a=500 * ( var_X - var_Y );
    lab.b=200 * ( var_Y - var_Z );
    (*Labpixel) = lab;
}


void CIEXYZ( double x, double y, double z)
{
//    x = (x>0.9505)? 0.9505 : ((x<0)? 0 : x);
//    y = (y>1.0)? 1.0 : ((y<0)? 0 : y);
//    z = (z>1.089)? 1.089 : ((z<0)? 0 : z);

    xyz.x=x;
    xyz.y=y;
    xyz.z=z;

}

 void RGBtoXYZ(Uint8 red, Uint8 green, Uint8 blue)
{
     double r,g,b;

    // normalize red, green, blue values
    double rLinear = (double)red/255.0;
    double gLinear = (double)green/255.0;
    double bLinear = (double)blue/255.0;

    // convert to a sRGB form
//    double r = (rLinear > 0.04045)? pow((rLinear + 0.055)/(1 + 0.055), 2.2) : (rLinear/12.92) ;
//    double g = (gLinear > 0.04045)? pow((gLinear + 0.055)/(1 + 0.055), 2.2) : (gLinear/12.92) ;
//    double b = (bLinear > 0.04045)? pow((bLinear + 0.055)/(1 + 0.055), 2.2) : (bLinear/12.92) ;

    if ( rLinear > 0.04045 )
        rLinear = pow( ( rLinear + 0.055 ) / 1.055 ,2.4);
    else
        rLinear = rLinear / 12.92;

    if ( gLinear > 0.04045 )
        gLinear = pow( ( gLinear + 0.055 ) / 1.055  , 2.4);
    else
        gLinear = gLinear / 12.92;

    if ( bLinear > 0.04045 )
        bLinear = pow( ( bLinear + 0.055 ) / 1.055  , 2.4);
    else
        bLinear = bLinear / 12.92;


//    rLinear *=100; gLinear *=100; bLinear *=100;


    //Observer. = 2°, Illuminant = D65
//    double X = rLinear * 0.4124 + gLinear * 0.3576 + bLinear * 0.1805;
//    double Y = rLinear * 0.2126 + gLinear * 0.7152 + bLinear * 0.0722;
//    double Z = rLinear * 0.0193 + gLinear * 0.1192 + bLinear * 0.9505;
//    printf("%f,%f,%f\n",X,Y,Z);

    // converts CIE to XYZ
    CIEXYZ(
        (rLinear * 0.4124 + gLinear * 0.3576 + bLinear * 0.1805),
        (rLinear * 0.2126 + gLinear * 0.7152 + bLinear * 0.0722),
        (rLinear * 0.0193 + gLinear * 0.1192 + bLinear * 0.9505)
        );






}



/// <summary>
/// Converts CIEXYZ to RGB structure.
/// </summary>
void  XYZtoRGB(Uint32 *destpixel,double x, double y, double z)
{
 double Clinear [3];
 Clinear[0] = x*3.2410 - y*1.5374 - z*0.4986; // red
 Clinear[1] = -x*0.9692 + y*1.8760 - z*0.0416; // green
 Clinear[2] = x*0.0556 - y*0.2040 + z*1.0570; // blue

 for(int i=0; i<3; i++)
 {
     Clinear[i] = (Clinear[i]<=0.0031308)? 12.92*Clinear[i] : (1+0.055)* pow(Clinear[i], (1.0/2.4)) - 0.055;
 }


 double t1=Clinear[0]*255.0;
 double t2=Clinear[1]*255.0;
 double t3=Clinear[2]*255.0;

 t1 = t1 > 255 ? 255 : t1; t2 = t2 > 255 ? 255 : t2; t3 = t3 > 255 ? 255 : t3;
 t1 = t1 < 0 ? 0 : t1; t2 = t2 < 0 ? 0 : t2; t3 = t3 < 0 ? 0 : t3;


 Uint32 tmppixel = SDL_MapRGB(formattedSurface->format, t1, t2, t3);
 (*destpixel)=tmppixel;

// RGB(
//     Convert.ToInt32( Double.Parse(String.Format("{0:0.00}",
//         Clinear[0]*255.0)) ),
//     Convert.ToInt32( Double.Parse(String.Format("{0:0.00}",
//         Clinear[1]*255.0)) ),
//     Convert.ToInt32( Double.Parse(String.Format("{0:0.00}",
//         Clinear[2]*255.0)) )
//     );
}


/// <summary>
/// Converts CIELab to CIEXYZ.
/// </summary>
void LabtoXYZ(double l, double a, double b)
{
 double delta = 6.0/29.0;

 double fy = (l+16)/116.0;
 double fx = fy + (a/500.0);
 double fz = fy - (b/200.0);

 double ciexyz [] = {0.9505, 1.0, 1.0890};


 CIEXYZ(
     (fx > delta)? ciexyz[0] * (fx*fx*fx) : (fx - 16.0/116.0)*3*( delta*delta)*ciexyz[0],
     (fy > delta)? ciexyz[1] * (fy*fy*fy) : (fy - 16.0/116.0)*3*( delta*delta)*ciexyz[1],
     (fz > delta)? ciexyz[2] * (fz*fz*fz) : (fz - 16.0/116.0)*3*( delta*delta)*ciexyz[2]
     );
}



void colortransfer(Uint32 **srcpixels, Uint32 **dstpixels  /*, Uint32 **convertedPixel*/)
{
    // Convert src to Lab color space
    XYZ * xyzArraySRC= new XYZ[ formattedSurfaceSRC->w*formattedSurfaceSRC->h];
    Lab *LabArraySRC = new Lab[ formattedSurfaceSRC->w*formattedSurfaceSRC->h];

    for (int y = 0; y < formattedSurfaceSRC->h; y++)
    {
        for (int x = 0; x < formattedSurfaceSRC->w; x++)
        {
            int tmpIndex = y * formattedSurfaceSRC->w + x;

            Uint8  red=0;
            Uint8  green=0;
            Uint8  blue=0;

            SDL_GetRGB( (*srcpixels)[tmpIndex], formattedSurfaceSRC->format, &red, &green, &blue);


            RGBtoXYZ(red, green, blue);//modify xyz
            xyzArraySRC[tmpIndex]= xyz; //assign it

//            printf("xyzArraySRC[%d]= %d, %d, %d, \n", tmpIndex, xyzArraySRC[tmpIndex].x ,xyzArraySRC[tmpIndex].y, xyzArraySRC[tmpIndex].z);

            double  X=xyz.x;
            double  Y=xyz.y;
            double  Z=xyz.z;
//            SDL_GetRGB(  (*srcpixels)[tmpIndex], formattedSurfaceSRC->format, &X, &Y, &Z);

            XYZtoLab( &(xyzArraySRC[tmpIndex]), &(LabArraySRC[tmpIndex]), X,Y,Z );
        }
    }

    // Convert dest to Lab color space
    XYZ * xyzArrayDest= new XYZ[ formattedSurface->w*formattedSurface->h];
    Lab *LabArrayDest = new Lab[ formattedSurface->w*formattedSurface->h];

    for (int y = 0; y < formattedSurface->h; y++)
    {
        for (int x = 0; x < formattedSurface->w; x++)
        {
            int tmpIndex = y * formattedSurface->w + x;

            Uint8  red=0;
            Uint8  green=0;
            Uint8  blue=0;

            SDL_GetRGB( (*dstpixels)[tmpIndex], formattedSurface->format, &red, &green, &blue);


            RGBtoXYZ(red, green, blue);//modify xyz
            xyzArrayDest[tmpIndex]= xyz; //assign it

            Uint8  X=0;
            Uint8  Y=0;
            Uint8  Z=0;
            SDL_GetRGB(  (*dstpixels)[tmpIndex], formattedSurfaceSRC->format, &X, &Y, &Z);

            XYZtoLab( &(xyzArrayDest[tmpIndex]), &(LabArrayDest[tmpIndex]), X,Y,Z );
        }
    }


    // compute mean of L, a, b  of src and dest image
    double totalLsrc, totalAsrc, totalBsrc;
    double totalLdest, totalAdest, totalBdest;


    for (int y = 0; y < formattedSurface->h; y++)
    {
        for (int x = 0; x < formattedSurface->w; x++)
        {
            int i = y * formattedSurface->w + x;

            totalLsrc+=LabArraySRC[i].L;  totalAsrc+=LabArraySRC[i].a;  totalBsrc+=LabArraySRC[i].b;
            totalLdest+=LabArrayDest[i].L;  totalAdest+=LabArrayDest[i].a;  totalBdest+=LabArrayDest[i].b;
        }
    }

    double meanLsrc = totalLsrc / formattedSurface->w*formattedSurface->h;
    double meanAsrc = totalAsrc / formattedSurface->w*formattedSurface->h;
    double meanBsrc = totalBsrc / formattedSurface->w*formattedSurface->h;
    double meanLdest = totalLdest / formattedSurface->w*formattedSurface->h;
    double meanAdest = totalAdest / formattedSurface->w*formattedSurface->h;
    double meanBdest = totalBdest / formattedSurface->w*formattedSurface->h;

    // compute standard deviation of L, a, b  of src and dest image (find variance and take sqrt of it)

    double sumdiffLsrc=0; double sumdiffAsrc=0; double sumdiffBsrc=0;
    double sumdiffLdest=0; double sumdiffAdest=0; double sumdiffBdest=0;

    for (int y = 0; y < formattedSurface->h; y++)
    {
        for (int x = 0; x < formattedSurface->w; x++)
        {
            int i = y * formattedSurface->w + x;

            sumdiffLsrc+= pow( (LabArraySRC[i].L - meanLsrc) , 2);
            sumdiffAsrc+= pow( (LabArraySRC[i].a - meanAsrc) , 2);
            sumdiffBsrc+= pow( (LabArraySRC[i].b - meanBsrc) , 2);

            sumdiffLdest+= pow( (LabArrayDest[i].L - meanLdest) , 2);
            sumdiffAdest+= pow( (LabArrayDest[i].a - meanAdest) , 2);
            sumdiffBdest+= pow( (LabArrayDest[i].b - meanBdest) , 2);
        }
    }

    double varLsrc = sumdiffLsrc / formattedSurface->w*formattedSurface->h;
    double varAsrc = sumdiffAsrc / formattedSurface->w*formattedSurface->h;
    double varBsrc = sumdiffBsrc / formattedSurface->w*formattedSurface->h;
    double varLdest = sumdiffLdest / formattedSurface->w*formattedSurface->h;
    double varAdest = sumdiffAdest / formattedSurface->w*formattedSurface->h;
    double varBdest = sumdiffBdest / formattedSurface->w*formattedSurface->h;

    // standar deviation
    double sdevLsrc = sqrt(varLsrc);
    double sdevAsrc = sqrt(varAsrc);
    double sdevBsrc = sqrt(varBsrc);
    double sdevLdest = sqrt(varLdest);
    double sdevAdest = sqrt(varAdest);
    double sdevBdest = sqrt(varBdest);

    // subtract the means from the target image
    for (int y = 0; y < formattedSurface->h; y++)
    {
        for (int x = 0; x < formattedSurface->w; x++)
        {
            int i = y * formattedSurface->w + x;
            // subtract the means from the target image

            LabArrayDest[i].L -= meanLdest;
            LabArrayDest[i].a -= meanAdest;
            LabArrayDest[i].b -= meanBdest;

            // scale by the standard deviations

            LabArrayDest[i].L = (sdevLdest/sdevLsrc)*LabArrayDest[i].L ;
            LabArrayDest[i].a = (sdevAdest/sdevAsrc)*LabArrayDest[i].a ;
            LabArrayDest[i].b = (sdevBdest/sdevBsrc)*LabArrayDest[i].b ;

            LabArrayDest[i].L +=meanLsrc;
            LabArrayDest[i].a +=meanAsrc;
            LabArrayDest[i].b +=meanBsrc;


            // clamp to 0-255
            LabArrayDest[i].L = (LabArrayDest[i].L > 255) ? LabArrayDest[i].L = 255 : LabArrayDest[i].L;
            LabArrayDest[i].L = (LabArrayDest[i].L < 0) ? LabArrayDest[i].L = 0 : LabArrayDest[i].L;

            LabArrayDest[i].a = (LabArrayDest[i].a > 255) ? LabArrayDest[i].a = 255 : LabArrayDest[i].a;
            LabArrayDest[i].a = (LabArrayDest[i].a < 0) ? LabArrayDest[i].a = 0 : LabArrayDest[i].a;

            LabArrayDest[i].b = (LabArrayDest[i].b > 255) ? LabArrayDest[i].b = 255 : LabArrayDest[i].b;
            LabArrayDest[i].b = (LabArrayDest[i].b < 0) ? LabArrayDest[i].b = 0 : LabArrayDest[i].b;

            //convert back from Lab to RGB color space

            LabtoXYZ(LabArrayDest[i].L, LabArrayDest[i].a, LabArrayDest[i].b);

            XYZtoRGB( &(*dstpixels)[i] ,xyz.x, xyz.y, xyz.z);

//            SDL_UpdateTexture(texture, NULL, backbufferpixels, 640 * sizeof(Uint32));
//            SDL_RenderCopy(renderer, texture, NULL, NULL);
//            SDL_RenderPresent(renderer);


        }

    }


//    int maxPixelintensity=0;
//    int minPixelintensity=255;
//    for (int y = 0; y < formattedSurface->h; y++)
//    {
//        for (int x = 0; x < formattedSurface->w; x++)
//        {
//            int tmpIndex = y * formattedSurface->w + x;

//            Uint8  red=0;
//            Uint8  green=0;
//            Uint8  blue=0;

//            float factor = (259 * (contrastFactor + 255)) / (255 * (259 - contrastFactor));

//            SDL_GetRGB((*pixels)[tmpIndex], formattedSurface->format, &red, &green, &blue);
//            float r=(float)red;
//            float g=(float)green;
//            float b=(float)blue;

//            float newRed   = clamp((factor * (r)   - 128) + 128);
//            float newGreen = clamp((factor * (g)   - 128) + 128);
//            float newBlue  = clamp((factor * (b)   - 128) + 128);

//            SDL_Color c;
//            c.r=newRed;
//            c.g=newGreen;
//            c.b=newBlue;
//            Uint32 tmpPixel=SDL_MapRGB(formattedSurface->format, c.r, c.g, c.b);
//            (*pixels)[ y * formattedSurface->w + x] = tmpPixel;


//        }
//    }



    delete xyzArraySRC;
    delete LabArraySRC;
    delete xyzArrayDest;
    delete LabArrayDest;
}




int main(int argc, char ** argv)
{

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG);

    window = SDL_CreateWindow("SDL2 Grayscale",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);

    //create a surface and load an image to it

    //create a properly formated surface (with the right pixel format) based on the image surface created before
    image = IMG_Load("antipaxoi.png");

    imageSRCCOLORGRADE = IMG_Load("imageSRCCOLORGRADE.png");


    if (image==NULL)
        printf("Oh My Goodness, an error : %s\n", IMG_GetError());
    formattedSurface = SDL_ConvertSurfaceFormat( image, SDL_PIXELFORMAT_ARGB8888, NULL );

    if (imageSRCCOLORGRADE==NULL)
        printf("Oh My Goodness, an error : %s\n", IMG_GetError());
    formattedSurfaceSRC = SDL_ConvertSurfaceFormat( imageSRCCOLORGRADE, SDL_PIXELFORMAT_ARGB8888, NULL );

    //create the texture based on a formated surface
    texture = SDL_CreateTextureFromSurface(renderer, formattedSurface);

//    texture2 = SDL_CreateTextureFromSurface(renderer, formattedSurfaceSRC);


    std::cout<<"Sharpen-'s', Blur-'b'"<<std::endl;
    std::cout<<"Brighten-'r', Darken-'d'"<<std::endl;
    std::cout<<"Contrast-'c', Un-Contrast-'u'"<<std::endl;
    std::cout<<"Restore Origina Image-'1'"<<std::endl;

    //allocate space for 1 pixel
//    convertedPixel = new Uint32[1];

    while (!quit)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_KEYDOWN:

            //allocate a pixels' buffer , if not already created
            if(pixels ==NULL)
            {
                //create an array of pixels to manipulate, a backbuffer array of pixels to update the pixels array from , and a saved orinal state of the pixels array
                pixels = (Uint32 *) formattedSurface->pixels;

                //save the original image as an array of pixels before any sort of image processing
                if(originalImagepixels ==NULL)
                {
                    originalImagepixels = new Uint32[640*480];
                    memcpy(originalImagepixels, pixels, 640*480 * sizeof(Uint32));
                }

                //NOT CURRENTLY USED
                if(backbufferpixels ==NULL)
                {
                    backbufferpixels = new Uint32[640*480];
                    memcpy(backbufferpixels, pixels, 640*480*sizeof(Uint32));
                }
                //NOT CURRENTLY USED

            }


            if(srcImagePixels ==NULL)
            {
                srcImagePixels = (Uint32 *) formattedSurfaceSRC->pixels;
//                memcpy(backbufferpixels, srcImagePixels, 640*480*sizeof(Uint32));
            }



            if(event.key.keysym.sym==SDLK_ESCAPE)
            {
                quit = true;
            }

            if(event.key.keysym.sym==SDLK_s)
            {
//                memcpy(backbufferpixels, pixels, 640*480*sizeof(Uint32));
                //allow the user sharpen frames by parameters given on the command-line
                sharpen(&backbufferpixels, sharpenCoefficient/*+=0.01*/);


//SET ALL PIXELS TO RED
//                for (int y = 0; y < formattedSurface->h; y++)
//                {
//                    for (int x = 0; x < formattedSurface->w; x++)
//                    {

//                       //get pixel color

//                        Uint8 red, green, blue;
//                        Uint32 pixel = pixels[y * formattedSurface->w + x];

////                        SDL_GetRGB(pixel, formattedSurface->format, &red, &green, &blue);
////                        //std::cout<<"red="<<(int)red<<std::endl;


//                       //set pixel color
//                        SDL_Color c;
//                        c.r=255;
//                        c.g=0;
//                        c.b=0;
//                        //create a
//                        Uint32 tmpPixel=SDL_MapRGB(formattedSurface->format, c.r,c.g,c.b);
//
//                            all the same
////                        pixel = tmpPixel;
////                        pixel = (0xFF << 24) | (red << 16) | (green << 8) | blue;
////                        pixels[y * formattedSurface->w + x] = pixel;



//                    }
//                }
                break;
            }


            if(event.key.keysym.sym==SDLK_b)
            {
//                memcpy(backbufferpixels, pixels, 640*480*sizeof(Uint32));
                //allow the user blur frames by parameters given on the command-line
                blur(&backbufferpixels);
                break;
            }

            if(event.key.keysym.sym==SDLK_r)
            {
                memcpy(backbufferpixels, pixels, 640*480*sizeof(Uint32));
                //allow users to change the brightness
                brighten(&backbufferpixels,brightness++);
                break;
            }
            if(event.key.keysym.sym==SDLK_d)
            {
                memcpy(backbufferpixels, pixels, 640*480*sizeof(Uint32));
                //allow users to change the brightness
                brighten(&backbufferpixels,brightness--);
                break;
            }

            if(event.key.keysym.sym==SDLK_c)
            {
                memcpy(backbufferpixels, pixels, 640*480*sizeof(Uint32));
                //allow users to change the brightness
                contrast(&backbufferpixels,contrastFactor++);
                break;
            }
            if(event.key.keysym.sym==SDLK_u)
            {
                memcpy(backbufferpixels, pixels, 640*480*sizeof(Uint32));
                //allow users to change the brightness
                contrast(&backbufferpixels,contrastFactor--);
                break;
            }


            if(event.key.keysym.sym==SDLK_h)
            {
                memcpy(backbufferpixels, pixels, 640*480*sizeof(Uint32));
                //allow users to find highlights and add glare
                processHighlights(&backbufferpixels);

                break;
            }

            if(event.key.keysym.sym==SDLK_t)
            {
                memcpy(backbufferpixels, pixels, 640*480*sizeof(Uint32));
                //allow users to find highlights and add glare
                colortransfer(&srcImagePixels, &backbufferpixels);

                break;
            }


//            if(event.key.keysym.sym==SDLK_g)
//            {
//                //allow users to change the brightness
//                brighten(brightness);
//                break;
//            }

            //load
            if(event.key.keysym.sym==SDLK_1)
            {
                memcpy(pixels, originalImagepixels, 640*480*sizeof(Uint32));
                memcpy(backbufferpixels, pixels, 640*480*sizeof(Uint32));
                break;
            }

            if (event.key.keysym.sym==SDLK_ESCAPE)
            {
               quit = true;
            }

        case SDL_KEYUP:
            if(event.key.keysym.sym==SDLK_r)
            {
                break;
            }
            if(event.key.keysym.sym==SDLK_d)
            {
                break;
            }
        }

        // Update the given texture rectangle with new updated pixel data.
        SDL_UpdateTexture(texture, NULL, backbufferpixels, 640 * sizeof(Uint32));

        //save out result
//        SDL_UpdateTexture(texture, NULL, pixels, 640 * sizeof(Uint32));

        //texture/or portion of it it to the rendering context-target
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        //Update the screen with rendering performed.
        SDL_RenderPresent(renderer);
    }


//    delete convertedPixel;
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(formattedSurface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    delete pixels;
    delete backbufferpixels;
    delete originalImagepixels;
    IMG_Quit();
    SDL_Quit();

    return 0;
}

























//#include <stdlib.h>
//#include <stdio.h>
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
//#include <math.h>

//int convertNumbers(Uint8);

//int main(int argc, char **argv)
//{
//    //Load both images as a surface
//    SDL_Surface * target = IMG_Load("foo1.png");
//    SDL_Surface * source = IMG_Load("foo.png");

//    int y=0, x=0;
//    Uint8 targetR, targetG, targetB, sourceR, sourceG, sourceB;

//    target = SDL_ConvertSurfaceFormat(target, SDL_PIXELFORMAT_ARGB8888, 0);
//    source = SDL_ConvertSurfaceFormat(source, SDL_PIXELFORMAT_ARGB8888, 0);

//    Uint32 *targetpixels = (Uint32 *)target->pixels;
//    Uint32 *sourcepixels = (Uint32 *)source->pixels;

//    Uint32 targetpixel = targetpixels[y * target-> w + x];
//    Uint32 sourcepixel = sourcepixels[y * source-> w + x];

//    //Get RGB values of the source image and the target image
//    SDL_GetRGB(targetpixels[x+y*target->w],target->format,&targetR,&targetG,&targetB);
//    SDL_GetRGB(sourcepixels[x+y*source->w],source->format,&sourceR,&sourceG,&sourceB);

//    printf("%hhu\n", targetR);

////    if (targetR!=0)
//    {
//        printf("%hhu\n", targetR);
//    }

//    //Convert the RGB values to doubles and make them in the range of 0-1
//    double convertTargetR = convertNumbers(targetR);
//    double convertTargetG = convertNumbers(targetG);
//    double convertTargetB = convertNumbers(targetB);
//    double convertSourceR = convertNumbers(sourceR);
//    double convertSourceG = convertNumbers(sourceG);
//    double convertSourceB = convertNumbers(sourceB);

//    //Print out new values
//    printf("New targetR value: %f\n", convertTargetR);
//    printf("New targetG value: %f\n", convertTargetG);
//    printf("New targetB value: %f\n", convertTargetB);
//    printf("New sourceR value: %f\n", convertSourceR);
//    printf("New sourceG value: %f\n", convertSourceG);
//    printf("New sourceB value: %f\n", convertSourceB);

//    float matA[3][3] = {
//        {0.3811, 0.5783, 0.0402},
//        {0.1967, 0.7244, 0.0782},
//        {0.0241, 0.1288, 0.8444}
//    };

//    float matB[3][3] = {
//        {(1/(sqrt(3))),0,0},
//        {0,(1/(sqrt(6))),0},
//        {0,0,(1/(sqrt(2)))}
//    };

//    float matC[3][3] = {
//        {1,1,1},
//        {1,1,-2},
//        {1,-1,0}
//    };

//    float matD[3][3] = {
//        {1,1,1},
//        {1,1,-1},
//        {1,-2,0}
//    };

//    float matE[3][3] = {
//        {((sqrt(3))/3),0,0},
//        {0,((sqrt(6))/6),0},
//        {0,0,((sqrt(2))/2)}
//    };

//    float matF[3][3] = {
//        {4.4679,-3.5873,0.1193},
//        {-1.2186,2.3809,-0.1624},
//        {0.0497,-0.2439,1.2045}
//    };

//    return 0;
//}

//int convertNumbers(Uint8 pixelColour){
//    double newpixelColour = pixelColour/255.0;
//    printf("Converted pixel colour: %f\n", newpixelColour);
//    return newpixelColour;
//}
