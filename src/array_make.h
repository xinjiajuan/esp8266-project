//
// Created by moexinjiajuan on 2022/11/2.
//

#ifndef ESP8266_PROJECT_ARRAY_MAKE_H
#define ESP8266_PROJECT_ARRAY_MAKE_H

template <typename T,std::size_t N>
constexpr std::size_t  countof(T const(&a)[N])noexcept{
    return N;
}

void CreatWifi_Epaper_Array_ICON();
void Epaper_Time_Array_Config(int Hour, int Minute,unsigned long day);
void Epaper_DHT22_Vale_Array(float Tem_Origin,float Hum_Origin,float HI);
#endif //ESP8266_PROJECT_ARRAY_MAKE_H
