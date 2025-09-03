# Proyek Kontrol LED via MQTT

Proyek sederhana ini menunjukkan cara mengontrol sebuah LED yang terhubung ke perangkat mikrokontroler (seperti ESP32 atau ESP8266) dari jarak jauh menggunakan protokol MQTT.

Aplikasi klien dibuat dengan Python menggunakan library **Tkinter** untuk antarmuka grafis (GUI), dan kode untuk perangkat kerasnya dikelola menggunakan **PlatformIO**.

## Fitur

-   **Kontrol Nirkabel**: Nyalakan dan matikan LED dari aplikasi desktop di komputer.
-   **Protokol MQTT**: Menggunakan protokol _publish-subscribe_ yang ringan dan efisien, ideal untuk IoT.
-   **Antarmuka Sederhana**: GUI yang mudah digunakan dengan dua tombol: "Nyalakan LED" dan "Matikan LED".

---

## Prasyarat

Sebelum memulai, pastikan sudah menginstal perangkat lunak berikut:

1.  **Visual Studio Code**: Editor kode yang akan kita gunakan.
2.  **Ekstensi PlatformIO IDE**: Untuk mengelola, membangun, dan meng-upload kode ke mikrokontroler.
3.  **Python 3**: Untuk menjalankan aplikasi klien.

---

## 🛠️ Pengaturan Perangkat Keras (PlatformIO)

Kode untuk mikrokontroler (misalnya ESP32) berada di dalam folder `src`. Agar kode ini dapat berjalan perlu untuk menambahkan library dan mengatur kredensial WiFi.

### 1. Instal Library PubSubClient

Proyek ini bergantung pada library **PubSubClient** oleh Nick O'Leary untuk menangani komunikasi MQTT.

-   Buka proyek di VS Code.
-   Klik ikon **PlatformIO** di sidebar kiri.
-   Pilih menu **Libraries**.
-   Cari `PubSubClient`, pilih yang dibuat oleh **Nick O'Leary**, dan klik **Add to Project**.

### 2. Konfigurasi Kredensial (Sangat Penting!)

Untuk alasan keamanan, informasi sensitif seperti nama dan password WiFi tidak disimpan langsung di dalam kode utama.

-   **Ubah Nama File**: Di dalam folder `src`, cari file bernama `secrets.h.example` dan ubah namanya menjadi `secrets.h`.
-   **Isi Kredensial**: Buka file `secrets.h` yang baru dan isi detail WiFi.

    ```cpp
    // File: src/secrets.h

    #ifndef SECRETS_H
    #define SECRETS_H

    // Ganti dengan nama WiFi-mu
    #define SECRET_SSID "NAMA_WIFI"

    // Ganti dengan password WiFi-mu
    #define SECRET_PASSWORD "PASSWORD_WIFI"

    #endif
    ```

    > **Catatan**: File `secrets.h` sudah dimasukkan ke dalam `.gitignore`, sehingga tidak akan ter-upload ke GitHub dan kredensial tetap aman.

Setelah kedua langkah di atas selesai, kode bisa diupload ke perangkat melalui PlatformIO.

---

## 💻 Pengaturan Klien (Python)

Aplikasi klien GUI digunakan untuk mengirim perintah ke perangkat keras.

### 1. Buat Virtual Environment

Sangat disarankan untuk menggunakan _virtual environment_ agar dependensi proyek tidak tercampur dengan instalasi Python global. Buka terminal di dalam folder proyek dan jalankan:

```bash
# Buat virtual environment bernama .venv
python -m venv .venv

# Aktifkan (Windows)
.\.venv\Scripts\activate

# Aktifkan (macOS/Linux)
source .venv/bin/activate
```

### 2. Instal Dependensi

Proyek ini membutuhkan library **paho-mqtt**. Instal menggunakan `pip`

```bash
pip install paho-mqtt
```

### 3. Jalankan Aplikasi

Setelah dependensi terinstal, jalankan program Python untuk menampilkan GUI

```bash
python nama_file_python.py
```

Jangan lupa jalankan program IoT-nya juga

1. Tekan `Ctrl + Shift + P`
2. Cari yang `Wokwi: Start Simulator`
