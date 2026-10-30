# GetPoint - Получить координату точки

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IStraightSlot](istraightslot.html) > [IStraightSlot - методы](istraightslot_methods.html) |  Scroll [ [ [ ](istraightslot_setpoint.html "К следующему разделу")](istraightslot_methods.html "На уровень выше")](istraightslot_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](istraightslot.html)

Синтаксис Automation:

BOOL GetPoint( ksStraightSlotPointEnum Index, double * X, double * Y );

Синтаксис COM:

HRESULT GetPoint( ksStraightSlotPointEnum Index, double * X, double * Y, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Index | \- индекс точки из перечисления [ksStraightSlotPointEnum](ksstraightslotpointenum.html),  
---|---  
  
Выходные параметры:

X, Y | \- координаты точки.  
---|---  
  
Подразделы:

(отсутствуют)
