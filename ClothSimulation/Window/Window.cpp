//
//  Window.cpp
//  ClothSimulation
//
//  Created by Eric Knapik on 1/9/16.
//  Copyright © 2016 EKnapik. All rights reserved.
//

#include "Window.hpp"

Window::Window(void) {
    setVertexData();
    setupOpenGLCalls();
}

void Window::renderToWindow(void) {
    glUseProgram(shaderProgram);
    glBindBuffer(GL_ARRAY_BUFFER, vBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eBuffer);
    
    // pass the vertex data info
    int step = 0;
    glEnableVertexAttribArray(vertPos);
    glVertexAttribPointer(vertPos, 3, GL_FLOAT, GL_FALSE, step, 0);
    
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
}


void Window::setupOpenGLCalls(void) {
    int dataSize = numVerts * 3 * sizeof(GLfloat);
    
    // Initialize the vertex and element buffer for later drawing
    glGenBuffers(1, &vBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vBuffer);
    glBufferData(GL_ARRAY_BUFFER, dataSize, vertexData, GL_STATIC_DRAW);
    
    glGenBuffers(1, &eBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6*sizeof(GLushort), elementData, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
    // Create shader program and find variable locations in shader program
    shaderProgram = shaderSetup("simpleCloth.vert", "simpleCloth.frag");
    if( !shaderProgram ) {
        perror("ERROR SETTING UP SHADERS!!!!\n");
        _exit(1);
    }
    
    vertPos = glGetAttribLocation(shaderProgram, "currVert");
}


void Window::setVertexData(void) {
    // define the 4 points of square in counter clockwise order
    //			     x,   y,   z,
    vertexData[0] = -1.0;
    vertexData[1] = 1.0;
    vertexData[2] = 0.0;
    
    vertexData[5] = -1.0;
    vertexData[6] = -1.0;
    vertexData[7] = 0.0;
    
    vertexData[10] = 1.0;
    vertexData[11] = -1.0;
    vertexData[12] = 0.0;

    vertexData[15] = 1.0;
    vertexData[16] = 1.0;
    vertexData[17] = 0.0;

    
    numVerts = 4;
    elementData[0] = 0;
    elementData[1] = 1;
    elementData[2] = 2;
    elementData[3] = 3;
    elementData[4] = 0;
    elementData[5] = 2;
}