
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
        glColor3f(1.0f, 1.0f, 1.0f); //white
        glDisableClientState(GL_VERTEX_ARRAY);

        // Render OpenGL here   left window      
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, windowL);
        glDrawArrays(GL_POLYGON, 0, 4); // Number of points in polygon             
        glColor3f(1.0f, 1.0f, 1.0f); //white
        glDisableClientState(GL_VERTEX_ARRAY);

        // Render OpenGL here   windowLHL  
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, windowLHL);
        glDrawArrays(GL_LINES, 0, 2); // Number of points in polygon       
        glColor3f(1.0f, 1.0f, 1.0f); //white
        glDisableClientState(GL_VERTEX_ARRAY);

        // Render OpenGL here   windowLVL  
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, windowLVL);
        glDrawArrays(GL_LINES, 0, 2); // Number of points in polygon      
        glColor3f(1.0f, 1.0f, 1.0f); //white
        glDisableClientState(GL_VERTEX_ARRAY);

        // Render OpenGL here door         
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, door);
        glDrawArrays(GL_POLYGON, 0, 4); // Number of points in polygon        
        glColor3f(1.0f, 1.0f, 1.0f); //white
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
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, windowR);
        glDrawArrays(GL_POLYGON, 0, 4); // Number of points in polygon       
        glColor3f(1.0f, 1.0f, 1.0f); //white
        glDisableClientState(GL_VERTEX_ARRAY);

        // Render OpenGL here   windowRHL  
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, windowRHL);
        glDrawArrays(GL_LINES, 0, 2); // Number of points in polygon       
        glColor3f(1.0f, 1.0f, 1.0f); //white
        glDisableClientState(GL_VERTEX_ARRAY);

        // Render OpenGL here   windowRVL  
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, windowRVL);
        glDrawArrays(GL_LINES, 0, 2); // Number of points in polygon      
        glColor3f(1.0f, 1.0f, 1.0f); //white
        glDisableClientState(GL_VERTEX_ARRAY);


        // render OpenGL here  dome       
        glColor3f(1.0f, 1.0f, 1.0f); //white
        drawSemiCircle(325, 450, 100, 100);//x axis, y axis, size

        //render crescent
        glEnableClientState(GL_VERTEX_ARRAY);
        glLineWidth(5);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(5);
        drawCircle(530, 530, 40, 360); // movement on x axis, movement on y axis , radius, sides       
        glLineWidth(5);
        drawCircleFill(530, 530, 40, 360); // movement on x axis, movement on y axis , radius, sides 
        glLineWidth(5);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);       
       glColor3f(0.0f, 0.0f, 0.0f); //black
       drawCircleFill(555, 540, 40, 360); // movement on x axis, movement on y axis , radius, sides        
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); 
        glDisableClientState(GL_VERTEX_ARRAY);

       

        // Swap front and back buffers
        glfwSwapBuffers(window);      
        glColor3f(1.0f, 1.0f, 1.0f); //white
       // glColor3f(0.5, 0.5, 0.2);//yellow
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(1);
        // Poll for and process events
        glfwPollEvents();
        
        
       
    }

    glfwTerminate();

    return 0;
}


void drawSemiCircle(float cx, float cy, float r, int num_segments)
{
    float theta = 3.1415926 / float(num_segments);
    float tan = tanf(theta);//calculate the tangent 
    float radius = cosf(theta);//calculate the radius
    float x = r;//we start at angle = 0 
    float y = 0;

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++)
    {
        glVertex2f(x + cx, y + cy);//output vertex 

       
        float tx = -y;
        float ty = x;

        //add the tangent vector 
        x += tx * tan;
        y += ty * tan;
        
        x *= radius;
        y *= radius;
    }
    glEnd();
}

void drawCircle(float cx, float cy, float r, int num_segments)
{
    float theta = 3.1415926 * 2 / float(num_segments);
    float tan = tanf(theta);//calculate the tangent 

    float radius = cosf(theta);//calculate the radius 
    float x = r;//we start at angle = 0 

    float y = 0;
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++)
    {
        glVertex2f(x + cx, y + cy);//output vertex 

       
        float tx = -y;
        float ty = x;

        //add the tangent vector

        x += tx * tan;
        y += ty * tan;
               

        x *= radius;
        y *= radius;
    }
    glEnd();
}
void drawCircleFill(float cx, float cy, float r, int num_segments)
{
    float theta = 3.1415926 * 2 / float(num_segments);
    float tan = tanf(theta);//calculate the tangent 
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    float radius = cosf(theta);//calculate the radius

    float x = r;//we start at angle = 0 

    float y = 0;

    //glClear(GL_COLOR_BUFFER_BIT);


    glBegin(GL_POLYGON);
    for (int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);//output vertex         
        //to get the tangent vector we flip those coordinates and negate one of them 
        float tx = -y;
        float ty = x;

        //add the tangent vector 
        x += tx * tan;
        y += ty * tan;       

        x *= radius;
        y *= radius;
    }
    glEnd();
}
