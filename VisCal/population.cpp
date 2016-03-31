#include "population.h"

population::population(){
    /* initialize size information*/
    num = 30;
    depthF = 2;
    depthR = 3;
    
    /* set size information */
    size_frontL = new unsigned int*[depthF];
    size_rearL = new unsigned int[depthR+1];
    
    for (int i = 0; i < depthF; i++) {
        size_frontL[i] = new unsigned int[3];
    }
    size_frontL[0][0] = 16;
    size_frontL[0][1] = 8;
    size_frontL[0][2] = 8;
    size_frontL[1][0] = 32;
    size_frontL[1][1] = 1;
    size_frontL[1][2] = 1;
    
    size_rearL[0] = size_frontL[depthF - 1][0];
    size_rearL[1] = 6;
    size_rearL[2] = 6;
    size_rearL[3] = 1;

    /* make layers */
    layers.frontL = new channelLayer2[depthF];
    layers.rearL = new layer1[depthR];
    
    
    /* training datas */
    int readChL2(ifstream& _file, channelLayer2& _target);
    int readL1(ifstream& _file, layer1& _target);
    
    /* make individuals */
    ref = new indiv[num];
    trial = new indiv[num];
    
	indiv initIndiv;
	foot = 0.3;

    for (int i = 0; i < num; i++){
        ref[i].init(depthF,depthR,size_frontL,size_rearL);
		ref[i].copy(initIndiv);
        trial[i].init(depthF, depthR, size_frontL, size_rearL);
		trial[i].copy(initIndiv);
    }
    
    /* import training data */
    //data = txtIn
}

void population::learn(T foot_size) {
    for(int i = 0; i < num; i++) {
        ref[i].mutate(foot_size);
        trial[i].calTotalScore(layers, data);
        
        if(ref[i].score < trial[i].score) {
            ref[i].copy(trial[i]);
            cout << "ref[" << i << "]:" << ref[i].score << endl;
        }
    }
}

void population::learn(unsigned int n, T foot_size) {
    for(int i = 0; i < n; i++) {
        learn(foot_size);
    }
}

int population::shell() {
    char command;
    char yes_no;
    int number;
    T foot_size;
    int from, to;
    bool saved = false;
    
    while(1) {
        cout << "learn(l) / open(o) / save(s) / copy(c) / quit(q)" << endl;
        command = getchar();
        switch(command) {
            case 'l':               // learning
                cout << "number of mutation trial : ";
                cin >> number;
                cout << "size of mutation foot size : ";
                cin >> foot_size;
                learn(number);
                saved = false;
                
            case 'o':               //  open
                // ???
                saved = true;
                
            case 's':               //  save
                // ???
                saved = true;
                
            case 'c':               //  copy
                cout << "copy from : ";
                cin >> from;
                cout << "copy to : ";
                cin >> to;
                ref[from].copy(ref[to]);
                saved = false;
                
            case 'q':
                if(saved) {
                    break;
                }
                else {
                    cout << "quit without save?";
                    yes_no = getchar();
                    if(yes_no == 'y') {
                        break;
                    }
                    else if(yes_no == 'n') {
                        continue;
                    }
                    else
                        cout << "invalid input" << endl;
                }
                
            default:
                cout << "invalid input" << endl;
        }
    }
}
