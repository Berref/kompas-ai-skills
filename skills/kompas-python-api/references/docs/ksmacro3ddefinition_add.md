# Add - Добавить объект в состав макроэлемента

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) > [Интерфейс макроэлемента (ksMacro3DDefinition, IMacro3DDefinition) ](ksmacro3ddefinition.html) > [IMacro3DDefinition - методы ](ksmacro3ddefinition_methods.html) |  Scroll [ [ [ ](ksmacro3ddefinition_clearallobj.html "К следующему разделу")](ksmacro3ddefinition_methods.html "На уровень выше")](ksmacro3ddefinition_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmacro3ddefinition.html)

Синтаксис Automation:

BOOL Add (LPDISPATCH obj);

Синтаксис COM:

BOOL Add (LPUNKNOWN obj);

Входные параметры:

obj | \- указатель на интерфейс объекта, добавляемого в макроэлемент.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. В качестве входного параметра могут быть переданы следующие интерфейсы:

•[ksFeature](ksfeature.html),

•[ksEntity](ksentity.html),

•[ksPart](kspart.html),

•[ksMateConstraint](ksmateconstraint.html).

2\. Если объект еще не создан в модели, то он создастся после вызова методов [ksEntity::Create](ksentity_create.html) или [ksEntity::Update](ksentity_update.html) макроэлемента. Для существовавших объектов в этом случае будет вызван метод [ksEntity::Update](ksentity_update.html).

3\. Добавляемый объект должен принадлежать тому же компоненту, что и сам макроэлемент. Он не должен принадлежать другому макроэлементу.

4\. При добавлении тела в макроэлемент в макроэлемент добавляются все операции данного тела на момент создания макроэлемента. Само тело в макроэлемент не добавляется.

Подразделы:

(отсутствуют)
