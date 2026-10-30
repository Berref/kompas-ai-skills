# ShowAllObjects - Показывать все объекты

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationDescription ](ispecificationdescription.html) > [ISpecificationDescription - свойства ](ispecificationdescription_props.html) |  Scroll [ [ [ ](ispecificationdescription_showonsheet.html "К следующему разделу")](ispecificationdescription_props.html "На уровень выше")](ispecificationdescription_performancename.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationdescription.html)

Тип данных: BOOL

Синтаксис Automation:

ShowAllObjects = iObject.ShowAllObjects | Получить свойство ([* ](1.html))  
---|---  
iObject.ShowAllObjects = ShowAllObjects | Установить свойство ([* ](1.html))  
ShowAllObjects = iObject.GetShowAllObjects() | Получить свойство ([**](2.html))  
iObject.SetShowAllObjects (ShowAllObjects) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ShowAllObjects (&ShowAllObjects) | Получить свойство  
---|---  
iObject->put_ShowAllObjects ( ShowAllObjects) | Установить свойство  
  
Значения свойства:

TRUE | \- отображаются все объекты в описании,  
---|---  
FALSE | \- одинаковые объекты отображаются одной строкой, а в колонке количество отображается.  
  
Примечание:

Свойство позволяет получить или установить состояние режима работы, в котором на экране отображаются все объекты спецификации, в том числе базовые объекты спецификации, имеющие одинаковую текстовую часть, а также базовые объекты спецификации, в настройках дополнительных параметров которых выключена опция показа объекта в таблице.

Одинаковые объекты могут иметь одинаковые или разные номера позиций, могут находиться в соседних строках или в разных местах таблицы (в пределах одного раздела спецификации). Если объекты с одинаковой текстовой частью находятся в разных разделах спецификации, то они считаются разными.

Подразделы:

(отсутствуют)
