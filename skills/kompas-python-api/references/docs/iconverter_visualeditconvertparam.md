# VisualEditConvertParam - Запустить визуальное редактирование параметров конвертации

[API интерфейсов. Версия 7](applicate.html) > [Конвертер файлов КОМПАС ](conv.html) > [Интерфейс IСonverter ](iconverter.html) > [IConverter - методы ](iconverter_methods.html) |  Scroll [ [ [ ](iadditionconvertparameters.html "К следующему разделу")](iconverter_methods.html "На уровень выше")](iconverter_getfilter.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconverter.html)

Синтаксис Automation:

BOOL * VisualEditConvertParam( OLE_HANDLE parentHwnd, long command );

Синтаксис COM:

HRESULT VisualEditConvertParam ([in] OLE_HANDLE parentHwnd,

[in] long command,

[out, retval] VARIANT_BOOL * val);

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
