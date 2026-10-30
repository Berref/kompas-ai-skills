# SetPoint - Установить координату точки

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IStraightSlot](istraightslot.html) > [IStraightSlot - методы](istraightslot_methods.html) |  Scroll [ [ [ ](icontour.html "К следующему разделу")](istraightslot_methods.html "На уровень выше")](istraightslot_getpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](istraightslot.html)

Синтаксис Automation:

BOOL SetPoint( ksStraightSlotPointEnum Index, double X, double Y )

Синтаксис COM:

HRESULT SetPoint( ksStraightSlotPointEnum Index, double X, double Y, BOOL * Result )

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Index | \- индекс точки из перечисления [ksStraightSlotPointEnum](ksstraightslotpointenum.html),  
---|---  
X, Y | \- координаты точки.  
  
Подразделы:

(отсутствуют)
