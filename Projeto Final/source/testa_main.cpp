/**
 * @file testa_main.cpp
 *
 * @brief Arquivo com testes das funções do jogo
 *
 * @author Grupo 2
 *
 */

#include <gtest/gtest.h>
#include "funcoes.h"

TEST(Testa, gtest_instalado) {
    ASSERT_EQ(42, (40 + 2));
}

TEST(Testa, cria_mapa) {
    cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    ASSERT_EQ(0, cria_mapa(mapa));
}

TEST(Testa, foto_existe) {
    ASSERT_EQ(true, verifica_imagem("imagens/grade.png"));
}

TEST(Testa, foto_n_existe) {
    ASSERT_EQ(false, verifica_imagem("imagens/mochileiro_das_galaxias.png"));
}

TEST(Testa, carrega_numeros_recurso) {
    
    player_data *player = (player_data *)malloc(sizeof(player_data));
    cria_player( player, ALIADO);
    
    texto_data texto;

    char result[50];
    char zero[3] = "0";
    int num = 0;

    ASSERT_EQ(0, carrega_numeros_recurso(texto, player));
    free(player);
}

TEST(Testa, comandante_falha) {
        imagens_data imagens; 
    
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

    unsigned int textura_minerio;
    unsigned int textura_raio;
    unsigned int textura_comida;

    unsigned int textura_exp;


    ASSERT_EQ(1, carrega_comandante(imagens));
}


TEST(Testa, espaco_verifica) {
    cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);
    ASSERT_EQ(false, verifica_espaco(mapa, 7899, 1234));
}

TEST(Testa, selecao_valida) {
    cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);
    int mouse_x = -1;
    int mouse_y = -1;
    mouse_data mouse;
    mouse.x_mem = 200;
    mouse.y_mem = 200;
    
    ASSERT_EQ(0 , verifica_selecao(mapa, mouse));
}

TEST(Testa, cria_base) {
    cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);
    ASSERT_EQ(0, cria_base(mapa, 5, 5, 10, 42, 0));
}

TEST(Testa, minimo) {
    
    ASSERT_EQ(2, min(2, 8));
}

TEST(Testa, maximo) {
    
    ASSERT_EQ(8, max(2,8));
}

/*
TEST(Testa, velocidade) {
    cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);
    int i = 56;
    int j = 45;
    unidade_movel* aux = mapa[i][j].pUniMovel;
    
    ASSERT_EQ(false, verifica_oposicao(mapa, aux, i, j));
}
/*
TEST(Testa, combate) {
    mouse_data *mouse;
    
    cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);
    
    player_data player1;
    player1.comida = 40;
    player1.minerio = 40;
    player1.eletricidade = 40;
    player1.xp = 0;
    player1.nivel = 1;
    player_data *player = &player1;
    
    
  
    SDL_Event evento;
    
    int cell_i = mouse->y/LADO;
    int cell_j = mouse->x/LADO;
    
    cell_i = evento.button.y/LADO;
    cell_j = evento.button.x/LADO;
    
    unidade_movel* aux = mapa[cell_i][cell_j].pUniMovel;
    ASSERT_EQ(0, move_unidade(mapa, aux, cell_i, cell_j));
}
TEST(Testa, cria_interface) {
    cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);
  
    imagens_data imagens; 
    player_data player1;
    player1.comida = 40;
    player1.minerio = 40;
    player1.eletricidade = 40;
    player1.xp = 0;
    player1.nivel = 1;
    player_data *player = &player1;
    
    atributos_data dados_uni;
    dados_uni.classe = GERADOR_DE_RECURSO;
    dados_uni.divisao = HUMANO;
    dados_uni.time = INIMIGO;
    dados_uni.nivel = 1;
    cria_uni_movel(mapa, 5, 5, dados_uni, player);
    
    mouse_data *mouse;
    texto_data texto;
    mouse->x = 200;
    mouse->y = 200;
    ASSERT_EQ(0, carrega_interface(mapa, imagens, mouse, texto, player, dados_uni));
}
*/

