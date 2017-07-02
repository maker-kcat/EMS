/* ＤＡＣに出力を行う処理の関数
void DACout(int dataPin, int clockPin, int destination, int value,int latch,int selection)
{
  int i;

  // コマンドデータの出力
  digitalWrite(latch, HIGH) ;
  digitalWrite(selection, LOW) ;
  digitalWrite(dataPin, destination) ; // 出力するピン(OUTA/OUTB)を選択する
  digitalWrite(clockPin, HIGH) ;
  digitalWrite(clockPin, LOW) ;
  digitalWrite(dataPin, LOW) ;       // VREFバッファは使用しない
  digitalWrite(clockPin, HIGH) ;
  digitalWrite(clockPin, LOW) ;
  digitalWrite(dataPin, HIGH) ;      // 出力ゲインは1倍とする
  digitalWrite(clockPin, HIGH) ;
  digitalWrite(clockPin, LOW) ;
  digitalWrite(dataPin, HIGH) ;      // アナログ出力は有効とする
  digitalWrite(clockPin, HIGH) ;
  digitalWrite(clockPin, LOW) ;
  // ＤＡＣデータビット出力
  for (i = 11 ; i >= 0 ; i--) {
    if (((value >> i) & 0x1) == 1) digitalWrite(dataPin, HIGH) ;
    else                           digitalWrite(dataPin, LOW) ;
  digitalWrite(clockPin, HIGH) ;
  digitalWrite(clockPin, LOW) ;
  }
  digitalWrite(selection, HIGH) ;
  digitalWrite(latch, LOW) ; // ラッチ信号を出す(ここで実際に出力する様に指示)
}

//複数出力用関数
///////////out1～out8が8chの入力値(範囲:0～3300mV)////////////////////////////////////////
void multipleOut(int dataPin, int clockPin,int latch,int selection1,int selection2,int selection3,int selection4,int plugNum,int plugValue)
{
  //入力数値を0～4095に変換
  int output=map(plugValue,0,3300,0,4095);
  switch(plugNum){
    case 1:
    //Serial.println(output);
    DACout(dataPin, clockPin, 1, output, latch, selection1) ; // 読み込んだアナログ値を出力(OUTA)
    break;

    case 2:
    DACout(dataPin, clockPin, 0, output, latch, selection1) ; // 読み込んだアナログ値を出力(OUTB)
    break;

    case 3:
    DACout(dataPin, clockPin, 1, output, latch, selection2); // 読み込んだアナログ値を出力(OUTA)
    break;

    case 4:
    DACout(dataPin, clockPin, 0,output, latch, selection2) ; // 読み込んだアナログ値を出力(OUTB)
    break;

    case 5:
    DACout(dataPin, clockPin, 1, output, latch, selection3) ; // 読み込んだアナログ値を出力(OUTA)
    break;

    case 6:
    DACout(dataPin, clockPin, 0,output, latch, selection3) ; // 読み込んだアナログ値を出力(OUTB)
    break;

    case 7:
    DACout(dataPin, clockPin, 1,output, latch, selection4) ; // 読み込んだアナログ値を出力(OUTA)
    break;

    case 8:
    DACout(dataPin, clockPin, 0,output, latch, selection4) ; // 読み込んだアナログ値を出力(OUTB)
    break;
  }
}
*/
