# Timestamp (time since system boot).
uint32 time_boot_ms

# Latitude in degrees * 1E7 (scaled integer representation of latitude)
int32 lat

# Longitude in degrees * 1E7 (scaled integer representation of longitude)
int32 lon

# Altitude (MSL) in millimeters
int32 alt

# Relative altitude above home in millimeters
int32 relative_alt

# Ground X Speed in cm/s (Latitude, positive north)
int16 vx

# Ground Y Speed in cm/s (Longitude, positive east)
int16 vy

# Ground Z Speed in cm/s (Altitude, positive down)
int16 vz

# Vehicle heading (yaw angle) in centi-degrees (0.0..359.99 degrees)
uint16 hdg
