#include <stdio.h>
#include <string.h>

#define START 1
#define END 3
 
/*
ST | 00 | 01 
---+----+----
q0 | q2 | q1
q1 | q3 | q0
q2 | q0 | q3
q3 | q1 | q2
*/

void render_plane(int instruction, int pivot) {

    // arf my puppy life

    if (pivot == 0) {
        printf("    #######            .......\n");
        printf("    #     #  ---0--->  .     .            # - aktywny stan\n");
        printf("    #  0  #            .  2  .            . - nieaktywny stan\n");
        if (instruction == 0) {
            printf("    #     #  <--[0]--  .     .            0 - przejscie \n");       
        } else {
            printf("    #     #  <---0---  .     .            0 - przejscie \n");       
        }
        printf("    #######            .......            [0] - aktywne przejscie \n");
    } else if (pivot == 2) {
        printf("    .......            #######\n");
        if (instruction == 0) {
            printf("    .     .  --[0]-->  #     #            # - aktywny stan\n");
        } else {
            printf("    .     .  ---0--->  #     #            # - aktywny stan\n");
        }
        printf("    .  0  .            #  2  #            . - nieaktywny stan\n");
        printf("    .     .  <---0---  #     #            0 - przejscie \n");       
        printf("    .......            #######            [0] - aktywne przejscie \n");
    } else {
        printf("    .......            .......\n");
        printf("    .     .  ---0--->  .     .            # - aktywny stan\n");
        printf("    .  0  .            .  2  .            . - nieaktywny stan\n");
        printf("    .     .  <---0---  .     .            0 - przejscie \n");       
        printf("    .......            .......            [0] - aktywne przejscie \n");
    }

    printf("\n");
    printf("      ^ |                ^ |\n");

    if (instruction == 1) {

        if (pivot == 0) {
            printf("      | 1                | 1\n");
            printf("     [1]|                1 |\n");
        } else if (pivot == 1) {
            printf("      |[1]               | 1\n");
            printf("      1 |                1 |\n");
        } else if (pivot == 2) {
            printf("      | 1                | 1\n");
            printf("      1 |               [1]|\n");
        } else if (pivot == 3) {
            printf("      | 1                |[1]\n");
            printf("      1 |                1 |\n");
        }

    } else {
        printf("      | 1                | 1\n");
        printf("      1 |                1 |\n");
    }
    
    printf("      | v                | v\n");
    printf("\n");

    if (pivot == 1) {
        printf("    #######            .......\n");
        printf("    #     #  ---0--->  .     .\n");
        printf("    #  1  #            .  3  .\n");
        if (instruction == 0) {
            printf("    #     #  <--[0]--  .     .\n");       
        } else {
            printf("    #     #  <---0---  .     .\n");       
        }
        printf("    #######            .......\n");
    } else if (pivot == 3) {
        printf("    .......            #######\n");
        if (instruction == 0) {
            printf("    .     .  --[0]-->  #     #\n");
        } else {
            printf("    .     .  ---0--->  #     #\n");
        }
        printf("    .  1  .            #  3  #\n");
        printf("    .     .  <---0---  #     #\n");       
        printf("    .......            #######\n");
    } else {
        printf("    .......            .......\n");
        printf("    .     .  ---0--->  .     .\n");
        printf("    .  1  .            .  3  .\n");
        printf("    .     .  <---0---  .     .\n");       
        printf("    .......            .......\n");
    }

    printf("\n----------------------------------\n");

}

int process_instruction(int instruction, int pivot) {

    switch (pivot) {
                               // if 1 / 0
        case 0: return instruction ? 1 : 2;
        case 1: return instruction ? 0 : 3;
        case 2: return instruction ? 3 : 0;
        case 3: return instruction ? 2 : 1;
        default: return -1;
    }

}

int main(int argc, char* argv[]) {

    int pivot = START;
    render_plane(-1, pivot);
    
    if (argc < 2) {

        char c;
        printf("Tryb wpisywania danych recznie, wpisz 0, 1 lub e aby zakonczyc:\n");

        while( scanf("%c", &c) && c != 'e' ) {

            if (c != '0' && c != '1') {
                if (c != '\n')
                    printf("Wykryto niewlasciwa instrukcje! (%c) Ignorujemy...\n", c);
                continue;
            }

            int instruction = c == '0' ? 0 : 1;
            pivot = process_instruction(instruction, pivot);

            render_plane(instruction, pivot);
            printf("PORUSZONO DO q%d UZYWAJAC %d\n\n", pivot, instruction);
            
        }

    } else {
        
        char* input = argv[1];
        int n = strlen(input);
        
        for (int i = 0; i < n ; i++) {
            
            scanf("%c");
            if (input[i] != '0' && input[i] != '1') {
                render_plane(-1, pivot);
                printf("Wykryto niewlasciwa instrukcje! (%c) Ignorujemy...\n", input[i]);
                continue;
            }

            int instruction = input[i] == '0' ? 0 : 1;
            pivot = process_instruction(instruction, pivot);
    
            render_plane(instruction, pivot);
            printf("Poruszono do (q%d) uzywajac %d\n", pivot, instruction);
     
        }
    }

 
    printf("Operacja zakonczyla sie na etapie %d.\n", pivot);

    if (pivot == END) {
        printf("Gratulujemy! Ciag zostal zaakceptowany.\n");
    }
 
    return 0;
 
}