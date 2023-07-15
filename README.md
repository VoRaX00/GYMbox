# GYMbox
После клонирования репозитория GYMbox в CLion от вас требуются следующие шаги:

  1. Настройки конфигурации:
     
     1.1 Найти раздел Working directory
     
     1.2 Вписать директорию ведящую к вашему проекту (Пример: C:\Users\nikit\CLionProjects\GYMbox)
  2. Создать папки:
     
     2.1 Создать папку в директории lib
     
     2.2 В lib создать папку sfml
     
     2.3 В sfml создать папку GCC 7.3.0 MinGW (SEH) - 64-bit
     
     2.4 Скачать библиотеку SFML для MINGW
     
     2.5 Кинуть папку SFML-2.6.0 в папку GCC 7.3.0 MinGW (SEH) - 64-bit
     
  3. Создание пути для CMake файлов (MY_PATH):
     
     3.1  Зайти в settings
     
     3.2 Зайти в раздел Build, Execution, Deployment и выбрать вкладку CMake
     
     3.3 В CMake options вписать следующую строку: -DMY_PATH=YOUR_PATH_TO_THE_CLIONPROJECTS_FOLDER (Пример: -DMY_PATH=C:/Users/nikit/CLionProjects)
