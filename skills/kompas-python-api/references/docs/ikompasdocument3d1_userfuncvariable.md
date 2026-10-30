# UserFuncVariable - Получить функциональную переменную по имени

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument3D1 ](ikompasdocument3d1.html) > [IKompasDocument3D1 - свойства ](ikompasdocument3d1_props.html) |  Scroll [ [ [ ](ikompasdocument3d1_userfuncvariables.html "К следующему разделу")](ikompasdocument3d1_props.html "На уровень выше")](ikompasdocument3d1_treeneedupdateitems.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument3d1.html)

Тип данных: Указатель на интерфейс [IVariable7](ivariable7.html).

Синтаксис Automation:

UserFuncVariable = Object.UserFuncVariable( Index ) | Получить свойство ([* ](1.html))  
---|---  
UserFuncVariable = Object.GetUserFuncVariable( Index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_UserFuncVariable( Index, &UserFuncVariable ) | Получить свойство  
---|---  
  
Входные параметры:

VARIANT Index | \- Индекс объекта в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс объекта, \- VT_BSTR - имя переменной.  
---|---  
  
Примечание:

Свойство доступно только для чтения.

Версия: Компас v20

Подразделы:

(отсутствуют)
