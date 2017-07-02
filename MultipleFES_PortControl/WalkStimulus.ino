//指定周波数によるパルス出力(とりあえずプラグ４まで)
void pulseOut(int value1, int value2, int value3, int value4, int value5, int value6, int value7, int value8, int pulseWidth, int pulseInterval ) {
  int static state = 1;
  int static t1 = micros();
  int static t2 = 0;
  int static v1 = 0;
  int static v2 = 0;
  int static v3 = 0;
  int static v4 = 0;
  int static v5 = 0;
  int static v6 = 0;
  int static v7 = 0;
  int static v8 = 0;

  switch (state) {
    case 1:
      //Serial.println(v);
      t2 = micros();
      v1 = value1;
      v2 = value2;
      v3 = value3;
      v4 = value4;
      v5 = value5;
      v6 = value6;
      v7 = value7;
      v8 = value8;
      if (t2 - t1 >= pulseWidth) {
        v1 = 0;
        v2 = 0;
        v3 = 0;
        v4 = 0;
        v5 = 0;
        v6 = 0;
        v7 = 0;
        v8 = 0;
        state = 2;
        t1 = micros();
      }
      break;

    case 2:
      //Serial.println(v);
      t2 = micros();
      v1 = 0;
      v2 = 0;
      v3 = 0;
      v4 = 0;
      v5 = 0;
      v6 = 0;
      v7 = 0;
      v8 = 0;
      if (t2 - t1 >= pulseInterval) {
        v1 = value1;
        v2 = value2;
        v3 = value3;
        v4 = value4;
        v5 = value5;
        v6 = value6;
        v7 = value7;
        v8 = value8;
        state = 1;
        t1 = micros();
      }
      break;

  }
  multipleOut(1, v1);
  multipleOut(2, v2);
  multipleOut(3, v3);
  multipleOut(4, v4);
  multipleOut(5, v5);
  multipleOut(6, v6);
  multipleOut(7, v7);
  multipleOut(8, v8);
}
//stepNum周期分の歩行刺激
/*
void walkStimulus(int stepNum ) { //1:左腓腹　2:右腓腹　3:左大腿　4:右大腿
  int t = micros();
  //初めの１周期
  while (micros() - t < 1400000) {
    UDP();
    if (micros() - t <= 200000) {
      pulseOut(maxVol1, 0, 0, 0,0,0,0,0, w1, w2 );
    } else if (micros() - t > 700000 && micros() - t <= 840000) {
      pulseOut(0, maxVol2, 0, 0,0,0,0,0, w1, w2 );
    } else if (micros() - t > 840000 && micros() - t <= 900000) {
      pulseOut(0, maxVol2, maxVol3, 0,0,0,0,0, w1, w2 );
    } else if (micros() - t > 900000 && micros() - t <= 1040000) {
      pulseOut(0, 0, maxVol3, 0, 0,0,0,0,w1, w2 );
    } else {
      pulseOut(0, 0, 0, 0,0,0,0,0, w1, w2 );
    }
  }
  //2周期目
  for (int i = 0; i < stepNum; i++) {
    t = micros();
    while (micros() - t < 1400000) {
      UDP();
      if (micros() - t <= 140000) {
        pulseOut(maxVol1, 0, 0, 0,0,0,0,0, w1, w2 );
      } else if (micros() - t > 140000 && micros() - t <= 200000) {
        pulseOut(maxVol1, 0, 0, maxVol4,0,0,0,0, w1, w2 );
      } else if (micros() - t > 200000 && micros() - t <= 340000) {
        pulseOut(0, 0, 0, maxVol4,0,0,0,0, w1, w2 );
      } else if (micros() - t > 700000 && micros() - t <= 840000) {
        pulseOut(0, maxVol2, 0, 0,0,0,0,0, w1, w2 );
      } else if (micros() - t > 840000 && micros() - t <= 900000) {
        pulseOut(0, maxVol2, maxVol3, 0,0,0,0,0, w1, w2 );
      } else if (micros() - t > 900000 && micros() - t <= 1040000) {
        pulseOut(0, 0, maxVol3, 0,0,0,0,0, w1, w2 );
      } else {
        pulseOut(0, 0, 0, 0,0,0,0,0, w1, w2 );
      }

    }

  }
}
*/
