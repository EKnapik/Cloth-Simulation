//
//  main.cpp
//  ClothSimulation
//
//  Created by Eric Knapik on 1/9/16.
//  Copyright © 2016 EKnapik. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h>
#include <OpenGL/gl.h>

#define WINDOW_HEIGHT 512
#define WINDOW_WIDTH 512
void initOpenGL(void);
void display(void);

int main(int argc, char * argv[]) {
    
    // Setup window statically because GLUT is poor at window and display render
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_HEIGHT, WINDOW_WIDTH);
    glutCreateWindow("Simple Ray Tracer");
    glutDisplayFunc(display);
    
    initOpenGL();
    
    
    glutMainLoop();
    return 0;
}


void initOpenGL(void) {
    glEnable(GL_DEPTH_TEST | GL_CULL_FACE | GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor( 0.0, 0.0, 0.0, 1.0 );
    glCullFace(GL_FRONT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    return;
}


void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // poll events
    // bind and draw
    
    glutSwapBuffers();
    glutPostRedisplay();
}
