# GetDisableReason - Получить описание причины недоступности команды

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Интерфейс ksKompasLibrary ](kskompaslibrary.html) > [ksKompasLibrary - методы ](kskompaslibrary_methods.html) |  Scroll [ [ [ ](kskompaslibrary_gethelpfile.html "К следующему разделу")](kskompaslibrary_methods.html "На уровень выше")](kskompaslibrary_fillcontextpanel.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kskompaslibrary.html)

Синтаксис:

BSTR GetDisableReason( long Command );

Входные параметры:

Command | \- номер команды приложения.  
---|---  
  
Возвращаемое значение:

  
| \- строка-пояснение с причиной недоступности команды.  
---|---  
  
Примечание:

Строка удаляется функцией SysFreeString.

Функция вызывается, если приложение в функции [IKompasLibrary::GetLibraryCommandState](ikompaslibrary_getlibrarycommandstate.html) сделало команду недоступной.

Подразделы:

(отсутствуют)
