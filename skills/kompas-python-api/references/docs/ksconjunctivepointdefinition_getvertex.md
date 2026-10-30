# GetVertex - Получить указатель на интерфейс опорной вершины

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Интерфейсы объекта “Присоединительная точка”ksConjunctivePointDefinition, IConjunctivePointDefinition ](ksconjunctivepointdefinition.html) > [IConjunctivePointDefinition - методы ](ksconjunctivepointdefinition_methods.html) |  Scroll [ [ [ ](ksconjunctivepointdefinition_getedge.html "К следующему разделу")](ksconjunctivepointdefinition_methods.html "На уровень выше")](ksconjunctivepointdefinition_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksconjunctivepointdefinition.html)

Синтаксис Automation:

LPDISPATCH GetVertex();

Синтаксис COM:

LPENTITY GetVertex();

Возвращаемое значение:

| \- Указатель на интерфейс [IEntity](ksentity.html) или[ ksEntity](ksentity.html) опорной вершины.  
---|---  
  
Примечания.

Возвращает указатель на интерфейс опорной вершины, на которой построена присоединительная точка. Опорной вершиной может быть объект "вершина" (тип o3d_vertex).

Подразделы:

(отсутствуют)
