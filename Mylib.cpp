//
//  Mylib.cpp
//  
//
//  Created by 동교 이 on 2015. 3. 18..
//
//

#include "Mylib.h"

FILE* openfileread (char* filename) {
    
    FILE *fp;
    
    fp = fopen(filename, "r");
    
    if(!fp) {
        fprintf(stderr,"Cannot read the file\n");
        exit(EXIT_FAILURE);
    }
    
    return fp;
}

FILE* openfilewrite (char* filename) {
    
    FILE *fp;
    
    fp = fopen(filename, "w");
    
    if(!fp) {
        fprintf(stderr,"Cannot read the file\n");
        exit(EXIT_FAILURE);
    }
    
    return fp;
}