TEST(Testa, cria_base_espaco_ocupado) {
    cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);
    cria_base(mapa, 35, 1, 4, VIDA_INICIAL_BASE, ALIADO);
    ASSERT_EQ(-1, cria_base(mapa, 35, 1, 4, VIDA_INICIAL_BASE, INIMIGO));
}

TEST(Testa, cria_uni_movel_recurso_MAX) {
    cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);

    player_data *player = (player_data *)malloc(sizeof(player_data));
    cria_player( player, ALIADO);
    
    player->comida = 999;
    player->minerio = 999;
    player->eletricidade = 999;
    player->nivel = 3;

    atributos_data dados_uni;
    bool aux =false;

    int divisao, classe, nivel, time;
    for (divisao = HUMANO; divisao <= OPERARIO; divisao++) {
        for (nivel = 1; nivel <=3; nivel++) {
            aux =false;
            dados_uni.divisao = divisao;
            dados_uni.time = ALIADO;
            dados_uni.nivel = nivel;
            mapa[1][1].pUniMovel = NULL;
            mapa[1][1].pUniImovel = NULL;
            mapa[1][1].pBase = NULL;
            ASSERT_EQ(0, cria_uni_movel(mapa, 1, 1, dados_uni, player));
            if(mapa[1][1].pUniMovel != NULL)
                aux = true;
            ASSERT_EQ(true, aux);
        }
    }
    free(player);
}

TEST(Testa, cria_uni_movel_espaco_ocupado) {
    cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);
        
    player_data *player = (player_data *)malloc(sizeof(player_data));
    cria_player( player, ALIADO);
    
    atributos_data dados_uni;
    dados_uni.classe = GERADOR_DE_RECURSO;
    dados_uni.divisao = HUMANO;
    dados_uni.time = ALIADO;
    dados_uni.nivel = 1;
    cria_uni_movel(mapa, 5, 5, dados_uni, player);

    ASSERT_EQ(-1, cria_uni_movel(mapa, 5, 5, dados_uni, player));
    free(player);
}

TEST(Testa, cria_uni_movel_sem_recurso) {
    cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);
        
    player_data *player = (player_data *)malloc(sizeof(player_data));
    cria_player( player, ALIADO);

    player->comida = 0;
    player->minerio = 0;
    player->eletricidade = 0;
    
    atributos_data dados_uni;
    dados_uni.classe = GERADOR_DE_RECURSO;
    dados_uni.divisao = HUMANO;
    dados_uni.time = ALIADO;
    dados_uni.nivel = 1;
    ASSERT_EQ(-2, cria_uni_movel(mapa, 5, 5, dados_uni, player));
    free(player);
}

TEST(Testa, cria_uni_estatico_recurso_MAX) {
    cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);

    player_data *player = (player_data *)malloc(sizeof(player_data));
    cria_player( player, ALIADO);
    
    player->comida = 999;
    player->minerio = 999;
    player->eletricidade = 999;
    player->nivel = 3;

    atributos_data dados_uni;
    bool aux =false;

    int divisao, classe, nivel, time, i, j;
    for(classe = GERADOR_DE_RECURSO; classe <= DEFESA_PASSIVA; classe++) {
        for (divisao = HUMANO; divisao <= ELETRICO; divisao++) {
                aux =false;
                dados_uni.classe = classe;
                dados_uni.divisao = divisao;
                dados_uni.time = ALIADO;
                for (i = 1; i <= 5; i++) {
                    for ( j= 1; j <= 5; j++) {
                        mapa[i][j].pUniImovel = NULL;
                        mapa[i][j].pUniMovel = NULL;
                        mapa[i][j].pBase = NULL;
                    }
                }
                ASSERT_EQ(0, cria_uni_estatico(mapa, 1, 1, dados_uni, player));
                if(mapa[1][1].pUniImovel != NULL)
                    aux = true;
                ASSERT_EQ(true, aux);
        }
    }
    free(player);
}

