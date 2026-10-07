//
// Created by daschoe on 10/6/26.
//
// DayTime.h
// Die Klasse DayTime mit den Operatoren < und ++ .
// ---------------------------------------------------
#ifndef DAYTIME_H
#define DAYTIME_H
class DayTime
{
private:
    short hour, minute, second;
    bool overflow;
public:
    DayTime( int h = 0, int m = 0, int s = 0)
    {
        overflow = false;
        if( !setTime( h, m, s)) // this->setTime(...)
            hour = minute = second = 0; // hour ist
    } // this->hour etc.
    bool setTime(int hour, int minute, int second = 0)
    {
        if( hour >= 0 && hour < 24
        && minute >= 0 && minute < 60
        && second >= 0 && second < 60 )
        {
            this->hour = (short)hour;
            this->minute = (short)minute;
            this->second = (short)second;
            return true;
        }
        else
            return false;
    }
    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    int getSecond() const { return second; }
    int asSeconds() const // Tageszeit als Sekunden
    {
        return (60*60*hour + 60*minute + second);
    }
    bool isLess( DayTime t) const // *this mit t vergl.
    {
        return asSeconds() < t.asSeconds();
    } // this->asSeconds() < t.asSeconds();
    bool operator<( const DayTime& t) const
    { // *this mit t vergl.
        return asSeconds() < t.asSeconds();
    }
    DayTime& operator++() // Sekunden erhöhen.
    {
        ++second; // und Überlauf behandeln.
        return *this;
    }
    void print() const {
        cout << std::setfill('0') << std::setw(2) << hour << ":" << std::setfill('0') << std::setw(2) << minute << ":" << std::setfill('0') << std::setw(2) << second << endl;
    };

};
#endif // DAYTIME_H