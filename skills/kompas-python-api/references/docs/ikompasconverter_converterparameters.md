# CIonverterParameters - Получить параметры конвертора

[Создание прикладных библиотек ](libraries_create.html) > [Оформление библиотек типа Converter ](cr95008.html) > [Интерфейс IKompasConverter ](ikompasconverter.html) > [IKompasConverter - свойства ](ikompasconverter_props.html) |  Scroll [ [ [ ](ikompasconverter_getfilter.html "К следующему разделу")](ikompasconverter_props.html "На уровень выше")](ikompasconverter_canunloadlibrary.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasconverter.html)

Синтаксис Automation:

LPDISPATCH ConverterParameters( long command);

Синтаксис COM:

HRESULT ConverterParameters ( [in] long command, [out, retval] IUnknown** iParam );

Входные параметры:

command | \- номер команды.  
---|---  
  
Возвращаемое значение:

указатель на интерфейс IUnknown | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Данный метод позволяет получить интерфейс параметров конвертирования.

Подразделы:

(отсутствуют)
