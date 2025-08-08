#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <windows.h> // Para _mkdir no Windows

int main() {
    char *vestibulares[] = {"FUVEST", "UNICAMP", "UNESP", "ENEM", "ITA", "IME", "EINSTEIN", "FAMEMA", "FAMERP", "FATEC", "MACKENZIE", "MANDIC", "PUCCAMP", "PUCSP", "UEA", "UECE", "UEL", "UEM", "UEMG", "UEPG", "UERJ", "UERR", "UFAM", "UFG", "UFPR", "UFRGS", "UFRR", "UFSC", "UFSM"};
    int numVestibulares = sizeof(vestibulares) / sizeof(vestibulares[0]);
    int anos[] = {2025, 2024, 2023, 2022, 2021, 2020, 2019, 2018, 2017, 2016, 2015};
    int numAnos = sizeof(anos) / sizeof(anos[0]);
    char path[256];

    // Cria diretório base
    _mkdir("banco de Imagens");

    for (int v = 0; v < numVestibulares; v++) {
        sprintf(path, "banco de Imagens\\%s", vestibulares[v]);
        _mkdir(path);

        for (int a = 0; a < numAnos; a++) {
            sprintf(path, "banco de Imagens\\%s\\%d", vestibulares[v], anos[a]);
            _mkdir(path);

            for (int q = 1; q <= 90; q++) {
                sprintf(path, "banco de Imagens\\%s\\%d\\questao-%02d", vestibulares[v], anos[a], q);
                _mkdir(path);
            }
        }
    }

    printf("Estrutura criada com sucesso!\n");
    return 0;
}