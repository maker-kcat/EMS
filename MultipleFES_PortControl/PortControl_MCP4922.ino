// ＤＡＣに出力を行う処理の関数(Port直接制御)
void DACout1(int value){
    // コマンドデータの出力
  
  PIOB->PIO_SODR = PIO_PB21; //digitalWrite(latch, HIGH) ;
  PIOA->PIO_CODR = PIO_PA10; //digitalWrite(selection, LOW) ;
  PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, destination) ; // 出力するピン(OUTA/OUTB)を選択する
  PIOA->PIO_SODR = PIO_PA11;//digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_CODR = PIO_PA12; //digitalWrite(dataPin, LOW) ;       // VREFバッファは使用しない
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;      // 出力ゲインは1倍とする
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;      // アナログ出力は有効とする
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  // ＤＡＣデータビット出力
  for (int i = 11 ; i >= 0 ; i--) {
    if (((value >> i) & 0x1) == 1) PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;
    else                           PIOA->PIO_CODR = PIO_PA12; //digitalWrite(dataPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  }
  PIOA->PIO_SODR = PIO_PA10; //digitalWrite(selection, HIGH) ;
  PIOB->PIO_CODR = PIO_PB21; //digitalWrite(latch, LOW) ; // ラッチ信号を出す(ここで実際に出力する様に指示)
}

