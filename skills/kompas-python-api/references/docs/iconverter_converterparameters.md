# ConverterParameters - Получить интерфейс параметров конвертирования

[API интерфейсов. Версия 7](applicate.html) > [Конвертер файлов КОМПАС ](conv.html) > [Интерфейс IСonverter ](iconverter.html) > [IConverter - методы ](iconverter_methods.html) |  Scroll [ [ [ ](iconverter_getfilter.html "К следующему разделу")](iconverter_methods.html "На уровень выше")](iconverter_convert.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconverter.html)

Синтаксис Automation:

LPDISPATCH ConverterParameters (long command);

Синтаксис COM:

HRESULT ConverterParameters ([in] long command, [out, retval] IUnknown ** PVal);

Входные параметры:

command | \- номер команды, для которой необходимо получить интерфейс параметров.  
---|---  
  
Возвращаемое значение:

указатель на интерфейс IUnknown | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Данный метод позволяет получить интерфейс параметров конвертирования, который объявлен, реализован и поддерживается в самом конвертере.

Подразделы:

(отсутствуют)
