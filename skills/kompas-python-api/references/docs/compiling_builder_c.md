# Builder C++

[Компиляция библиотек](compiling_libraries.html) |  Scroll [ [ [ ](compiling_builder_c_automation.html "К следующему разделу")](compiling_libraries.html "На уровень выше")](compiling_libraries.html "К предыдущему разделу")  
---|---  
  
1.Задайте пути к подключаемым модулям. Для этого вызовите команды Project — Options… — Directories/Conditionals — Include path и Library path.

2.Отключите прежние файлы библиотек (файлы *.lib).  
Возможность компиляции 64-разрядных библиотек есть в Embarcadero RAD Studio XE3 и выше.  
Для 64-разрядной версии КОМПАС-3D требуется подключение файлов SDK\lib64\kAPI2D5bc.a, kAPI3D5bc.a.  
Файлы архивов .а генерируются утилитой MKEXP.EXE:  
  
MKEXP.EXE kAPI2D5bc.a kAPI2D5.dll  
  
Для использования API7 может потребоваться подключение файлов kAPI7bc.lib или kAPI7bc.а.  
  
см. также:  
<http://forum.ascon.ru/index.php/topic,25560.20.html>  
<http://docwiki.embarcadero.com/RADStudio/XE3/en/MKEXP.EXE,_the_64-bit_Windows_Import_Library_Tool_for_C%2B%2B>  
  
Рекомендуется вместо подключения в дереве сделать линковку библиотек через директиву #pragma:  
  
#pragma comment(lib, "kAPI2D5bc")  
#pragma comment(lib, "kAPI3D5bc")  
  
В настройках проекта требуется добавить путь к каталогу SDK\lib64, см. пример в SDK\C++\CBuilder\step1  
  
При адаптации библиотеки, созданной в старых версиях Borland C++ Builder для Embarcadero RAD Studio XE3 и выше, требуется открыть в блокноте и изменить значение параметра   
<FrameworkType>None</FrameworkType> на <FrameworkType>VCL</FrameworkType>  
  
При компиляции под x64 не работает директива __pascal. Требуется изменение функций.  
  
Было:  
  
extern "C" unsigned int far __pascal WINAPI LibraryId()  
{  
return IDR_LIBID;  
}  
extern "C" void far __pascal LibraryEntry( UINT comm )  
  
Стало:  
  
extern "C" unsigned int far __export WINAPI LIBRARYID()  
{  
return IDR_LIBID;  
}  
extern "C" void far __export WINAPI LIBRARYENTRY( UINT comm )  
  
В x64 __export не работает для функций, возвращающих указатель на строку char * и wchar_t *. Требуется объявление как __declspec(dllexport):  
  
extern "C" char * __declspec(dllexport) __stdcall LIBRARYNAME()  
  
Нужно учитывать, что класс string стал Unicod-ным. Вместо него рекомендуется использовать классы AnsiString или Unicod-ный WideString.  
В Embarcadero RAD Studio есть поддержка Unicod.  
Рекомендуется выполнить перевод библиотеки на Unicod с использованием Unicod-ных аналогов структур и функций.
