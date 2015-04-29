#pragma once

#include "config.h"

#include "ofMain.h"
#include "ofGraphics.h"

#include "ofxAssimpModelLoader.h"
#include "ofVboMesh.h"

#ifdef WITH_KINECT
#include "ofxOpenCv.h"
#include "kinectManager.h"
#endif

#ifdef WITH_SYPHON
#include "ofxSyphon.h"
#endif

#ifndef True
#define True true
#endif

#ifndef False
#define False false
#endif

class quad: public ofNode
{

public:
    quad()
    {
    }

    ofPoint corners[4];
    ofPoint center;

    ofPoint src[4];
    ofPoint dst[4];
    float crop[4];
    float circularCrop[3];
    //lets make a matrix for openGL
    //this will be the matrix that peforms the transformation
    GLfloat matrix[16];
    ofTrueTypeFont ttf;

    // img and video stuff
    ofImage img;
    ofImage slide;
    ofVideoPlayer video;
    int videoWidth;
    int videoHeight;

    int borderColor;
    ofFloatColor bgColor;
    ofFloatColor secondColor;
    ofFloatColor startColor;
    ofFloatColor endColor;
    ofFloatColor transColor;
    ofFloatColor imgColorize;
    ofFloatColor imgBgColorize;
    ofFloatColor videoColorize;
    ofFloatColor camColorize;
    ofFloatColor colorGreenscreen;
    ofFloatColor kinectColorize;
    ofFloatColor timelineColor;
    ofFloatColor brickColor;
    ofFloatColor mortarColor;
    ofFloatColor animationCol;



    float timelineRed;
    float timelineGreen;
    float timelineBlu;
    float timelineAlpha;

    bool bTimelineColor;
    bool bTimelineTint;
    bool bTimelineAlpha;
    bool bTimelineSlideChange;

    int bgAlpha;

    //3dmodel
    ofxAssimpModelLoader model;
    bool bAnimate;
    bool bAnimateMouse;
    float animationPosition;
    float animationRotation;
    float animaScalex;
    float animaScaley;
    float animaScalez;
    float animaRotateX;
    float animaRotateY;
    float animaRotateZ;
    float animaMovex;
    float animaMovey;
    float animaMovez;
    int textureModes;



    ofMesh mesh;
    ofLight	light;

    // camera stuff
    bool camAvailable;

    int camWidth;
    int camHeight;

    int camNumber;
    int prevCamNumber;

    int layer;

    float camMultX;
    float camMultY;
    float imgMultX;
    float imgMultY;
    float kinectMultX;
    float kinectMultY;
    float videoMultX;
    float videoMultY;
    float videoSpeed;
    float sVideoMultX;
    float sVideoMultY;
    float sVideoSpeed;
    float previousSpeed;
    float slideshowSpeed;
    float transDuration;
    float edgeBlendExponent;
    float edgeBlendAmountSin;
    float edgeBlendAmountDx;
    float edgeBlendAmountTop;
    float edgeBlendAmountBottom;
    float edgeBlendGamma;
    float edgeBlendLuminance;
    int quadNumber;

    bool initialized;
    bool isActive;
    bool isSetup;
    bool isOn;
    bool isMaskSetup;
    bool colorBg;
    bool transBg;
    bool transUp;
    bool camBg;
    bool camGreenscreen;
    bool camFit;
    bool camKeepAspect;
    bool videoFit;
    bool videoKeepAspect;
    bool sVideoFit;
    bool sVideoKeepAspect;
    bool imgBg;
    bool imgBgGreenscreen;
    bool videoBg;
    bool videoSound;
    bool videoLoop;
    bool videoGreenscreen;
    bool animaBg;
    bool animaFull;
    bool animaWire;
    bool animaDots;
    bool sVideoSound;
    bool sVideoLoop;
    bool sVideoGreenscreen;
    bool sharedVideoBg;
    int sharedVideoNum;
    int sharedVideoId;
    bool slideshowBg;
    bool slideFit;
    bool slideKeepAspect;
    bool kinectBg;
    bool kinectImg;
    bool kinectMask;
    int nearDepthTh;
    int farDepthTh;
    int kinectBlur;
    float kinectContourMin;
    float kinectContourMax;
    float kinectContourSimplify;
    int kinectContourSmooth;
    bool getKinectContours;
    bool getKinectGrayImage;
    bool kinectContourCurved;
    bool videoBrick;
    bool camBrick;
    bool imgGreenscreen;

    bool videoHFlip;
    bool imgHFlip;
    bool camHFlip;
    bool videoVFlip;
    bool sVideoHFlip;
    bool imgVFlip;
    bool camVFlip;
    bool sVideoVFlip;
    bool edgeBlendBool;

    bool bBlendModes;
    int blendMode;

    bool bMask;
    bool maskInvert;
    int maskMode;

    bool bHighlightCorner;
    int highlightedCorner;

