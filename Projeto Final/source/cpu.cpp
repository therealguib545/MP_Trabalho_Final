/**
 * @file cpu.cpp
 *
 * @brief Arquivo com a aplicação da inteligencia artificial da CPU para simular o oponente
 *
 * @author Grupo 2
 *
 */

#include "funcoes.h"
bool verificador_CPU (cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA], int i, int j);
void criacoes_iniciais_1(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA], atributos_data atributos, player_data *player_CPU);
void criacoes_iniciais_2(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA], atributos_data atributos, player_data *player_CPU);
void criacoes_iniciais_3(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA], atributos_data atributos, player_data *player_CPU);
void priorizar_defesa(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA], atributos_data atributos, player_data *player_CPU);
void priorizar_recursos(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA], atributos_data atributos, player_data *player_CPU);
void priorizar_evolucoes(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA], atributos_data atributos, player_data *player_CPU);
void priorizar_tropas(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA], atributos_data atributos, player_data *player_CPU);
void priorizar_movimentacao(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA], atributos_data atributos, player_data *player_CPU);
void priorizar_destruicao(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA], atributos_data atributos, player_data *player_CPU);
void priorizar_combate(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA], atributos_data atributos, player_data *player_CPU);
void priorizar_destruicao_base(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA], atributos_data atributos, player_data *player_CPU);

void CPU(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA], imagens_data imagens, mouse_data mouse,
texto_data texto, player_data *player_CPU, atributos_data atributos, int contador_turno) {
    struct timeval time; 
    gettimeofday(&time,NULL);
    srand((time.tv_sec * 1000) + (time.tv_usec / 1000)); 
    if(contador_turno == 1){
        criacoes_iniciais_1(mapa, atributos, player_CPU);
    }
    else if(contador_turno == 3){
        criacoes_iniciais_2(mapa, atributos, player_CPU);
    }
    else if(contador_turno == 5){
        criacoes_iniciais_3(mapa, atributos, player_CPU);
    }
    else{
        usleep(10000);
        if(player_CPU->vida_base < VIDA_INICIAL_BASE/2)
            priorizar_defesa(mapa, atributos, player_CPU);
        if(player_CPU->vida_base < VIDA_INICIAL_BASE/4)
            priorizar_defesa(mapa, atributos, player_CPU);
        usleep(10000);
        priorizar_recursos(mapa, atributos, player_CPU);
        usleep(10000);
        priorizar_evolucoes(mapa, atributos, player_CPU);
        usleep(10000);
        priorizar_tropas(mapa, atributos, player_CPU);
        usleep(10000);
        priorizar_movimentacao(mapa, atributos, player_CPU);
        usleep(10000);
        priorizar_destruicao(mapa, atributos, player_CPU);
        usleep(10000);
        priorizar_combate(mapa, atributos, player_CPU);
        priorizar_destruicao_base(mapa, atributos, player_CPU);
    }
    mouse.x_mem = -1;
    mouse.y_mem = -1;
    carrega_interface(mapa, imagens, &mouse, texto, player_CPU, atributos);
}

void criacoes_iniciais_1(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA], atributos_data atributos, player_data *player_CPU) {
    atributos.classe = GERADOR_DE_RECURSO;
    atributos.divisao = HUMANO;
    atributos.time = INIMIGO;
    atributos.nivel = 1;
    cria_uni_estatico(mapa, 1, 30, atributos, player_CPU);
    atributos.classe = GERADOR_DE_RECURSO;
    atributos.divisao = MECANICO;
    atributos.time = INIMIGO;
    atributos.nivel = 1;
    cria_uni_estatico(mapa, 6, 30, atributos, player_CPU);
    atributos.classe = GERADOR_DE_RECURSO;
    atributos.divisao = ELETRICO;
    atributos.time = INIMIGO;
    atributos.nivel = 1;
    cria_uni_estatico(mapa, 6, 35, atributos, player_CPU);
    atributos.classe = GERADOR_DE_TROPA;
    atributos.divisao = HUMANO;
    atributos.time = INIMIGO;
    atributos.nivel = 1;
    cria_uni_estatico(mapa, 2, 25, atributos, player_CPU);
    atributos.classe = GERADOR_DE_TROPA;
    atributos.divisao = MECANICO;
    atributos.time = INIMIGO;
    atributos.nivel = 1;
    cria_uni_estatico(mapa, 9, 26, atributos, player_CPU);
    atributos.classe = GERADOR_DE_TROPA;
    atributos.divisao = ELETRICO;
    atributos.time = INIMIGO;
    atributos.nivel = 1;
    cria_uni_estatico(mapa, 10, 35, atributos, player_CPU);
}
void criacoes_iniciais_2(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA], atributos_data atributos, player_data *player_CPU) {
    
    atributos.classe = DEFESA_OFENSIVA;
    atributos.divisao = HUMANO;
    atributos.time = INIMIGO;
    atributos.nivel = 1;
    cria_uni_estatico(mapa, 3, 19, atributos, player_CPU);
    atributos.classe = DEFESA_OFENSIVA;
    atributos.divisao = MECANICO;
    atributos.time = INIMIGO;
    atributos.nivel = 1;
    cria_uni_estatico(mapa, 14, 22, atributos, player_CPU);
    atributos.classe = DEFESA_OFENSIVA;
    atributos.divisao = ELETRICO;
    atributos.time = INIMIGO;
    atributos.nivel = 1;
    cria_uni_estatico(mapa, 15, 35, atributos, player_CPU);
}

