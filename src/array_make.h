//
// Created by moexinjiajuan on 2022/11/2.
//

#ifndef ESP8266_PROJECT_ARRAY_MAKE_H
#define ESP8266_PROJECT_ARRAY_MAKE_H

class EpaperArray {
private:
    unsigned char gImage_EA_BW[4000];
    unsigned char gImage_EA_R[4000];
    void Creat_Time_Number_Array(int vale, int location);
    int Creat_Number_Array(int vale, int start_local);
    int Creat_DecimalPoint_Array(int local);
    int CreatLettersArray(int vale,int local);
    void Epaper_Wifi_Config(int wifi_status);
    int GetLettersID(int ascii);
    void Creat_BMP180_Unit_array(int type,int startlocal);
public:
    void CreatWifi_Epaper_Array_ICON();
    void Epaper_Time_Array_Config(unsigned long EpochTime);
    void Epaper_DHT22_Vale_Array(float Tem_Origin, float Hum_Origin, float HI);
    void Epaper_BMP180_Vale_Array(int pressure, float temp, float altitude);
    void Epaper_Array_init();
    unsigned char * Return_gImage_BW();
    unsigned char * Return_gImage_R();

    //constexpr size_t countof(const T (&a)[N]) noexcept;
};

template<typename T, std::size_t N>
constexpr std::size_t countof(T const(&a)[N]) noexcept {
    return N;
}

//extern unsigned char gImage_BW_USE[4000];
//extern unsigned char gImage_R_USE[4000];

//void CreatWifi_Epaper_Array_ICON();
//
//void Epaper_Time_Array_Config(int Hour, int Minute, unsigned long day);
//
//void Epaper_DHT22_Vale_Array(float Tem_Origin, float Hum_Origin, float HI);
//
//void Epaper_BMP180_Vale_Array(int pressure, float temp, float altitude);
//
//void Epaper_Array_init();

#endif //ESP8266_PROJECT_ARRAY_MAKE_H