TEST(Testa, cria_uni_estatica_espaco_ocupado) {
    cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);
        
    player_data *player = (player_data *)malloc(sizeof(player_data));
    cria_player( player, ALIADO);
    
    atributos_data dados_uni;
    dados_uni.classe = GERADOR_DE_RECURSO;
    dados_uni.divisao = HUMANO;
    dados_uni.time = ALIADO;
    dados_uni.nivel = 1;
    cria_uni_estatico(mapa, 5, 5, dados_uni, player);

    ASSERT_EQ(-1, cria_uni_estatico(mapa, 5, 5, dados_uni, player));
    free(player);
}

TEST(Testa, cria_uni_estatica_sem_recurso) {
    cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);

    player_data *player = (player_data *)malloc(sizeof(player_data));
    cria_player( player, ALIADO);
        
    player->comida = 0;
    player->minerio = 0;
    player->eletricidade = 0;
    
    atributos_data dados_uni;
    dados_uni.classe = GERADOR_DE_RECURSO;
    dados_uni.divisao = HUMANO;
    dados_uni.time = ALIADO;
    dados_uni.nivel = 1;
    ASSERT_EQ(-2, cria_uni_estatico(mapa, 5, 5, dados_uni, player));
    free(player);
}

 
TEST(Testa, cria_uni_movel_2) {
    cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);
        
    player_data *player = (player_data *)malloc(sizeof(player_data));
    cria_player( player, ALIADO);
    
    
    atributos_data dados_uni;
    dados_uni.classe = GERADOR_DE_RECURSO;
    dados_uni.divisao = ELETRICO;
    dados_uni.time = ALIADO;
    dados_uni.nivel = 1;

    ASSERT_EQ(0, cria_uni_movel(mapa, 5, 5, dados_uni, player));
    free(player);
}

TEST(Testa, cria_uni_movel_3) {
    cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);

    player_data *player = (player_data *)malloc(sizeof(player_data));
    cria_player( player, ALIADO);
    
    atributos_data dados_uni;
    dados_uni.classe = GERADOR_DE_RECURSO;
    dados_uni.divisao = MECANICO;
    dados_uni.time = ALIADO;
    dados_uni.nivel = 1;

    ASSERT_EQ(0, cria_uni_movel(mapa, 5, 5, dados_uni, player));

    free(player);
}

TEST(Testa, move_unidade) {
	cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);

    player_data *player = (player_data *)malloc(sizeof(player_data));
    cria_player( player, ALIADO);
    
    atributos_data dados_uni;
    dados_uni.divisao = MECANICO;
    dados_uni.time = ALIADO;
    dados_uni.nivel = 1;
    ASSERT_EQ(0, cria_uni_movel(mapa, 1, 1, dados_uni, player));
    ASSERT_EQ(0, move_unidade(mapa, mapa[1][1].pUniMovel, 2, 2));
    free(player);
}

TEST(Testa, combate) {
	cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);

    player_data *player = (player_data *)malloc(sizeof(player_data));
    cria_player( player, ALIADO);

    player_data *player_CPU = (player_data *)malloc(sizeof(player_data));
    cria_player( player, INIMIGO);
    
    atributos_data dados_uni;
    dados_uni.divisao = MECANICO;
    dados_uni.time = ALIADO;
    dados_uni.nivel = 1;
    ASSERT_EQ(0, cria_uni_movel(mapa, 1, 1, dados_uni, player));
    dados_uni.time = INIMIGO;
    ASSERT_EQ(0, cria_uni_movel(mapa, 2, 2, dados_uni, player));
    ASSERT_EQ(0, combate(mapa, mapa[1][1].pUniMovel,  mapa[2][2].pUniMovel, player));
    free(player);
    free(player_CPU);
}

