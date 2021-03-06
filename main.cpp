/**
 * @file main.cpp
 *
 * @brief Arquivo principal da execução do jogo
 *
 * @author Grupo 2
 *
 */


#include "funcoes.h"

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    printf("Rodando programa...\n");

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
    SDL_WM_SetCaption("BOTTOM TEXT", NULL);

    // tamanho janela
    SDL_Surface* screen = SDL_SetVideoMode(RX, RY, 32, SDL_SWSURFACE|SDL_OPENGL);

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

    bool executando = false;
    bool menu = true;

    SDL_Event eventos;

    //CARREGAMENTO DOS NUMEROS

    texto_data texto;

    char result[50];
    char zero[3] = "0";
    int num = 0;

    for (num = 0; num < 100; num++) {
        sprintf(result, "%d", num);
        if (num < 10) {
            strcat(zero, result);
            texto.numero_textura[num] = importText(zero,200,255,255,255);
            zero[1] = '\0';
        } else {
            texto.numero_textura[num] = importText(result,200,255,255,255);
        }
    }

    //CARREGAMENTO DOS NOMES DAS UNIDADES

    texto.nome_textura[HUMANO] = importText("Humano",200,255,255,255);
    texto.nome_textura[MECANICO] = importText("Mecanico",200,255,255,255);
    texto.nome_textura[ELETRICO] = importText("Eletrico",200,255,255,255);
    texto.nome_textura[OPERARIO] = importText("Operario",200,255,255,255);
    texto.nome_textura[GERADOR_DE_RECURSO] = importText("Gerador de Recurso",200,255,255,255);
   
	texto.nome_textura[GERADOR_DE_COMIDA] = importText("Gerador de comida",200,255,255,255);
	texto.nome_textura[GERADOR_DE_MINERIO] = importText("Gerador de minerio",200,255,255,255);
	texto.nome_textura[GERADOR_DE_ELETRICIDADE] = importText("Gerador de eletricidade",200,255,255,255);

    texto.nome_textura[GERADOR_DE_TROPA] = importText("Gerador de Tropa",200,255,255,255);

	texto.nome_textura[GERADOR_DE_TROPA_HUMANA] = importText("Gerador de tropa humana",200,255,255,255);
	texto.nome_textura[GERADOR_DE_TROPA_MECANICA] = importText("Gerador de tropa mecanica",200,255,255,255);
	texto.nome_textura[GERADOR_DE_TROPA_ELETRICA] = importText("Gerador de tropa eletrica",200,255,255,255);


    texto.nome_textura[DEFESA_PASSIVA] = importText("Muralha",200,255,255,255);
    texto.nome_textura[DEFESA_OFENSIVA] = importText("Torre",200,255,255,255);

	texto.nome_textura[TORRE_TIPO_HUMANO] = importText("Torre tipo humano",200,255,255,255);
	texto.nome_textura[TORRE_TIPO_MECANICO] = importText("Torre tipo mecanico",200,255,255,255);
	texto.nome_textura[TORRE_TIPO_ELETRICO] = importText("Torre tipo eletrico",200,255,255,255);

    texto.nome_textura[REPLICANTE] = importText("Replicante",200,255,255,255);
    texto.nome_textura[EXTERMINADOR] = importText("Exterminador",200,255,255,255);
    texto.nome_textura[HATSUNE] = importText("Hatsune Miku",200,255,255,255);
    texto.nome_textura[WALL] = importText("Wall-E",200,255,255,255);
    texto.nome_textura[DROIDES] = importText("Droide a vapor",200,255,255,255);
    texto.nome_textura[IRON] = importText("Iron Giant",200,255,255,255);
    texto.nome_textura[MERCENARIOS] = importText("Mercenario",200,255,255,255);
    texto.nome_textura[CAVALEIROS] = importText("Cavaleiro Estelar",200,255,255,255);
    texto.nome_textura[CHORIS] = importText("Choris",200,255,255,255);
    texto.nome_textura[BASE] = importText("Base",200,255,255,255);
    texto.nome_textura[CUSTO] = importText("Custo:",50,255,255,255);
    texto.nome_textura[GERAR_OPERARIO] = importText("Gerar Operario",50,255,255,255);
    texto.nome_textura[CRIAR_GER_REC] = importText("Criar Ger. de Rec.",50,255,255,255);
    texto.nome_textura[CRIAR_GER_TRO] = importText("Criar Ger. de Tropa",50,255,255,255);
    texto.nome_textura[CRIAR_DEFESA] = importText("Criar Defesa",50,255,255,255);
    texto.nome_textura[CRIAR_MUR] = importText("   Criar Muralha   ",50,255,255,255);
    texto.nome_textura[CRIAR_DEFESA_OF] = importText("Criar Defesa Ofensiva",50,255,255,255);
    texto.nome_textura[GERAR_TROPA] = importText("   Gerar Tropa   ",50,255,255,255);
    texto.nome_textura[EVOLUIR] = importText("   Evoluir   ",50,255,255,255);
    texto.nome_textura[NIVEL_MAXIMO] = importText("   NIVEL MAXIMO   ",50,255,255,255);
    texto.nome_textura[NIVEL_1] = importText("   NIVEL 1   ",50,255,255,255);
    texto.nome_textura[NIVEL_2] = importText("   NIVEL 2   ",50,255,255,255);
    texto.nome_textura[NIVEL_3] = importText("   NIVEL 3   ",50,255,255,255);
    texto.nome_textura[EVOLUIR_NIVEL_INSUFICIENTE] = importText("   Evoluir (Nivel insuficiente)   ",50,255,255,255);

    // pegar textura
    unsigned int textura_grade;
    unsigned int textura_fundo;
    unsigned int textura_base;
    unsigned int menu_principal;

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
    unsigned int operario;

    unsigned int cavaleiro_estelar;
   	unsigned int choris;
   	unsigned int droids;
   	unsigned int exterminador;
   	unsigned int hatsune;
   	unsigned int iron_giant;
   	unsigned int mercenario;
   	unsigned int replicantes;
   	unsigned int comandante;
   	unsigned int wall_e;

    unsigned int botao1;
    unsigned int botao2;

    unsigned int textura_minerio;
    unsigned int textura_raio;
    unsigned int textura_comida;

    unsigned int textura_exp;

    imagens_data imagens;
	
    // JOGADOR
    player_data *player = (player_data *)malloc(sizeof(player_data));
    cria_player( player, ALIADO);
    // CPU
    player_data *player_CPU = (player_data *)malloc(sizeof(player_data));
    cria_player( player_CPU, INIMIGO);

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
        verifica_imagem("imagens/comida.png") == false ||
        verifica_imagem("imagens/Kuru.png") == false ||
        verifica_imagem("imagens/menu_principal.png") == false ||
        verifica_imagem("imagens/botao1.png") == false ||
        verifica_imagem("imagens/botao2.png") == false ||
        verifica_imagem("imagens/cavaleiroestelar.png") == false ||
        verifica_imagem("imagens/choris.png") == false ||
        verifica_imagem("imagens/droids.png") == false ||
        verifica_imagem("imagens/exterminador.png") == false ||
        verifica_imagem("imagens/hatsune.png") == false ||
        verifica_imagem("imagens/Iron_Giant.png") == false ||
        verifica_imagem("imagens/mercenario.png") == false ||
        verifica_imagem("imagens/replicantes.png") == false ||
        verifica_imagem("imagens/terminator.png") == false
        ) {

        printf("FALHA AO CARREGAR IMAGEM\n");
        SDL_FreeSurface(screen);
        TTF_Quit();
        SDL_Quit();
        return -1;
    }

    textura_grade = loadTexture("imagens/grade.png");
    textura_fundo = loadTexture("imagens/sand.png");
    menu_principal = loadTexture("imagens/menu_principal.png");
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
    operario = loadTexture("imagens/Kuru.png");

    cavaleiro_estelar = loadTexture("imagens/cavaleiroestelar.png");
   	choris = loadTexture("imagens/choris.png");
   	droids = loadTexture("imagens/droids.png");
   	exterminador = loadTexture("imagens/exterminador.png");
   	hatsune = loadTexture("imagens/hatsune.png");
   	iron_giant = loadTexture("imagens/Iron_Giant.png");
   	mercenario = loadTexture("imagens/mercenario.png");
   	replicantes = loadTexture("imagens/replicantes.png");
   	comandante = loadTexture("imagens/terminator.png");
   	wall_e = loadTexture("imagens/wall-e.png");

    botao1 = loadTexture("imagens/botao1.png");
    botao2 = loadTexture("imagens/botao2.png");

    imagens.textura_grade = textura_grade;
    imagens.textura_fundo = textura_fundo;
    imagens.textura_base = textura_base;
    imagens.textura_menu_principal = menu_principal;
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
    imagens.operario = operario;

    imagens.cavaleiro_estelar = cavaleiro_estelar;
   	imagens.choris = choris;
   	imagens.droids = droids;
   	imagens.exterminador = exterminador;
   	imagens.hatsune = hatsune;
   	imagens.iron_giant = iron_giant;
   	imagens.mercenario = mercenario;
   	imagens.replicantes = replicantes;
   	imagens.comandante = comandante;
   	imagens.wall_e = wall_e;

    imagens.botao1 = botao1;
    imagens.botao2 = botao2;

    //  Carrega mapa
    cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);

    // i = 35, j = 1, dimensao = 4, vida = 20, time = 0
    if (cria_base(mapa, 35, 1, 4, VIDA_INICIAL_BASE, ALIADO) == -1) {
        printf("FALHA AO CRIAR BASE 1\n");
        SDL_FreeSurface(screen);
        TTF_Quit();
        SDL_Quit();
        return -1; 
    }
    //1, 35, 4, 20, 1
    if (cria_base(mapa, 1, 35, 4, VIDA_INICIAL_BASE, INIMIGO) == -1) {
        printf("FALHA AO CRIAR BASE 2\n");
        SDL_FreeSurface(screen);
        TTF_Quit();
        SDL_Quit();
        return -1; 
    }

    atributos_data dados_uni;
    dados_uni.classe = GERADOR_DE_RECURSO;
    dados_uni.divisao = HUMANO;
    dados_uni.time = INIMIGO;
    dados_uni.nivel = 1;
    cria_uni_movel(mapa, 5, 5, dados_uni, player);
    dados_uni.nivel = 1;
    dados_uni.time = ALIADO;
    cria_uni_movel(mapa,10,10, dados_uni, player);
    dados_uni.divisao = HUMANO;
    dados_uni.time = INIMIGO;
    cria_uni_movel(mapa,15,15, dados_uni, player);
    dados_uni.nivel = 2;
    dados_uni.time = ALIADO;
    cria_uni_movel(mapa,20,20, dados_uni, player);
    dados_uni.time = INIMIGO;

    //cria_uni_estatico(mapa, 30, 30, dados_uni, player);
    dados_uni.nivel = 1;

    dados_uni.divisao = HUMANO;
    cria_uni_estatico(mapa, 25, 10, dados_uni, player);
    dados_uni.divisao = MECANICO;
    dados_uni.time = ALIADO;
    //cria_uni_estatico(mapa, 10, 25, dados_uni, player);
    dados_uni.divisao = ELETRICO;
    cria_uni_estatico(mapa, 20, 12, dados_uni, player);

    cria_uni_movel(mapa,7,7, dados_uni, player);
    cria_uni_movel(mapa,9,9, dados_uni, player);
    dados_uni.time = INIMIGO;
    cria_uni_movel(mapa,12,12, dados_uni, player);
    cria_uni_movel(mapa,2,12, dados_uni, player);
    cria_uni_movel(mapa,2,14, dados_uni, player);

    dados_uni.time = ALIADO;
    dados_uni.divisao = OPERARIO;
    cria_uni_movel(mapa,2,2, dados_uni, player);
    dados_uni.divisao = MECANICO;

    dados_uni.classe = DEFESA_OFENSIVA; 
    cria_uni_estatico(mapa, 30, 18, dados_uni, player);

    int mouse_x = -1;
    int mouse_y = -1;
    mouse_data *mouse;
    mouse = (mouse_data*)malloc(sizeof(mouse_data));
    mouse->x_mem = 200;
    mouse->y_mem = 200;
    mouse->botao_mem = -1;

    //Atualizar_recursos(mapa, player);
    /*
    int menu = mostra_menu(screen, font); 
    
    if(menu == 1){
        executando = false;
    }
    
    um caso dentro da main:
        while(SDL_PollEvent(&event))...
            switch(event.key.keysym.sym)
                case SDKL_ESCAPE: *muda executando pra false*
    */
    while(menu){
        while (SDL_PollEvent(&eventos)) {
            // fecha com o x da janela ou com ESC
            if (eventos.type == SDL_QUIT) {
                menu = false;
            } else if (eventos.type == SDL_KEYUP && eventos.key.keysym.sym == SDLK_ESCAPE) {
                menu = false;
                break;
            } else if (eventos.type == SDL_KEYUP && eventos.key.keysym.sym == SDLK_j) {
                menu = false;
                executando = true;
            } else if (eventos.type == SDL_KEYUP && eventos.key.keysym.sym == SDLK_s) {
                carrega_jogo(mapa);
		menu = false;
                executando = true;
            } else if (eventos.type == SDL_KEYUP && eventos.key.keysym.sym == SDLK_f) {
                menu = false;
                break;
            }
            
        }
        /*
         * !!!INSTRUCOES!!!!
         * F OU ESC - SAIR
         * S - LOAD GAME
         * J - NOVO JOGO
         */

        glClear(GL_COLOR_BUFFER_BIT);

        mouse->x = mouse_x;
        mouse->y = mouse_y;

        //
        glPushMatrix();
        glOrtho(0, 800, 1200, 0, -1, 1);
        glEnable(GL_TEXTURE_2D);
        
        glBindTexture(GL_TEXTURE_2D, imagens.textura_menu_principal);
        
        glColor4ub(255, 255, 255, 255);
        
        glBegin(GL_QUADS);
        
        glTexCoord2d(0,0);  glVertex2f(0, 0);  
        glTexCoord2d(1,0);  glVertex2f(800, 0);
        glTexCoord2d(1,1);  glVertex2f(800, 1200);
        glTexCoord2d(0,1);  glVertex2f(0, 1200);
        
        glEnd();
        
        glPopMatrix();
        //glDisable(GL_TEXTURE_2D);
        //
        
        SDL_Flip(screen);
        SDL_GL_SwapBuffers();
    }
    
    int i, j, contador_turno = 0;
    int turno_de_quem = ALIADO;
    while (executando) {
        // eventos
        while (SDL_PollEvent(&eventos)) {
            // fecha com o x da janela ou com ESC
            if (eventos.type == SDL_QUIT) {
                executando = false;
            } else if (eventos.type == SDL_KEYUP && eventos.key.keysym.sym == SDLK_ESCAPE) {
                executando = false;
            }

            if (eventos.type == SDL_MOUSEMOTION) {
                mouse->x_agr = eventos.motion.x;
                mouse->y_agr = eventos.motion.y;
            }

            if (eventos.type == SDL_MOUSEBUTTONDOWN) {
                if (eventos.button.button == SDL_BUTTON_LEFT) {
                    mouse_x = eventos.button.x;
                    mouse_y = eventos.button.y;
                    mouse->x_botao = mouse_x;
                    mouse->y_botao = mouse_y;
                    if (mouse_x/LADO < BLOCOS_LINHA && mouse_x/LADO >= 0 &&
                        mouse_y/LADO < BLOCOS_LINHA && mouse_y/LADO >= 0) {
                        mouse->x_mem = mouse_x;
                        mouse->y_mem = mouse_y;
                    }
                    //printf("x = %d y = %d\n", mouse_x, mouse_y);
                    //printf("i = %d j = %d\n", mouse_y/LADO, mouse_x/LADO);
                }
            } else if (eventos.type == SDL_MOUSEBUTTONUP) {
                    mouse_x = -1;
                    mouse_y = -1;
                    //mouse.botao_mem = -1;
            }
            // Para mudar de turno PRESS 'enter'
            if(eventos.type == SDL_KEYDOWN && (eventos.key.keysym.sym == SDLK_RETURN || SDL_KEYDOWN && eventos.key.keysym.sym == SDLK_KP_ENTER)){
                turno_de_quem = INIMIGO;
                printf("Vez do CPU\n");
                contador_turno++;
            }
        }
        // LIMPA O BUFFER
        glClear(GL_COLOR_BUFFER_BIT);

        mouse->x = mouse_x;
        mouse->y = mouse_y;
        if (turno_de_quem == ALIADO) {
        	carrega_interface(mapa, imagens, mouse, texto, player, dados_uni);

        	SDL_Flip(screen);
        	SDL_GL_SwapBuffers();

            
        if (verifica_selecao(mapa, *mouse) != 0) {
                verifica_unidades(mapa, mouse, player, dados_uni, imagens, texto);
                mouse_x = -1;
                mouse_y = -1;
            }


    	}
    	else if (turno_de_quem == INIMIGO) {
            CPU(mapa, player_CPU, contador_turno);
            //Atualizacoes do turno:
            Atualizar_recursos(mapa, player_CPU);
            Atualizar_recursos(mapa, player);
            restaurar_acoes(mapa);
            turno_de_quem = ALIADO;
            printf("sua vez\n");
            contador_turno++;
        }
    }

    printf("Fechado com sucesso!\n");
    salva_jogo(mapa);
    SDL_FreeSurface(screen);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
