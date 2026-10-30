# DrawBottomUp - Строить снизу вверх

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - свойства ](ispecificationtuning_props.html) |  Scroll [ [ [ ](ispecificationtuning_initialposition.html "К следующему разделу")](ispecificationtuning_props.html "На уровень выше")](ispecificationtuning_disablenestingblockemptystrings.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Тип данных: BOOL

Синтаксис Automation:

DrawBottomUp = iObject.DrawBottomUp | Получить свойство ([* ](1.html))  
---|---  
iObject.DrawBottomUp = DrawBottomUp | Установить свойство ([* ](1.html))  
DrawBottomUp = iObject.GetDrawBottomUp() | Получить свойство ([**](2.html))  
iObject.SetDrawBottomUp (DrawBottomUp) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DrawBottomUp (&DrawBottomUp) | Получить свойство  
---|---  
iObject->put_DrawBottomUp (DrawBottomUp) | Установить свойство  
  
Значения свойства:

TRUE | \- строить снизу вверх,  
---|---  
FALSE | \- строить сверху вниз.  
  
Примечание:

Позволяет управлять порядком следования разделов и объектов в них. Если значение свойства - TRUE, разделы располагаются в порядке, обратном указанному в стиле спецификации, и порядок сортировки объектов также становится «обратным». Такой порядок расположения предписывается некоторыми СТП при заполнении спецификации, размещаемой на чертеже.

Подразделы:

(отсутствуют)
