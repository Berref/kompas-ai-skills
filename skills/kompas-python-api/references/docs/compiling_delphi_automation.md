# Delphi Automation

[Компиляция библиотек](compiling_libraries.html) |  Scroll [ [ [ ](compiling_visual_basic.html "К следующему разделу")](compiling_libraries.html "На уровень выше")](compiling_delphi.html "К предыдущему разделу")  
---|---  
  
Подключите новую библиотеку (файл с расширением tlb). Для этого выполните следующие действия.

1.Вызовите команду Project — Import type library — Add.  
В Embarcadero RAD Studio XE2 и выше импорт выполняется командой Component — Import — Component — VCL for Delphi Win32.

2.Выберите файл kAPI5.tlb.

3.Выключите опцию Generate Component Wrapper.

4.Укажите путь к корневой папке размещения примеров Unit dir name.

5.Нажмите кнопку Create Unit.

6.Переименуйте полученный файл в KsTLB.pas и отредактируйте его первую строку.

7.Найдите строчку Application = KompasObject; и исправьте на ksApp = KompasObject;  
Это нужно, чтобы избежать конфликта с глобальной переменной Delphi Forms.Application.