TEST(Testa, combate_defensivo) {
	cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);

    player_data *player = (player_data *)malloc(sizeof(player_data));
    cria_player( player, ALIADO);

    player_data *player_CPU = (player_data *)malloc(sizeof(player_data));
    cria_player( player, INIMIGO);
    
    atributos_data dados_uni;
    dados_uni.classe = DEFESA_OFENSIVA;
    dados_uni.divisao = MECANICO;
    dados_uni.time = ALIADO;
    dados_uni.nivel = 1;
    ASSERT_EQ(0, cria_uni_movel(mapa, 1, 1, dados_uni, player));
    dados_uni.time = INIMIGO;
    ASSERT_EQ(0, cria_uni_estatico(mapa, 2, 2, dados_uni, player));
    ASSERT_EQ(0, combate_defensivo(mapa, mapa[2][2].pUniImovel,  mapa[1][1].pUniMovel, player_CPU));
    free(player);
    free(player_CPU);
}

TEST(Testa, destruicao) {
	cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);

    player_data *player = (player_data *)malloc(sizeof(player_data));
    cria_player( player, ALIADO);

    player_data *player_CPU = (player_data *)malloc(sizeof(player_data));
    cria_player( player, INIMIGO);
    
    atributos_data dados_uni;
    dados_uni.classe = GERADOR_DE_RECURSO;
    dados_uni.divisao = MECANICO;
    dados_uni.time = ALIADO;
    dados_uni.nivel = 1;
    ASSERT_EQ(0, cria_uni_movel(mapa, 1, 1, dados_uni, player));
    dados_uni.time = INIMIGO;
    ASSERT_EQ(0, cria_uni_estatico(mapa, 2, 2, dados_uni, player));
    ASSERT_EQ(0, destruicao(mapa, mapa[1][1].pUniMovel,  mapa[2][2].pUniImovel, player));
	Atualizar_recursos(mapa, player);
	Atualizar_recursos(mapa, player_CPU);
	restaurar_acoes(mapa);
    ASSERT_EQ(0, destruicao(mapa, mapa[1][1].pUniMovel,  mapa[2][2].pUniImovel, player));
    free(player);
    free(player_CPU);
}

TEST(Testa, destruicao_defensiva) {
	cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);

    player_data *player = (player_data *)malloc(sizeof(player_data));
    cria_player( player, ALIADO);

    player_data *player_CPU = (player_data *)malloc(sizeof(player_data));
    cria_player( player, INIMIGO);
    
    atributos_data dados_uni;
    dados_uni.classe = DEFESA_PASSIVA;
    dados_uni.divisao = MECANICO;
    dados_uni.time = ALIADO;
    dados_uni.nivel = 1;
    ASSERT_EQ(0, cria_uni_estatico(mapa, 1, 1, dados_uni, player));
    dados_uni.classe = DEFESA_OFENSIVA;
    dados_uni.time = INIMIGO;
    ASSERT_EQ(0, cria_uni_estatico(mapa, 2, 2, dados_uni, player));
    ASSERT_EQ(0, destruicao_defensiva(mapa, mapa[2][2].pUniImovel,  mapa[1][1].pUniImovel, player_CPU));
    free(player);
    free(player_CPU);
}

TEST(Testa, destruicao_base) {
	cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);

    player_data *player = (player_data *)malloc(sizeof(player_data));
    cria_player( player, ALIADO);

    player_data *player_CPU = (player_data *)malloc(sizeof(player_data));
    cria_player( player, INIMIGO);
    
    atributos_data dados_uni;
    dados_uni.classe = DEFESA_PASSIVA;
    dados_uni.divisao = MECANICO;
    dados_uni.time = ALIADO;
    dados_uni.nivel = 1;
    ASSERT_EQ(0, cria_uni_movel(mapa, 1, 1, dados_uni, player));
    dados_uni.classe = DEFESA_OFENSIVA;
    dados_uni.time = INIMIGO;
    ASSERT_EQ(0, cria_base(mapa, 2, 2, 4, VIDA_INICIAL_BASE, INIMIGO));
    ASSERT_EQ(0, destruicao_base(mapa, mapa[1][1].pUniMovel,  mapa[2][2].pBase, player));
    free(player);
    free(player_CPU);
}

