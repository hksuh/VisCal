#include "population.h"

#define LEARN_NUM 1
#define PROGRESS_DIV 1

population::population(){
    /* initialize size information*/
    num = 4;

	init.preset();
	init.presetRead();

	depthF = init.depthF;
	depthR = init.depthR;
	size_frontL = init.size_frontL;
	size_rearL = init.size_rearL;

	cout << size_frontL[0][1] << endl;

    /* make layers */
    layers.frontL = new channelLayer2[depthF];
	for (int i = 0; i < depthF; i++){
		layers.frontL[i] = new layer2[size_frontL[i][0]];
		for (int j = 0; j < size_frontL[i][0]; j++){
			layers.frontL[i][j].init(size_frontL[i][1], size_frontL[i][2]);
		}
	}
    layers.rearL = new layer1[depthR+1];
	for (int i = 0; i < depthR+1; i++){
		layers.rearL[i].init(size_rearL[i]);
	}
    
    /* training datas
    int readChL2(ifstream& _file, channelLayer2& _target);
    int readL1(ifstream& _file, layer1& _target);
    */
    
    /* make individuals */
    ref = new indiv[num];
    trial = new indiv[num];

    for (int i = 0; i < num; i++){
        //ref[i].init(depthF,depthR,size_frontL,size_rearL);
		ref[i].preset();
		ref[i].presetRead();
		//ref[i].copy(init);
        //trial[i].init(depthF, depthR, size_frontL, size_rearL);
		trial[i].preset();
		trial[i].presetRead();
		//trial[i].copy(init);
    }
    
    /* maximum score for progress checking */
    max_score = 0;
}

void population::learn(T foot_size) {
    for(int i = 0; i < num; i++) {
        trial[i].mutate(foot_size,2);
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

void population::learnTemp(unsigned int n, T foot_size) {
	int i = 0;

	/* start with same individuals */
	for (i = 0; i < num; i++) {
		trial[i].copy(ref[i]);
	}

	for (i = 0; i < n; i++) {
		learn(foot_size);
		if (i % 30 == 0){
			//print result temporary part
			for (int qw = 0; qw < num; qw++){
				ref[qw].calTotalScore(layers, data);
				cout << "[" << qw << "] : " << ref[qw].score << endl;
			}
			//
		}
	}
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
        
        cin>>command;
        switch(command) {
            case 'l':               // learning
                cout << "number of mutation trial : ";
                cin >> number;
                cout << "size of mutation foot size : ";
                cin >> foot_size;
                //learn(number, foot_size);
				learnTemp(number, foot_size);
                saved = false;
                break;
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
                break;
                
            case 'c':               //  copy
                cout << "copy from : ";
                cin >> from;
                cout << "copy to : ";
                cin >> to;
                ref[from].copy(ref[to]);
                saved = false;
                break;
                
            case 'm':
                cout << "modify index : ";
                cin >> to;
                //ref[to].copy(initIndiv); /////////????????????
                break;
                
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
                break;
                
            case 'h':
                cout << "open(o) / save(s) / quit(q)" << endl;
                cout << "learn(l) / copy(c) / modify(m)" << endl;
                cout << "help(h) shows this message" << endl;
                break;
                
            default:
                cout << "invalid input" << endl;
        }
    }
}
