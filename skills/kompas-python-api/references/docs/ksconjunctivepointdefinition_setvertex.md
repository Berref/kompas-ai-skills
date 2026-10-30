# SetVertex - Установить указатель на интерфейс опорной вершины

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Интерфейсы объекта “Присоединительная точка”ksConjunctivePointDefinition, IConjunctivePointDefinition ](ksconjunctivepointdefinition.html) > [IConjunctivePointDefinition - методы ](ksconjunctivepointdefinition_methods.html) |  Scroll [ [ [ ](ksplaneedgepointdefinition.html "К следующему разделу")](ksconjunctivepointdefinition_methods.html "На уровень выше")](ksconjunctivepointdefinition_setedge.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksconjunctivepointdefinition.html)

Синтаксис Automation:

VARIANT_BOOL SetVertex (LPDISPATCH Val);

Синтаксис COM:

BOOL SetVertex (LPENTITY Val);

Входные параметры:

Val | \- Указатель на интерфейс [IEntity](ksentity.html) или[ ksEntity](ksentity.html) опорной вершины.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечания.

Позволяет задать опорную вершину, на которой будет построена присоединительная точка. Опорной вершиной может быть объект "вершина" (тип o3d_vertex).

Подразделы:

(отсутствуют)
