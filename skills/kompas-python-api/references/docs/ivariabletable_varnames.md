# VarNames - Массив имен переменных в таблице переменных

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Переменные ](ba1859837.html) > [Интерфейс IVariableTable ](ivariabletable.html) > [IVariableTable - свойства ](ivariabletable_props.html) |  Scroll [ [ [ ](ivariabletable_visualtable.html "К следующему разделу")](ivariabletable_props.html "На уровень выше")](ivariabletable_varname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ivariabletable.html)

Тип данных: VARIANT

Синтаксис Automation:

VarNames = iObject.VarNames | Получить свойство ([* ](1.html))  
---|---  
iObject.VarNames = VarNames | Установить свойство ([* ](1.html))  
VarNames = iObject.GetVarNames() | Получить свойство ([**](2.html))  
iObject.SetVarNames (VarNames) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_VarNames(&VarNames) | Получить свойство  
---|---  
iObject->put_VarNames (VarNames) | Установить свойство  
  
Примечание:

1\. Массив имён переменных передаётся через массив SAFEARRAY значений типа BSTR.

2\. Установка свойства доступна только для верхнего компонента.

Подразделы:

(отсутствуют)
