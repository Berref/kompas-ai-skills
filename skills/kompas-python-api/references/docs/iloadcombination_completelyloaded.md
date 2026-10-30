# CompletelyLoaded - Документ загружен полностью

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Сборка ](bc3308967.html) > [Интерфейс ILoadCombination ](iloadcombination.html) > [ILoadCombination - свойства ](iloadcombination_props.html) |  Scroll [ [ [ ](iloadcombination_currentindex.html "К следующему разделу")](iloadcombination_props.html "На уровень выше")](iloadcombination_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iloadcombination.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- документ загружен полностью,  
---|---  
FALSE | \- документ загружен не полностью,  
  
Синтаксис Automation:

CompletelyLoaded = iObject.CompletelyLoaded | Получить свойство ([* ](1.html))  
---|---  
CompletelyLoaded = iObject.GetCompletelyLoaded() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_CompletelyLoaded(&CompletelyLoaded) | Получить свойство ([* ](1.html))  
---|---  
  
Примечание:

1\. Свойство позволяет узнать загружен ли документ полностью.

2\. Если документ загружен полностью, можно получить массово-центровочные характеристики документа. В противном случае вернутся обнуленные данные.

Подразделы:

(отсутствуют)
