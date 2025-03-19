#include <glad/glad.h>
#include <SDL2/SDL.h>

#include <iostream>

//Globals
int SCREEN_HEIGHT = 480;
int SCREEN_WIDTH = 640;
SDL_Window* gGraphicsAppWindow = nullptr;
SDL_GLContext gOpenGLContext = nullptr;
bool quit = false;


//Get Opengl version info
void printGLInfo(){
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "Shading Language Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
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

void PreDraw(){

}

void Draw(){

}





void MainLoop(){
    while(!quit){
        Input();

        PreDraw();

        Draw();

        //Update Screen
        SDL_GL_SwapWindow(gGraphicsAppWindow);
    }

}
void CleanUp(){

    SDL_DestroyWindow(gGraphicsAppWindow);
    SDL_Quit();

}




int main()
{
    InitializeProgram();
    MainLoop();
    CleanUp();

    return 0; 
}



