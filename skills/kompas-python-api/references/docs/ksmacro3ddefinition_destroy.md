# Destroy - Разрушить макроэлемент

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) > [Интерфейс макроэлемента (ksMacro3DDefinition, IMacro3DDefinition) ](ksmacro3ddefinition.html) > [IMacro3DDefinition - методы ](ksmacro3ddefinition_methods.html) |  Scroll [ [ [ ](ksmacro3ddefinition_featurecollection.html "К следующему разделу")](ksmacro3ddefinition_methods.html "На уровень выше")](ksmacro3ddefinition_clearallobj.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmacro3ddefinition.html)

Синтаксис Automation:

BOOL Destroy();

Синтаксис COM:

BOOL Destroy();

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

После вызова этого метода макроэлемент будет разрушен, а все объекты, входившие в его состав, станут самостоятельными.

Подразделы:

(отсутствуют)
