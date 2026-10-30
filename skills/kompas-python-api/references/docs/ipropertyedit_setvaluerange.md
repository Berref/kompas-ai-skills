# SetValueRange - Установить новые ограничения на значение

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyEdit ](ipropertyedit.html) > [IPropertyEdit - методы ](ipropertyedit_methods.html) |  Scroll [ [ [ ](ipropertyeditlist.html "К следующему разделу")](ipropertyedit_methods.html "На уровень выше")](ipropertyedit_setstringregularvalidator.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyedit.html)

Синтаксис Automation:

BOOL SetValueRange (const VARIANT& minVal, const VARIANT& maxVal);

Синтаксис COM:

HRESULT SetValueRange ([in] VARIANT minVal,

[in] VARIANT maxVal,

[out, retval] VARIANT_BOOL * pVal);

Входные параметры:

minVal | \- минимальное значение,  
---|---  
maxVal | \- максимальное значение.  
  
Примечание:

Тип данных максимального и минимального допустимого значения определяется типом элемента управления из перечисления [ControlTypeEnum](controltypeenum.html):

•для типа ksControlListInt используется тип long,

•для типа ksControlListReal используется тип double,

•для типа ksControlEditStr ограничения на значение не накладываются,

•для типа ksControlEditAngle используется тип double,

•для типа ksControlEditLength используется тип double,

•для типа ksControlEditPoint используется тип VT_ARRAY | VT_R8 - на 2 значения координат.

Подразделы:

(отсутствуют)
