#include <SPI.h>
#include <RH_NRF24.h>

RH_NRF24 nrf24;
uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];
uint8_t len = sizeof(buf);
uint8_t data[] = "Testing_2";
void setup() {
  Serial.begin(9600);
  nrf24.init();
  nrf24.setChannel(5);
  nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm);
}

void loop() {
  if (nrf24.recv(buf, &len)) {
    Serial.print("Got a Request :  ");
    Serial.println((char*)buf);
    delay(50);
    Serial.println("Send Reply !");
    nrf24.send(data, sizeof(data));
    Serial.println("    ");
    nrf24.waitPacketSent();
  }

}
