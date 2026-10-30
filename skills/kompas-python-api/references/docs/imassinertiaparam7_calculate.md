# Calculate - Рассчитать параметры

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IMassInertiaParam7 ](imassinertiaparam7.html) > [IMassInertiaParam7 - методы ](imassinertiaparam7_methods.html) |  Scroll [ [ [ ](imassinertiaparam7_getaxisx.html "К следующему разделу")](imassinertiaparam7_methods.html "На уровень выше")](imassinertiaparam7_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imassinertiaparam7.html)

Синтаксис Automation:

BOOL Calculate( );

Синтаксис COM:

HRESULT Calculate ( VARIANT_BOOL* Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет рассчитать массово-центровочные характеристики объекта. Метод следует вызывать после изменения одного из параметров объекта, чтобы привести остальные параметры в соответствие с измененным.

Подразделы:

(отсутствуют)
