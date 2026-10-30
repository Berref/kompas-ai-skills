# BendCoefficient - Коэффициент нейтрального слоя

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalBend ](isheetmetalbend.html) > [ISheetMetalBend - свойства ](isheetmetalbend_props.html) |  Scroll [ [ [ ](isheetmetalbend_bendobject.html "К следующему разделу")](isheetmetalbend_props.html "На уровень выше")](isheetmetalbend_angletype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalbend.html)

Тип данных: double

Синтаксис Automation:

BendCoefficient = iObject.BendCoefficient(); | Получить свойство ([* ](1.html))  
---|---  
iObject.BendCoefficient() = BendCoefficient; | Установить свойство ([* ](1.html))  
BendCoefficient = iObject.GetBendCoefficient(); | Получить свойство ([**](2.html))  
iObject.SetBendCoefficient( BendCoefficient ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_BendCoefficient( &BendCoefficient ); | Получить свойство  
---|---  
iObject->put_BendCoefficient( BendCoefficient ); | Установить свойство  
  
Примечание.

Чтобы свойство было доступно, необходимо установить тип расчета длины развёртки - коэффициент нейтрального слоя. Позволяет считывать и устанавливать коэффициент нейтрального слоя. Get - cвойство будет возвращать коэффициент нейтрального слоя базового листового тела пока не будет установлен коэффициент нейтрального слоя для сгиба.

Подразделы:

(отсутствуют)
