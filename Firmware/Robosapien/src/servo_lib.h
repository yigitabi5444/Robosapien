
const int servo_pins[] = {19, 17, 16, 13, 14, 27, 26, 33, 32};

void initServo();

/// @brief Set servo position
/// @param id ID of servo 0-17
/// @param pos Position of servo 0-180
void setServo(int id, int pos);

/// @brief Set servo enabled
/// @param id ID of servo
/// @param enabled Enabled or disabled
void setServoEnabled(int id, bool enabled);