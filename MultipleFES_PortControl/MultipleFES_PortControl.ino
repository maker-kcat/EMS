

/**************************************************************************************/
#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet2.h>
#include <EthernetUdp2.h>         // UDP library from: bjoern@cs.stanford.edu 12/30/2008
#define UDP_TX_PACKET_MAX_SIZE 60 //increase UDP size
/**************************************************************************************/

/***********************EtherNetによるUDP関連******************************************/
/**************************************************************************************/


// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
  0x90, 0xA2, 0xDA, 0x0F, 0xF9, 0x9A
};
IPAddress ip(133, 10, 79, 170);

unsigned int localPort = 61000;      // local port to listen on

// buffers for receiving and sending data
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];  //buffer to hold incoming packet,
char  ReplyBuffer[] = "acknowledged";       // a string to send back
int DataNum=10;//Unityから受け取るデータの個数
float RecData[10];//配列数はDataNum
String fromIP;
String hostIP;//ArduinoのIPを代入
// An EthernetUDP instance to let us send and receive packets over UDP
EthernetUDP Udp;

/**************************************************************************************/
#define DA_SCK   18           // クロック信号出力ピン
#define DA_SDI   17           // データ信号出力ピン
#define DA_CS1   19           // 選択動作出力ピン
#define DA_CS2   14           // 選択動作出力ピン
#define DA_CS3   16           // 選択動作出力ピン
#define DA_CS4   15           // 選択動作出力ピン
#define DA_LDAC  52           // ラッチ動作出力ピン
int x;//アナログ読み取り値
//int maxVol;//入力電圧(mV)(0-4095)
int maxVol[8]={};
float ch[8]={};
int w1;//パルス幅
int w2;//パルス間隔
int recNum=0;;
String keyWord;


void setup() {
  EtherNetUDPsetup();
  
  //マイコンボードの分解能を12bitに変更
  analogReadResolution(12);

  // 制御するピンは全て出力に設定する
  pinMode(DA_SCK, OUTPUT) ;
  pinMode(DA_SDI, OUTPUT) ;
  pinMode(DA_LDAC, OUTPUT) ;
  pinMode(DA_CS1,  OUTPUT) ;
  pinMode(DA_CS2,  OUTPUT) ;
  pinMode(DA_CS3,  OUTPUT) ;
  pinMode(DA_CS4,  OUTPUT) ;
  // 出力ピンの初期化
  digitalWrite(DA_SCK, LOW) ;
}
void loop() {
  UDP();
  if(recNum==1){
    pulseOut(maxVol[0],maxVol[1],maxVol[2],maxVol[3],maxVol[4],maxVol[5],maxVol[6],maxVol[7], w1, w2 );
  }else if(recNum==0){
    pulseOut(maxVol[0]*ch[0],maxVol[1]*ch[1],maxVol[2]*ch[2],maxVol[3]*ch[3],maxVol[4]*ch[4],maxVol[5]*ch[5],maxVol[6]*ch[6],maxVol[7]*ch[7], w1, w2 );
    //pulseOut(0,0,0,0,0,0,0,0, w1, w2 );
  }
}

void EtherNetUDPsetup(){
  /**********************EtherNetのsetup部分******************************************/
  // start the Ethernet and UDP:
  Ethernet.begin(mac, ip);
  Udp.begin(localPort);
  recNum=0;
  Serial.begin(115200);
  /***********************************************************************************/
  
}

void UDP(){
  /**********************EtherNetのloop部分******************************************/
  // if there's data available, read a packet
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    //Serial.print("Received packet of size ");
    //Serial.println(packetSize);
    //Serial.print("From ");
    IPAddress remote = Udp.remoteIP();
    for (int i = 0; i < 4; i++) {
      //Serial.print(remote[i], DEC);
      fromIP+=(String)remote[i];
      hostIP+=(String)ip[i];
      
      if (i < 3) {
        //Serial.print(".");
        fromIP+=".";
        hostIP+=".";
      }
    }
    //Serial.println(fromIP);
    //Serial.print(", port ");
    //Serial.println(Udp.remotePort());
    //read the packet into packetBufffer
    Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);
    //Serial.println(packetBuffer);
    //Serial.println("Contents:");
    //Serial.println(packetBuffer);
    keyWord=strtok(packetBuffer,",");
    for(int i=0;i<DataNum;i++){
      RecData[i]=atof(strtok(NULL,","));
    }
    
    //Serial.println(receiveIP);
    
    if(keyWord=="Controller"){
      
      for(int i=0;i<8;i++){
        maxVol[i]=RecData[i];
      }
      w1=RecData[8];
      w2=RecData[9];
      /*
      maxVol1=RecData[0];
      maxVol2=RecData[1];
      maxVol3=RecData[2];
      maxVol4=RecData[3];
      maxVol5=RecData[4];
      maxVol6=RecData[5];
      maxVol7=RecData[6];
      maxVol8=RecData[7];
      */
      
      
      Serial.print(RecData[0]);
      Serial.print(",");
      Serial.print(RecData[1]);
      Serial.print(",");
      Serial.print(RecData[2]);
      Serial.print(",");
      Serial.print(RecData[3]);
      Serial.print(",");
      Serial.print(RecData[4]);
      Serial.print(",");
      Serial.print(RecData[5]);
      Serial.print(",");
      Serial.print(RecData[6]);
      Serial.print(",");
      Serial.print(RecData[7]);
      Serial.print(",");
      Serial.print(RecData[8]);
      Serial.print(",");
      Serial.println(RecData[9]);
      
    
    }else if(keyWord=="PCServer"){
      Serial.print(RecData[0]);
      Serial.print(",");
      Serial.print(RecData[1]);
      Serial.print(",");
      Serial.print(RecData[2]);
      Serial.print(",");
      Serial.print(RecData[3]);
      Serial.print(",");
      Serial.print(RecData[4]);
      Serial.print(",");
      Serial.print(RecData[5]);
      Serial.print(",");
      Serial.print(RecData[6]);
      Serial.print(",");
      Serial.print(RecData[7]);
      Serial.print(",");
      Serial.print(RecData[8]);
      Serial.print(",");
      Serial.println(RecData[9]);
      for(int i=0;i<8;i++){
        ch[i]=RecData[i];
      }
    }else if(keyWord=="mode"){
      recNum=RecData[0];
      //recNum=atoi(packetBuffer);//受信データをintに変換
      Serial.println(recNum);
    }else Serial.println(packetBuffer);
    // send a reply to the IP address and port that sent us the packet we received
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write(ReplyBuffer);
    Udp.endPacket();
    fromIP="";//fromIP初期化
    hostIP="";
  }
}
