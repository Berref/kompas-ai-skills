# Builder C++ Automation

[Компиляция библиотек](compiling_libraries.html) |  Scroll [ [ [ ](compiling_delphi.html "К следующему разделу")](compiling_libraries.html "На уровень выше")](compiling_builder_c.html "К предыдущему разделу")  
---|---  
  
1.Задайте пути к подключаемым модулям. Для этого вызовите команды Project — Options… — Directories/Conditionals — Include path и Library path.

2.Отключите прежние файлы библиотек (файлы *.lib).  
Для 64-разрядной версии КОМПАС-3D требуется использовать файл kapi5bc.a.  
Рекомендуется вместо подключения в дереве сделать линковку библиотек через директиву #pragma.

#pragma comment(lib, "kAPI5bc") 

3.Удалите файлы ks_tlb.h, ks_tlb.cpp, ks_ocx.h, ks_ocx.cpp.

4.Подключите новую библиотеку (файл с расширением tlb). Для этого выполните следующие действия.

4.1. Вызовите команду Project — Import type library — Add.   
В Embarcadero RAD Studio XE3 и выше импорт выполняется командой Component — Import —Component —VCL for C++ Win32.   
Перед запуском команды требуется снять в настройках Tools — Options — Delphi Options — Type Library — RTL следующие флаги:  
  
Check for UTF8 data in type library  
Store Unicode data as UTF8 in type library   
  
Аналогичные настройки снять в Tools — Options — С++ Options — Type Library — RTL.  
Данные настройки влияют на корректность импорта helpstring-ов из tlb.

4.2. Выберите файл kAPI5.tlb или kAPI7.tlb для использования API7, а также файлы констант ksConstants.tlb и ksConstants3D.tlb.  
Так как файл kAPI7.tlb использует все перечисленные tlb, достаточно импорт сделать с данного файла — при этом будут созданы файлы для всех tlb.

4.3. Выключите опцию Generate Component Wrapper.

5.Укажите путь к папке SDK\Include в параметре Unit dir name.

6.Нажмите кнопку Create Unit.

7.Переименуйте полученные файлы в ks_tlb.h, ks_tlb.cpp (ksAPI7.cpp и ksAPI7.h при импорте kAPI7.tlb).  
При сохранении под другим именем в ks_tlb.cpp изменяется имя namespace Kompas6api5_tlb на ks_tlb. Требуется вернуть Kompas6api5.

8.Отредактируйте в файле ks_tlb.cpp подключение h файла, если оно не изменилось при сохранении.  
В ksAPI7.h требуется отредактировать подключение фалов, полученных с kAPI5.tlb.
