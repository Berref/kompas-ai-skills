# SetEdge - Установить указатель на интерфейс опорного объекта для определения вектора направления

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Интерфейсы объекта “Присоединительная точка”ksConjunctivePointDefinition, IConjunctivePointDefinition ](ksconjunctivepointdefinition.html) > [IConjunctivePointDefinition - методы ](ksconjunctivepointdefinition_methods.html) |  Scroll [ [ [ ](ksconjunctivepointdefinition_setvertex.html "К следующему разделу")](ksconjunctivepointdefinition_methods.html "На уровень выше")](ksconjunctivepointdefinition_getpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksconjunctivepointdefinition.html)

Синтаксис Automation:

VARIANT_BOOL SetEdge (LPDISPATCH Val);

Синтаксис COM:

BOOL SetEdge (LPENTITY Val);

Входные параметры:

Val | \- Указатель на интерфейс [ksEntity](ksentity.html) или [IEntity](ksentity.html) опорного объекта.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечания.

Позволяет задать опорный объект, по которому будет определяться вектор направления. Опорными объектами могут быть:

•грани,

•конструктивные плоскости,

•ребра,

•вспомогательные оси.

Если в качестве опорного объекта выбрана грань или конструктивная плоскость, то вектор будет перпендикулярен опорному объекту. Если в качестве опорного объекта выбрано ребро или вспомогательная ось, то вектор будет параллелен опорному объекту. Чтобы задать конкретное (прямое или обратное) направление вектора относительно опорного объекта, необходимо установить соответствующее значение свойству [Direction](ksconjunctivepointdefinition_direction.html).

Подразделы:

(отсутствуют)
