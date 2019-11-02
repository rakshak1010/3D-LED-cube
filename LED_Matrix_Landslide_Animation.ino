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
#define mod total_planes
#define rep(i,a,b) for(int i=a;i<b;i++)
#define showFrame() for(int i=0;i<2000;i++)


int columns[9] = {13,12,11,10,9,8,7,6,5};
int planes[3] = {0,1,2};
int onPlane;

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

void currentPlane(int x){
  for(int i=0;i<total_planes;i++){
    if(planes[i]!=x){
      high(planes[i]);
    }
  }
  low(x);
  onPlane = x;
}

void loop() {  
  
  currentPlane(P2);   // Starting Plane
  showFrame(){
    rep(i,0,total_columns){
      high(columns[i]);
      delayMicroseconds(35);
    }
  }
  lowAll();

  showFrame(){        // Land slide
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
  showFrame(){    //First Diagonal
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
  showFrame(){    // Standing Pillar
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
  showFrame(){    // Second Diagonal
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
  showFrame(){
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









// FIRST ANIMATION : Glow and Turn Off all Colums in Array

// for(int i=0;i<total_columns;i++){
  //  high(columns[i]);
  //  delay(500);
  // }
  // for(int i=0;i<total_columns;i++){
  //  low(columns[i]);
  //  delay(500);
  // }

// Cross Moving in all Planes
// while(1){
  //  for (int i = 0; i < total_columns; i+=2){
  //    high(columns[i]);
  //    delayMicroseconds(20);
  //  }
  //  delay(1000);
  //  currentPlane((--onPlane+3)%3);
  // } 
