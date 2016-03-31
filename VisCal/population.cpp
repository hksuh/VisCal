#include "population.h"

#define LEARN_NUM 1000
#define PROGRESS_DIV 20

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
    
    /* training datas
    int readChL2(ifstream& _file, channelLayer2& _target);
    int readL1(ifstream& _file, layer1& _target);
    */
    
    /* make individuals */
    ref = new indiv[num];
    trial = new indiv[num];
    
	indiv initIndiv;

    for (int i = 0; i < num; i++){
        ref[i].init(depthF,depthR,size_frontL,size_rearL);
		ref[i].copy(initIndiv);
        trial[i].init(depthF, depthR, size_frontL, size_rearL);
		trial[i].copy(initIndiv);
    }
    
    /* maximum score for progress checking */
    max_score = 0;
}

void population::learn(T foot_size) {
    for(int i = 0; i < num; i++) {
        trial[i].mutate(foot_size);
        trial[i].calTotalScore(layers, data);
        
        if(ref[i].score > trial[i].score) {
            ref[i].copy(trial[i]);
        }
    }
}

void population::learn(unsigned int n, T foot_size) {
    int i, j, k;
    int unit = n/PROGRESS_DIV;
    int progress;
    
    /* start with same individuals */
    for(i = 0; i < num; i++) {
        trial[i].copy(ref[i]);
    }
    
    for(i = 0; i < n; i++) {
        for(j = 0; j < LEARN_NUM; j++) {
            learn(foot_size);
        }
        
        /* draw progress bar */
        if((i % unit) == 0) {
            progress = i/unit;
            printf("\r[");
            for(k = 0; k < progress; k++) {
                printf("-");
            }
            for(; k < PROGRESS_DIV; k++) {
                printf(" ");
            }
            printf("] %d%% || max score : %f", progress, max_score);
        }
    }
    cout << endl;
}

int population::shell() {
    char command;
    char yes_no;
    int number;
    T foot_size;
    int from, to;
    bool saved = false;
    //bool opened = false;
    ifstream inFile("data.txt");
    
    cout << "open(o) / save(s) / quit(q)" << endl;
    cout << "learn(l) / copy(c) / modify(m)" << endl;
    cout << "help(h) shows this message" << endl;
    
    while(1) {

        cout << "VisCal>> ";
        
        command = getchar();
        switch(command) {
            case 'l':               // learning
                cout << "number of mutation trial : ";
                cin >> number;
                cout << "size of mutation foot size : ";
                cin >> foot_size;
                learn(number, foot_size);
                saved = false;
            /*
            case 'o':               //  open
                if(opened)
                    cout << "file is already opened";
                else
                    
                    saved = true;
            */
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
                
            case 'm':
                cout << "modify index : ";
                cin >> to;
                //ref[to].copy(initIndiv); /////////????????????
                
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
                
            case 'h':
                cout << "open(o) / save(s) / quit(q)" << endl;
                cout << "learn(l) / copy(c) / modify(m)" << endl;
                cout << "help(h) shows this message" << endl;
                
            default:
                cout << "invalid input" << endl;
        }
    }
}