void criacoes_iniciais_3(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA], atributos_data atributos, player_data *player_CPU) {
    int count;
    int i, j, divisao;
    for (divisao = HUMANO; divisao <= ELETRICO; divisao++) {
        atributos.classe = DEFESA_PASSIVA;
        atributos.divisao = divisao;
        atributos.time = INIMIGO;
        count = 3+rand()%2;
        while (count--) {
            do {
                i = rand()%40;
                j = rand()%40;
            } while (i-j > 0 || j+(39-i) > 53 || !verificador_CPU(mapa, i, j));
            cria_uni_estatico(mapa, i, j, atributos, player_CPU);
        }
    }
}
void priorizar_defesa(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA],
atributos_data atributos, player_data *player_CPU) {
    int count;
    int i, j, divisao, defesa, k;
    for (defesa = DEFESA_OFENSIVA; defesa <= DEFESA_PASSIVA; defesa++) {
        for (divisao = HUMANO; divisao <= ELETRICO; divisao++) {
            atributos.classe = defesa;
            atributos.divisao = divisao;
            atributos.time = INIMIGO;
            count = 1;
            while (count--) {
                k = 0;
                do {
                    i = rand()%40;
                    j = rand()%40;
                    k++;
                } while ((i-j > 0 || !cria_uni_estatico(mapa, i, j, atributos, player_CPU)) && k < 15);
                if (k > 15)
                    break;
            }
        }
    }
}

void priorizar_recursos(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA],
atributos_data atributos, player_data *player_CPU) {
    int count;
    int i, j, divisao, defesa, k;
    // RECURSOS
    for (divisao = HUMANO; divisao <= ELETRICO; divisao++) {
        atributos.classe = GERADOR_DE_RECURSO;
        atributos.divisao = divisao;
        atributos.time = INIMIGO;
        atributos.nivel = 1;
        count = 0;
        if (divisao == HUMANO && player_CPU->comida < COMIDA_INICIAL/2)
            count = 1;
        if (divisao == MECANICO && player_CPU->minerio < MINERIO_INICIAL/2)
            count = 1;
        if (divisao == ELETRICO && player_CPU->eletricidade < ELETRICIDADE_INICIAL/2)
            count = 1;
        while (count--) {
            k = 0;
            do {
                i = rand()%40;
                j = rand()%40;
                k++;
            } while ((i-j > 0 || !cria_uni_estatico(mapa, i, j, atributos, player_CPU)) && k < 15);
            if (k > 15)
                break;
        }
    }
    // DEFESA
    for (defesa = DEFESA_OFENSIVA; defesa <= DEFESA_PASSIVA; defesa++) {
        for (divisao = HUMANO; divisao <= ELETRICO; divisao++) {
            atributos.classe = defesa;
            atributos.divisao = divisao;
            atributos.time = INIMIGO;
            count = rand()%2;
            while (count--) {
                k = 0;
                do {
                    i = rand()%40;
                    j = rand()%40;
                    k++;
                } while ((i-j > 0 || !cria_uni_estatico(mapa, i, j, atributos, player_CPU)) && k < 10);
                if (k > 10)
                    break;
            }
        }
    }
}

