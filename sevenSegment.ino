const int pins[4][4] = {{22,23,24,25},{26,27,28,29},{30,31,32,33},{34,35,36,37}};    //Output pins to seven segment BCD Display     
byte BCD[10][4] ={{0,0,0,0}, //0
{1,0,0,0}, //1
{0,1,0,0}, //2
{1,1,0,0}, //3
{0,0,1,0}, //4
{1,0,1,0}, //5
{0,1,1,0}, //6
{1,1,1,0}, //7
{0,0,0,1}, //8
{1,0,0,1}}; //9
String Time="2030";            //********** initial time in "HrHrMinMin" (24 Hr format) ***********
int a=Time.charAt(0)-'0',b=Time.charAt(1)-'0',c=Time.charAt(2)-'0',i=Time.charAt(3)-'0';
void disp(int place,int num){
  for(int i=0;i<4;i++)
  digitalWrite(pins[place][i],BCD[num][i]);
}
void setup(){
for(int i=0;i<4;i++)
for(int j=0;j<4;j++)
pinMode(pins[i][j],OUTPUT);
}
void loop(){
  for(;a<3;a++){
    for(;b<10;b++){
      for(;c<6;c++){
        for(;i<10;i++){
          disp(0,i);disp(1,c);disp(2,b);disp(3,a);
          delay(60000);                            // 1 minute delay
          if(b==4 and a==2){
            a=0;b=0;c=0;
          }
        }
        i=0; 
      }
      c=0;
    }
    b=0;
  }
}
