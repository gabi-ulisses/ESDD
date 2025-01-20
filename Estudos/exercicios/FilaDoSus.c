#include <stdio.h>

typedef struct {
    int hora;
    int minuto;
    int critico;
} Paciente;

int tempoEmMinutos(int hora, int minuto) {
    return (hora - 7) * 60 + minuto;
}

int main() {
    int N;
    
    while (scanf("%d", &N) != EOF) {
        Paciente pacientes[N];
        int criticos = 0;
        
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &pacientes[i].hora, &pacientes[i].minuto, &pacientes[i].critico);
        }
        
        int tempoAtual = 0;
        for (int i = 0; i < N; i++) {
            int chegada = tempoEmMinutos(pacientes[i].hora, pacientes[i].minuto);
            int critico = pacientes[i].critico;
            
            while (tempoAtual < chegada) {
                tempoAtual += 30;
            }

            if (tempoAtual > chegada + critico) {
                criticos++;
            }

            tempoAtual += 30;
        }
        
        printf("%d\n", criticos);
    }
    
    return 0;
}