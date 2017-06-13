#ifndef SONAR_H
#define SONAR_H

void sonars_init();
unsigned get_distance(int trigPin, int echoPin);
unsigned get_sonar_distance(int sonar);

#endif
