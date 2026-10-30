# SetValueRange - Установить новые ограничения на значение

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyList ](ipropertylist.html) > [IPropertyList - методы ](ipropertylist_methods.html) |  Scroll [ [ [ ](ipropertymultibutton.html "К следующему разделу")](ipropertylist_methods.html "На уровень выше")](ipropertylist_setcurrentbyindex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertylist.html)

Синтаксис Automation:

BOOL SetValueRange (const VARIANT& minVal, const VARIANT& maxVal);

Синтаксис COM:

HRESULT SetValueRange ([in] VARIANT minVal, [in] VARIANT maxVal, [out, retval] VARIANT_BOOL * pVal);

Входные параметры:

minVal | \- минимальное допустимое значение (тип данных long или double),  
---|---  
maxVal | \- максимальное допустимое значение (тип данных long или double).  
  
Примечание:

Тип данных максимального и минимального допустимого значения определяется типом элемента управления из перечисления [ControlTypeEnum](controltypeenum.html):

•для типа ksControlListInt используется тип long,

•для типа ksControlListReal используется тип double,

•для типа ksControlListStr ограничения на значение не накладываются,

•для типа ksControlListLength используется тип double,

•для типа ksControlListAngle используется тип double.

Подразделы:

(отсутствуют)
