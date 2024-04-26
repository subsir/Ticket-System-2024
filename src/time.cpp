struct Time {
  int month = 0, day = 0, hour = 0, minute = 0;
  Time operator+(const Time &other) const {
    Time result;
    result.minute = this->minute + other.minute;
    result.hour = this->hour + other.hour + result.minute / 60;
    result.minute %= 60;
    result.day = this->day + other.day + result.hour / 24;
    result.hour %= 24;
    result.month = this->month + other.month + result.day / 30;
    result.day %= 30;
    // 假设每个月都是30天，每年都是12个月
    result.month %= 12;
    return result;
  }
  Time &operator+=(const Time &other) {
    *this = *this + other;
    return *this;
  }
};