void DACout2(int value){
    // コマンドデータの出力
  
  PIOB->PIO_SODR = PIO_PB21; //digitalWrite(latch, HIGH) ;
  PIOA->PIO_CODR = PIO_PA10; //digitalWrite(selection, LOW) ;
  PIOA->PIO_CODR = PIO_PA12; //digitalWrite(dataPin, destination) ; // 出力するピン(OUTA/OUTB)を選択する
  PIOA->PIO_SODR = PIO_PA11;//digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_CODR = PIO_PA12; //digitalWrite(dataPin, LOW) ;       // VREFバッファは使用しない
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;      // 出力ゲインは1倍とする
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;      // アナログ出力は有効とする
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  // ＤＡＣデータビット出力
  for (int i = 11 ; i >= 0 ; i--) {
    if (((value >> i) & 0x1) == 1) PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;
    else                           PIOA->PIO_CODR = PIO_PA12; //digitalWrite(dataPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  }
  PIOA->PIO_SODR = PIO_PA10; //digitalWrite(selection, HIGH) ;
  PIOB->PIO_CODR = PIO_PB21; //digitalWrite(latch, LOW) ; // ラッチ信号を出す(ここで実際に出力する様に指示)
}

void DACout3(int value){
    // コマンドデータの出力
  
  PIOB->PIO_SODR = PIO_PB21; //digitalWrite(latch, HIGH) ;
  PIOD->PIO_CODR = PIO_PD4; //digitalWrite(selection, LOW) ;
  PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, destination) ; // 出力するピン(OUTA/OUTB)を選択する
  PIOA->PIO_SODR = PIO_PA11;//digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_CODR = PIO_PA12; //digitalWrite(dataPin, LOW) ;       // VREFバッファは使用しない
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;      // 出力ゲインは1倍とする
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;      // アナログ出力は有効とする
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  // ＤＡＣデータビット出力
  for (int i = 11 ; i >= 0 ; i--) {
    if (((value >> i) & 0x1) == 1) PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;
    else                           PIOA->PIO_CODR = PIO_PA12; //digitalWrite(dataPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  }
  PIOD->PIO_SODR = PIO_PD4; //digitalWrite(selection, HIGH) ;
  PIOB->PIO_CODR = PIO_PB21; //digitalWrite(latch, LOW) ; // ラッチ信号を出す(ここで実際に出力する様に指示)
}

void DACout4(int value){
    // コマンドデータの出力
  
  PIOB->PIO_SODR = PIO_PB21; //digitalWrite(latch, HIGH) ;
  PIOD->PIO_CODR = PIO_PD4; //digitalWrite(selection, LOW) ;
  PIOA->PIO_CODR = PIO_PA12; //digitalWrite(dataPin, destination) ; // 出力するピン(OUTA/OUTB)を選択する
  PIOA->PIO_SODR = PIO_PA11;//digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_CODR = PIO_PA12; //digitalWrite(dataPin, LOW) ;       // VREFバッファは使用しない
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;      // 出力ゲインは1倍とする
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;      // アナログ出力は有効とする
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  // ＤＡＣデータビット出力
  for (int i = 11 ; i >= 0 ; i--) {
    if (((value >> i) & 0x1) == 1) PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;
    else                           PIOA->PIO_CODR = PIO_PA12; //digitalWrite(dataPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  }
  PIOD->PIO_SODR = PIO_PD4; //digitalWrite(selection, HIGH) ;
  PIOB->PIO_CODR = PIO_PB21; //digitalWrite(latch, LOW) ; // ラッチ信号を出す(ここで実際に出力する様に指示)
}

void DACout5(int value){
    // コマンドデータの出力
  
  PIOB->PIO_SODR = PIO_PB21; //digitalWrite(latch, HIGH) ;
  PIOA->PIO_CODR = PIO_PA13; //digitalWrite(selection, LOW) ;
  PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, destination) ; // 出力するピン(OUTA/OUTB)を選択する
  PIOA->PIO_SODR = PIO_PA11;//digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_CODR = PIO_PA12; //digitalWrite(dataPin, LOW) ;       // VREFバッファは使用しない
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;      // 出力ゲインは1倍とする
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;      // アナログ出力は有効とする
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  // ＤＡＣデータビット出力
  for (int i = 11 ; i >= 0 ; i--) {
    if (((value >> i) & 0x1) == 1) PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;
    else                           PIOA->PIO_CODR = PIO_PA12; //digitalWrite(dataPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  }
  PIOA->PIO_SODR = PIO_PA13; //digitalWrite(selection, HIGH) ;
  PIOB->PIO_CODR = PIO_PB21; //digitalWrite(latch, LOW) ; // ラッチ信号を出す(ここで実際に出力する様に指示)
}

void DACout6(int value){
    // コマンドデータの出力
  
  PIOB->PIO_SODR = PIO_PB21; //digitalWrite(latch, HIGH) ;
  PIOA->PIO_CODR = PIO_PA13; //digitalWrite(selection, LOW) ;
  PIOA->PIO_CODR = PIO_PA12; //digitalWrite(dataPin, destination) ; // 出力するピン(OUTA/OUTB)を選択する
  PIOA->PIO_SODR = PIO_PA11;//digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_CODR = PIO_PA12; //digitalWrite(dataPin, LOW) ;       // VREFバッファは使用しない
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;      // 出力ゲインは1倍とする
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;      // アナログ出力は有効とする
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  // ＤＡＣデータビット出力
  for (int i = 11 ; i >= 0 ; i--) {
    if (((value >> i) & 0x1) == 1) PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;
    else                           PIOA->PIO_CODR = PIO_PA12; //digitalWrite(dataPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  }
  PIOA->PIO_SODR = PIO_PA13; //digitalWrite(selection, HIGH) ;
  PIOB->PIO_CODR = PIO_PB21; //digitalWrite(latch, LOW) ; // ラッチ信号を出す(ここで実際に出力する様に指示)
}

void DACout7(int value){
    // コマンドデータの出力
  
  PIOB->PIO_SODR = PIO_PB21; //digitalWrite(latch, HIGH) ;
  PIOD->PIO_CODR = PIO_PD5; //digitalWrite(selection, LOW) ;
  PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, destination) ; // 出力するピン(OUTA/OUTB)を選択する
  PIOA->PIO_SODR = PIO_PA11;//digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_CODR = PIO_PA12; //digitalWrite(dataPin, LOW) ;       // VREFバッファは使用しない
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;      // 出力ゲインは1倍とする
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;      // アナログ出力は有効とする
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  // ＤＡＣデータビット出力
  for (int i = 11 ; i >= 0 ; i--) {
    if (((value >> i) & 0x1) == 1) PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;
    else                           PIOA->PIO_CODR = PIO_PA12; //digitalWrite(dataPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  }
  PIOD->PIO_SODR = PIO_PD5; //digitalWrite(selection, HIGH) ;
  PIOB->PIO_CODR = PIO_PB21; //digitalWrite(latch, LOW) ; // ラッチ信号を出す(ここで実際に出力する様に指示)
}

void DACout8(int value){
    // コマンドデータの出力
  
  PIOB->PIO_SODR = PIO_PB21; //digitalWrite(latch, HIGH) ;
  PIOD->PIO_CODR = PIO_PD5; //digitalWrite(selection, LOW) ;
  PIOA->PIO_CODR = PIO_PA12; //digitalWrite(dataPin, destination) ; // 出力するピン(OUTA/OUTB)を選択する
  PIOA->PIO_SODR = PIO_PA11;//digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_CODR = PIO_PA12; //digitalWrite(dataPin, LOW) ;       // VREFバッファは使用しない
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;      // 出力ゲインは1倍とする
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;      // アナログ出力は有効とする
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  // ＤＡＣデータビット出力
  for (int i = 11 ; i >= 0 ; i--) {
    if (((value >> i) & 0x1) == 1) PIOA->PIO_SODR = PIO_PA12; //digitalWrite(dataPin, HIGH) ;
    else                           PIOA->PIO_CODR = PIO_PA12; //digitalWrite(dataPin, LOW) ;
  PIOA->PIO_SODR = PIO_PA11; //digitalWrite(clockPin, HIGH) ;
  PIOA->PIO_CODR = PIO_PA11; //digitalWrite(clockPin, LOW) ;
  }
  PIOD->PIO_SODR = PIO_PD5; //digitalWrite(selection, HIGH) ;
  PIOB->PIO_CODR = PIO_PB21; //digitalWrite(latch, LOW) ; // ラッチ信号を出す(ここで実際に出力する様に指示)
}

//複数出力用関数(Port直接制御)
///////////out1～out8が8chの入力値(範囲:0～3300mV)////////////////////////////////////////
void multipleOut(int plugNum,int plugValue)
{
  //入力数値を0～4095に変換
  //int output=map(plugValue,0,3300,0,4095);
  int output=plugValue;
  switch(plugNum){
    case 1:
    //Serial.println(output);
    DACout1(output) ; // 読み込んだアナログ値を出力
    break;

    case 2:
    DACout2(output) ; // 読み込んだアナログ値を出力
    break;

    case 3:
    DACout3(output) ; // 読み込んだアナログ値を出力
    break;

    case 4:
    DACout4(output) ; // 読み込んだアナログ値を出力
    break;

    case 5:
    DACout5(output) ; // 読み込んだアナログ値を出力
    break;

    case 6:
    DACout6(output) ; // 読み込んだアナログ値を出力
    break;

    case 7:
    DACout7(output) ; // 読み込んだアナログ値を出力
    break;

    case 8:
    DACout8(output) ; // 読み込んだアナログ値を出力
    break;
  }
}
