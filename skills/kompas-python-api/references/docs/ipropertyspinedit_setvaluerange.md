# SetValueRange - Установить новые ограничения на значение

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertySpinEdit ](ipropertyspinedit.html) > [IPropertySpinEdit - методы ](ipropertyspinedit_methods.html) |  Scroll [ [ [ ](ipropertystylelist.html "К следующему разделу")](ipropertyspinedit_methods.html "На уровень выше")](ipropertyspinedit_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyspinedit.html)

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

Тип данных максимального и минимального допустимого значения определяется типом элемента управления:

•для типа ksControlSpinInt из [ControlTypeEnum](controltypeenum.html) используется тип long,

•для типа ksControlSpinReal из ControlTypeEnum используется тип double.

Подразделы:

(отсутствуют)
