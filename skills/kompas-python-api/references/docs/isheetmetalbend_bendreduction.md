# BendReduction - Уменьшение сгиба

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalBend ](isheetmetalbend.html) > [ISheetMetalBend - свойства ](isheetmetalbend_props.html) |  Scroll [ [ [ ](isheetmetalbend_bendrelease.html "К следующему разделу")](isheetmetalbend_props.html "На уровень выше")](isheetmetalbend_bendobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalbend.html)

Тип данных: double

Синтаксис Automation:

BendReduction = iObject.BendReduction(); | Получить свойство ([* ](1.html))  
---|---  
iObject.BendReduction() = BendReduction; | Установить свойство ([* ](1.html))  
BendReduction = iObject.GetBendReduction(); | Получить свойство ([**](2.html))  
iObject.SetBendReduction( BendReduction ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_BendReduction( &BendReduction ); | Получить свойство  
---|---  
iObject->put_BendReduction( BendReduction ); | Установить свойство  
  
Примечание.

Чтобы свойство было доступно, необходимо установить тип расчета длины развёртки - уменьшение сгиба. Позволяет считывать и устанавливать уменьшение сгиба. Get - cвойство будет возвращать уменьшение сгиба базового листового тела пока не будет установлено "уменьшение сгиба" для сгиба.

Подразделы:

(отсутствуют)
