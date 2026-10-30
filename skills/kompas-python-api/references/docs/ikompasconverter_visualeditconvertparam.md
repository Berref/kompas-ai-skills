# VIisualEditConvertParam - Запустить визуальное редактирование параметров конвертации

[Создание прикладных библиотек ](libraries_create.html) > [Оформление библиотек типа Converter ](cr95008.html) > [Интерфейс IKompasConverter ](ikompasconverter.html) > [IKompasConverter - свойства ](ikompasconverter_props.html) |  Scroll [ [ [ ](applicate.html "К следующему разделу")](ikompasconverter_props.html "На уровень выше")](ikompasconverter_convert.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasconverter.html)

Синтаксис Automation:

BOOL * VisualEditConvertParam ( OLE_HANDLE parentHwnd, long command );

Синтаксис COM:

HRESULT VisualEditConvertParam ( [in] OLE_HANDLE parentHwnd,

[in] long command,

[out, retval] VARIANT_BOOL * val );

Входные параметры:

parentHwnd | \- дескриптор окна родителя,  
---|---  
command | \- номер команды.  
  
Возвращаемое значение:

TRUE | \- выход из диалога по кнопке OK,  
---|---  
FALSE | \- выход из диалога по кнопке Отмена.  
  
Подразделы:

(отсутствуют)
