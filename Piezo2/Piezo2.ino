// 피에조 PWM 핀
int spk_pin = 10;

// 4, 5옥타브 주파수
enum code { 
  o4do=261, o4re=293, o4mi=329, o4fa=349, o4sol=391, o4la =440, o4si = 493,
  o5do=523, o5re=587, o5mi=659, o5fa=698, o5sol=783, o5la =880, o5si = 987
 };

// 젓가락 행진곡
// { 계, 출력시간, 횟수 }
int song[][3] = {
  // 솔솔솔솔솔솔 솔솔솔솔솔
  // 시시시시시시 도도도도시라
  { o4sol, 200, 12},
  { o4si, 200, 6},
  { o5do, 200, 4},
  { o4si, 200, 1},
  { o4la, 200, 1},
  
  // 솔솔솔솔솔솔 솔솔솔솔솔
  // 시시시시시시 도도도도솔미도
  { o4sol, 200, 12},
  { o4si, 200, 6},
  { o5do, 200, 4},
  { o4sol, 200, 1},
  { o4mi, 200, 1},
  { o4do, 200, 1},
  
  // 주파수 0을 할당하여 쉼표 역할
  { 0, 800, 1},

  // 미레도시라솔 솔솔라솔파파파솔파미 파솔
  // 2회
  { o5mi, 400, 1},
  { o5re, 400, 1},
  { o5do, 400, 1},
  { o4si, 200, 1},
  { o4la, 400, 1},
  { o4sol, 500, 1},
  
  { o4sol, 200, 2},
  { o4la, 200, 1},
  { o4sol, 200, 1},
  { o4fa, 500, 1},
  { o4fa, 200, 2},
  { o4sol, 200, 1},
  { o4fa, 300, 1},
  { o4mi, 500, 1},
  
  { o4fa, 200, 1},
  { o4sol, 500, 1},

  { o5mi, 400, 1},
  { o5re, 400, 1},
  { o5do, 400, 1},
  { o4si, 200, 1},
  { o4la, 400, 1},
  { o4sol, 500, 1},
  
  { o4sol, 200, 2},
  { o4la, 200, 1},
  { o4sol, 200, 1},
  { o4fa, 500, 1},
  { o4fa, 200, 2},
  { o4sol, 200, 1},
  { o4fa, 300, 1},
  { o4mi, 500, 1},
  { o4mi, 300, 2},
  
  { 0, 800, 1},
  // 도솔미도
  { o5do, 200, 1},
  { o4sol, 200, 1},
  { o4mi, 200, 1},
  { o4do, 200, 1},
};

void setup() {
  pinMode(spk_pin, OUTPUT); 
}

void loop() {
  // sizeof(배열)/sizeof(배열의 첫원소)으로 전체 배열 길이를 구함
  for(int i = 0 ; i < sizeof(song)/sizeof(*song); i++){
    // 3번째 데이터의 횟수만큼 루프
    for(int j = 0 ; j < song[i][2]; j++){
      // tone 함수는 
      // tone(핀, 주파수, 출력시간)
      tone(spk_pin, song[i][0], song[i][1]);
      // 300ms 딜레이 부여
      delay(300); 
    }
  }
}