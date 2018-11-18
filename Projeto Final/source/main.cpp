#include "funcoes.h"

void drawText
(SDL_Surface* tela, char* string,
int size, int x, int y,
int fR, int fG, int fB) {
TTF_Font* font = TTF_OpenFont("arial.ttf", size);

SDL_Color foregroundColor = { fR, fG, fB };
SDL_Color backgroundColor = { 126, 126, 126 };

SDL_Surface* textSurface = TTF_RenderText_Shaded(font, string, foregroundColor, backgroundColor);

SDL_Rect textLocation = { x, y, 0, 0 };

SDL_BlitSurface(textSurface, NULL, tela, &textLocation);

SDL_FreeSurface(textSurface);

TTF_CloseFont(font);

}


int main(int argc, char* args[]) {
    printf("Rodando programa...\n");
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Surface *tela;

    TTF_Init();
    /*CRIANDO JANELA*/

    // memoria
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // nome janela
    SDL_WM_SetCaption("Meu primeiro jogo SDL", NULL);

    // tamanho janela
    tela = SDL_SetVideoMode(RX, RY, 32, SDL_OPENGL);

    // cor
    glClearColor(1, 1, 1, 1);

    // area exibida
    glViewport(0, 0, RX, RY);

    // sombra
    glShadeModel(GL_SMOOTH);

    // 2D
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();  // desenho geometrico

    // 3D
    glDisable(GL_DEPTH_TEST);

    // para uso da imagem
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    /*FIM DA CRIAÇÃO*/

    bool executando = true;

    SDL_Event eventos;

    // pegar textura
    unsigned int textura_grade;
    unsigned int textura_fundo;
    unsigned int textura_base;

    unsigned int humano_GER_REC;
    unsigned int humano_GER_TROP;
    unsigned int humano_DEF_OFS;
    unsigned int humano_DEF_PAS;
    unsigned int mecanico_GER_REC;
    unsigned int mecanico_GER_TROP;
    unsigned int mecanico_DEF_OFS;
    unsigned int mecanico_DEF_PAS;
    unsigned int eletrico_GER_REC;
    unsigned int eletrico_GER_TROP;
    unsigned int eletrico_DEF_OFS;
    unsigned int eletrico_DEF_PAS;

    unsigned int textura_minerio;
    unsigned int textura_raio;
    unsigned int textura_comida;
    imagens_data imagens;

    if (verifica_imagem("imagens/grade.png") == false ||
        verifica_imagem("imagens/sand.png") == false ||
        verifica_imagem("imagens/base.png") == false ||
        verifica_imagem("imagens/Akeno.png") == false ||
        verifica_imagem("imagens/albedo.png") == false ||
        verifica_imagem("imagens/chitoge2.png") == false ||
        verifica_imagem("imagens/Dva.png") == false ||
        verifica_imagem("imagens/Eliza.png") == false ||
        verifica_imagem("imagens/Emilia.png") == false ||
        verifica_imagem("imagens/Hatsune.png") == false ||
        verifica_imagem("imagens/Lucy.png") == false ||
        verifica_imagem("imagens/megumin.png") == false ||
        verifica_imagem("imagens/Rias.png") == false ||
        verifica_imagem("imagens/Lucy4.png") == false ||
        verifica_imagem("imagens/Rias2.png") == false ||
        verifica_imagem("imagens/minerio.png") == false ||
        verifica_imagem("imagens/raio.png") == false ||
        verifica_imagem("imagens/comida.png") == false
        ) {

        printf("FALHA AO CARREGAR IMAGEM\n");
        SDL_Quit();
        return -1;
    }

    textura_grade = loadTexture("imagens/grade.png");
    textura_fundo = loadTexture("imagens/sand.png");
    textura_base = loadTexture("imagens/base.png");
    humano_GER_REC = loadTexture("imagens/Akeno.png");
    humano_GER_TROP = loadTexture("imagens/albedo.png");
    humano_DEF_OFS = loadTexture("imagens/chitoge2.png");
    humano_DEF_PAS = loadTexture("imagens/Dva.png");
    mecanico_GER_REC = loadTexture("imagens/Eliza.png");
    mecanico_GER_TROP = loadTexture("imagens/Emilia.png");
    mecanico_DEF_OFS = loadTexture("imagens/Hatsune.png");
    mecanico_DEF_PAS = loadTexture("imagens/Lucy.png");
    eletrico_GER_REC = loadTexture("imagens/megumin.png");
    eletrico_GER_TROP = loadTexture("imagens/Rias.png");
    eletrico_DEF_OFS = loadTexture("imagens/Lucy4.png");
    eletrico_DEF_PAS = loadTexture("imagens/Rias2.png");
    textura_minerio = loadTexture("imagens/minerio.png");
    textura_comida = loadTexture("imagens/comida.png");
    textura_raio = loadTexture("imagens/raio.png");

    imagens.textura_grade = textura_grade;
    imagens.textura_fundo = textura_fundo;
    imagens.textura_base = textura_base;
    imagens.humano_GER_REC = humano_GER_REC;
    imagens.humano_GER_TROP = humano_GER_TROP;
    imagens.humano_DEF_OFS = humano_DEF_OFS;
    imagens.humano_DEF_PAS = humano_DEF_PAS;
    imagens.mecanico_GER_REC = mecanico_GER_REC;
    imagens.mecanico_GER_TROP = mecanico_GER_TROP;
    imagens.mecanico_DEF_OFS = mecanico_DEF_OFS;
    imagens.mecanico_DEF_PAS = mecanico_DEF_PAS;
    imagens.eletrico_GER_REC = eletrico_GER_REC;
    imagens.eletrico_GER_TROP = eletrico_GER_TROP;
    imagens.eletrico_DEF_OFS = eletrico_DEF_OFS;
    imagens.eletrico_DEF_PAS = eletrico_DEF_PAS;
    imagens.raio = textura_raio;
    imagens.comida = textura_comida;
    imagens.minerio = textura_minerio;

    //  Carrega mapa
    cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);

    // i = 35, j = 1, dimensao = 4, vida = 20, time = 0
    if (cria_base(mapa, 35, 1, 4, 20, 0) == -1) {
        printf("FALHA AO CRIAR BASE 1\n");
        TTF_Quit();
        SDL_Quit();
        return -1; 
    }
    //1, 35, 4, 20, 1
    if (cria_base(mapa, 1, 35, 4, 20, 1) == -1) {
        printf("FALHA AO CRIAR BASE 2\n");
        TTF_Quit();
        SDL_Quit();
        return -1; 
    }

    int mouse_x = -1;
    int mouse_y = -1;
    mouse_data mouse;

    char* string = "FUNCIONA PLS";

    while (executando) {
        // eventos
        while (SDL_PollEvent(&eventos)) {
            // fecha com o x da janela ou com ESC
            if (eventos.type == SDL_QUIT) {
                executando = false;
            } else if (eventos.type == SDL_KEYUP && eventos.key.keysym.sym == SDLK_ESCAPE) {
                executando = false;
            }

            if (eventos.type == SDL_MOUSEBUTTONDOWN) {
                if (eventos.button.button == SDL_BUTTON_LEFT) {
                    mouse_x = eventos.button.x;
                    mouse_y = eventos.button.y;
                    printf("x = %d y = %d\n", mouse_x, mouse_y);
                    printf("i = %d j = %d\n", mouse_y/LADO, mouse_x/LADO);
                }
            } else if (eventos.type == SDL_MOUSEBUTTONUP) {
                    mouse_x = -1;
                    mouse_y = -1;
            }
        }
        // LIMPA O BUFFER
        glClear(GL_COLOR_BUFFER_BIT);

        mouse.x = mouse_x;
        mouse.y = mouse_y;

        //carrega_interface(mapa, imagens, mouse);
        drawText(tela, string, 20, 500, 500, 0, 255, 0);

        // animacao
        SDL_GL_SwapBuffers();
    }

    printf("Fechado com sucesso!\n");

    TTF_Quit();
    SDL_Quit();

    return 0;
}
