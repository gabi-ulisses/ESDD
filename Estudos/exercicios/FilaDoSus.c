#include <stdio.h>

typedef struct {
    int hora;
    int minuto;
    int critico;
} Paciente;

int tempoEmMinutos(int hora, int minuto) {
    return hora * 60 + minuto;
}

int main() {
    int N;
    
    while (scanf("%d", &N) != EOF) {
        Paciente pacientes[N];
        int criticos = 0;
        
        // Leitura dos pacientes
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &pacientes[i].hora, &pacientes[i].minuto, &pacientes[i].critico);
        }
        
        int tempoAtual = 7 * 60; // A triagem começa às 7h da manhã em minutos
        for (int i = 0; i < N; i++) {
            int chegada = tempoEmMinutos(pacientes[i].hora, pacientes[i].minuto);
            int critico = pacientes[i].critico;
            
            // Verificar se o paciente atingiu a condição crítica enquanto espera
            if (chegada + critico > tempoAtual) {
                criticos++;
            }
            
            // O atendimento é feito a cada 30 minutos
            while (tempoAtual < chegada) {
                tempoAtual += 30;
            }
            
            tempoAtual += 30;
        }
        
        // Resultado para o caso atual
        printf("%d\n", criticos);
    }
    
    return 0;
}