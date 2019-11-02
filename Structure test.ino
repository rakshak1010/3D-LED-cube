#define P0 0
#define P1 1
#define P2 2
#define C0 13
#define C1 12
#define C2 11
#define C3 10
#define C4 9
#define C5 8
#define C6 7
#define C7 6
#define C8 5
#define total_columns 9
#define total_planes 3
#define faces 3
#define mod total_planes
#define rep(i,a,b) for(int i=a;i<b;i++)
#define showFrame(a) for(int i=0;i<a;i++)


int columns[total_columns] = {13,12,11,10,9,8,7,6,5};
int planes[total_planes] = {0,1,2};
int currentBlock[total_planes][total_columns], fixedBase[total_planes][total_columns] = {
                                0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0
                              };
int blockPlane=total_planes-1, basePlane=0;

void setup() {
  pinMode(P0,OUTPUT);
  pinMode(P1,OUTPUT);
  pinMode(P2,OUTPUT);
  pinMode(C0,OUTPUT);
  pinMode(C1,OUTPUT);
  pinMode(C2,OUTPUT);
  pinMode(C3,OUTPUT);
  pinMode(C4,OUTPUT);
  pinMode(C5,OUTPUT);
  pinMode(C6,OUTPUT);
  pinMode(C7,OUTPUT);
  pinMode(C8,OUTPUT);
}

void clockPattern();    // Animation Design
void high(int );
void low(int );
void lowAll();
void setBase();
void currentPlane(int );
void createBlock();
void createBlock1x3();
void createBlock2x3();
void initialize(int[] , int );
void setBase();
void display();



void loop() {
  initialize(currentBlock,0);
  currentPlane(blockPlane);
  createBlock2x3(); // First 2x3 Block
  while(1){
    display();
    if(blockPlane==0){
      setBase();
    }
    else currentPlane(--blockPlane);
  }
  // blockPlane = total_planes-1; 
}





// FIRST ANIMATION : Glow and Turn Off all Colums in Array

// for(int i=0;i<total_columns;i++){
  //  high(columns[i]);
  //  delay(500);
  // }
  // for(int i=0;i<total_columns;i++){
  //  low(columns[i]);
  //  delay(500);
  // }


void high(int x){
  digitalWrite(x,HIGH);
}

void low(int x){
  digitalWrite(x,LOW);
}

void lowAll(){
  rep(i,0,total_columns){
    low(columns[i]);
  }
}

void setBase(){
  rep(j,0,total_planes){
    rep(i,0,total_columns){
      if(currentBlock[j][i]==1){
        fixedBase[j][i] = 1;
      }
    }
  }
}

void createBlock2x3(){
  rep(j,0,total_planes){
    if(j==total_planes-1){
      rep(i,0,total_columns){
        if(i%faces!=0){
          currentBlock[j][i]=1;
        }
      }
    }
  }
}

void createBlock1x3(){
  rep(i,0,total_columns){
    if(i%faces==0){
      currentBlock[total_planes-1][i]=1;
    }
  }
}

void currentPlane(int x){
  for(int i=0;i<total_planes;i++){
    if(planes[i]!=x){
      high(planes[i]);
    }
  }
  low(x);
  blockPlane = x;
}

void display(){
  showFrame(2000){
    rep(j,0,total_planes){
      lowAll();
      currentPlane(j);
      if(j>=blockPlane){
        rep(i,0,total_columns){
          if(currentBlock[j][i]==1){
            high(columns[i]);
            delayMicroseconds(35);
          }
        }
      }
      lowAll();
      if(j<=basePlane){
        rep(i,0,total_columns){
          if(fixedBase[j][i]==1){
            high(columns[i]),;
            delayMicroseconds(35);
          }
        }
      }
    }
  }
  lowAll();
}

void initialize(int arr[][], int value){
  rep(j,0,total_planes){
    rep(i,0,total_columns){
      arr[i] = value;
    }
  }
}


// --------  PATTERNS  -----------
// CLOCK PATTERN
void clockPattern(){
  currentPlane(P2);   // Starting Plane
  showFrame(2000){
    rep(i,0,total_columns){
      high(columns[i]);
      delayMicroseconds(35);
    }
  }
  lowAll();

  showFrame(2000){        // Land slide
    rep(i,0,total_columns){
      if(i%3==0){
        currentPlane(P2);
      }
      else{
        currentPlane(P1);
      }
        high(columns[i]);
        delayMicroseconds(20);
        low(columns[i]);
    }
  }
  showFrame(2000){    //First Diagonal
    rep(i,0,total_columns){
      if(i%3==0){
        currentPlane(P2);
      }
      else if((i+1)%3==0){
        currentPlane(P0);
      }
      else{
        currentPlane(P1);
      }
        high(columns[i]);
        delayMicroseconds(20);
        low(columns[i]);
    }
  }
  lowAll();
  showFrame(2000){    // Standing Pillar
    rep(i,0,total_columns){
      
      if((i+2)%3==0){
        high(columns[i]);
        currentPlane(P0);
        delayMicroseconds(20);
        currentPlane(P1);
        delayMicroseconds(20);
        currentPlane(P2);
        delayMicroseconds(20);
        low(columns[i]);    
      }
    }
  }
  showFrame(2000){    // Second Diagonal
    rep(i,0,total_columns){
      if(i%3==0){
        currentPlane(P0);
      }
      else if((i+1)%3==0){
        currentPlane(P2);
      }
      else{
        currentPlane(P1);
      }
        high(columns[i]);
        delayMicroseconds(20);
        low(columns[i]);
    }
  }
  lowAll();
  showFrame(2000){
    rep(i,0,total_columns){
      if((i+1)%3==0){
        currentPlane(P2);
      }
      else{
        currentPlane(P1);
      }
        high(columns[i]);
        delayMicroseconds(20);
        low(columns[i]);
    }
  }
}

// Cross Moving in all Planes
void crossFalling(){
  while(1){
      for (int i = 0; i < total_columns; i+=2){
        high(columns[i]);
        delayMicroseconds(20);
      }
      delay(1000);
      currentPlane((--blockPlane+3)%3);
    }
}

