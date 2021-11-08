
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>

//#define SCREEN_WIDTH 640
//#define SCREEN_HEIGHT 480
#define SCREEN_WIDTH 740
#define SCREEN_HEIGHT 580


//void drawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides);
void drawSemiCircle(GLfloat x, GLfloat y, GLfloat radius, GLint numberOfSides);
void drawCircle(GLfloat x, GLfloat y, GLfloat radius, GLint numberOfSides);
void drawCircleFill(float cx, float cy, float r, int num_segments);


int main(void)
{
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
    {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode(GL_PROJECTION); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity(); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1); // essentially set coordinate system
    glMatrixMode(GL_MODELVIEW); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity(); // same as above comment

    GLfloat lineVertices[] =
    {
        210,250,0,
        210,400,0,
        170,400,0,
        170,450,0,
        480,450,0,
        480,400,0,
        440,400,0,
        440,250,0

    };
    GLfloat windowL[] =
    {
        230,320,0,
        230,370,0,
        280,370,0,
        280,320,0
    };

    GLfloat windowLHL[] =
    {
        230,345,0,
        280,345,0,
        
    };
    GLfloat windowLVL[] =
    {
        255,320,0,
        255,370,0,

    };

    GLfloat door[] =
    {
        300,250,0,
        300,370,0,
        350,370,0,
        350,250,0
    };

    //gl point 
    
    GLfloat pointVertex1[] = 
    { 
        340,300
    };


    GLfloat windowR[] =
    {
        370,320,0,
        370,370,0,
        420,370,0,
        420,320,0
    };
    GLfloat windowRHL[] =
    {
        370,345,0,
        420,345,0,

    };
    GLfloat windowRVL[] =
    {
        395,320,0,
        395,370,0,

    };
    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

      // Render OpenGL here house outline
            
        glEnableClientState(GL_VERTEX_ARRAY);           
        glVertexPointer(3, GL_FLOAT, 0, lineVertices);        
        glDrawArrays(GL_POLYGON, 0, 8); // Number of points in polygon
       glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glColor3f(0.5, 0.5, 0.2);//yellow
        glDisableClientState(GL_VERTEX_ARRAY);

        // Render OpenGL here   left window      
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, windowL);
        glDrawArrays(GL_POLYGON, 0, 4); // Number of points in polygon
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glColor3f(0.5, 0.5, 0.2);//yellow
        glDisableClientState(GL_VERTEX_ARRAY);

        // Render OpenGL here   windowLHL  
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, windowLHL);
        glDrawArrays(GL_LINES, 0, 2); // Number of points in polygon
       // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glColor3f(0.5, 0.5, 0.2);//yellow
        glDisableClientState(GL_VERTEX_ARRAY);

        // Render OpenGL here   windowLVL  
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, windowLVL);
        glDrawArrays(GL_LINES, 0, 2); // Number of points in polygon
       // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glColor3f(0.5, 0.5, 0.2);//yellow
        glDisableClientState(GL_VERTEX_ARRAY);

        // Render OpenGL here door   
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, door);
        glDrawArrays(GL_POLYGON, 0, 4); // Number of points in polygon
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glColor3f(0.5, 0.5, 0.2);//yellow
        glDisableClientState(GL_VERTEX_ARRAY);

        // Render OpenGL here door knob
        glEnable(GL_POINT_SMOOTH); // make the point circular
        glEnableClientState(GL_VERTEX_ARRAY); // tell OpenGL that you're using a vertex array for fixed-function attribute
        glPointSize(10); // must be added before glDrawArrays is called
        glVertexPointer(2, GL_FLOAT, 0, pointVertex1); // point to the vertices to be used
        glDrawArrays(GL_POINTS, 0, 1); // draw the vertixes
        glDisableClientState(GL_VERTEX_ARRAY); // tell OpenGL that you're finished using the vertex arrayattribute
        glDisable(GL_POINT_SMOOTH); // stop the smoothing to make the points circular

        // Render OpenGL here right window   
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, windowR);
        glDrawArrays(GL_POLYGON, 0, 4); // Number of points in polygon
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glColor3f(0.5, 0.5, 0.2);//yellow
        glDisableClientState(GL_VERTEX_ARRAY);

        // Render OpenGL here   windowRHL  
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, windowRHL);
        glDrawArrays(GL_LINES, 0, 2); // Number of points in polygon
       // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glColor3f(0.5, 0.5, 0.2);//yellow
        glDisableClientState(GL_VERTEX_ARRAY);

        // Render OpenGL here   windowRVL  
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, windowRVL);
        glDrawArrays(GL_LINES, 0, 2); // Number of points in polygon
       // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glColor3f(0.5, 0.5, 0.2);//yellow
        glDisableClientState(GL_VERTEX_ARRAY);


       

         // render OpenGL here semicircle
        //drawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 120, 36);
        // 
        // render OpenGL here  dome
        glColor3f(0.5, 0.5, 0.2);//yellow       
        drawSemiCircle(325, 450, 100, 100);//x axis, y axis, size

        //render crescent
        glLineWidth(5);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(5);
       // drawCircle(500, 400, 40, 360); // movement on x axis, movement on y axis , radius, sides
        drawCircle(530, 530, 40, 360);
        drawCircleFill(555, 540, 40, 360);
        //glColor3f(1.0, 1.0, 0.0);//red       
        glLineWidth(5);
       // drawCircleFill(500, 400, 40, 360); // movement on x axis, movement on y axis , radius, sides 
        drawCircle(530, 530, 40, 360);
        drawCircleFill(555, 540, 40, 360);
       // glColor3f(1.0, 1.0, 0.0);//red
        glLineWidth(5);
        //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        //glColor3f(1.0f, 0.0f, 0.0f); //black
        glColor3f(1.0, 1.0, 0.0);//red
       // glColor3f(0.3, 0.3, 0.3);
       // glColor3f(0.5, 0.5, 0.2);//yellow
        //drawCircleFill(525, 410, 40, 360); // movement on x axis, movement on y axis , radius, sides 
       // drawCircleFill(555, 540, 40, 360);
        
       glColor3f(0.5, 0.5, 0.2);//yellow
       
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        
       // glColor3f(0.3, 0.3, 0.3);
        //glColor3f(1.0f, 0.0f, 0.0f); //black
       // glColor3f(0.5, 0.5, 0.2);//yellow
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(1); 
       
        
        
        
      
        


        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}

