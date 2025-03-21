#include <glad/glad.h>
#include <SDL2/SDL.h>

//Std library
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

//Globals
int SCREEN_HEIGHT = 480;
int SCREEN_WIDTH = 640;
SDL_Window* gGraphicsAppWindow = nullptr;
SDL_GLContext gOpenGLContext = nullptr;
bool quit = false;

//Get Opengl version info
void printGLInfo(){
    cout << "Vendor: " << glGetString(GL_VENDOR) << endl;
    cout << "Renderer: " << glGetString(GL_RENDERER) << endl;
    cout << "Version: " << glGetString(GL_VERSION) << endl;
    cout << "Shading Language Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    cout << "--------------------------------------------------------------\n";
}

/// @brief Important functions for main fn
void InitializeProgram();
void Input();
void PreDraw();
void Draw();
void MainLoop();
void CleanUp();
string readShaderFile(string filePath);


//Shader code
string s1 = readShaderFile("../shader.vert");
string s2 = readShaderFile("../shader.frag");


const char *vertexShaderSource = s1.c_str();
const char *fragmentShaderSource = s2.c_str();

int main(){

    InitializeProgram();
    MainLoop();
    CleanUp();

    

    return 0;
    
}


void InitializeProgram(){
    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std:: cout << "Could not Initialize SDL2 Video \n";
        exit(1);
    }

    gGraphicsAppWindow = SDL_CreateWindow("Opengl Window", 0, 0, SCREEN_WIDTH,SCREEN_HEIGHT, SDL_WINDOW_OPENGL);

    if(gGraphicsAppWindow == nullptr){
        std::cout << "SDL Window was not created /n";
        exit(1);
    }

    //We want to set attributes of our Opengl context
    // These are versions etc.
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    gOpenGLContext = SDL_GL_CreateContext(gGraphicsAppWindow);

    if(gOpenGLContext == nullptr){
        std::cout << "OpenGL context not available/n";
        exit(1);
    }

    // Load OpenGL functions using GLAD
    // Glad must be loaded before we can use opengl functions
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        std::cerr << "Failed to initialize GLAD!" << std::endl;
        exit(1);
    }

    //print gl info for debugging.
    printGLInfo();
}

void Input(){
    SDL_Event e;
    while(SDL_PollEvent(&e) != 0){
        if(e.type == SDL_QUIT){
            std::cout << "Goodbye!!" << std::endl;
            quit = true;
        }
    }
}

void MainLoop(){

    // build and compile our shader program
    // ------------------------------------
    // vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top   
    }; 

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);


    while(!quit){
        Input();

        PreDraw();

        Draw();

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // glBindVertexArray(0); // no need to unbind it every time 

        //Update Screen
        SDL_GL_SwapWindow(gGraphicsAppWindow);
    }
}


void CleanUp(){
    SDL_DestroyWindow(gGraphicsAppWindow);
    SDL_Quit();
}

void PreDraw(){}
void Draw(){}

string readShaderFile(string filePath){

    string shaderCode;
    std::ifstream myfile;

    // ensure ifstream objects can throw exceptions:
    myfile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try {
        // open file
        myfile.open(filePath);
        stringstream shaderStream;
        // read file's buffer contents into streams
        shaderStream << myfile.rdbuf();
        // close file handlers
        myfile.close();
        // convert stream into string
        shaderCode   = shaderStream.str();	
    }
    catch(std::ifstream::failure e){
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }

    return shaderCode;
}




