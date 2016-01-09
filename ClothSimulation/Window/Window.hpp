//
//  Window.hpp
//  ClothSimulation
//
//  Created by Eric Knapik on 1/9/16.
//  Copyright © 2016 EKnapik. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include <stdio.h>
#include <OpenGL/gl.h>


class Window {
public:
    Window(void);
    void renderToWindow(void);
private:
    void setupOpenGLCalls(void);
    void setVertexData(void);
    
    GLuint shaderProgram;
    GLuint vBuffer, eBuffer;
    GLuint vertPos;
    GLuint numVerts;
    GLfloat vertexData[20];
    GLushort elementData[6];
};
#endif /* Window_hpp */
