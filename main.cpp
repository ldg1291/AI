#include <stdio.h>
#define CONST 0.5

class AIwork {

public :
    
    int x;
    int w[3];
    float theta;
    float error[4];
    float delta_w[3];
    bool correctset[4];
    bool resultset[4];

    
    AIwork() {
        x = -1;
        
        w[0] = 1;
        w[1] = 2;
        w[2] = 3;
        
        theta = 1.5;

        delta_w[0] = 0;
        delta_w[1] = 0;
        delta_w[2] = 0;
        
        error[0] = 0;
        error[1] = 0;
        error[2] = 0;
        error[3] = 0;
        
        correctset[0] = 0;
        correctset[1] = 0;
        correctset[2] = 0;
        correctset[3] = 1;
    }
 
private :
    
    AIwork (const AIwork& ai) {
        
    }
    
    void do_work() {
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                resultset[i*2+j] = x*w[0] + i*w[1] + j*w[2];
            }
        }
    }
    
    
    // DWk = c*(Yj-f(X)j)*Xjk
    void check_result() {
        
        for(int i=0; i<3; i++ ) {
            delta_w[i] = CONST*(error[i] = (resultset[i] - correctset[i]));
        }
    }
    
    void re_sizing() {
        for(int i=0; i<3; i++)
          w[i] += delta_w[i];
    }
    
public:
    int sum(int arr[]) {
        int tmp=0;
        
        for(int i=0; i<sizeof(arr) ; i++) {
            tmp += arr[i];
        }
        
        return tmp;
    }
};

int main(int argc, const char * argv[]) {
    
    AIwork work;
    
    int tmp[] = {1,2,3,4,5,6,7,8,9,10};
    
    return 0;
}
