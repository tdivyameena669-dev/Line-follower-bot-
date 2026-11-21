#define MAspeed 3
#define MBspeed 9
#define MAF 5
#define MAB 4
#define stdby 6
#define MBF 8
#define MBB 7
#define S0 A5
#define S1 A3
#define S2 A2
#define S3 A1 //green gray violet red empty white empty empty power 
#define S4 A0
#define B 1
#define W 0


int sen_arr[5]={S0,S1,S2,S3,S4};
int w_arr[5]={-20, -10, 0, 10, 20};
float error;
float kp=4;
float kd=5;
float correction;
float P,D;
float prev_error=0;
int basespeed=100;
int maxspeed=255;
int l_speed,r_speed;

void setup()
{Serial.begin(9600);
  pinMode(MAspeed, OUTPUT);
  pinMode(MBspeed, OUTPUT);
  pinMode(MAF, OUTPUT);
  pinMode(MAB, OUTPUT);
  pinMode(MBF, OUTPUT);
  pinMode(MBB, OUTPUT);
  pinMode(S0, INPUT);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(stdby, OUTPUT);

  digitalWrite(MAF, HIGH);
  digitalWrite(MAB, LOW);
  digitalWrite(MBF, HIGH);
  digitalWrite(MBB, LOW);
  digitalWrite(stdby, HIGH);
}

void loop()
{
  detect_error();
  pid(); 
  l_speed = constrain(basespeed - correction, 0, maxspeed);
  r_speed = constrain(basespeed + correction, 0, maxspeed);
  analogWrite(MAspeed, l_speed);
  analogWrite(MBspeed, r_speed);
  Serial.println(l_speed);
  Serial.println(r_speed);

}

void detect_error()
{
  Serial.println("detecterror");
  int w = 0;
  float num_error = 0, den_error = 0;
  int r = 0;

  for(int i =0 ; i<=4 ; i++)
  {
    r = !digitalRead(sen_arr[i]);
    num_error += r*w_arr[i];
    den_error += r ;
  }
  if (den_error==0)
    stop();
  error = num_error/den_error;
}

void pid()
{
  Serial.println("pid");
  P = error;
  D = error - prev_error;
  correction=(kp*P)+(kd*D);
  prev_error=error;
}

void stop()
{
  Serial.println("stop");
  analogWrite(MAspeed, 0);
  analogWrite(MBspeed, 0);
  detect_error();
}