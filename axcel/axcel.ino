const int X = 0;
const int Y = 2;
const int Z = 4;
void setup()
{
  // シリアルモニターの初期化をする
  Serial.begin(9600) ;
}
void loop()
{
  int i , a ;
  long x , y , z ;

  // 各データを100回読込んで平均化する
  x = y = z = 0 ;
  for (i = 0 ; i < 100 ; i++) {
    x = x + analogRead(X) ;  // Ｘ軸を読込む
    y = y + analogRead(Y) ;  // Ｙ軸を読込む
    z = z + analogRead(Z) ;  // Ｚ軸を読込む
  }
  x = x / 100 ;
  y = y / 100 ;
  z = z / 100 ;
  // 角度を計算して表示を行う
  a = atan2(x - 507, z - 558) / 3.14159 * 180.0 ;
  String s;
  s = String(a);
  s.concat(",");
  a = atan2(y - 520, z - 558) / 3.14159 * 180.0 ;
  s.concat(String(a));
  Serial.println(s) ;           // Y軸方向角度表示
  //Serial.println(String(rundom(300));
  delay(33) ;
}
