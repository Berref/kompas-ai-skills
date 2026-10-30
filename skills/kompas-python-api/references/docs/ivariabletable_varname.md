# VarName - Имя переменной в колонке таблицы переменных

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Переменные ](ba1859837.html) > [Интерфейс IVariableTable ](ivariabletable.html) > [IVariableTable - свойства ](ivariabletable_props.html) |  Scroll [ [ [ ](ivariabletable_varnames.html "К следующему разделу")](ivariabletable_props.html "На уровень выше")](ivariabletable_tablerow.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ivariabletable.html)

Тип данных: BSTR (строка)

Синтаксис Automation:

Name = iObject.VarName (column) | Получить свойство ([* ](1.html))  
---|---  
iObject.VarName (column) = Name | Установить свойство ([* ](1.html))  
Name = iObject.GetVarName (column) | Получить свойство ([**](2.html))  
iObject.SetVarName (column, Name) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_VarName (column, &Name) | Получить свойство  
---|---  
iObject->put_VarName (column, Name) | Установить свойство  
  
Входные параметры:

long column | \- индекс колонки таблицы переменных.  
---|---  
  
Примечание:

Установка свойства доступна только для верхнего компонента.

Подразделы:

(отсутствуют)
