# Alat Monitoring KWh Meter dengan ESP32 Menggunakan Sensor PZEM-004T

Alat monitoring KWh meter ini dirancang untuk memantau konsumsi daya listrik secara real-time menggunakan ESP32 dan sensor PZEM-004T. Data konsumsi listrik akan dikirimkan secara otomatis ke Google Spreadsheet sehingga dapat diakses dan dipantau dari mana saja melalui internet.
Komponen yang Dibutuhkan

- ESP32: Mikrokontroler dengan konektivitas Wi-Fi yang digunakan untuk mengirim data ke Google Spreadsheet.
- Sensor PZEM-004T: Sensor yang digunakan untuk mengukur tegangan, arus, daya aktif, dan energi (KWh).
- Adaptor Daya: Untuk memberikan daya kepada ESP32 dan PZEM-004T.
- Kabel Jumper: Untuk menghubungkan sensor PZEM-004T dengan ESP32.
- Breadboard: Untuk memudahkan koneksi antara komponen.

## Langkah Kerja

### Koneksi Perangkat Keras:

- Hubungkan VCC dari PZEM-004T ke 5V pada ESP32.
- Hubungkan GND dari PZEM-004T ke GND pada ESP32.
- Hubungkan TX dari PZEM-004T ke RX pada ESP32.
- Hubungkan RX dari PZEM-004T ke TX pada ESP32.

## Pemrograman ESP32:

### Library yang Dibutuhkan:

- WiFi.h: Untuk menghubungkan ESP32 ke jaringan Wi-Fi.
- HTTPClient.h: Untuk mengirim data ke Google Spreadsheet.
- SoftwareSerial.h: Untuk komunikasi serial dengan sensor PZEM-004T.
- PZEM004Tv30.h: Library untuk mengakses sensor PZEM-004T.

## Kesimpulan

Dengan menggunakan alat monitoring KWh meter berbasis ESP32 dan sensor PZEM-004T ini, Anda dapat memantau konsumsi daya listrik secara real-time dari mana saja. Data yang terkirim ke Google Spreadsheet memungkinkan analisis dan pemantauan yang lebih mudah dan fleksibel. Alat ini cocok untuk penggunaan rumah tangga maupun industri kecil yang memerlukan pemantauan konsumsi energi secara efisien.


#Sarah
