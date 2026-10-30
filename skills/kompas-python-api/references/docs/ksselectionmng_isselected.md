# IsSelected - Определить, выделен ли объект

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Менеджер выделенных объектов (Интерфейсы ksSelectionMng, ISelectionMng) ](ksselectionmng.html) > [ISelectionMng - методы ](ksselectionmng_methods.html) |  Scroll [ [ [ ](ksselectionmng_last.html "К следующему разделу")](ksselectionmng_methods.html "На уровень выше")](ksselectionmng_getobjecttype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksselectionmng.html)

Синтаксис Automation:

BOOL IsSelected (LPDISPATCH obj);

Синтаксис COM:

BOOL IsSelected (LPUNKNOWN obj);

Входной параметр:

obj | \- указатель на интерфейс IDispatch или IUnknown выделенного объекта.  
---|---  
  
Возвращаемое значение:

TRUE | \- объект выделен,  
---|---  
FALSE | \- объект не выделен.  
  
Подразделы:

(отсутствуют)
