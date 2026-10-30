# Правило именования и расположения ini-файлов

[Инструкция по созданию справки HTML для приложений](help_for_applications.html) > [Локальная справка для приложений](local_help.html) |  Scroll [ [ [ ](name_help.html "К следующему разделу")](local_help.html "На уровень выше")](key_for_help.html "К предыдущему разделу")  
---|---  
  
В %ProgramData%\ASCON\HelpServer должен быть помещен ini-файл приложения. Имя файла может быть задано в одном из следующих форматов:

•<App ID>_<major версия>_<локаль>.ini

•<helpId>_<major версия>_<локаль>.ini

Пример: 

APP_Gayka1_v23_ru-Ru.ini или Gayka1_v23_ru-Ru.ini

![warn](./images/warn.png) | Ini-файл должен быть в кодировке UTF-8 and UTF-16LE with BOM encoded configuration files are supported.  
---|---  
  
Структура ini-файла

Help]

формируемый путь для строки браузера:

path=/<App ID>/<major версия>/<локаль>/

или

path=/<HelpId>/<major версия>/<локаль>/

путь к справке:

root=J:\Test Lib\Help\Gayka1_ru-Ru.zip

Пример содержания ini-файла

[Help]

path=/Gayka1/22/ru-RU/

root=J:\Test Lib\Help\Gayka1_ru-Ru.zip

Если в системе установлено несколько локализаций, то рекомендуется создавать разные ini-файлы на каждый язык.

Например:

Gayka1_v22_ru-RU.ini

Gayka1_v22_en-US.ini
