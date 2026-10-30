# IsChoosen - Получить признак подсвеченности (выбора) объекта

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Менеджер выбора (подсветки) объектов (Интерфейсы ksChooseMng, IChooseMng) ](kschoosemng.html) > [IChooseMng - методы ](kschoosemng_methods.html) |  Scroll [ [ [ ](kschoosemng_last.html "К следующему разделу")](kschoosemng_methods.html "На уровень выше")](kschoosemng_getobjecttype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kschoosemng.html)

Синтаксис Automation:

BOOL IsChoosen (LPDISPATCH obj);

Синтаксис COM:

BOOL IsChoosen (LPUNKNOWN obj);

Входной параметр:

obj | \- указатель на интерфейс IDispatch или IUnknown.  
---|---  
  
Возвращаемое значение:

TRUE | \- объект подсвечен,  
---|---  
FALSE | \- объект не подсвечен.  
  
Подразделы:

(отсутствуют)
