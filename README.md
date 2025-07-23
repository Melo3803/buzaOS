# efi tabanlı sistem için C ile basit kernel ve bootloader
<img width="1907" height="973" alt="Screenshot 2025-07-23 235600" src="https://github.com/user-attachments/assets/afd5b2e7-03ab-444a-b0b7-db56fa413042" />


Building(derlemek için)
### 1. Build bootloader (Bootloader'ı Derle)

```bash
cd gnu-efi
make
make bootloader
```
### 2. Build kernel (kernel'ı derle)

```bash
cd ../kernel
make setup
make kernel
```

### 3. Build img (img dosyasını oluştur)
```bash
make buildimg
make run
```
ya da windowsta run.bat dosyaları kullarak qemu ile çalıştır
