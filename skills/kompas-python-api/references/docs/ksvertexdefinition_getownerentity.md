# GetOwnerEntity - Получить указатель на объект, породивший вершину

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) > [Описание вершины (Интерфейсы ksVertexDefinition,IVertexDefinition) ](ksvertexdefinition.html) > [IVertexDefinition - методы ](ksvertexdefinition_methods.html) |  Scroll [ [ [ ](ksvertexdefinition_getpoint.html "К следующему разделу")](ksvertexdefinition_methods.html "На уровень выше")](ksvertexdefinition_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksvertexdefinition.html)

Синтаксис Automation:

LPDISPATCH GetOwnerEntity();

Синтаксис COM:

LPENTITY GetOwnerEntity();

Выходные параметры:

x, y, z | \- координаты вершины.  
---|---  
  
Возвращаемое значение:

указатель на интерфейс [ksEntity](ksentity.html) или [iEntity](ksentity.html) |   
---|---  
  
Подразделы:

(отсутствуют)