void priorizar_evolucoes(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA],
atributos_data atributos, player_data *player_CPU) {
    int count;
    int i, j, k, pode_evoluir;
    count = 3;
    while (count--) {
        k = 0;
        pode_evoluir = 0;
        do {
            i = rand()%40;
            j = rand()%40;
            if (mapa[i][j].pUniImovel != NULL &&
            mapa[i][j].pUniImovel->time == INIMIGO &&
            mapa[i][j].pUniImovel->nivel < 3) {
                pode_evoluir = 1;
                evolution(mapa[i][j].pUniImovel, player_CPU);
            }
            k++;
        } while (pode_evoluir == 0 && k < 800);
    }
}
void priorizar_tropas(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA],
atributos_data atributos, player_data *player_CPU) {
    int count;
    int i, j, k;
    bool pode_gerar_tropas;
    mouse_data mouse;
    count = 3;
    while (count--) {
        k = 0;
        pode_gerar_tropas = false;
        do {
            i = rand()%40;
            j = rand()%40;
            if (mapa[i][j].pUniImovel != NULL &&
            mapa[i][j].pUniImovel->time == INIMIGO &&
            mapa[i][j].pUniImovel->classe == GERADOR_DE_TROPA) {
                pode_gerar_tropas = true;
                mouse.y_mem = i*LADO;
                mouse.x_mem = j*LADO;
                atributos.time = INIMIGO;
                atributos.nivel = 1+rand()%mapa[i][j].pUniImovel->nivel;
                atributos.divisao = mapa[i][j].pUniImovel->divisao;
                gera_tropa(mapa, &mouse, atributos, player_CPU);
            }
            k++;
        } while (pode_gerar_tropas == false && k < 800);
    }
}
void priorizar_movimentacao(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA],
atributos_data atributos, player_data *player_CPU) {
    int count;
    int i, j, k, new_i, new_j;
    bool pode_mover;
    count = 10;
    while (count--) {
        k = 0;
        pode_mover = false;
        do {
            i = rand()%40;
            j = rand()%40;
            if (mapa[i][j].pUniMovel != NULL &&
            mapa[i][j].pUniMovel->time == INIMIGO) {
                pode_mover = true;
                new_i = i+rand()%mapa[i][j].pUniMovel->velocidade;
                new_j = j-rand()%mapa[i][j].pUniMovel->velocidade;
                if(verificador_CPU(mapa, new_i, new_j))
                    move_unidade(mapa, mapa[i][j].pUniMovel, new_i, new_j);
                else
                    pode_mover = false;
            }
            k++;
        } while (pode_mover == false && k < 800);
    }
}
void priorizar_destruicao(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA],
atributos_data atributos, player_data *player_CPU) {
    bool loop;
    int count;
    int i, j, alcance, k, p, q;
    count = 3+rand()%3;
    while (count--) {
        k = 0;
        do {
            i = rand()%40;
            j = rand()%40;
            if (mapa[i][j].pUniMovel != NULL &&
            mapa[i][j].pUniMovel->time == INIMIGO) {
                loop = true;
                alcance = mapa[i][j].pUniMovel->alcance;
                for (p = i - alcance; p <= i + alcance && loop == true; p++) {
                    for (q = j - alcance; q<= j + alcance && loop == true; q++) {
                        if(p >= 0 && p < BLOCOS_LINHA && q >= 0 && q < BLOCOS_LINHA) {
                            if (mapa[p][q].pUniImovel != NULL &&
                            mapa[p][q].pUniImovel->time == ALIADO) {
                                destruicao(mapa, mapa[i][j].pUniMovel, mapa[p][q].pUniImovel, player_CPU);
                                loop = false;
                            }
                        }
                    }
                }

            }
            k++;
        } while (k < 800);
    }
}

void priorizar_combate(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA],
atributos_data atributos, player_data *player_CPU) {
    bool loop;
    int count;
    int i, j, alcance, k, p, q;
    count = 3+rand()%3;
    while (count--) {
        k = 0;
        do {
            i = rand()%40;
            j = rand()%40;
            if (mapa[i][j].pUniMovel != NULL &&
            mapa[i][j].pUniMovel->time == INIMIGO) {
                alcance = mapa[i][j].pUniMovel->alcance;
                loop = true;
                for (p = i - alcance; p <= i + alcance && loop == true; p++) {
                    for (q = j - alcance; q<= j + alcance && loop == true; q++) {
                        if(p >= 0 && p < BLOCOS_LINHA && q >= 0 && q < BLOCOS_LINHA) {
                            if (mapa[p][q].pUniMovel != NULL &&
                            mapa[p][q].pUniMovel->time == ALIADO) {
                                combate(mapa, mapa[i][j].pUniMovel, mapa[p][q].pUniMovel, player_CPU);
                                loop = false;
                            }
                        }
                    }
                }
            }
            k++;
        } while (k < 800);
    }
}

void priorizar_destruicao_base(cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA],
atributos_data atributos, player_data *player_CPU) {
    bool loop;
    int count;
    int i, j, alcance, k, p, q;
    count = 5;
    while (count--) {
        k = 0;
        do {
            i = 20+rand()%20;
            j = rand()%20;
            if (mapa[i][j].pUniMovel != NULL &&
            mapa[i][j].pUniMovel->time == INIMIGO) {
                alcance = mapa[i][j].pUniMovel->alcance;
                loop = true;
                for (p = i - alcance; p <= i + alcance && loop == true; p++) {
                    for (q = j - alcance; q<= j + alcance && loop == true; q++) {
                        if(p >= 0 && p < BLOCOS_LINHA && q >= 0 && q < BLOCOS_LINHA) {
                            if (mapa[p][q].pBase != NULL &&
                            mapa[p][q].pBase->time == ALIADO) {
                                destruicao_base(mapa, mapa[i][j].pUniMovel, mapa[p][q].pBase, player_CPU);
                                loop = false;
                            }
                        }
                    }
                }
            }
            k++;
        } while (k < 800);
    }
}

bool verificador_CPU (cell_mapa mapa[BLOCOS_LINHA][BLOCOS_LINHA], int i, int j) {
    if (i >= 0 && i < BLOCOS_LINHA && j >= 0 && j < BLOCOS_LINHA &&
            mapa[i][j].pUniMovel == NULL &&
            mapa[i][j].pUniImovel == NULL &&
            mapa[i][j].pBase == NULL)
        return true;
    else
        return false;
}
