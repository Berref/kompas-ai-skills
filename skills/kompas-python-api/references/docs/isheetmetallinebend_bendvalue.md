# BendValue - Величина сгиба

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalLineBend ](isheetmetallinebend.html) > [ISheetMetalLineBend - свойства ](isheetmetallinebend_props.html) |  Scroll [ [ [ ](isheetmetallinebend_direction.html "К следующему разделу")](isheetmetallinebend_props.html "На уровень выше")](isheetmetallinebend_bendtype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetallinebend.html)

Тип данных: double

Синтаксис Automation:

BendValue = iObject.BendValue; | Получить свойство ([* ](1.html))  
---|---  
iObject.BendValue = BendValue; | Установить свойство ([* ](1.html))  
BendValue = iObject.GetBendValue; | Получить свойство ([**](2.html))  
iObject.SetBendValue( BendValue ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_BendValue( &BendValue ); | Получить свойство  
---|---  
iObject->put_BendValue( BendValue ); | Установить свойство  
  
Примечание.

Чтобы свойство было доступно, необходимо установить тип расчета длины развёртки - величина сгиба. Позволяет считывать и устанавливать величину сгиба. Get - cвойство будет возвращать величину сгиба базового листового тела, пока не будет установлена "величина сгиба" для сгиба по линии.

Подразделы:

(отсутствуют)
