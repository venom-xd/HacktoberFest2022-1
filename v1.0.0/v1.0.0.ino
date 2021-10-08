#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>

#include <SD.h>
#define SD_ChipSelectPin 4
#include <SPI.h>

TMRpcm tmrpcm;

void setup(){
tmrpcm.speakerPin = 9;
Serial.begin(9600);
if (!SD.begin(SD_ChipSelectPin)) {
Serial.println("SD fail");
return;
}else
{
  Serial.println("SD UP!");
}

tmrpcm.setVolume(10);
tmrpcm.play("file.wav");

}

void loop(){  }
