#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <chrono>

typedef std::chrono::nanoseconds TDurationNanoSecond;
typedef std::chrono::seconds TDurationSecond;
typedef std::chrono::high_resolution_clock::time_point TClock;
typedef std::chrono::high_resolution_clock Clock;

namespace Config{

void Init();

extern const int AddStairChance;
extern const int Height,Width;
extern const float StairSpeedPerSecond;
extern const TDurationNanoSecond AddStairTestTime;

}


#endif // CONFIG_H
