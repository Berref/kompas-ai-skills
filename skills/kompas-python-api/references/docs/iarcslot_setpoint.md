# SetPoint - Установить координату точки

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IArcSlot](iarcslot.html) > [IArcSlot - методы](iarcslot_methods.html) |  Scroll [ [ [ ](ibezier.html "К следующему разделу")](iarcslot_methods.html "На уровень выше")](iarcslot_getpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](iarcslot.html).

Синтаксис Automation:

BOOL SetPoint( ksArcSlotPointEnum Index, double X, double Y );

Синтаксис COM:

HRESULT SetPoint( ksArcSlotPointEnum Index, double X, double Y, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Index | \- индекс точки паза из перечисления [ksArcSlotPointEnum](ksarcslotpointenum.html),  
---|---  
X, Y | \- координаты точки.   
  
Подразделы:

(отсутствуют)