/*
void drawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides)
{
   
    GLint numberOfVertices = numberOfSides + 1;

    GLfloat doublePi = 2.0f * M_PI;

    GLfloat circleVerticesX[numberOfVertices];
    GLfloat circleVerticesY[numberOfVertices];
    GLfloat circleVerticesZ[numberOfVertices];

    //circleVerticesX[0] = x;
    //circleVerticesY[0] = y;
    //circleVerticesZ[0] = z;

    for (int i = 0; i < numberOfVertices; i++)
    {
        circleVerticesX[i] = x + (radius * cos(i * doublePi / numberOfSides));
        circleVerticesY[i] = y + (radius * sin(i * doublePi / numberOfSides));
        circleVerticesZ[i] = z;
    }

    GLfloat allCircleVertices[numberOfVertices * 3];

    for (int i = 0; i < numberOfVertices; i++)
    {
        allCircleVertices[i * 3] = circleVerticesX[i];
        allCircleVertices[(i * 3) + 1] = circleVerticesY[i];
        allCircleVertices[(i * 3) + 2] = circleVerticesZ[i];
    }

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, allCircleVertices);
    glDrawArrays(GL_LINE_STRIP, 0, numberOfVertices);
    glDisableClientState(GL_VERTEX_ARRAY);
}
*/
void drawSemiCircle(float cx, float cy, float r, int num_segments)
{
    float theta = 3.1415926 / float(num_segments);
    float tangetial_factor = tanf(theta);//calculate the tangential factor 

    float radial_factor = cosf(theta);//calculate the radial factor 

    float x = r;//we start at angle = 0 

    float y = 0;

    glBegin(GL_LINE_LOOP);
    for (int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);//output vertex 

        //calculate the tangential vector 
        //remember, the radial vector is (x, y) 
        //to get the tangential vector we flip those coordinates and negate one of them 

        float tx = -y;
        float ty = x;

        //add the tangential vector 

        x += tx * tangetial_factor;
        y += ty * tangetial_factor;

        //correct using the radial factor 

        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}

void drawCircle(float cx, float cy, float r, int num_segments)
{
    float theta = 3.1415926 * 2 / float(num_segments);
    float tangetial_factor = tanf(theta);//calculate the tangential factor 

    float radial_factor = cosf(theta);//calculate the radial factor 

    float x = r;//we start at angle = 0 

    float y = 0;
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    for (int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);//output vertex 

        //calculate the tangential vector 
        //remember, the radial vector is (x, y) 
        //to get the tangential vector we flip those coordinates and negate one of them 

        float tx = -y;
        float ty = x;

        //add the tangential vector 

        x += tx * tangetial_factor;
        y += ty * tangetial_factor;

        //correct using the radial factor 

        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}
void drawCircleFill(float cx, float cy, float r, int num_segments)
{
    float theta = 3.1415926 * 2 / float(num_segments);
    float tangetial_factor = tanf(theta);//calculate the tangential factor 
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    float radial_factor = cosf(theta);//calculate the radial factor 

    float x = r;//we start at angle = 0 

    float y = 0;

    //glClear(GL_COLOR_BUFFER_BIT);


    glBegin(GL_POLYGON);
    for (int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);//output vertex 

        //calculate the tangential vector 
        //remember, the radial vector is (x, y) 
        //to get the tangential vector we flip those coordinates and negate one of them 

        float tx = -y;
        float ty = x;

        //add the tangential vector 

        x += tx * tangetial_factor;
        y += ty * tangetial_factor;

        //correct using the radial factor 

        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}