    bool bHighlightCenter;
    bool bHighlightRotation;

    int videoVolume;
    float thresholdGreenscreen;
    int bgSlideshow;
    unsigned int currentSlide;
    int transStep;
    int transCounter;
    int fps;
    int slideFramesDuration;
    int slideTimer;

    vector<string> videos;
    //vector<string> slideshows;
    vector<string> slidesnames;
    vector<ofImage> slides;
    vector<ofVideoGrabber> cams;
    vector<ofVideoPlayer> vids;
    vector<ofxAssimpModelLoader> mods;
    vector<ofURLFileLoader> urls;

    string bgImg;
    string bgVideo;
    string bgAnima;
    string bgUrl;
    string loadedImg;
    string loadedVideo;
    string loadedUrl;
    string loadedAnima;
    string loadedSlideshow;
    string slideshowName;

    ofShader * shaderBlend;
    ofShader * noise;
    ofFbo   quadFbo;
    ofFbo::Settings settings;

    ofShader * maskShader;
    ofFbo maskFbo;
    ofFbo::Settings maskFboSettings;

    ofURLFileLoader url;

    #ifdef WITH_KINECT
    kinectManager * quadKinect;
    ofxCvGrayscaleImage kinectThreshImage;
    ofxCvGrayscaleImage kinectContourImage;
    ofxCvContourFinder kinectContourFinder;
    ofPath kinectPath;
    #endif

    #ifdef WITH_SYPHON
    ofxSyphonClient * syphClientTex;
    bool bSyphon;
    float syphonPosX;
	float syphonPosY;
	float syphonScaleX;
    float syphonScaleY;
    #endif

    ofFbo targetFbo;

    int quadDispX;
    int quadDispY;
    int quadW;
    int quadH;

    ofShader * greenscreenShader;
    //ofShader * brickwallShader;

    // a func for reading a dir content to a vector of strings
    int getdir (string dir, vector<string> &files);

    #ifdef WITH_KINECT
        #ifdef WITH_SYPHON
        void setup(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, ofShader &edgeBlendShader, ofShader &quadMaskShader, ofShader &chromaShader, vector<ofVideoGrabber> &cameras, vector<ofxAssimpModelLoader> &models, vector<ofVideoPlayer> &sharedVideos, kinectManager &kinect, ofxSyphonClient &syphon);
        #else
        void setup(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, ofShader &edgeBlendShader, ofShader &quadMaskShader, ofShader &chromaShader, vector<ofVideoGrabber> &cameras, vector<ofxAssimpModelLoader> &models, vector<ofVideoPlayer> &sharedVideos, kinectManager &kinect);
        #endif
    #else
        #ifdef WITH_SYPHON
        void setup(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, ofShader &edgeBlendShader, ofShader &quadMaskShader, ofShader &chromaShader, vector<ofVideoGrabber> &cameras, vector<ofxAssimpModelLoader> &models, vector<ofVideoPlayer> &sharedVideos, ofxSyphonClient &syphon);
        #else
        void setup(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, ofShader &edgeBlendShader, ofShader &quadMaskShader, ofShader &chromaShader, vector<ofVideoGrabber> &cameras, vector<ofxAssimpModelLoader> &models, vector<ofVideoPlayer> &sharedVideos);
        #endif
    #endif


    void update();

    void draw();

    void gaussian_elimination(float *input, int n);
    void findHomography(ofPoint src[4], ofPoint dst[4], float homography[16]);
    ofMatrix4x4 findVectorHomography(ofPoint src[4], ofPoint dst[4]);
    ofPoint findWarpedPoint(ofPoint src[4], ofPoint dst[4], ofPoint point);

    void loadImageFromFile(string imgName, string imgPath);

    void loadVideoFromFile(string videoName, string videoPath);

    void loadAnimaFromFile(string modelName, string modelPath);

    void allocateFbo(int w, int h);

    void maskAddPoint(int x, int y);
    void drawMaskMarkers();

    vector<ofPoint> maskPoints;
    ofVec3f getWarpedPoint(int x, int y);
    bool bHighlightMaskPoint;
    int highlightedMaskPoint;

    bool bDeform;

    bool isBezierSetup;
    bool bHighlightCtrlPoint;
    int highlightedCtrlPointRow;
    int highlightedCtrlPointCol;
    float bezierPoints[4][4][3];
    bool bBezier;
    float bezierCtrlPoints[4][4][3];

    bool bGrid;
    vector<vector<vector<float> > > gridPoints;
    //vector<GLfloat> gridCtrlPoints;
    int gridRows;
    int gridColumns;
    void gridSurfaceSetup();
    void gridSurfaceUpdate();
    void drawGridMarkers();

    ofMesh gridMesh;

    void bezierSurfaceSetup();
    void bezierSurfaceUpdate();
    void drawBezierMarkers();

    void setupCamera();


};

