# SetPoint - Установить указатель на интерфейс вершины, через которую будет проходить новая плоскость

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Плоскость перпендикулярная ребру (Интерфейсы ksPlanePerpendicularDefinition, IPlanePerpendicularDefinition) ](ksplaneperpendiculardefinition.html) > [IPlanePerpendicularDefinition - методы ](ksplaneperpendiculardefinition_methods.html) |  Scroll [ [ [ ](ksplanelinetoedgedefinition.html "К следующему разделу")](ksplaneperpendiculardefinition_methods.html "На уровень выше")](ksplaneperpendiculardefinition_setedge.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksplaneperpendiculardefinition.html)

Синтаксис Automation:

BOOL SetPoint (LPDISPATCH point);

Синтаксис COM:

BOOL SetPoint (LPENTITY point);

Входной параметр:

point | \- указатель на интерфейс вершины [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
