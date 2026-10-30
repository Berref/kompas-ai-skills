# BendValue - Величина сгиба

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalBend ](isheetmetalbend.html) > [ISheetMetalBend - свойства ](isheetmetalbend_props.html) |  Scroll [ [ [ ](isheetmetalbend_deviationleftside.html "К следующему разделу")](isheetmetalbend_props.html "На уровень выше")](isheetmetalbend_bendtablepath.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalbend.html)

Тип данных: double

Синтаксис Automation:

BendValue = iObject.BendValue(); | Получить свойство ([* ](1.html))  
---|---  
iObject.BendValue() = BendValue; | Установить свойство ([* ](1.html))  
BendValue = iObject.GetBendValue(); | Получить свойство ([**](2.html))  
iObject.SetBendValue( BendValue ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_BendValue( &BendValue ); | Получить свойство  
---|---  
iObject->put_BendValue( BendValue ); | Установить свойство  
  
Примечание.

Чтобы свойство было доступно, необходимо установить тип расчета длины развёртки - величина сгиба. Позволяет считывать и устанавливать величину сгиба. Get - cвойство будет возвращать величину сгиба базового листового тела пока не будет установлена "величина сгиба" для сгиба.

Подразделы:

(отсутствуют)