TEST(Testa, player_level) {
	cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);

    player_data *player = (player_data *)malloc(sizeof(player_data));
    cria_player( player, ALIADO);
    player->xp = 51;
    ASSERT_EQ(0, player_level(player));
    free(player);
}

TEST(Testa, evolution) {
	cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);

    player_data *player = (player_data *)malloc(sizeof(player_data));
    cria_player( player, ALIADO);

    atributos_data dados_uni;
    dados_uni.classe = GERADOR_DE_RECURSO;
    dados_uni.divisao = MECANICO;
    dados_uni.time = ALIADO;
    dados_uni.nivel = 1;
    ASSERT_EQ(0, cria_uni_estatico(mapa, 1, 1, dados_uni, player));
    ASSERT_EQ(0, evolution(mapa[1][1].pUniImovel, player));
    free(player);
}

TEST(Testa, gera_operario) {
	cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);

    player_data *player = (player_data *)malloc(sizeof(player_data));
    cria_player( player, ALIADO);

    ASSERT_EQ(0, cria_base(mapa, 1, 1, 4, VIDA_INICIAL_BASE, ALIADO));
    atributos_data dados_uni;
    dados_uni.classe = GERADOR_DE_RECURSO;
    dados_uni.divisao = MECANICO;
    dados_uni.time = ALIADO;
    mouse_data mouse;
    mouse.y_mem = 1*LADO;
    mouse.x_mem = 1*LADO;
    ASSERT_EQ(0, gera_operario(mapa, &mouse, dados_uni, player));
    free(player);
}

TEST(Testa, gera_tropa) {
	cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);

    player_data *player = (player_data *)malloc(sizeof(player_data));
    cria_player( player, ALIADO);

    atributos_data dados_uni;
    dados_uni.classe = GERADOR_DE_RECURSO;
    dados_uni.divisao = MECANICO;
    dados_uni.time = ALIADO;
    ASSERT_EQ(0, cria_uni_estatico(mapa, 1, 1, dados_uni, player));
    mouse_data mouse;
    mouse.y_mem = 1*LADO;
    mouse.x_mem = 1*LADO;
    ASSERT_EQ(0, gera_tropa(mapa, &mouse, dados_uni, player));
    free(player);
}

TEST(Testa, CPU_module) {
    cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA];
    cria_mapa(mapa);
    // JOGADOR
    player_data *player = (player_data *)malloc(sizeof(player_data));
    cria_player( player, ALIADO);
    // CPU
    player_data *player_CPU = (player_data *)malloc(sizeof(player_data));
    cria_player( player_CPU, INIMIGO);
    cria_base(mapa, 35, 1, 4, VIDA_INICIAL_BASE, ALIADO);
    cria_base(mapa, 1, 35, 4, VIDA_INICIAL_BASE, INIMIGO);
    int i, j, funciona = -1, alcance, p, q;
    bool loop;
    for (i = 0; i<=50; i++) {
        ASSERT_EQ(0, CPU(mapa, player, i));
        ASSERT_EQ(0, CPU(mapa, player_CPU, i+1));
        Atualizar_recursos(mapa, player_CPU);
        Atualizar_recursos(mapa, player);
        restaurar_acoes(mapa);
    }
    player->vida_base = VIDA_INICIAL_BASE/5;
        ASSERT_EQ(0, CPU(mapa, player, 52));
    player_CPU->vida_base = VIDA_INICIAL_BASE/5;
        ASSERT_EQ(0, CPU(mapa, player_CPU, 53));
    free(player);
    free(player_CPU);
} 
    
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}