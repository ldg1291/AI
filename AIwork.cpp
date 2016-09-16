#include "AIwork.h"
#include "Mylib.h"
#define CONST 0.9
#define AND 10
#define OR  20
#define XOR 30

AIwork::AIwork(int type) {
    
    op = type;
    
    x[0].first = 0;
    x[0].second = 0;
    
    x[1].first = 0;
    x[1].second = 1;
    
    x[2].first = 1;
    x[2].second = 0;
    
    x[3].first = 1;
    x[3].second = 1;
    
    w[0] = rand()%4;
    w[1] = rand()%4;
    w[2] = rand()%4;
    
    theta = 0;
    
    delta_w[0] = 0;
    delta_w[1] = 0;
    delta_w[2] = 0;
    
    switch (type) {
        case AND :
            correctset[0] = 0;
            correctset[1] = 0;
            correctset[2] = 0;
            correctset[3] = 1;
            break;
        case OR :
            correctset[0] = 0;
            correctset[1] = 1;
            correctset[2] = 1;
            correctset[3] = 1;
            break;
        case XOR :
            correctset[0] = 0;
            correctset[1] = 1;
            correctset[2] = 1;
            correctset[3] = 0;
            break;
    }
}

void AIwork:: do_work() {
    switch(op) {
        case AND :
            fp = openfilewrite("/Users/Shared/Documents/XCode/AI/AI HomeWork1/AND_Result.txt");
            fprintf (fp, "AND gate Learning...\n");
            break;
        case OR :
            fp = openfilewrite("/Users/Shared/Documents/XCode/AI/AI HomeWork1/OR_Result.txt");
            fprintf (fp, "OR gate Learning...\n");
            break;
        case XOR :
            fp = openfilewrite("/Users/Shared/Documents/XCode/AI/AI HomeWork1/XOR_Result.txt");
            fprintf (fp, "OR gate Learning...\n");
            break;
    }
    int count = 1;
    do {
        if(count > 10) {
            fprintf(fp, "TOO MANY CALCUATE, USE OTHER SETTINGS\n");
            return;
        }
        fprintf(fp, "Rotate %d \n", count ++);
        for(int i=0; i<4; i++) {
            fprintf(fp, "SET %d : x1 = %d, x2 = %d, w0 = %.2f, w1 = %.2f, w2 = %.2f\n", i+1, x[i].first, x[i].second, w[0], w[1], w[2]);
            resultset[i] = calculate(x[i], w);
            fprintf(fp, "CALCULATE : %d\n", resultset[i]);
            fprintf(fp, "CORRECT : %d\n", correctset[i]);
            error[i] = find_error(correctset[i], resultset[i]);
            fprintf(fp, "ERROR : %d\n", error[i]);
            delta_w[0] = find_delta(-1, correctset[i] - resultset[i]);
            delta_w[1] = find_delta(x[i].first, correctset[i] - resultset[i]);
            delta_w[2] = find_delta(x[i].second, correctset[i] - resultset[i]);
            re_size();
            fprintf(fp, "RESULT %d : x1 = %d, x2 = %d, w0 = %.2f, w1 = %.2f, w2 = %.2f\n\n", i+1, x[i].first, x[i].second, w[0], w[1], w[2]);
        }
        
    } while(errsum());
    fprintf(fp, "\nCALCULATE FINISHED\n");
    fprintf(fp, "RESULT of w are w0 = %f, w1 = %f, w2 = %f", w[0], w[1], w[2]);
    
}

AIwork::AIwork (const AIwork& ai) {
    
}

int AIwork::calculate(pair <int, int> x, float w[3]) {
    
    float tmp = -1*w[0] + x.first*w[1] + x.second*w[2];
    
    if(tmp > theta)
        return 1;
    
    return 0;
}

float AIwork::find_delta(int x, int err) {
    return CONST*x*err;
}

int AIwork::find_error(int r, int c) {
    return c-r;
}

int AIwork::errsum() {
    return abs(error[0]) + abs(error[1]) + abs(error[3]) + abs(error[2]);
}

void AIwork::re_size() {
    for(int i=0; i<3; i++)
        w[i] += delta_w[i];
}




