# ViewEdit - Выводится диалог для просмотра и редактирования свойства

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Свойства ](ba1946975.html) > [Интерфейс IProperty ](iproperty.html) > [IProperty - методы ](iproperty_methods.html) |  Scroll [ [ [ ](iproperty_update.html "К следующему разделу")](iproperty_methods.html "На уровень выше")](iproperty_setvaluerange.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iproperty.html)

Синтаксис Automation:

BOOL ViewEdit(OLE_HANDLE Parent, BOOL readOnly );

Синтаксис COM:

HRESULT ViewEdit( OLE_HANDLE Parent, BOOL ReadOnly, BOOL * Res );

Синтаксис Automation:

Parent | \- дескриптор окна (может быть задан ноль - признак главного окна),  
---|---  
ReadOnly | \- диалог только на чтение свойства.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
