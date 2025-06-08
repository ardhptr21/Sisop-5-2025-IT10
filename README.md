# Sisop-5-2025-IT

## Kelompok

| No  | Nama                   | NRP        |
| --- | ---------------------- | ---------- |
| 1   | Ardhi Putra Pradana    | 5027241022 |
| 2   | Aslam Ahmad Usman      | 5027241074 |
| 3   | Kanafira Vanesha Putri | 5027241010 |

## Daftar Isi

- [Kelompok](#kelompok)
- [Daftar Isi](#daftar-isi)
- [Soal](#soal)
- [Petunjuk Soal](#petunjuk-soal)
  - [Source](#source)
  - [Headers](#headers)
  - [Makefile](#makefile)
  - [Video Demonstrasi](#video-demonstrasi)
- [Laporan](#laporan)

## Soal

Pada suatu hari, anda merasa sangat lelah dari segala macam praktikum yang sudah ada, sehingga anda berencana untuk tidur yang nyenyak di sebuah jam 3:34AM yang cerah. Tetapi, anda terbangun di dalam dunia berbeda yang bernama "Eorzea". Ada sesuatu yang mengganggu pikiran anda sehingga anda diharuskan membuat sebuah operating system bernama "EorzeOS" untuk mendampingi diri anda dalam dunia ini.

1. Sebagai seorang main character dari dunia ini, ternyata anda memiliki kekuatan yang bernama "The Echo", kekuatan ini memungkinkan anda untuk berbicara pada Operating System ini (mungkin sebenarnya bukan ini kekuatannya, tetapi ini cukup kuat juga), dengan tujuan agar semua hal yang anda katakan, bila bukan merupakan sebuah command yang valid, akan mengulang hal yang anda katakan.

   Ilustrasi:

   ```
   user> Hello!
   Hello!
   user> I have the Echo
   I have the Echo
   ```

2. gurt: yo

   Ilustrasi:

   ```
   user> yo
   gurt
   user> gurt
   yo
   ```

3. Seorang main character memerlukan sebuah nama yang semua orang bisa ingat dengan baik. Buatlah sebuah command yang memungkinkan pengguna untuk mengubah nama user pada shell yang digunakan:

   - `user <username>` = mengubah username menjadi `<username>`
   - `user` = mengubah username menjadi default `user`

   Ilustrasi:

   ```
   user> user Tia
   Username changed to Tia
   Tia> user
   Username changed to user
   user>
   ```

4. Tiga negara besar dari Eorzean Alliance butuh bantuan anda untuk ikut serta dalam "Grand Company" mereka sehingga anda bisa mengubah warna terminal ajaib anda sesuai warna utama dari company mereka:

   - `grandcompany maelstrom` = clear terminal, ubah semua teks berikutnya jadi merah
   - `grandcompany twinadder` = clear terminal, ubah semua teks berikutnya jadi kuning
   - `grandcompany immortalflames` = clear terminal, ubah semua teks berikutnya jadi biru
   - `grandcompany <selain atau kosong>` = tunjukkan error message
   - `clear` = clear terminal, ubah semua teks berikutnya kembali jadi awal (para Grand Company sedih kamu netral)

   Selain mengubah seluruh warna terminal, nama anda di dalam terminal akan diberikan tambahan nama judul Grand Company:

   - Maelstrom = `user@Storm`
   - Twin Adder = `user@Serpent`
   - Immortal Flames = `user@Flame`
   - `clear` = menghapus nama grand company

   Ilustrasi:

   ```
   gurt> grandcompany maelstrom
   -- terminal clear menjadi warna merah --
   gurt@Storm> clear
   -- terminal clear menjadi warna putih --
   ```

5. Sebagai pahlawan terkenal di antara ketiga negara besar Eorzean Alliance, salah satu supplier senjata terbesar di seluruh Eorzea bernama "Rowena's House of Splendors" tiba-tiba memerlukan bantuan anda untuk membuat sebuah sistem kalkulator sederhana melalui command karena pemimpin mereka tertidur setelah mengurus semua orang di dalam Eorzea:

   - `add <x> <y>` = x + y
   - `sub <x> <y>` = x - y
   - `mul <x> <y>` = x \* y
   - `div <x> <y>` = x / y

   Ilustrasi:

   ```
   user> add 4 2
   6
   user> sub 4 2
   2
   user> mul 3 -2
   -6
   user> div -6 -2
   3
   ```

6. me: yogurt

   gurt:

   - `yo`
   - `ts unami gng </3`
   - `sygau`

   pilih secara _random_

   Ilustrasi:

   ```
   user> yogurt
   gurt> yo
   user> yogurt
   gurt> ts unami gng </3
   user> yogurt
   gurt> sygau
   ```

7. Perusahaan mesin "Garlond Ironworks" tiba-tiba lelah mengurus permintaan senjata perang untuk orang ke-148649813234 yang berusaha menghadapi final boss yang sama, sehingga mereka perlu bantuan kamu untuk melengkapi `Makefile` yang diberikan dengan command-command yang sesuai untuk compile seluruh operating system ini.

## Petunjuk Soal

### Source

- [kernel.asm](src/kernel.asm)
  - `_putInMemory`: penjelasan terdapat dalam modul
  - `_interrupt`: fungsi untuk interrupt
    - `number`: interrupt vector number
    - `AX`,`BX`,`CX`,`DX`: register untuk diisi
    - `AX` merupakan kombinasi dari `AH` dan `AL`, pola ini juga berlaku untuk `BX`,`CX`, dan `DX`
    - Untuk menggabungkan jenis register `H` dan `L` menjadi `X` bisa menggunakan salah satu metode berikut:
      ```c
      AX = AH << 8 | AL    // first method
      AX = AH * 256 + AL   // second method
      ```
  - `getBiosTick`: fungsi untuk mendapatkan tick dari BIOS
- [kernel.c](src/kernel.c)
  - Diisi penerapan fungsi `printString`, `readString`, dan `clearScreen` dengan bantuan `kernel.asm`
    - untuk `printString`: Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 10h` dengan parameter `AH = 0x0E` untuk _teletype output_. Karakter yang ditampilkan dapat dimasukkan pada register `AL`. Fungsi ini akan menampilkan string karakter ASCII (_null-terminated_) ke layar.
    - untuk `readString`: Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 16h` dengan parameter `AH = 0x00` untuk _keyboard input_. Fungsi ini akan membaca karakter ASCII (_non-control_) yang dimasukkan oleh pengguna dan menyimpannya pada buffer hingga menekan tombol `Enter`. Handle tombol `Backspace` dibebaskan kepada praktikan.
    - untuk `clearScreen`: Ukuran layar adalah `80x25` karakter. Setelah layar dibersihkan, kursor akan kembali ke posisi awal yaitu `(0, 0)` dan buffer video untuk warna karakter diubah ke warna putih. Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 10h` atau menggunakan fungsi `putInMemory` untuk mengisi memori video.
- [shell.c](src/shell.c)
  - Diisi penerapan shell yang menggunakan fungsi kernel untuk parsing keseluruhan command yang diinput

### Headers

- [std_type.h](include/std_type.h)
  - `byte`: unsigned char data type, untuk angka 0-255 (`0x00`-`0xFF`)
  - `bool`: untuk boolean (true/false), karena boolean tidak built-in
- [std_lib.h](include/std_lib.h)
  - `div`: division
  - `mod`: modulo
  - Pembagian dan modulo tidak ada dalam assembly, sehingga harus dilengkapi dengan operator yang tersedia (`+`,`-`,`*`,`<<`,`>>`)
  - `strcmp`: membandingkan dua string
  - `strcpy`: copy string
  - `clear`: fill memory dengan `0`
  - `atoi`: alphanumeric to integer (string menjadi angka)
  - `itoa`: integer to alphanumeric (angka menjadi string)
- [kernel.h](include/kernel.h)
  - Deklarasi header untuk fungsi-fungsi dalam `kernel.c`
- [shell.h](include/shell.h)
  - Deklarasi header untuk fungsi-fungsi dalam `shell.c`

### Makefile

- [makefile](./makefile)
  - `prepare` : membuat disk image baru `floppy.img` pada direktori `bin/` dengan ukuran 1.44 MB.
  - `bootloader` : mengkompilasi `bootloader.asm` menjadi `bootloader.bin` pada direktori `bin/`.
  - `stdlib` : mengkompilasi `std_lib.c` menjadi `std_lib.o` pada direktori `bin/`.
  - `shell`: mengkompilasi `shell.c` menjadi `shell.o` pada direktori `bin/`.
  - `kernel` : mengkompilasi `kernel.c` menjadi `kernel.o` pada direktori `bin/` dan mengkompilasi `kernel.asm` menjadi `kernel_asm.o` pada direktori `bin/`.
  - `link` : menggabungkan `bootloader.bin`, `kernel.o`, `kernel_asm.o`, dan `std_lib.o` menjadi `floppy.img`.
  - `build` : menjalankan perintah `prepare`, `bootloader`, `stdlib`, `kernel`, dan `link`.

### Video Demonstrasi

[Akses Video dalam Assets](./assets/demo.mp4)

https://github.com/user-attachments/assets/1cfa66b1-b2f5-4e3e-a4b2-ec8b012f6fbb

## Laporan

### Initial Setup

**Dikerjakan Oleh: Ardhi Putra Pradana (5027241022)**

#### std_lib.c

```c
int div(int a, int b) {
    int quotient = 0;
    int isNegative = 0;
    int absA = a, absB = b;

    if (b == 0) return 0;

    if (a < 0) {
        isNegative = !isNegative;
        absA = -a;
    }
    if (b < 0) {
        isNegative = !isNegative;
        absB = -b;
    }

    while (absA >= absB) {
        absA -= absB;
        quotient++;
    }

    return isNegative ? -quotient : quotient;
}
```

Pelengkapan function `div` disini digunakan untuk melakukan operasi pembagian, dikarenakan secara default operasi div ini tidak disupport oleh system 16 bit ansi. Function diatas menerapkan operasi perulangan dan operasi aritmatika standar seperti tambah dan kurang untuk mendapatkan hasil baginya.

```c
int mod(int a, int b) {
    int absA = a < 0 ? -a : a;
    int absB = b < 0 ? -b : b;

    if (b == 0) return 0;

    while (absA >= absB) {
        absA -= absB;
    }

    return a < 0 ? -absA : absA;
}
```

Function `mod` digunakan untuk operasi modulus, yang sama hal nya dengan division sebelumnya bahwa operasi modulus tidak secara default disupport, untuk menerapkannya menggunakan konsep perulangan untuk mendapatkan hasil modulusnya.

```c
bool strcmp(char *str1, char *str2) {
    int i = 0, flag = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            flag = 1;
            break;
        }
        i++;
    }

    if (flag == 0 && str1[i] == '\0' && str2[i] == '\0') return 1;
    return 0;
}
```

Penerapan function `strcmp` dibuat untuk digunakan ketika ingin membandingkan dua string yang sama nantinya, nah konsep low level disini digunakan yaitu dengan membandingkan char per char dari string yang ada pada argument dan melihat apakah semua char tersebut sama disetiap posisinya.

```c
void strcpy(char *dst, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}
```

Function `strcpy` menerupakan penerapan function untuk melakukan copy dari string ke string yang lain dialamat memory yang berbeda, penerapannya menggunakan assigning manual char per char ke string target.

```c
void clear(byte *buf, unsigned int size) {
    int i = 0;
    while (i < size) {
        buf[i] = 0x0;
        i++;
    }
}
```

Function `clear` digunakan untuk melakukang clearing buffer, yaitu dengan cara melakukan assigning null byte ke setiap char sepanjang size string tersebit.

```c
void atoi(char *str, int *num) {
    int i = 0;
    int result = 0;
    int sign = 1;

    while (str[i] == ' ' || str[i] == '\t') i++;

    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    *num = sign * result;
}
```

Function `atoi` (ascii to integer) digunakan untuk mengubah sebuah string menjadi value integer, dimana caranya adalah dengan melihat semua possibility sebuah angka yang ada pada string tersebut, lalu dengan cara menggunakan konsep `decrement` dengan zero value untuk setiap char yang valid dan melakukan perkalian 10 untuk melihat decimal point.

```c
void itoa(int num, char *str) {
    int i = 0;
    int isNegative = 0;
    int start, end;
    char temp;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    while (num > 0) {
        str[i++] = mod(num, 10) + '0';
        num = div(num, 10);
    }

    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0';

    start = 0;
    end = i - 1;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
```

Function `itoa` (integer to ascii) digunakan untuk mengubah sebuah angka menjadi string, dimana penerapannya sedikit lebih rumit dengan menggabungkan operasi `mod` dan `div` secara bersamaan untuk mendapatkan tiap decimal int yang akan diconvert menjadi string.

#### kernel.c

> tambahan value di kernel.h

```c
#define WHITE_COLOR 0x000F
#define RED_COLOR 0x000C
#define YELLOW_COLOR 0x000E
#define BLUE_COLOR 0x0001

void setColor(int color);
```

Define variable color untuk memudahkan mapping color terminal yang dibutuhkan, dan juga placeholder function `setColor` untuk mengubah global variable.

```c
static int currentColor = WHITE_COLOR;

int main() {
    clearScreen();
    shell();
    return 0;
}
```

variable global diatas akan digunakan sebagai changer terminal color, yang nanti dapat digunakan untuk fitur yang mengharuskan untuk mengganti terminal colornya. Dan function `main` sebagai gerbang utama dimana OS ini akan dijalankan.

```c
void setColor(int color) {
    currentColor = color;
}
```

Function `setColor` yang sangat simple digunakan untuk mengubah global variable `currentColor`.

```c
void printString(char *str) {
    char *p = str;
    while (*p != 0) {
        if (*p == '\n') {
            interrupt(0x10, 0x0e0d, 0x0000, 0x0001, 0);
            interrupt(0x10, 0x0e0a, 0x0000, 0x0001, 0);
        } else {
            interrupt(0x10, 0x0900 | *p, currentColor, 0x0001, 0);
            interrupt(0x10, 0x0e00 | *p, 0x0000, 0x0001, 0);
        }
        p++;
    }
}
```

Function `printString` digunakan untuk menampilkan sebuah string ke `console` atau `terminal`, dimana penerapannya menggunakan low level function yaitu `interrupt` yang sudah didefinisikan pada `assembly kernel.asm`. Penerapannya adalah dengan melakukan loop satu persatu karakter, dan ketika kasus khusus char tersebut adalah `\n` (LF) maka akan diconvert menjadi `\r\n` (CRLF), sisanya adalah menampilkan char dari tiap string tersebut, dengan menggunakan dua interrupt, yang pertama untuk melakukan set color dan yang kedua adalah melakukan resetting point colornya untuk tiap karakter.

```c
void readString(char *buf) {
    char c;
    int i = 0;

    while (1) {
        c = interrupt(0x16, 0, 0, 0, 0);

        if (c == '\r') {
            interrupt(0x10, 0x0e0d, 0x0000, 0x0001, 0);
            interrupt(0x10, 0x0e0a, 0x0000, 0x0001, 0);
            break;
        } else if (c == '\b') {
            if (i > 0) {
                i--;
                interrupt(0x10, 0x0e08, 0x0000, 0x0001, 0);
                interrupt(0x10, 0x0e20, 0x0000, 0x0001, 0);
                interrupt(0x10, 0x0e08, 0x0000, 0x0001, 0);
            }
        } else {
            interrupt(0x10, 0x0900 | c, currentColor, 0x0001, 0);
            interrupt(0x10, 0x0e00 | c, 0x0000, 0x0001, 0);
            buf[i++] = c;
        }
    }
    buf[i] = 0;
}
```

Function `readString` digunakan untuk membaca input dari user yang dikirimkan ke OS ini, dimana penarapannya adalah dengan membaca 0x16 offset dari interrupt bios systemnya untuk setiap loopingnya, lalu ada beberapa bagian yaitu `\r` akan diubah menjadi `\r\n`, dan `\b` akan diubah menjadi `\b \b`, dan sisanya adalah printing karakter biasa untuk setiap buffer nya.

```c
void clearScreen() {
    interrupt(0x10, 0x0003, 0x0007, 0, 0);
    interrupt(0x10, 0x0200, 0x0000, 0, 0);
}
```

Function `clearScreen` digunakan untuk membersihkan semua output yang ada diconsole, yaitu baris pertama melakukan setting screen size, dan yang kedua adalah mengubah posisi kursor ke `top-left`.

#### shell.c

> penambahan placeholder function pada shell.h

```h
void yogurt(char *buf);
void realyogurt();
void changeUser(char *user, char *to);
void grandCompany(char *top, char *arg);
void calc(char *op, char *a, char *b);
```

Placholder yang diguanakan untuk setiap handler function disetiap custom operation pada OS yang dibuat.

```c
void shell() {
    char buf[128];
    char cmd[64];
    char arg[2][64];
    char user[64];
    char gc[64];

    printLogo();
    strcpy(user, "user");

    while (true) {
        prompt(user, gc, buf);
        parseCommand(buf, cmd, arg);

        if (strcmp(cmd, "clear")) {
            clearScreen();
            setColor(WHITE_COLOR);
            continue;
        }
        if (strcmp(cmd, "yo") || strcmp(cmd, "gurt")) {
            yogurt(buf);
            continue;
        }

        if (strcmp(cmd, "yogurt")) {
            realyogurt();
            continue;
        }

        if (strcmp(cmd, "user")) {
            changeUser(user, arg[0]);
            continue;
        }

        if (strcmp(cmd, "grandcompany")) {
            grandCompany(gc, arg[0]);
            continue;
        }

        if (strcmp(cmd, "add") || strcmp(cmd, "sub") || strcmp(cmd, "mul") || strcmp(cmd, "div")) {
            calc(cmd, arg[0], arg[1]);
            continue;
        }

        printString(buf);
        printString("\n");
    }
}
```

Function `shell` adalah entrypoint dimana semua tahap operasi pada shell/console akan dilakukan, yaitu dengan melakukan while loop atau perulangan tanpa henti, dan terus melakukan `read` input dari user dan melakukan `output` dari setiap command yang ada.
Hal utama yang dilakukan pada function ini adalah untuk membandingkan operasi apa yang akan dilakukan dan memanggil handlernya sesuai dengan command yang sesuai.

```c
void prompt(char *user, char *top, char *buf) {
    printString(user);
    if (top[0] != '\0') {
        printString(top);
    }
    printString("> ");
    readString(buf);
}
```

Function `prompt` digunakan untuk menampilkan prompting ke user atau membaca input dari user, dimana user nantinya akan memberikan command - command yang sesuai.

```c
void printLogo() {
    printString(" ____ ___ ____   ___  ____  \n");
    printString("/ ___|_ _/ ___| / _ \\|  _ \\ \n");
    printString("\\___ \\| |\\___ \\| | | | |_) |\n");
    printString(" ___) | | ___) | |_| |  __/ \n");
    printString("|____/___|____/ \\___/|_|    \n\n");
    printString(" ___ _____   _  ___  \n");
    printString("|_ _|_   _| | |/ _ \\ \n");
    printString(" | |  | |   | | | | |\n");
    printString(" | |  | |   | | |_| |\n");
    printString("|___| |_|   |_|\\___/ \n\n");
    printString("Welcome to our very lite OS!\n\n");
}
```

Function `printLogo` adalah function yang hanya untuk menampilkan header output dari OS untuk menampilkan string dari logo OS ini.

```c
void parseCommand(char *buf, char *cmd, char arg[2][64]) {
    int i = 0, j = 0, k = 0;
    int argIndex = -1;

    cmd[0] = '\0';
    arg[0][0] = '\0';
    arg[1][0] = '\0';

    while (buf[i] == ' ' || buf[i] == '\t') i++;

    while (buf[i] != '\0' && buf[i] != '\n') {
        if (buf[i] == ' ' || buf[i] == '\t') {
            if (argIndex == -1) {
                cmd[j] = '\0';
                argIndex = 0;
            } else if (argIndex < 2) {
                arg[argIndex][k] = '\0';
                argIndex++;
                k = 0;
            }
            while (buf[i] == ' ' || buf[i] == '\t') i++;
            continue;
        }

        if (argIndex == -1) {
            cmd[j++] = buf[i++];
        } else if (argIndex < 2) {
            arg[argIndex][k++] = buf[i++];
        } else {
            i++;
        }
    }

    if (argIndex == -1) {
        cmd[j] = '\0';
    } else if (argIndex < 2) {
        arg[argIndex][k] = '\0';
    }
}
```

Function `parseCommand` digunakan untuk membaca input dari user yang akan dimapping menjadi command - command yang sesuai, function ini sebenarnya akan membagi menjadi 3 hal, yaitu membaca `main command` atau ini adalah string posisi pertama sebelum tanda spasi, dan sisanya adalah membaca 2 argument setelah `main command` yang dipisahkan dengan spasi juga, dan function ini hanya membaca 2 argument saja setelah argument `main command`, dimana hasil parsing ini dapat digunakan dan diterapkan untuk membuat handler command yang sesuai.

## Pengerjaan Soal

### Soal 1

**Dikerjakan Oleh: Aslam Ahmad Usman (5027241074)**

Untuk soal ini diharuskan untuk menggunakan kekuatan The Echo agar Operating System dapat mengulangi kata yang user ucapkan. Caranya sangat simple:

```c
printString(buf);
printString("\n");
```

Perintah diatas akan mengulangi setiap kata yang diucapkan user selama bukan command seperti "user", "clear", "add", dan semacamnya.

### Soal 2

**Dikerjakan Oleh: Kanafira Vanesha Putri (5027241010)**

Soal ini meminta agar shell mengenali dua perintah spesifik: yo dan gurt, yang saling merespon satu sama lain. Sehingga, jika input adalah yo, maka output-nya gurt, dan sebaliknya jika input adalah gurt, maka output-nya yo.

Untuk menyelesaikan hal ini, ditambahkan pengecekan di shell() dibagian command parser:

```c
if (strcmp(cmd, "yo") || strcmp(cmd, "gurt")) {
    yogurt(buf);
    continue;
}
```

Kemudian, fungsi yogurt() dibuat untuk menangani pembalikan kata berdasarkan input pengguna:

```c
void yogurt(char *buf) {
    if (strcmp(buf, "yo")) {
        printString("gurt\n");
    } else {
        printString("yo\n");
    }
}
```

### Soal 3

**Dikerjakan Oleh: Kanafira Vanesha Putri (5027241010)**

Menambahkan fitur untuk mengganti nama pengguna pada prompt shell. Secara default, username adalah user. Ketika mengetik user <nama>, maka prompt akan berubah menjadi <nama>. Jika mengetik user tanpa argumen, maka akan kembali menjadi user.

Pertama adalah menambahkan pengecekan command user di fungsi shell():

```c
if (strcmp(cmd, "user")) {
    changeUser(user, arg[0]);
    continue;
}
```

Lalu menambahkan fungsi changeUser() untuk mengubah isi variabel user:

```c
void changeUser(char *user, char *to) {
    if (to[0] == '\0') {
        strcpy(user, "user");
    } else {
        strcpy(user, to);
    }

    printString("Username changed to ");
    printString(user);
    printString("\n");
}
```

Fungsi changeUser() pakai strcpy buat ganti nama user. Nama ini disimpan di variabel user, dan tiap kali shell nunggu input, fungsi prompt() bakal nampilin isi user itu. Jadi kalau namanya diganti, langsung keliatan di prompt-nya.

```c
void prompt(char *user, char *top, char *buf) {
    printString(user);
    if (top[0] != '\0') {
        printString(top);
    }
    printString("> ");
    readString(buf);
}
```

### Soal 4

**Dikerjakan Oleh: Ardhi Putra Pradana (5027241022)**

```c
void grandCompany(char *top, char *arg) {
    if (strcmp(arg, "maelstorm")) {
        strcpy(top, "@Storm");
        setColor(RED_COLOR);
    } else if (strcmp(arg, "twinadder")) {
        strcpy(top, "@Serpent");
        setColor(YELLOW_COLOR);
    } else if (strcmp(arg, "immortalflames")) {
        strcpy(top, "@Flame");
        setColor(BLUE_COLOR);
    } else {
        printString("Error: invalid grand company\n");
        return;
    }

    clearScreen();
}
```

Dibagian soal ini objektifnya adalah hanya untuk mengganti warna dari console/terminal yang ada, dan kemudian mengubah `top host` nya untuk menampilkan hal yang sesuai. Disini menggunakan `strcpy` untuk melakukan write string ke `top` variable dan memanggil `setColor` untuk mengubah global color terminal yang ada.

### Soal 5

**Dikerjakan Oleh: Ardhi Putra Pradana (5027241022)**

```c
void calc(char *op, char *a, char *b) {
    int num1 = 0, num2 = 0, result = 0;
    char *out;

    if (a[0] == '\0' || b[0] == '\0') {
        printString("Error: arguments missing\n");
        return;
    }

    atoi(a, &num1);
    atoi(b, &num2);

    if (strcmp(op, "add")) {
        result = num1 + num2;
    } else if (strcmp(op, "sub")) {
        result = num1 - num2;
    } else if (strcmp(op, "mul")) {
        result = num1 * num2;
    } else if (strcmp(op, "div")) {
        if (num2 == 0) {
            printString("Error: division by zero\n");
            return;
        }

        result = num1 / num2;
    }

    itoa(result, out);

    printString(out);
    printString("\n");
}
```

Sangat komprehensif jika dilihat, hanya dengan melihat operasi apa yang dimasukkan oleh user, kemudian sesuaikan operasi tersebut dengan bilangan dari argument pertama dan kedua. Menggunakan std function `atoi` untuk mengubah dari string ke integer agar bisa dilakukan operasi aritmetik, kemudian sesuaikan operasinya, dan lalu balikkan kembali ke string menggunakan `itoa` dan lalu tampilkan hasilnya.

### Soal 6

**Dikerjakan Oleh: Ardhi Putra Pradana (5027241022)**

```c
void realyogurt(void) {
    static unsigned int seed = 0;
    static char *strings[] = {
        "yo",
        "ts unami gng </3",
        "sygau"};

    int random_index;

    if (seed == 0) {
        seed = getBiosTick();
    }

    seed = seed * 17 + 7;  // LCG
    random_index = mod(mod(seed, 3) + 3, 3);

    printString("gurt> ");
    printString(strings[random_index]);
    printString("\n");
}
```

Objektif soal ini adalah untuk menampilkan random string yaitu `yo, ts unami gng </3, sygau`, nah biasanya untuk melakukan random kita memerlukan interface `pseudo-random` untuk bisa mendapatkan random value, dalam kasus ini sudah disediakan low-level function `getBiosTick` yang akan mendapatkan `pseudo-random` value dari BIOS yang dapat dimanfaatkan pada soal ini. Lalu kemudian menggunakan formula LCG (Linear Congruential Generator) untuk mendapatkan hasil akhir value `pseudo-random` nya. Setelah itu dapatkan `random_index` untuk memanggil random index dari setiap array value yang ada.

### Soal 7

**Dikerjakan Oleh: Ardhi Putra Pradana (5027241022)**

```c
prepare:
	dd if=/dev/zero of=bin/floppy.img bs=512 count=2880

bootloader:
	nasm -f bin src/bootloader.asm -o bin/bootloader.bin
	dd if=bin/bootloader.bin of=bin/floppy.img conv=notrunc bs=512 count=1

stdlib:
	bcc -ansi -c -Iinclude src/std_lib.c -o bin/std_lib.o

shell:
	bcc -ansi -c -Iinclude src/shell.c -o bin/shell.o

kernel:
	nasm -f as86 src/kernel.asm -o bin/kernel-asm.o
	bcc -ansi -c -Iinclude src/kernel.c -o bin/kernel.o

link:
	ld86 -o bin/kernel.bin -d bin/kernel.o bin/kernel-asm.o bin/shell.o bin/std_lib.o
	dd if=bin/kernel.bin of=bin/floppy.img conv=notrunc bs=512 seek=1

build: prepare bootloader stdlib shell kernel link

run: build
	bochs -f bochsrc.txt
```

Dalam soal 5 ini adalah melengkapi file `makefile` untuk bisa meng-compile dan mem-bundling resource raw code OS yang ada menjadi `disk image` file yang nantinya akan dibooting oleh bootloader.

```make
prepare:
	dd if=/dev/zero of=bin/floppy.img bs=512 count=2880
```

Tahap pertama untuk handler `prepare` adalah melakukan inisiasi disk image

```make
bootloader:
	nasm -f bin src/bootloader.asm -o bin/bootloader.bin
	dd if=bin/bootloader.bin of=bin/floppy.img conv=notrunc bs=512 count=1
```

Tahap untuk `bootloader` adalah melakukan compiling assembly dari `bootlader.asm` menjadi binary file, kemudian melakukan write hasil binary tersebut ke `disk image` sebelumnya.

```make
stdlib:
	bcc -ansi -c -Iinclude src/std_lib.c -o bin/std_lib.o
```

Tahap `stdlib` sangat simple hanya melakukan compiling file `std_lib.c` dengan menggunakan `bcc` compiler dan menggunakan format `ansi`

```make
shell:
	bcc -ansi -c -Iinclude src/shell.c -o bin/shell.o
```

Tahap `shell` sangat simple hanya melakukan compiling file `shell.c` dengan menggunakan `bcc` compiler dan menggunakan format `ansi`

```make
kernel:
	nasm -f as86 src/kernel.asm -o bin/kernel-asm.o
	bcc -ansi -c -Iinclude src/kernel.c -o bin/kernel.o
```

Tahap `kernel` adalah melakukan compile/build assembly `kernel.asm` menjadi binary file, dan kemudian melakukan compile file `kernel.c` menggunaakn `bcc` compiler dengan format `ansi`

```make
link:
	ld86 -o bin/kernel.bin -d bin/kernel.o bin/kernel-asm.o bin/shell.o bin/std_lib.o
	dd if=bin/kernel.bin of=bin/floppy.img conv=notrunc bs=512 seek=1
```

Tahap `link` adalah melakukan linking setiap binary file menjadi satu binary, linker yang digunakan adalah `ld86`, semua file **.o** akan dilinking dan outputnya menjadi `kernel.bin`, kemudian hasil dari `kernel.bin` akan diwrite ke `disk image`.

```make
build: prepare bootloader stdlib shell kernel link

run: build
	bochs -f bochsrc.txt
```

Tahap `build` akan menjadi entrypoint yang dipanggil independent, dan memiliki dependent ke handler make lainnya yang akan dipanggil satu persatu.

Tahap `run` akan menjalankan `bochs` bootloader dengan membaca config `bochsrc.txt`
