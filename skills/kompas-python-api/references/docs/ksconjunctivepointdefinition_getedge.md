# GetEdge - Получить указатель на интерфейс опорного объекта для определения вектора направления

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Интерфейсы объекта “Присоединительная точка”ksConjunctivePointDefinition, IConjunctivePointDefinition ](ksconjunctivepointdefinition.html) > [IConjunctivePointDefinition - методы ](ksconjunctivepointdefinition_methods.html) |  Scroll [ [ [ ](ksconjunctivepointdefinition_getpoint.html "К следующему разделу")](ksconjunctivepointdefinition_methods.html "На уровень выше")](ksconjunctivepointdefinition_getvertex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksconjunctivepointdefinition.html)

Синтаксис Automation:

LPDISPATCH GetEdge();

Синтаксис COM:

LPENTITY GetEdge();

Входные параметры:

Указатель на интерфейс [ksEntity](ksentity.html) или [IEntity](ksentity.html) опорного объекта. |   
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечания.

Возвращает указатель на интерфейс опорного объекта, для определения вектора направления. Опорными объектами могут быть:

•грани,

•конструктивные плоскости,

•ребра,

•вспомогательные оси.

Подразделы:

(отсутствуют)
