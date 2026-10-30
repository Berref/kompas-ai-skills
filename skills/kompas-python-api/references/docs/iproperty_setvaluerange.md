# SetValueRange - Установить новые ограничения на значение

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Свойства ](ba1946975.html) > [Интерфейс IProperty ](iproperty.html) > [IProperty - методы ](iproperty_methods.html) |  Scroll [ [ [ ](iproperty_viewedit.html "К следующему разделу")](iproperty_methods.html "На уровень выше")](iproperty_delete.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iproperty.html)

Синтаксис Automation:

BOOL SetValueRange( VARIANT MinVal, VARIANT MaxVal );

Синтаксис COM:

HRESULT SetValueRange( VARIANT MinVal, VARIANT MaxVal, BOOL * PVal);

Входные параметры:

MinVal | \- минимальное значение,  
---|---  
MaxVal | \- максимальное значение.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Для свойства с типом данных:

•ksPropertyDataTypeDouble значение должно иметь тип VT_R8,

•ksPropertyDataTypeLong значение должно иметь тип VT_I4,

•ksPropertyDataTypeString значение должно иметь тип VT_BSTR.

Подразделы:

(отсутствуют)
